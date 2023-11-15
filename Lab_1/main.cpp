#include "PostMachine.h"
#include <fstream>


using namespace std;

int main() {
	std::ifstream inputFile("program.txt");
	Program program;
	inputFile >> program;
	inputFile.close();
	Tape tape;
	"00111110111000" >> tape;
	PostMachine machine(tape, program);
	machine.setHead(8);
	machine--;
	machine.printTape();
    return 0;
}
