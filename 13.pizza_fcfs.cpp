//C++ Program to Simulate Pizza parlor system using Circular Queue Using Array

#include <iostream>
using namespace std;

#define SIZE 5  

class CircularQueue 
{
private:
    int queue[SIZE];
    int front, rear;  
public:
    CircularQueue() 
    {
        front = -1;
        rear = -1;
    }

    bool isFull() 
    {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() 
    {
        return front == -1;
    }

    void enQueue(int order) 
    {
        if (isFull()) 
        {
            cout << "Queue is FULL! Cannot add more orders." << endl;
        } 
        else 
        {
            if (front == -1)  
                front = 0;

            rear = (rear + 1) % SIZE;  
            queue[rear] = order;  
            cout << "Order " << order << " added to the queue." << endl;
        }
    }

    void deQueue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is EMPTY! No orders to serve." << endl;
        } 
        else 
        {
            cout << "Order " << queue[front] << " served." << endl;

            if (front == rear) 
            {  
                front = rear = -1;
            }
            else 
            {
                front = (front + 1) % SIZE;  
            }
        }
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is EMPTY! No orders to display." << endl;
        }
        else 
        {
            cout << "Current Orders in Queue: ";
            int i = front;
            while (i != rear) 
            {
                cout << queue[i] << " ";  
                i = (i + 1) % SIZE;
            }
            cout << queue[rear] << endl;  
        }
    }
};

int main() 
{
    CircularQueue cq;
    int choice, order;

    do 
    {
        cout << "\n1. Add Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter order number to add: ";
                cin >> order;
                cq.enQueue(order);  
                break;
                
            case 2:
                cq.deQueue();  
                break;
                
            case 3:
                cq.display();  
                break;
                
            case 4:
                cout << "Exiting program." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    while (choice != 4);

    return 0;
}
