#ifndef __LIBMATH__INTERSECTION__3D__RAY_H__
#define __LIBMATH__INTERSECTION__3D__RAY_H__

#pragma region Header

/// Intersection librairies
#include "../LibMath/Intersection/Point.h"

#pragma endregion

namespace LibMath
{
	class Ray
	{
	public:

#pragma region Constructor

		/// Constructor

						/// Default constructor set to delete by default
						Ray(void)					= delete;
						/// Copy constructor set to default
						Ray(const Ray&)				= default;
						/// Move constructor set to default
						Ray(Ray&&)					= default;
						/// Constructor with two parameters
		explicit		Ray(const point3D&, const Vector3&);
#pragma endregion

#pragma region Getter

		/// Getter

		/// Get the origin of the ray
		const point3D&	GetOrigin() const;
		/// Get the direction of the ray
		const Vector3&	GetDirection() const;
#pragma endregion

#pragma region Setter

		/// Setter

		/// Set the origin of the ray
		void			SetOrigin(point3D);
		/// Set the direction of the ray
		void			SetDirection(Vector3);
#pragma endregion

#pragma region In class operator

		/// In class operator

		/// Copy assignement set to default
		Ray&			operator=(const Ray& rhs)	= default;
		/// Move assignement set to default
		Ray&			operator=(Ray&& rhs)		= default;
#pragma endregion

#pragma region Destructor

		/// Destructor
			
						/// Destructor set to default
						~Ray()						= default;
#pragma endregion

	private:

		/// Variables
		point3D m_origin{ 0.f, 0.f, 0.f };
		Vector3 m_direction{ 0.f, 0.f, 0.f };

	}; // !Class Ray

} // !Namespace LibMath

#endif // !__LIBMATH__INTERSECTION__3D__RAY_H__