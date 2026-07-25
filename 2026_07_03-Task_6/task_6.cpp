#include <iostream>
using namespace std;

//========================
// BST Node
//========================
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

//========================
// Insert
//========================
Node* insert(Node* root, int value)
{
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    // Ignore duplicate values
    return root;
}

//========================
// Search
//========================
bool search(Node* root, int value)
{
    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

//========================
// Find Minimum Node
//========================
Node* findMin(Node* root)
{
    while (root->left != nullptr)
        root = root->left;

    return root;
}

//========================
// Delete
//========================
Node* deleteNode(Node* root, int value)
{
    if (root == nullptr)
        return nullptr;

    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else
    {
        // No child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // One child
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

//========================
// Find Minimum Value
//========================
int findMinimum(Node* root)
{
    while (root->left != nullptr)
        root = root->left;

    return root->data;
}

//========================
// Find Maximum Value
//========================
int findMaximum(Node* root)
{
    while (root->right != nullptr)
        root = root->right;

    return root->data;
}

//========================
// Traversals
//========================
void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//========================
// Main
//========================
int main()
{
    Node* root = nullptr;

    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int value : values)
        root = insert(root, value);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n\nMinimum = " << findMinimum(root);
    cout << "\nMaximum = " << findMaximum(root);

    cout << "\n\nSearching for 60... ";
    if (search(root, 60))
        cout << "Found";
    else
        cout << "Not Found";

    cout << "\n\nDeleting 70...\n";
    root = deleteNode(root, 70);

    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}