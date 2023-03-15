#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class MyList
{
public:
    MyList()
    : m_Size(0)
    , m_Head(nullptr)
    {
    }

    ~MyList()
    {
        Delete();
    }

    void MakeHead(int data)
    {
        m_Head = MakeNode(data);
    }

    void AddNode(int data)
    {
        Node* newNode = MakeNode(data);
        Node* current = m_Head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    /* use for debugging */
    void Print()
    {
        Node* current = m_Head;
        while (current != nullptr)
        {
            PrintNode(current);
            current = current->next;
        }
    }

private:
    Node* m_Head;
    int m_Size;

    Node* MakeNode(int data)
    {
        return new Node {data, nullptr};
    }

    /* use for debugging */
    void PrintNode(Node* current)
    {
        std::cout << "Node: " << current << "\n";
        std::cout << "Node data: " << current->data << "\n";
        std::cout << "Node point to: " << current->next << "\n";
    }

    void Delete()
    {
        Node* temp = m_Head->next;
        while (temp != nullptr)
        {
            m_Head->next = temp->next;
            temp->next = nullptr;
            std::cout << "Delete Node: " << temp << "\n";
            delete temp;
            temp = m_Head->next;
        }
        std::cout << "Delete Node: " << m_Head << "\n";
        delete m_Head;
    }
};

int main()
{
    MyList ll;
    ll.MakeHead(400);
    ll.AddNode(300);
    ll.AddNode(400);
    ll.AddNode(500);
    ll.Print();
    return 0;
}