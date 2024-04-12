#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    string keyword;
    string meaning;
    int height;
    Node *left;
    Node *right;
}; 

class AVL_Tree
{
    private:
    Node *root;

    int getHeight(Node *node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node *node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    int updateHeight(Node *node)
    {
        node->height = 1+ max(getHeight(node->left), getHeight(node->right));
    }
    
    public:

    AVL_Tree()
    {

    }
};

int main()
{
    
    
    return 0;
}
