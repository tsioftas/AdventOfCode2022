#include "9_commons.h"

const int ROPE_SIZE = 10;

int main()
{
    vector<pair<char, int> > input = read_input();
    vector<coord_t*> rope;
    for(int i=0;i<ROPE_SIZE;++i)
    {
        rope.push_back(new coord_t(0, 0));
    }
    set<coord_t> tailcoords;
    coord_t* tail = rope[ROPE_SIZE-1];
    tailcoords.insert(*tail);
    for(int i=0;i<input.size();++i)
    {
        for(int rep=0;rep<input[i].reps;++rep)
        {
            move(rope, input[i].instr);
            tailcoords.insert(*tail);
        }
    }
    cout<<tailcoords.size()<<"\n";
    return 0;
}