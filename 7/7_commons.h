#ifndef COMMONS7_H
#define COMMONS7_H

#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>

#define mp make_pair
using namespace std;

enum filesystem_node_type {DIRECTORY_T, FILE_T};

class filesystem_node
{
private:
    filesystem_node_type type;
    string name;
protected:
    filesystem_node(string name, filesystem_node_type t);
public:
    filesystem_node_type get_type();
    string get_name();
};

class directory : public filesystem_node
{
private:
    vector<filesystem_node*> contents;
    directory* parent;
public:
    directory(string name, directory* parent);
    void add_content(filesystem_node* n);
    vector<filesystem_node*> get_contents();
    int get_size();
    directory* get_parent();
};

class file : public filesystem_node
{
private:
    int size;
    directory* parent;
public:
    file(string name, directory* parent, int size);
    int get_size();
    directory* get_parent();
};

bool isnum(char c);

filesystem_node* parse_ls_line(string s, directory* cwd);

directory* read_input();

#endif // COMMONS7H