/*
TITLE::WASHING CENTRE
*/
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

class queue1;
class node
{
	int cno;
	string name;
	long int phone;
	int kg;
	float arrival;
	float b;
	node *link;
	public:
		node()
		{
			b=0;
			kg=0;
			cno=0;
			link=NULL;
		}
		friend class list;

};

class list
{
 node *head;

	public:
		list()
		{
			head=NULL;
		}
		void insert();
		void display();
		void allot(queue1*);
		float decendtime();
		void genbill(int sno);
		void initprize(node*);		
		node* traverse();
};
void list::initprize(node* temp)
{
	switch(temp->kg)
	{
		case 1:
			temp->b=20;
			break;
		case 2:
			temp->b=40;
			break;
		case 5:
			temp->b=100;
			break;
		case 10:
			temp->b=200;
			break;	
	}
}
void list::genbill(int sno)
{
	node* ptr;
	ptr=head;
	while(ptr->cno!=sno)
	{
		ptr=ptr->link;
	}
		cout<<"\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\t";
		cout<<"\n\t\t\tBILL\n\t";
		cout<<"\nCust. no.\tKg clothes\tPrice per kg\t\tTotal amount\n";
		cout<<"\n------------------------------------------------------------------------------\n\t";
		initprize(ptr);
		cout<<"\n"<<ptr->cno<<"\t\t"<<ptr->kg<<"\t\t20"<<"\t\t\t"<<ptr->b;
		cout<<"\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\t";
}
void list::insert()
{
	node *temp=new node();
	cout<<"Enter details:: ";
	cout<<"\nName:: "<<endl;
	cin>>temp->name;
	cout<<"\nPhone number:: "<<endl;
	cin>>temp->phone;
	cout<<"\nWeight of clothes in kg:: "<<endl;
	cin>>temp->kg;
	cout<<"\nArrival time of the customer::(Please enter in minutes) ";
	cin>>temp->arrival;

	if(head==NULL)
	{
		temp->cno=1;
		head=temp;
	}
	else
	{
		node *ptr;

		for(ptr=head;ptr->link!=NULL;ptr=ptr->link);
		temp->cno=ptr->cno+1;
		ptr->link=temp;
	}
}
void list::display()
{
	node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t";
		cout<<"\n\tCustomer no: "<<ptr->cno;
		cout<<"\n\tName: "<<ptr->name;
		cout<<"\n\tPhone: "<<ptr->phone;
		cout<<"\n\tWeight of clothes: "<<ptr->kg;
		cout<<"\n\tArrival: "<<ptr->arrival;
		cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t";
		ptr=ptr->link;
	}

}
class job
{
	int jno,cno,kg;
	float start,end;
	job *link1;

	public:
		job()
		{
			cno=0;
			jno=0;
			link1=NULL;
		}
		friend class queue1;

};
class queue1
{
 job *front,*rear;

	public:
		queue1()
		{
			front=rear=NULL;
		}
		void enq(int cno,int kg,float arrival);
		void displayq();
		void set_time(job*);
		void deq();
};
void queue1::deq()
{
	job* temp1;
	temp1=front;
	if(front->link1!=NULL)
		front=front->link1;
	else
		front=NULL;
	temp1->link1=NULL;
	delete temp1;
	cout<<"\n\tQueue moved ahead";
}
void queue1::set_time(job* temp)
{
	switch(temp->kg)
	{
		case 1:
			temp->end=temp->start+15;
			break;
		case 2:
			temp->end=temp->start+30;
			break;
		case 5:
			temp->end=temp->start+75;
			break;
		case 10:
			temp->end=temp->start+150;
			break;
	}
}
void queue1::enq(int cno,int kg,float arrival)
{
	job *temp=new job();
	temp->cno=cno;
	temp->kg=kg;
	temp->start=arrival;
	set_time(temp);
	if(front==NULL)
	{
		temp->jno=1;
		front=rear=temp;
	}
	else
	{
		rear->link1=temp;
		temp->jno=rear->jno+1;
		
		if(rear->end<=temp->start)
		{
			deq();
		}
		else
			rear=rear->link1;
	}
}
void queue1::displayq()
{
	job *ptr;
	ptr=front;
	while(ptr!=NULL)
	{	cout<<"\n\n\tCustomer no: "<<ptr->cno;
		cout<<"\n\tJob no: "<<ptr->jno;
		cout<<"\n\tStart time: "<<ptr->start;
		cout<<"\n\tEnd time: "<<ptr->end;
		ptr=ptr->link1;
	}
}
node* list::traverse()
{
	node* ptr;
	ptr=head;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	return ptr;
}
void list::allot(queue1* q)
{
	node* temp;
	temp=traverse();
	if(temp->kg==1)
	{
		q[0].enq(temp->cno,temp->kg,temp->arrival);
	}
	if(temp->kg==2)
	{
		q[1].enq(temp->cno,temp->kg,temp->arrival);
	}
	if(temp->kg==5)
	{
		q[2].enq(temp->cno,temp->kg,temp->arrival);
	}
	if(temp->kg==10)
	{
		q[3].enq(temp->cno,temp->kg,temp->arrival);
	}
}
class node1
{	    string name;
	    int id,t;
	    int clothes;
	    public:
	    int delay;
	    int tdelay;
	    int bill;
	friend class list1;
	node1 *link;
public:
	node1()
{
	id=0;
	bill=0;
	t=0;
	clothes=0.0;
	name="N.A.";
	delay=0;
	link=NULL;
    tdelay=0;
}
};
class list1
{
	node1*head;
public:
	void add_customer();
	void update_clothes();
	void genbill1(int sid);
    void display();
	void delete_customer();
	void search();
	void qtime(int zid);
	void timer(node1* ptr);
	void update_customer(int pos);
	int count(node1 *ptr);
	void billhandwash();
	void displayClock(int min,int sec);
		list1()
	{head=NULL;}
};
void list1::qtime(int zid)
{
	node1* ptr;
	ptr=head;
	while(ptr->id!=zid)
	{
		ptr=ptr->link;
	}
	timer(ptr);
}


void list1::displayClock(int min,int sec)
{

    system("clear");


    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << setfill('0') << setw(2) << min<< " min | ";
    cout << setfill('0') << setw(2) << sec << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n";
}

void list1::timer(node1 *ptr)
{

    int min,sec;
    //tdelay or delay
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
   for(int min=(ptr->delay);min>0;min--)
   {
        for(int sec=59;sec>=0;sec--)
        {
        	sleep(1);
        	displayClock(min,sec);
        }
   }
}




void list1::add_customer()
{	node1 *temp,*ptr;
	temp =new node1();
	cout<<"\nENTER THE BeUrban ID-";
	cin>>temp->id;
	cout<<"\nENTER NAME:";
	cin>>temp->name;
	cout<<"ENTER NUMBER OF CLOTHES:";
	cin>>temp->clothes;
	cout<<"ESTIMATED BILL :";
	temp->bill=(temp->clothes*5);
	cout<<temp->bill<<" INR";
	/*while(temp->clothes< 5)
	{
		cout<<"minimum 5 clothes expected"<<endl;
		cout<<"REENTER THE NUMBER:";
				cin>>temp->clothes;
	}*/
	cout<<"\n\tStay calm,we are working as fast as we can";
	temp->delay=temp->clothes*1;
	cout<<"\nESTIMATED TIME FOR THESE CLOTHES:"<<temp->delay<<" min";

	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		ptr = head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
	}

}

void list1::display()
{
	node1 * ptr;
	ptr=head;
	cout<<"\n::EXISTING ACCOUNT ENTRIES::";
	while(ptr!=NULL)
	{
		cout<<"\nACCOUNT NO:"<<ptr->id<<"\n ";
		cout<<"NAME:"<<ptr->name<<"\n ";
		cout<<"ClOTHES:"<<ptr->clothes<<"\n ";
		cout<<"ESTIMATED TIME:"<<ptr->delay<<"\n";
		//cout<<"QUEUE TIME:"<<count(ptr)<<"\n";
		cout<<"ESTIMATED BILL :"<<ptr->bill;
		ptr=ptr->link;
		cout<<"\n*******************\n";
	}
}
void list1::genbill1(int sid)
{node1* ptr;
	ptr=head;
	while(ptr->id!=sid)
	{
		ptr=ptr->link;
	}

		cout<<"\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\t";
		cout<<"\n\t\t\t***BILL***\n\t";
		cout<<"\n\t--------------------------------------------------------------------------\n\t";
		cout<<"\n\tNo. of clothes\t\tRate\t\tAmount\n";
		cout<<"\n\t"<<ptr->clothes<<"\t\t\t5 INR"<<"\t\t\t"<<ptr->bill;
		cout<<"\n\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\t";

}
int list1::count(node1* ptr)
{
	int x=0,y=0;
	node1 *ptr1;
	ptr1=head;
	while(ptr1!=ptr)
	{   y=ptr1->delay;
		ptr1->tdelay+=y;
		ptr1=ptr1->link;

	}
	return ptr1->tdelay;
}


void list1::delete_customer()
{
	node1*temp;
    int fl=0;
	node1 *ptr;
	node1 *del;
	del=head;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->id==del->id)
		{
			temp->link=ptr->link;
			ptr->link=NULL;
			delete ptr;
			fl=1;
		}

		temp=ptr;
		ptr=ptr->link;
	}
	if(fl==0)
	{
		cout<<"ID does not exist";
		cout<<"\nPlease Try Again";
	}

}

void list1::update_customer(int pos)
{
	int i=0;
	node1 *temp;
	node1 *ptr;
	temp=new node1();
	cout<<"Enter the ID: ";
	cin>>temp->id;
	cout<<"Enter name";
	cin>>temp->name;
	cout<<"Enter the no of clothes";
	cin>>temp->clothes;

	if(temp->clothes <5)
	{
		cout<<"MINIMUM 5 CLOTHES EXPECTED";
	}

	if(pos==1)
	{
		temp->link=head;
		head=temp;
	}
	else
	{
		for(i=1,ptr=head;i<pos-1&&ptr!=NULL;i++,ptr=ptr->link);
		temp->link=ptr->link;
		ptr->link=temp;
	}

}
void list1::search()
{
	    node1 *temp;
		int idd=0;
		cout<<"\nEnter the id:";
		cin>>idd;
		node1 *ptr;
		ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->id==idd)
			{
				cout<<"NAME:"<<ptr->name<<endl;
				cout<<"ID:"<<ptr->id<<endl;
				cout<<"CLOTHES:"<<ptr->clothes<<endl;
				cout<<"TIME:"<<ptr->delay<<endl;
				cout<<"QUEUE TIME:"<<count(ptr)<<"\n";
				break;
			}
			temp=ptr;
			ptr=ptr->link;
		}
}

void list1::update_clothes()
{
	int e=0;

	int idd=0;

	cout<<"\nEnter the id:";
	cin>>idd;
    node1 *ptr;
			ptr=head;
			while(ptr!=NULL)
			{

				if(ptr->id==idd)
				{

					cout<<"NAME:"<<ptr->name<<endl;
					cout<<"ID:"<<ptr->id<<endl;

								cout<<"No of Clothes:";
								cin>>e;
								ptr->clothes=ptr->clothes+e;
								cout<<"CLOTHES:"<<(ptr->clothes)<<endl;
								ptr->delay=ptr->clothes*3;
                                ptr->tdelay=ptr->delay+ptr->tdelay;
                                break;
				}
				ptr=ptr->link;
	    }
}
void list1::billhandwash()
{
	node1* ptr;
	ptr=head;
	int tot=0;
	while(ptr!=NULL)
	{
		tot=tot+ptr->bill;
		ptr=ptr->link;
	}
	cout<<"Total revenue of the section is "<<tot;
}

// membership

class node4
{
    node4*next;
    int cust_id;
    string nm;
    int duration;
public:
    friend class membership;
};
class membership
{
    node4*head;
public:
    membership()
    {
        head = NULL;
    }
    void get_membership();
    void display_members();
    void renew_membership();
    void cancel_membership();
};
void membership::get_membership()
{
    node4*ptr,*prev,*temp;
    int cid;
    string nm;
    int duration;
    int ch;
    do
    {
      cout<<"\n\t Enter id of the Customer: ";
      cin>>cid;
      cout<<"\n\t Enter name of Customer: ";
      cin>>nm;
      cout<<"\n\t Enter the Membership duration: ";
      cin>>duration;
      prev = NULL;
      ptr = head;
      while(ptr!=NULL)
      {
          prev = ptr;
          ptr = ptr->next;
      }
      if(ptr!=NULL && ptr->cust_id==cid)
      {
          cout<<"\n\t You are already a Member of BeUrban family";
      }
      else
      {
            temp = new node4;
            temp->cust_id = cid;
            temp->nm = nm;
            temp->duration = duration;
            temp->next = NULL;
            if(prev==NULL)
            {
                temp->next = head;
                head = temp;
            }
            else
            {
                prev->next = temp;
                temp->next = ptr;
            }
        }
       cout<<"\n\t Press 1 to continue ";
       cin>>ch;
    }while(ch==1);
    cout<<"\n\t Welcome to BeUrban Family";
}
void membership::display_members()
{
    node4*ptr;
    if(head==NULL)
    {
        cout<<"\n\t No members";
    }
    else
    {
        ptr = head;
        cout<<"\n\t"<<left<<setw(25)<<setfill(' ')<<"Customer id"<<setw(20)<<setfill(' ')<<"Customer name"<<setw(25)<<setfill(' ')<<"Membership Duration";
        cout<<"\n\t-----------------------------------------------------------------------------------------------------------\n\t";
        while(ptr!=NULL)
        {
              cout<<"\n\t"<<left<<setw(25)<<setfill(' ')<<ptr->cust_id<<setw(20)<<setfill(' ')<<ptr->nm<<setw(25)<<setfill(' ')<<ptr->duration;
              ptr = ptr->next;
        }
    }
}
void membership::renew_membership()
{
    node4*ptr,*prev;
    int id1,time;
    prev = NULL;
    ptr = head;
    cout<<"\n\t Enter the customer id who wants to renew membership: ";
    cin>>id1;
    while(ptr!=NULL && ptr->cust_id<id1)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if((ptr==NULL) || (ptr!=NULL && ptr->cust_id!=id1))
    {
        cout<<"\n\t Customer not found";
    }
    else
    {
        cout<<"\n\t Enter the renewal duration you want: ";
        cin>>time;
        ptr->duration = time;
        ptr->duration;
    }
}
void membership::cancel_membership()
{
    node4*prev,*ptr;
    int id;
    prev = NULL;
    ptr = head;
    cout<<"\n\t Enter the id of the Customer who wants to cancel Membership: ";
    cin>>id;
    while(ptr!=NULL && ptr->cust_id<id)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if((ptr==NULL) || (ptr!=NULL && ptr->cust_id!=id))
    {
        cout<<"\n\t Customer not found";
    }
    else
    {
        cout<<"\n\t Customer Found";
        if(prev==NULL)
        {
            head = ptr->next;
            ptr->next = NULL;
            delete ptr;
        }
        else
        {
            prev->next = ptr->next;
            ptr->next = NULL;
            delete ptr;
        }
    }
    cout<<"\n\t Hope to see you again!!!";
}


int main()
{
	membership m;
	int c,qqq,xid,sid;	
	list l;
	int qid,qq;
	list1 l1,l2;
	queue1 q[4];
	int ch,mach,z;
	int pos1,sno;
	cout<<"\n\t*****************************************************************\n\t";
	cout<< setw(35)<<"<BeUrban>";;
	cout<<"\n\t*****************************************************************\n";

	do{
	cout<<"\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"\t1.Machine Wash Section"<<endl;
		cout<<"\t2.Hand Wash Section"<<endl;
		cout<<"\t3.Ironing"<<endl;
		cout<<"\t4.BeUrban Membership"<<endl;
	cout<<"\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cin>>z;
	switch(z)
	{
    case 1:
	do
	{
	cout<<"\n\nHere are the details of the job::\n\nThere are 4 machines , \n\tMachine capacity\tPrice\t\tTime duration\n\n\t 1 kg\t\t\t20 Rs\t\t15 min.\n\t2 kg\t\t\t40 Rs\t\t30 min.\n\t5 kg\t\t\t100 Rs\t\t75 min.(1 hour 15 min.)\n\t10 kg\t\t\t200 Rs\t\t150 min(2 hrs 30 min)\n";
	cout<<"\n\n\n\t1.Insert customer\n\t2.Display list\n\t3.Display queue\n\t4.Generate bill\n\t0.Exit\n\tEnter your choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			l.insert();
			l.allot(q);
			break;
		case 2:
			l.display();
			break;
		case 3:
			cout<<"\n\t1) One kg\n\t2) Two kg\n\t3) Five kg\n\t4) Ten kg\n\tEnter which machine queue you want to display?? ";
			cin>>mach;
			switch(mach)
			{
				case 1:

					q[0].displayq();
					break;

				case 2:

					q[1].displayq();
					break;
				case 3:

					q[2].displayq();
					break;
				case 4:

					q[3].displayq();
					break;
				default:
					cout<<"Enter Valid choice";
					break;
			}
			break;
		case 4:
			cout<<"Enter customer number to generate bill";
			cin>>sno;
			l.genbill(sno);
		case 0:
			break;
	}
	}while(ch!=0);
	break;
	case 2:
		do{
			cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t";
			cout<<"\n\t1.Get in the Queue";
			cout<<"\n\t2.VIP register";
			cout<<"\n\t3.Display registration Module";
			cout<<"\n\t4.Search Details";
			cout<<"\n\t5.Add Clothes";
			cout<<"\n\t6.Wait and Count down Time";
			cout<<"\n\t7.Total Earnings of the days";
			cout<<"\n\t8.Generate bill\nEnter choice";
			cin>>qq;
			switch(qq)
			{
			case 1:
				l1.add_customer();
				break;
			case 2:
				cout<<"Which position will you prefer?";
				cin>>pos1;
				l1.update_customer(pos1);
				break;
			case 3:
				l1.display();
				break;
			case 4:
				l1.search();
				break;
			case 5:
				l1.update_clothes();
				break;
			case 6:
				cout<<"Enter 'BeUrban' id";
				cin>>qid;
				l1.qtime(qid);
				break;
			case 8:
				cout<<"Enter ID:";
				cin>>xid;
				l1.genbill1(xid);
				break;
			case 7:
				l1.billhandwash();
				break;
			default:
				cout<<"EXIT:HANDWASH SECTION";
				break;
			}

		}while(qq!=0);
		break;


	case 3:
				do{
					cout<<"\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t";
					cout<<"\n\t1.Deposit";
					cout<<"\n\t2.VIP register";
					cout<<"\n\t3.Display registration Module";
					cout<<"\n\t4.Search Details";
					cout<<"\n\t5.Add Clothes";
					cout<<"\n\t6.Generate bill\nEnter choice";
					cin>>qqq;
					switch(qqq)
					{
					case 1:
						l2.add_customer();
						break;
					case 2:
						cout<<"Which position will you prefer?";
						cin>>pos1;
						l2.update_customer(pos1);
						break;
					case 3:
						l2.display();
						break;
					case 4:
						l2.search();
						break;
					case 5:
						l2.update_clothes();
						break;
					case 6:
						l2.billhandwash();
						break;
					default:
						cout<<"EXIT:IRONING SECTION";
						break;
					}

				}while(qqq!=0);
		//ironing

		break;
	case 4:
		do
	    {
	       cout<<"\n\n\t ************MENU************";
	       cout<<"\n\n\t 1.Get Membership";
	       cout<<"\n\t 2.Display Members";
	       cout<<"\n\t 3.Cancel Membership";
	       cout<<"\n\t 4.Renew Membership";
	       cout<<"\n\t 5.Exit";
	       cout<<"\n\t Enter your choice: ";
	       cin>>c;
	       switch(c)
	       {
	          case 1:
	              m.get_membership();
	              break;
	          case 2:
	            m.display_members();
	            break;
	          case 3:
	            m.cancel_membership();
	            break;
	          case 4:
	            m.renew_membership();
	            break;
	          case 5:
	            cout<<"\n\t Thank You!!!\n  Visit again :)";
	            break;
	          default:
	            cout<<"\n\t Invalid choice";
	            break;
	       }
	    }while(c!=5);

		break;
	}}while(z!=0);

	return 0;
}


/*
OUTPUT::
output::
	*****************************************************************
	                          <BeUrban>
	*****************************************************************

	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	1.Machine Wash Section
	2.Hand Wash Section
	3.Ironing
	4.BeUrban Membership

	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1


Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice1
Enter details:: 
Name:: 
vallari

Phone number:: 
9011452944

Weight of clothes in kg:: 
2

Arrival time of the customer::(Please enter in minutes) 10


Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice1
Enter details:: 
Name:: 
samruddhi

Phone number:: 
7448037689

Weight of clothes in kg:: 
5

Arrival time of the customer::(Please enter in minutes) 20


Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice1
Enter details:: 
Name:: 
rutvika

Phone number:: 
8275284242

Weight of clothes in kg:: 
2

Arrival time of the customer::(Please enter in minutes) 80

	Queue moved ahead

Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice2

	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	Customer no: 1
	Name: vallari
	Phone: 9011452944
	Weight of clothes: 2
	Arrival: 10
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	Customer no: 2
	Name: samruddhi
	Phone: 7448037689
	Weight of clothes: 5
	Arrival: 20
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	Customer no: 3
	Name: rutvika
	Phone: 8275284242
	Weight of clothes: 2
	Arrival: 80
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	

Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice33


Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice3

	1) One kg
	2) Two kg
	3) Five kg
	4) Ten kg
	Enter which machine queue you want to display?? 2


	Customer no: 3
	Job no: 2
	Start time: 80
	End time: 110

Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice3

	1) One kg
	2) Two kg
	3) Five kg
	4) Ten kg
	Enter which machine queue you want to display?? 3


	Customer no: 2
	Job no: 1
	Start time: 20
	End time: 95

Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice4
Enter customer number to generate bill1

	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	
			BILL
	
Cust. no.	Kg clothes	Price per kg		Total amount

------------------------------------------------------------------------------
	
1		2		20			40
	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	

Here are the details of the job::

There are 4 machines , 
	Machine capacity	Price		Time duration

	 1 kg			20 Rs		15 min.
	2 kg			40 Rs		30 min.
	5 kg			100 Rs		75 min.(1 hour 15 min.)
	10 kg			200 Rs		150 min(2 hrs 30 min)



	1.Insert customer
	2.Display list
	3.Display queue
	4.Generate bill
	0.Exit
	Enter your choice0

	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	1.Machine Wash Section
	2.Hand Wash Section
	3.Ironing
	4.BeUrban Membership

	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2

	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	1.Get in the Queue
	2.VIP register
	3.Display registration Module
	4.Search Details
	5.Add Clothes
	6.Wait and Count down Time
	7.Total Earnings of the days
	8.Generate bill
Enter choice1

ENTER THE BeUrban ID-101

ENTER NAME:sakshi
ENTER NUMBER OF CLOTHES:2
ESTIMATED BILL :10 INR
	Stay calm,we are working as fast as we can
ESTIMATED TIME FOR THESE CLOTHES:2 min
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	1.Get in the Queue
	2.VIP register
	3.Display registration Module
	4.Search Details
	5.Add Clothes
	6.Wait and Count down Time
	7.Total Earnings of the days
	8.Generate bill
Enter choice1

ENTER THE BeUrban ID-102

ENTER NAME:anushka
ENTER NUMBER OF CLOTHES:10
ESTIMATED BILL :50 INR
	Stay calm,we are working as fast as we can
ESTIMATED TIME FOR THESE CLOTHES:10 min
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	1.Get in the Queue
	2.VIP register
	3.Display registration Module
	4.Search Details
	5.Add Clothes
	6.Wait and Count down Time
	7.Total Earnings of the days
	8.Generate bill
Enter choice3

::EXISTING ACCOUNT ENTRIES::
ACCOUNT NO:101
 NAME:sakshi
 ClOTHES:2
 ESTIMATED TIME:2
QUEUE TIME:0
ESTIMATED BILL :10
*******************

ACCOUNT NO:102
 NAME:anushka
 ClOTHES:10
 ESTIMATED TIME:10
QUEUE TIME:0
ESTIMATED BILL :50
*******************

	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	1.Get in the Queue
	2.VIP register
	3.Display registration Module
	4.Search Details
	5.Add Clothes
	6.Wait and Count down Time
	7.Total Earnings of the days
	8.Generate bill
Enter choice4

Enter the id:102
NAME:anushka
ID:102
CLOTHES:10
TIME:10
QUEUE TIME:0

	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	1.Get in the Queue
	2.VIP register
	3.Display registration Module
	4.Search Details
	5.Add Clothes
	6.Wait and Count down Time
	7.Total Earnings of the days
	8.Generate bill
Enter choice5

Enter the id:102
NAME:anushka
ID:102
No of Clothes:2
CLOTHES:12

	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	1.Get in the Queue
	2.VIP register
	3.Display registration Module
	4.Search Details
	5.Add Clothes
	6.Wait and Count down Time
	7.Total Earnings of the days
	8.Generate bill
Enter choice8
Enter ID:101

	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	
			***BILL***
	
	--------------------------------------------------------------------------
	
	No. of clothes		Rate		Amount

	2		5 INR		10
	$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
	
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	1.Get in the Queue
	2.VIP register
	3.Display registration Module
	4.Search Details
	5.Add Clothes
	6.Wait and Count down Time
	7.Total Earnings of the days
	8.Generate bill
Enter choice7
Total revenue of the section is 60
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	1.Get in the Queue
	2.VIP register
	3.Display registration Module
	4.Search Details
	5.Add Clothes
	6.Wait and Count down Time
	7.Total Earnings of the days
	8.Generate bill
Enter choice  
	4.BeUrban Membership
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 1.Get Membership
	 2.Display Members
	 3.Cancel Membership
	 4.Renew Membership
	 5.Exit
	 Enter your choice: 1
	 Enter id of the Customer: 11
	 Enter name of Customer: sakshi
	 Enter the Membership duration: 2
	 Press 1 to continue 1
	 Enter id of the Customer: 22
	 Enter name of Customer: anushka
	 Enter the Membership duration: 3
	 Press 1 to continue 0
	 Welcome to BeUrban Family
	 1.Get Membership
	 2.Display Members
	 3.Cancel Membership
	 4.Renew Membership
	 5.Exit
	 Enter your choice: 2
	Customer id     Customer name   Membership Duration      
	--------------------------------------------------
	11               sakshi           2                        
	22               anushka          3                        

	 3.Cancel Membership
	 Enter the id of the Customer who wants to cancel Membership: 22

	 Customer Found
	 Hope to see you again!!!

	 **4.Renew Membership
	 Enter the customer id who wants to renew membership: 11
	 Enter the renewal duration you want: 4
	 2.Display Members
	Customer id    Customer name    Membership Duration      
	--------------------------------------------------
	
	11              sakshi            4      

*/




