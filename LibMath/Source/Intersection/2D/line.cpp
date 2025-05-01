/// Header
#include "Intersection/2D/line.h"

#include "Arithmetic.h"

namespace LibMath
{
#pragma region Constructor

	/// Constructor with a start point and an end point as parameters
	Line::Line(const point2D& _start, const point2D& _end)
	{
		m_start = _start;
		m_end	= _end;
	}

#pragma endregion

#pragma region Getter

	/// Get the start point of the line
	const point2D& Line::GetStart(void) const
	{
		return m_start;
	}
	/// Get the end point of the line
	const point2D& Line::GetEnd(void) const
	{
		return m_end;
	}
	/// Get the slope of the line
	const float Line::GetSlope(void) const
	{
		return ((m_end.m_y - m_start.m_y) / (m_end.m_x - m_start.m_x));
	}

#pragma endregion

#pragma region Setter
	
	/// Set the start point
	void Line::SetStart(point2D _start)
	{
		m_start = _start;
	}
	/// Set the end point
	void Line::SetEnd(point2D _end)
	{
		m_end = _end;
	}

#pragma endregion

#pragma region Other functions
	
	/// Calcul the length of the line
	float Line::Length(void) const
	{
		float x = (m_end.m_x - m_start.m_x);
		float y = (m_end.m_y - m_start.m_y);

		return squareRoot(x * x + y * y);
	}
	/// Calcul thee squared length of the line
	float Line::LengthSquared(void) const
	{
		float x = (m_end.m_x - m_start.m_x);
		float y = (m_end.m_y - m_start.m_y);

		return (x * x + y * y);
	}

#pragma endregion

} // !Namespace LibMath