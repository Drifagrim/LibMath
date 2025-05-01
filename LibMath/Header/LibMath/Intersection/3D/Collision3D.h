#ifndef __LIBMATH__INTERSECTION__3D_COLLISION_H__
#define __LIBMATH__INTERSECTION__3D_COLLISION_H__

#pragma region Header

/// Standard librairies
#include <vector>

/// Intersection librairies
#include "../LibMath/Intersection.h"

/// Vector librairies
#include "../LibMath/Vector.h"

#pragma endregion

namespace LibMath
{
	/// Check if the ray collide with the sphere
	bool								RayToSphere(const Ray&, const Sphere&);
	/// Check if the ray collide with the box
	std::pair<LibMath::Vector3, bool>	RayToAABB(const Ray&, float, const Box&);
	/// Check is the two sphere collide together
	bool								SpheretoSphere(const Sphere&, const Sphere&);
	/// Check if the sphere collide with the box
	std::pair<float, bool>				SphereToAABB(const Sphere&, const Box&);
	/// Check if the point is in the sphere
	bool								PointToSphere(const point3D&, const Sphere&);
	/// Check if the point is in the box
	bool								PointToAABB(const point3D&, const Box&);
	/// Check if the two boxes collide together
	bool								AABBToAABB(const Box&, const Box&);

} // !Namespace LibMath

#endif // !__LIBMATH__INTERSECTION__3D_COLLISION_H__