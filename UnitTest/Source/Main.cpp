//#include <catch2/catch_session.hpp>
//#include <algorithm>

#include "arguments.h"

/*
* todo: finish adding test to the debug section of the Vector3 test case in Vector_UnitTest.cpp
*/

/*
* Fun piece of code (for you to discover)
* 
* automatic converetion from Degree to Radian (see "Angle/Degree.h" line 16)
* literral can bypass explicit constructor (see "Angle/Degree.h" line 46)
* use of include guards instead of "pragma once" let you auto include stuff if another header is already included (see "Vector/Vector4" line 18)
* overloading operator>> make it easy to save/display state (see "Vector/Vector3" line 89)
* macro that performe many catch test in a single test wile still displaying the right variable name (see "Vector_UnitTest.cpp" line 14)
* 
* 
* 
* tricks (you can use)
* 
* be wary of where the physical file are place when using "Add/New Item..."
* many function body can reuse other function (this is called the DRY principle, as opposed to the WET principle (Look those up))
* you can use the default keyword (other keywords include: delete, static, consteval, noexcept, [[nodiscard]], inline, ...)
* many function can be made constexpr (this will trade runtime execution for compile time execution)
* inline/constexpr function body can be defined in a .hpp/.inl file and included in you headear file (keeping function declaration and definition separated)
* replacing "Vector3" with a template, then making typedef for floats call "Vector3" won't brake the unit test (if done well)
* you can change the folder structure or add/remove file as you see fit (you may want to refactor/rename the test file)
* you are forbidden to use glm in your math library but it is allowed to use to test against in the unit test (I greatly encourage you to do that extensively)
* you can add custom argument to the arguments' vector in the main function below
* 
* 
* 
* traps
* 
* many comment left by me make your lines execed your coding standard limits (you will have to fix this)
* this main function is way too long to fit your coding standard limits (you will also have to fix this)
* Radian, Degree, Vector3 are by no means fully complete (you can add to them any function you think would be useful (don't forget to test))
* don't test only for success, think of as many edge case as you can and create test for each, your math library will be that more robust
* don't disable working test once they've pass, keeping them active will protect you against regression as you add more functionnality
* 
* 
* 
* references
* https://en.cppreference.com/w/cpp/language/operators
* 
* https://docs.unity3d.com/ScriptReference/Vector3.html
* https://docs.unity3d.com/ScriptReference/Mathf.html
* https://docs.unity3d.com/ScriptReference/Matrix4x4.html
* https://docs.unrealengine.com/4.26/en-US/API/Runtime/Core/Math/FVector/
* https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FMath/
* https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FMatrix/
*/

int main(int argc, char* argv[])
{
	testArguments(argc, argv);

	return 0;
}
