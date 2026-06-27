#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *prev;
    Node *next;
};

// Function Prototypes
void traverseForward(Node *head);
void traverseBackward(Node *head);
void search(Node *head);
void access(Node *head);
void insertEnd(Node *&head);
void insertAnywhere(Node *&head);
void deleteNode(Node *&head);

int main()
{
    // Create nodes
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();

    node1->data = "Aimar";
    node2->data = "Ahmad";
    node3->data = "Anjana";

    // Link them circularly
    node1->next = node2;
    node1->prev = node3;

    node2->next = node3;
    node2->prev = node1;

    node3->next = node1;
    node3->prev = node2;

    Node *head = node1;

    int choice;

    do
    {
        cout << "\n===== CIRCULAR DOUBLY LINKED LIST =====\n";
        cout << "1. Traverse Forward\n";
        cout << "2. Traverse Backward\n";
        cout << "3. Search\n";
        cout << "4. Access by Position\n";
        cout << "5. Insert End\n";
        cout << "6. Insert Anywhere\n";
        cout << "7. Delete\n";
        cout << "8. Exit\n";
        cout << "Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            traverseForward(head);
            break;
        case 2:
            traverseBackward(head);
            break;
        case 3:
            search(head);
            break;
        case 4:
            access(head);
            break;
        case 5:
            insertEnd(head);
            break;
        case 6:
            insertAnywhere(head);
            break;
        case 7:
            deleteNode(head);
            break;
        case 8:
            cout << "Program Ended\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 8);

    return 0;
}

// ================= Traverse Forward =================
void traverseForward(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    do
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD)\n";
}

// ================= Traverse Backward =================
void traverseBackward(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head->prev;

    do
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    } while (temp != head->prev);

    cout << "(TAIL)\n";
}

// ================= Search =================
void search(Node *head)
{
    if (head == NULL)
        return;

    string target;
    cout << "Enter data: ";
    cin >> target;

    Node *temp = head;

    do
    {
        if (temp->data == target)
        {
            cout << "Found\n";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Not Found\n";
}

// ================= Access =================
void access(Node *head)
{
    int pos;
    cout << "Enter Position: ";
    cin >> pos;

    Node *temp = head;

    for (int i = 1; i < pos; i++)
        temp = temp->next;

    cout << "Data = " << temp->data << endl;
}

// ================= Insert End =================
void insertEnd(Node *&head)
{
    Node *newNode = new Node();

    cout << "Enter data: ";
    cin >> newNode->data;

    Node *tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;

    cout << "Inserted Successfully\n";
}

// ================= Insert Anywhere =================
void insertAnywhere(Node *&head)
{
    int pos;

    cout << "Enter Position: ";
    cin >> pos;

    Node *newNode = new Node();

    cout << "Enter data: ";
    cin >> newNode->data;

    if (pos == 1)
    {
        Node *tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;

        tail->next = newNode;
        head->prev = newNode;

        head = newNode;

        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    cout << "Inserted Successfully\n";
}

// ================= Delete =================
void deleteNode(Node *&head)
{
    if (head == NULL)
        return;

    string target;

    cout << "Enter data to delete: ";
    cin >> target;

    Node *current = head;

    do
    {
        if (current->data == target)
        {
            if (current->next == current)
            {
                delete current;
                head = NULL;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == head)
                head = current->next;

            delete current;

            cout << "Deleted Successfully\n";
            return;
        }

        current = current->next;

    } while (current != head);

    cout << "Data Not Found\n";
}