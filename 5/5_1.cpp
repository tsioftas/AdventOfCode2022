#include "5_commons.h"

int main()
{
    input_t input;
    input = read_and_parse_input();
    vector<stack<char> > stacks = input.first;
    vector<instruction> instructions = input.second;

    for(int i=0;i<instructions.size();++i)
    {
        int f = instructions[i].from;
        int t = instructions[i].to;
        for(int j=0;j<instructions[i].count;++j)
        {
            char crate = stacks[f].top();
            stacks[f].pop();
            stacks[t].push(crate);
        }
    }

    for(int i=0;i<stacks.size();++i)
    {
        cout<<stacks[i].top();
    }
    cout<<"\n";
    return 0;
}