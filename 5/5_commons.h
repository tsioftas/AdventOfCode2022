#ifndef COMMONS5H
#define COMMONS5H

#include <stack>
#include <fstream>
#include <iostream>
#include <vector>

#define count first
#define from second.first
#define to second.second
#define mp make_pair
using namespace std;

typedef pair<int, pair<int, int> > instruction;
typedef pair<vector<stack<char> >, vector<instruction> > input_t;


bool isnum(char c);

int find_next_num(int* pos, string s);

instruction make_instruction(string s);

input_t read_and_parse_input();

#endif // COMMONS5H