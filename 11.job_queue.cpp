//C++ program for simulating job queue using functions to add job and delete job from queue


#include<iostream>
using namespace std;

class Queue 
{
public:
    int queue[5]; 
    int front, rear;

    Queue() 
    {
        front = -1;
        rear = -1;
    }

    void enQueue() 
    {
        int value;
        if (rear == 4) 
        {  
            cout << "Queue is FULL!!! Insertion is not possible!!!" << endl;
        } 
        else 
        {
            cout << "Enter the value to be inserted: ";
            cin >> value;

            if (front == -1)  
                front = 0;

            rear++;
            queue[rear] = value;
            cout << "Inserted: " << value << endl;
        }
    }

    void deQueue() 
    {
        if (front == -1 || front > rear) 
        {
            cout << "Queue is EMPTY!!! Deletion is not possible!!!" << endl;
        }
        else 
        {
            int temp = queue[front];
            cout << "Deleted Element: " << temp << endl;
            front++;  
            
            if (front > rear) 
            {
                front = rear = -1;
            }
        }
    }

    void display() 
    {
        if (front == -1) 
        {
            cout << "Queue is EMPTY!!!" << endl;
        }
        else 
        {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++) 
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    Queue Q1;  
    int choice;

    do 
    {
        cout << "\n1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                Q1.enQueue();
                break;
                
            case 2:
                Q1.deQueue();
                break;
                
            case 3:
                Q1.display();
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
