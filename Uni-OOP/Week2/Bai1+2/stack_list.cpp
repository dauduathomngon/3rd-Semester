#include "stack_list.h"

void StackList::Push(const std::string& val)
{
    m_List.insert(m_List.size() - 1, val);
}

void StackList::Pop()
{
    m_List.erase(m_List.size() - 1);
}

std::string StackList::Top() const
{
    return m_List.get(0);
}

int StackList::Size() const
{
    return m_List.size();
}
