#ifndef __LIBMATH__INTERPOLATION_H__
#define __LIBMATH__INTERPOLATION_H__

#pragma region Header

/// Angle librairy
#include "Angle.h"

/// Vector librairy
#include "Vector.h"

#pragma endregion

namespace LibMath
{
	/// Linear interpolation between first and second float by third float
	float	Lerp(float&, float&, float);
	/// Linear interpolation between first and second vector2 by third float
	Vector2	Lerp(Vector2&, Vector2&, float);
	/// Linear interpolation between first and second vector3 by third float
	Vector3	Lerp(Vector3&, Vector3&, float);
	/// Linear interpolation between first and second vector4 by third float
	Vector4	Lerp(Vector4&, Vector4&, float);
	/// Linear interpolation between first and second Radian by third float
	Radian	Lerp(Radian&, Radian&, float);
	/// Linear interpolation between first and second Degree by third float
	Degree	Lerp(Degree&, Degree&, float);
	/// Linear interpolation between first and second vector2 by third vector2
	Vector2	Bilerp(Vector2&, Vector2&, Vector2&);

} // !Namespace LibMath

#endif // !__LIBMATH__INTERPOLATION_H__