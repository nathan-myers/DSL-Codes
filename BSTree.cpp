#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

class BSTree
{
    private:
        Node *root;

    public:
        Node *insertRecord(Node *root, int data)
        {
            if(root == nullptr)
            {
                return new Node(data);
            }

            if(data < root->data)
            {
                insertRecord(root->left, data);
            }

            else if(data > root->data)
            {
                insertRecord(root->right, data);
            }

            return root;
        }

        void displayInorder(Node *root)
        {
            if(root == nullptr)
            {
                return;
            }

            displayInorder(root->left);
            cout << root->data << " ";
            displayInorder(root->right);
        }

};

int main()
{
    BSTree bst;
    int choice;
    int data;
    Node *root;

    while(true)
    {
        cout << "\nSelect operation:";
        cout << "\n1. Insert a value";
        cout << "\n2. Display Inorder Traversal";

        cin >> choice;

        switch(choice)
        {
            case 1:
            bst.insertRecord(root, data);
            break;

            case 2:
            bst.displayInorder(root);
            break;

            default:
            cout << "Invalid input!!";
        }
    }

    return 0;
}
