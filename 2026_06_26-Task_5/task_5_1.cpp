#include <iostream>
#include <string>

using namespace std;

/*
Aimar
Ahmad
Anajana
Jessy
*/

//=============Stack using linked list=============
// class Stack
// {
// public:
//     string name;
//     Stack *next = NULL;
//     Stack *top = NULL;
//     // push
//     void push(string name)
//     {
//         Stack *newnode = new Stack();
//         newnode->name = name;
//         newnode->next = top;
//         top = newnode;
//     }
//     // pop
//     void pop()
//     {
//         top = top->next;
//     }

//     // peek
//     void peek()
//     {
//         if (top == NULL)
//         {
//             cout << "Stack is empty." << endl;
//         }
//         else
//         {
//             cout << "Top element: " << top->name << endl;
//         }
//     }
//     // display
//     void display()
//     {
//         Stack *display_node = top;
//         while (display_node != NULL)
//         {
//             cout << display_node->name << endl;
//             display_node = display_node->next;
//         }
//     }
// };

// int main()
// {
//     Stack *stack = new Stack();
//     stack->push("Aimar");
//     stack->push("Ahmad");
//     stack->push("Anajana");
//     stack->pop();
//     stack->push("Jessy");
//     stack->peek();
//     stack->display();
//     return 0;
// }

//=============Stack using array=============
#include <iostream>
#include <string>

using namespace std;

class Stack
{
public:
    static const int SIZE = 5;
    string arr[SIZE];
    int top;

    Stack()
    {
        top = -1;
    }

    // push
    void push(string name)
    {
        if (top == SIZE - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = name;
    }

    // pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << "Removed: " << arr[top] << endl;
        top--;
    }

    // peek
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // display
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements:\n";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack stack;

    stack.push("Aimar");
    stack.push("Ahmad");
    stack.push("Anajana");

    stack.pop(); // removes Anjana

    stack.push("Jessy");

    stack.peek();
    stack.display();

    return 0;
}