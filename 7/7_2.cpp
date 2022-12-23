#include "7_commons.h"

using namespace std;

pair<int, vector<directory*> > find_directories_over_threshold(int threshold, directory* pos)
{
    vector<filesystem_node*> options = pos->get_contents();
    vector<directory*> ret;
    int ownsize = 0;
    for(int i=0;i<options.size();++i)
    {
        filesystem_node* curr = options[i];
        if(curr->get_type() == DIRECTORY_T)
        {
            pair<int, vector<directory*> > result = find_directories_over_threshold(threshold, (directory*)curr);
            ownsize += result.first;
            vector<directory*> v = result.second;
            ret.insert(ret.end(), v.begin(), v.end());
        }
        else if(curr->get_type() == FILE_T)
        {
            ownsize += ((file*)curr)->get_size();
        }
    }
    if(ownsize >= threshold)
    {
        ret.push_back(pos);
    }
    return mp(ownsize, ret);
}

const int CAPACITY = 70000000;
const int UPDATE_SIZE = 30000000;

int main()
{
    directory* root = read_input();
    int used_space = root->get_size();
    int free_space = CAPACITY - used_space;
    int to_free = UPDATE_SIZE - free_space;
    pair<int, vector<directory*> > result = find_directories_over_threshold(to_free, root);
    vector<directory*> selected = result.second;
    int smallest = CAPACITY;
    for(int i=0;i<selected.size();++i)
    {
        int size = selected[i]->get_size();
        if(size < smallest)
        {
            smallest = size;
        }
    }
    cout<<smallest<<"\n";
    return 0;
}