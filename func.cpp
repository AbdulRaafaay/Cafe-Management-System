#include "header.h"


void func_admin ( char admin_id[], char admin_pass[] )
{
	
	ifstream fin;		// Declaring object for reading
	fin.open ("admin.txt" , ios :: in);		// open a file in read mode
	if (!fin)		// Checking if file is created
	{
		cout << "\nError In Creation Of File" << endl;
	}
	else
	{
			fin.getline(admin_id,6,' ');		// Reading admin id from file
			fin.getline(admin_pass,5);		// Reading admin password from file
	}
	fin.close();		// closing the read mode file
	
}


bool func_employees(char employee_id[], char employee_pass[])
{
	bool f;
	int i=0;
	char employee1_id[10][12], employee1_pass[10][12];
	ifstream fin;		// Declaring object for reading
	fin.open ("employees.txt" , ios :: in);		// open a file in read mode
	if (!fin)		// Checking if file is created
	{
		cout << "\nError In Creation Of File" << endl;
	}
	else
	{
		while( fin.getline(employee1_id[i],12,' '),fin.getline(employee1_pass[i],12,'\n') )
		{
			if ( (strcmp(employee_id,employee1_id[i])==0) && (strcmp(employee_pass,employee1_pass[i])==0) )
			{
				f=1;
				break;
			}
			i++;
		}	
	}
	fin.close();	// closing the read mode file
	return f;
					
}


void showitems(void)
{
	char c;
	
	ifstream fin;		// declarimg object for reading
	fin.open ("Items.txt", ios :: in);		// Opening in read mode
	if (!fin)		// Checking if file is present
	{
		cout << "Error in Creating File Of Items" << endl;
	}
	else
	{
		cout << endl;
		while ( !fin.eof() )
		{
			fin.get(c);		// Reading each character from file
			cout << c;		// Terminal pe display karwa raha hun
		}

	}
	fin.close();		// closing the read mode file
	
}

void additem(int idadd, char itemname1[13], int qty, int rate, int totalp)
{

	char itemname[20][10],hdr[30];
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0;
	bool f=0;
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if(!fin)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			totalarr[i] = ratearr[i] * qtyarr[i];
				if (idarr[i]==idadd)
				{
					f=1;
					break;
				}
			i++;
		}
	}
	fin.close();
	

	if (f==1)
	{
		cout << "\nID Already present!" << endl;
		cout << "NOT ADDED!" << endl;
	}
	else
	{
		ofstream fout;
		fout.open ("Items.txt",ios::out|ios::app);
			if (!fout)
			{
				cout << "Error in Opening the File!" << endl;
			}
			else
			{
				fout.seekp(0,ios::end);
				fout << idadd << "	" << itemname1 << "	" << qty << "	" << rate << "	" << totalp << "\n";
			}
			fout.close();
			cout << BLUE << BOLD << "\nItem Has Been Added Successfully!" << RESET << endl;
	}
	
	i=0;
	ifstream fin1;
	fin1.open ("Items.txt",ios::in);
	if(!fin1)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin1.getline(hdr,30,'\n');
		while ( fin1>>idarr[i], fin1.ignore(), fin1.getline(itemname[i],20,'	'), fin1>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin1.ignore();
			totalarr[i] = ratearr[i] * qtyarr[i];
			i++;
		}
	}
	fin1.close();
	
	int temp;
	int n = i-1;
	for (int k = 0; k<i; k++)
	{
		for (int j = 0 ; j<n; ++j)
		{ 
			if(idarr[j] > idarr[j + 1])
			{
	 			temp = idarr[j];
				idarr[j] = idarr[j + 1];
				idarr[j + 1] = temp;
			}

		}
		n--;
	}
	
	ofstream fout;
	fout.open ("Items.txt",ios::out);
		if (!fout)
		{
			cout << "Error in Opening the File!" << endl;
		}
		else
		{
			fout << hdr << "\n";
			for (int x=0; x<i; x++)
				fout << idarr[x] << "	" << itemname[x] << "	" << qtyarr[x] << "	" << ratearr[x] << "	" << totalarr[x] << "\n";
		}
		fout.close();
}


void notify(char arrnotify[100])
{
	ofstream fout;
	fout.open("notifications.txt",ios::out|ios::app);
	if (!fout)
	{
		cout << "Error in creating or opening file!" << endl;
	}
	else
	{
		fout.seekp(0,ios::end);
		fout << arrnotify << "\n";
	}
	fout.close();
	
}

void notifyread(void)
{
	char c;
	ifstream fin;
	fin.open("notifications.txt",ios::in);
	if (!fin)
	{
		cout << "Error in File Opening" << endl;
	}
	else
	{
		cout << "\n :: Notifications ::\n" << endl;
		while ( !fin.eof() )
		{
			fin.get(c);
			cout << c;
		}
	}
	fin.close();
	
}

void removeitem(int idrem)
{
	char itemname[20][10],hdr[30];
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0;
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if(!fin)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			totalarr[i] = ratearr[i] * qtyarr[i];
				if (idarr[i]==idrem)
					continue;
			i++;
		}
	}
	fin.close();
	
	ofstream fout;
	fout.open ("Items.txt",ios::out);
	if (!fout)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fout << hdr << "\n";
		for ( int k=0; k<i; k++ )
		{
			if (idarr[k]==idrem)
				continue;
			fout << idarr[k] << "	" << itemname[k] << "	" << qtyarr[k] << "	" << ratearr[k] << "	" << totalarr[k] << "\n";
		}
	cout << BLUE << BOLD << "\nItem Has Been Removed Successfully!" << RESET << endl;
	}
	fout.close();
}

void searchitem( char namesearch[10] )
{
	bool f;
	int id=0;
	char itemname[20][10],hdr[30];
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0;
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if(!fin)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			totalarr[i] = ratearr[i] * qtyarr[i];
				if ( strcmp(itemname[i],namesearch)==0 )
				{
					f=1;
					id=idarr[i];
				}
			i++;
		}
		if (f==1)
		cout << "\nITEM FOUND AT ID \'" << id << "\'" <<  endl;
		else
		cout << "\nITEM NOT FOUND" << endl;
		
	}
	fin.close();
}

void complaints(char arrcomplaint[100])
{
	ofstream fout;
	fout.open("complaints.txt",ios::out|ios::app);
	if (!fout)
	{
		cout << "Error in creating or opening file!" << endl;
	}
	else
	{
		fout.seekp(0,ios::end);
		fout << arrcomplaint << "\n";
	}
	fout.close();
	
}

void complaintsread(void)
{
	char c;
	ifstream fin;
	fin.open("complaints.txt",ios::in);
	if (!fin)
	{
		cout << "Error in File Opening" << endl;
	}
	else
	{
		cout << "\n :: Complaints ::\n" << endl;
		while ( !fin.eof() )
		{
			fin.get(c);
			cout << c;
		}
	}
	fin.close();
}

void addemployee( char employee_id[], char employee_pass[] )
{
	ofstream fout;
	fout.open ("employees.txt",ios::out|ios::app);
	if (!fout)
	{
		cout << "Error in Opening the File!" << endl;
	}
	else
	{
		fout.seekp(0,ios::end);
		fout << employee_id << " " << employee_pass << "\n";
	}
	fout.close();
}

void employeeshow(void)
{
	char c;
	
	ifstream fin;		// declarimg object for reading
	fin.open ("employees.txt", ios :: in);		// Opening in read mode
	if (!fin)		// Checking if file is present
	{
		cout << "Error in Creating File Of Items" << endl;
	}
	else
	{
		cout << endl;
		while ( !fin.eof() )
		{
			fin.get(c);		// Reading each character from file
			cout << c;		// Terminal pe display karwa raha hun
		}

	}
	fin.close();		// closing the read mode file	
}

void rememployee(char employeenewid[])
{
	char employeerem[20][20],employeerempass[20][20];
	bool f;
	int i=0;
	ifstream fin;		// Declaring object for reading
	fin.open ("employees.txt" , ios :: in);		// open a file in read mode
	if (!fin)		// Checking if file is created
	{
		cout << "\nError In Creation Of File" << endl;
	}
	else
	{
		while( fin.getline(employeerem[i],20,' '),fin.getline(employeerempass[i],20,'\n') )
		{
			if ( (strcmp(employeerem[i],employeenewid)==0) )
			{
				continue;
			}
			i++;
		}	
	}
	fin.close();	// closing the read mode file
	
	ofstream fout;
	fout.open ("employees.txt",ios::out);
	if (!fout)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		for (int k=0; k<i; k++)
		{
			fout << employeerem[k] << " " << employeerempass[k] << endl;
		}	
	}
	fout.close();
}

void studentshow(void)
{
	char c;
	
	ifstream fin;		// declarimg object for reading
	fin.open ("students.txt", ios :: in);		// Opening in read mode
	if (!fin)		// Checking if file is present
	{
		cout << "Error in Creating File Of Items" << endl;
	}
	else
	{
		cout << endl;
		while ( !fin.eof() )
		{
			fin.get(c);		// Reading each character from file
			cout << c;		// Terminal pe display karwa raha hun
		}

	}
	fin.close();		// closing the read mode file	
}

void addstudent( char student_id[], char student_pass[] )
{
	ofstream fout;
	fout.open ("students.txt",ios::out|ios::app);
	if (!fout)
	{
		cout << "Error in Opening the File!" << endl;
	}
	else
	{
		fout.seekp(0,ios::end);
		fout << student_id << " " << student_pass << "\n";
	}
	fout.close();
}

void remstudent(char studentnewid[])
{
	char studentrem[20][20],studentrempass[20][20];
	bool f;
	int i=0;
	ifstream fin;		// Declaring object for reading
	fin.open ("students.txt" , ios :: in);		// open a file in read mode
	if (!fin)		// Checking if file is created
	{
		cout << "\nError In Creation Of File" << endl;
	}
	else
	{
		while( fin.getline(studentrem[i],20,' '),fin.getline(studentrempass[i],20,'\n') )
		{
			if ( (strcmp(studentrem[i],studentnewid)==0) )
			{
				continue;
			}
			i++;
		}	
	}
	fin.close();	// closing the read mode file
	
	ofstream fout;
	fout.open ("students.txt",ios::out);
	if (!fout)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		for (int k=0; k<i; k++)
		{
			fout << studentrem[k] << " " << studentrempass[k] << endl;
		}	
	}
	fout.close();
}

void order(int id, int qty)
{
	char itemname[20][10], hdr[30]; 
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0, total, rate; 
	char *arr;
	bool f=0;
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if(!fin)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
				if (idarr[i]==id && (qty>0 && qty<=qtyarr[i]) )
				{
					f=1;
					arr = itemname[i];
					qtyarr[i] = qtyarr[i]-qty;
					rate = ratearr[i];
					total = qty*ratearr[i];
					
				}
			i++;
					
		}
	}
	fin.close();
	if ( f==1 )
	{
		ofstream fout;
		fout.open ("bill.txt",ios::out|ios::app);
		if (!fout)
		{
			cout << "Error in opening File" << endl;
		}
		else
		{
			fout.seekp(0,ios::end);
			fout << id << "	" << arr << "	" << qty << "	" << rate << "	" << total << "\n";
		}
		fout.close();
		
		ofstream fout1;
		fout1.open ("Items.txt",ios::out);
		if (!fout1)
		{
			cout << "Error in opening File" << endl;
		}
		else
		{
			fout1 << hdr << "\n";
			for ( int k=0; k<i; k++ )
			{
				fout1.seekp(0,ios::end);
				fout1 << idarr[k] << "	" << itemname[k] << "	" << qtyarr[k] << "	" 	<< ratearr[k] << "	" << totalarr[k] << "\n";
			}
		}
		fout.close();
	}	
	else
	{
		cout << "\nInvalid Quantity!" << endl;
	}
	
	
	
}

void showbill(void)
{
	char itemname[20][10],hdr[30];
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0;
	ifstream fin;
	fin.open ("bill.txt",ios::in);
	if(!fin)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			i++;
		}
		
	}
	fin.close();
	
	ofstream fout;
	fout.open ("bill.txt",ios::out);
	int sum=0;
	if (!fout)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		cout << endl;
		fout << hdr << "\n";
		cout << hdr << "\n";
		for ( int k=0; k<i; k++ )
		{
			fout << idarr[k] << "	" << itemname[k] << "	" << qtyarr[k] << "	" << ratearr[k] << "	" << totalarr[k] << "\n";
			cout << idarr[k] << "	" << itemname[k] << "	" << qtyarr[k] << "	" << ratearr[k] << "	" << totalarr[k] << "\n";
			sum = totalarr[k] + sum;
		}
		cout << endl;
		cout << "\nYour Total Bill = " << sum << " Rs\n" << endl;
	}
	fout.close();	
}

bool func_students(char student_id[], char student_pass[])
{
	bool f;
	char student1_id[5], student1_pass[5];
	ifstream fin;		// Declaring object for reading
	fin.open ("students.txt" , ios :: in);		// open a file in read mode
	if (!fin)		// Checking if file is created
	{
		cout << "\nError In Creation Of File" << endl;
	}
	else
	{
		while( fin.getline(student1_id,5,' '),fin.getline(student1_pass,5,'\n') )
		{
			if ( (strcmp(student_id,student1_id)==0) && (strcmp(student_pass,student1_pass)==0) )
			{
				f=1;
				break;
			}
		}	
	}
	fin.close();	// closing the read mode file
	return f;
					
}

void orderonline(char time[], char student_id[])
{
	ofstream fout;
	fout.open ("orderonline.txt",ios::out|ios::app);
	if (!fout)
	{
		cout << "\nError In Opening or Creating The File orderonline!" << endl;
	}
	else
	{
		fout.seekp(0,ios::end);
		fout << student_id << "\t" << time << "\n";
		cout << "\n::  THANK YOU FOR ORDERING :)  ::\n" << endl;
	}
	fout.close();
}

void showorders(void)
{
	char c;
	
	ifstream fin;		// declarimg object for reading
	fin.open ("orderonline.txt", ios :: in);		// Opening in read mode
	if (!fin)		// Checking if file is present
	{
		cout << "Error in Creating File Of Order Online" << endl;
	}
	else
	{
		cout << endl;
		while ( !fin.eof() )
		{
			fin.get(c);		// Reading each character from file
			cout << c;		// Terminal pe display karwa raha hun
		}

	}
	fin.close();		// closing the read mode file
	
}

void bestseller(char employee_id[])
{
	char itemname[20][10],hdr[30];
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0;
	ifstream fin;
	fin.open ("bill.txt",ios::in);
	if(!fin)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			i++;
		}
		
	}
	fin.close();
	
	ofstream fout;
	fout.open ("bestseller.txt",ios::out|ios::app);
	int sum=0;
	if (!fout)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		cout << endl;
		for ( int k=0; k<i; k++ )
		{
			sum = totalarr[k] + sum;
		}
		fout << employee_id << "\t" << sum << "\n";
	}
	fout.close();	
	
}	

void bestsellershow(void)
{
	char* hdr = new char[50];
    	char** name = new char*[20];
    	for (int i = 0; i < 20; ++i) 
    	{
        	name[i] = new char[20];
    	}

    	int* price = new int[20];
    	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    	int j = 0;

    	ifstream fin;
    	fin.open("bestseller.txt", ios::in);

    	if (!fin)
        cout << "Error in opening File" << endl;
    	else 
    	{
        	fin.getline(hdr, 50, '\n');
        	while (fin.getline(name[j], 20, '\t'), fin >> price[j]) 
        	{
        	    fin.ignore();
        	    j++;
        	}

        for (int x = 0; x < j; x++) {
            if (strcmp(name[x], "kamil") == 0)
                sum1 = sum1 + price[x];
            else if (strcmp(name[x], "hayan") == 0)
                sum2 = sum2 + price[x];
            else if (strcmp(name[x], "ahmad") == 0)
                sum3 = sum3 + price[x];
            else if (strcmp(name[x], "umair") == 0)
                sum4 = sum4 + price[x];
            else if (strcmp(name[x], "rohan") == 0)
                sum5 = sum5 + price[x];
        }

        cout << "kamil = " << sum1 << " Rs" << endl;
        cout << "hayan = " << sum2 << " Rs" << endl;
        cout << "ahmad = " << sum3 << " Rs" << endl;
        cout << "umair = " << sum4 << " Rs" << endl;
        cout << "rohan = " << sum5 << " Rs" << endl;

        if (sum1 > sum2 && sum1 > sum3 && sum1 > sum4 && sum1 > sum5)
            cout << "\nKamil Is The Best Seller Employee!" << endl;
        else if (sum2 > sum1 && sum2 > sum3 && sum2 > sum4 && sum2 > sum5)
            cout << "\nHayan Is The Best Seller Employee!" << endl;
        else if (sum3 > sum1 && sum3 > sum2 && sum3 > sum4 && sum3 > sum5)
            cout << "\nAhmad Is The Best Seller Employee!" << endl;
        else if (sum4 > sum1 && sum4 > sum2 && sum4 > sum3 && sum4 > sum5)
            cout << "\nUmair Is The Best Seller Employee!" << endl;
        else if (sum5 > sum1 && sum5 > sum2 && sum5 > sum3 && sum5 > sum4)
            cout << "\nRohan Is The Best Seller Employee!" << endl;
    }

    fin.close();

    // Deallocate memory and Undangle
    delete[] hdr;
    hdr = NULL;
    for (int i = 0; i < 20; ++i)
    {
        delete[] name[i];
        name [i] = NULL;
    }
    delete[] name;
    name = NULL;
    delete[] price;
    price = NULL;;

}

void showlist_best(void)
{
	char c;
	
	ifstream fin;		// declarimg object for reading
	fin.open ("bestseller.txt", ios :: in);		// Opening in read mode
	if (!fin)		// Checking if file is present
	{
		cout << "Error in Creating File" << endl;
	}
	else
	{
		cout << endl;
		while ( !fin.eof() )
		{
			fin.get(c);		// Reading each character from file
			cout << c;		// Terminal pe display karwa raha hun
		}

	}
	fin.close();		// closing the read mode file
}

bool orderadmin(int id, int qty)
{
	char itemname[20][10], hdr[30]; 
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0, total, rate; 
	char *arr;
	bool f=0,f1=0;
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if(!fin)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
				if (idarr[i]==id && qty>0)
				{
					f=1;
					arr = itemname[i];
					qtyarr[i] = qtyarr[i]+qty;
					rate = ratearr[i];
					total = qty*ratearr[i];
					totalarr[i] = ratearr[i] * qtyarr[i];
					
				}
			i++;			
		}
	}
	fin.close();
	if ( f==1 )
	{
		ofstream fout;
		fout.open ("bill.txt",ios::out|ios::app);
		if (!fout)
		{
			cout << "Error in opening File" << endl;
		}
		else
		{
			fout.seekp(0,ios::end);
			fout << id << "	" << arr << "	" << qty << "	" << rate << "	" << total << "\n";
		}
		fout.close();
		
		ofstream fout1;
		fout1.open ("Items.txt",ios::out);
		if (!fout1)
		{
			cout << "Error in opening File" << endl;
		}
		else
		{
			fout1 << hdr << "\n";
			for ( int k=0; k<i; k++ )
			{
				if (qtyarr[k]>1000)
				{
					cout << "\nQuantity can not exceed 1000!!" << endl;
					qtyarr[k]=qtyarr[k]-qty;
					f1=1;
				}	
				fout1.seekp(0,ios::end);
				fout1 << idarr[k] << "	" << itemname[k] << "	" << qtyarr[k] << "	" 	<< ratearr[k] << "	" << totalarr[k] << "\n";
			}
		}
		fout.close();
	}	
	else
	{
		cout << "\nInvalid Quantity!" << endl;
	}
	return f1;

}

void lowitems(void)
{
	char itemname[30][20], hdr[30]; 
	int idarr[20], qtyarr[20], ratearr[20], totalarr[20];
	int i=0, total, rate, id, qty,id1,total1,qty1,rate1;
	char* arr;		// Pointer arrays takay inme name store karlun jo items low hain
	char* arr1; 
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if(!fin)
	{
		cout << "Error in opening File" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			
				if (qtyarr[i]==0)
				{
					arr1 = itemname[i];
					id1 = idarr[i];
					qty1 = qtyarr[i];
					rate1 = ratearr[i];
					totalarr[i] = ratearr[i] * qtyarr[i];
					total1 = totalarr[i];
				}
				
				if ( qtyarr[i]<15 && qtyarr[i]>0 )
				{
					arr = itemname[i];
					id = idarr[i];
					qty = qtyarr[i];
					rate = ratearr[i];
					totalarr[i] = ratearr[i] * qtyarr[i];
					total = totalarr[i];
				}
			i++;
		}
	}
	fin.close();
	
	ofstream fout;
	fout.open ("Items.txt",ios::out);
	if (!fout)
	{
		cout << "Error in Opening file!" << endl;
	}
	else
	{
		cout << endl;
		cout << hdr << endl;
		fout << hdr << endl;
		
		if ( qty1==0 )
		{
			cout << YELLOW << id1 << "\t" << arr1 << "\t" << qty1 << "\t" << rate1 << "\t" << total1 << RESET << endl;
			ofstream fout;
			fout.open("notifications.txt",ios::out|ios::app);
			if (!fout)
			{
				cout << "Error in creating or opening file!" << endl;
			}
			else
			{
				fout << arr1 << " Is Low In Quantity!" << endl;
			}
			fout.close();
		}
		
		if ( qty<15 && qty>0 )
		{
			cout << RED << id << "\t" << arr << "\t" << qty << "\t" << rate << "\t" << total << RESET << endl;
			ofstream fout;
			fout.open("notifications.txt",ios::out|ios::app);
			if (!fout)
			{
				cout << "Error in creating or opening file!" << endl;
			}
			else
			{
				fout << arr << " Is Low In Quantity!" << endl;
			}
			fout.close();
		}
		
		
		for (int k=0; k<i; k++)
		{
			fout << idarr[k] << "\t" << itemname[k] << "\t" << qtyarr[k] << "\t" << ratearr[k] << "\t" << totalarr[k] << endl;
			if ( (qtyarr[k]<15 && qtyarr[k]>0) || qtyarr[k]==0)
				continue;			
			cout << idarr[k] << "\t" << itemname[k] << "\t" << qtyarr[k] << "\t" << ratearr[k] << "\t" << totalarr[k] << endl;
			
		}	
	}
	fout.close();	

}

void items(void)
{
	char itemname[20][10], hdr[30]; 
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0;
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if (!fin)
	{
		cout << "\nError In Opening File!" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],20,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			totalarr[i] = qtyarr[i] * ratearr[i];
			i++;
		}
	}
	fin.close();
	
	ofstream fout;
	fout.open ("Items.txt",ios::out);
	if (!fout)
		cout << "\nError In Opening File!" << endl;
	else
	{
		fout << hdr << "\n";
		for (int k=0; k<i; k++)
		{
			fout << idarr[k] << "\t" << itemname[k] << "\t" << qtyarr[k] << "\t" << ratearr[k] << "\t" << totalarr[k] << endl;
		}
	}
	fout.close();
}

void showitems1(void)
{
	char itemname[20][10], hdr[30]; 
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0;
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if (!fin)
	{
		cout << "\nError In Opening File!" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],10,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			totalarr[i] = qtyarr[i] * ratearr[i];
			i++;
		}
	}
	fin.close();
	
	ofstream fout;
	fout.open ("Items.txt",ios::out);
	if (!fout)
		cout << "\nError In Opening File!" << endl;
	else
	{
		cout << endl;
		fout << hdr << "\n";
		cout << "ID\tName\tQTY\tRate" << endl;
		for (int k=0; k<i; k++)
		{
			fout << idarr[k] << "\t" << itemname[k] << "\t" << qtyarr[k] << "\t" << ratearr[k] << "\t" << totalarr[k] << endl;
			cout << idarr[k] << "\t" << itemname[k] << "\t" << qtyarr[k] << "\t" << ratearr[k] << endl;
		}
		cout << endl;
	}
	fout.close();
	
}

void approval(void)
{
	ofstream fout;
	fout.open("notifications.txt",ios::out|ios::app);
	if (!fout)
	{
		cout << "Error in creating or opening file!" << endl;
	}
	else
	{
		fout << "The Order Has Been Approved!" << endl;
		cout << BLUE << BOLD << "\nThe Order Has Been Approved!" << RESET << endl;
	}
	fout.close();

}
	
void rejection(void)
{
	ofstream fout;
	fout.open("notifications.txt",ios::out|ios::app);
	if (!fout)
	{
		cout << "Error in creating or opening file!" << endl;
	}
	else
	{
		fout << "The Order Has Been Rejected!" << endl;
		cout << BLUE << BOLD << "\nThe Order Has Been Rejected!" << RESET << endl;
	}
	fout.close();
}	

void decrease(int quant)
{
	char itemname[20][10], hdr[30]; 
	int idarr[10], qtyarr[10], ratearr[10], totalarr[10];
	int i=0;
	ifstream fin;
	fin.open ("Items.txt",ios::in);
	if (!fin)
	{
		cout << "\nError In Opening File!" << endl;
	}
	else
	{
		fin.getline(hdr,30,'\n');
		while ( fin>>idarr[i], fin.ignore(), fin.getline(itemname[i],10,'	'), fin>>qtyarr[i]>>ratearr[i]>>totalarr[i])
		{
			fin.ignore();
			totalarr[i] = qtyarr[i] * ratearr[i];
			qtyarr[i] = qtyarr[i] - quant;
			i++;
		}
	}
	fin.close();
	
	ofstream fout;
	fout.open ("Items.txt",ios::out);
	if (!fout)
		cout << "\nError In Opening File!" << endl;
	else
	{
		fout << hdr << "\n";
		for (int k=0; k<i; k++)
		{
			fout << idarr[k] << "\t" << itemname[k] << "\t" << qtyarr[k] << "\t" << ratearr[k] << "\t" << totalarr[k] << endl;
		}
	}
	fout.close();

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
			
