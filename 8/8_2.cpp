#include "8_commons.h"

int main()
{
    grid_t grid = read_input();
    cout<<find_best_score(grid)<<"\n";
    return 0;
}