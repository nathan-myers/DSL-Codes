#include<iostream>
using namespace std;

struct node {
    int prn;
    string name;

    node* next;
};

class lnk {
    node *head, *temp = NULL;
    public:
        node* create();
        void inserp();
        void insers();
        void display();
        void display_nodes();
};

node* lnk::create() {
    node* p = new node;
    cout << "Enter prn No: ";
    cin>> p -> prn;
    cout << "Enter name: ";
    cin>> p -> name;
    p -> next = NULL;
    return p;
}

void lnk::inserp() {
    node* p = create();
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        temp = head;
        p -> next = temp;
        head = p;
    }
}

void lnk::insers() {
    node* s = create();
    if(head == NULL)
    {
        head = s;
    }
    else
    {
        temp = head;
        s -> next = temp;
        head = s;
    }
}

// void lnk::display(){
//     temp = head;
//     while(temp != NULL){
//         cout << "PRN: " << temp->prn << "\n";
//         cout << "Name: " << temp->name << "\n";
//         temp = temp->next;
//     }

// }

void lnk::display_nodes(){
    node *temp = head;
    int count;
    cout << "How many nodes to display: ";
    cin >> count;
    cout << "\n\n\n";
    while(temp!=NULL && count>0){
        cout << "PRN: " << temp->prn << "\n";
        cout << "Name: " << temp->name << "\n";
        temp = temp->next;
        count--;
    }
    cout<<"\n\n\n";
}

int main(){
    lnk list;

    while(true){
        cout << "Select Your Choice\n 1.Insert President\n 2.Insert Secretary/s\n 3.Display Nodes\n 4.Exit\n";
        int choice;
        cout << "Select Your Choice: ";
        cin >> choice;

        if(choice == 1){
            list.inserp();
        }
        else if(choice == 2){
            list.insers();
        }
        else if(choice == 3){
            list.display_nodes();
        }
        else{
            cout << "Exit\n";
            break;
        }
    }
}
