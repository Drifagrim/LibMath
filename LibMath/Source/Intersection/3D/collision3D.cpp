/// Header
#include "Intersection/3D/Collision3D.h"

namespace LibMath
{
    /// Check if the ray collide with the sphere
    bool                        RayToSphere(const Ray& _ray, const Sphere& _sphere)
    {
        Vector3 proj = _sphere.GetCenter();

        
        // Calcul a vector 3 between the sphere center and ray origin
        Vector3 dif = _sphere.GetCenter() - _ray.GetOrigin();

        /*
        * If the dot product between the ray direction and the vector 3 previous
        * calculate is not <= 0 then there is no collision
        */
        if (_ray.GetDirection().dot(dif) <= 0)
            return false;

        // Project the sphere center on to the ray direction vector
        proj.projectOnto(_ray.GetDirection());

        /*
        * If the distance squared from the sphere center and the project vector
        * is < to the power of sphere radius then there is collision
        */
        return proj.distanceSquaredFrom(_sphere.GetCenter()) < (_sphere.GetRadius() * _sphere.GetRadius());
    }
    /// Check if the ray collide with the box
    std::pair<Vector3, bool>    RayToAABB(const Ray& _ray, float _raySize, const Box& _box)
    {
        // Gets minimum and maximum vertices of the box
        std::pair<vertex3D, vertex3D> minMax = _box.GetMinMax();
        Vector3 origin = _ray.GetOrigin();

        // transforms normalized vector so it has a distance
        Vector3 v = (-_ray.GetDirection()) * _raySize;
        // and adds it to its starting position
        Vector3 newRay = origin + v;

        // repeat for each normal of the the box
        for (int i = 0; i < AABB_NORMAL_AXIS; i++)
        {
            // because we need to stay in range [0, 3[
            int j = (i + 1) % AABB_NORMAL_AXIS;
            // because we need to stay in range[0, 3[
            int k = (i + 2) % AABB_NORMAL_AXIS;

            // Checks if both ends of the newRay are on different sides of the plane
            if (std::signbit(origin[i] - minMax.first[i]) != std::signbit(newRay[i] - minMax.first[i]))
            {
                // apply equation of intersection between a vector and a plane
                float t = (minMax.first[i] - origin[i]) / v[i];

                Vector3 newPoint = origin + v * t;
                if ((newPoint[j] >= minMax.first[j] && (newPoint[j] <= minMax.second[j])) &&
                    (newPoint[k] >= minMax.first[k] && (newPoint[k] <= minMax.second[k])))
                {
                    return std::make_pair(newPoint, true);
                }
            }
            // Repeat for the opposite face
            if (std::signbit(origin[i] - minMax.second[i]) != std::signbit(newRay[i] - minMax.second[i]))
            {
                float t = (minMax.second[i] - origin[i]) / v[i];

                Vector3 newPoint = origin + v * t;
                if ((newPoint[j] >= minMax.first[j] && (newPoint[j] <= minMax.second[j])) &&
                    (newPoint[k] >= minMax.first[k] && (newPoint[k] <= minMax.second[k])))
                {
                    return std::make_pair(newPoint, true);
                }
            }
        }

        return std::make_pair(Vector3(std::numeric_limits<float>::infinity()), false);
    }
    /// Check if the two sphere collide together
    bool                        SpheretoSphere(const Sphere& _alpha, const Sphere& _beta)
    {
        // Calcul the distance squared between center of the two sphere
        float distanceSquared = (_alpha.GetCenter().m_x - _beta.GetCenter().m_x) * (_alpha.GetCenter().m_x - _beta.GetCenter().m_x) +
                                (_alpha.GetCenter().m_y - _beta.GetCenter().m_y) * (_alpha.GetCenter().m_y - _beta.GetCenter().m_y) +
                                (_alpha.GetCenter().m_z - _beta.GetCenter().m_z) * (_alpha.GetCenter().m_z - _beta.GetCenter().m_z);

        // If the previous result is inferior to the two radius added and powered then there is collision
        return distanceSquared < ((_alpha.GetRadius() + _beta.GetRadius()) * (_alpha.GetRadius() + _beta.GetRadius()));
    }
    /// Check if the sphere collide with the box
    std::pair<float, bool>      SphereToAABB(const Sphere& _sphere, const Box& _box)
    {
        float squaredDistance = 0.0f;
        bool collision = false;

        // Gets minimum and maximum vertices of the box
        std::pair<vertex3D, vertex3D> minMax = _box.GetMinMax();    
        Vector3 sphereCenter = _sphere.GetCenter();

        for (int axis = 0; axis < AABB_NORMAL_AXIS; axis++)
        {
            // If the center is between the min and max, then the distance is 0
            if (sphereCenter[axis] < minMax.first[axis])
                squaredDistance += (minMax.first[axis] - sphereCenter[axis]) * (minMax.first[axis] - sphereCenter[axis]);
            else if (sphereCenter[axis] > minMax.second[axis])
                squaredDistance += (sphereCenter[axis] - minMax.second[axis]) * (sphereCenter[axis] - minMax.second[axis]);
        }

        /* 
        * Collision will happen if the (squared) distance between the sphere
        * and the box is inferior to the (squared) radius of the sphere 
        */
        collision = squaredDistance <= (_sphere.GetRadius() * _sphere.GetRadius());

        return std::pair<float, bool>(squaredDistance, collision);
    }
    /// Check if the point is in the sphere
    bool                        PointToSphere(const point3D& _point, const Sphere& _sphere)
    {
        // Calcul the distance squared between the point and the center of the sphere
        float distanceSquared = _point.distanceSquaredFrom(_sphere.GetCenter());

        /* 
        * If this distance is < to the radius of the sphere powered then the point
        * is in the sphere
        */
        return distanceSquared < (_sphere.GetRadius() * _sphere.GetRadius());
    }
    /// Check if the point is in the box
    bool                        PointToAABB(const point3D& _point, const Box& _box)
    {
        // Gets minimum and maximum vertices of the box
        std::pair<vertex3D, vertex3D> minMax = _box.GetMinMax();

        return (
            _point.m_x >= minMax.first.m_x &&
            _point.m_x <= minMax.second.m_x &&
            _point.m_y >= minMax.first.m_y &&
            _point.m_y <= minMax.second.m_y &&
            _point.m_z >= minMax.first.m_z &&
            _point.m_z <= minMax.second.m_z);
    }
    /// Check if the two boxes are colliding
    bool                        AABBToAABB(const Box& _alpha, const Box& _beta)
    {
        // Gets minimum and maximum vertices of the first box
        std::pair<vertex3D, vertex3D> minMax1 = _alpha.GetMinMax();
        // Gets minimum and maximum vertices of the second box
        std::pair<vertex3D, vertex3D> minMax2 = _beta.GetMinMax();

        for (int axis = 0; axis < AABB_NORMAL_AXIS; axis++)
        {
            // If there is a gap on at least one axis, there is no collision
            if (!(minMax1.first[axis] <= minMax2.second[axis] && minMax2.first[axis] <= minMax1.second[axis]))
            {
                return false;
            }
        }

        return true;
    }

} // !Namespace LibMath