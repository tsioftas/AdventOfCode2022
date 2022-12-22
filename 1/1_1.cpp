#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream fin("1.in");
    int elfsum = 0;
    int maxelfsum = -1;
    int calories;
    string input;
    while(getline(fin, input))
    {
        if(input == "")
        {
            maxelfsum = max(elfsum, maxelfsum);
            elfsum = 0;
        }
        else
        {
            calories = stoi(input);
            elfsum += calories;
        }
    }
    cout << maxelfsum << "\n";
    fin.close();
    return 0;
}