#include <bits/stdc++.h>
using namespace std;

class employee
{
	int id;
	char name[50];
	char designation;
	int exp,age,salary,HRA=25,PF=10,Tax=10, gross,mealA=20,transA=20;
	int workingHours;
	int DA=20;
public:
  void calculate();	//function to calculate grade
	void getdata();		//function to accept data from user
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
  void salary_slip();
	int retid() const;
	int retgross() const;
}; 
void employee::calculate()
{
  gross=(salary+HRA+DA+mealA+transA)-(Tax+PF);
  cout<<gross<<endl;
}
void employee::salary_slip()
{
	cout<<"=========================================";
  cout<<"\nID of the employee :                      "<<id;
	cout<<"\nName of employee :                    "<<name;
	cout<<"\nSalary of the employee :             "<<salary;
	cout<<"\n Working hours of the employee :"<<workingHours;
  	cout<<"\n  Tax for the employee :                  "<<Tax;
	cout<<"\n HRA for the employee :                 "<<HRA;
	cout<<"\n DA for the employee :                     "<<DA;
	cout<<"\n Meal allowence for the employee : "<<mealA;
	cout<<"\n Transport allowence for the employee :"<<transA;
	cout<<"\n PF for the employee :                            "<<PF;
	cout<<"\n gross Salary of Employee :";
    calculate();
}

void employee::getdata()
{
	cout<<"\nEnter The id of the employee : ";
	cin>>id;
	cout<<"\n\nEnter The Name of employee :";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The Designation of employee :";
	cin>>designation;
	cout<<"\nEnter The experence of employee :";
	cin>>exp;
	cout<<"\nEnter The salary of employee :";
	cin>>salary;
	cout<<"\nEnter The working hours of employee : ";
	cin>>workingHours;
	cout<<"\nEnter The age of employee :";
	cin>>age;
	calculate();
}

void employee::showdata() const
{
	cout<<"\nID of the employee : "<<id;
	cout<<"\nName of employee : "<<name;
	cout<<"\nAge of the employee : "<<age;
	cout<<"\nDesignation of employee "<<designation;
	cout<<"\nExperience of the employee : "<<exp;
	cout<<"\nSalary of the employee : "<<salary;
	cout<<"\n Working hours of the employee :"<<workingHours;
}

void employee::show_tabular() const
{
	cout<<id<<setw(6)<<" "<<name<<setw(10)<<age<<setw(12)<<designation<<setw(14)<<exp<<setw(16)
		<<salary<<setw(18)<<workingHours<<endl;
}

int  employee::retid() const
{
	return id;
}

int employee::retgross() const
{
	return gross;
}

void Addtion_Employee();	//write the record in binary file
void display_all();	//read all records from binary file
void display_ep(int);	//accept rollno and read record from binary file
void modify_Employee(int);	//accept rollno and update record of binary file
void delete_Employee(int);	//accept rollno and delete selected records from binary file
void display_record();	//display all records in tabular format from binary file
void entry_menu();	//display entry menu on screen
void display_slip();

int main()
{
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); // program outputs decimal number to two decimal places
	do
	{
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. ENTRY MENU";
		cout<<"\n\n\t02. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-2) ";
		cin>>ch;
		switch(ch)
		{
			case '1': entry_menu();
				break;
			case '2':
				break;
			default :cout<<"\a";
		}
    }while(ch!='2');
	return 0;
}

void Addtion_Employee()
{
	employee st;
	ofstream outFile;
	outFile.open("employee.dat",ios::binary|ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(employee));
	outFile.close();
    	cout<<"\n\nEmployee record Has Been Created ";
	cin.ignore();
	cin.get();
}

void display_all()
{
	employee st;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(employee)))
	{
		st.showdata();
		cout<<"\n\n===================================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

void display_ep(int n)
{
	employee st;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(employee)))
	{
		if(st.retid()==n)
		{
	  		 st.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}
void display_slip(int n)
{
	employee st;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(employee)))
	{
		if(st.retid()==n)
		{
	  		 st.salary_slip();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}


void modify_Employee(int n)
{
	bool found=false;
	employee st;
	fstream File;
	File.open("employee.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
    	while(!File.eof() && found==false)
	{

		File.read(reinterpret_cast<char *> (&st), sizeof(employee));
		if(st.retid()==n)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of Employee"<<endl;
			st.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(st));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&st), sizeof(employee));
		    	cout<<"\n\n\t Record Updated";
		    	found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();
}

void delete_Employee(int n)
{
	employee st;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(employee)))
	{
		if(st.retid()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(employee));
		}
	}
	outFile.close();
	inFile.close();
	remove("employee.dat");
	rename("Temp.dat","employee.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}
void display_record()
{
	employee st;
	ifstream inFile;
	inFile.open("employee.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tALL THE EMPLOYEES RECORD \n\n";
	cout<<"========================================================================================\n";
	cout<<"ID       Name      AGE    DESIGNATION   EXPERINCE      SALARY           WORKING HOURS         "<<endl;
	cout<<"========================================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(employee)))
	{
		st.show_tabular();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}
void entry_menu()
{
	char ch;
	int num;
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE EMPLOYEE RECORD";
	cout<<"\n\n\t2.DISPLAY ALL EMPLOYEE RECORDS";
	cout<<"\n\n\t3.SEARCH EMPLOYEE RECORD ";
	cout<<"\n\n\t4.MODIFY EMPLOYEE RECORD";
	cout<<"\n\n\t5.DELETE EMPLOYEE RECORD";
	cout<<"\n\n\t6.SALARY SLIP OF EMPLOYEE";
	cout<<"\n\n\t7.BACK TO MAIN MENU";		
	cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
	cin>>ch;
	switch(ch)
	{
	case '1':	Addtion_Employee();break;
	case '2':	display_record();break;
	case '3':	cout<<"\n\n\tPlease Enter The ID of the Employee :"; cin>>num;
			display_ep(num); break;
	case '4':	cout<<"\n\n\tPlease Enter The ID of the Employee : "; cin>>num;
			modify_Employee(num);break;
	case '5':	cout<<"\n\n\tPlease Enter The ID of the Employee : "; cin>>num;
			delete_Employee(num);break;
	case '6': cout<<"\n\n\t Please Enter The ID of the Employee :";cin>>num;
	 display_slip(num);break;
	 case '7': break;
	default:	cout<<"\a"; entry_menu();
	}
}