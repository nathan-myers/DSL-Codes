#include<iostream>
#include<string>
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
        int tbook, tchapters;
        root = new Node;
        
        cout << "\nEnter book name: ";
        cin.ignore();
        getline(cin, root->label);

        cout << "\nEnter number of chapters in book: ";
        cin >> tchapters;

        root->chap_count = tchapters;
        
        for(int i=0; i < tchapters; i++)
        {
            root->child[i] = new Node;
            
            cout << "\nEnter name of chapter " << i+1 << " : ";
            cin.ignore();
            getline(cin, root->child[i]->label);

            cout << "Enter no of sections in chapter " << root->child[i]->label << " : ";
            cin >> root->child[i] -> chap_count;

            for(int j=0; j < root->child[i]->chap_count; j++)
            {
                root->child[i]->child[j] = new Node;
                cout << "Enter name of section " << j+1 << " : ";
                cin.ignore();
                getline(cin, root->child[i]->child[j]->label);
            }
        }
    }

    void display(Node *root)
    {
        if(root == NULL)
        {
            cout << "Tree is empty !!";
            return;
        }

        cout << "\n-----Book hierarchy----\n";
        cout << "Book name: " << root->label << endl;

        int tchapters = root->chap_count;
        
        for(int i=0; i < tchapters; i++)
        {
            cout << "\nChapter " << i+1 << ": " << root->child[i]->label << endl;
            cout << "Sections:\n";

            int sections = root->child[i]->chap_count;

            for(int j=0; j < sections; j++)
            {
                cout << j+1 << ". " << root->child[i]->child[j]->label << endl;
            }
        }
        cout << "\n";   
    }




};


int main()
{
    GeneralTree obj;
    obj.create();
    obj.display(root);
    return 0;
}
