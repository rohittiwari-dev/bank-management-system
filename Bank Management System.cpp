//***************************************************************
//    					Headers File Used
//***************************************************************

#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<time.h>

using namespace std;

//***************************************************************
//    					Global Declaration
//***************************************************************

void showCust();
int main();
void Coose();
int getareapin();
int getmobno();
int getadhar();
char gettype();
int getmon();
char getadd();
char getname();
char getdate();

//***************************************************************
//    				class for Bank Registration
//***************************************************************
class Regis
{
	public:
	char B_name[20];
	int B_code;
	char B_IFSC[10];
	char Add[20];
	int A_pin;
	void Register()
	{
		system("cls");
		cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
		cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
		cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
		cout<<"\n\t\t\t\t\t\t      Bank Detail"<<endl;
		cout<<"\t\t\t\t\t\t     -------------"<<endl;

		fflush(stdin);
		cout<<"Enter the Bank Name"<<endl;
		gets(B_name);

		cout<<"\nEnter the Branch code"<<endl;
		cin>>B_code;

		fflush(stdin);
		cout<<"\nEnter the Address of the Bank"<<endl;
		gets(Add);

		fflush(stdin);
		cout<<"\nEnter the Bank IFSC Code"<<endl;
		gets(B_IFSC);

		cout<<"\nEnter Area Pin Code"<<endl;
		cin>>A_pin;
	}
	void R_show();//Show the IFSC,Branch code,Bank Name
}Reg;


//***************************************************************
//    			class Customer Inherites Regis
//***************************************************************

class Customer:public Regis
{
	public:
	char BankN[20];
	int BranchC;
	char IFSC[10];
	long int Acc_N;
	char date[10];
	char Cust_N[20];
	char Cust_Add[20];
	int Cust_Apin;
    __attribute__((unused)) int Cust_aadhar;
	char Acc_Type;
	float money;
	char mobile[10];
	void C_Acc(); // To Create Account
	void D_Mon(); // To Deposit Money
	void W_Mon(); // To Withdraw Money
	void B_Mon(); // for All Balance Details
	void B_Enq(); //for Each Balance Enquiry
	void Detail();	// to show detail of customer added in the registered branch
	void update();	// to update detail of customer
	void DeleteAcc();	//to delete account
}Cust;

//***************************************************************
//    	function to write in file Registration of Bank
//  					class Regis Function
//***************************************************************

void WReg()
{
	ofstream fil;
	Reg.Register();
	fil.open("Bank.dat",ios::binary);
	fil.write((char*)&Reg,sizeof(Regis));
	fil.close();
	cout<<"\n\nBank Registered successfully"<<endl;;
	cout<<"\n\nPress Any Key to Continue"<<endl;
	getch();
}


//***************************************************************
//    		Show the Value of IFSC,Bank Name,Branch Code
//  					class Regis Function
//***************************************************************

void Regis::R_show()
{
	ifstream frr;
	frr.open("Bank.dat",ios::binary);
	while(frr.read((char*)&Reg,sizeof(Regis)))
	{
		strcpy(Cust.BankN,B_name);
		Cust.BranchC=B_code;
		strcpy(Cust.IFSC,B_IFSC);
	};
	frr.close();
}



//***************************************************************
//    				Create new Account Function
//  					class Customer Function
//**************************************************************

void Customer::C_Acc()
{
	
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Create Account"<<endl;
	cout<<"\t\t\t\t\t\t   ----------------"<<endl;
	Reg.R_show();
	getdate();
	cout<<"Bank Name : "<<BankN<<endl;
	cout<<"Banch Code : "<<BranchC<<endl;
	cout<<"IFSC Code : "<<IFSC<<endl;
	cout<<"Account No. : "<<Acc_N<<endl;
	cout<<"Today's Date : "<<date<<endl;
	cout<<"\n\nEnter Name of Customer : "<<endl;
	getname();
	cout<<"\n\nEnter the of Customer Address (Enter only City ): "<<endl;
	getadd();
	cout<<"\n\nEnter Ammount to be Deposited (Minimum Ammount 100): "<<endl;
	money=getmon();
	cout<<"\n\nEnter 6 Digits Customer Area Pin : "<<endl;
	Cust_Apin=getareapin();
	cout<<"\n\nEnter 12 Digits Customer Aadhar No. (without any Space): "<<endl;
	Cust_aadhar=getadhar();
	cout<<"\n\nEnter Account Type 'S' for Saving and 'C' for Current A/c "<<endl;
	Acc_Type=gettype();
	cout<<"\n\nEnter 10 Digits Mobile no. (Indian Olny)"<<endl;
	getmobno();
	
}
void regc()
{
	Cust.Acc_N=1000;
	fstream fic,fii;
	fic.open("Customer.dat",ios::app|ios::out|ios::binary);
	fii.open("Customer.dat",ios::app|ios::in|ios::binary);
	if(fic.is_open())
	{
		fii.seekp(-1*sizeof(Cust),ios::end);
		if(fii.read((char*)&Cust,sizeof(Customer)))
		{
			Cust.Acc_N+=1;
			fii.seekp(ios::end);
		}
		Cust.C_Acc();
		cout<<"\n\nAccount Created"<<endl;
		fic.write((char*)&Cust,sizeof(Customer));
	}
	else
	cout<<"\nError in Adding Data to Database"<<endl;
	fic.close();
	fii.close();
}

//***************************************************************
//    				Create new Account Function
//  				  Input area pin Function
//**************************************************************
int getareapin()
{
	int num=0,ch,len=0;
	do
	{
		ch=getch();
		if(ch>=48&&ch<=57)
		{
			printf("%c",ch);
			num=num*10+(ch-48);
			len++;
		}
		else if (ch==8)
    	{
        	cout<<"\b \b";
        	num=num/10;
        	len--;
    	}
    	else if(num!=0&&ch==13&&len==6)
		{
        	break;         
    	}
    	if(len==6)
    	break;
	}while(1);
	return num;
}
//***************************************************************
//    				Create new Account Function
//  				 Input AAdhar no Function
//**************************************************************
int getmobno()
{
	char num[10],ch,ah='\0';
	int len=0;
	int i=0;
	do
	{
		ch=getch();
		
		if(ch>='0'&&ch<='9')
		{
			printf("%c",ch);
			num[i]=ch;
			i++;
			len++;
			ah=ch;
		}
		else if (ch==(char)8)
    	{
        	cout<<"\b \b";
        	i--;
        	len--;
    	}
    	else if(ah!='\0'&&ch==(char)13&&len==10)
		{
        	break;         
    	}
    	if(len==10)
    	{
    		break;
		}
	}while(1);
	num[i]='\0';
	strcpy(Cust.mobile,num);
}
//***************************************************************
//    				Create new Account Function
//  				Input Account Type Function
//**************************************************************
char gettype()
{
	char ch,num='\0';
	int len=0;
	do
	{
		ch=getch();
		if(ch=='S'||ch=='C'||ch=='s'||ch=='c')
		{
			printf("%c",toupper(ch));
			num=ch;
			len++;
		}
		else if (ch==(char)8)
    	{
        	cout<<"\b \b";
        	num='\0';
        	len--;
    	}
    	else if(num!='\0'&&ch==(char)13)
		{
        	break;         
    	}
    	if(len==1)
    	break;
	}while(1);
	toupper(num);
	return num;
}
//***************************************************************
//    				Create new Account Function
//  				 Input mobile no Function
//**************************************************************
int getadhar()
{
	int num=0,ch,len=0;
	do
	{
		ch=getch();
		
		if(ch>=48&&ch<=57)
		{
			printf("%c",ch);
			num=num*10+(ch-48);
			len++;
		}
		else if (ch==8)
    	{
        	cout<<"\b \b";
        	num=num/10;
        	len--;
    	}
    	else if(num!=0&&ch==13&&len==12)
		{
        	break;         
    	}
    	if(len==12)
    	break;
	}while(1);
	return num;
}
//***************************************************************
//    				Create new Account Function
//  				 Input Money Function
//**************************************************************
int getmon()
{
	int num=0,ch;
	do
	{
		ch=getch();
		if(ch>=48&&ch<=57)
		{
			printf("%c",ch);
			num=num*10+(ch-48);
		}
		else if (ch==8)
    	{
        	cout<<"\b \b";
        	num=num/10;
        	
    	}
    	else if(num!=0&&ch==13&&num>=100)
		{
        	break;         
    	}
	}while(1);
	return num;
}

//***************************************************************
//    				Create new Account Function
//  				Input Address Function
//**************************************************************
char getadd()
{
	char ch,ca='\0';
	char num[20];
	int len=0;
	for(int i=0;i>=0;)
	{
		ch=getch();
		if(ch==','||ch=='('||ch==')'||ch=='-'||ch==' '||ch>=(char)65&&ch<=(char)91||ch>=(char)97&&ch<=(char)122)
		{
			printf("%c",ch);
			num[i]=ch;
			ca=ch;
			len++;
			i++;
		}
		else if (ch==(char)8)
    	{
        	cout<<"\b \b";
        	i--;
        	len--;
    	}
    	else if(ca!='\0'&&ch==(char)13)
		{
			num[i]='\0';
        	break;         
    	}
    	else if(len==20)
    	break;
	};
	strcpy(Cust.Cust_Add,num);
}
//***************************************************************
//    				Create new Account Function
//  				Input Address Function
//**************************************************************
char getname()
{
	char ch,ca='\0';
	char num[20];
	int len=0;
	for(int i=0;i>=0;)
	{
		ch=getch();
		if(ch==','||ch=='('||ch==')'||ch=='-'||ch==' '||ch>=(char)65&&ch<=(char)91||ch>=(char)97&&ch<=(char)122)
		{
			printf("%c",ch);
			num[i]=ch;
			ca=ch;
			len++;
			i++;
		}
		else if (ch==(char)8)
    	{
        	cout<<"\b \b";
        	i--;
        	len--;
    	}
    	else if(ca!='\0'&&ch==(char)13)
		{
			num[i]='\0';
        	break;         
    	}
    	else if(len==20)
    	break;
	};
	strcpy(Cust.Cust_N,num);
}

//***************************************************************
//    				Create new Account Function
//  				Input Address Function
//**************************************************************
char getdate()
{
	char date[11];
	time_t d1=time(0);
	strftime(date,11,"%m/%d/%y",localtime(&d1));
	strcpy(Cust.date,date);
}

//***************************************************************
//    					Deposit Money Fuction
//  					class Customer Function
//***************************************************************

void Customer::D_Mon()
{
	unsigned long int AACC;
	fstream ff;
	ff.open("Customer.dat",ios::in|ios::out|ios::binary);
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Deposit Money"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	cout<<"Enter the Account NO. : "<<endl;
	cin>>AACC;
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Deposit Money"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	int flag=0;
	while(ff.read((char*)&Cust,sizeof(Cust)))
	{
		if(AACC==Cust.Acc_N)
		{
			cout<<"\n\n Details of account"<<endl;
			cout<<"------------------------------\n"<<endl;
			cout<<"Customer Account No. : "<<Cust.Acc_N<<endl;
			cout<<"Customer Name : "<<Cust.Cust_N<<endl;
			cout<<"Date of Creation : "<<Cust.date<<endl;
			cout<<"Balance : "<<Cust.money<<endl;
			cout<<"Account Type : "<<Cust.Acc_Type<<endl;
			cout<<"Mobile no. : "<<Cust.mobile<<endl;
			cout<<"Area Pin Code : "<<Cust.Cust_Apin<<endl;
			cout<<"Customer Address : "<<Cust.Cust_Add<<endl;
			cout<<"------------------------------\n"<<endl;
			cout<<"Enter Ammount to be Deposited"<<endl;
			Cust.money+=getmon();
			ff.seekg(-1*sizeof(Cust),ios::cur);
			ff.write((char*)&Cust,sizeof(Cust));
			cout<<"\n\nDeposition Successful"<<endl;
			flag=1;
			break;
		}
	};
	if(AACC!=Cust.Acc_N)
	{
		cout<<"\n\nNo Such Account Found"<<endl;
	}
	else if(flag!=1)
	{
		cout<<"\n\nDeposition Failed"<<endl;
	}
	ff.close();
}

//***************************************************************
//    						Withdraw Money
//  					class Customer Function
//***************************************************************
void Customer::W_Mon()
{
	unsigned long int AACC;
	float Mon;
	fstream ff;
	ff.open("Customer.dat",ios::in|ios::out|ios::binary);
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Withdraw Money"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	cout<<"Enter the Account NO. : "<<endl;
	cin>>AACC;
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Withdraw Money"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	int flag=0;
	while(ff.read((char*)&Cust,sizeof(Cust)))
	{
		if(AACC==Cust.Acc_N)
		{
			cout<<"\n\n Details of account"<<endl;
			cout<<"------------------------------\n"<<endl;
			cout<<"Customer Account No. : "<<Cust.Acc_N<<endl;
			cout<<"Customer Name : "<<Cust.Cust_N<<endl;
			cout<<"Date of Creation : "<<Cust.date<<endl;
			cout<<"Balance : "<<Cust.money<<endl;
			cout<<"Account Type : "<<Cust.Acc_Type<<endl;
			cout<<"Mobile no. : "<<Cust.mobile<<endl;
			cout<<"Area Pin Code : "<<Cust.Cust_Apin<<endl;
			cout<<"Customer Address : "<<Cust.Cust_Add<<endl;
			cout<<"------------------------------\n"<<endl;
			cout<<"Enter Ammount to be Withdrawn"<<endl;
			Cust.money-=getmon();
			ff.seekg(-1*sizeof(Cust),ios::cur);
			ff.write((char*)&Cust,sizeof(Cust));
			cout<<"\n\nSuccessfuly Withdrawn"<<endl;
			flag=1;
			break;
		}
	};
	if(AACC!=Cust.Acc_N)
	{
		cout<<"\n\nNo Such Account Found"<<endl;
	}
	else if(flag!=1)
	{
		cout<<"\n\nWithdraw Failed"<<endl;
	}
	ff.close();
}


//***************************************************************
//    				 		All Balance Detail
//  					class Customer Function
//***************************************************************
void Customer::B_Mon()
{
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Balance Detail"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	cout<<"\n\n";
	cout<<"  |---------------------------------------------------------------------|"<<endl;
	cout<<"  |   Account No.   |"<<"           Name          |"<<"          Ammount        |\n";
	cout<<"  |---------------------------------------------------------------------|"<<endl;
	ifstream ird;
	ird.open("Customer.dat",ios::binary|ios::in);
	if(!ird.is_open())
	cout<<"\n\nNo Detail Found"<<endl;
	else
	{
		ird.read((char*)&Cust,sizeof(Customer));
		while(!ird.eof())
		{
			cout<<"\t"<<Cust.Acc_N<<"\t\t"<<Cust.Cust_N<<"\t\t    "<<Cust.money<<"\n"<<endl;
			ird.read((char*)&Cust,sizeof(Cust));
		};
	}
	ird.close();
}

//***************************************************************
//    				 	Balance Enquiry for Each
//  					class Customer Function
//***************************************************************
void Customer::B_Enq()
{
	unsigned long int AACC;
	float Mon;
	fstream ff1;
	ff1.open("Customer.dat",ios::in|ios::out|ios::binary);
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Balance Enquiry"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	cout<<"Enter the Account NO. : "<<endl;
	cin>>AACC;
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Balance Enquiry"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	while(ff1.read((char*)&Cust,sizeof(Cust)))
	{
		if(AACC==Cust.Acc_N)
		{
			cout<<"\n\n Details of account"<<endl;
			cout<<"------------------------------\n"<<endl;
			cout<<"Customer Account No. : "<<Cust.Acc_N<<endl;
			cout<<"Customer Name : "<<Cust.Cust_N<<endl;
			cout<<"Date of Creation : "<<Cust.date<<endl;
			cout<<"Account Type : "<<Cust.Acc_Type<<endl;
			cout<<"Mobile no. : "<<Cust.mobile<<endl;
			cout<<"\n------------------------------"<<endl;
			cout<<"Customer Balance  :  "<<Cust.money<<endl;
			cout<<"------------------------------"<<endl;
			break;
		}
	};
	if(AACC!=Cust.Acc_N)
	{
		cout<<"\n\nNo Such Account Found"<<endl;
	}
	ff1.close();
}


//***************************************************************
//    				   		Customer Detail 
//  					class Customer Function
//***************************************************************
void Customer::Detail()
{
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Customer Detail"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	cout<<"\n\n"<<endl;
	cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"|  Account No.  |"<<"      Date      |"<<"           Name           |"<<"          Address         "<<"|     Mobile No.    |"<<"  Acc.Type |"<<endl;
	cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
	
}
//***************************************************************
//    	Customer Detail show option for Employee Panel
//***************************************************************
void showCust()
{
	system("cls");
	ifstream ird;
	ird.open("Customer.dat",ios::binary|ios::in);
	if(!ird.is_open())
	cout<<"\n\nNo Detail Found"<<endl;
	else
	{
		Cust.Detail();
		ird.read((char*)&Cust,sizeof(Customer));
		while(!ird.eof())
		{
			cout<<"  "<<Cust.Acc_N<<"\t\t  "<<Cust.date<<"\t   "<<Cust.Cust_N<<"\t\t      "<<Cust.Cust_Add<<"\t\t         "<<Cust.mobile<<"\t     "<<Cust.Acc_Type<<"\n"<<endl;
			ird.read((char*)&Cust,sizeof(Customer));
		};
	}
	ird.close();
}
//***************************************************************
//    		Customer Detail show option for Admin Panel
//***************************************************************
void showCust1()
{
	system("cls");
	ifstream ird;
	ird.open("Customer.dat",ios::binary|ios::in);
	if(!ird.is_open())
	cout<<"\n\nNo Detail Found"<<endl;
	else
	{
		Cust.Detail();
		ird.read((char*)&Cust,sizeof(Customer));
		while(!ird.eof())
		{
			cout<<"  "<<Cust.Acc_N<<"\t\t  "<<Cust.date<<"\t   "<<Cust.Cust_N<<"\t\t      "<<Cust.Cust_Add<<"\t\t         "<<Cust.mobile<<"\t     "<<Cust.Acc_Type<<"\n"<<endl;
			ird.read((char*)&Cust,sizeof(Customer));
			
		};
	}
	ird.close();
}

//***************************************************************
//    				   		Delete Account 
//  					class Customer Function
//***************************************************************
void Customer::DeleteAcc()
{
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Delete Account"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------"<<endl;
	unsigned long int ACC;
	cout<<"Enter Account No."<<endl;
	cin>>ACC;
	ifstream fin;
	ofstream fout;
	int flag=0;
	fin.open("Customer.dat",ios::in|ios::binary);
	if(!fin)
		cout<<"\n No Customer Data Found"<<endl;
	else
	{
		fout.open("tempcust.dat",ios::out|ios::binary);
		while(fin.read((char*)&Cust,sizeof(Cust)))
		{
			if(ACC!=Cust.Acc_N)
			{
				fout.write((char*)&Cust,sizeof(Cust));
			}
			else 
			flag=1;
		};
		if(flag==0)
		cout<<"\n\nNo Match Found"<<endl;
		else
		cout<<"\n\nAccount Deleted successfully"<<endl;
		fin.close();
		fout.close();
		remove("Customer.dat");
		rename("tempcust.dat","Customer.dat");
		
	}
}

//***************************************************************
//    				   		Update Account 
//  					class Customer Function
//***************************************************************
void Customer::update()
{
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Update Account"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------\n"<<endl;
	bool found=false;
	unsigned long int ACCn;
	cout<<"Enter Account No."<<endl;
	cin>>ACCn;
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Update Account"<<endl;
	cout<<"\t\t\t\t\t\t   -----------------\n"<<endl;
	fstream File;
	File.open("Customer.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key..."<<endl;
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&Cust), sizeof(Customer));
		if(Cust.Acc_N==ACCn)
		{
			cout<<"\n\nOLD Details of account"<<endl;
			cout<<"------------------------------\n"<<endl;
			cout<<"Customer Account No. : "<<Cust.Acc_N<<endl;
			cout<<"Customer Name : "<<Cust.Cust_N<<endl;
			cout<<"Date of Creation : "<<Cust.date<<endl;
			cout<<"Balance : "<<Cust.money<<endl;
			cout<<"Account Type : "<<Cust.Acc_Type<<endl;
			cout<<"Mobile no. : "<<Cust.mobile<<endl;
			cout<<"Area Pin Code : "<<Cust.Cust_Apin<<endl;
			cout<<"Customer Address : "<<Cust.Cust_Add<<endl;
			cout<<"------------------------------\n"<<endl;
			cout<<"Enter The New Details of account\n"<<endl;
			cout<<"Enter Area Pin Code"<<endl;
			Cust_Apin=getareapin();
			cout<<"\nEnter Address"<<endl;
			getadd();
			cout<<"\nEnter Mobile No."<<endl;
			getmobno();
			int pos=(-1)*static_cast<int>(sizeof(Customer));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&Cust), sizeof(Customer));
			cout<<"\n\n Record Updated"<<endl;
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found "<<endl;
}

//***************************************************************
//    						Admin Screen
//***************************************************************

void Admin()
{
	int caseop=0;
	char sd;
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Choose Option"<<endl;
	cout<<"\t\t\t\t\t\t   ---------------"<<endl;
	cout<<"1. Create Account"<<endl;
	cout<<"2. Customer Detail"<<endl;
	cout<<"3. Balance Detail"<<endl;
	cout<<"4. Customer Detail Update"<<endl;
	cout<<"5. Delete Customer Account"<<endl;
	cout<<"6. Back To Login Panel"<<endl;
	cout<<"7. Exit"<<endl;
	cout<<"\nSelect Required Field (1-7) :: ";
	cin>>caseop;
	switch(caseop)
	{
		case 1:
			regc();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Admin();
			break;
		case 2:
			showCust1();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Admin();
			break;
		case 3:
			Cust.B_Mon();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Admin();
			break;
		case 4:
			Cust.update();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Admin();
			break;
		case 5:
			Cust.DeleteAcc();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Admin();
			break;
		case 6:
			main();
			break;
		case 7:
			exit(0);
			break;
		default:
			cout<<"\nInvalid Choice"<<endl;
			cout<<"\nPress 'y' to Continue Customer Option else you will be Redirected to Login Panel" <<endl;
			cin>>sd;
			if(sd=='y'||sd=='Y')
			Admin();
			else
			main();
	}
}

//***************************************************************
//    						Employee Screen
//***************************************************************
void Coose()
{
	int choose;
	char ch;
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Choose Option"<<endl;
	cout<<"\t\t\t\t\t\t   ---------------"<<endl;
	cout<<"1. Customer Detail"<<endl;
	cout<<"2. Deposit Money"<<endl;
	cout<<"3. Withdraw Money"<<endl;
	cout<<"4. Balance Enquiry"<<endl;
	cout<<"5. Back To Login Panel"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"\nSelect Required Field (1-6) :: ";
	cin>>choose;
	switch(choose)
	{
		case 1:
			showCust();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Coose();
			break;
		case 2:
			Cust.D_Mon();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Coose();
			break;
		case 3:
			Cust.W_Mon();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Coose();
			break;
		case 4:
			Cust.B_Enq();
			cout<<"\nPress Any key to continue"<<endl;
			getch();
			Coose();
			break;
		case 5:
			main();
			break;
		case 6:
			exit(0);
			break;
		default:
			cout<<"\nInvalid Choice"<<endl;
			cout<<"\nPress 'y' to Continue Customer Option else you will be Redirected to Login Panel" <<endl;
			cin>>ch;
			if(ch=='y'||ch=='Y')
			Coose();
			else
			main();
	}
}

//***************************************************************
//    				    	Main Function
//***************************************************************
int main()
{
	void pass1();
	void pass2();
	fstream frr;
	frr.open("Bank.dat",ios::in);
	if(!frr)
	WReg();
	char sd;
	int ch1;
	system("cls");
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
	cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"\n\t\t\t\t\t\t    Choose Login Option"<<endl;
	cout<<"\t\t\t\t\t\t   ---------------------\n"<<endl;
	cout<<"\t\t   Created By : Rohit Tiwari Student of Vivekananda Vidya Mandir in Class XII G  \n\n\t\t\t\t\t\tComputer Science Students \n\n"<<endl;
	cout<<"1. Admin Login"<<endl;
	cout<<"2. Employee Login"<<endl;
	cout<<"3. Exit Program"<<endl;
	cin>>ch1;
	switch(ch1)
	{
		case 1:
			system("cls");
			cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
			cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
			cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
			cout<<"\n\t\t\t\t\t\t   Password Panel Screen"<<endl;
			cout<<"\t\t\t\t\t\t  -----------------------\n"<<endl;
			cout<<"Enter Password for Admin Login "<<endl<<endl;
			pass1();
			break;
			
		case 2:
			system("cls");
			cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
			cout<<"| 	   				         Bank Management System	       			 	       	      |"<<endl;
			cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
			cout<<"\n\t\t\t\t\t\t   Password Panel Screen"<<endl;
			cout<<"\t\t\t\t\t\t  -----------------------\n"<<endl;
			cout<<"Enter Password for Employee Login"<<endl<<endl;
			pass2();
			break;
			
		case 3:
			exit(0);
			break;
			
		default :
			cout<<"\nInvalid Choice"<<endl;
			cout<<"\nPress 'y' to Continue Customer Option else Programme Will Exit" <<endl;
			cin>>sd;
			if(sd=='y'||sd=='Y')
			main();
			else
			exit(0);
	}
	return 0;
}

//***************************************************************
//     Function to Convert Password of Admin panel to Asterix
//***************************************************************
void pass1()
{
	int i;
    char ch,password[]="SBIAdmin",match[8];
    for(i=0;i>=0;)
	{
		ch=getch();
		if(ch!=(char)8&&ch!=(char)13)
        {
    		cout<<"*";
        	match[i]=ch;
        	i++;
        }
    	else if (ch==(char)8) // if backspace is presssed
    	{
        	cout<<"\b \b";
        	i--;
    	}
    	else if(ch==(char)13)
		{
        	match[i]='\0'; // if enter is pressed, last character in match[] becomes null
        	break;         // for end of string
    	}
    	else
    	{
        	break;
    	}
	};
	if(strcmp(match,password)==0)// comparing two strings.. if equal returns 0
	{
		Admin();
	}
	else
	{
		cout<<"\nPassword is not corect"<<endl;
		cout<<"\nPress Any Key to continue"<<endl;
		getch();
		main();
	}
}

//***************************************************************
//    Function to Convert Password of Employee panel to Asterix
//***************************************************************
void pass2()
{
	int i;
    char ch,password[]="SBIEmp",match[8];
    for(i=0;i>=0;)
	{
		ch=getch();
		if(ch!=(char)8&&ch!=(char)13)
        {
    		cout<<"*";
        	match[i]=ch;
        	i++;
        }
    	else if (ch==(char)8) // if backspace is presssed
    	{
        	cout<<"\b \b";
        	i--;
    	}
    	else if(ch==(char)13)
		{
        	match[i]='\0'; // if enter is pressed, last character in match[] becomes null
        	break;         // for end of string
    	}
    	else
    	{
        	break;
    	}
	};
	if(strcmp(match,password)==0)// comparing two strings.. if equal returns 0
	{
		Coose();
	}
	else
	{
		cout<<"\nPassword is not corect"<<endl;
		cout<<"\nPress Any Key to continue"<<endl;
		getch();
		main();
	}
}

