#include "6_commons.h"

int solve(int M)
{
    ifstream fin("6.in");
    char nextc;
    char relevant[M];
    unordered_map<char, int> cnt_chars;
    int p = 0;
    char c;
    while(fin>>c)
    {
        if(p >= M)
        {
            --cnt_chars[relevant[p%M]];
        }
        relevant[p%M] = c;
        ++cnt_chars[c];
        bool ok = true;
        for(int i=0;ok && i<M;++i)
        {
            ok &= cnt_chars[relevant[i]] == 1;
        }
        if(ok)
        {
            break;
        }
        ++p;
    }
    fin.close();
    return p+1;
}