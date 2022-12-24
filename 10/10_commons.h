#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum instruction_type {ADDX, NOOP};

class instruction
{
private:
    instruction_type t;
    int cycles_needed, progress;
    vector<int> parameters;
public:
    instruction(instruction_type t, vector<int> parameters);
    bool step(int* reg);
};

class cpu
{
private:
    vector<instruction*> instructions;
    int current_cycle;
    int pc, reg;
public:
    cpu(vector<instruction*> instructions);
    ~cpu();
    int get_current_cycle();
    int get_register_value();
    bool step();
};

vector<instruction*> read_input();