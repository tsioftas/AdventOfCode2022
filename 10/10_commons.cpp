#include "10_commons.h"


cpu::cpu(vector<instruction*> instructions)
{
    this->instructions = instructions;
    this->current_cycle = 1;
    this->reg = 1;
    this->pc = 0;
}

cpu::~cpu()
{
    for(int i=0;i<this->instructions.size();++i)
    {
        free(this->instructions[i]);
    }
}

int cpu::get_current_cycle()
{
    return this->current_cycle;
}

int cpu::get_register_value()
{
    return this->reg;
}

bool cpu::step()
{
    if(this->pc >= this->instructions.size())
    {
        return true;
    }
    instruction* instr = this->instructions[this->pc];
    bool instruction_finished = instr->step(&(this->reg));
    if(instruction_finished)
    {
        ++this->pc;
    }
    ++this->current_cycle;
    return this->pc == this->instructions.size();
}

instruction::instruction(instruction_type t, vector<int> parameters)
{
    this->t = t;
    this->parameters = parameters;
    this->progress = 0;
    if(t == ADDX)
    {
        this->cycles_needed = 2;
    }
    else if(t == NOOP)
    {
        this->cycles_needed = 1;
    }
    else
    {
        throw runtime_error("Invalid instruction given: "+t);
    }
}

bool instruction::step(int* reg)
{
    if(this->progress >= this->cycles_needed)
    {
        throw runtime_error("Instruction executed for too many cycles");
    }
    if(this->t == ADDX && this->progress == 1)
    {
        (*reg) += this->parameters[0];
    }
    ++this->progress;
    return this->progress == this->cycles_needed;
}

vector<instruction*> read_input()
{
    ifstream fin("10.in");
    string instruction_str;
    vector<instruction*> input;
    while(fin>>instruction_str)
    {
        vector<int> parameters;
        if(instruction_str == "noop")
        {
            input.push_back(new instruction(NOOP, parameters));
        }
        else if(instruction_str == "addx")
        {
            int p;
            fin>>p;
            parameters.push_back(p);
            input.push_back(new instruction(ADDX, parameters));
        }
        else
        {
            throw runtime_error("Invalid instruction: "+instruction_str);
        }
    }
    fin.close();
    return input;
}