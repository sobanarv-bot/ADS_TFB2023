#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;
    int size;         // to keep track of how many elements are in the stack
    int maxSize;      // optional limit (you can set it in constructor)

public:
    // Constructor
    Stack(int limit =5) {  // default max size = 5
        top = nullptr;
        size = 0;
        maxSize = limit;
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to check if stack is full (based on maxSize)
    bool isFull() {
        return size >= maxSize;
    }

    // Push an element to the top of stack
    void push(string value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push '" << value << "' — stack is full.\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;

        cout << value << " pushed to stack.\n";
    }

    // Pop an element from the top
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Nothing to pop.\n";
            return;
        }

        cout << top->data << " popped from stack.\n";
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // Peek at the top element without removing it
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
        } else {
            cout << "Top element: " << top->data << endl;
        }
    }

    // Display all elements in stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        Node* current = top;
        cout << "\nStack elements (top to bottom):\n";
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Destructor — cleans memory when stack is destroyed
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Main function to test the stack
int main() {
    Stack stack(3);  // stack can only hold 3 elements

    stack.push("test1");
    stack.push("test2");
    stack.push("test3");
    stack.push("extra"); // this will show "stack full"

    stack.display();

    stack.peek();   // shows top element
    stack.pop();    // removes top
    stack.peek();   // shows new top
    stack.pop();
    stack.pop();
    stack.pop();    // tries to pop empty stack

    if (stack.isEmpty())
        cout << "\nStack is now empty.\n";

    return 0;
}
