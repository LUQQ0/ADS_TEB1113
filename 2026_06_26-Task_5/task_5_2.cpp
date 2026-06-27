#include <iostream>
#include <string>

using namespace std;

//=============Queue using linked list=============
// class Queue
// {
// public:
//     string name;
//     Queue *next = NULL;

//     Queue *front = NULL;
//     Queue *rear = NULL;

//     // enqueue (push in queue)
//     void enqueue(string name)
//     {
//         Queue *newnode = new Queue();
//         newnode->name = name;
//         newnode->next = NULL;

//         if (rear == NULL) // empty queue
//         {
//             front = rear = newnode;
//             return;
//         }

//         rear->next = newnode;
//         rear = newnode;
//     }

//     // dequeue (pop from front)
//     void dequeue()
//     {
//         if (front == NULL)
//         {
//             cout << "Queue is empty." << endl;
//             return;
//         }

//         Queue *temp = front;
//         front = front->next;

//         if (front == NULL)
//         {
//             rear = NULL;
//         }

//         delete temp;
//     }

//     // peek (front element)
//     void peek()
//     {
//         if (front == NULL)
//         {
//             cout << "Queue is empty." << endl;
//         }
//         else
//         {
//             cout << "Front element: " << front->name << endl;
//         }
//     }

//     // display
//     void display()
//     {
//         Queue *temp = front;

//         while (temp != NULL)
//         {
//             cout << temp->name << endl;
//             temp = temp->next;
//         }
//     }
// };

// int main()
// {
//     Queue *q = new Queue();

//     q->enqueue("Aimar");
//     q->enqueue("Ahmad");
//     q->enqueue("Anajana");

//     q->dequeue();      // removes Aimar

//     q->enqueue("Jessy");

//     q->peek();
//     q->display();

//     return 0;
// }

//=============Queue using array=============
class Queue
{
public:
    static const int SIZE = 5;
    string arr[SIZE];

    int front;
    int rear;

    Queue()
    {
        front = -1;
        rear = -1;
    }

    // enqueue
    void enqueue(string name)
    {
        if (rear == SIZE - 1)
        {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1) // first element
        {
            front = 0;
        }

        rear++;
        arr[rear] = name;
    }

    // dequeue
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Removed: " << arr[front] << endl;
        front++;

        // reset queue if empty
        if (front > rear)
        {
            front = rear = -1;
        }
    }

    // peek
    void peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // display
    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements:\n";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue("Aimar");
    q.enqueue("Ahmad");
    q.enqueue("Anajana");

    q.dequeue(); // removes Aimar

    q.enqueue("Jessy");

    q.peek();
    q.display();

    return 0;
}