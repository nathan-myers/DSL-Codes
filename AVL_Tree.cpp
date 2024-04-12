// Practical No 19 from Group D
// Code taken from chatgpt but running fine.

#include<bits/stdc++.h>
using namespace std;

class AVLTree {
private:
    struct Node {
        string keyword;
        string meaning;
        int height;
        Node* left;
        Node* right;
    };

    Node* root;

    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* insert(Node* root, string keyword, string meaning) {
        if (root == nullptr) {
            Node* newNode = new Node;
            newNode->keyword = keyword;
            newNode->meaning = meaning;
            newNode->height = 1;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        if (keyword < root->keyword)
            root->left = insert(root->left, keyword, meaning);
        else if (keyword > root->keyword)
            root->right = insert(root->right, keyword, meaning);
        else // Duplicate keyword, update meaning
            root->meaning = meaning;

        // Update height of the current node
        updateHeight(root);

        // Check balance factor and perform rotations if needed
        int balance = getBalanceFactor(root);

        // Left Left Case
        if (balance > 1 && keyword < root->left->keyword)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && keyword > root->right->keyword)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && keyword > root->left->keyword) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && keyword < root->right->keyword) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* deleteNode(Node* root, string keyword) {
        if (root == nullptr)
            return root;

        if (keyword < root->keyword)
            root->left = deleteNode(root->left, keyword);
        else if (keyword > root->keyword)
            root->right = deleteNode(root->right, keyword);
        else {
            // Node to delete found
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                // Node with two children
                Node* temp = root->right;
                while (temp->left != nullptr)
                    temp = temp->left;
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }

        // If the tree had only one node then return
        if (root == nullptr)
            return root;

        // Update height of the current node
        updateHeight(root);

        // Check balance factor and perform rotations if needed
        int balance = getBalanceFactor(root);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void displayTable(Node* root) {
        if (root != nullptr) {
            displayTable(root->left);
            cout << setw(20) << left << root->keyword << " | " << root->meaning << endl;
            displayTable(root->right);
        }
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void addKeyword(string keyword, string meaning) {
        root = insert(root, keyword, meaning);
    }

    void deleteKeyword(string keyword) {
        root = deleteNode(root, keyword);
    }

    void displayDictionary() {
        if (root == nullptr) {
            cout << "Dictionary is empty.\n";
        } else {
            cout << setw(20) << left << "Keyword" << " | Meaning\n";
            cout << "-------------------------------------------\n";
            displayTable(root);
        }
    }

    // ~AVLTree() {
    //     deleteTree(root);
    // }
};

int main() {
    AVLTree dictionary;

    while (true) {
        cout << "\nOperations:\n";
        cout << "1. Add keyword and meaning\n";
        cout << "2. Delete keyword\n";
        cout << "3. Display dictionary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string keyword, meaning;
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, meaning);
                dictionary.addKeyword(keyword, meaning);
                cout << "Keyword added successfully.\n";
                break;
            }
            case 2: {
                string keyword;
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                dictionary.deleteKeyword(keyword);
                cout << "Keyword deleted successfully.\n";
                break;
            }
            case 3:
                dictionary.displayDictionary();
                break;
            case 4:
                cout << "Program Exitted.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
