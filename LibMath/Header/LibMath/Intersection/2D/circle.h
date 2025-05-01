#ifndef __LIBMATH__INTERSECTION__2D__CIRCLE_H__
#define __LIBMATH__INTERSECTION__2D__CIRCLE_H__

#pragma region Header

///Intersection librairies
#include "../point.h"

#pragma endregion

namespace LibMath
{
	class Circle
	{
	public :

#pragma region Constructor

						/// Delete the default constructor
						Circle(void)				= delete;
						/// Set to default copy constructor
						Circle(const Circle&)		= default;
						/// Set to default move constructor
						Circle(Circle&&)			= default;
						/// Constructor with two parameters
		explicit		Circle(const point2D&, float _radius = 1.f);

#pragma endregion

#pragma region Getter

		/// Get the center of the circle
		const point2D&	getCenter(void) const;
		/// Get the radius of the circle
		const float&	getRadius(void) const;

#pragma endregion

#pragma region Setter

		/// Set the center of the circle
		void			setCenter(point2D);
		/// Set the radius of the circle
		void			setRadius(float);

#pragma endregion

#pragma region In class operator

		/// Set to default copy assignement
		Circle&			operator=(const Circle&)	= default;
		/// Set to default move assignement
		Circle&			operator=(Circle&&)			= default;

#pragma endregion

#pragma region Destructor

						/// Set to default destructor
						~Circle(void)				= default;

#pragma endregion

	private :

		///Variables
		point2D			m_center{ 0.f, 0.f };
		float			m_radius{ 0.f };

	}; // !Class Circle

} // !Namespace LibMath

#endif // !__LIBMATH__INTERSECTION__2D__CIRCLE_H__