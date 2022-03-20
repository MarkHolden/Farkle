#include "pch.h"
#include "CppUnitTest.h"
#include "../Farkle/Input.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InputTests
{
	TEST_CLASS(InputTests)
	{
	public:
		TEST_METHOD(ReadInt_ShouldReadInt_BetweenMinAndMax)
		{
			std::streambuf* orig = std::cin.rdbuf();
			std::istringstream input("1");
			std::cin.rdbuf(input.rdbuf());
			int result = Input::ReadInt(1, 1);

			Assert::AreEqual(1, result);
			std::cin.rdbuf(orig);
		}

		TEST_METHOD(ReadInt_ShouldNotReadInt_OutsideMinAndMax)
		{
			std::string userEntry = "42\n-999\n2";
			std::streambuf* orig = std::cin.rdbuf();
			std::istringstream input(userEntry);
			std::cin.rdbuf(input.rdbuf());
			int result = Input::ReadInt(2, 2);

			Assert::AreEqual(2, result);
			std::cin.rdbuf(orig);
		}

		TEST_METHOD(ReadInt_ShouldNotReadUnparsableInput)
		{
			std::string userEntry = "seven\nnope\n3";
			std::streambuf* orig = std::cin.rdbuf();
			std::istringstream input(userEntry);
			std::cin.rdbuf(input.rdbuf());
			int result = Input::ReadInt();

			Assert::AreEqual(3, result);
			std::cin.rdbuf(orig);
		}
	};
}
