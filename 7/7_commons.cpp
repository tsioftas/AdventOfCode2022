#include "7_commons.h"

filesystem_node::filesystem_node(string name, filesystem_node_type t)
{
    this->name = name;
    this->type = t;
}

filesystem_node_type filesystem_node::get_type()
{
    return this->type;
}

string filesystem_node::get_name()
{
    return this->name;
}

directory::directory(string name, directory* parent) : filesystem_node(name, DIRECTORY_T)
{
    this->parent = parent;
}

void directory::add_content(filesystem_node* n)
{
    this->contents.push_back(n);
}

vector<filesystem_node*> directory::get_contents()
{
    return this->contents;
}

int directory::get_size()
{
    int s = 0;
    for(int i=0;i<this->contents.size();++i)
    {
        filesystem_node_type t = this->contents[i]->get_type();
        if(t == DIRECTORY_T)
        {
            s += ((directory*)(this->contents[i]))->get_size();
        }
        else if(t == FILE_T)
        {
            s += ((file*)(this->contents[i]))->get_size();
        }
        else
        {
            throw runtime_error("Unexpected type of filesystem node found: "+this->get_name()+"/"+this->contents[i]->get_name());
        }
    }
    return s;
}

directory* directory::get_parent()
{
    return this->parent;
}

file::file(string name, directory* parent, int size) : filesystem_node(name, FILE_T)
{
    this->size = size;
    this->parent = parent;
}

int file::get_size()
{
    return this->size;
}

directory* file::get_parent()
{
    return this->parent;
}

directory* read_input()
{
    directory* root = new directory("/", nullptr);
    ifstream fin("7.in");
    string line;
    getline(fin, line);
    const string expected_first_line = "$ cd /";
    if(line != expected_first_line)
    {
        throw invalid_argument("Expected the input to start from root directory");
        return root;
    }
    directory* cwd = root;
    bool reading_ls_output = false;
    while(getline(fin, line))
    {
        if(line[0] == '$')
        {
            reading_ls_output = false;
            string command = line.substr(2, 2);
            if(command == "cd")
            {
                string target = line.substr(5, line.size()-5);
                directory* next = nullptr;
                if(target == "..")
                {
                    next = cwd->get_parent();
                }
                else if(target == "/")
                {
                    next = root;
                }
                else
                {
                    vector<filesystem_node*> options = cwd->get_contents();
                    for(int i=0;i<options.size();++i)
                    {
                        filesystem_node* curr = options[i];
                        if(curr->get_type() == DIRECTORY_T && curr->get_name() == target)
                        {
                            next = (directory*)curr;
                            break;
                        }
                    }
                    if(next == nullptr)
                    {
                        throw invalid_argument("Directory \""+target+"\" not found under \""+cwd->get_name()+"\"");
                    }
                }
                cwd = next;
            }
            else if(command == "ls")
            {
                reading_ls_output = true;
            }
            else
            {
                throw invalid_argument("Unexpected command found: \""+command+"\"");
            }
        }
        else if(reading_ls_output)
        {
            filesystem_node* node = parse_ls_line(line, cwd);
            cwd->add_content(node);
        }
        else
        {
            throw invalid_argument("Unexpected line of input found: \""+line+"\"");
        }
    }
    fin.close();
    return root;
}

bool isnum(char c)
{
    return '0' <= c && c <= '9';
}

filesystem_node* parse_ls_line(string s, directory* cwd)
{
    filesystem_node* ret;
    if(s[0] == 'd' && s[1] == 'i' && s[2] == 'r')
    {
        string name = s.substr(4, s.size()-4);
        ret = new directory(name, cwd);
    }
    else
    {
        int size = 0;
        int p = 0;
        while(!isnum(s[p]) && p < s.size())
        {
            ++p;
        }
        while(isnum(s[p]) && p < s.size())
        {
            size = size*10+(s[p]-'0');
            ++p;
        }
        ++p; // skip space character
        string name = s.substr(p, s.size()-p);
        ret = new file(name, cwd, size);
    }
    return ret;
}