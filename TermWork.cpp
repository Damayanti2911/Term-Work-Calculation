#include<iostream>
#include<fstream>
using namespace std;

class TermWork
{
	struct node
	{
		int rollNo;
		char name[20];
		int attendence;
		int unit_test[5];
		int stu_achievement;
		int mockPract;
		int Termwork;
	}s;
	public:
		void insert();
		void calculate();
		void display();
		void max_min();
		void modify();
	
};

void TermWork::insert()
{
	char mock,achievement;
	int ans,days,TotalAttendence;
	ofstream out;
	out.open("Student.txt",ios::out|ios::app);
	do{
	
	cout<<"\n\n\t  ==  Enter Details of Student  ==  \n\n ";
	cout<<"\t Enter Roll No: ";
	cin>>s.rollNo;
	cout<<"\t Enter Name: ";
	cin>>s.name;
	
	cout<<"\n\n\n\t  ==  Enter Score  ==  \n\n";
	cout<<"\t Enter Total days of Attendence : ";
	cin>>days;
	TotalAttendence=(days*100)/330;
	if(TotalAttendence>=75)
	{
		s.attendence=10;
	}
	else
	{
		s.attendence=0;
	}
	
	cout<<"\t Enter Unit Test marks: ";
	cout<<"\n\t\t DSA: ";
	cin>>s.unit_test[0];
    cout<<"\t\t Microprocessor: ";
	cin>>s.unit_test[1];
	cout<<"\t\t M3: ";
	cin>>s.unit_test[2];
	cout<<"\t\t Software Engineering: ";
	cin>>s.unit_test[3];
	cout<<"\t\t PPL: ";
	cin>>s.unit_test[4];
	
	cout<<"\t Is any student Achievement(20)? (yes-y/no-n)  ";
	cin>>achievement;
	if(achievement=='y')
	{
		s.stu_achievement=20;
	}
	else
	{
		s.stu_achievement=0;
	}
	cout<<"\t Is appear for mock Practical(40)? (yes-y/no-n) ";
	cin>>mock;
	if(mock=='y')
	{
		cout<<"\t\t Enter Marks obtained in Mock Practical: ";
		cin>>s.mockPract;
	}
	else
	{
		s.mockPract=0;
	}
	
	
	out.write((char *)&s,sizeof(s));
	
	cout<<"\n\nDo u want to store another Student data: (y-1/n-0)";
	cin>>ans;
	}
	
	while(ans==1);
	out.close();
}


void TermWork::display()
{
	int ut=0,avg_ut;
	ifstream in;
	in.open("student.txt",ios::in|ios::app);
	cout<<"\n\n\t  **** Display Data **** \n\n";
	while(in.read((char *)&s,sizeof(s)))
	{
		cout<<"\n\n Student data is: \n\tRoll No: "<<s.rollNo<<"\n\tName: "<<s.name<<endl;
		ut=s.unit_test[0]+s.unit_test[1]+s.unit_test[2]+s.unit_test[3]+s.unit_test[4];
		avg_ut=(30*ut)/150;
		cout<<"\n Detailed Score- ";
		cout<<"\n\t Attendence: "<<s.attendence<<"\n\t Unit Test: "<<avg_ut<<"\n\t Student Achievement: "<<s.stu_achievement<<"\n\t Mock Practical: "<<s.mockPract<<endl<<endl;
		
	}
	in.close();


}

void TermWork::calculate()
{
	int sum=0,total,ut=0,avg_ut;
	ofstream outfile;
	ifstream infile;
	
	outfile.open("Student.txt",ios::out|ios::app);
	infile.open("student.txt",ios::in|ios::app);
	
	while(infile.read((char *)&s,sizeof(s)))
	{
		ut=s.unit_test[0]+s.unit_test[1]+s.unit_test[2]+s.unit_test[3]+s.unit_test[4];
		avg_ut=(30*ut)/150;
		sum=s.attendence+avg_ut+s.stu_achievement+s.mockPract;
		s.Termwork=sum;
		total=sum/2;
		cout<<"\n\n\n\t\t ++++ Term Work ++++ \n";
		cout<<"\n\t Name: "<<s.name<<endl;
		cout<<"\n\t Term Work is- "<<total;
	}
	
	outfile.write((char *)&s,sizeof(s));
	infile.close();
	outfile.close();
}

void TermWork::max_min()
{
	int max=0,min=0;
	ifstream in;
	in.open("student.txt",ios::in|ios::app);
	
	while(in.read((char *)&s,sizeof(s)))
	{
		if(max<s.Termwork)
		{
			max=s.Termwork;
		}
		if(min>s.Termwork)
		{
			min=s.Termwork;
		}
		
	}
	
	cout<<"\n\n\t\t  ^^^^^  Highest TermWork Marks is "<<max/2<<" ^^^^^  \n";
	cout<<"\n\n\t\t  ^^^^^  Lowest TermWork Marks is "<<min/2<<" ^^^^^  \n";
}

void TermWork::modify()
{
	int rn,flag=0,cnt=0;
	long int loc;
	fstream file;
	cout<<"\n\nEnter Roll no to be modified: ";
	cin>>rn;
	file.open("student.txt",ios::in|ios::out|ios::app);
	while(file.read((char *)&s,sizeof(s)))
	{
		if(s.rollNo==rn)
		{
			cout<<"\n\nRecord is Found!!!\n";
			cout<<"\t"<<s.rollNo<<"\t"<<s.name<<"\t"<<s.Termwork<<"\n\n";
			loc=cnt*sizeof(s);
			file.seekp(loc,ios::beg);
			cout<<"\n\nEnter Updated Mock Prcatical Marks: ";
			cin>>s.mockPract;
			file.write((char *)&s,sizeof(s));
			flag=1;
			break;
		}
		else
		{
			cnt++;
		}
	}
	
	if(flag==0)
	{
		cout<<"\n\nRecord not Found!!!\n";
		
	}
	file.close();
	
}


int main()
{
	TermWork obj;
	int choice;
	while(true)
	{
	
	cout<<"\n\n  1. Add Record \n  2. Display Record \n  3. TermWork \n  4. Maximum & Minimum TermWork \n  5. Modify \n  6. Exit \n\n";
	cout<<"\t Enter Choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1: obj.insert(); break;
		case 2: obj.display(); break;
		case 3: obj.calculate(); break;
		case 4: obj.max_min(); break;
		case 5: obj.modify(); break;
		case 6: cout<<"\n\n\t Thank You !!!! \n "; return 0; break;
		default: cout<<"\n\n\t Choose Correct option !!\n\n "; break;	
	}
    }
    
	return 0;
}

