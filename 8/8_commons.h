#ifndef COMMONS8_H
#define COMMONS8_H

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

typedef vector<vector<int> > grid_t;

grid_t read_input();

int count_visible_trees(grid_t grid);

bool valid_coords(int i, int j, int M, int N);

void count_visible_trees_from(grid_t grid, int di, int dj, bool** visible);

int count_scenic_score_in_direction(grid_t grid, int di, int dj, int i, int j);

int find_best_score(grid_t grid);

#endif // COMMONS8_H