#include <fstream.h>
#include <iostream.h>
#include <cstring>

class Pharmacy
{
public:
	char Drug_ID[10];
	char Drug_Name[20];
	char Drug_Amount[15];
	char Price[15];
	char Type_of_package[4];
	char Shelf_Number[3];

	Pharmacy()
	{
		Drug_ID[0]=0;
	    Drug_Name[0]=0;
	    Drug_Amount[0]=0;
	    Price[0]=0;
	    Type_of_package[0]=0;
	    Shelf_Number[0]=0;
	}
void EnterDrug()
{
	fstream f;
	Pharmacy x;
	char PharmacyFile[30];
	char ch;
	f.open("PharmacyFile.txt" , ios::app);
	do
	{
		cout<<"Enter the Drug_ID :";
		cin>>x.Drug_ID;
		cout<<"Enter the Drug_Name :";
		cin>>x.Drug_Name;
		cout<<"Enter the Drug_Amount :";
		cin>>x.Drug_Amount;
		cout<<"Enter the Price :";
		cin>>x.Price;
		cout<<"Enter the Type_of_package :";
		cin>>x.Type_of_package;
		cout<<"Enter the Shelf_Number :";
		cin>>x.Shelf_Number;
		cout<<"Do you want to add another Drug [y , n] ?";
		cin>>ch;
	}
	while(ch=='y');
	f.close();
}
void CheckDrug_ID()
{
	fstream f;
	Pharmacy x;
	char PharmacyFile[30];
	f.open(PharmacyFile , ios::in);
	while(!f.eof())
	{
		f.getline(x.Drug_ID , 10);
		if(!strcmp(Drug_ID , x.Drug_ID))
		{
			cout<<"This Drug_ID is already in the file , Please check it \n";
		}
	}
	f.close();
}

void DisplayDrug()
{
	fstream f;
	Pharmacy x;
	char PharmacyFile[30];
	f.open(PharmacyFile , ios::in);
	while(!f.eof())
	{
		f<<x.Drug_ID<<"|"<<x.Drug_Name<<"|"<<x.Drug_Amount<<"|"<<x.Price<<"|"
			<<x.Type_of_package<<"|"<<x.Shelf_Number<<"/n";
	}
	f.close();
}


void SearchDrug()
{
fstream f;
Pharmacy x;
char PharmacyFile[30];
int flag = 0;
char Drug_ID[10];
cout<<"Enter the Drug_ID :";
cin>>Drug_ID;
f.open(PharmacyFile , ios::in);
while(!f.eof())
{
	f.getline(x.Drug_ID , 10 , '|');
	f.getline(x.Drug_Name , 20 , '|');
	f.getline(x.Drug_Amount , 15 , '|');
	f.getline(x.Price , 4);
	if(!strcmp(Drug_ID , x.Drug_ID))
	{
		cout<<"The Drug is Founded :"<<"/n";
		cout<<x.Drug_ID<<"/t";
		cout<<x.Drug_Name<<"/t";
		cout<<x.Drug_Amount<<"/t";
		cout<<x.Price<<"/t";
		cout<<x.Type_of_package<<"/t";
		cout<<x.Shelf_Number<<endl;
		flag = 1;
	}
}
f.close();
if(flag == 0)
cout<<"\n The Drug is not in the Pharmacy : \n";
}
void DeleteDrug()
{
	fstream f;
	Pharmacy x;
	char PharmacyFile[30];
	char newfile[30];
	char Drug_ID[12];
	cout<<"Enter the Drug_ID :";
	cin>>Drug_ID;
	f.open(PharmacyFile , ios::out);
	f.open(PharmacyFile , ios::in);
	while(!f.eof())
	{
		f.open(newfile , ios::app);
		if(strcmp(Drug_ID , x.Drug_ID))
		{
			f<<x.Drug_ID<<"|"<<x.Drug_Name<<"|"<<x.Drug_Amount<<"|"<<x.Price<<"|"
			<<x.Type_of_package<<"|"<<x.Shelf_Number<<"/n";
		}
		f.close();
	}
	f.close();
	f.open(newfile , ios::in);
	while(!f.eof())
	{
		f.open(PharmacyFile , ios::out);
	
		f.close();
	}
	f.close();
}
};
int main()
{
Pharmacy c;
int ch;
cout<<"FACULTY OF COMBUTER AND INFORMATION \n";
cout<<"Project Name:Pharmacy System Project\n";
cout<<"Name:Mohamed El Sayed Mohamed Badr\n";
cout<<"ID:090192\n";
cout<<"Section:7\n";
cout<<"1) Add a new Drug \n";
cout<<"2) Read the entire Pharmacy \n";
cout<<"3) Search for a Drug \n";
cout<<"4) Delete a Drug \n";
cout<<"Enter your choise :";
cin>>ch;
switch(ch)
{
case 1:
	c.EnterDrug();
	break;
case 2:
	c.DisplayDrug();
	break;
case 3:
	c.SearchDrug();
	break;
case 4:
	c.DeleteDrug();
	break;
default :
	cout<<"Wrong cloise \n";
	break;
}
}