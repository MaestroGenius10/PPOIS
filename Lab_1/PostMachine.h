#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


struct Arguments {
    Arguments() : first(0), second(0) { }
    Arguments(size_t first) : first(first), second(0) { }
    Arguments(size_t first, size_t second) : first(first), second(second) { }
    size_t first;
    size_t second;
};

class Tape {
public:
    Tape();
    Tape(std::string tape);
    size_t getSize();
    void removeLabel(size_t position);
    void insertLabel(size_t position);
    bool isLabel(size_t position);
    std::string getStr();
    friend void operator>>(std::string str, Tape& tape);
private:
    std::string str;
};

class Program {
public:
    friend void operator>>(std::string str, Program& program);
    friend void operator>>(std::ifstream& inputFile, Program& program);
    void addCommand(size_t line, char command, Arguments args);
    void deleteCommand(size_t line);
    void changeCommand(size_t line, char command, Arguments args);
    void print();
    void getCommand(char& command, Arguments& args, size_t line);
    size_t getSize() const;
private:
    std::vector<char> commandLines;
    std::vector<Arguments> argsLines;
};

class Head {
public:
    Head(Tape tape);
    void setPosition(size_t position);
    bool isLabel();
    void removeLabel();
    void insertLabel();
    void moveLeft();
    void moveRight();
    size_t getPosition();
    Tape getTape() const;
private:
    size_t position;
    Tape tape;
};

class PostMachine {
public:
    PostMachine(Tape tape, Program program);
    PostMachine(Tape);
    bool operator==(const PostMachine& machine2) const;
    void setHead(size_t position);
    void operator++(int);
    void operator--(int);
    Tape getTape() const;
    void printTape();
private:
    void executeCommnad(const char command, const Arguments& args);
    bool toPrint;
    size_t programLine;
    Head head;
    Program program;
};