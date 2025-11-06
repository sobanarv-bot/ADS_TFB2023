#include <iostream>
using namespace std;

// Node class to represent each element in the queue
class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front;   // front of queue (dequeue from here)
    Node* rear;    // rear of queue (enqueue here)
    int size;
    int maxSize;

public:
    // Constructor
    Queue(int limit = 5) {
        front = nullptr;
        rear = nullptr;
        size = 0;
        maxSize = limit;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Check if queue is full
    bool isFull() {
        return size >= maxSize;
    }

    // Enqueue (insert at rear)
    void enqueue(string value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue '" << value << "' — queue is full.\n";
            return;
        }

        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        size++;
        cout << value << " enqueued to queue.\n";
    }

    // Dequeue (remove from front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Nothing to dequeue.\n";
            return;
        }

        cout << front->data << " dequeued from queue.\n";
        Node* temp = front;
        front = front->next;

        if (front == nullptr) // if queue becomes empty
            rear = nullptr;

        delete temp;
        size--;
    }

    // Peek at the front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Display all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* current = front;
        cout << "\nQueue elements (front to rear):\n";
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    // Destructor — cleans up memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Main function to test the queue
int main() {
    Queue queue(3);  // queue can only hold 3 elements

    queue.enqueue("test1");
    queue.enqueue("test2");
    queue.enqueue("test3");
    queue.enqueue("extra"); // this will show "queue full"

    queue.display();

    queue.peek();   // shows front element
    queue.dequeue(); // removes front
    queue.peek();   // shows new front
    queue.dequeue();
    queue.dequeue();
    queue.dequeue(); // tries to dequeue empty queue

    if (queue.isEmpty())
        cout << "\nQueue is now empty.\n";

    return 0;
}
