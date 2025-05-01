#ifndef __LIBMATH__INTERSECTION__2D__COLLISION_H__
#define __LIBMATH__INTERSECTION__2D__COLLISION_H__

#pragma region Header

///Standard librairies
#include <vector>

///Intersection librairies
#include "../LibMath/Intersection.h"

#pragma endregion

namespace LibMath
{
	/// Check the collision between two circle
	bool					collisionCheck(const Circle&, const Circle&);
	/// Check the collision between a circle and a rectangle
	bool					collisionCheck(const Circle&, const Rectangle&);
	/// Check the collision between a circle and a line
	bool					collisionCheck(const Circle&, const Line&);

	/// Check the collision between two line
	bool					collisionCheck(const Line&, const Line&);
	/// Check the collision between a line and a rectangle
	bool					collisionCheck(const Line&, const Rectangle&);

	/// Check the AABB collision between two rectangle
	bool					collisionCheckAABB(const Rectangle&, const Rectangle&);
	/// Check the OBB collision between two rectangle
	bool					collisionCheckOBB(const Rectangle&, const Rectangle&);
	
	/// Check the OBB collision between different vertex
	bool					collisionCheckOBB(std::vector<vertex2D>&, std::vector<vertex2D>&);
	
	/// Check the SAT between a vector and different vertex
	bool					sat(Vector2&, std::vector<vertex2D>&, std::vector<vertex2D>&);

	/// Check the collision between a point and a circle
	bool					collisionCheck(const point2D&, const Circle&);
	/// Check the collision between a point and a rectangle
	bool					collisionCheck(const point2D&, const Rectangle&);
	/// Check the collision between a point and a line
	bool					collisionCheck(const point2D&, const Line&);

	/// Calcul the intersection point between two circle
	std::vector<point2D>	intersection(const Circle&, const Circle&);
	/// Calcul the intersection point between a circle and a rectangle
	std::vector<point2D>	intersection(const Circle&, const Rectangle&);
	/// Calcul the intersection point between a circle and a line
	std::vector<point2D>	intersection(const Circle&, const Line&);

	/// Calcul the intersection point between two line
	point2D					intersection(const Line&, const Line&);

	/// Calcul the intersection point between a line and a rectangle
	std::vector<point2D>	intersection(const Line&, const Rectangle&);

	/// Calcul the intersection point between two rectangle
	std::vector<point2D>	intersection(const Rectangle&, const Rectangle&);
	
} // !Namespace LibMath

#endif // !__LIBMATH__INTERSECTION__2D__COLLISION_H__