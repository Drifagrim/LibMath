#include "LibMath/Vector/Vector2.h"
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

#define CHECK_VECTOR2(vector, vectorGlm) CHECK(vector.m_x == Catch::Approx(vectorGlm.x)); CHECK(vector.m_y == Catch::Approx(vectorGlm.y));

TEST_CASE("Vector2", "[.all][vector][Vector2]")
{
	SECTION("Instantiation")
	{
		// destructor
		{
			LibMath::Vector2 temp;
		}

		// default constructor
		LibMath::Vector2 empty;
		glm::vec2 emptyGlm{};
		CHECK_VECTOR2(empty, emptyGlm);

		// basic constructor
		LibMath::Vector2 oneParam{ 2.5f };
		glm::vec2 oneParamGlm{ 2.5f };
		CHECK_VECTOR2(oneParam, oneParamGlm);

		LibMath::Vector2 allParam{ 2.5f, .5f };
		glm::vec2 allParamGlm{ 2.5f, .5f };
		CHECK_VECTOR2(allParam, allParamGlm);

		// copy constructor
		LibMath::Vector2 copy{ allParam };
		glm::vec2 copyGlm{ allParamGlm };
		CHECK_VECTOR2(copy, copyGlm);

		// assignment operator
		empty = allParam;
		emptyGlm = allParamGlm;
		CHECK_VECTOR2(empty, emptyGlm);

		// OpenGL compatibility
		CHECK(sizeof LibMath::Vector2 == sizeof glm::vec2);
		//printf("%d", memcmp(&allParam, &allParamGlm, sizeof LibMath::Vec3));
		//CHECK(memcmp(&allParam, &allParamGlm, sizeof LibMath::Vec3));
	}

	SECTION("Accessor")
	{
		float const x = 2.5f;
		float const y = .5f;
		LibMath::Vector2 vector{ x, y };

		{
			LibMath::Vector2 const& vectorConst = vector;
			CHECK(vectorConst[0] == x);
			CHECK(vectorConst[1] == y);
		}

		{
			vector[0] += 1.f;
			vector[1] += 1.f;
			CHECK(vector[0] == x + 1.f);
			CHECK(vector[1] == y + 1.f);
		}
	}

	SECTION("Comparator")
	{
		// compare with self
		LibMath::Vector2 self{ 2.5f, .5f };
		CHECK(self == self);
		CHECK_FALSE(self != self);

		// compare with same
		CHECK(LibMath::Vector2{ 2.5f, .5f } == LibMath::Vector2{ 2.5f, .5f });
		CHECK(LibMath::Vector2{ 2.5f, .5f } != LibMath::Vector2{ 2.5f, 1.5f });

		// trying to find copy/paste mistake
		LibMath::Vector2 twos{ 2.f, 2.f };
		CHECK_FALSE(LibMath::Vector2{ .5f, 2.f } == twos);
		CHECK_FALSE(LibMath::Vector2{ 2.f, .5f } == twos);
		CHECK(LibMath::Vector2{ .5f, 2.f } != twos);
		CHECK(LibMath::Vector2{ 2.f, .5f } != twos);
		CHECK_FALSE(twos == LibMath::Vector2{ .5f, 2.f });
		CHECK_FALSE(twos == LibMath::Vector2{ 2.f, .5f });
		CHECK(twos != LibMath::Vector2{ .5f, 2.f });
		CHECK(twos != LibMath::Vector2{ 2.f, .5f });

		// testing comparaision fonctionnality
		LibMath::Vector2 small{ 2.5f, .5f };
		LibMath::Vector2 big{ 3.75f, 3.f };

		CHECK(big.isLongerThan(small));
		CHECK_FALSE(small.isLongerThan(big));

		CHECK(small.isShorterThan(big));
		CHECK_FALSE(big.isShorterThan(small));

		CHECK_FALSE(self.isUnit());
		CHECK(LibMath::Vector2{ 0.6f, 0.8f }.isUnit());
	}

	SECTION("Constant")
	{
		CHECK_VECTOR2(LibMath::Vector2::down(), glm::vec2(0.f, -1.f));

		CHECK_VECTOR2(LibMath::Vector2::left(), glm::vec2(-1.f, 0.f));

		CHECK_VECTOR2(LibMath::Vector2::one(), glm::vec2(1.f, 1.f));

		CHECK_VECTOR2(LibMath::Vector2::right(), glm::vec2(1.f, 0.f));

		CHECK_VECTOR2(LibMath::Vector2::up(), glm::vec2(0.f, 1.f));

		CHECK_VECTOR2(LibMath::Vector2::zero(), glm::vec2(0.f, 0.f));
	}

	SECTION("Arithmetic")
	{
		LibMath::Vector2 const small{ 2.5f, .5f };
		LibMath::Vector2 const big{ 3.75f, 3.f };

		glm::vec2 const smallGlm{ 2.5f, .5f };
		glm::vec2 const bigGlm{ 3.75f, 3.f };

		SECTION("Addition")
		{
			{
				LibMath::Vector2 sumAssignment = big;
				sumAssignment += small;

				glm::vec2 sumAssignmentGlm = bigGlm;
				sumAssignmentGlm += smallGlm;

				CHECK_VECTOR2(sumAssignment, sumAssignmentGlm);
			}

			{
				LibMath::Vector2 sum = big + small;

				glm::vec2 sumGlm = bigGlm + smallGlm;

				CHECK_VECTOR2(sum, sumGlm);
			}
		}

		SECTION("Opposite")
		{
			LibMath::Vector2 opposite = -LibMath::Vector2{ 3.7f, 3.f };

			glm::vec2 oppositeGlm = -glm::vec2{ 3.7f, 3.f };

			CHECK_VECTOR2(opposite, oppositeGlm);
		}

		SECTION("Substraction")
		{
			{
				LibMath::Vector2 differenceAssignment = big;
				differenceAssignment -= small;

				glm::vec2 differenceAssignmentGlm = bigGlm;
				differenceAssignmentGlm -= smallGlm;

				CHECK_VECTOR2(differenceAssignment, differenceAssignmentGlm);
			}

			{
				LibMath::Vector2 difference = big - small;

				glm::vec2 differenceGlm = bigGlm - smallGlm;

				CHECK_VECTOR2(difference, differenceGlm);
			}
		}

		SECTION("Multiplication")
		{
			{
				LibMath::Vector2 productAssignment = big;
				productAssignment *= small;

				glm::vec2 productAssignmentGlm = bigGlm;
				productAssignmentGlm *= smallGlm;

				CHECK_VECTOR2(productAssignment, productAssignmentGlm);
			}

			{
				LibMath::Vector2 product = big * small;

				glm::vec2 productGlm = bigGlm * smallGlm;

				CHECK_VECTOR2(product, productGlm);
			}
		}

		SECTION("Division")
		{
			{
				LibMath::Vector2 quotientAssignment = big;
				quotientAssignment /= small;

				glm::vec2 quotientAssignmentGlm = bigGlm;
				quotientAssignmentGlm /= smallGlm;

				CHECK_VECTOR2(quotientAssignment, quotientAssignmentGlm);
			}

			{
				LibMath::Vector2 quotient = big / small;

				glm::vec2 quotientGlm = bigGlm / smallGlm;

				CHECK_VECTOR2(quotient, quotientGlm);
			}
		}
	}

	SECTION("Transformation")
	{
		LibMath::Vector2 const origin{ 2.5f, .5f };
		LibMath::Vector2 const transformation{ -2.f, 1.5f };

		glm::vec4 const originGlm{ 2.5f, .5f, 1.f, 1.f };
		glm::vec3 const transformationGlm{ -2.f, 1.5f, 0.f };

		SECTION("Translation")
		{
			LibMath::Vector2 translate = origin;
			translate.translate(transformation);

			glm::vec4 translateGlm = glm::translate(transformationGlm) * originGlm;

			CHECK_VECTOR2(translate, translateGlm);
		}

		SECTION("Scale")
		{
			LibMath::Vector2 scale = origin;
			scale.scale(transformation);

			glm::vec4 scaleGlm = glm::scale(transformationGlm) * originGlm;

			CHECK_VECTOR2(scale, scaleGlm);
		}

		////TODO Fix 2D Rotation
		//SECTION("Rotation")
		//{
		//	SECTION("Euler Angle")
		//	{
		//		LibMath::Vector2 rotate = origin;
		//		rotate.rotate(LibMath::Radian{ transformation.m_x }, LibMath::Radian{ transformation.m_y });

		//		glm::vec4 rotateGlm = glm::orientate4(transformationGlm) * originGlm;

		//		CHECK_VECTOR2(rotate, rotateGlm);
		//	}

		//	SECTION("Axis")
		//	{
		//		LibMath::Vector2 rotate = origin;
		//		rotate.rotate(-3_rad, transformation);

		//		glm::vec4 rotateGlm = glm::rotate(-3.f, transformationGlm) * originGlm;

		//		CHECK_VECTOR2(rotate, rotateGlm);
		//	}

		//	SECTION("Quaternion")
		//	{
		//		// todo
		//	}
		//}
	}

	SECTION("Functionality")
	{
		LibMath::Vector2 const base{ 2.5f, .5f };
		LibMath::Vector2 const other{ 3.75f, 3.f };

		glm::vec2 const baseGlm{ 2.5f, .5f };
		glm::vec2 const otherGlm{ 3.75f, 3.f };

		SECTION("Angle")
		{
			LibMath::Radian angle = base.angleFrom(other);

			float angleGlm = glm::angle(glm::normalize(baseGlm), glm::normalize(otherGlm));

			CHECK(angle.radian() == Catch::Approx(angleGlm));
		}

		SECTION("Cross")
		{
			glm::vec3 const baseGlm3{ 2.5f, .5f, 0.f };
			glm::vec3 const otherGlm3{ 3.75f, 3.f, 0.f };

			float cross = base.crossProduct(other);

			float crossGlm = glm::cross(baseGlm3, otherGlm3).z;

			CHECK(cross == crossGlm);
		}

		SECTION("Dot")
		{
			float dot = base.dotProduct(other);

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
				float distanceSquare = base.squaredDistanceFrom(other);

				float distanceSquareGlm = glm::distance2(baseGlm, otherGlm);

				CHECK(distanceSquare == Catch::Approx(distanceSquareGlm));
			}

			{
				float distance2D = base.distanceFrom(other);

				float distance2DGlm = glm::distance(glm::vec2(baseGlm), glm::vec2(otherGlm));

				CHECK(distance2D == Catch::Approx(distance2DGlm));
			}

			{
				float distance2DSquare = base.squaredDistanceFrom(other);

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
				float magnitudeSquare = base.squareMagnitude();

				float magnitudeSquareGlm = glm::length2(baseGlm);

				CHECK(magnitudeSquare == Catch::Approx(magnitudeSquareGlm));
			}
		}

		SECTION("Normal")
		{
			LibMath::Vector2 normalize = base;
			normalize.normalize();

			glm::vec2 normalizeGlm = glm::normalize(baseGlm);

			CHECK_VECTOR2(normalize, normalizeGlm);
		}

		SECTION("ProjectOnto")
		{
			LibMath::Vector2 project = base;
			project.project(other);

			glm::vec2 projectGlm = glm::proj(baseGlm, otherGlm);

			CHECK_VECTOR2(project, projectGlm);
		}

		SECTION("ReflectOnto")
		{
			LibMath::Vector2 reflect = base;
			reflect.reflection(other);

			glm::vec2 reflectGlm = glm::reflect(baseGlm, glm::normalize(otherGlm));

			CHECK_VECTOR2(reflect, reflectGlm);
		}
	}

	SECTION("Extra")
	{
		LibMath::Vector2 const input{ 2.5f, -.5f };
		{
			std::stringstream buffer;
			buffer << input;
			CHECK(buffer.str() == "{ 2.5, -0.5 }");

			buffer << " extra";

			LibMath::Vector2 output;
			buffer >> output;
			CHECK(output == input);

			std::string extra;
			buffer >> extra;
			CHECK(extra == "extra");
		}

		{
			CHECK(input.string() == "{ 2.5, -0.5 }");

			CHECK(input.stringLong() == "Vector2{ x: 2.5, y: -0.5 }");
		}
	}

	SECTION("Conversion")
	{
		LibMath::Vector2 base2{ 1.f, 2.f };
		const LibMath::Vector3 base3{ 1.f, 2.f, 1.f };
		const LibMath::Vector4 base4{ 1.f, 2.f, 1.f, 1.f };

		{
			LibMath::Vector3 checkBase3 = base2;
			CHECK(checkBase3 == base3);

			LibMath::Vector4 checkBase4 = base2;
			CHECK(checkBase4 == base4);
		}
	}

	SECTION("Debug")
	{
#if (defined _DEBUG) || (! defined NDEBUG)
		LibMath::Vector2 vector{ 2.5f, .5f };

		CHECK_THROWS(vector[-1]);
		CHECK_THROWS(vector[3]);
#endif // DEBUG
	}
}