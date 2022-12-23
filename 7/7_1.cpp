#include "7_commons.h"

using namespace std;

pair<int, vector<directory*> > find_directories_under_threshold(int threshold, directory* pos)
{
    vector<filesystem_node*> options = pos->get_contents();
    vector<directory*> ret;
    int ownsize = 0;
    for(int i=0;i<options.size();++i)
    {
        filesystem_node* curr = options[i];
        if(curr->get_type() == DIRECTORY_T)
        {
            pair<int, vector<directory*> > result = find_directories_under_threshold(threshold, (directory*)curr);
            ownsize += result.first;
            vector<directory*> v = result.second;
            ret.insert(ret.end(), v.begin(), v.end());
        }
        else if(curr->get_type() == FILE_T)
        {
            ownsize += ((file*)curr)->get_size();
        }
    }
    if(ownsize <= threshold)
    {
        ret.push_back(pos);
    }
    return mp(ownsize, ret);
}

int main()
{
    directory* root = read_input();
    pair<int, vector<directory*> > result = find_directories_under_threshold(100000, root);
    vector<directory*> selected = result.second;
    int sum = 0;
    for(int i=0;i<selected.size();++i)
    {
        sum += selected[i]->get_size();
    }
    cout<<sum<<"\n";
    return 0;
}