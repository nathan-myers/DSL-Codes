#include<iostream>
using namespace std;

struct Node
{
    string label;
    int chap_count;
    struct Node *child[50];
}*root;

class GeneralTree
{
    public:
    GeneralTree()
    {
        root = NULL;
    }

    void create()
    {
        int tbook, tchapter;
        root = new Node();
        // cin.ignore();
        cout << "\nEnter book name: ";
        // cin >> root->label;
        getline(cin, root->label);
        cin.ignore();
        cout << "\nEnter total number of chapters: ";
        cin >> tchapter;

        root->chap_count = tchapter;
        
        for(int i=0; i < tchapter; i++)
        {
            root->child[i] = new Node();
            
            cout << "\nEnter name of chapter: ";
            cin >> root->child[i]->label;

            cout << "\nEnter no of sections in chapter " << i+1 << " : ";
            cin >> root-> chap_count;

            for(int j=0; j < root->chap_count; j++)
            {
                root->child[i]->child[j] = new Node;
                cout << "Enter section name: ";
                cin >> root-> child[i] -> child[j] -> label;
            }
        }
    }

    void display()
    {
        int tbook, tchapter;
        
        if(root == NULL)
        {
            cout << "Tree is empty !!";
        }

        else
        {
        root->chap_count = tchapter;
        
        for(int i=0; i < tchapter; i++)
        {
            
            cout << "Name of chapter: " << root->child[i]->label;

            cout << "Name of section " << i+1 << " : " << root-> chap_count;

            for(int j=0; j < root->chap_count; j++)
            {
                cout << "Section name: " << root-> child[i] -> child[j] -> label;
            }
        }
        }

        
    }
};

int main()
{
    GeneralTree obj;
    obj.create();
    obj.display();
    return 0;
}


