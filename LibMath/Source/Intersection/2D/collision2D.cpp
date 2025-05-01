///Header
#include "Intersection/2D/collision2D.h"

namespace LibMath
{
	/// Check collision between two circle
	bool collisionCheck(const Circle& _first, const Circle& _second)
	{
		// Calcul the distance between center of two circles
		float distanceBetweenCenter = (_second.getCenter() - _first.getCenter()).squareMagnitude();

		// Add the two radius 
		float sumRadius = _first.getRadius() + _second.getRadius();

		/*
		* If the distance between center is <= to power(radius)
		* there is collision
		*/
		if (distanceBetweenCenter <= (sumRadius * sumRadius))
			return true;

		return false;
	}
	/// Check collision between a circle and a rectangle
	bool collisionCheck(const Circle& _circle, const Rectangle& _rectangle)
	{
		// Get the sides of the rectangle
		std::vector<Line> sides = _rectangle.GetSides();

		for (int i = 0; i < 4; i++)
		{
			/*
			* For each side of the rectangle check the collision
			* between sphere and line by calling the function
			* collision check between sphere and line
			*/
			if (collisionCheck(_circle, sides[i]))
				return true;
		}

		return false;
	}
	/// Check collision between a circle and a line
	bool collisionCheck(const Circle& _circle, const Line& _line)
	{
		point2D circleCenter = _circle.getCenter();
		point2D lineStart = _line.GetStart();
		point2D lineEnd = _line.GetEnd();

		float dot = ((circleCenter.m_x - lineStart.m_x) * (lineEnd.m_x - lineStart.m_x)) +
					((circleCenter.m_y - lineStart.m_y) * (lineEnd.m_y - lineStart.m_y)) /
					_line.LengthSquared();

		point2D closest
		{
			lineStart.m_x + (dot * (lineEnd.m_x - lineStart.m_x)),
			lineStart.m_y + (dot * (lineEnd.m_y - lineStart.m_y))
		};

		Vector2 lineCenter(closest - circleCenter);

		if (lineCenter.squareMagnitude() <= _circle.getRadius() * _circle.getRadius())
			return true;

		return false;
	}
	/// Check collision between two line
	bool collisionCheck(const Line& _first, const Line& _second)
	{
		float firstDistance =	((_second.GetEnd().m_x - _second.GetStart().m_x) * (_first.GetStart().m_y - _second.GetStart().m_y) -
								(_second.GetEnd().m_y - _second.GetStart().m_y) * (_first.GetStart().m_x - _second.GetStart().m_x)) /
								((_second.GetEnd().m_y - _second.GetStart().m_y) * (_first.GetEnd().m_x - _first.GetStart().m_x) -
								(_second.GetEnd().m_x - _second.GetStart().m_x) * (_first.GetEnd().m_y - _first.GetStart().m_y));

		float secondDistance =	((_first.GetEnd().m_x - _first.GetStart().m_x) * (_first.GetStart().m_y - _second.GetStart().m_y) -
								(_first.GetEnd().m_y - _first.GetStart().m_y) * (_first.GetStart().m_x - _second.GetStart().m_x)) /
								((_second.GetEnd().m_y - _second.GetStart().m_y) * (_first.GetEnd().m_x - _first.GetStart().m_x) -
								(_second.GetEnd().m_x - _second.GetStart().m_x) * (_first.GetEnd().m_y - _first.GetStart().m_y));

		if (firstDistance >= 0 && firstDistance <= 1 && secondDistance >= 0 && secondDistance <= 1)
			return true;

		return false;
	}
	/// Check collision between a line and a rectangle
	bool collisionCheck(const Line& _line, const Rectangle& _rectangle)
	{
		// Get the sides of the rectangle
		std::vector<Line> sides = _rectangle.GetSides();

		for (int i = 0; i < 4; i++)
		{
			/*
			* Check the collision between rectangle's side and line
			* by calling the function collision check between two lines
			*/
			if (collisionCheck(_line, sides[i]))
				return true;
		}

		return false;
	}
	/// Check AABB collision between two rectangle
	bool collisionCheckAABB(const Rectangle& _first, const Rectangle& _second)
	{
		std::pair<vertex2D, vertex2D> _firstMinMax = _first.GetMinMax();
		std::pair<vertex2D, vertex2D> _secondMinMax = _second.GetMinMax();

		if (_firstMinMax.first.m_x < _secondMinMax.second.m_x &&
			_firstMinMax.first.m_y < _secondMinMax.second.m_y &&
			_secondMinMax.first.m_x < _firstMinMax.second.m_x &&
			_secondMinMax.first.m_y < _firstMinMax.second.m_y)
			return true;

		return false;
	}
	/// Check OBB collision between two rectangle
	bool collisionCheckOBB(const Rectangle& _first, const Rectangle& _second)
	{
		std::vector<vertex2D> _firstVertices = _first.GetVertices();
		std::vector<vertex2D> _secondVertices = _second.GetVertices();

		for (int i = 0; i < _firstVertices.size(); ++i)
		{
			Vector2 normalVector(_firstVertices[i].m_y, -(_firstVertices[i].m_x));

			if (!sat(normalVector, _firstVertices, _secondVertices))
				return false;
		}

		for (int i = 0; i < _secondVertices.size(); ++i)
		{
			Vector2 normalVector(_secondVertices[i].m_y, -(_secondVertices[i].m_y));

			if (!sat(normalVector, _firstVertices, _secondVertices))
				return false;
		}

		return true;
	}
	/// Check OBB collision between vertices
	bool collisionCheckOBB(std::vector<vertex2D>& _first, std::vector<vertex2D>& _second)
	{
		for (int i = 0; i < _first.size(); ++i)
		{
			Vector2 normalVector(_first[i].m_y, -(_first[i].m_x));

			if (!sat(normalVector, _first, _second))
				return false;
		}

		for (int i = 0; i < _second.size(); ++i)
		{
			Vector2 normalVector(_second[i].m_y, -(_second[i].m_y));

			if (!sat(normalVector, _first, _second))
				return false;
		}

		return true;
	}
	/// Check SAT between a vector and vertices
	bool sat(Vector2& normalVector, std::vector<vertex2D>& _first, std::vector<vertex2D>& _second)
	{
		float   maxFirst	= normalVector.dotProduct(_first[0]), minFirst = normalVector.dotProduct(_first[0]);
		float   maxSecond	= normalVector.dotProduct(_second[0]), minSecond = normalVector.dotProduct(_second[0]);
		float   result		= 0.f;

		for (unsigned int i = 1; i < _first.size(); i++)
		{
			result = normalVector.dotProduct(_first[i]);

			if (result > maxFirst)
			{
				maxFirst = result;
				continue;
			}
			else if (result < minFirst)
			{
				minFirst = result;
			}
		}

		for (unsigned int i = 1; i < _second.size(); i++)
		{
			result = normalVector.dotProduct(_second[i]);
			if (result > maxSecond)
			{
				maxSecond = result;
				continue;
			}
			else if (result < minSecond)
			{
				minSecond = result;
			}
		}

		if (!(maxFirst >= minSecond && maxSecond >= minFirst))
		{
			return false;
		}

		return true;
	}
	/// Check collision between a point and a circle
	bool collisionCheck(const point2D& _point, const Circle& _circle)
	{
		if (Vector2(_point - _circle.getCenter()).squareMagnitude() <= _circle.getRadius() * _circle.getRadius())
			return true;

		return false;
	}
	/// Check collision between a point and a rectangle
	bool collisionCheck(const point2D& _point, const Rectangle& _rectangle)
	{
		std::pair<vertex2D, vertex2D> rectangleMinMax = _rectangle.GetMinMax();

		if (_point.m_x >= rectangleMinMax.first.m_x &&
			_point.m_y >= rectangleMinMax.first.m_y &&
			_point.m_x <= rectangleMinMax.second.m_x &&
			_point.m_y <= rectangleMinMax.second.m_y)
			return true;

		return false;
	}
	/// Check collision between a point and a line
	bool collisionCheck(const point2D& _point, const Line& _line)
	{
		float lineSlope = _line.GetSlope();
		// retrieved from line equation y = mx + b
		float b			= -lineSlope * _line.GetStart().m_x + _line.GetStart().m_y;

		if ((_point.m_x * lineSlope + b) == _point.m_y)
			return true;

		return false;
	}

} // !Namespace LibMath