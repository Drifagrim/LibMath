#include "LibMath/Matrix.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_SILENT_WARNINGS
#define GLM_FORCE_XYZW_ONLY
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/projection.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/vector_angle.hpp>

#define CHECK_MATRIX4(matrix, matrixGlm) \
    CHECK(matrix[0][0] == Catch::Approx(matrixGlm[0][0])); CHECK(matrix[1][0] == Catch::Approx(matrixGlm[1][0])); CHECK(matrix[2][0] == Catch::Approx(matrixGlm[2][0])); CHECK(matrix[3][0] == Catch::Approx(matrixGlm[3][0])); \
    CHECK(matrix[0][1] == Catch::Approx(matrixGlm[0][1])); CHECK(matrix[1][1] == Catch::Approx(matrixGlm[1][1])); CHECK(matrix[2][1] == Catch::Approx(matrixGlm[2][1])); CHECK(matrix[3][1] == Catch::Approx(matrixGlm[3][1])); \
    CHECK(matrix[0][2] == Catch::Approx(matrixGlm[0][2])); CHECK(matrix[1][2] == Catch::Approx(matrixGlm[1][2])); CHECK(matrix[2][2] == Catch::Approx(matrixGlm[2][2])); CHECK(matrix[3][2] == Catch::Approx(matrixGlm[3][2])); \
    CHECK(matrix[0][3] == Catch::Approx(matrixGlm[0][3])); CHECK(matrix[1][3] == Catch::Approx(matrixGlm[1][3])); CHECK(matrix[2][3] == Catch::Approx(matrixGlm[2][3])); CHECK(matrix[3][3] == Catch::Approx(matrixGlm[3][3]));

#define CHECK_MATRIX3(matrix, matrixGlm) \
    CHECK(matrix[0][0] == Catch::Approx(matrixGlm[0][0])); CHECK(matrix[1][0] == Catch::Approx(matrixGlm[1][0])); CHECK(matrix[2][0] == Catch::Approx(matrixGlm[2][0])); CHECK(matrix[3][0] == Catch::Approx(matrixGlm[3][0])); \
    CHECK(matrix[0][1] == Catch::Approx(matrixGlm[0][1])); CHECK(matrix[1][1] == Catch::Approx(matrixGlm[1][1])); CHECK(matrix[2][1] == Catch::Approx(matrixGlm[2][1])); CHECK(matrix[3][1] == Catch::Approx(matrixGlm[3][1])); \
    CHECK(matrix[0][2] == Catch::Approx(matrixGlm[0][2])); CHECK(matrix[1][2] == Catch::Approx(matrixGlm[1][2])); CHECK(matrix[2][2] == Catch::Approx(matrixGlm[2][2])); CHECK(matrix[3][2] == Catch::Approx(matrixGlm[3][2]));

#define CHECK_MATRIX2(matrix, matrixGlm) \
    CHECK(matrix[0][0] == Catch::Approx(matrixGlm[0][0])); CHECK(matrix[1][0] == Catch::Approx(matrixGlm[1][0])); CHECK(matrix[2][0] == Catch::Approx(matrixGlm[2][0])); CHECK(matrix[3][0] == Catch::Approx(matrixGlm[3][0])); \
    CHECK(matrix[0][1] == Catch::Approx(matrixGlm[0][1])); CHECK(matrix[1][1] == Catch::Approx(matrixGlm[1][1])); CHECK(matrix[2][1] == Catch::Approx(matrixGlm[2][1])); CHECK(matrix[3][1] == Catch::Approx(matrixGlm[3][1]));

TEST_CASE("Matrix4", "[.all][matrix][Matrix4]")
{
	SECTION("Instantiation")
	{
		// destructor
		{
			LibMath::Matrix4 temp;
		}

		// default constructor
		LibMath::Matrix4 empty(0.f);
		glm::mat4 emptyGlm(0.f);
		CHECK_MATRIX4(empty, emptyGlm);

		// basic constructor
		LibMath::Matrix4 oneParam(2.f);
		glm::mat4 oneParamGlm(2.f);
		CHECK_MATRIX4(oneParam, oneParamGlm);

		LibMath::Matrix4 copy{ oneParam };
		glm::mat4 copyGlm{ oneParamGlm };
		CHECK_MATRIX4(copy, copyGlm);

		empty = oneParam;
		emptyGlm = oneParamGlm;
		CHECK_MATRIX4(empty, emptyGlm);

		CHECK(sizeof(LibMath::Matrix4) == sizeof(glm::mat4));
	}

	SECTION("Accessor")
	{
		// compare with self
		LibMath::Matrix4 self(3.0f);
		CHECK(self == self);
		CHECK_FALSE(self != self);

		// compare with same
		CHECK(LibMath::Matrix4(1.0f) == LibMath::Matrix4(1.0f));
		CHECK_FALSE(LibMath::Matrix4(1.0f) != LibMath::Matrix4(1.0f));
	}

	SECTION("Constant")
	{
		//CHECK_MATRIX4(LibMath::Matrix4::Translate(LibMath::Vector3{ 1.1f, 2.3f, 1.f }), glm::translate(glm::vec3{ 1.1f, 2.3f, 1.f }));

		CHECK_MATRIX4(LibMath::Matrix4::Scale(LibMath::Vector3{ 1.1f, 2.3f, 1.f }), glm::scale(glm::mat4{ 1.f }, glm::vec3{ 1.1f, 2.3f, 1.f }));

		//CHECK_MATRIX4(LibMath::Matrix4::Orthographique(0.f, 10.f, 0.f, 10.f), glm::ortho(0.f, 10.f, 0.f, 10.f));

		//CHECK_MATRIX4(LibMath::Matrix4::Orthographique(0.f, 10.f, 0.f, 10.f, -1.f, 1.f), glm::ortho(0.f, 10.f, 0.f, 10.f, -1.f, 1.f));

		//CHECK_MATRIX4(LibMath::Matrix4::PerspectiveProjection(90.f, 0.8f, -1.f, 1.f), glm::perspective(90.f, 0.8f, -1.f, 1.f));
	}

	SECTION("Arithmetic")
	{
		float smallArr[4][4] = {
			1.f, 2.f, 3.f, 4.f,
			2.f, 3.f, 4.f, 1.f,
			3.f, 4.f, 1.f, 2.f,
			4.f, 1.f, 2.f, 3.f
		};

		LibMath::Matrix4 const small(smallArr);

		float bigArr[4][4] = {
			9.f, 8.f, 7.f, 6.f,
			8.f, 7.f, 6.f, 9.f,
			7.f, 6.f, 9.f, 8.f,
			6.f, 9.f, 8.f, 7.f
		};

		LibMath::Matrix4 const big(bigArr);

		glm::mat4 const smallGlm{
			glm::vec4{1.f, 2.f, 3.f, 4.f},
			glm::vec4{2.f, 3.f, 4.f, 1.f},
			glm::vec4{3.f, 4.f, 1.f, 2.f},
			glm::vec4{4.f, 1.f, 2.f, 3.f}
		};

		glm::mat4 const bigGlm{
			glm::vec4{9.f, 8.f, 7.f, 6.f},
			glm::vec4{8.f, 7.f, 6.f, 9.f},
			glm::vec4{7.f, 6.f, 9.f, 8.f},
			glm::vec4{6.f, 9.f, 8.f, 7.f}
		};

		SECTION("Addition")
		{
			{
				LibMath::Matrix4 sumAssignment = big;
				sumAssignment += small;

				glm::mat4 sumAssignmentGlm = bigGlm;
				sumAssignmentGlm += smallGlm;

				CHECK_MATRIX4(sumAssignment, sumAssignmentGlm);
			}

			{
				LibMath::Matrix4 sum = big + small;

				glm::mat4 sumGlm = bigGlm + smallGlm;

				CHECK_MATRIX4(sum, sumGlm);
			}
		}

		SECTION("Substraction")
		{
			{
				LibMath::Matrix4 difference = big;
				difference -= small;

				glm::mat4 differenceGlm = bigGlm;
				differenceGlm -= smallGlm;

				CHECK_MATRIX4(difference, differenceGlm);
			}

			{
				LibMath::Matrix4 difference = big - small;

				glm::mat4 differenceGlm = bigGlm - smallGlm;

				CHECK_MATRIX4(difference, differenceGlm);
			}
		}

		SECTION("Inverse")
		{
			LibMath::Matrix4 inverse = small.GetInverse();

			glm::mat4 inverseGlm = glm::inverse(smallGlm);

			CHECK_MATRIX4(inverse, inverseGlm);
		}

		SECTION("Determinant")
		{
			float determinant = small.Determinant(small);

			float determinantGlm = glm::determinant(smallGlm);

			CHECK(determinant == Catch::Approx(determinantGlm));
		}

		SECTION("Multiplication")
		{
			LibMath::Matrix4 product = big * small;

			glm::mat4 productGlm = bigGlm * smallGlm;

			CHECK_MATRIX4(product, productGlm);
		}
	}
}

TEST_CASE("Matrix3", "[.all][matrix][Matrix3]")
{
	SECTION("Instantiation")
	{
		// destructor
		{
			LibMath::Matrix3 temp;
		}

		// default constructor
		LibMath::Matrix3 empty{ 0.f };
		glm::mat3 emptyGlm{ 0.f };
		//CHECK_MATRIX3(empty, emptyGlm);

		// basic constructor
		LibMath::Matrix3 oneParam{ 2.0f };
		glm::mat3 oneParamGlm{ 2.0f };
		//CHECK_MATRIX3(oneParam, oneParamGlm);

		LibMath::Matrix3 copy{ oneParam };
		glm::mat3 copyGlm{ oneParamGlm };
		//CHECK_MATRIX3(copy, copyGlm);

		empty = oneParam;
		emptyGlm = oneParamGlm;
		//CHECK_MATRIX3(empty, emptyGlm);

		CHECK(sizeof(LibMath::Matrix3) == sizeof(glm::mat3));
	}

	SECTION("Accessor")
	{
		// compare with self
		LibMath::Matrix3 self{ 3.0f };
		CHECK(self == self);
		CHECK_FALSE(self != self);

		// compare with same
		CHECK(LibMath::Matrix3{ 1.0f } == LibMath::Matrix3{ 1.0f });
		CHECK_FALSE(LibMath::Matrix3{ 1.0f } != LibMath::Matrix3{ 1.0f });
	}

	SECTION("Arithmetic")
	{
		float smallArr[3][3] = {
			1.f, 2.f, 3.f,
			2.f, 3.f, 4.f,
			3.f, 4.f, 1.f
		};

		LibMath::Matrix3 const small(smallArr);

		float bigArr[3][3] = {
			9.f, 8.f, 7.f,
			8.f, 7.f, 6.f,
			7.f, 6.f, 9.f
		};

		LibMath::Matrix3 const big(bigArr);

		glm::mat3 const smallGlm{
			glm::vec3{1.f, 2.f, 3.f},
			glm::vec3{2.f, 3.f, 4.f},
			glm::vec3{3.f, 4.f, 1.f}
		};

		glm::mat3 const bigGlm{
			glm::vec3{9.f, 8.f, 7.f},
			glm::vec3{8.f, 7.f, 6.f},
			glm::vec3{7.f, 6.f, 9.f}
		};

		SECTION("Addition")
		{
			{
				LibMath::Matrix3 sumAssignment = big;
				sumAssignment += small;

				glm::mat3 sumAssignmentGlm = bigGlm;
				sumAssignmentGlm += smallGlm;

				CHECK_MATRIX3(sumAssignment, sumAssignmentGlm);
			}

			{
				LibMath::Matrix3 sum = big + small;

				glm::mat3 sumGlm = bigGlm + smallGlm;

				CHECK_MATRIX3(sum, sumGlm);
			}
		}

		SECTION("Substraction")
		{
			{
				LibMath::Matrix3 difference = big;
				difference -= small;

				glm::mat3 differenceGlm = bigGlm;
				differenceGlm -= smallGlm;

				CHECK_MATRIX3(difference, differenceGlm);
			}

			{
				LibMath::Matrix3 difference = big - small;

				glm::mat3 differenceGlm = bigGlm - smallGlm;

				CHECK_MATRIX3(difference, differenceGlm);
			}
		}

		SECTION("Inverse")
		{
			LibMath::Matrix3 inverse = small.Inverse(small);

			glm::mat3 inverseGlm = glm::inverse(smallGlm);

			CHECK_MATRIX3(inverse, inverseGlm);
		}

		SECTION("Determinant")
		{
			float determinant = small.Determinant(small);

			float determinantGlm = glm::determinant(smallGlm);

			CHECK(determinant == Catch::Approx(determinantGlm));
		}

		SECTION("Multiplication")
		{
			LibMath::Matrix3 product = big * small;

			glm::mat3 productGlm = bigGlm * smallGlm;

			CHECK_MATRIX3(product, productGlm);
		}
	}
}

TEST_CASE("Matrix2", "[.all][matrix][Matrix2]")
{
	SECTION("Instantiation")
	{
		// destructor
		{
			LibMath::Matrix2 temp;
		}

		// default constructor
		LibMath::Matrix2 empty{ 0.f };
		glm::mat2 emptyGlm{ 0.f };
		//CHECK_MATRIX2(empty, emptyGlm);

		// basic constructor
		LibMath::Matrix2 oneParam{ 2.0f };
		glm::mat2 oneParamGlm{ 2.0f };
		//CHECK_MATRIX2(oneParam, oneParamGlm);

		LibMath::Matrix2 copy{ oneParam };
		glm::mat2 copyGlm{ oneParamGlm };
		//CHECK_MATRIX2(copy, copyGlm);

		empty = oneParam;
		emptyGlm = oneParamGlm;
		//CHECK_MATRIX2(empty, emptyGlm);

		//CHECK(sizeof(LibMath::Matrix2) == sizeof(glm::mat2));
	}

	SECTION("Accessor")
	{
		// compare with self
		LibMath::Matrix2 self{ 3.0f };
		CHECK(self == self);
		CHECK_FALSE(self != self);

		// compare with same
		CHECK(LibMath::Matrix2{ 1.0f } == LibMath::Matrix2{ 1.0f });
		CHECK_FALSE(LibMath::Matrix2{ 1.0f } != LibMath::Matrix2{ 1.0f });
	}

	SECTION("Arithmetic")
	{
		LibMath::Matrix2 const small(1.f, 2.f, 2.f, 3.f);
		LibMath::Matrix2 const big(9.f, 8.f, 8.f, 7.f);

		glm::mat2 const smallGlm{
			glm::vec2{1.f, 2.f},
			glm::vec2{2.f, 3.f}
		};

		glm::mat2 const bigGlm{
			glm::vec2{9.f, 8.f},
			glm::vec2{8.f, 7.f}
		};

		SECTION("Addition")
		{
			{
				LibMath::Matrix2 sumAssignment = big;
				sumAssignment += small;

				glm::mat2 sumAssignmentGlm = bigGlm;
				sumAssignmentGlm += smallGlm;

				CHECK_MATRIX2(sumAssignment, sumAssignmentGlm);
			}

			{
				LibMath::Matrix2 sum = big + small;

				glm::mat2 sumGlm = bigGlm + smallGlm;

				CHECK_MATRIX2(sum, sumGlm);
			}
		}

		SECTION("Substraction")
		{
			{
				LibMath::Matrix2 difference = big;
				difference -= small;

				glm::mat2 differenceGlm = bigGlm;
				differenceGlm -= smallGlm;

				CHECK_MATRIX2(difference, differenceGlm);
			}

			{
				LibMath::Matrix2 difference = big - small;

				glm::mat2 differenceGlm = bigGlm - smallGlm;

				CHECK_MATRIX2(difference, differenceGlm);
			}
		}

		SECTION("Determinant")
		{
			float determinant = small.Determinant(small);

			float determinantGlm = glm::determinant(smallGlm);

			CHECK(determinant == Catch::Approx(determinantGlm));
		}

		SECTION("Multiplication")
		{
			LibMath::Matrix2 product = big * small;

			glm::mat2 productGlm = bigGlm * smallGlm;

			CHECK_MATRIX2(product, productGlm);
		}
	}
}