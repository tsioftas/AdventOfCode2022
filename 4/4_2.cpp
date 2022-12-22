#include <iostream>
#include <fstream>

#define fst first
#define snd second
#define mp make_pair
using namespace std;

typedef pair<int, int> range;

bool overlap(range r1, range r2)
{
    return !(r2.snd < r1.fst || r2.fst > r1.snd);
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
        if(overlap(range1, range2))
        {
            ++total;
        }
    }
    cout<<total<<"\n";
    fin.close();
    return 0;
}