#include <iostream>
#include <climits>

using namespace std;



// linkedlist using class
class Node
{
public:
    int data;
    Node *link;

    Node()
    {
        data = INT_MIN;
        link = nullptr;
    }

    Node(int value)
    {
        data = value;
        link = nullptr;
    }
    Node(int value, Node *next_node)
    {
        data = value;
        link = next_node;
    }
};

// class SinglyLinkedList
// {
// private:
//     Node *head;
//     Node *current;

// public:
//     SinglyLinkedList(int num_of_nodes)
//     {
//         head = (Node *)malloc(sizeof(Node));
//         Node nodes[num_of_nodes];
//     }

//     Node *createNode(int num_of_nodes)
//     {
//         for (size_t i = 0; i < num_of_nodes; i++)
//         {
//             cout << "Enter the data in " << i << "th node";
//             cin >> current->data;

//         }
//     }
// };

int main()
{
    Node *head = nullptr;

    // First node of linked list
    Node *node = new Node[3];
    head = node;

    node[0] = Node(45);
    node[1] = Node(55, &node[0], &node[1]);
    node[2] = Node(65, &node[1], &node[2]);

    cout << head << "|------>|"
         << node[0].data << " | " << node[0].link << " |------>| "
         << node[1].data << " | " << node[1].link << " |------>| "
         << node[2].data << " | " << node[2].link << " |" << endl;
    
    cout << head << "|------>|"
         << head->data << " | " << head->link << " |------>| "
         << head->link->data << " | " << head->link->link << " |------>| "
         << head->link->link->data << " | " << head->link->link->link << " |" << endl;

    delete[] node;
}