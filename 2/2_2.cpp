#include <fstream>
#include <iostream>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define LOSS 0
#define DRAW 3
#define WIN 6
using namespace std;

int outcomes[3] = {LOSS, DRAW, WIN};
int choices[3] = {ROCK, PAPER, SCISSORS};
int choice_scores[3] = {1,2,3};
int to_lose[3] = {SCISSORS, ROCK, PAPER};
int to_win[3] = {PAPER, SCISSORS, ROCK};

int match_score(int opponent, int outcome)
{
    int player;
    if(outcome == LOSS)
    {
        player = to_lose[opponent];
    }
    else if(outcome == WIN)
    {
        player = to_win[opponent];
    }
    else if(outcome == DRAW)
    {
        player = opponent;
    }
    int s = choice_scores[player] + outcome;
    return s;
}

int char_to_choice(char c)
{
    c -= 'A';
    return choices[c];
}

int char_to_outcome(char c)
{
    c-= 'X';
    return outcomes[c];
}

int main()
{
    ifstream fin("2.in");
    char opponent, player;
    int total_score = 0;
    while(fin>>opponent>>player)
    {
        int opp = char_to_choice(opponent);
        int outcome = char_to_outcome(player);
        total_score += match_score(opp, outcome);
    }
    cout<<total_score<<"\n";
    return 0;
}