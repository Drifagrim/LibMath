/// Header
#include "Intersection/3D/Box.h"

namespace LibMath
{
#pragma region Constructor
	
	/// Constructor

	/// Constructor with 5 parameters
	Box::Box(const point3D& _center, const float _width, const float _height, const float _depth, Matrix4 _rotation)
		: m_center(_center), m_width(_width), m_height(_height), m_depth(_depth), m_rotation(_rotation) {}
#pragma endregion

#pragma region Getter

	/// Getter

	/// Get the center of the box
	const point3D& Box::GetCenter() const
	{
		return m_center;
	}
	/// Get the rotation of the box
	const Matrix4& Box::GetRotation() const
	{
		return m_rotation;
	}
	/// Get the width of the box
	const float& Box::GetWidth() const
	{
		return m_width;
	}
	/// Get the height of the box
	const float& Box::GetHeight() const
	{
		return m_height;
	}
	/// Get the depth of the box
	const float& Box::GetDepth() const
	{
		return m_depth;
	}
	/// Get the min and the max between the box's vertex
	std::pair<vertex3D, vertex3D> Box::GetMinMax(void) const
	{
		/*
		* Set the start point to center to 
		* calcul min and max
		*/
		vertex3D min = m_center;
		vertex3D max = m_center;

		/*
		* Calcul the min of a vertex coordinates
		* by reducing the size of the box divide by two
		*/
		min.m_x -= m_width * 0.5f;
		min.m_y -= m_height * 0.5f;
		min.m_z -= m_depth * 0.5f;

		/*
		* Calcul the min of a vertex coordinates
		* by adding the size of the box divide by two
		*/
		max.m_x += m_width * 0.5f;
		max.m_y += m_height * 0.5f;
		max.m_z += m_depth * 0.5f;

		/*
		* Apply the rotation of the vertex in regard
		* to the rotation matrix (identity = no rotation)
		*/
		min = Vector4(min) * m_rotation;
		max = Vector4(max) * m_rotation;

		return std::make_pair(min, max);
	}
#pragma endregion

#pragma region Setter

	/// Setter

	/// Set the center of the box
	void Box::SetCenter(point3D _point)
	{
		m_center = _point;
	}
	/// Set the rotation of the box
	void Box::SetRotation(Matrix4 _matrix)
	{
		m_rotation = _matrix;
	}
	/// Set the width of the box
	void Box::SetWidth(float _value)
	{
		m_width = _value;
	}
	/// Set the height of the box
	void Box::SetHeight(float _value)
	{
		m_height = _value;
	}
	/// Set the depth of the box
	void Box::SetDepth(float _value)
	{
		m_depth = _value;
	}
#pragma endregion

} // !Namespace LibMath