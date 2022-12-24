#include "8_commons.h"

using namespace std;

int main()
{
    grid_t g = read_input();
    int answer = count_visible_trees(g);
    cout<<answer<<"\n";
    return 0;
}