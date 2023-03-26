#include "list.h"

List::List()
: m_Count(0)
, m_Head(nullptr)
{
}

List::~List()
{
    Node* temp = m_Head->next;
    while (temp != nullptr)
    {
        m_Head->next = temp->next;
        temp->next = nullptr;
        delete temp;
        temp = m_Head->next;
    }
    delete m_Head;
}

Node* List::makeNode(const std::string& val)
{
    return new Node {val, nullptr};
}

void List::insert(int pos, const std::string& val)
{
    // check empty head
    std::string headVal;
    if (m_Head == nullptr)
    {
        std::cout << "Hay tao gia tri cho head: ";
        getline(std::cin, headVal);
        m_Head = makeNode(headVal);
    }

    // make new node
    Node* newNode = makeNode(val);

    // at head
    if (pos == 0)
    {
        newNode->next = m_Head;
        m_Head = newNode;
        ++m_Count;
        return;
    }

    // find pos
    int count = 0;
    Node* current = m_Head;

    while (count != (pos-1))
    {
        current = current->next;
        ++count;
    }

    // last position
    if (count == (m_Count - 1))
    {
        current->next = newNode;
        // increase size
        ++m_Count;
    }
    else // elsewhere
    {
        newNode->next = current->next;
        current->next = newNode;
        ++m_Count;
    }
}

void List::erase(int pos)
{
    // check empty head
    std::string headVal;
    if (m_Head == nullptr)
    {
        std::cout << "ko co gia tri cho Node head \n";
        return;
    }

    // find pos
    int count = 0;
    Node* current = m_Head;
    
    while (count != (pos-1))
    {
        current = current->next;
        ++count;
    }

    // last position
    if (count == (m_Count - 1))
    {
        delete current->next;
        current->next = nullptr;
        --m_Count;
    }
    else if (count == 0) // at head
    {
        Node* headTmp = m_Head;
        m_Head = m_Head->next;
        delete headTmp;
        --m_Count;
    }
    else // elsewhere
    {
        Node* next = current->next->next;
        delete current->next;
        current->next = next;
        --m_Count;
    }
}

std::string List::get(int pos) const
{
    int count = 0;
    Node* current = m_Head;
    
    while (count != pos)
    {
        current = current->next;
        count++;
    }

    return current->data;
}

void List::print() const
{
    Node* current = m_Head;
    while (current != nullptr)
    {
        std::cout << "Node: " << current << "\n";
        std::cout << "Node data: " << current->data << "\n";
        std::cout << "Node point to: " << current->data << "\n";
    }
}

int List::size() const
{
    return m_Count;
}