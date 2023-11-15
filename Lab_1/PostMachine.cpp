#include "PostMachine.h"

using namespace std;

Tape::Tape() { }

Tape::Tape(string tape) : str(tape) { }

size_t Tape::getSize() {
    return str.size();
}

void Tape::removeLabel(size_t position) {
    str[position] = '0';
}

void Tape::insertLabel(size_t position) {
    str[position] = '1';
}

bool Tape::isLabel(size_t position) {
    return (str[position] == '1') ? true : false;
}

string Tape::getStr() {
    return str;
}

void operator>>(std::string str, Tape& tape) {
    tape.str = str;
}

 void operator>>(string str, Program& program) {
    stringstream ss(str);
    char command;
    ss >> command;
    program.commandLines.push_back(command);
    int arg = 0;
    Arguments args;
    if (command == '?') {
        ss >> arg;
        args.first = arg;
        ss >> arg;
        args.second = arg;
    }
    else if (command == '!') {}
    else {
        ss >> arg;
        if (arg)
            args.first = arg;
        else
            args.first = program.argsLines.size() + 2;
    }
    program.argsLines.push_back(args);
}

void operator>>(ifstream& inputFile, Program& program) {
    string str;
    while (getline(inputFile, str)) {
        str >> program;
    }
}

void Program::addCommand(size_t line, char command, Arguments args) {
    if (line == commandLines.size() + 1) {
        commandLines.push_back(command);
        if (args.first == 0)
            args.first = line + 1;
        argsLines.push_back(args);
        return;
    }
    if (line > commandLines.size()) {
        return;
    }
    commandLines.insert(commandLines.begin() + line - 1, command);
    argsLines.insert(argsLines.begin() + line - 1, args);
}
    
void Program::deleteCommand(size_t line) {
    commandLines.erase(commandLines.begin() + line - 1);
    argsLines.erase(argsLines.begin() + line - 1);
}

void Program::changeCommand(size_t line, char command, Arguments args) {
    if (args.first == 0)
        args.first = line + 1;
    commandLines[line - 1] = command;
    argsLines[line - 1] = args;
}

void Program::print() {
    for (int i = 0; i < commandLines.size(); i++) {
        cout << commandLines[i] << " ";
        if (argsLines[i].first > 0)
            cout << argsLines[i].first << " ";
        if (argsLines[i].second > 0)
            cout << argsLines[i].second;
        cout << endl;
    }
}

size_t Program::getSize() const {
    return commandLines.size();
}

void Program::getCommand(char& command, Arguments& args, size_t line) {
    if (line > commandLines.size()) {
        cout << "Out of bounds" << endl;
        exit(EXIT_FAILURE);
    }
    command = commandLines[line - 1];
    args = argsLines[line - 1];
}

Head::Head(Tape tape) : position(0) {
    this->tape = tape;
}

void Head::setPosition(size_t position) {
    if (position >= 0 && position < tape.getSize())
        this->position = position;
}

bool Head::isLabel() {
    return tape.isLabel(position);
}

void Head::removeLabel() {
    tape.removeLabel(position);
}

void Head::insertLabel() {
    tape.insertLabel(position);
}

void Head::moveLeft() {
    if (position != 0)
        position--;
}

void Head::moveRight() {
    if (position != tape.getSize() - 1)
        position++;
}

size_t Head::getPosition() {
    return position;
}

Tape Head::getTape() const {
    return tape;
}

PostMachine::PostMachine(Tape tape, Program program)
    : head(tape), program(program), programLine(1), toPrint(false) {}

PostMachine::PostMachine(Tape tape)
    : head(tape), program(), programLine(1), toPrint(false) {

}

Tape PostMachine::getTape() const {
    return head.getTape();
}

void PostMachine::setHead(size_t position) {
    head.setPosition(position);
}

void PostMachine::operator++(int) {
    if (programLine > head.getTape().getSize())
        return;

    Arguments args;
    char command;
    program.getCommand(command, args, programLine);
    
    if (command == '!')
        return;
    executeCommnad(command, args);
}

void PostMachine::operator--(int) {
    if (programLine > program.getSize())
        return;

    Arguments args;
    char command;
    program.getCommand(command, args, programLine);
    while (command != '!') {
        executeCommnad(command, args);
        program.getCommand(command, args, programLine);
    }
}

bool PostMachine::operator==(const PostMachine& machine2) const {
    return head.getTape().getStr() == machine2.head.getTape().getStr();
}

void PostMachine::printTape() {
    cout << head.getTape().getStr() << endl;
    string indent = string(head.getPosition(), ' ');
    cout << indent << '^' << endl;
}

void PostMachine::executeCommnad(const char command, const Arguments& args) {
    switch (command) {
    case '?':
        if (!head.isLabel()) {
            programLine = args.first;
            break;
        }
        programLine = args.second;
        break;
    case '>':
        head.moveRight();
        programLine = args.first;
        break;
    case '<':
        head.moveLeft();
        programLine = args.first;
        break;
    case 'x':
        head.removeLabel();
        programLine = args.first;
        break;
    case 'v':
        head.insertLabel();
        programLine = args.first;
        break;
    case 'l':
        toPrint = true;
        programLine = args.first;
        break;
    default:
        exit(EXIT_FAILURE);
    }

    if (toPrint) {
        printTape();
    }
}