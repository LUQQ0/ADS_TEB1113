#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next; // pointer variable, stores address
    Node *prev;
};

int main()
{

    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Node *node4 = new Node();

    node1->data = "Aimar";
    node1->next = node2;
    node1->prev = NULL;

    node2->data = "Ahmad";
    node2->next = node3;
    node2->prev = node1;

    node3->data = "anjana";
    node3->next = node4;
    node3->prev = node2;

    node4->data = "Jessy";
    node4->next = NULL;
    node4->prev = node3;

    // Traverse and print
    Node *temp = node1;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}