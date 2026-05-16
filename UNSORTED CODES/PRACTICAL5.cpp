//Q1

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Class for Circular Linked List
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a node at the end
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Link new node to head
        }
    }

    // Function to delete a node with a given value
    void deleteNode(int value) {
        if (head == nullptr) return;

        Node *temp = head, *prev = nullptr;

        // If head needs to be deleted
        if (head->data == value) {
            // If there's only one node
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }
            // Find the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            // Change head to the next node
            Node* toDelete = head;
            head = head->next;
            temp->next = head; // Last node points to new head
            delete toDelete;
            return;
        }

        // Traverse the list to find the node to delete
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);

        // If the node was not found
        if (temp == head) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        // Unlink the node and delete it
        prev->next = temp->next;
        delete temp;
    }

    // Function to traverse the list
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Destructor to clean up memory
    ~CircularLinkedList() {
        if (head == nullptr) return;
        Node* current = head;
        Node* nextNode;

        // Ensure all nodes are deleted
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);

    cout << "Circular Linked List after insertion: ";
    cll.traverse();

    cll.deleteNode(20);
    cout << "Circular Linked List after deletion of 20: ";
    cll.traverse();

    cll.deleteNode(10);
    cout << "Circular Linked List after deletion of 10: ";
    cll.traverse();

    cll.deleteNode(50); // Attempt to delete a non-existent node

    return 0;
}












//q2
#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Class for Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Function to insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to insert a node at a specific position (0-based index)
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds. Inserting at the end." << endl;
            insertAtEnd(value);
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    cout << "List after inserting at end: ";
    dll.display();

    dll.insertAtBeginning(5);
    cout << "List after inserting at beginning: ";
    dll.display();

    dll.insertAtPosition(15, 2);
    cout << "List after inserting 15 at position 2: ";
    dll.display();

    dll.insertAtPosition(25, 5); // Inserting at an out-of-bounds position
    cout << "List after attempting to insert 25 at position 5: ";
    dll.display();

    return 0;
}
