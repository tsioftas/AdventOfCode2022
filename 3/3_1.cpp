#include <iostream>
#include <fstream>

using namespace std;

char find_item(string rucksack)
{
    int mid = rucksack.size()/2-1;
    int cnt_capitals[26], cnt_small[26];
    for(int i=0;i<26;++i)
    {
        cnt_capitals[i] = cnt_small[i] = 0;
    }
    for(int i=0;i<=mid;++i)
    {
        char c = rucksack[i];
        if('a' <= c && c <= 'z')
        {
            ++cnt_small[c-'a'];
        }
        else if('A' <= c && c <= 'Z')
        {
            ++cnt_capitals[c-'A'];
        }
    }
    for(int i=mid+1;i<rucksack.size();++i)
    {
        char c = rucksack[i];
        if('a' <= c && c <= 'z')
        {
            if(cnt_small[c-'a'] > 0)
            {
                return c;
            }
        }
        else if('A' <= c && c <= 'Z')
        {
            if(cnt_capitals[c-'A'] > 0)
            {
                return c;
            }
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
    string rucksack;
    int total = 0;
    while(fin>>rucksack)
    {
        char item = find_item(rucksack);
        total += char_to_priority(item);
    }
    cout<<total<<"\n";
    fin.close();
    return 0;
}