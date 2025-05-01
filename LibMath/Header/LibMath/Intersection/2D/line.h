#ifndef __LIBMATH__INTERSECTION__2D__LINE_H__
#define __LIBMATH__INTERSECTION__2D__LINE_H__

#pragma region Header

/// Intersection librairies
#include "../point.h"

#pragma endregion

namespace LibMath
{
	class Line
	{
	public:

#pragma region Constructor

		/// Constructor

						/// Delete the default constructor
						Line(void)				= delete;
						/// Set to default the copy constructor
						Line(const Line&)		= default;
						/// Set to deefault the move contructor
						Line(Line&&)			= default;
						/// Explicit constructor
		explicit		Line(const point2D&, const point2D&);
#pragma endregion

#pragma region Getter

		/// Getter

		/// Get the start point
		const point2D&	GetStart(void) const;
		/// Get the end point
		const point2D&	GetEnd(void) const;
		/// Get the slope between a start point and an end point
		const float		GetSlope(void) const;
#pragma endregion

#pragma region Setter

		/// Setter

		/// Set the value of the start point
		void			SetStart(point2D);
		/// Set the value of the end point
		void			SetEnd(point2D);
#pragma endregion

#pragma region Other functions

		/// Other functions

		/// Calcul the length of the line
		float			Length(void) const;
		/// Calcul the squared length of the line
		float			LengthSquared(void) const;
#pragma endregion

#pragma region In class operator

		/// In class operator

		/// Set to default the copy assignement operator
		Line&			operator=(const Line&)	= default;
		/// Set to default the move assignement operator
		Line&			operator=(Line&&)		= default;
#pragma endregion

#pragma region Destructor

		/// Destructor

						/// Set to default the destructor
						~Line(void)				= default;
#pragma endregion

	private:

		/// Variables
		point2D m_start{ 0.f, 0.f };
		point2D m_end{ 0.f, 0.f };

	}; // !Class Line

} // !Namespace LibMath

#endif // !__LIBMATH__INTERSECTION__2D__LINE_H__