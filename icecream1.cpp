#include <iostream>
using namespace std;

struct node
{
	int rollno;
	node *next;
};

class information
{
  public:
	node *head1 = NULL, *temp1 = NULL, *head2 = NULL, *temp2 = NULL, *head = NULL, *temp = NULL, *h1 = NULL, *head3 = NULL, *temp3 = NULL, *p = NULL;
	int roll_no, i, f, bs_student, totalstudent, v_student;
	node *create();
	void insert();
	void allstud();
	void vanila();
	void butterscotch();
	void union_vanilla_butterscotch();
	void intersection_vanila_butterscotch();
	void notice();
	void onlyvanila();
	void onlybutterscotch();
	void display();
};
node *information::create()
{
	node *p = new node;
	cout << "Enter student roll no";
	cin >> roll_no;
	p->rollno = roll_no;
	p->next = NULL;
	return p;
}

void information::insert()
{
	node *p = create();
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
	}
}
void information::display()
{
	temp = head;
	cout << "\nRoll no of student is : ";
	while (temp != NULL)
	{
		cout << " " << temp->rollno;
		temp = temp->next;
	}
}
void information::allstud()
{
	cout << "Enter total no of student in class:";

	cin >> totalstudent;
	for (i = 0; i < totalstudent; i++)
	{
		insert();
		h1 = head;
	}
	cout << "\n------------------------------------------------";
	display();
	head = NULL;
}
void information::vanila()
{
	cout << "\n------------------------------------------------";
	cout << "\nEnter total no of student who likes only vanila:";
	cin >> v_student;
	for (i = 0; i < v_student; i++)
	{
		insert();
		head1 = head;
	}
	cout << "\n------------------------------------------------";

	display();
	head = NULL;
}
void information::butterscotch()
{
	cout << "\n------------------------------------------------";
	cout << "\nEnter total no of student who likes only butterscotch:";
	cin >> bs_student;
	for (i = 0; i < bs_student; i++)
	{
		insert();
		head2 = head;
	}
	cout << "\n------------------------------------------------";
	display();
	head = NULL;
}

void information::union_vanilla_butterscotch()
{
	cout << "\n------------------------------------------------";
	cout << "\nstudents who like vanila or butterscotch: ";
	temp1 = head1;
	while (temp1 != NULL)
	{
		node *p = new node;
		p->rollno = temp1->rollno;
		p->next = NULL;
		if (head3 == NULL)
		{
			head3 = p;
		}
		else
		{
			temp3 = head3;
			while (temp3->next != NULL)
			{
				temp3 = temp3->next;
			}
			temp3->next = p;
		}
		temp1 = temp1->next;
	}
	temp2 = head2;
	while (temp2 != NULL)
	{
		f = 0;
		temp1 = head1;
		while (temp1 != NULL)
		{
			if (temp2->rollno == temp1->rollno)
			{
				f = 1;
				break;
			}
			temp1 = temp1->next;
		}
		if (f == 0)
		{
			node *p = new node;
			p->rollno = temp2->rollno;
			p->next = NULL;
			if (head3 == NULL)
			{
				head3 = p;
			}
			else
			{
				temp3 = head3;
				while (temp3->next != NULL)
				{
					temp3 = temp3->next;
				}
				temp3->next = p;
			}
		}
		temp2 = temp2->next;
	}
	temp3 = head3;
	while (temp3 != NULL)
	{
		cout << " " << temp3->rollno;
		temp3 = temp3->next;
	}
	cout << "\n------------------------------------------------";
}
void information::onlyvanila()
{
	cout << "\nRoll no of student who like only vanila:";
	temp1 = head1;
	while (temp1 != NULL)
	{
		temp2 = head2;
		f = 0;
		while (temp2 != NULL)
		{
			if (temp2->rollno == temp1->rollno)
			{
				f = 1;
				break;
			}
			temp2 = temp2->next;
		}
		if (f == 0)
		{
			cout << " " << temp1->rollno;
		}

		temp1 = temp1->next;
	}
	cout << "\n------------------------------------------------";
}
void information::onlybutterscotch()
{
	cout << "\nRoll no of student who like only butterscotch:";
	temp2 = head2;
	while (temp2 != NULL)
	{
		temp1 = head1;
		f = 0;
		while (temp1 != NULL)
		{
			if (temp1->rollno == temp2->rollno)
			{
				f = 1;
			}
			temp1 = temp1->next;
		}
		if (f == 0)
		{
			cout << " " << temp2->rollno;
		}

		temp2 = temp2->next;
	}
	cout << "\n------------------------------------------------";
}
void information::intersection_vanila_butterscotch()
{
	cout << "\nstudents who like both vanila and butterscotch: ";
	temp1 = head1;
	while (temp1 != NULL)
	{
		temp2 = head2;
		while (temp2 != NULL)
		{
			if (temp1->rollno == temp2->rollno)
			{
				cout << " " << temp1->rollno;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	cout << "\n------------------------------------------------";
}
void information ::notice()
{
	cout << "\nstudents who like neither vanila nor butterscotch\n";
	temp = h1;
	while (temp != NULL)
	{
		temp3 = head3;
		f = 0;
		while (temp3 != NULL)
		{
			if (temp3->rollno == temp->rollno)
			{
				f = 1;
			}
			temp3 = temp3->next;
		}
		if (f == 0)
		{
			cout << " " << temp->rollno;
		}
		temp = temp->next;
	}
}

int main()
{
	information info;

	info.allstud();
	info.vanila();
	info.butterscotch();
	info.union_vanilla_butterscotch();
	info.onlyvanila();
	info.onlybutterscotch();
	info.intersection_vanila_butterscotch();
	info.notice();
	return 0;
}
