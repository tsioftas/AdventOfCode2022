#include <iostream>
#include <fstream>
#include <set>
#include <vector>

#define mp make_pair
#define instr first
#define reps second
#define x first
#define y second
using namespace std;

typedef pair<int, int> coord_t;

bool touching(coord_t* head, coord_t* tail);

void update(coord_t* head, coord_t* tail);

void move(coord_t* head, coord_t* tail, char direction);

void move(vector<coord_t*> rope, char direction);

vector<pair<char, int> > read_input();

pair<int, int> direction_to_changes(char direction);