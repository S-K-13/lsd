//C++ program for expression conversion as infix to postfix and its evaluation using
stack

#include <iostream>
#include <stack>
using namespace std;


int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; 
}


int applyOperator(int a, int b, char op) 
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}


string infixToPostfix(string infix) 
{
    stack<char> s; 
    string postfix = "";  

    for (char ch : infix) 
    {
        if (isalnum(ch)) 
        {
            postfix += ch;  
        } 
        else if (ch == '(') 
        {
            s.push(ch);  
        } 
        else if (ch == ')') 
        {
            while (s.top() != '(') 
            {
                postfix += s.top();  
                s.pop();
            }
            s.pop(); 
        } 
        else 
        {  
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) 
            {
                postfix += s.top();  
                s.pop();
            }
            s.push(ch);  
        }
    }

   
    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}


int evaluatePostfix(string postfix) 
{
    stack<int> s; 

    for (char ch : postfix) 
    {
        if (isdigit(ch)) 
        {
            s.push(ch - '0'); 
        } 
        else 
        {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result = applyOperator(a, b, ch);  
            s.push(result); 
        }
    }

    return s.top();  
}

int main() 
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}

