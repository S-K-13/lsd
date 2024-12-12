//C++ program for storing binary numbers and finding 1’s and 2’s complements using doubly linked lists.

#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val) 
    {
        data = val;
        prev = next = NULL;
    }
};

class Binary 
{
private:
    Node *head;
    Node *last;

public:
    Binary() {
        head = last = NULL;
    }

    void CreateList(int num) {
        while (num != 0) {
            int rem = num % 2;
            Node *temp = new Node(rem);
            if (head == NULL) 
            {
                head = last = temp;
            } else {
                last->next = temp;
                temp->prev = last;
                last = temp;
            }
            num = num / 2;
        }
    }

    void DisplayList() 
    {
        Node *temp = last;
        while (temp != NULL) 
        {
            cout << temp->data;
            temp = temp->prev;
        }
        cout << endl;
    }

    void OnesComplement() 
    {
        Node *temp = head;
        while (temp != NULL) 
        {
            temp->data = 1 - temp->data;  
            temp = temp->next;
        }
    }

    void TwosComplement() 
    {
        OnesComplement();  
        Node *temp = last;
        int carry = 1;
        while (temp != NULL && carry != 0) {
            temp->data = temp->data + carry;
            if (temp->data == 2) 
            {
                temp->data = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            temp = temp->prev;
        }
        if (carry == 1) {
            Node *new_node = new Node(1);
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    Binary operator+(Binary& other) 
    {
        Binary result;
        Node *t1 = this->last;
        Node *t2 = other.last;
        int carry = 0;

        while (t1 != NULL || t2 != NULL || carry != 0) {
            int sum = carry;
            if (t1 != NULL) 
            {
                sum += t1->data;
                t1 = t1->prev;
            }
            if (t2 != NULL) 
            {
                sum += t2->data;
                t2 = t2->prev;
            }
            carry = sum / 2;
            Node *new_node = new Node(sum % 2);
            if (result.head == NULL) 
            {
                result.head = result.last = new_node;
            } else {
                result.head->prev = new_node;
                new_node->next = result.head;
                result.head = new_node;
            }
        }
        return result;
    }
};

int main() 
{
    int num1, num2, choice;
    Binary b1, b2, sum;

    while (true) 
    {
        cout << "\nDoubly Linked List Binary Operations:\n";
        cout << "1. Enter first decimal number and convert to binary\n";
        cout << "2. Enter second decimal number and convert to binary\n";
        cout << "3. Display first binary number\n";
        cout << "4. Display second binary number\n";
        cout << "5. Compute 1's complement of first binary number\n";
        cout << "6. Compute 2's complement of first binary number\n";
        cout << "7. Add two binary numbers\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter first decimal number: ";
            cin >> num1;
            b1.CreateList(num1);
            break;

        case 2:
            cout << "Enter second decimal number: ";
            cin >> num2;
            b2.CreateList(num2);
            break;

        case 3:
            cout << "First binary number: ";
            b1.DisplayList();
            break;

        case 4:
            cout << "Second binary number: ";
            b2.DisplayList();
            break;

        case 5:
            cout << "1's complement of first binary number: ";
            b1.OnesComplement();
            b1.DisplayList();
            break;

        case 6:
            cout << "2's complement of first binary number: ";
            b1.TwosComplement();
            b1.DisplayList();
            break;

        case 7:
            sum = b1 + b2;
            cout << "Sum of two binary numbers: ";
            sum.DisplayList();
            break;

        case 8:
            exit(0);

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
