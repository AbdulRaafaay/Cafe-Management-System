#include "header.h"


int main ()
{

		remove("bill.txt");		// So that bill is refreshed
		ofstream fout;		// opening/creating bill in write mode
		fout.open ("bill.txt",ios::out);
		fout << "ID	" << "Name	" << "Qty	" << "Rate	" << "Total" << "\n";
		fout.close();		// Closing bill
		
		remove("orderonline.txt");		// So that bill is refreshed
		ofstream fout1;
		fout1.open ("orderonline.txt",ios::out);
		
		items();
		
		srand (time(0));	// To Generate a random value
		
	const int size=20; // Declaring size of array	
	char adminid[size],adminpass[size],admin_id[6],admin_pass[5]; 	// Declaring Arrays for admin
	char employeeid[size],employeepass[size],itemname[13];
	char employee_id[12],employee_pass[12], employeenewid[20], employeenewpass[20]; 	// Declaring Arrays for Employees
	char studentnewid[20], studentnewpass[20],student_id[20], student_pass[20];
	char arrnotify[100], namesearch[10], arrcomplaint[100];
	char time[20];
	int choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8, choice9, choice10, choice11, choice12, count=0; // Declaring choices and Initializing Count variable 	
	int idadd, qty, rate, totalp, idrem, id, quant;	
	bool f,f1,f2;		// Declaring flags

	// Design Print Hoga
	cout << BLUE << BOLD <<  "\t\t" << setfill ('*') << setw(43) << "*" << RESET << endl;
	cout << GREEN << BOLD << "\n\t\t*  WELCOME TO THE CAFE MANAGEMENT SYSTEM  *" << RESET << endl;
	cout << BLUE << BOLD << "\n\t\t" << setfill ('*') << setw(43) << "*" << RESET <<  endl;
	
do
{


do
{
	
	// Asking About User
	cout << BOLD << "\n1. Admin" << endl;	
	cout << "\n2. Employee" << endl;	
	cout << "\n3. Student/Staff" << RESET << endl;	
	cout << "\nWho is Using the System ? ";
	cin >> choice1;
	cout << endl;
	
	
	///////////////////     ADMIN   LOGIN	///////////////////
	
	if ( choice1==1 )	
	{
		cin.ignore();		// To get rid of buffer value
		func_admin(admin_id,admin_pass);	 // Admin ke credentials wala function call.
	
		do		// loop for no.of characters		
		{
			do		// loop for correct admin id
			{

				count = 0;
				cout << RED << BOLD << "NOTE : MINIMUM 3 and MAXIMIUM 20 CHARACTERS" << RESET << endl;
				cout << BOLD << "\nADMIN ID : " << RESET;
				cin.getline(adminid,20);
					if ( strcmp(adminid,admin_id)==0 )
					{
						cout << "\nCorrect ID" << endl;
					}
					else
					{
						cout << RED << BOLD << "\nID is not Correct" << endl;
						cout << "Try AGAIN!\n" << RESET << endl;
					}
					for ( int i=0; adminid[i]!='\0'; i++ )
					{
						count++;
					}
						if ( count < 3 || count > 20 )
						{
							cout << RED << "READ THE NOTE!!\n" << RESET << endl;
						}
			}
			while( strcmp(adminid,admin_id)!=0 );
		}
		while (count<3 || count >20);
		cout << endl;
		
		do		// loop for no.of characters
		{
			do		// loop for correct Password
			{
				count = 0;
				cout << RED << BOLD <<"NOTE : MINIMUM 3 and MAXIMIUM 20 CHARACTERS" << RESET << endl;
				cout << BOLD << "\nPASSWORD : " << RESET;
				cin.getline(adminpass,20);
				
					if ( strcmp(adminpass,admin_pass)==0 )
					{
						cout << "\nCorrect Password" << endl;
						cout << "Successfull Log In :)\n" << endl;
					}
					else
					{
						cout << RED << "\nPassword is not Correct" << endl;
						cout << "Try AGAIN!\n" << RESET << endl;
					}
					for ( int i=0; adminpass[i]!='\0'; i++ )
					{
						count++;
					}
						if ( count < 3 || count > 20 )
						{
							cout << RED << "READ THE NOTE!!\n" << RESET << endl;
						}
			}
			while( strcmp(adminpass,admin_pass)!=0 );
		}
		while (count<3 || count >20);
		
		// Printing Design
		cout << BLUE << BOLD << "\n\t\t" << setfill ('*') << setw(20) << "*" << RESET << endl;
		cout << GREEN << BOLD << "\n\t\t*    ADMIN LOGIN   *" << RESET << endl;
		cout << BLUE << BOLD << "\n\t\t" << setfill ('*') << setw(20) << "*" << RESET << endl;
	do
	{
		// Admin ke paas in cheezon ki access hai
		do
		{
		cout << BOLD << "\n1. Go back" << endl;
		cout << "2. Show All Items in Stock" << endl;
		cout << "3. Add an Item in Stock" << endl;
		cout << "4. Remove an Item in Stock" << endl;
		cout << "5. Search for an Item in Stock" << endl;
		cout << "6. Update Credentials of Employees" << endl;
		cout << "7. Update Credentials of Students" << endl;
		cout << "8. Manage Notifications" << endl;
		cout << "9. Online/Scheduled Orders" << endl;
		cout << "10. Check Complaints" << endl;
		cout << "11. Best Seller Employee" << endl;
		cout << "12. Order Items Lower in Quantity" << endl;
		cout << "13. Low Stock Items Management" << endl;
		cout << "14. One Day Pass" << RESET << endl;
		
		cout << "\nEnter Your choice : ";
		cin >> choice2;
			if (choice2==1)		// For going back
				break;
			
			else if ( choice2==2 )		// For displaying menu
			{
				showitems();
				do
				{
				cout << "\nEnter \'1\' to Go back: ";
				cin >> choice5;
					if (choice5!=1)
					{	
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while (choice5!=1);
			}
			
			else if ( choice2==3 )		// For Adding an Item
			{
				showitems();
				cout << "\nEnter ID: ";
				cin >> idadd;
				cout << "Name: ";
				cin >> itemname;
				cout << "Enter Quantity: ";
				cin >> qty;
				cout << "Enter Rate per item: ";
				cin >> rate;
				totalp = qty*rate;
				additem(idadd,itemname,qty,rate,totalp);
				showitems();
				do
				{
				cout << "\nEnter \'1\' to Go back: ";
				cin >> choice5;
					if (choice5!=1)
					{	
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while (choice5!=1);
				
			}
			
			else if ( choice2==4)		// To remove an item from stock
			{
				showitems();
				cout << "\nEnter ID that you want to remove: ";
				cin >> idrem;
				removeitem(idrem);
				showitems();
				do
				{
				cout << "\nEnter \'1\' to Go back: ";
				cin >> choice5;
					if (choice5!=1)
					{	
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while (choice5!=1);
			}
			
			else if ( choice2==5)		// Item search karne ke liye
			{
				cin.ignore();

				showitems();
				cout << "\nEnter Name of item that you want to search: ";
				cin.getline(namesearch,10);
				searchitem(namesearch);
				do
				{
				cout << "\nEnter \'1\' to Go back: ";
				cin >> choice5;
					if (choice5!=1)
					{	
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while (choice5!=1);
			}
			
			else if ( choice2==6)		// Employee ke credentials
			{
				do
				{
				cout << "\n1. Show Credentials" << endl;
				cout << "2. Add Credentials" << endl;
				cout << "3. Remove Credentials" << endl;
				cout << "\nChoose an option: ";
				cin >> choice8;
					if ( !(choice8>=1 && choice8<=3) )
					{
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while ( !(choice8>=1 && choice8<=3) );
					if (choice8==1)
					{
						employeeshow();
						do
						{
							cout << "\nEnter \'1\' to Go back: ";
							cin >> choice5;
							if (choice5!=1)
							{	
								cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
								cin.clear();
								cin.ignore();
							}
						}
						while (choice5!=1);
					}
					
					else if ( choice8==2 )
					{
						cin.ignore();
						employeeshow();
						cout << "Enter ID: ";
						cin.getline(employeenewid,20);
						cout << "PASSWORD: ";
						cin.getline(employeenewpass,20);
						addemployee( employeenewid , employeenewpass );
						employeeshow();
						cout << "New Employee Has been Added SUCCESSFULY!" << endl;
						do
						{
							cout << "\nEnter \'1\' to Go back: ";
							cin >> choice5;
							if (choice5!=1)
							{	
								cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
								cin.clear();
								cin.ignore();
							}
						}
						while (choice5!=1);
					}
					
					else if ( choice8==3 )
					{
						cin.ignore();
						employeeshow();
						cout << "Enter ID that you want to remove: ";
						cin.getline(employeenewid,20);
						rememployee( employeenewid );
						employeeshow();
						cout << "Employee's Credentials Have been Removed SUCCESSFULY!" << endl;
						do
						{
							cout << "\nEnter \'1\' to Go back: ";
							cin >> choice5;
							if (choice5!=1)
							{	
								cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
								cin.clear();
								cin.ignore();
							}
						}
						while (choice5!=1);
					
					}
					
			}
			
			else if ( choice2==7)		// Students ke credentials
			{
				do
				{
				cout << "\n1. Show Credentials" << endl;
				cout << "2. Add Credentials" << endl;
				cout << "3. Remove Credentials" << endl;
				cout << "\nChoose an option: ";
				cin >> choice8;
					if ( !(choice8>=1 && choice8<=3) )
					{
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while ( !(choice8>=1 && choice8<=3) );
					if (choice8==1)
					{
						studentshow();
						do
						{
							cout << "\nEnter \'1\' to Go back: ";
							cin >> choice5;
							if (choice5!=1)
							{	
								cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
								cin.clear();
								cin.ignore();
							}
						}
						while (choice5!=1);
					}
					
					else if ( choice8==2 )
					{
						cin.ignore();
						studentshow();
						cout << "Enter ID: ";
						cin.getline(studentnewid,20);
						cout << "PASSWORD: ";
						cin.getline(studentnewpass,20);
						addstudent( studentnewid , studentnewpass );
						studentshow();
						cout << "New Student Has been Added SUCCESSFULY!" << endl;
						do
						{
							cout << "\nEnter \'1\' to Go back: ";
							cin >> choice5;
							if (choice5!=1)
							{	
								cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
								cin.clear();
								cin.ignore();
							}
						}
						while (choice5!=1);
					}
					
					else if ( choice8==3 )
					{
						cin.ignore();
						studentshow();
						cout << "Enter name that you want to remove: ";
						cin.getline(studentnewid,20);
						remstudent( studentnewid );
						studentshow();
						cout << "Student's Credentials Have been Removed SUCCESSFULY!" << endl;
						do
						{
							cout << "\nEnter \'1\' to Go back: ";
							cin >> choice5;
							if (choice5!=1)
							{	
								cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
								cin.clear();
								cin.ignore();
							}
						}
						while (choice5!=1);
					
					}
					
			}
			
			
			else if ( choice2==8 )		// Manage Notifications
			{
				cin.ignore();
				do
				{
				cout << "\n1. See Notifications" << endl;
				cout << "\n2. Enter Notifications" << endl;
					cout << "\nEnter your Choice: ";
					cin >> choice10;
					if (choice10==1)
						notifyread();
					else if (choice10==2)
					{
						cin.ignore();
						cout << "\nEnter the Notification: ";
						cin.getline(arrnotify,100);
						notify(arrnotify);
						notifyread();
					}
					else
					{
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;
						cin.clear();
						cin.ignore();
					}
				}
				while (choice10!=1 && choice10!=2);
				do
				{
					cout << "\nEnter \'1\' to Go back: ";
					cin >> choice5;
						if (choice5!=1)
						{	
							cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
							cin.clear();
							cin.ignore();
						}
				}
				while (choice5!=1);
			}
			
			else if ( choice2==9 )		// For Online/Scheduled Orders
			{
				showorders();
				showbill();
				do
				{
					cout << BOLD << "\n1. Approve" << endl;
					cout << "2. Reject" <<  RESET << endl;
					cout << "\nEnter your choice: ";
					cin >> choice12;
						if (choice12==1)
							approval();
						else if (choice12==2)
							rejection();
						else
						{
							cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
							cin.clear();
							cin.ignore();
						}
				}
				while (choice12!=1 && choice12!=2);
				do
				{
					cout << "\nEnter \'1\' to Go back: ";
					cin >> choice5;
						if (choice5!=1)
						{	
							cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
							cin.clear();
							cin.ignore();
						}
				}
				while (choice5!=1);
			}
			
			else if ( choice2==10 )		// Displaying Complaints
			{
				cin.ignore();
				complaintsread();
				cout << "\nRespond To Copmlaints: ";
				cin.getline(arrnotify,100);
				notify(arrnotify);
				notifyread();
				do
				{
					cout << "\nEnter \'1\' to Go back: ";
					cin >> choice5;
						if (choice5!=1)
						{	
							cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
							cin.clear();
							cin.ignore();
						}
				}
				while (choice5!=1);
				
			}
			
			else if (choice2==11)		// Best Seller
			{
				showlist_best();
				cout << endl;
				bestsellershow();
				do
				{
					cout << "\nEnter \'1\' to Go back: ";
					cin >> choice5;
						if (choice5!=1)
						{	
							cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
							cin.clear();
							cin.ignore();
						}
				}
				while (choice5!=1);
			}
			
			else if (choice2==12)		// Low quantitiy items order karne ke liye 
			{
				showitems();
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Quantity: ";
				cin >> qty;
				f1 = orderadmin(id,qty);
				if (f1==1)
				{
					cout << "\nYour Order Has Been Cancelled!" << endl;
				}
				else
				{
					cout << "\n\t---   YOUR RECIEPT   ---" << endl;
					showbill();
				}
				showitems();
				do
				{
					cout << "\nEnter \'1\' to Go back: ";
					cin >> choice5;
						if (choice5!=1)
						{	
							cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
							cin.clear();
							cin.ignore();
						}
				}
				while (choice5!=1);
			}
			
			else if (choice2==13)		// Threshold wala (colour)
			{
				lowitems();
			do
			{
				cout << "\n1. Order" << endl;
				cout << "2. Cancel" << endl;
				cout << "\nWould you like to order? ";
				cin >> choice11;
					if (choice11==1)
					{
						showitems();
						cout << "Enter ID: ";
						cin >> id;
						cout << "Enter Quantity: ";
						cin >> qty;
						f1 = orderadmin(id,qty);
							if (f1==1)
							{
								cout << "\nYour Order Has Been Cancelled!" << endl;
							}
							else
							{
								cout << "\n\t---   YOUR RECIEPT   ---" << endl;
								showbill();
							}
							showitems();
					}
					else if (choice11==2)
					{
						cout << BLUE << BOLD << "\nYou Have Decided To Cancel!\n" << RESET << endl;
					}
			}
			while (choice11!=1 && choice11!=2);
						
				do
				{
					cout << "\nEnter \'1\' to Go back: ";
					cin >> choice5;
						if (choice5!=1)
						{	
							cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
							cin.clear();
							cin.ignore();
						}
				}
				while (choice5!=1);
			}
			
			else if (choice2==14)
			{
				quant = (rand()%10) + 1;		// random number generate hoga jo decrease hoga quantity mein se
				decrease(quant);	// Decrease karne ke liye function
				cout << BLUE << BOLD << "\nQUANTITY OF ITEMS HAS BEEN DECREASED RANDOMLY!" << RESET << endl;
			
			}
			
			else
			{
				cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;
				cin.clear();		// Takay koi character waghera na enter karde user
				cin.ignore();
			}
			
			}
			while ( !(choice2>0 && choice2<=12) );
		if (choice2==1)
			break;
	}
	while (choice5==1);
	}		// Admin Login ENDS HERE
	
	
	///////////////////     EMPLOYEE   LOGIN	///////////////////
	
	else if ( choice1==2 )	
	{	
		cin.ignore();		// To get rid of buffer value
		do
		{
			cout << BOLD << "\nEmployee ID: ";
			cin.getline(employee_id,12);
			cout << "\nPASSWORD: " << RESET;
			cin.getline(employee_pass,12);	
			f = func_employees(employee_id,employee_pass); // Func call for employees credentials
				
				if (f==1)		// IF function returns true
				{
					// Printing Design
					cout << BLUE << BOLD << "\n\t\t" << setfill ('*') << setw(20) << "*" << RESET << endl;
					cout << GREEN << BOLD << "\n\t\t*  Employee Login  *" << RESET << endl;
					cout << BLUE << BOLD << "\n\t\t" << setfill ('*') << setw(20) << "*" << RESET << endl;
				do
				{
					do
					{
					// Employee ke paas in cheezon ki access hai
					cout << BOLD << "\n1. Go Back" << endl;
					cout << "2. Take Orders" << endl;
					cout << "3. Search For Items" << endl;
					cout << "4. Generate a transaction" << endl;
					cout << "5. Online/Scheduled Orders" << RESET << endl;		
					cout << "\nEnter Your choice : ";
					cin >> choice3;
						if ( !(choice3>0 && choice3<=5) )
						{
							cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
							cin.clear();
							cin.ignore();
						}
					}
					while ( !(choice3>0 && choice3<=5) );
						if ( choice3==1 )
							break;
					
						else if ( choice3==2 )		//For displaying menu and ordering
						{
						do
						{
							showitems();
							cout << "Enter ID: ";
							cin >> id;
							cout << "Enter Quantity: ";
							cin >> qty;
							order(id,qty);
							do
							{
							cout << "\n1. Go Back" << endl;
							cout << "2. Keep ordering" << endl;
							cout << "3. View Bill" << endl;
							cout << "\nEnter your choice: ";
							cin >> choice6;
								if ( choice6!=1 && choice6!=2 && choice6!=3 )
								{		
									cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
									cin.clear();
									cin.ignore();
								}
							}
							while (choice6!=1 && choice6!=2 && choice6!=3);
								if (choice6==1)
									break;	
								else if (choice6==3)
								{
									cout << "\n\t---   YOUR RECIEPT   ---" << endl;
									showbill();
									do
									{
									cout << "\n1. Cancel" << endl;
									cout << "2. Confirm" << endl;
									cout << "\nEnter your choice: ";
									cin >> choice9;		
										if (choice9==1)
										{
											remove("bill.txt");
											cout << "Your Order Has Been Cancelled!" << endl;
											f2=1;
										}
										else if (choice9==2)
										{
											cout << "\nYour Order Has Been Confirmed!" << endl;
											bestseller(employee_id);
											f2=1;
										}
										else
										{
												
											cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
											cin.clear();
											cin.ignore();
										}
									}
									while (choice9!=1 && choice9!=2);
								}
						}
						while(choice6==2);
						}
						else if (choice3==3)
						{
							cin.ignore();
							showitems();
							cout << "\nEnter Name of item that you want to search: ";
							cin.getline(namesearch,10);
							searchitem(namesearch);
							do
							{
								cout << "\nEnter \'1\' to Go back: ";
								cin >> choice7;
								if (choice7!=1)
								{	
									cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
									cin.clear();
									cin.ignore();
								}
							}
							while (choice7!=1);
						}
						
						else if (choice3==4)
						{
							cout << "\n\t---   YOUR RECIEPT   ---" << endl;
							showbill();
							do
							{
								cout << "\nEnter \'1\' to Go back: ";
								cin >> choice7;
								if (choice7!=1)
								{	
									cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
									cin.clear();
									cin.ignore();
								}
							}
							while (choice7!=1);
						}
						
						else if (choice3==5)
						{
							showorders();
							showbill();
							do
							{
							cout << BOLD << "\n1. Approve" << endl;
							cout << "2. Reject" <<  RESET << endl;
							cout << "\nEnter your choice: ";
							cin >> choice12;
								if (choice12==1)
									approval();
								else if (choice12==2)
									rejection();
								else
								{
									cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
									cin.clear();
									cin.ignore();
								}
							}
							while (choice12!=1 && choice12!=2);
									
							
							do
							{
								cout << "\nEnter \'1\' to Go back: ";
								cin >> choice7;
								if (choice7!=1)
								{	
									cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
									cin.clear();
									cin.ignore();
								}
							}
							while (choice7!=1);
						}
				}
				while (choice7==1);
				}
				else
					cout << RED << BOLD << "\n\t---:   Incorrect ID or PASSWORD! Try Again   :---\n" << RESET << endl;
					
		}
		while (f!=1);
				
	}
			
			
	///////////////////     STUDENT   LOGIN	///////////////////
	
	else if (choice1==3)
	{
	do
	{
		do
		{		//	STUDENT YE KAAM KARSAKTA HAI	
		cout << BOLD << "\n1. Go Back" << endl;
		cout << "2. Search And Order" << endl;
		cout << "3. Search Items" << endl;
		cout << "4. Give And Schedule Order" << endl;
		cout << "5. Give Complaints" << endl;
		cout << "6. See Notifications" << RESET << endl;
		cout << "\nChoose an option: ";
		cin >> choice4;
			if (!(choice4>0 && choice4<=6))		// Input validation
			{	
				cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
				cin.clear();
				cin.ignore();
			}
		
		}
		while ( !(choice4>0 && choice4<=6) );
		
			if (choice4==1)
				break;
			
			else if ( choice4==2 )		//For displaying menu and ordering
			{
				do
				{
				showitems1();
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Quantity: ";
				cin >> qty;
				order(id,qty);
				showitems1();
				do
				{
				cout << "\n1. Go Back" << endl;
				cout << "2. Keep ordering" << endl;
				cout << "3. View Bill" << endl;
				cout << "\nEnter your choice: ";
				cin >> choice6;
					if (!(choice6>0 && choice6<=3))
					{	
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
					
				}
				while ( !(choice6>0 && choice6<=3) );
					if (choice6==1)
						break;	
					else if (choice6==3)
					{
						cout << "\n\t---   YOUR RECIEPT   ---" << endl;
						showbill();
						do
						{
						cout << "\n1. Cancel" << endl;
						cout << "2. Confirm" << endl;
						cout << "\nEnter your choice: ";
						cin >> choice9;
							if (choice9==1)
							{
								remove("bill.txt");
								ofstream fout;		// opening/creating bill in write mode
								fout.open ("bill.txt",ios::out);
								fout << "ID	" << "Name	" << "Qty	" << "Rate	" << "Total" << "\n";
								fout.close();	
								cout << "Your Order Has Been Cancelled!" << endl;
								f2=1;
							}
							else if (choice9==2)
							{
								cout << "\nYour Order Has Been Confirmed!" << endl;
								cout << "THANK YOU FOR ORDERING" << endl;
								f2=1;
							}
							else
							{
								cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
								cin.clear();
								cin.ignore();
							}
						}
						while (choice9!=1 && choice9!=2);			
					}
				}
				while(choice6==2);
			}
			
			else if ( choice4==3 )		// Search karne ke liye by name
			{
				cin.ignore();
				showitems1();
				cout << "\nEnter Name of item that you want to search: ";
				cin.getline(namesearch,10);
				searchitem(namesearch);
				do
				{
				cout << "\nEnter \'1\' to Go back: ";
				cin >> choice6;
					if (choice6!=1)
					{
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while (choice6!=1);
			}
			
			else if ( choice4==4 )		//  STUDENT LOGIN 
			{	
				cin.ignore();
				do
				{		// To get rid of buffer value
				cout << BOLD << "\nStudent ID: ";
				cin.getline(student_id,20);
				cout << "\nPASSWORD: " << RESET;
				cin.getline(student_pass,20);	
				f = func_students(student_id,student_pass); // Func call for students credentials
				
					if (f==1)		// IF function returns true
					{
						// Printing Design
						cout <<  BLUE << BOLD << "\n\t\t" << setfill ('*') << setw(20) << "*" << RESET << endl;	
						cout << GREEN << BOLD << "\n\t\t*  Student's Login *" << RESET << endl;
						cout << BLUE << BOLD << "\n\t\t" << setfill ('*') << setw(20) << "*" << RESET << endl;
						do
						{
							showitems1();
							cout << "Enter ID: ";
							cin >> id;
							cout << "Enter Quantity: ";
							cin >> qty;
							order(id,qty);
							showitems1();
							do
							{
							cout << "\n1. Go Back" << endl;
							cout << "2. Keep ordering" << endl;
							cout << "3. Confirm order" << endl;
							cout << "\nEnter your choice: ";
							cin >> choice6;
								if (!(choice6>0 && choice6<=3))
								{	
									cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
									cin.clear();
									cin.ignore();
								}
							}
							while ( !(choice6>0 && choice6<=3) );
								if (choice6==1)
									break;	
								else if (choice6==3)
								{
									cout << "\nEnter time for Pick Up (00 : 00 am/pm): ";
									cin.ignore();
									cin.getline(time,20);
									cout << "\n\t---   YOUR RECIEPT   ---" << endl;
									showbill();
									do
									{
									cout << "\n1. Cancel" << endl;
									cout << "2. Confirm" << endl;
									cout << "\nEnter your choice: ";
									cin >> choice9;		
										if (choice9==1)
										{
											remove("bill.txt");
											ofstream fout;		// opening/creating bill in write mode
											fout.open ("bill.txt",ios::out);
											fout << "ID	" << "Name	" << "Qty	" << "Rate	" << "Total" << "\n";
											fout.close();	
											cout << "Your Order Has Been Cancelled!" << endl;
											f2=1;
										}
										else if (choice9==2)
										{
											cout << RED << BOLD << "\nPLEASE WAIT FOR APPROVAL OF YOUR ORDER!" << RESET << endl;
											cout << RED << BOLD << "\nKEEP CHECKING NOTIFICATIONS FOR APPROVAL!" << RESET << endl;
											orderonline(time,student_id);
											f2=1;
										}
										else
										{
											cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
											cin.clear();
											cin.ignore();
										}
									}
									while (choice9!=1 && choice9!=2);
								
								}
						}
						while(choice6==2);				
					}
					
					else
						cout << RED << BOLD << "\n\t---:   Inavlid ID or Password! Try Again   :---\n" << RESET <<  endl;	
					}
					while(f!=1);
					
			}
			
			else if ( choice4==5 )
			{
				cin.ignore();
				cout << "\nEnter the Complaint: ";
				cin.getline(arrcomplaint,100);
				complaints(arrcomplaint);
				cout << "\nYour Complaint has been submitted!" << endl;
				cout << "Thank you for pointing it out!" << endl;
				do
				{
				cout << "\nEnter \'1\' to Go back: ";
				cin >> choice6;
					if (choice6!=1)
					{
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while (choice6!=1);
			}
			
			else if ( choice4==6 )
			{
				notifyread();
				do
				{
				cout << "\nEnter \'1\' to Go back: ";
				cin >> choice6;
					if (choice6!=1)
					{
						cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;	
						cin.clear();
						cin.ignore();
					}
				}
				while (choice6!=1);
			}
	
	}
	while(choice6==1);
	}
	
	else
	{
		cout << RED << BOLD << "\n\t---:   Inavlid Entry! Try Again   :---\n" << RESET <<  endl;
		cin.clear();
		cin.ignore();
	}
}
while(choice1!=1 && choice1!=2 && choice1!=3);

}
while (choice4==1 || choice2==1 || choice3==1 || f2==1);

return 0;
}
