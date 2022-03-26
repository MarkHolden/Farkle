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
            // cin wizardry from here: https://stackoverflow.com/questions/14550187/how-to-put-data-in-cin-from-string
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

        TEST_METHOD(ReadString_ShouldReturnTheStringEntered)
        {
            std::string userEntry = "a;sldkjfa;irth";
            std::streambuf* orig = std::cin.rdbuf();
            std::istringstream input(userEntry);
            std::cin.rdbuf(input.rdbuf());
            std::string result = Input::ReadString();

            Assert::AreEqual(userEntry, result);
            std::cin.rdbuf(orig);
        }

        TEST_METHOD(ShouldContinue_ShouldReturnTrueWhenYIsEntered)
        {
            std::streambuf* orig = std::cin.rdbuf();
            std::string inputs[] = { "y", "Y" };

            for (std::string entry : inputs) {
                std::istringstream input(entry);
                std::cin.rdbuf(input.rdbuf());
                bool result = Input::ShouldContinue();

                Assert::IsTrue(result);
            }
            std::cin.rdbuf(orig);
        }

        TEST_METHOD(ShouldContinue_ShouldReturnFalseWhenNIsEntered)
        {
            std::streambuf* orig = std::cin.rdbuf();
            std::string inputs[] = { "n", "N" };

            for (std::string entry : inputs) {
                std::istringstream input(entry);
                std::cin.rdbuf(input.rdbuf());
                bool result = Input::ShouldContinue();

                Assert::IsFalse(result);
            }

            std::cin.rdbuf(orig);
        }

        TEST_METHOD(ShouldContinue_ShouldPromptAgainWhenUnrecognizedCharacterIsEntered)
        {
            std::streambuf* orig = std::cin.rdbuf();
            std::istringstream input("ubuntu\n42\ny");
            std::cin.rdbuf(input.rdbuf());
            bool result = Input::ShouldContinue();
            Assert::IsTrue(result);
            std::cin.rdbuf(orig);
        }
    };
}
