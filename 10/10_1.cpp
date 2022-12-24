#include "10_commons.h"

int main()
{
    vector<instruction*> instructions = read_input();
    cpu CPU = cpu(instructions);
    bool execution_finished = false;
    int sum = 0;
    do
    {
        int current_cycle = CPU.get_current_cycle();
        if(current_cycle >= 20 && (current_cycle-20)%40 == 0)
        {
            // a cycle of interest
            int ss = current_cycle * CPU.get_register_value();
            sum += ss;
        }
        execution_finished = CPU.step();
    }while(!execution_finished);
    cout<<sum<<"\n";
    return 0;
}