#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <cstring>

#define MEM_SIZE 100

struct regs
{
    int counter;
    int instruction;
    short opCode;
    short operand;
    int accumulator;
};

class Simpletron
{
private:
    int memory[MEM_SIZE] = {0};
    regs reg = {0};
    std::map<short, bool (Simpletron::*)()> handlers = {
        {OpCode::READ, &Simpletron::opRead},
        {OpCode::WRITE, &Simpletron::opWrite},
        {OpCode::LOAD, &Simpletron::opLoad},
        {OpCode::STORE, &Simpletron::opStore},
        {OpCode::ADD, &Simpletron::opAdd},
        {OpCode::SUBTRACT, &Simpletron::opSubtract},
        {OpCode::DIVIDE, &Simpletron::opDivide},
        {OpCode::MULTIPLY, &Simpletron::opMultiply},
        {OpCode::BRANCH, &Simpletron::opBranch},
        {OpCode::BRANCHNEG, &Simpletron::opBranchNeg},
        {OpCode::BRANCHZERO, &Simpletron::opBranchZero},
        {OpCode::HALT, &Simpletron::opHalt}};

    bool opRead();
    bool opWrite();
    bool opLoad();
    bool opStore();
    bool opAdd();
    bool opSubtract();
    bool opDivide();
    bool opMultiply();
    bool opBranch();
    bool opBranchNeg();
    bool opBranchZero();
    bool opHalt();

    void load(const std::vector<short>& program);
    void reset();
    void execute();
    void dumpRegisters() const;
    void dumpMemory() const;
    void printInteractiveMenu() const;

public:
    enum OpCode
    {
        READ = 10,
        WRITE = 11,
        LOAD = 20,
        STORE = 21,
        ADD = 30,
        SUBTRACT = 31,
        DIVIDE = 32,
        MULTIPLY = 33,
        BRANCH = 40,
        BRANCHNEG = 41,
        BRANCHZERO = 42,
        HALT = 43
    };
    bool parse(const std::vector<short> program);
    void dump() const;
    void run(const std::vector<short>& program);
    std::vector<short> *readProgram();
    std::vector<short> *readFromFile(std::string fileName);
};