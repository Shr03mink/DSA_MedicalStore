/*
 * med.cpp
 *
 *  Created on: Oct 13, 2018
 *      Author: ccoew
 */



/*
 * med.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: ccoew
 */
#include<iostream>
#include<string.h>
using namespace std;
class tablet
{
	long code;
	char type[20];
	int expmonth;
	int expyr;	int manumnth,manudate;
	int manuyr;
	char comp_name[20];
	char med_name[20];
	double price=0;
	tablet *next,*prev;
public:
	friend class shopkeeper;
	friend class customer;
	tablet (long cd,char t[20],char cn[20],char mn[20],int xm,int xy,int md,int mm,int my, double p) //Parameterized constructor called
{
	    code=cd;
	    strcpy(type,t);
	    strcpy(comp_name,cn);
	    strcpy(med_name,mn);
	    expmonth=xm;
		expyr=xy;
		manudate=md;
		manumnth=mm;
		manuyr=my;
	    price=p;
		next=NULL;
		prev=NULL;
}
tablet(char t1[20],char n1[20] )
{
    strcpy(type,t1);
	strcpy(med_name,n1);
	next=NULL;
	prev=NULL;
}
};
class shopkeeper
{
public:
	friend class customer;
	char name[20];
	int age;
	long mo_no;
	char doc_name[20];
	double gst,total;
    tablet *head;
 	 shopkeeper()
 	 {
 		 head=NULL;
 	 }

	void accept_tab_details();
	void display_tab_details();
	void add_tab();
	void remove_tab(int v);
	void count_total_tabs();
	void contents();
	void medicine();
	void buyer();
	void bill();
};
void shopkeeper::accept_tab_details()
{
	char ans;
	tablet *temp;
	tablet *ptr;
	long code;
	int expmonth;
	int expyr;
	int manudate;
	int manumnth;
	int manuyr;
	char comp_name[20];
	char med_name[20];
	char type[30];
	double price;
	do
	{
	cout<<"enter bar code number:";
cin>>code;
	cout<<"enter type of tablet";
	cin>>type;
	cout<<"enter name of tablet: ";
	cin>>med_name;
	cout<<"enter name of company: ";
	cin>>comp_name;
	cout<<"enter expiry month :";
	cin>>expmonth;
	cout<<"enter expiry year:";
	cin>>expyr;
	cout<<"manufactuing date";
	cin>>manudate;
	cout<<"enter manu month :";
		cin>>manumnth;
		cout<<"enter manu year:";
		cin>>manuyr;

	cout<<"enter price:";
	cin>>price;
	temp=new tablet(code,type,comp_name,med_name,expmonth,expyr,manudate,manumnth,manuyr,price); //assign new node to temp
	if(head==NULL)
			{
				head=temp;
			}
			else
			{
				ptr=head;
				while(ptr->next!=NULL)
				{
				ptr=ptr->next;
				}
				ptr->next=temp;
			    temp->prev=ptr;
			}
			cout<<"if you want to add more node enter y else enter n "<<endl;
			cin>>ans;
}while(ans=='y');
}
void shopkeeper::display_tab_details()
{
	tablet *ptr;
	 ptr=head;

	while(ptr!=NULL)
	{
		cout<<"code:";
		cout<<ptr->code<<"\n";
		cout<<"tablet name:"<<ptr->med_name<<"\n";
		cout<<"company name:"<<ptr->comp_name<<"\n";
        cout<<"price:"<<ptr->price<<"\n";
        cout<<"expiry :"<<ptr->expmonth<<"/"<<ptr->expyr<<"\n";
        //cout<<"contents:"<<"\n";
		ptr=ptr->next;
	}


}
void shopkeeper::add_tab()
{
	tablet *temp,*cur,*next,*prev;
	next=NULL;
	prev=NULL;
	accept_tab_details();
	cur=head;
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->next=temp;
	temp->prev=cur;

}
class customer
{

	char cust_name[20];
			int age;
			long mo_no;
			char doc_ref[30];

public:
		void bill(shopkeeper s);
		void display_bill();
		customer(char cn[20],int a,long mn,char doc[30])
		{
			strcpy(cust_name,cn);
			age=a;
			mo_no=mn;
			strcpy(doc_ref,doc);
		}
};
void customer::bill(shopkeeper s)
{
	char ans1;
	char ans;
	tablet *temp;
	customer *temp1;
			tablet *ptr,*cur;
			tablet *head,*next,*prev;
			next=NULL;
			prev=NULL;

		char cust_name[30];
		long mo_no;
		char doc_ref[30];
		int cust_age,flag=0;
		char type[10],med_name[10];
		do
		{
			float bill_med=0;
		cout<<"enter name of customer";
		cin>>cust_name;
		cout<<"enter age of customer: ";
cin>>cust_age;
		cout<<"enter mobile number :";
			cin>>mo_no;
			cout<<"enter reference doctor name :";
			cin>>doc_ref;
temp1=new customer(cust_name,age,mo_no,doc_ref);
{
	do
	{

		cout<<"enter name of medicine : ";
		cin>>med_name;
		cur=s.head;
		while(strcmp(med_name,cur->med_name)&&cur!=NULL)
		{
                cur=cur->next;
		}
		if(cur==NULL)
		{
			cout<<"not found";
		}
		else
{
			temp=new tablet(type,med_name); //assign new node to temp
			if(head==NULL)
					{
						head=temp;
					}
					else
					{
						ptr=head;
						while(ptr!=NULL)
						{
						ptr=ptr->next;
						}
						ptr->next=temp;
					    temp->prev=ptr;

					} bill_med=bill_med+cur->price;
}

					cout<<"if you want to add more tablets enter y else enter n "<<endl;
									cin>>ans1;
		}while(ans1=='y');
cout<<bill_med;
}

	if(head==NULL)
{
	head=temp;
}
else
{
	ptr=head;
	while(ptr!=NULL)
	{
	ptr=ptr->next;
	}
	ptr->next=temp;
    temp->prev=ptr;
}
cout<<"if you want to add more customer enter y else enter n "<<endl;
				cin>>ans1;
}while(ans=='y');

}



int main()
{
	shopkeeper s;
	int ch;
    char cn[20];
	int a=0;
	long mn=0;
	char doc[30];
    cout<<"accept";
	s.accept_tab_details();
	cout<<"\n display";
	s.display_tab_details();
    customer c(cn,a,mn,doc);
	c.bill(s);

	return 0;
}




































