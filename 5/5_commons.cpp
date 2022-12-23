#include "5_commons.h"

bool isnum(char c)
{
    return '0' <= c && c <= '9';
}

int find_next_num(int* pos, string s)
{
    while(!isnum(s[*pos]))
    {
        ++(*pos);
    }
    int ret = 0;
    while(isnum(s[*pos]))
    {
        ret = ret*10+(s[*pos]-'0');
        ++(*pos);
    }
    return ret;
}

instruction make_instruction(string s)
{
    int c, f, t;
    int p = 0;
    c = find_next_num(&p, s);
    f = find_next_num(&p, s)-1; // change to 0-indexed
    t = find_next_num(&p, s)-1; // change to 0-indexed
    return mp(c, mp(f,t));
}

input_t read_and_parse_input()
{
    ifstream fin("5.in");
    string line;
    vector<stack<char> > stacks;
    vector<instruction> instructions;
    bool stacks_read = false;
    while(getline(fin, line))
    {
        if(stacks_read)
        {
            if(line.size() > 0)
            {
                instructions.push_back(make_instruction(line));
            }
        }
        else
        {
            if(stacks.size() == 0)
            {
                // first line of input
                stacks.resize((line.size()+1)/4);
            }
            if(line[1] != '1')
            {
                for(int stack_idx=0;stack_idx<stacks.size();++stack_idx)
                {
                    int i = stack_idx*4+1;
                    if(line[i] != ' ')
                    {
                        stacks[stack_idx].push(line[i]);
                    }
                }
            }
            else
            {
                for(int stack_idx=0;stack_idx<stacks.size();++stack_idx)
                {
                    stack<char> reversed;
                    while(!stacks[stack_idx].empty())
                    {
                        reversed.push(stacks[stack_idx].top());
                        stacks[stack_idx].pop();
                    }
                    stacks[stack_idx] = reversed;
                }
                stacks_read = true;
            }
        }
    }
    fin.close();
    return mp(stacks, instructions);
}
