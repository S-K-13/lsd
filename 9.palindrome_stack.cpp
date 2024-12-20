//C++ program that implements a stack using an array to check if a given string is a palindrome

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100  

class Stack 
{
private:
    char data[MAX]; 
    int top;  

public:
    Stack() 
    {
        top = -1;
    }

    void push(char ch) 
    {
        if (top < MAX - 1) 
        {
            data[++top] = ch;
        } else {
            cout << "Stack overflow, cannot push more elements.\n";
        }
    }

    char pop() 
    {
        if (top >= 0) {
            return data[top--];
        } else {
            cout << "Stack underflow, cannot pop elements.\n";
            return '\0';  
        }
    }

    bool isEmpty() 
    {
        return top == -1;
    }

    void reverseString(const char str[]) 
    {
        for (int i = 0; str[i] != '\0'; i++) {
            push(str[i]);
        }
        cout << "Reversed String: ";
        while (!isEmpty()) {
            cout << pop();
        }
        cout << endl;
    }

    bool isPalindrome(const char str[]) 
    {
        int len = strlen(str);

        for (int i = 0; i < len / 2; i++) {
            push(str[i]);
        }

        int mid = (len % 2 == 0) ? len / 2 : len / 2 + 1;  
        for (int i = mid; i < len; i++) {
            if (str[i] != pop()) {
                return false;
            }
        }

        return true;
    }

    void preprocessString(const char input[], char output[]) 
    {
        int j = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                output[j++] = input[i] + 32;
            }
            else if (input[i] >= 'a' && input[i] <= 'z') {
                output[j++] = input[i];
            }
        }
        output[j] = '\0';  
    }
};

int main() 
{
    Stack stack;
    char str[MAX], processedStr[MAX];
    int choice;

    cout << "Enter a string: ";
    cin.getline(str, MAX);

    while (true) 
    {
        cout << "\nSTACK OPERATIONS\n";
        cout << "1. Check if string is palindrome using stack\n";
        cout << "2. Convert string to lowercase, remove spaces, and check for palindrome\n";
        cout << "3. Print string in reverse order using stack\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) 
        {
            case 1:
                if (stack.isPalindrome(str)) {
                    cout << "The string is a palindrome.\n";
                } else {
                    cout << "The string is not a palindrome.\n";
                }
                break;

            case 2:
                stack.preprocessString(str, processedStr);
                cout << "Processed string: " << processedStr << endl;
                if (stack.isPalindrome(processedStr)) {
                    cout << "The processed string is a palindrome.\n";
                } else {
                    cout << "The processed string is not a palindrome.\n";
                }
                break;

            case 3:
                stack.reverseString(str);
                break;

            case 4:
                exit(0);

            default:
                cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
