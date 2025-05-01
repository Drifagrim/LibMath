#ifndef __LIBMATH__INTERSECTION__3D__BOX_H__
#define __LIBMATH__INTERSECTION__3D__BOX_H__

#pragma region Header

/// Standard librairies
#include <vector>

/// Intersection librairies
#include "../LibMath/Intersection/point.h"
#include "../LibMath/Intersection/3D/Ray.h"

/// Matrix librairies
#include "../LibMath/Matrix.h"

/// Vector librairies
#include "../LibMath/Vector.h"

#pragma endregion

#pragma region Define

#define AABB_NORMAL_AXIS 3

#pragma endregion

namespace LibMath
{
	class Box
	{
	public:

#pragma region Constructor

		///Constructor

										/// Constructor without parameter set by default
										Box()						= default;
										/// Constructor with 5 parameters
		explicit						Box(const point3D& center, const float width,
			const float height, const float depth, Matrix4 rotation = Matrix4::Identity());
										/// Copy constructor set by default
										Box(const Box& other)		= default;
										/// Move constructor set by default
										Box(Box&& other)			= default;
#pragma endregion

#pragma region Getter

		///Getter

		/// Get the center of the box
		const point3D&					GetCenter(void) const;
		/// Get the rotation of the box
		const Matrix4&					GetRotation(void) const;
		/// Get the width of the box
		const float&					GetWidth(void) const;
		/// Get the height of the box
		const float&					GetHeight(void) const;
		/// Get the depth of the box
		const float&					GetDepth(void) const;
		/// Get the min and the max between the box's vertex
		std::pair<vertex3D, vertex3D>	GetMinMax(void) const;
#pragma endregion

#pragma region Setter

		///Setter

		/// Set the center of the box
		void							SetCenter(point3D);
		/// Set the rotation of the box
		void							SetRotation(Matrix4);
		/// Set the width of the box
		void							SetWidth(float);
		/// Set the height of the box
		void							SetHeight(float);
		/// Set the depth of the box
		void							SetDepth(float);
#pragma endregion

#pragma region In class operator

		/// In class operator

		/// Copy assignement set to default
		Box&							operator=(const Box& rhs)	= default;
		/// Move assignement set to default
		Box&							operator=(Box&& rhs)		= default;
#pragma endregion

#pragma region Destructor

		///Destructor

										/// Destructor set to default
										~Box() = default;
#pragma endregion
	private:

		///Variables

		point3D m_center{ Vector3::zero() };
		Matrix4 m_rotation{ Matrix4::Matrix4(0.f) };
		float m_width{ 0.f };
		float m_height{ 0.f };
		float m_depth{ 0.f };

	}; // !Class Box

} // !Namespace LibMath

#endif // !__LIBMATH__INTERSECTION__3D__BOX_H__