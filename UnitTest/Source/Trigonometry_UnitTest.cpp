#include <LibMath/Trigonometry.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#define GLM_FORCE_SILENT_WARNINGS
#include <glm/glm.hpp>

TEST_CASE("Trigonometry", "[.all]")
{
	LibMath::Radian radian{ 1.2f };
	LibMath::Radian rad{ 3.f };

	/* Trig functions */
	{
		CHECK(LibMath::sin(radian) == Catch::Approx(glm::sin(1.2f)));
		CHECK(LibMath::cos(radian) == Catch::Approx(glm::cos(1.2f)));
		CHECK(LibMath::tan(radian) == Catch::Approx(glm::tan(1.2f)));

		CHECK(LibMath::sin(rad) == Catch::Approx(glm::sin(3.f)));
		CHECK(LibMath::cos(rad) == Catch::Approx(glm::cos(3.f)));
		CHECK(LibMath::tan(rad) == Catch::Approx(glm::tan(3.f)));

		CHECK(LibMath::sin(-radian) == Catch::Approx(glm::sin(-1.2f)));
		CHECK(LibMath::cos(-radian) == Catch::Approx(glm::cos(-1.2f)));
		CHECK(LibMath::tan(-radian) == Catch::Approx(glm::tan(-1.2f)));

		CHECK(LibMath::sin(-rad) == Catch::Approx(glm::sin(-3.f)));
		CHECK(LibMath::cos(-rad) == Catch::Approx(glm::cos(-3.f)));
		CHECK(LibMath::tan(-rad) == Catch::Approx(glm::tan(-3.f)));
	}

	/* Inverse trig functions */
	{
		CHECK(LibMath::asin(0.5f).radian() == Catch::Approx(glm::asin(0.5f)));
		CHECK(LibMath::acos(0.5f).radian() == Catch::Approx(glm::acos(0.5f)));
		CHECK(LibMath::atan(0.5f).radian() == Catch::Approx(glm::atan(0.5f)));

		CHECK(LibMath::asin(-0.5f).radian() == Catch::Approx(glm::asin(-0.5f)));
		CHECK(LibMath::acos(-0.5f).radian() == Catch::Approx(glm::acos(-0.5f)));
		CHECK(LibMath::atan(-0.5f).radian() == Catch::Approx(glm::atan(-0.5f)));

		CHECK(LibMath::atan2(1.f, 2.f).radian() == Catch::Approx(glm::atan(1.f, 2.f)));
		CHECK(LibMath::atan2(1.f, -2.f).radian() == Catch::Approx(glm::atan(1.f, -2.f)));
		CHECK(LibMath::atan2(-1.f, -2.f).radian() == Catch::Approx(glm::atan(-1.f, -2.f)));
		CHECK(LibMath::atan2(-1.f, 2.f).radian() == Catch::Approx(glm::atan(-1.f, 2.f)));
		REQUIRE_THROWS(LibMath::atan2(0.f, 0.f), "Atan2 with x and y == 0 is undefined.");
	}
}