#include <iostream>
#include <queue>
using namespace std;

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

class BSTree
{
    private:
        Node* root;

    public:
        BSTree() 
        {
            root = nullptr;
        }

        void insert(int data) 
        {
            if (root == nullptr) 
            {
                root = new Node(data);
                return;
            }

            Node* currentNode = root;
            while(true) 
            {
                if (data < currentNode->data) 
                {
                    if (currentNode->left == nullptr) 
                    {
                        currentNode->left = new Node(data);
                        return;
                    }
                    currentNode = currentNode->left;
                } 
                
                else if(data > currentNode->data) 
                {
                    if(currentNode->right == nullptr) 
                    {
                        currentNode->right = new Node(data);
                        return;
                    }
                    currentNode = currentNode->right;
                } 
                else 
                {
                    // Duplicate value, ignoring insertion
                    return;
                }
        }

        }

        int longestPath() 
        {
            if (root == nullptr) 
            {
                return 0;
            }

            int maxDepth = 0;
            queue<pair<Node*, int>> q;
            q.push({root, 1});
            while (!q.empty()) 
            {
                Node* node = q.front().first;
                int depth = q.front().second;
                q.pop();
                maxDepth = max(maxDepth, depth);
                if (node->left) q.push({node->left, depth + 1});
                if (node->right) q.push({node->right, depth + 1});
            }
            return maxDepth - 1;
        }

    int minValue() 
    {
        if (root == nullptr) return -1; // Assuming tree cannot contain negative values

        Node* currentNode = root;
        while (currentNode->left != nullptr) 
        {
            currentNode = currentNode->left;
        }
        return currentNode->data;
    }

    void swapRoles() {
        swapRolesHelper(root);
    }

    void swapRolesHelper(Node* root) {
        if (root == nullptr) return;

        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        swapRolesHelper(root->left);
        swapRolesHelper(root->right);
    }

    bool search(int key) {
        Node* currentNode = root;
        while (currentNode != nullptr) {
            if (key == currentNode->data) {
                return true;
            } else if (key < currentNode->data) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }
        return false;
    }

    void displayInOrder() {
        displayInOrderHelper(root);
        cout << endl;
    }

    void displayInOrderHelper(Node* root) {
        if (root == nullptr) return;
        displayInOrderHelper(root->left);
        cout << root->data << " ";
        displayInOrderHelper(root->right);
    }
};

int main() {
    BSTree bst;
    int choice;

    while(true) {
        cout << "\nSelect operation:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Find the number of nodes in the longest path from root" << endl;
        cout << "3. Find minimum data value in the tree" << endl;
        cout << "4. Swap left and right pointers at every node" << endl;
        cout << "5. Search for a value" << endl;
        cout << "6. Display the tree (In-order traversal)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                cout << "Value " << value << " inserted successfully." << endl;
                break;
            }
            case 2: {
                cout << "Number of nodes in the longest path from root: " << bst.longestPath() << endl;
                break;
            }
            case 3: {
                cout << "Minimum data value found in the tree: " << bst.minValue() << endl;
                break;
            }
            case 4: {
                bst.swapRoles();
                cout << "Left and right pointers swapped at every node." << endl;
                break;
            }
            case 5: {
                int searchValue;
                cout << "Enter value to search: ";
                cin >> searchValue;
                cout << "Searching for value " << searchValue << ": " << (bst.search(searchValue) ? "Found" : "Not Found") << endl;
                break;
            }
            case 6: {
                cout << "Tree (In-order traversal): ";
                bst.displayInOrder();
                break;
            }
            case 7: {
                cout << "Exiting program." << endl;
                exit(0);
            }
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
