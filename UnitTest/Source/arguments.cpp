#include "arguments.h"

int testArguments(int argc, char* argv[])
{
	// transfers command line argument to dynamic collection so we can add our own argument easily
	std::vector<char const*> arguments;
	for (int i = 0; i < argc; i++)
	{
		arguments.push_back(argv[i]);
	}

	/************************************\
	*                                    *
	*    uncomment line(s) from below    *
	*    to run all test cases marked    *
	*    by at least 1 of the            *
	*    uncommented tags                *
	*                                    *
	*    By default :                    *
	*    If no test are specified, no    *
	*    test are ran                    *
	*                                    *
	\************************************/
	arguments.push_back("[all],");
	arguments.push_back("[angle],");
	arguments.push_back("[vector],");
	arguments.push_back("[matrix],");


	/************************************\
	*                                    *
	*    uncomment line(s) from below    *
	*    to add the test case with       *
	*    matching name to the list of    *
	*    test cases to run defined       *
	*    above                           *
	*                                    *
	*    Note :                          *
	*    You can leave de section        *
	*    above fully commented out       *
	*    and only uncomment line(s)      *
	*    from this section               *
	*                                    *
	\************************************/
	arguments.push_back("Degree,");
	arguments.push_back("Radian,");
	arguments.push_back("Vector2,");
	arguments.push_back("Vector3,");
	arguments.push_back("Vector4,");
	arguments.push_back("Trigonometry,");
	arguments.push_back("Arithmetic,");
	arguments.push_back("2D,");
	arguments.push_back("3D,");
	arguments.push_back("Interpolation,");
	arguments.push_back("Matrix4,");
	arguments.push_back("Matrix3,");
	arguments.push_back("Matrix2,");
	arguments.push_back("Quaternion,");


	/************************************\
	*                                    *
	*    uncomment line(s) from below    *
	*    to only run specific section    *
	*    from the test selected above    *
	*                                    *
	*    By default :                    *
	*    If no section are specified,    *
	*    all section are ran             *
	*                                    *
	\************************************/
	arguments.push_back("-c Accessor");
	arguments.push_back("-c Arithmetic");
	arguments.push_back("-c Comparator");
	arguments.push_back("-c Constant");
	arguments.push_back("-c Conversion");
	arguments.push_back("-c Debug");
	arguments.push_back("-c Extra");
	arguments.push_back("-c Functionality");
	arguments.push_back("-c Instantiation");
	arguments.push_back("-c Transformation");
	arguments.push_back("-c Collision");


	/************************************\
	*                                    *
	*    add more catch command line     *
	*    argument here                   *
	*                                    *
	\************************************/
	// https://github.com/catchorg/Catch2/blob/devel/docs/command-line.md

	return Catch::Session().run((int)arguments.size(), &arguments[0]);
}