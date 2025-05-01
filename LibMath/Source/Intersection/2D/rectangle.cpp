/// Header
#include "Intersection/2D/rectangle.h"

#include "Trigonometry.h"

namespace LibMath
{
#pragma region Constructor

	/// Constructor of the rectangle
	Rectangle::Rectangle(const point2D _center, float _width, float _height, Degree _rotation)
	{
		m_center	= _center;
		m_width		= _width;
		m_height	= _height;
		m_rotation	= _rotation;
	}

#pragma endregion

#pragma region Getter
	
	/// Get the center of the rectangle
	const point2D& Rectangle::GetCenter(void) const
	{
		return m_center;
	}
	/// Get the size of the rectangle
	const Vector2 Rectangle::GetSize(void) const
	{
		return Vector2(m_width, m_height);
	}
	/// Get the width of the rectangle
	const float& Rectangle::GetWidth(void) const
	{
		return m_width;
	}
	/// Get the height of the rectangle
	const float& Rectangle::GetHeight(void) const
	{
		return m_height;
	}
	/// Get the rotation of the rectangle
	const Degree& Rectangle::GetRotation(void) const
	{
		return m_rotation;
	}
	/// Get the vertices of the rectangle
	std::vector<vertex2D> Rectangle::GetVertices(void) const
	{
		std::vector<vertex2D> vertices;

		Radian firstRotation = (m_rotation + 135_deg);
		Radian secondRotation = (m_rotation + 45_deg);

		vertex2D firstVertex
		{
			m_center.m_x + cos(firstRotation) * m_width,
			m_center.m_y + sin(firstRotation) * m_height
		};

		vertex2D secondVertex
		{
			m_center.m_x + cos(secondRotation) * m_width,
			m_center.m_y + sin(secondRotation) * m_height
		};

		vertex2D thirdVertex
		{
			m_center.m_x - cos(firstRotation) * m_width,
			m_center.m_y - sin(firstRotation) * m_height
		};

		vertex2D fourthVertex
		{
			m_center.m_x - cos(secondRotation) * m_width,
			m_center.m_y - sin(secondRotation) * m_height
		};

		vertices.push_back(firstVertex);
		vertices.push_back(secondVertex);
		vertices.push_back(thirdVertex);
		vertices.push_back(fourthVertex);

		return std::vector<vertex2D>(vertices);
	}
	/// Get the min and the max between rectangle vertices
	std::pair<vertex2D, vertex2D> Rectangle::GetMinMax(void) const
	{
		std::vector<vertex2D> vertices = this->GetVertices();

		vertex2D min = vertices[0];
		vertex2D max = vertices[0];

		for (int i = 1; i < 4; i++)
		{
			if (vertices[i].m_x < min.m_x)
				min.m_x = vertices[i].m_x;
			if (vertices[i].m_y < min.m_y)
				min.m_y = vertices[i].m_y;

			if (vertices[i].m_x > max.m_x)
				max.m_x = vertices[i].m_x;
			if (vertices[i].m_y > max.m_y)
				max.m_y = vertices[i].m_y;
		}

		return std::pair<vertex2D, vertex2D>(min, max);
	}
	/// Get the sides of the rectangle
	std::vector<Line> Rectangle::GetSides(void) const
	{
		std::vector<Line> sides;
		std::vector<vertex2D> vertices = this->GetVertices();

		for (int i = 0; i < 3; i++)
			sides.emplace_back(vertices[i], vertices[i + 1]);

		sides.emplace_back(vertices[3], vertices[0]);

		return std::vector<Line>(sides);
	}

#pragma endregion

#pragma region Setter

	/// Set the center of the rectangle
	void Rectangle::SetCenter(point2D _center)
	{
		m_center = _center;
	}
	/// Set the size of the rectangle
	void Rectangle::SetSize(Vector2 _size)
	{
		m_width		= _size.m_x;
		m_height	= _size.m_y;
	}
	/// Set the width of the rectangle
	void Rectangle::SetWidth(float _width)
	{
		m_width = _width;
	}
	/// Set the height of the rectangle
	void Rectangle::SetHeight(float _height)
	{
		m_height = _height;
	}
	/// Set the rotation of the rectangle
	void Rectangle::SetRotation(Degree _rotation)
	{
		m_rotation = _rotation;
	}

#pragma endregion

} // !Namespace LibMath