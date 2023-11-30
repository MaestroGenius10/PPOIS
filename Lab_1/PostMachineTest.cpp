#include "pch.h"
#include "CppUnitTest.h"
#include "PostMachine.h"
#include <string>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

std::wstring ToString(const PostMachine& machine) {
	std::string str = machine.getTape().getStr();
	return std::wstring(str.begin(), str.end());
}

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Tape tape("010101010");
			Program program;
			"v" >> program;
			"!" >> program;
			PostMachine machine(tape, program);
			machine.setHead(4);
			machine--;
			Tape expectedTape("010111010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod2)
		{
			Tape tape("010101010");
			Program program;
			"x" >> program;
			"!" >> program;
			PostMachine machine(tape, program);
			machine.setHead(3);
			machine--;
			Tape expectedTape("010001010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod3)
		{
			Tape tape("010101010");
			Program program;
			"? 2 4" >> program;
			"v" >> program;
			">" >> program;
			"v" >> program;
			"!" >> program;
			PostMachine machine(tape, program);
			machine--;
			Tape expectedTape("110101010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod4)
		{
			Tape tape("010101010");
			Program program;
			"? 2 4" >> program;
			"v" >> program;
			"<" >> program;
			"x" >> program;
			"!" >> program;
			PostMachine machine(tape, program);
			machine.setHead(3);
			machine--;
			Tape expectedTape("010001010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod5)
		{
			Tape tape("010101010");
			Program program;
			"v" >> program;
			"!" >> program;
			PostMachine machine(tape, program);
			machine.setHead(2);
			machine--;
			Assert::IsTrue(machine.getTape().getStr() == "011101010");
		}

		TEST_METHOD(TestMethod6)
		{
			Tape tape("010101010");
			Program program;
			"? 2 4" >> program;
			"v" >> program;
			">" >> program;
			"v" >> program;
			"!" >> program;
			PostMachine machine(tape, program);
			machine++;
			Tape expectedTape("010101010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod7)
		{
			Tape tape("010101010");
			Program program;
			"? 2 4" >> program;
			"v" >> program;
			">" >> program;
			"v" >> program;
			"!" >> program;
			PostMachine machine(tape, program);
			machine++;
			machine++;
			machine++;
			machine++;
			machine++;
			Tape expectedTape("110101010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod8)
		{
			Tape tape("010101010");
			Program program;
			"? 2 4" >> program;
			"v" >> program;
			"<" >> program;
			"x" >> program;
			"!" >> program;
			program.changeCommand(1, '<', Arguments{});
			PostMachine machine(tape, program);
			machine.setHead(3);
			machine--;
			Tape expectedTape("001101010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod9)
		{
			Tape tape("010101010");
			Program program;
			"? 2 4" >> program;
			"v" >> program;
			"<" >> program;
			"x" >> program;
			"!" >> program;
			program.changeCommand(5, '<', Arguments{});
			program.addCommand(6, '!', Arguments{});
			PostMachine machine(tape, program);
			machine.setHead(3);
			machine--;
			Tape expectedTape("010001010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod10)
		{
			Tape tape("010101010");
			Program program;
			"? 2 4" >> program;
			"v" >> program;
			"<" >> program;
			"x" >> program;
			"!" >> program;
			program.changeCommand(5, '<', Arguments{});
			program.addCommand(6, 'v', Arguments{});
			program.addCommand(7, '!', Arguments{});
			PostMachine machine(tape, program);
			machine.setHead(3);
			machine--;
			Tape expectedTape("011001010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}

		TEST_METHOD(TestMethod11)
		{
			Tape tape("010101010");
			Program program;
			"l" >> program;
			"v" >> program;
			"!" >> program;
			PostMachine machine(tape, program);
			machine.setHead(4);
			machine--;
			Tape expectedTape("010111010");
			PostMachine expected(expectedTape);
			Assert::AreEqual(expected, machine);
		}
	};
}
