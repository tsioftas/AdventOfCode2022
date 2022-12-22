#include <fstream>
#include <iostream>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define WIN 6
#define DRAW 3
using namespace std;

int choices[3] = {ROCK, PAPER, SCISSORS};
int choice_scores[3] = {1,2,3};

int match_score(int opponent, int player)
{
    int s = choice_scores[player];
    if(opponent == player)
    {
        s += DRAW;
    }
    else if((opponent == ROCK && player == PAPER) || 
            (opponent == PAPER && player == SCISSORS) ||
            (opponent == SCISSORS && player == ROCK))
    {
        s += WIN;
    }
    return s;
}

int char_to_choice(char c)
{
    if(c >= 'A' && c <= 'C')
    {
        c -= 'A';
    }
    else if(c >= 'X' && c <= 'Z')
    {
        c -= 'X';
    }
    return choices[c];
}

int main()
{
    ifstream fin("2.in");
    char opponent, player;
    int total_score = 0;
    while(fin>>opponent>>player)
    {
        int opp = char_to_choice(opponent);
        int plr = char_to_choice(player);
        total_score += match_score(opp, plr);
    }
    cout<<total_score<<"\n";
    return 0;
}