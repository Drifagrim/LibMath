#include <LibMath/Vector/Vector4.h>
#include "LibMath/Angle/Degree.h"
#include "LibMath/Angle/Radian.h"

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

using namespace LibMath;

#define CHECK_VECTOR4(vector, vectorGlm) CHECK(vector.m_x == Catch::Approx(vectorGlm.x)); CHECK(vector.m_y == Catch::Approx(vectorGlm.y)); CHECK(vector.m_z == Catch::Approx(vectorGlm.z)); CHECK(vector.m_w == Catch::Approx(vectorGlm.w))

TEST_CASE("Vector4", "[.all][vector][Vector4]")
{
	SECTION("Instantiation")
	{
		// destructor
		{
			Vector4 temp;
		}

		// default constructor
		Vector4 empty;
		glm::vec4 emptyGlm{};
		CHECK_VECTOR4(empty, emptyGlm);

		// basic constructor
		Vector4 oneParam{ 2.5f };
		glm::vec4 oneParamGlm{ 2.5f };
		CHECK_VECTOR4(oneParam, oneParamGlm);

		Vector4 allParam{ 2.5f, .5f, 2.f, 1.f };
		glm::vec4 allParamGlm{ 2.5f, .5f, 2.f, 1.f };
		CHECK_VECTOR4(allParam, allParamGlm);

		// copy constructor
		Vector4 copy{ allParam };
		glm::vec4 copyGlm{ allParamGlm };
		CHECK_VECTOR4(copy, copyGlm);

		// assignment operator
		empty = allParam;
		emptyGlm = allParamGlm;
		CHECK_VECTOR4(empty, emptyGlm);

		// OpenGL compatibility
		CHECK(sizeof Vector4 == sizeof glm::vec4);
		CHECK(memcmp(&allParam, &allParamGlm, sizeof Vector3));
	}

	SECTION("Accessor")
	{
		float const x = 2.5f;
		float const y = .5f;
		float const z = 2.f;
		float const w = 5.f;
		Vector4 vector{ x, y, z, w };

		{
			Vector4 const& vectorConst = vector;
			CHECK(vectorConst[0] == x);
			CHECK(vectorConst[1] == y);
			CHECK(vectorConst[2] == z);
			CHECK(vectorConst[3] == w);
		}

		{
			vector[0] += 1.f;
			vector[1] += 1.f;
			vector[2] += 1.f;
			vector[3] += 1.f;
			CHECK(vector[0] == x + 1.f);
			CHECK(vector[1] == y + 1.f);
			CHECK(vector[2] == z + 1.f);
			CHECK(vector[3] == w + 1.f);
		}
	}

	SECTION("Comparator")
	{
		// compare with self
		Vector4 self{ 2.5f, .5f, 2.f, 5.f };
		CHECK(self == self);
		CHECK_FALSE(self != self);

		// compare with same
		CHECK(Vector4{ 2.5f, .5f, 2.f, 5.f } == Vector4{ 2.5f, .5f, 2.f, 5.f });
		CHECK(Vector4{ 2.5f, .5f, 2.f, 5.f } != Vector4{ 2.5f, 1.5f, 2.f, 5.f });

		// trying to find copy/paste mistake
		Vector4 twos{ 2.f, 2.f, 2.f, 2.f };
		CHECK_FALSE(Vector4{ .5f, 2.f, 2.f, 2.f } == twos);
		CHECK_FALSE(Vector4{ 2.f, .5f, 2.f, 2.f } == twos);
		CHECK_FALSE(Vector4{ 2.f, 2.f, .5f, 2.f } == twos);
		CHECK_FALSE(Vector4{ 2.f, 2.f, 2.f, .5f } == twos);
		CHECK(Vector4{ .5f, 2.f, 2.f, 2.f } != twos);
		CHECK(Vector4{ 2.f, .5f, 2.f, 2.f } != twos);
		CHECK(Vector4{ 2.f, 2.f, .5f, 2.f } != twos);
		CHECK(Vector4{ 2.f, 2.f, 2.f, .5f } != twos);
		CHECK_FALSE(twos == Vector4{ .5f, 2.f, 2.f, 2.f });
		CHECK_FALSE(twos == Vector4{ 2.f, .5f, 2.f, 2.f });
		CHECK_FALSE(twos == Vector4{ 2.f, 2.f, .5f, 2.f });
		CHECK_FALSE(twos == Vector4{ 2.f, 2.f, 2.f, .5f });
		CHECK(twos != Vector4{ .5f, 2.f, 2.f, 2.f });
		CHECK(twos != Vector4{ 2.f, .5f, 2.f, 2.f });
		CHECK(twos != Vector4{ 2.f, 2.f, .5f, 2.f });
		CHECK(twos != Vector4{ 2.f, 2.f, 2.f, .5f });

		// testing comparaision fonctionnality
		Vector4 small{ 2.5f, .5f, 2.f, 5.f };
		Vector4 big{ 3.75f, 3.f, .75f, 5.f };

		CHECK(big.isLongerThan(small));
		CHECK_FALSE(small.isLongerThan(big));

		CHECK(small.isShorterThan(big));
		CHECK_FALSE(big.isShorterThan(small));

		CHECK_FALSE(self.isUnitVector());
		CHECK(Vector4{ 0.5f, 0.5f, 0.5f, 0.5f }.isUnitVector());
	}

	SECTION("Constant")
	{
		CHECK_VECTOR4(Vector4::one(), glm::vec4(1.f, 1.f, 1.f, 1.f));

		CHECK_VECTOR4(Vector4::zero(), glm::vec4(0.f, 0.f, 0.f, 0.f));
	}

	SECTION("Arithmetic")
	{
		Vector4 const small{ 2.5f, .5f, 2.f, 5.f };
		Vector4 const big{ 3.75f, 3.f, .75f, 5.f };

		glm::vec4 const smallGlm{ 2.5f, .5f, 2.f, 5.f };
		glm::vec4 const bigGlm{ 3.75f, 3.f, .75f, 5.f };

		SECTION("Addition")
		{
			{
				Vector4 sumAssignment = big;
				sumAssignment += small;

				glm::vec4 sumAssignmentGlm = bigGlm;
				sumAssignmentGlm += smallGlm;

				CHECK_VECTOR4(sumAssignment, sumAssignmentGlm);
			}

			{
				Vector4 sum = big + small;

				glm::vec4 sumGlm = bigGlm + smallGlm;

				CHECK_VECTOR4(sum, sumGlm);
			}
		}

		SECTION("Opposite")
		{
			Vector4 opposite = -Vector4{ 3.75f, 3.f, .75f, 5.f };

			glm::vec4 oppositeGlm = -glm::vec4{ 3.75f, 3.f, .75f, 5.f };

			CHECK_VECTOR4(opposite, oppositeGlm);
		}

		SECTION("Substraction")
		{
			{
				Vector4 differenceAssignment = big;
				differenceAssignment -= small;

				glm::vec4 differenceAssignmentGlm = bigGlm;
				differenceAssignmentGlm -= smallGlm;

				CHECK_VECTOR4(differenceAssignment, differenceAssignmentGlm);
			}

			{
				Vector4 difference = big - small;

				glm::vec4 differenceGlm = bigGlm - smallGlm;

				CHECK_VECTOR4(difference, differenceGlm);
			}
		}

		SECTION("Multiplication")
		{
			{
				Vector4 productAssignment = big;
				productAssignment *= small;

				glm::vec4 productAssignmentGlm = bigGlm;
				productAssignmentGlm *= smallGlm;

				CHECK_VECTOR4(productAssignment, productAssignmentGlm);
			}

			{
				Vector4 product = big * small;

				glm::vec4 productGlm = bigGlm * smallGlm;

				CHECK_VECTOR4(product, productGlm);
			}
		}

		SECTION("Division")
		{
			{
				Vector4 quotientAssignment = big;
				quotientAssignment /= small;

				glm::vec4 quotientAssignmentGlm = bigGlm;
				quotientAssignmentGlm /= smallGlm;

				CHECK_VECTOR4(quotientAssignment, quotientAssignmentGlm);
			}

			{
				Vector4 quotient = big / small;

				glm::vec4 quotientGlm = bigGlm / smallGlm;

				CHECK_VECTOR4(quotient, quotientGlm);
			}
		}
	}

	SECTION("Transformation")
	{
		Vector4 const origin{ 2.5f, .5f, 2.f, 1.f };
		Vector4 const transformation0{ -2.f, 0.f, 1.25f, 0.f };
		Vector4 const transformation1{ -2.f, 0.f, 1.25f, 1.f };

		glm::vec4 const originGlm{ 2.5f, .5f, 2.f, 1.f };
		glm::vec3 const transformationGlm{ -2.f, 0.f, 1.25f };

		SECTION("Translation")
		{
			Vector4 translate = origin;
			translate.translate(transformation0);

			glm::vec4 translateGlm = glm::translate(transformationGlm) * originGlm;

			CHECK_VECTOR4(translate, translateGlm);
		}

		SECTION("Scale")
		{
			Vector4 scale = origin;
			scale.scale(transformation1);

			glm::vec4 scaleGlm = glm::scale(transformationGlm) * originGlm;

			CHECK_VECTOR4(scale, scaleGlm);
		}
	}

	SECTION("Functionality")
	{
		Vector4 const base{ 2.5f, .5f, 2.f, 5.f };
		Vector4 const other{ 3.75f, 3.f, .75f, 5.f };

		glm::vec4 const baseGlm{ 2.5f, .5f, 2.f, 5.f };
		glm::vec4 const otherGlm{ 3.75f, 3.f, .75f, 5.f };

		SECTION("Angle")
		{
			LibMath::Radian angle = base.angleFrom(other);

			float angleGlm = glm::angle(glm::normalize(baseGlm), glm::normalize(otherGlm));

			CHECK(angle.radian() == Catch::Approx(angleGlm));
		}

		SECTION("Dot")
		{
			float dot = base.dot(other);

			float dotGlm = glm::dot(baseGlm, otherGlm);

			CHECK(dot == dotGlm);
		}

		SECTION("Distance")
		{
			{
				float distance = base.distanceFrom(other);

				float distanceGlm = glm::distance(baseGlm, otherGlm);

				CHECK(distance == Catch::Approx(distanceGlm));
			}

			{
				float distanceSquare = base.distanceSquaredFrom(other);

				float distanceSquareGlm = glm::distance2(baseGlm, otherGlm);

				CHECK(distanceSquare == Catch::Approx(distanceSquareGlm));
			}

			{
				float distance2D = base.distance2DFrom(other);

				float distance2DGlm = glm::distance(glm::vec2(baseGlm), glm::vec2(otherGlm));

				CHECK(distance2D == Catch::Approx(distance2DGlm));
			}

			{
				float distance2DSquare = base.distance2DSquaredFrom(other);

				float distance2DSquareGlm = glm::distance2(glm::vec2(baseGlm), glm::vec2(otherGlm));

				CHECK(distance2DSquare == Catch::Approx(distance2DSquareGlm));
			}
		}

		SECTION("Magnitude")
		{
			{
				float magnitude = base.magnitude();

				float magnitudeGlm = glm::length(baseGlm);

				CHECK(magnitude == Catch::Approx(magnitudeGlm));
			}

			{
				float magnitudeSquare = base.magnitudeSquared();

				float magnitudeSquareGlm = glm::length2(baseGlm);

				CHECK(magnitudeSquare == Catch::Approx(magnitudeSquareGlm));
			}
		}

		SECTION("Normal")
		{
			Vector4 normalize = base;
			normalize.normalize();

			glm::vec4 normalizeGlm = glm::normalize(baseGlm);

			CHECK_VECTOR4(normalize, normalizeGlm);
		}

		SECTION("ProjectOnto")
		{
			Vector4 project = base;
			project.projectOnto(other);

			glm::vec4 projectGlm = glm::proj(baseGlm, otherGlm);

			CHECK_VECTOR4(project, projectGlm);
		}

		SECTION("ReflectOnto")
		{
			Vector4 reflect = base;
			reflect.reflectOnto(other);

			std::cout << glm::length(otherGlm) << '\t' << other.magnitude() << '\n';

			glm::vec4 reflectGlm = glm::reflect(baseGlm, glm::normalize(otherGlm));

			CHECK_VECTOR4(reflect, reflectGlm);
		}
	}

	SECTION("Extra")
	{
		Vector4 const input{ 2.5f, -.5f, 2.f, 5.f };
		{
			std::stringstream buffer;
			buffer << input;
			CHECK(buffer.str() == "{ 2.5, -0.5, 2, 5 }");

			buffer << " extra";

			Vector4 output;
			buffer >> output;
			CHECK(output == input);

			std::string extra;
			buffer >> extra;
			CHECK(extra == "extra");
		}

		{
			CHECK(input.string() == "{ 2.5, -0.5, 2, 5 }");

			CHECK(input.stringLong() == "Vector4{ x: 2.5, y: -0.5, z: 2, w: 5 }");
		}
	}

	SECTION("Conversion")
	{
		const Vector2 base2{ 1.f, 2.f };
		const Vector3 base3{ 1.f, 2.f, 3.f };
		Vector4 base4{ 1.f, 2.f, 3.f, 4.f };

		{
			Vector2 checkBase2 = base4;
			CHECK(checkBase2 == base2);

			Vector3 checkBase3 = base4;
			CHECK(checkBase3 == base3);
		}
	}

	SECTION("Debug")
	{
#if (defined _DEBUG) || (! defined NDEBUG)
		Vector4 vector{ 2.5f, .5f, 2.f, 5.f };

		CHECK_THROWS(vector[-1]);
		CHECK_THROWS(vector[4]);
#endif // DEBUG
	}
}