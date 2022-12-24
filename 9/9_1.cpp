#include "9_commons.h"

int main()
{
    vector<pair<char, int> > input = read_input();
    coord_t *head = new coord_t(0,0), *tail = new coord_t(0,0);
    set<coord_t> tailcoords;
    tailcoords.insert(*tail);
    for(int i=0;i<input.size();++i)
    {
        for(int rep=0;rep<input[i].reps;++rep)
        {
            move(head, tail, input[i].instr);
            tailcoords.insert(*tail);
        }
    }
    cout<<tailcoords.size()<<"\n";
    return 0;
}