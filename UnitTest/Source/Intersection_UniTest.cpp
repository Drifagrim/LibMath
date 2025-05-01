#include "LibMath/Intersection.h"
#include "LibMath/Angle.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#define GLM_FORCE_SILENT_WARNINGS
#include <glm/glm.hpp>

TEST_CASE("2D", "[.all]")
{
	SECTION("Collision")
	{
		/* Circle to circle */
		{
			LibMath::Circle alpha({ 1, 1 }, 4);
			LibMath::Circle beta({ 2, 2 }, 4);

			CHECK(LibMath::collisionCheck(alpha, beta));

			alpha = LibMath::Circle({ 10, 10 }, 4);
			beta = LibMath::Circle({ 2, 2 }, 4);

			CHECK_FALSE(LibMath::collisionCheck(alpha, beta));
		}

		/* Line to circle */
		{
			LibMath::Circle gamma({ 1, 2 }, 4);
			LibMath::Line delta({ 0, 0 }, { 0, 5 });

			CHECK(LibMath::collisionCheck(gamma, delta));

			gamma = LibMath::Circle({ 5, 2 }, 4);
			delta = LibMath::Line({ 0, 0 }, { 0, 5 });

			CHECK_FALSE(LibMath::collisionCheck(gamma, delta));
		}

		/* Rectangle to circle */
		{
			LibMath::Circle epsilon({ 1, 3 }, 4);
			LibMath::Rectangle zeta({ 0, 0 }, 2, 4);

			CHECK(LibMath::collisionCheck(epsilon, zeta));

			epsilon = LibMath::Circle({ 6, 2 }, 4);
			zeta = LibMath::Rectangle({ 0, 0 }, 2, 4);

			CHECK_FALSE(LibMath::collisionCheck(epsilon, zeta));
		}

		/* Line to Line */
		{
			LibMath::Line eta({ 0, 0 }, { 0, 5 });
			LibMath::Line theta({ -2, 2.5f }, { 2, 2.5f });

			CHECK(LibMath::collisionCheck(eta, theta));

			eta = LibMath::Line({ 0, 0 }, { 0, 5 });
			theta = LibMath::Line({ 1, 0 }, { 1, 5 });

			CHECK_FALSE(LibMath::collisionCheck(eta, theta));
		}

		/* Line to Rectangle */
		{
			LibMath::Line iota({ -2, 2 }, { 2, -2 });
			LibMath::Rectangle kappa({ 0,  0 }, 2, 4);

			CHECK(LibMath::collisionCheck(iota, kappa));

			iota = LibMath::Line({ -2, 3 }, { 2, 3 });
			kappa = LibMath::Rectangle({ 0,  0 }, 2, 4);

			CHECK_FALSE(LibMath::collisionCheck(iota, kappa));
		}

		/* Point to Rectangle */
		{
			LibMath::point2D lambda(-0.5f, 0.5f);
			LibMath::Rectangle mu({ 0,  0 }, 2, 4);

			CHECK(LibMath::collisionCheck(lambda, mu));

			lambda = LibMath::point2D(3, 3);
			mu = LibMath::Rectangle({ 0,  0 }, 2, 4);

			CHECK_FALSE(LibMath::collisionCheck(lambda, mu));
		}

		/* Point to Circle */
		{
			LibMath::point2D nu(-0.5f, 0.5f);
			LibMath::Circle xi({ 0,  0 }, 2);

			CHECK(LibMath::collisionCheck(nu, xi));

			nu = LibMath::point2D(3, 3);

			CHECK_FALSE(LibMath::collisionCheck(nu, xi));
		}

		/* Point to Line */
		{
			LibMath::point2D omicron(4.f, 1.25f);
			LibMath::Line pi({ 3,  1 }, { 7, 2 });

			CHECK(LibMath::collisionCheck(omicron, pi));

			omicron = LibMath::point2D(10.f, 10.f);

			CHECK_FALSE(LibMath::collisionCheck(omicron, pi));
		}

		/* AABB */
		{
			LibMath::Rectangle rho({ 0.f, 0.f }, 10.f, 5.f);
			LibMath::Rectangle sigma({ 0.f, 0.f }, 5.f, 10.f);

			CHECK(LibMath::collisionCheckAABB(rho, sigma));

			sigma.SetCenter({ 100.f, 100.f });

			CHECK_FALSE(LibMath::collisionCheckAABB(rho, sigma));
		}

		/* SAT */
		{
			LibMath::Rectangle tau({ 0.f, 0.f }, 10.f, 5.f, LibMath::Degree{ 90.f });
			LibMath::Rectangle upsilon({ 0.f, 0.f }, 5.f, 10.f, LibMath::Degree{ -90.f });

			CHECK(LibMath::collisionCheckOBB(tau, upsilon));

			upsilon.SetCenter({ 100.f, 100.f });

			CHECK_FALSE(LibMath::collisionCheckOBB(tau, upsilon));
		}
	}
}

TEST_CASE("3D", "[.all][coll]")
{
	///Point to Sphere
	{
		LibMath::Sphere a({ 0, 0, 0 }, 4);
		LibMath::point3D b(1, 1, 1);

		CHECK(LibMath::PointToSphere(b, a));

		a = LibMath::Sphere({ 0, 0, 0 }, 4);
		b = LibMath::point3D(5, 1, 1);

		CHECK_FALSE(LibMath::PointToSphere(b, a));
	}

	///Ray to sphere
	{
		LibMath::Sphere a({ 0, 0, 4 }, 2);
		LibMath::Ray b({ 0, 0, 0 }, { 0, 0, 4 });

		CHECK(LibMath::RayToSphere(b, a));

		b = LibMath::Ray({ -3, 0, -3 }, { -3, 0, 3 });

		CHECK_FALSE(LibMath::RayToSphere(b, a));
	}

	///Sphere to Sphere
	{
		LibMath::Sphere a({ 0, 0, 0 }, 4);
		LibMath::Sphere b({ 0, 0, -4 }, 4);

		CHECK(LibMath::SpheretoSphere(a, b));

		b = LibMath::Sphere({ 0, 0, -10 }, 4);

		CHECK_FALSE(LibMath::SpheretoSphere(a, b));
	}

	///Point to Box
	{
		LibMath::point3D a(0, 0, 1);
		LibMath::Box b({ 0, 0, 0 }, 2, 2, 4);

		CHECK(LibMath::PointToAABB(a, b));

		a = LibMath::point3D(0, 0, 4);

		CHECK_FALSE(LibMath::PointToAABB(a, b));
	}

	///Sphere to Box
	{
		LibMath::Sphere a({ 0, 0, 0 }, 4);
		LibMath::Box b({ 0, 0, 4 }, 2, 2, 8);

		CHECK(LibMath::SphereToAABB(a, b).second);

		a = LibMath::Sphere({ 0, 0, -4 }, 1);

		CHECK_FALSE(LibMath::SphereToAABB(a, b).second);
	}

	///Box to Box
	{
		LibMath::Box a({ 0, 0, 0 }, 2, 2, 8);
		LibMath::Box b({ 0, 0, 2 }, 2, 2, 2);

		CHECK(LibMath::AABBToAABB(a, b));

		a = LibMath::Box({ 0, 0, -4 }, 2, 2, 1);

		CHECK_FALSE(LibMath::AABBToAABB(a, b));
	}
}