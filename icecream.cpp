#include<iostream>
using namespace std;

struct node
{
    int rollno;
    node *next;
};

class information
{
    public:
    node *head1=NULL, *temp1=NULL, *head2=NULL, *temp2=NULL, *head=NULL, *temp=NULL, *h1=NULL, *head3=NULL, *temp3=NULL, *p=NULL;
    int roll_no, i, f, bs_students, total_students, v_students;
    node *create();         //done
    void insert();          //done
    void allstudent();
    void vanilla();
    void butterscotch();
    void union_vanilla_butterscotch();
    void intersection_vanilla_butterscotch();
    void no_icecream();
    void only_vanilla();
    void only_butterscotch();
    void display();         //done
};

node *information::create()
{
    node *p = new node;
    cout << "Enter student roll number: ";
    cin >> roll_no;
    p -> rollno = roll_no;
    p -> next = NULL;
    return p;
}

void information::insert()
{
    node *p = create();
    if(head==NULL)
    {
        head = p;
    }
    
    else
    {
        temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = p;
    }
}

void information::display()
{
    temp = head;
    cout << "\nRoll number of student is: ";
    while(temp != NULL)
    {
        cout << " " << temp -> rollno;
        temp = temp -> next;
    }
}
