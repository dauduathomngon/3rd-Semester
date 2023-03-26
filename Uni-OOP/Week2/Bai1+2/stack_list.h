#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "list.h"

class StackList
{
public:
    List m_List;
private:
    void Push(const std::string& val);
    void Pop();
    std::string Top() const;
    int Size() const;
};

#endif // STACK_LIST_H