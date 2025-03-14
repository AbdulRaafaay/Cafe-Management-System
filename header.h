#ifndef HEADER_H
#define HEADER_H

// Adding Colours
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"

// Essential Libraries
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;

void func_admin(char [], char []);		// Func for admin credentials

bool func_employees(char [], char []);		// Funtions for employees credentials	

bool func_students(char [], char []);		// Funtions for Students credentials	

void showitems(void);		// Func for displaying menu

void additem(int,char [],int,int,int);		// Func for adding items

void notify(char []);		// Func for managing notifications

void notifyread(void);		// Students ke liye notifications dekhne ke liye

void removeitem(int);		// items remove karne ke liye

void searchitem( char []);		// items search karne ke liye

void complaints(char []);		// Func for managing complaints

void complaintsread(void);		// Func for managing complaints

void employeeshow(void);		// Admin ko employees dikhanay ke liye

void addemployee(char [], char []);		// Employees Add karne ke liye

void rememployee(char []);		// Employees Remove karne ke liye

void studentshow(void);		// Admin Ko students dikhanay ke liye

void addstudent(char [], char []);		// Studnets Add karne ke liye

void remstudent(char []);		// Studnets Remove karne ke liye

void order(int, int);		// Order karne ke liye

void showbill(void);		// Bill display karwane ke liye

void orderonline(char [],char []);		// Online orders ke liye

void showorders(void);		// Func for online orders for admin

void bestseller(char []);		// Best seller employee ke liye

void bestsellershow(void);		// Best seller employee ke liye

void showlist_best(void);		// Best sellers ki list dikhanay ke liye

bool orderadmin(int, int);		// Admin ke Order ke liye

void lowitems(void);		// Low quantity items ko manage karne ke liye

void items(void);		// Items function jo main ke shuru mein call hota

void showitems1(void);		// student ko items dikhanay  ke liye without total

void approval(void);		// Online order approve

void rejection(void);		// Online order Reject

void decrease(int);		// Randomly quantity decrease ke liye



#endif
