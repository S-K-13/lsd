//C++ program to simulate deque with functions to add and delete elements from either end of the deque.

#include <iostream>
using namespace std;
const int SIZE = 6;
class Deque 
{
private:
    int dequeArray[SIZE];
    int front;
    int rear;
public:
    Deque() 
    {
    front = -1;
    rear = -1;
    }
    
    bool isEmpty();
    bool isFull();
    void insertFront(int);
    void insertRear(int);
    void deleteFront();
    void deleteRear();
    void printDeque();
};

bool Deque::isEmpty() 
{
    return (front == -1 && rear == -1);
}


bool Deque::isFull() 
{
    return ((front == 0 && rear == SIZE - 1) || front == rear + 1);
}

void Deque::insertFront(int element) 
{
    if (isFull()) 
    {
    cout << ";Deque is full. Cannot insert at the front.\n";
    return;
    }
    if (isEmpty())
    front = rear = 0;
    else if(front==0)
    front = SIZE-1;
    else
    --front;
    dequeArray[front] = element;
    cout << "Element inserted at the front.\n";
}

void Deque::insertRear(int element) 
{
    if (isFull()) 
    {
    cout << "Deque is full. Cannot insert at the rea.\n";
    return;
    }
    if (isEmpty())
    front = rear = 0;
    else if(rear==SIZE-1)
    rear=0;
    else
    ++rear;
    dequeArray[rear] = element;
    cout << "Element inserted at the rear.\n";
}

void Deque::deleteFront()   
{
    if (isEmpty()) 
    {
    cout << "Deque is empty. Cannot delete from the front.\n";
    return;
    }
    if (front == rear)
    front = rear = -1;
    else if(front==SIZE-1)
    front=0;
    else
    ++front;
    cout <<"Element deleted from the front.\n";
}

void Deque::deleteRear() 
{
    if (isEmpty()) 
    {
    cout << "Deque is empty. Cannot delete from the rear.\n";
    return;
    }
    if (front == rear)
    front = rear = -1;
    else if(rear==0)
    rear=SIZE-1;
    else
    rear--;
    cout << "Element deleted from the rear.\n";
}

void Deque::printDeque() 
{
    if (isEmpty()) 
    {
    cout << "Deque is empty.\n";
    return;
    }
    int index = front;
    cout << "Elements in the deque: ";
    while (index != rear) 
    {
    cout << dequeArray[index] << "; ";
    index = (index + 1) % SIZE;
    }
    cout << dequeArray[rear] << endl;
}

int main()
{
Deque dq;
int choice,element;
do 
{
    cout << "Double-Ended Queue (Deque) Menu:\n";
    cout << "1. Insert at the front\n";
    cout << "2. Insert at the rear\n";
    cout << "3. Delete from the front\n";
    cout << "4. Delete from the rear\n";
    cout << "5. Print the deque\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) 
    {
    case 1:
    cout << "Enter the element to insert at the front: ";
    cin >> element;
    dq.insertFront(element);
    break;
    
    case 2:
    cout << "Enter the element to insert at the rear: ";
    cin >> element;
    dq.insertRear(element);
    break;
    
    case 3:
    dq.deleteFront();
    break;
    
    case 4:
    dq.deleteRear();
    break;
    
    case 5:
    dq.printDeque();
    break;
    
    case 6:
    cout << "Exiting the program.\n";
    break;
    
    default:

    cout << "Invalid choice. Please try again.\n";
    break;
    
    }
    cout << endl;
    } 
    while (choice != 6);
    return 0;
} 

