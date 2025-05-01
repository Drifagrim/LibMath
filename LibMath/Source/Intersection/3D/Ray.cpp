/// Header
#include "Intersection/3D/Ray.h"

namespace LibMath
{
#pragma region Constructor
	/// Constructor

	/// Construct the ray in regard two parameters
	Ray::Ray(const point3D& _origin, const Vector3& _direction) : 
		m_origin(_origin), m_direction(_direction) {}
#pragma endregion

#pragma region Getter

	/// Getter

	/// Get the origin of the ray
	const point3D& Ray::GetOrigin() const
	{
		return m_origin;
	}
	/// Get the direction of the ray
	const Vector3& Ray::GetDirection() const
	{
		return m_direction;
	}
#pragma endregion

#pragma region Setter

	/// Setter

	/// Set the origin of the ray
	void Ray::SetOrigin(point3D _point)
	{
		m_origin = _point;
	}
	/// Set the direction of the ray
	void Ray::SetDirection(Vector3 _direction)
	{
		m_direction = _direction;
	}
#pragma endregion

} // !Namespace LibMath