#include "9_commons.h"

bool touching(coord_t* head, coord_t* tail)
{
    for(int addx=-1;addx<=1;++addx)
    {
        for(int addy=-1;addy<=1;++addy)
        {
            int checkx = head->x + addx;
            int checky = head->y + addy;
            if(tail->x == checkx && tail->y == checky)
            {
                return true;
            }
        }
    }
    return false;
}

void update(coord_t* head, coord_t* tail)
{
    if(touching(head, tail))
    {
        return;
    }
    int dx = head->x - tail->x;
    int dy = head->y - tail->y;
    int addx = dx < 0 ? -1 : dx > 0 ? 1 : 0;
    int addy = dy < 0 ? -1 : dy > 0 ? 1 : 0;
    tail->x += addx;
    tail->y += addy;
}

void move(coord_t* head, coord_t* tail, char direction)
{
    pair<int, int> d = direction_to_changes(direction);
    int addx = d.first, addy = d.second;
    head->x += addx;
    head->y += addy;
    update(head, tail);
    return;
}

vector<pair<char, int> > read_input()
{
    ifstream fin("9.in");
    vector<pair<char, int> > input;
    pair<char, int> tmp;
    while(fin>>tmp.instr>>tmp.reps)
    {
        input.push_back(tmp);
    }
    fin.close();
    return input;
}

void move(vector<coord_t*> rope, char direction)
{
    pair<int, int> d = direction_to_changes(direction);
    int addx = d.first, addy = d.second;
    rope[0]->x += addx;
    rope[0]->y += addy;
    for(int i=0;i<rope.size()-1;++i)
    {
        update(rope[i], rope[i+1]);
    }
}

pair<int, int> direction_to_changes(char direction)
{
    int addx=0, addy=0;
    switch(direction)
    {
        case 'L':
            addx = -1;
            break;
        case 'R':
            addx = 1;
            break;
        case 'U':
            addy = 1;
            break;
        case 'D':
            addy = -1;
            break;
        default:
            throw runtime_error("Invalid direction given: "+direction);
            break;
    }
    return mp(addx, addy);
}