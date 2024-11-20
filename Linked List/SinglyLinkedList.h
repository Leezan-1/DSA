
using namespace std;

namespace NumericLinkedList
{
    class Singly
    {
    private:
        // Node structure representing a single element in the linked list.
        struct Node
        {
            int data;
            struct Node *next_addr;

            Node(int value) : data(value), next_addr(nullptr) {}
        };

        Node *head, *tail;

        Node *createNode()
        {
            int data;
            cout << "Enter the data for node: ";
            cin >> data;
            Node *new_node = new Node(data);
            return new_node;

            /*
                The fuction creates a new node with dynamic memory allocation.
                It returns the address of the new_node.
            */
        }

        Node *createNode(int data)
        {
            Node *new_node = new Node(data);
            return new_node;
        }

        // Checks if a given position is valid within the list bounds.
        bool checkInvalidPosition(int position)
        {
            return (position > countNodes() || position <= 0) ? true : false;
            /*
                if position is greater than number of nodes or 0 or less than 0, position is invalid.
            */
        }

    public:
        // Constructor initializes the list with a single node entered by the user.
        Singly() : head(nullptr), tail(nullptr) {}

        bool checkEmpty()
        {
            return (head == nullptr || tail == nullptr) ? true : false;
        }

        // Counts the number of nodes in the linked list.
        int countNodes()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return 0;
            }
            int count = 0;
            Node *temp = head;
            while (temp != nullptr)
            {
                count++;
                temp = temp->next_addr;
            }
            return count;
        }

        // Displays all nodes in the linked list.
        void displayNodes()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return;
            }

            Node *temp = head;

            cout << "\n-----------------------" << endl
                 << "Number of Node(s): " << countNodes() << endl;

            while (temp != nullptr)
            {
                cout << "| " << temp->data << " | ";
                temp = temp->next_addr;
            }
            cout << "\n-----------------------\n"
                 << endl;
        }

        // Inserts a new node at the front of the list asking user input
        bool insertNodeAtFront()
        {

            Node *temp = createNode();
            if (head == nullptr)
                tail = temp;
            else
                temp->next_addr = head;
            head = temp;

            return true;
        }

        // Insets node at front by given data
        bool insertNodeAtFront(int data)
        {

            Node *temp = createNode(data);
            if (head == nullptr)
                tail = temp;
            else
                temp->next_addr = head;
            head = temp;

            return true;
        }

        // Deletes the node at the front of the list.
        bool deleteNodeAtFront()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }

            Node *temp = head;
            head = head->next_addr;
            delete temp;
            temp = nullptr;

            // If the list became empty, update the tail to nullptr as well.
            if (head == nullptr)
                tail = nullptr;

            return true;
        }

        // Inserts a new node at the end of the list.
        bool insertNodeAtEnd()
        {
            Node *temp = createNode();
            if (tail == nullptr)
                head = temp;
            else
                tail->next_addr = temp;

            tail = temp;

            return true;
        }

        // Inserts a new node at the end of the list but with data as arg
        bool insertNodeAtEnd(int data)
        {
            Node *temp = createNode(data);
            if (tail == nullptr)
                head = temp;
            else
                tail->next_addr = temp;

            tail = temp;

            return true;
        }

        // Deletes the node at the end of the list.
        bool deleteNodeAtEnd()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }

            // If there's only one node, reset the head and tail.
            if (tail == head)
            {
                delete tail;
                tail = nullptr;
                head = nullptr;
            }
            else
            {
                Node *temp = head;
                // Traverse to the second-last node.
                while (temp->next_addr != tail)
                    temp = temp->next_addr;

                // Update the second-last node to become the new tail.
                temp->next_addr = nullptr;
                delete tail;
                tail = temp;
            }
            return true;
        }

        // Inserts a new node at a specified position.
        bool insertNodeAtPosition(int position)
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }
            else if (checkInvalidPosition(position))
            {
                cout << "Invalid Position!" << endl;
                return false;
            }

            // If inserting at the front, use insertNodeAtFront.
            if (position == 1)
                insertNodeAtFront();
            else
            {
                Node *new_node = createNode();
                Node *temp = head;

                // Traverse to the node before the insertion position.
                for (size_t i = 1; i < position - 1; i++)
                    temp = temp->next_addr;

                // Insert the new node at the specified position.
                new_node->next_addr = temp->next_addr;
                temp->next_addr = new_node;
            }
            return true;
        }

        // Deletes a node at a specified position.
        bool deleteNodeAtPosition(int position)
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }
            else if (checkInvalidPosition(position))
            {
                cout << "Invalid Position" << endl;
                return false;
            }

            // If deleting the first node, use deleteNodeAtFront.
            if (position == 1)
                deleteNodeAtFront();

            else
            {
                Node *temp = nullptr, *node_bef_pos = head;

                // Traverse to the node before the target position.
                for (size_t i = 1; i < position - 1; i++)
                {
                    node_bef_pos = node_bef_pos->next_addr;
                }
                temp = node_bef_pos->next_addr;
                // Remove the node at the specified position.
                node_bef_pos->next_addr = temp->next_addr;
                delete temp;
                temp = nullptr;

                // Update the tail if the last node was deleted.
                if (node_bef_pos->next_addr == nullptr)
                    tail = node_bef_pos;
            }
            return true;
        }

        // creates entire list
        bool createEntireList()
        {
            if (!checkEmpty())
            {
                cout << "\nEntire list can only be created when it is empty!" << endl;
                return false;
            }

            int no_of_nodes;
            cout << "\nEntire new linkedlist will be created!\nEnter the number of nodes in linked list: ";
            cin >> no_of_nodes;

            if (no_of_nodes > 0)
            {
                for (size_t i = 1; i <= no_of_nodes; i++)
                {
                    cout << "\nFor Node " << i << ": \n";
                    insertNodeAtEnd();
                }
                cout << "Linked List Created\n";
            }
            else
                cout << "Invalid number! No list created!\n";
            return true;
        }

        // delete entire list
        bool deleteEntireList()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }

            while (head != nullptr)
                deleteNodeAtFront();

            return true;
        }

        // Reverses entire list
        bool reverseList()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }

            Node *front_node = head, *prev_node = nullptr, *next_node = nullptr;

            while (front_node != nullptr)
            {
                next_node = front_node->next_addr;
                front_node->next_addr = prev_node;
                prev_node = front_node;
                front_node = next_node;
            }
            front_node = prev_node;
            head = front_node;
            return true;
        }

        int accessAtPosition(int position)
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return -1;
            }
            else if (checkInvalidPosition(position))
            {
                cout << "Invalid Position!" << endl;
                return -1;
            }

            Node *node_at_pos = head;
            for (size_t i = 1; i < position; i++)
                node_at_pos = node_at_pos->next_addr;

            int data_at_position = node_at_pos->data;
            return data_at_position;
        }

        ~Singly()
        {
            deleteEntireList();
        }
    };
}

namespace StringLinkedList
{
    class Singly
    {
    private:
        struct Node
        {
            Node *next_addr;
            char data;
            Node(char value) : data(value), next_addr(nullptr) {}
        };

        Node *head, *tail;

        Node *createNode()
        {
            char data;
            cout << "Enter the data for node: ";
            cin >> data;
            Node *new_node = new Node(data);
            return new_node;

            /*
                The fuction creates a new node with dynamic memory allocation.
                It returns the address of the new_node.
            */
        }

        Node *createNode(char data)
        {
            Node *new_node = new Node(data);
            return new_node;
        }

        bool checkInvalidPosition(int position)
        {
            return (position > countNodes() || position <= 0) ? true : false;
            /*
                if position is greater than number of nodes or 0 or less than 0, position is invalid.
            */
        }

    public:
        // Constructor initializes the list with a single node entered by the user.
        Singly() : head(nullptr), tail(nullptr) {}

        // Checks if linkedlist is empty
        bool checkEmpty()
        {
            return (head == nullptr) ? true : false;
        }

        // Counts the number of nodes in the linked list.
        int countNodes()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return 0;
            }
            int count = 0;
            Node *temp = head;
            while (temp != nullptr)
            {
                count++;
                temp = temp->next_addr;
            }
            return count;
        }

        // Displays all nodes in the linked list.
        void displayNodes()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return;
            }

            Node *temp = head;

            cout << "\n-----------------------" << endl
                 << "Number of Node(s): " << countNodes() << endl;

            while (temp != nullptr)
            {
                cout << "| " << temp->data << " | ";
                temp = temp->next_addr;
            }
            cout << "\n-----------------------\n"
                 << endl;
        }

        // accesses data in the given position;
        char accessAtPosition(int position)
        {
            if (checkEmpty())
                return '\0';
            else if (checkInvalidPosition(position))
                return '\0';

            Node *node_at_pos = head;
            for (size_t i = 1; i < position; i++)
                node_at_pos = node_at_pos->next_addr;

            char data_at_position = node_at_pos->data;
            return data_at_position;
        }

        // Insets node at front by given data
        bool insertNodeAtFront(char data)
        {

            Node *temp = createNode(data);
            if (head == nullptr)
                tail = temp;
            else
                temp->next_addr = head;
            head = temp;

            return true;
        }

        // Deletes the node at the end of the list.
        bool deleteNodeAtFront()
        {
            if (checkEmpty())
                return false;

            Node *temp = head;
            head = head->next_addr;
            delete temp;
            temp = nullptr;

            // If the list became empty, update the tail to nullptr as well.
            if (head == nullptr)
                tail = nullptr;

            return true;
        }

        // Inserts a new node at the end of the list.
        bool insertNodeAtEnd(char data)
        {
            Node *temp = createNode(data);
            if (tail == nullptr)
                head = temp;
            else
                tail->next_addr = temp;

            tail = temp;

            return true;
        }

        bool insertNodeAtEnd()
        {
            Node *temp = createNode();
            if (tail == nullptr)
                head = temp;
            else
                tail->next_addr = temp;

            tail = temp;

            return true;
        }

        // Deletes the node at the end of the list.
        bool deleteNodeAtEnd()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }

            // If there's only one node, reset the head and tail.
            if (tail == head)
            {
                delete tail;
                tail = nullptr;
                head = nullptr;
            }
            else
            {
                Node *temp = head;
                // Traverse to the second-last node.
                while (temp->next_addr != tail)
                    temp = temp->next_addr;

                // Update the second-last node to become the new tail.
                temp->next_addr = nullptr;
                delete tail;
                tail = temp;
            }
            return true;
        }

        // Inserts a new node at a specified position.
        bool insertNodeAtPosition(int position, char data)
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }
            else if (checkInvalidPosition(position))
            {
                cout << "Invalid Position!" << endl;
                return false;
            }

            // If inserting at the front, use insertNodeAtFront.
            if (position == 1)
                insertNodeAtFront(data);
            else
            {
                Node *new_node = createNode(data);
                Node *temp = head;

                // Traverse to the node before the insertion position.
                for (size_t i = 1; i < position - 1; i++)
                    temp = temp->next_addr;

                // Insert the new node at the specified position.
                new_node->next_addr = temp->next_addr;
                temp->next_addr = new_node;
            }
            return true;
        }

        // Deletes a node at a specified position.
        bool deleteNodeAtPosition(int position)
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }
            else if (checkInvalidPosition(position))
            {
                cout << "Invalid Position" << endl;
                return false;
            }

            // If deleting the first node, use deleteNodeAtFront.
            if (position == 1)
                deleteNodeAtFront();

            else
            {
                Node *temp = nullptr, *node_bef_pos = head;

                // Traverse to the node before the target position.
                for (size_t i = 1; i < position - 1; i++)
                {
                    node_bef_pos = node_bef_pos->next_addr;
                }
                temp = node_bef_pos->next_addr;
                // Remove the node at the specified position.
                node_bef_pos->next_addr = temp->next_addr;
                delete temp;
                temp = nullptr;

                // Update the tail if the last node was deleted.
                if (node_bef_pos->next_addr == nullptr)
                    tail = node_bef_pos;
            }
            return true;
        }

        // Reverses entire list
        bool reverseList()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }

            Node *front_node = head, *prev_node = nullptr, *next_node = nullptr;

            while (front_node != nullptr)
            {
                next_node = front_node->next_addr;
                front_node->next_addr = prev_node;
                prev_node = front_node;
                front_node = next_node;
            }
            front_node = prev_node;
            head = front_node;
            return true;
        }

        bool createEntireList()
        {
            if (!checkEmpty())
            {
                cout << "\nEntire list can only be created when it is empty!" << endl;
                return false;
            }

            int no_of_nodes;
            cout << "\nEntire new linkedlist will be created!\nEnter the number of nodes in linked list: ";
            cin >> no_of_nodes;

            if (no_of_nodes > 0)
            {
                for (size_t i = 1; i <= no_of_nodes; i++)
                {
                    cout << "\nFor Node " << i << ": \n";
                    insertNodeAtEnd();
                }
                cout << "Linked List Created\n";
            }
            else
                cout << "Invalid number! No list created!\n";
            return true;
        }

        // delete entire list
        bool deleteEntireList()
        {
            if (checkEmpty())
            {
                cout << "Linked List Empty!" << endl;
                return false;
            }

            while (head != nullptr)
                deleteNodeAtFront();

            return true;
        }
    };
}