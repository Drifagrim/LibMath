/// Header
#include "Intersection/3D/sphere.h"

namespace LibMath
{
#pragma region Constructor

	/// Constructor

	/// Construct the sphere in regard two parameters
	Sphere::Sphere(const point3D& _center, const float _radius) : 
		m_center(_center), m_radius(_radius) {}
#pragma endregion

#pragma region Getter

	/// Getter

	/// Get the center of the sphere
	const point3D& Sphere::GetCenter() const
	{
		return m_center;
	}
	/// Get the radius of the sphere
	const float& Sphere::GetRadius() const
	{
		return m_radius;
	}
#pragma endregion

#pragma region Setter

	/// Setter

	/// Set the center of the sphere
	void Sphere::SetCenter(point3D _point)
	{
		m_center = _point;
	}
	/// Set the radius of the sphere
	void Sphere::SetRadius(float _radius)
	{
		m_radius = _radius;
	}
#pragma endregion

} // !Namespace LibMath