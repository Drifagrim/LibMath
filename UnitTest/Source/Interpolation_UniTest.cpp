#include "LibMath/Interpolation.h"
#include "LibMath/Trigonometry.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#define GLM_FORCE_SILENT_WARNINGS
#include <glm/glm.hpp>

TEST_CASE("Interpolation", "[.all][lerp]")
{
	/* Float lerp */
	{
		float half = 0.5f, quarter = 0.25f, threeQuarter = 0.75f;

		float positiveAlpha = 1.f, negativeAlpha = -3.5f, positiveBeta = 3.5f, negativeBeta = -1.f;

		CHECK(LibMath::Lerp(positiveAlpha, positiveBeta, half) == 2.25f);
		CHECK(LibMath::Lerp(negativeAlpha, positiveBeta, half) == 0.f);
		CHECK(LibMath::Lerp(positiveAlpha, negativeBeta, half) == 0.f);
		CHECK(LibMath::Lerp(negativeAlpha, negativeBeta, half) == -2.25f);

		CHECK(LibMath::Lerp(positiveAlpha, positiveBeta, quarter) == 1.625f);
		CHECK(LibMath::Lerp(negativeAlpha, positiveBeta, quarter) == -1.75f);
		CHECK(LibMath::Lerp(positiveAlpha, negativeBeta, quarter) == 0.5f);
		CHECK(LibMath::Lerp(negativeAlpha, negativeBeta, quarter) == -2.875f);

		CHECK(LibMath::Lerp(positiveAlpha, positiveBeta, threeQuarter) == 2.875);
		CHECK(LibMath::Lerp(negativeAlpha, positiveBeta, threeQuarter) == 1.75f);
		CHECK(LibMath::Lerp(positiveAlpha, negativeBeta, threeQuarter) == -0.5f);
		CHECK(LibMath::Lerp(negativeAlpha, negativeBeta, threeQuarter) == -1.625f);
	}

	/* Vec2 lerp */
	{
		float half = 0.5f, zero = 0.f, one = 1.f;

		LibMath::Vector2 first(1.f, 3.5f), second(-3.5f, 3.5f), third(1.f, -1.f), fourth(-3.5f, -1.f);

		CHECK(LibMath::Lerp(first, second, half) == LibMath::Vector2(-1.25f, 3.5f));
		CHECK(LibMath::Lerp(first, third, half) == LibMath::Vector2(1.f, 1.25f));
		CHECK(LibMath::Lerp(first, fourth, half) == LibMath::Vector2(-1.25f, 1.25f));

		CHECK(LibMath::Lerp(second, first, half) == LibMath::Vector2(-1.25f, 3.5f));
		CHECK(LibMath::Lerp(second, third, half) == LibMath::Vector2(-1.25f, 1.25f));
		CHECK(LibMath::Lerp(second, fourth, half) == LibMath::Vector2(-3.5f, 1.25f));

		CHECK(LibMath::Lerp(third, first, half) == LibMath::Vector2(1.f, 1.25f));
		CHECK(LibMath::Lerp(third, second, half) == LibMath::Vector2(-1.25f, 1.25f));
		CHECK(LibMath::Lerp(third, fourth, half) == LibMath::Vector2(-1.25f, -1.f));

		CHECK(LibMath::Lerp(fourth, first, half) == LibMath::Vector2(-1.25f, 1.25f));
		CHECK(LibMath::Lerp(fourth, second, half) == LibMath::Vector2(-3.5f, 1.25f));
		CHECK(LibMath::Lerp(fourth, third, half) == LibMath::Vector2(-1.25f, -1.f));

		CHECK(LibMath::Lerp(first, second, zero) == first);
		CHECK(LibMath::Lerp(first, third, zero) == first);
		CHECK(LibMath::Lerp(first, fourth, zero) == first);

		CHECK(LibMath::Lerp(first, second, one) == second);
		CHECK(LibMath::Lerp(first, third, one) == third);
		CHECK(LibMath::Lerp(first, fourth, one) == fourth);
	}

	/* Vec3 lerp */
	{
		LibMath::Vector3 first(1.f), second(2.f, 2.f, -2.f), third(3.f, -3.f, 3.f), fourth(-4.f, 4.f, 4.f),
			fifth(5.f, -5.f, -5.f), sixth(-6.f, 6.f, -6.f), seventh(-7.f, -7.f, 7.f), eighth(-8.f);

		CHECK(LibMath::Lerp(first, second, 0.5f) == LibMath::Vector3(1.5f, 1.5f, -0.5f));
		CHECK(LibMath::Lerp(first, third, 0.5f) == LibMath::Vector3(2.f, -1.f, 2.f));
		CHECK(LibMath::Lerp(first, fourth, 0.5f) == LibMath::Vector3(-1.5f, 2.5f, 2.5f));
		CHECK(LibMath::Lerp(first, fifth, 0.5f) == LibMath::Vector3(3.f, -2.f, -2.f));
		CHECK(LibMath::Lerp(first, sixth, 0.5f) == LibMath::Vector3(-2.5f, 3.5f, -2.5f));
		CHECK(LibMath::Lerp(first, seventh, 0.5f) == LibMath::Vector3(-3.f, -3.f, 4.f));
		CHECK(LibMath::Lerp(first, eighth, 0.5f) == LibMath::Vector3(-3.5f, -3.5f, -3.5f));

		CHECK(LibMath::Lerp(first, first, 0.f) == first);
		CHECK(LibMath::Lerp(first, first, 0.5f) == first);
		CHECK(LibMath::Lerp(first, first, 1.f) == first);
	}

	/* Vec4 lerp */
	{
		float zero = 0.f, half = 0.5f, quarter = 0.25f, threeQuarter = 0.75f, one = 1.f;

		LibMath::Vector4 first(0.f, 1.f, 2.f, 3.f), second(7.f, 7.f, 7.f, 1.f);

		CHECK(LibMath::Lerp(first, second, zero) == first);
		CHECK(LibMath::Lerp(first, second, quarter) == LibMath::Vector4(1.75f, 2.5f, 3.25f, 2.5f));
		CHECK(LibMath::Lerp(first, second, half) == LibMath::Vector4(3.5f, 4.f, 4.5f, 2.f));
		CHECK(LibMath::Lerp(first, second, threeQuarter) == LibMath::Vector4(5.25f, 5.5f, 5.75f, 1.5f));
		CHECK(LibMath::Lerp(first, second, one) == second);

		CHECK(LibMath::Lerp(second, first, zero) == second);
		CHECK(LibMath::Lerp(second, first, quarter) == LibMath::Vector4(5.25f, 5.5f, 5.75f, 1.5f));
		CHECK(LibMath::Lerp(second, first, half) == LibMath::Vector4(3.5f, 4.f, 4.5f, 2.f));
		CHECK(LibMath::Lerp(second, first, threeQuarter) == LibMath::Vector4(1.75f, 2.5f, 3.25f, 2.5f));
		CHECK(LibMath::Lerp(second, first, one) == first);
	}

	/* Degree/Radian lerp */
	{
		float half = 0.5f, quarter = 0.25f, threeQuarter = 0.75f;

		LibMath::Degree ninetyDegrees(90.f), twoSeventyDegrees(270.f);
		LibMath::Radian halfPiRad(PI / 2), piRad(PI);

		CHECK(LibMath::Lerp(ninetyDegrees, twoSeventyDegrees, half) == LibMath::Degree(180.f));
		CHECK(LibMath::Lerp(twoSeventyDegrees, ninetyDegrees, half) == LibMath::Degree(180.f));
		CHECK(LibMath::Lerp(halfPiRad, piRad, half) == LibMath::Radian((PI / 2) * 1.5f));
		CHECK(LibMath::Lerp(piRad, halfPiRad, half) == LibMath::Radian((PI / 2) * 1.5f));

		CHECK(LibMath::Lerp(ninetyDegrees, twoSeventyDegrees, quarter) == LibMath::Degree(135.f));
		CHECK(LibMath::Lerp(twoSeventyDegrees, ninetyDegrees, quarter) == LibMath::Degree(225.f));
		CHECK(LibMath::Lerp(halfPiRad, piRad, quarter) == LibMath::Radian((PI / 2) * 1.25f));
		CHECK(LibMath::Lerp(piRad, halfPiRad, quarter) == LibMath::Radian((PI / 2) * 1.75f));

		CHECK(LibMath::Lerp(ninetyDegrees, twoSeventyDegrees, threeQuarter) == LibMath::Degree(225.f));
		CHECK(LibMath::Lerp(twoSeventyDegrees, ninetyDegrees, threeQuarter) == LibMath::Degree(135.f));
		CHECK(LibMath::Lerp(halfPiRad, piRad, threeQuarter) == LibMath::Radian((PI / 2) * 1.75f));
		CHECK(LibMath::Lerp(piRad, halfPiRad, threeQuarter) == LibMath::Radian((PI / 2) * 1.25f));
	}

	/* Bilinear interpolation */
	{
		LibMath::Vector2 ratio(0.25f, 0.75f);

		LibMath::Vector2 first(10.f, 20.f), second(30.f, 40.f);

		CHECK(LibMath::Bilerp(first, second, ratio) == LibMath::Vector2(15.f, 35.f));
		CHECK(LibMath::Bilerp(second, first, ratio) == LibMath::Vector2(25.f, 25.f));
	}
}