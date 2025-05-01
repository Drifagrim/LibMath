#ifndef __LIBMATH__INTERSECTION__3D__SPHERE_H__
#define __LIBMATH__INTERSECTION__3D__SPHERE_H__

#pragma region Header

/// Intersection librairies
#include "../LibMath/Intersection/point.h"

#pragma endregion

namespace LibMath
{
	class Sphere
	{
	public:

#pragma region Constructor

		/// Constructor

						/// Constructor by default set to delete by default
						Sphere(void)				= delete;
						/// Copy constructor set to default
						Sphere(const Sphere&)		= default;
						/// Move constructor set to default
						Sphere(Sphere&&)			= default;
						/// Constructor with two parameters with the radius set to 1.f by default
		explicit		Sphere(const point3D&, const float radius = 1.f);
#pragma endregion

#pragma region Getter

		/// Getter

		/// Get the center of the sphere
		const point3D&	GetCenter() const;
		/// Get the radius of the sphere
		const float&	GetRadius() const;
#pragma endregion

#pragma region Setter

		/// Setter

		/// Set the center of the sphere
		void			SetCenter(point3D);
		/// Set the radius of the sphere
		void			SetRadius(float);
#pragma endregion

#pragma region In class operator

		/// In class operator

		/// Copy assignement set to default
		Sphere&			operator=(const Sphere&)	= default;
		/// Move assignement set to default
		Sphere&			operator=(Sphere&& rhs)		= default;
#pragma endregion

#pragma region Destructor

		/// Destructor

						/// Destructor set to default
						~Sphere()					= default;
#pragma endregion

	private:


		point3D m_center{ Vector3::zero() };
		float	m_radius{ 0.f };

	}; // !Class Sphere

} // !Namespace LibMath

#endif // !__LIBMATH__INTERSECTION__3D__SPHERE_H__