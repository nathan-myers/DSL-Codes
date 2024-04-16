// My code
// implement using arrays

#include<bits/stdc++.h>
using namespace std;

class Queue 
{
    int capacity;
    int front;
    int rear;
    int size;

    
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue();
    void dequeue();

};


int main()
{
    int n, ch;
    cout << "Enter no of patients: ";
    cin >> n;

    cout << "1. Insert patient\n";
    cout << "2. Dequeue patient\n";
    cout << "3. Display data\n";
    cout << "4. Exit\n";
    cout << "\nEnter the operation: ";

    cin >> ch;


    switch(ch)
    {
        case 1:

        
    }

    return 0;
}






//////////////// CHAT GPT CODE  ////////////////////////
/*
#include <iostream>
#include <string>
using namespace std;

// Class to represent a Patient
class Patient {
public:
    string name;
    int condition; // 1 for serious, 2 for non-serious, 3 for general checkup

    // Constructor
    Patient(string name, int condition) {
        this->name = name;
        this->condition = condition;
    }
};

// Class to represent a Queue
class Queue {
private:
    Patient* arr; // Array to store queue elements
    int capacity; // Maximum capacity of the queue
    int front; // Index of the front element
    int rear; // Index of the rear element
    int size; // Current size of the queue

public:
    // Constructor
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new Patient[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to enqueue an element into the queue
    void enqueue(Patient patient) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = patient;
        size++;
    }

    // Function to dequeue an element from the queue
    Patient dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return Patient("", 0); // Return a default patient
        }
        Patient patient = arr[front];
        front = (front + 1) % capacity;
        size--;
        return patient;
    }
};

// Function to transfer data from inputQueue to priorityQueue based on priority
void transferData(Queue& inputQueue, Queue& priorityQueue) {
    while (!inputQueue.isEmpty()) {
        Patient patient = inputQueue.dequeue();
        priorityQueue.enqueue(patient);
    }
}

int main() {
    // Prompt the user to enter the number of patients
    int numPatients;
    cout << "Enter the number of patients: ";
    cin >> numPatients;

    // Create input queue and priority queue
    Queue inputQueue(100);
    Queue priorityQueue(100);

    // Input patients
    cout << "Enter patient data:\n";
    for (int i = 0; i < numPatients; ++i) {
        string name;
        int condition;
        cout << "Enter name of patient " << i + 1 << ": ";
        cin >> name;
        cout << "Enter condition (1 for serious, 2 for non-serious, 3 for general checkup): ";
        cin >> condition;
        inputQueue.enqueue(Patient(name, condition));
    }

    // Transfer data to priority queue
    transferData(inputQueue, priorityQueue);

    // Menu-driven program
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert data\n";
        cout << "2. Delete data\n";
        cout << "3. Display data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert:\n";
                string name;
                int condition;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter condition (1 for serious, 2 for non-serious, 3 for general checkup): ";
                cin >> condition;
                inputQueue.enqueue(Patient(name, condition));
                break;
            case 2:
                if (!priorityQueue.isEmpty()) {
                    Patient patient = priorityQueue.dequeue();
                    cout << "Deleted data: " << patient.name << " (Condition: " << patient.condition << ")\n";
                } else {
                    cout << "Priority queue is empty. Cannot delete.\n";
                }
                break;
            case 3:
                cout << "Priority queue data:\n";
                while (!priorityQueue.isEmpty()) {
                    Patient patient = priorityQueue.dequeue();
                    cout << "Name: " << patient.name << ", Condition: " << patient.condition << endl;
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

*/
