///Header
#include "Intersection/2D/circle.h"

namespace LibMath
{
#pragma region Constructor
	 
	/// Circle constructor with two parameters
	Circle::Circle(const point2D& _center, float _radius)
	{
		m_center = _center;
		m_radius = _radius;
	}

#pragma endregion

#pragma region Getter

	/// Get the center of the circle
	const point2D& Circle::getCenter(void) const
	{
		return m_center;
	}
	/// Get the radius of the circle
	const float& Circle::getRadius(void) const
	{
		return m_radius;
	}

#pragma endregion

#pragma region Setter

	/// Set the center of the circle
	void Circle::setCenter(point2D _center)
	{
		m_center.m_x = _center.m_x;
		m_center.m_y = _center.m_y;
	}
	/// Set the radius of the circle
	void Circle::setRadius(float _radius)
	{
		m_radius = _radius;
	}

#pragma endregion

} // !Namespace LibMath