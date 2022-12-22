#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

char find_badge(string r1, string r2, string r3)
{
    unordered_map<char, bool> has1, has2;
    for(int i=0;i<r1.size();++i)
    {
        has1[r1[i]] = true;
    }
    for(int i=0;i<r2.size();++i)
    {
        has2[r2[i]] = true;
    }
    for(int i=0;i<r3.size();++i)
    {
        char c = r3[i];
        if(has1[c] && has2[c])
        {
            return c;
        }
    }
    return '#';
}

int char_to_priority(char c)
{
    if('a' <= c && c <= 'z')
    {
        return c-'a'+1;
    }
    else if('A' <= c && c <= 'Z')
    {
        return c-'A'+27;
    }
    return 9999999;
}

int main()
{
    ifstream fin("3.in");
    string r1,r2,r3;
    int total = 0;
    while(fin>>r1>>r2>>r3)
    {
        char item = find_badge(r1, r2, r3);
        total += char_to_priority(item);
    }
    cout<<total<<"\n";
    fin.close();
    return 0;
}