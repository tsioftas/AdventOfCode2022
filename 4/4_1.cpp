#include <iostream>
#include <fstream>

#define fst first
#define snd second
#define mp make_pair
using namespace std;

typedef pair<int, int> range;

bool contains(range lrg, range sml)
{
    return lrg.fst <= sml.fst && sml.snd <= lrg.snd;
}

bool total_overlap(range r1, range r2)
{
    return contains(r1, r2) || contains(r2, r1);
}

int main()
{
    ifstream fin("4.in");
    int total = 0;
    int l1,r1,l2,r2;
    char bs;
    while(fin>>l1>>bs>>r1>>bs>>l2>>bs>>r2)
    {
        range range1 = mp(l1, r1);
        range range2 = mp(l2, r2);
        if(total_overlap(range1, range2))
        {
            ++total;
        }
    }
    cout<<total<<"\n";
    fin.close();
    return 0;
}