#ifndef __LIBMATH__INTERSECTION__2D__RECTANGLE_H__
#define __LIBMATH__INTERSECTION__2D__RECTANGLE_H__

#pragma region Header

/// Standard librairies
#include <vector>

/// Intersection librairies
#include "../point.h"
#include "line.h"

/// Angle librairies
#include "../LibMath/Angle.h"

#pragma endregion

namespace LibMath
{
	class Rectangle
	{
	public:

#pragma region Contructor

		///Constructor

										/// Delete default constructor
										Rectangle(void)				= delete;
										/// Set to default copy constructor
										Rectangle(const Rectangle&) = default;
										///Set to default move constructor
										Rectangle(Rectangle&&)		= default;
										/// Constructor with four parameters
		explicit						Rectangle(const point2D, float, float, Degree _rotation = 0_deg);
#pragma endregion

#pragma region Getter

		///Getter

		/// Get center coordinates
		const point2D&					GetCenter(void) const;
		/// Get the size
		const Vector2					GetSize(void) const; 
		/// Get the width
		const float&					GetWidth(void) const;
		/// Get the height
		const float&					GetHeight(void) const;
		/// Get the rotation
		const Degree&					GetRotation(void) const;
		/// Get the vertices
		std::vector<vertex2D>			GetVertices(void) const;
		/// Get the min and the max
		std::pair<vertex2D, vertex2D>	GetMinMax(void) const;
		/// Get the lines
		std::vector<Line>				GetSides(void) const;
#pragma endregion

#pragma region Setter

		///Setter

		/// Set the center
		void							SetCenter(point2D);
		/// Set the size
		void							SetSize(Vector2);
		/// Set the width
		void							SetWidth(float);
		/// Set the height
		void							SetHeight(float);
		/// Set the rotation
		void							SetRotation(Degree);
#pragma endregion

#pragma region In class operator

		///In class operator

		/// Set to default the copy assignement
		Rectangle&						operator=(const Rectangle&) = default;
		/// Set to default the move assignement
		Rectangle&						operator=(Rectangle&&)		= default;
#pragma endregion

#pragma region Destructor

		///Destructor

										/// Set to default the destructor
										~Rectangle(void)			= default;
#pragma endregion

	private:

		/// Variables
		point2D m_center{ 0.f, 0.f };
		Degree	m_rotation{ 0.f };
		float	m_width{ 0.f };
		float	m_height{ 0.f };

	}; // !Class Rectangle

} // !Namespace LibMath

#endif // !__LIBMATH__INTERSECTION__2D__RECTANGLE_H__