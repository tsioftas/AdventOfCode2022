#include "10_commons.h"

const int CRT_W = 40, CRT_H = 6;
const int P = CRT_W*CRT_H;
char CRT[CRT_H][CRT_W];

pair<int, int> num_to_pixel_coords(int p)
{
    int j = p % CRT_W;
    int i = p / CRT_W;
    return make_pair(i, j);
}

void draw_pixel(int sprite_centre, int pixel)
{
    pair<int, int> pixel_coords = num_to_pixel_coords(pixel);
    char c = abs(sprite_centre-pixel_coords.second) <= 1 ? '#' : '.';
    CRT[pixel_coords.first][pixel_coords.second] = c;
    return;
}

void print_CRT()
{
    for(int i=0;i<CRT_H;++i)
    {
        for(int j=0;j<CRT_W;++j)
        {
            cout<<CRT[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    vector<instruction*> instructions = read_input();
    cpu CPU = cpu(instructions);
    bool execution_finished = false;
    int pixel = 0;
    do
    {
        int sprite_centre = CPU.get_register_value();
        draw_pixel(sprite_centre, pixel);
        pixel = (pixel+1)%P;
        execution_finished = CPU.step();
    }while(!execution_finished);
    print_CRT();
    return 0;
}