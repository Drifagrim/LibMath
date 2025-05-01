#include "LibMath/Arithmetic.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#define GLM_FORCE_SILENT_WARNINGS
#include <glm/glm.hpp>

using namespace LibMath;

TEST_CASE("Arithmetic", "[.all]")
{
	/* Almost equals */
	{
		float alpha = 1.5000001f, beta = 1.4999999f;
		CHECK(LibMath::almostEqual(alpha, beta));
	}

	/* Rounding/Truncating */
	{
		float gamma = 6.66f;
		CHECK(LibMath::ceiling(gamma) == 7);
		CHECK(LibMath::floor(gamma) == 6);
	}

	/* Clamp */
	{
		float delta = 3.47f, epsilon = 4.73f, zeta = 7.34f;
		CHECK(LibMath::clamp(epsilon, delta, zeta) == epsilon);	/* Value is in the range */
		CHECK(LibMath::clamp(epsilon, zeta, delta) == epsilon); /* Min and max are inverted */
		CHECK(LibMath::clamp(zeta, delta, epsilon) == epsilon); /* Value is greater than max */
		CHECK(LibMath::clamp(delta, epsilon, zeta) == epsilon); /* Value is smaller than min */
		CHECK(LibMath::clamp(delta, delta, zeta) == delta); /* Value is equal to min */
		CHECK(LibMath::clamp(zeta, epsilon, zeta) == zeta); /* Value is equal to max */
	}

	/* Power/Square Root */
	{
		CHECK(LibMath::power(25.f, 2) == 625.f);
		CHECK(LibMath::power(7.f, 3) == 343.f);

		CHECK(LibMath::squareRoot(25.f) == 5.f);
		CHECK(LibMath::squareRoot(-7771.f) == 0.f);

		CHECK(LibMath::squareRoot(LibMath::power(2.f, 2)) == 2.f);
	}

	/* Wrap */
	{
		float eta = 123.456f, theta = 654.321f;
		CHECK(LibMath::wrap(500.f, eta, theta));	/* Value is in the range */
		CHECK(LibMath::wrap(500.f, theta, eta));	/* Min and max are inverted */
		CHECK(LibMath::wrap(500.f, eta, eta));		/* rangeMin = rangeMax */
		CHECK(LibMath::wrap(1.f, eta, theta));		/* Value is smaller than rangeMin*/
		CHECK(LibMath::wrap(1000.f, eta, theta));	/* Value is rgeater than rangeMax*/
	}

	/* Swap */
	{
		float iota = 75.57f, kappa = 57.75f;
		int lambda = 100, mu = 200;
		LibMath::swap(iota, kappa);
		LibMath::swap(lambda, mu);
		CHECK(iota == 57.75f);
		CHECK(kappa == 75.57f);
		CHECK(lambda == 200);
		CHECK(mu == 100);
	}
}