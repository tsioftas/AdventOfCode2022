#include <fstream>
#include <iostream>

using namespace std;

void update_maxsums(int* maxelfsums, int elfsum)
{
    int pos = 0;
    while(pos < 3)
    {
        if(elfsum > maxelfsums[pos])
        {
            swap(maxelfsums[pos], elfsum);
        }
        ++pos;
    }
}

int main()
{
    ifstream fin("1.in");
    int elfsum = 0;
    int maxelfsums[3] = {0, 0, 0};
    int calories;
    string input;
    while(getline(fin, input))
    {
        if(input == "")
        {
            update_maxsums(maxelfsums, elfsum);
            elfsum = 0;
        }
        else
        {
            calories = stoi(input);
            elfsum += calories;
        }
    }
    int sum = maxelfsums[0] + maxelfsums[1] + maxelfsums[2];
    cout<<maxelfsums[0]<<" "<<maxelfsums[1]<<" "<<maxelfsums[2]<<"\n";
    cout << sum << "\n";
    fin.close();
    return 0;
}