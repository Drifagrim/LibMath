#include "Interpolation.h"

namespace LibMath
{
	/// Linear interpolation between first and second float by third float
	float Lerp(float& _alpha, float& _bravo, float _ratio)
	{
		if (_ratio == 0)
			return _alpha;
		else if (_ratio == 1.f)
			return _bravo;

		return (_bravo - _alpha) * _ratio + _alpha;
	}
	/// Linear interpolation between first and second vector2 by third float
	Vector2 Lerp(Vector2& _charlie, Vector2& _delta, float _ratio)
	{
		if (_ratio == 0)
			return _charlie;
		else if (_ratio == 1.f)
			return _delta;

		return (_delta - _charlie) * _ratio + _charlie;
	}
	/// Linear interpolation between first and second vector3 by third float
	Vector3 Lerp(Vector3& _echo, Vector3& _foxtrot, float _ratio)
	{
		if (_ratio == 0)
			return _echo;
		else if (_ratio == 1.f)
			return _foxtrot;

		return (_foxtrot - _echo) * _ratio + _echo;
	}
	/// Linear interpolation between first and second vector4 by third float
	Vector4 Lerp(Vector4& _kilo, Vector4& _lima, float _ratio)
	{
		if (_ratio == 0)
			return _kilo;
		else if (_ratio == 1.f)
			return _lima;

		return (_lima - _kilo) * _ratio + _kilo;
	}
	/// Linear interpolation between first and second Radian by third float
	Radian Lerp(Radian& _mike, Radian& _november, float _ratio)
	{
		if (_ratio == 0)
			return _mike;
		else if (_ratio == 1.f)
			return _november;

		return Radian((_november.raw() - _mike.raw()) * _ratio + _mike.raw());
	}
	/// Linear interpolation between first and second Degree by third float
	Degree Lerp(Degree& _oscar, Degree& _papa, float _ratio)
	{
		if (_ratio == 0)
			return _oscar;
		else if (_ratio == 1.f)
			return _papa;

		return Degree((_papa.raw() - _oscar.raw()) * _ratio + _oscar.raw());
	}
	/// Linear interpolation between first and second vector2 by third vector2
	Vector2 Bilerp(Vector2& _quebec, Vector2& _romeo, Vector2& _ratio)
	{
		return Vector2(Lerp(_quebec.m_x, _romeo.m_x, _ratio.m_x), Lerp(_quebec.m_y, _romeo.m_y, _ratio.m_y));
	}

} // !Namespace LibMath