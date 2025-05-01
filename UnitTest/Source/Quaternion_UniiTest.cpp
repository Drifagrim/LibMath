#include "LibMath/Quaternion.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#define GLM_FORCE_SILENT_WARNINGS
#define GLM_FORCE_XYZW_ONLY
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/projection.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/quaternion.hpp>

using namespace LibMath;

#define CHECK_QUATERNION(quaternion, quaternionGlm) CHECK(quaternion.m_a == Catch::Approx(quaternionGlm.w)); CHECK(quaternion.m_b == Catch::Approx(quaternionGlm.x)); CHECK(quaternion.m_c == Catch::Approx(quaternionGlm.y)); CHECK(quaternion.m_d == Catch::Approx(quaternionGlm.z))

TEST_CASE("Quaternion")
{
	SECTION("Instantiation")
	{
		// destructor
		{
			Quaternion temp;
		}

		// default constructor
		Quaternion empty;
		glm::quat emptyGlm{};
		CHECK_QUATERNION(empty, emptyGlm);

		Quaternion allParam{ 2.5f, .5f, 2.f, 1.f };
		glm::quat allParamGlm{ 2.5f, .5f, 2.f, 1.f };
		CHECK_QUATERNION(allParam, allParamGlm);

		// OpenGL compatibility
		CHECK(sizeof Quaternion == sizeof glm::quat);
		CHECK(memcmp(&allParam, &allParamGlm, sizeof Quaternion));
	}
}