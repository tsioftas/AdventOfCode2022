#include "8_commons.h"

grid_t read_input()
{
    ifstream fin("8.in");
    string line;
    grid_t ret;
    while(fin>>line)
    {
        ret.push_back(vector<int>());
        for(int i=0;i<line.size();++i)
        {
            int x = line[i]-'0';
            ret[ret.size()-1].push_back(x);
        }
    }
    fin.close();
    return ret;
}

int count_visible_trees(grid_t grid)
{
    int M = grid.size();
    int N = grid[0].size();
    bool** visible = (bool**)malloc(M*sizeof(bool*));
    for(int i=0;i<M;++i)
    {
        visible[i] = (bool*)malloc(N*sizeof(bool));
        for(int j=0;j<N;++j)
        {
            visible[i][j] = false;
        }
    }
    count_visible_trees_from(grid, -1, 0, visible);
    count_visible_trees_from(grid, 1, 0, visible);
    count_visible_trees_from(grid, 0, -1, visible);
    count_visible_trees_from(grid, 0, 1, visible);
    int count = 0;
    for(int i=0;i<M;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(visible[i][j])
            {
                ++count;
            }
        }
        free(visible[i]);
    }
    free(visible);
    return count;
}

bool valid_coords(int i, int j, int M, int N)
{
    return 0 <= i && i < M && 0 <= j && j < N;
}

void count_visible_trees_from(grid_t grid, int di, int dj, bool** visible)
{
    int M = grid.size();
    int N = grid[0].size();
    int count = 0;
    int max_in_dir[M][N];
    int i_start = di == -1 ? 0 : M-1;
    int i_stop = di == -1 ? M : -1;
    int i_add = i_start <= i_stop ? 1 : -1;
    int j_start = dj == -1 ? 0 : N-1;
    int j_stop = dj == -1 ? N : -1;
    int j_add = j_start <= j_stop ? 1 : -1;
    for(int i = i_start; i != i_stop; i += i_add)
    {
        for(int j=j_start; j != j_stop; j += j_add)
        {
            int check_i = i+di;
            int check_j = j+dj;
            if(valid_coords(check_i, check_j, M, N))
            {
                max_in_dir[i][j] = max(max_in_dir[check_i][check_j], grid[check_i][check_j]);
            }
            else
            {
                max_in_dir[i][j] = -1;
            }
            if(max_in_dir[i][j] < grid[i][j])
            {
                visible[i][j] = true;
            }
        }
    }
    return;
}

int count_scenic_score_in_direction(grid_t grid, int di, int dj, int i, int j)
{
    int x = i+di, y = j+dj;
    int M = grid.size();
    int N = grid[0].size();
    int score = 0;
    while(valid_coords(x, y, M, N))
    {
        ++score;
        if(grid[x][y] >= grid[i][j])
        {
            break;
        }
        x += di;
        y += dj;
    }
    return score;
}

int find_best_score(grid_t grid)
{
    int M = grid.size();
    int N = grid[0].size();
    int max_score = 0;
    for(int i=0;i<M;++i)
    {
        for(int j=0;j<N;++j)
        {
            int score = count_scenic_score_in_direction(grid, -1, 0, i, j)*
                count_scenic_score_in_direction(grid, 1, 0, i, j)*
                count_scenic_score_in_direction(grid, 0, -1, i, j)*
                count_scenic_score_in_direction(grid, 0, 1, i, j);
            max_score = max(score, max_score);
        }
    }
    return max_score;
}