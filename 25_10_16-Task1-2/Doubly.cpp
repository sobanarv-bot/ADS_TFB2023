#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

int main() {
    // Create three nodes
    Node node1 = Node();
    Node node2 = Node();
    Node node3 = Node();

    // Assign data
    node1.data = "test1";
    node2.data = "test2";
    node3.data = "test3";

    // Link them forward
    node1.next = &node2;
    node2.next = &node3;
    node3.next = nullptr;

    // Link them backward
    node1.prev = nullptr;
    node2.prev = &node1;
    node3.prev = &node2;

    // Print data directly
    cout << node1.data << endl;
    cout << node2.data << endl;
    cout << node3.data << endl;

    // Traverse forward
    cout << "\nForward Traversal:\n";
    Node* current = &node1;
    while (current != nullptr) {
        cout << current->data << "  \n";
        current = current->next;
    }

    // Traverse backward
    cout << "\nBackward Traversal:\n";
    current = &node3;
    while (current != nullptr) {
        cout << current->data << "  \n";
        current = current->prev;
    }

    cout << endl;
}
