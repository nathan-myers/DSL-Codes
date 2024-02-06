#include <iostream>
using namespace std;

struct Node
{
    string label;
    int chap_count;
    struct Node *child[50];
};

class GeneralTree
{
public:
    Node *root;

    GeneralTree()
    {
        root = NULL;
    }

    void create(Node *current)
    {
        int tchapter;
        
        cout << "\nEnter total number of chapters for " << current->label << ": ";
        cin >> tchapter;

        current->chap_count = tchapter;

        for (int i = 0; i < tchapter; i++)
        {
            current->child[i] = new Node();

            cout << "\nEnter name of chapter: ";
            cin >> current->child[i]->label;

            cout << "\nEnter no of sections in chapter " << current->child[i]->label << " : ";
            cin >> current->child[i]->chap_count;

            create(current->child[i]); // Recursively create child sections
        }
    }

    void display(Node *current)
    {
        if (current == NULL)
            return;

        cout << "\nName of chapter: " << current->label << endl;

        for (int i = 0; i < current->chap_count; i++)
        {
            cout << "\nName of section in chapter " << current->label << " : " << current->child[i]->label << endl;
            display(current->child[i]); // Recursively display child sections
        }
    }
};

int main()
{
    GeneralTree obj;
    obj.root = new Node();
    cout << "\nEnter book name: ";
    cin >> obj.root->label;

    obj.create(obj.root);
    obj.display(obj.root);

    return 0;
}
