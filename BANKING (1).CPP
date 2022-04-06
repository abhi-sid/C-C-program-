#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
#include<iomanip.h>


class menus
{
	public:
		void showmenu(void);
	private:
		void closemenu(void);
};


class disprecords
{
	public:
		void  adddetails(int,char name[30],char address[60],float);
		void  displaycustomers(void);
		void  deleteaccount(int);
		void  updatebalance(int,float);
		void  updatecustomer(void);
		int   lastaccount(void);
		int   accountexists(int);
		char  *getname(int);
		char  *getaddress(int);
		float getbalance(int);
		int   getrecord(int);
		void  display(int);
		void  displaylist(void);
		int   accountnumber;
		char  name[50],address[50];
		float intbalance;

};

class accounttransactions
{
	public:
				void  new_account(void);
				void  closeaccount(void);
				void  display_account(void);
				void  transaction(void);
				void  adddetails(int,int,int,int,char,char typetransaction[15],float,float,float);
				void  deleteaccount(int);
				int   datediffer(int,int,int,int,int,int);
				float getinterest(int,float);
				void  display(int);
				void  showaccount(int);
				int   accountnumber;
				char  trantype[10];
				int   dday,mmonth,yyear;
				char  transactions;

//withdrawl of account

				float intinterest,intamount,intbalance;
				static float calcinterest;
				void showinterest(void);
};

void menus::showmenu(void)
{
	char choice;
	while(1)
	{

		system("cls");//clrscr()
		cout<<"\n   ----welcome to banking system application-    \n";
		cout<<"********************************************************\n\n";
		cout<<"     choose from options\n";
		cout<<"     1:open an account\n";
		cout<<"     2:view an account\n";
		cout<<"     3:show all accounts\n";
		cout<<"     4:make a transaction\n";
		cout<<"	    5:calculate interest\n";
		cout<<"	    6:close an account\n";
		cout<<"	    7:exit\n\n";
		cout<<"	please select a choice:";
		choice=getche();

				if(choice=='1')
				{
					accounttransactions objat;
					objat.new_account();
				}
				else
				if(choice=='2')
				{
					accounttransactions objat;
					objat.display_account();
				}
				else
				if(choice=='3')
				{
					disprecords newrec;
					newrec.displaycustomers();
				}
				else
				if(choice=='4')
				{
					accounttransactions objat;
					objat.transaction();
				}
				else
				if(choice=='5')
				{
					accounttransactions objat;
					objat.showinterest();
				}
				else
				if(choice=='6')
				{
					closemenu();
				}
				else
				if(choice=='7')
				{
					cout<<"\n   Thanks for using this application.please press any key to exit\n";
					getch();
					break;
				}
			}
}


void menus::closemenu(void)
{
	char choice;
	while(1)
	{
			system("cls");//clrscr()
			cout<<"    -close menu   \n";
			cout<<"    **********************\n";
			cout<<"	1:close/delete an account\n";
			cout<<" 0:exit from this menu\n\n";
			cout<<"select a choice : ";
			choice=getche();

					if(choice=='1')
					{
						accounttransactions at;
						at.closeaccount();
						break;
					}
					else
					if(choice=='0')
					{
						cout<<"\n		you have entered 0 to go back to the previous menu.\n";
						getch();
						break;
					}
	 }
}

int disprecords::lastaccount(void)
{
	fstream filename;
	filename.open("newrecords.dat",ios::in);
	filename.seekg(0,ios::beg);
	int count=0;
	while(filename.read((char*)this,sizeof(disprecords)))
				count=accountnumber;
	filename.close();
	return count;
}

int disprecords::getrecord(int retrieve_accno)
{
	fstream filename;
	filename.open("newrecords.dat",ios::in);
	filename.seekg(0,ios::beg);
	int count=0;
	while(filename.read((char*)this,sizeof(disprecords)))
	{
		count++;
		if(retrieve_accno==accountnumber)
				break;
	}
		filename.close();
		return count;
	}
	//newrecords.dat file
void disprecords::display(int retrieve_accno)
{
	int record;
	record = getrecord(retrieve_accno);
	fstream filename;
	filename.open("newrecords.dat", ios::in);
	filename.seekg(0,ios::end);
	int location;
	location = (record) * sizeof(disprecords);
	filename.seekp(location);

	while (filename.read((char*)this,sizeof(disprecords)))
	{
			if(retrieve_accno == accountnumber)
			{
					cout<<endl<<"account no. "<<accountnumber;
					cout<<endl<<"name : "<<name;
					cout<<endl<<"address :"<<address;
					cout<<endl<<"balance :"<<intbalance;
					break;
			}
	}
	filename.close();
}

char *disprecords :: getname(int retrieve_accno)
{
		fstream filename;
		filename.open("newrecords.dat", ios::in);
		filename.seekg(0,ios::beg);
		char retrieve_custname[30];

				while (filename.read((char*)this,sizeof(disprecords)))
				{
						if(accountnumber == retrieve_accno)
						{
								strcpy(retrieve_custname,name);
						}
				}
				filename.close();
				return retrieve_custname;
}

char *disprecords :: getaddress(int retrieve_accno)
{
		fstream filename;
		filename.open("newrecords.dat", ios::in);
		filename.seekg(0,ios::beg);
		char retrieve_address[60];

				while (filename.read((char*)this,sizeof(disprecords)))
				{
						if(accountnumber == retrieve_accno)
						{
								strcpy(retrieve_address,address);
						}
				}
				filename.close();
				return retrieve_address;
}

float disprecords :: getbalance(int retrieve_accno)
{
		fstream filename;
		filename.open("newrecords.dat", ios::in);
		filename.seekg(0,ios::beg);
		float ibalance;

				while (filename.read((char*)this,sizeof(disprecords)))
				{
						if(accountnumber == retrieve_accno)
						{
								ibalance = intbalance;
						}
				}
				filename.close();
				return ibalance;
}
//------------------------------------------

int disprecords :: accountexists(int retrieve_accno)
{
		fstream filename;
		filename.open("newrecords.dat", ios::in);
		filename.seekg(0,ios::beg);
		int count = 0;

				while (filename.read((char*)this,sizeof(disprecords)))
				{
						if(accountnumber == retrieve_accno)
						{
								count = 1;
								break ;
						}
				}
				filename.close();
				return count;
}

//-------------------------------------
void disprecords :: displaylist()
{
		cout<<"                           ";
		cout<<"                           "<<endl;
		int    day1,month1,year1;
		struct date dateval;
		getdate(&dateval);
		day1   = dateval.da_day;
		month1 = dateval.da_mon;
		year1  = dateval.da_year;
		cout<<endl<<"Date: "<<day1 <<"/" <<month1 <<"/" <<year1<<endl;
		cout<<setw(80)<<"______________________________________"<<endl;
		cout<<setw(23)<<"ACCOUNT NO.";
		cout<<setw(23)<<"NAME OF THE PERSON";
		cout<<setw(23)<<"BALANCE"<<endl;
		cout<<setw(80)<<"______________________________________"<<endl;
}

//----------------------------------------

void disprecords :: displaycustomers(void)
{
		system("cls");//clrscr()
		int len1;
		int row=8, check;
		fstream filename;

		FILE * pfile;
		pfile = fopen("newrecords.dat","r");
		if(pfile == NULL)
		{
				cout<<endl<<"no account exists. please go back to the previous menu."<<endl;
					getch();
					return;

		}
		else
		{
		displaylist();
		filename.open("newrecords.dat", ios::in);
		filename.seekg(0,ios::beg);
		while (filename.read((char*)this,sizeof(disprecords)))
		{
					check = 0;

					cout.fill(' ');
					cout<<setw(20);
					cout.setf(ios::right,ios::adjustfield);
					cout<<accountnumber;
					cout.fill(' ');
					cout<<setw(25);
					cout.setf(ios::internal,ios::adjustfield);
					cout<<name;

					cout<<setw(23);
					cout.setf(ios::right,ios::adjustfield);
					cout<<intbalance<<endl;
					row++;
					if(row == 23)
					{
							check = 1;
							row   = 8;
							cout<<"\n\n continue the application..."<<endl;
							getch();
							system("cls");//clrscr()
							displaylist();
					}
		}
}
filename.close();
if(!check)
	{

			cout<<"\n\n continue the application..."<<endl;
			getch();
	}
}

//--------------------------------------

void disprecords :: adddetails(int retrieve_accno, char retrieve_custname[30],char retrieve_address[60], float ibalance)
{
		accountnumber = retrieve_accno ;
		strcpy(name,retrieve_custname) ;
		strcpy(address,retrieve_address) ;
		intbalance = ibalance;
		fstream filename;
		filename.open("newrecords.dat", ios::out | ios::app);
		filename.write((char*)this,sizeof(disprecords));
		filename.close();
}

//------------------------------

void disprecords :: deleteaccount(int retrieve_accno)
{
		fstream filename;
		filename.open("newrecords.dat", ios::in);
		fstream temp;
		temp.open("calculations.txt", ios::out);
		filename.seekg(0,ios::beg) ;
		while (!filename.eof() )
		{
				filename.read((char*)this,sizeof(disprecords));
				if(filename.eof())
						break;
				if( accountnumber != retrieve_accno)
						temp.write((char*)this,sizeof(disprecords));
		}
		filename.close();
		temp.close();
		filename.open("newrecords.dat", ios::out) ;
		temp.open("calculations.txt", ios::in) ;
		temp.seekg(0,ios::beg) ;
		while (!temp.eof() )
		{
				temp.read((char*)this,sizeof(disprecords));
						if(temp.eof())
							break;
						filename.write((char*)this,sizeof(disprecords));
		}
		filename.close();
		temp.close();
}

//---------------------------------

void disprecords :: updatebalance(int retrieve_accno, float ibalance)
{
	int record ;
	record = getrecord(retrieve_accno);
	fstream filename;
	filename.open("newrecords.dat", ios::out | ios::ate);
	intbalance = ibalance;
	int location;
	location = (record-1) * sizeof(disprecords);
	filename.seekp(location);
	filename.write((char*)this,sizeof(disprecords));
	filename.close();
}

//-----------------------------

void accounttransactions :: adddetails(int retrieve_accno, int day1, int month1, int year1, char t_tran, char typetransaction[10], float interest_accured, float t_amount, float ibalance)
{
	 fstream filename;
	 filename.open("transactions.dat", ios::app);
	 accountnumber = retrieve_accno ;
	 dday   = day1;
	 mmonth = month1;
	 yyear  = year1;
	 transactions = t_tran;
	 strcpy(trantype,typetransaction);
	 intinterest = interest_accured;
	 intamount = t_amount;
	 intbalance = ibalance;
	 filename.write((char*)this,sizeof(accounttransactions));
	 filename.close();
}

//--------------------------------------------

void accounttransactions :: deleteaccount(int retrieve_accno)
{

	 fstream filename;
	 filename.open("transactions.dat", ios::in);
	 fstream temp;
	 temp.open("calculations.txt", ios::in) ;
	 filename.seekg(0,ios::beg) ;
	 while (!filename.eof() )
		{
				filename.read((char*)this,sizeof(accounttransactions));
				if(filename.eof())
						break;
				if( accountnumber != retrieve_accno)
						temp.write((char*)this,sizeof(accounttransactions));
		}
		filename.close();
		temp.close();
		filename.open("transactions.dat", ios::out);
		temp.open("calculations.txt", ios::in) ;
		temp.seekg(0,ios::beg) ;
		while (!temp.eof() )
		{
				temp.read((char*)this,sizeof(accounttransactions));
				if(temp.eof())
						break;
				filename.write((char*)this,sizeof(accounttransactions));
		}
		filename.close();
		temp.close();
}

//-----------------------------

void accounttransactions :: new_account(void)
{
	char choice;
	int i, check;
	system("cls");//clrscr()
	disprecords newrec ;
	cout<<"         Please press 0 to go back to previous menu,"<<endl;
	cout<<"                                                   "<<endl;
	cout<<"         -open a new bank account-                 "<<endl;
	cout<<"         *************************"<<endl;
	int    day1, month1, year1;
	struct date dateval;
	getdate(&dateval);
	day1   = dateval.da_day;
	month1 = dateval.da_mon;
	year1  = dateval.da_year;
	int retrieve_accno;
	retrieve_accno = newrec.lastaccount();
	retrieve_accno++;

	if(retrieve_accno == 1)
	{
			newrec.adddetails(retrieve_accno,"Ravi","Delhi",1.1);
			newrec.deleteaccount(retrieve_accno);
			adddetails(retrieve_accno,1,1,1997,'D',"Default value",1.1,1.1,1.1);
			deleteaccount(retrieve_accno);
	}
	char retrieve_custname[30], tran_acc[10], retrieve_address[60];
	float t_bal, ibalance;
	cout<<"          Date : "<<day1<<"/" <<month1 <<"/"<<year1<<endl;
	cout<<"          Account no. # "<<retrieve_accno;
	do
	{
			cout<<"\n\n  please enter the name of the account holder     :";
			check = 1;
			gets(retrieve_custname);
			if (retrieve_custname[0] =='0')
			{
						cout<<"\n\t  Invalid customer name.";
						getch();
						return;
			}
			strupr(retrieve_custname);
			if (strlen(retrieve_custname) == 0 || strlen(retrieve_custname) > 30)
			{
					check = 0;
					cout<<"\n\t  Customer name is either blank or greater than 30 characters"<<endl;
					getch();
			}
}
while(!check);

do
{
		cout << endl<< "     Please enter the account holder's address :";
		check = 1;
		gets(retrieve_address);
		if (retrieve_address[0] == '0')
		{
				cout<<"\n\t  Invalid customer address.";
				getch();
				return;
		}
			strupr(retrieve_address);
			if (strlen(retrieve_address) == 0 || strlen(retrieve_address) > 60)
			{
					check = 0;
					cout<<"\n\t  Customer address is either blank or its length is greater than 60 characters."<<endl;
					getch();
			}
}while(!check);

do
{
		char chr_verifyingperson[30];
		cout <<endl<<"          Please enter the Name of the Verifying Person of the Account Holder : ";
		check = 1;
		gets(chr_verifyingperson);
		if(chr_verifyingperson[0]=='0')
		{
				cout<<"\n\t	Invalid Verifying Person Name.";
				getch();
				return;
}
strupr(chr_verifyingperson);
	if(strlen(chr_verifyingperson)<1||strlen(chr_verifyingperson)>30)
	{
		check=0;
		cout<<"\t\n The Verifying Person's Name is either blank or greater than 30 characters. Please try again.\n";
		getch();
	}
}while(!check);

do
{
	cout<<"\n Please enter the Deposit Amount while opening a New Account :";
	check=1;
	gets(tran_acc);
	t_bal=atof(tran_acc);
	ibalance=t_bal;
	if(strlen(tran_acc)<1)
	{
			cout<<"\n Invalid Transaction value. Exiting form the current Menu.\n";
			getch();
			return;
	}
	if(ibalance < 1000)
	{
			check=0;
			cout<<"\t\n The Minimum Deposit Amount should be' Rs.1000'. Please try again. \n";
			getch();
	}
}while(!check);

do
{
		cout<<"\n Do you want to save the record?(y/n):";
		choice=getche();
		choice=toupper(choice);
}
while(choice!='N' && choice!='Y');
		if(choice=='N' || choice=='n')
		{
			cout<<"\n The Customer Account is not created\n. Please continue with the application.\n";
			getch();
			return;
		}
		float t_amount,interest_accured;
		t_amount=ibalance;
		interest_accured=0.0;
		char t_tran,typetransaction[10];
		t_tran='D';
		strcpy(typetransaction," ");

		newrec.adddetails(retrieve_accno,retrieve_custname,retrieve_address,ibalance);
		adddetails(retrieve_accno,day1,month1,year1,t_tran,typetransaction,interest_accured,t_amount,ibalance);
		cout<<"\n\n	The New Account is successfully created.\n Please continue with the application.\n";
		getch();
}

//----------------------------

void accounttransactions::showaccount(int retrieve_accno)
{
		cout<<"							\n";
		cout<<"							\n";
		int day1,month1,year1;
		struct date dateval;
		getdate(&dateval);
		day1  =dateval.da_day;
		month1=dateval.da_mon;
		year1 =dateval.da_year;
		cout<<"Date:"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
		cout<<"Account no."<<retrieve_accno;
		disprecords newrec;

		char retrieve_custname[30];
		strcpy(retrieve_custname,newrec.getname(retrieve_accno));
		char retrieve_address[60];
		strcpy(retrieve_address,newrec.getaddress(retrieve_accno));

		cout<<setw(25)<<"\n Account Holder's Name:"<<retrieve_custname;
		cout<<"\nAddress	            :	         "<<retrieve_address<<"\n";
		cout<<setw(80)<<"\n----------------------------------\n";
		cout<<setw(10)<<"Dated";
		cout<<setw(12)<<"Details";
		cout<<setw(15)<<"Deposited";
		cout<<setw(12)<<"Withdrawn";
		cout<<setw(10)<<"	        ";
		cout<<setw(80)<<"Balance";
		cout<<setw(80)<<"\n------------------------------\n";
}

//-----------------------------

void accounttransactions::display_account(void)
{
	system("cls");//clrscr()
	char t_acc[10];
	int tran_acc,retrieve_accno;
	disprecords obj2;
	cout<<"		Press 0 to go back to previous menu\n";
	cout<<"		Please enter Account No. you want to view:";
	gets(t_acc);
	tran_acc=atoi(t_acc);
	retrieve_accno=tran_acc;
	if(retrieve_accno==0)
	{
		cout<<"\n	You have pressed 0 to exit\n";
		getch();
		return;
	}
	system("cls");//clrscr()
	disprecords newrec;
	accounttransactions aa;
	int row=8,check;
	fstream filename;

	FILE * pfile;
	pfile=fopen("newrecords.dat","r");
	if(pfile==NULL)
	{
		cout<<"\n No such Account Exists. Please create a New Account. \n";
		getch();
		return;
	}
	else if(!newrec.accountexists(retrieve_accno))
	{
		cout<<"\t\n	Account does not exist.\n";
		getch();
		return;
	}
	else
	{
	showaccount(retrieve_accno);
	filename.open("transactions.dat",ios::in);

	while(filename.read((char*)this,sizeof(accounttransactions)))
	{
		if(accountnumber==retrieve_accno)
		{
			check=0;
			cout<<setw(3)<<dday<<"/"<<mmonth<<"/"<<yyear;
			cout<<setw(10)<<trantype;
			if (transactions=='d')
			{
				cout.setf(ios::right,ios::adjustfield);
				cout<<setw(15);
				cout<<intamount;
				cout<<setw(20);
				cout<<"	";
			}
			else
			{
				cout.setf(ios::right,ios::adjustfield);
				cout<<setw(25);
				cout<<intamount;
				cout<<setw(10);
				cout<<"	";
			}
			cout<<setw(15);
			cout.setf(ios::right,ios::adjustfield);
			cout<<intbalance<<"\n";
			row++;

			if(row==23)
			{
				check=1;
				row=8;
				cout<<"\n\n Please continue with the application."<<"\n";
				getch();
				system("cls");//clrscr()
				showaccount(retrieve_accno);
			}
		}
	}
}
filename.close();
	if(!check)
	{
		cout<<"\n\n	Press any key to continue with the application\n";
		getch();
	}
}

//------------------------------------

int accounttransactions::datediffer(int day1,int month1,int year1,int day2,int month2,int year2)
{
	static int montharr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int days=0;
	while(day1!=day2 || month1!=month2 || year1!=year2)
	{
	days++;
	day1++;
		if(day1>montharr[month1-1])
		{
			day1=1;
			month1++;
		}
		if(month1>12)
		{
			month1=1;
			year1++;
		}
	}
	return days;
}

//---------------------------------

float accounttransactions::getinterest(int retrieve_accno,float ibalance)
{
	fstream filename;
	filename.open("transactions.dat",ios::in);
	disprecords newrec;
	filename.seekg(0,ios::beg);
	int day1,month1,year1,month_day;
	while(filename.read((char*) this,sizeof(accounttransactions)))
	{
		if(accountnumber==retrieve_accno)
		{
			day1=dday;
			month1=mmonth;
			year1=yyear;
			ibalance=newrec.getbalance(retrieve_accno);
			break;
		}
	}
	int day2,month2,year2;
	struct date dateval;
	getdate(&dateval);
	day2=dateval.da_day;
	month2=dateval.da_mon;
	year2=dateval.da_year;
	float interest_accured=0.0;
	int yeardiff=year2-year1;

	if((year2<year1) || (year2==year1 && month2<month1) || (year2==year1 && month2==month1 && day2<day1))
	{
		return interest_accured;
	}
	month_day=datediffer(day1,month1,year1,day2,month2,year2);
	int months;
		if(month_day>=30)
		{
			months=month_day/30;
		}
		else
		{
			months=month_day/30;
		}
		if(interest_accured==0 && yeardiff==1)
		{
			interest_accured=((ibalance*0.5)/100)*(months);
		}
		else if(yeardiff>1 && yeardiff<25 && interest_accured==0)
		{
			interest_accured=((ibalance*0.5)/100)*(months);
		}
		else
		{
			interest_accured=0;
		}
	filename.close();
	return interest_accured;
}

//---------------------------

void accounttransactions::showinterest(void)
{
	system("cls");//clrscr()
	char t_acc[10];
	int tran_acc,retrieve_accno,check;
	cout<<strupr("\n	important information:interest should be generated only \n once in a year.\n\n\t if you have already generated interest for an account,\n\t please ignore that account\n\t.thank you.\n");
	cout<<"\n	Press 0 to go back to previous menu\n";
	cout<<"\n	to view the transactions of the account,please enter it:";
	gets(t_acc);
	tran_acc=atoi(t_acc);
	retrieve_accno=tran_acc;
	if(retrieve_accno==0)
			return;
	system("cls");//clrscr()
	disprecords newrec;
		if(!newrec.accountexists(retrieve_accno))
		{
			cout<<"\t\n	Account does not exist.\n";
			getch();
			return;
		}
		cout<<"		Press 0 to go back to previous menu\n";
		cout<<"						    \n";
		cout<<endl<<"    -Please enter the Account no. to generate interest- "<<endl;
		cout<<"***********************************************\n";
		int day1,month1,year1;
		struct date dateval;
		getdate(&dateval);
		day1=dateval.da_day;
		month1=dateval.da_mon;
		year1=dateval.da_year;
		cout<<"		Date:"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
		cout<<"		Account no."<<retrieve_accno<<"\n";
		char retrieve_custname[30];
		char retrieve_address[60];
		float ibalance;
		strcpy(retrieve_custname,newrec.getname(retrieve_accno));
		strcpy(retrieve_address,newrec.getaddress(retrieve_accno));
		ibalance=newrec.getbalance(retrieve_accno);

		cout<<"		Customer name:		"<<retrieve_custname;
		cout<<"\n	Customer Address:	"<<retrieve_address;
		cout<<"\n 	Bank Balance:		"<<ibalance;

		float interest_accured;
		interest_accured=getinterest(retrieve_accno,ibalance);
		cout<<"\n\tInterest generated:		"<<interest_accured;
		getch();
		ibalance=ibalance+interest_accured;
		disprecords obj2;
		obj2.updatebalance(retrieve_accno,ibalance);
		adddetails(retrieve_accno,day1,month1,year1,'d',"interest",interest_accured,interest_accured,ibalance);
}

//--------------------------------------------------

void accounttransactions::transaction(void)
{
	system("cls");//clrscr()
	char t_acc[10];
	int tran_acc,retrieve_accno,check;
	cout<<"  Press 0 to go back to previous menu.\n";
	cout<<"  To view the transaction of the acccount,please enter it:";
	gets(t_acc);
	tran_acc=atoi(t_acc);
	retrieve_accno=tran_acc;
		if(retrieve_accno==0)
			return;
	system("cls");//clrscr()
	disprecords newrec;
		if(!newrec.accountexists(retrieve_accno))
		{
			cout<<"\t\n account does not exist.\n";
			getch();
			return;
		}
	cout<<"  press 0 to go back to previous menu.\n";
	cout<<"                                           \n";
	cout<<"\n -make correct entry for the transaction below-\n";
	cout<<"***************************************\n";
	int day1,month1,year1;
	struct date dateval;
	getdate(&dateval);
	day1=dateval.da_day;
	month1=dateval.da_mon;
	year1=dateval.da_year;
	cout<<"  date:"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
	cout<<"  account no."<<retrieve_accno<<"\n";
	char retrieve_custname[30];
	char retrieve_address[60];
	float ibalance;
	float interest_accured=0.0;
	strcpy(retrieve_custname,newrec.getname(retrieve_accno));
	strcpy(retrieve_address,newrec.getaddress(retrieve_accno));
	ibalance=newrec.getbalance(retrieve_accno);
	cout<<"  customer name:"<<retrieve_custname;
	cout<<"\ncustomer address:"<<retrieve_address;
	cout<<"\nbank balance:"<<ibalance;
	char trandetails,typetransaction[10],tm[10];
	float t_amount,t_amt;

	do
	{
		cout<<"\n please enter d for deposit or w for withdrawal of amount:";
		trandetails=getche();
		if(trandetails=='0')
		{
			cout<<"\n\n you have pressed 0 to exit";
			getch();
			return;
		}
		trandetails=toupper(trandetails);
	}
	while(trandetails!='W' && trandetails!='D');

	do
	{
		cout<<"\n the transaction type is either cash or cheque. .\n";
		check=1;
		cout<<" (cash/cheque):";
		gets(typetransaction);
		strupr(typetransaction);
			if(typetransaction[0]=='0')
			{
				cout<<"\n\n you have pressed 0 to exit";
				getch();
				return;
			}
			if (strlen(typetransaction)<1|| (strcmp(typetransaction,"CASH") && strcmp(typetransaction,"CHEQUE")))
			{
				check=0;
				cout<<"\n the transaction is invalid.please enter in cheque or cash.\n";
				getch();
			}
}
while(!check);
do
{
cout<<"\n  please enter the transaction amount:  \n";
check=1;
cout<<"\n";
cout<<"  amount: Rs.";
gets(tm);
t_amt=atof(tm);
t_amount=t_amt;
if(t_amount<1 || (trandetails=='w' && t_amount>ibalance))
{
check=0;
cout<<"\n either amount is not a numeric value or\n it is blank or\n you are trying to withdraw more amount than in account. . . \n";
getch();
}
}while(!check);
char choice;

do
{

cout<<"\n save changes made in transaction details?(y/n)";
choice=getche();
choice=toupper(choice);
}
while(choice!='N'&& choice!='Y');
if(choice=='N'&& choice=='n')
{
cout<<"\n transaction is not saved";
getch();
return;
}
if(trandetails=='d')
{
cout<<"\n  the amount is deposited in the bank";
getch();
ibalance=ibalance+t_amount;
}
else
{
cout<<"\n the amount is withdrawn from the bank\n";
getch();
ibalance=ibalance-t_amount;
}
newrec.updatebalance(retrieve_accno,ibalance);
adddetails(retrieve_accno,day1,month1,year1,trandetails,typetransaction,interest_accured,t_amount,ibalance);
}

//------------------------------------------------------

void accounttransactions::closeaccount(void)
{
system("cls");//clrscr()
char t_acc[10];
int tran_acc,retrieve_accno;
cout<<"\n press 0 to go back to previous menu\n";
cout<<"\n please enter the account you want to close : ";
gets(t_acc);
tran_acc=atoi(t_acc);
retrieve_accno=tran_acc;
system("cls");//clrscr()
disprecords newrec;
if(!newrec.accountexists(retrieve_accno))
{
cout<<"\n you have entered invalid account or it doesn't exists\n";
cout<<"\n please try again\n";
getch();
return;
}
cout<<"\n press 0 to go to previous menu \n";
cout<<"\n closing this account\n";
cout<<"\n ************************\n";
int day1,month1,year1;
struct date dateval;
getdate(&dateval);
day1=dateval.da_day;
month1=dateval.da_mon;
year1=dateval.da_year;

cout<<"\n date "<<day1<<"/"<<month1<<"/"<<year1<<"\n";
char choice;
newrec.display(retrieve_accno);

do
{
cout<<"\n are you sure you want to close this account ?(y/n)";
choice=getche();
choice=toupper(choice);
}
while(choice!='N'&& choice!='Y');

if(choice=='N'|| choice=='n')
{
cout<<"\n this account is not closed\n";
getch();
return;
}
newrec.deleteaccount(retrieve_accno);
deleteaccount(retrieve_accno);
cout<<"\t\n\n rtecord deleted succesfully\n";
cout<<"\n  please continue with the application . . . \n";
getch();
}

int login(void)
{
char username[9],ch;
char username1[]="banking";
int i=0;
char a,b[9],pass[]="banking";
cout<<"\n\\t\t\tWelcome to Banking System";
cout<<"\n\n\t\t   Developed by: Abhisek Siddhartha Ghosh";
cout<<"\n\\n\tClass : XII     Sec : A        Roll : 12    ";
cout<<"\n\n\n\t\tS U D H I R    M E M O R I A L   I N S T I T U T E ";

cout<<"\n\npress any key to continue...";
getch();
system("cls");
cout<<"\n \t login to the banking application.\n";
cout<<"\t**********************************\n";
cout<<"\n\n enter username:";
cin>>username;
cout<<"\n \n\t please enter password to authenticate yourself:";
fflush(stdin);

do
{
ch=getch();
if(isalnum(ch))
{
b[i]=ch;
cout<<"*";
i++;
}
else
if(ch=='\r')
b[i]='\0';
else if(ch=='\b')
{
i--;
cout<<"\b\b";
}
}
while(ch!='\r');
b[i]='\0';
fflush(stdin);

if((strcmp(b,pass)==0)&&(strcmp(username1,username)==0))
{
cout<<"\n \n\t you have entered succesfully";
return(1);
}
else
{
cout<<"\n incorrect username or password";
cout<<"\n ";
return(0);
}
}

int main(void)
{
system("cls");//clrscr()
int val,ch;
a:val=login();
if(val==0)
{
cout<<"\n \t want to try again ";
cout<<"\t  1.try again";
cout<<"\t  2.exit";
cout<<"\n enter your choice and press enter";
cin>>ch;
if(ch==1)
{
system("cls");//clrscr()
goto a;
}
else
{
exit(0);
}
}
menus obj1;
obj1.showmenu();
return 0;
}
