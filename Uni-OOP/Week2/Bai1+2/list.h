#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>
#include <string>

struct Node
{
    std::string data;
    Node* next;
};

class List
{
public:
    List();
    ~List();
    void insert(int pos, const std::string& val);
    void erase(int pos);
    std::string get(int pos) const;
    void print() const;
    int size() const;

private:
    Node* m_Head;
    int m_Count;
    Node* makeNode(const std::string& val);
};

#endif // LIST_H