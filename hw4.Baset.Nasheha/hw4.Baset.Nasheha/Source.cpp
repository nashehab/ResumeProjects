//Student Name: Nasheha Baset
//University of Texas at Dallas
//Course: CS 5303-001
//Instructor: Dr. Eric W. Becker
//Homework #4
//October 26, 2018
//Lenovo Ideapad 320 running Windows 10
//Using Visual Studio Professional 2017
//Study Group: NULL


using namespace std;                                                                //Calling the library

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <list>
#include <array>

void output_name();
void menu();


//=========================================
//Name of Function: OneStopFibonacciShop
//Input Parameters: fibonacci numbers
//Return Type: class
//Description: It takes a sequence of 20 fibonacci numbers, calculates the values, and stores them in a vector.
//=========================================
class OneStopFibonacciShop
{
private:
	vector<int>values;
	list<int>fiblist;
	int arr[20];

public:
	OneStopFibonacciShop()
	{
		for (int i = 0; i < 20; i++)
		{
			values.push_back(0);
		}
	}

	void fibout()
	{
		//vector calculations
		for (int i = 0; i < 20; i++)
		{
			if (i == 0)
			{
				values[i] = i;
			}
			else if (i == 1)
			{
				values[i] = i;
			}
			else
			{
				values[i] = values[i - 1] + values[i - 2];
			}
		}

		//array calculation
		for (int i = 0; i < 20; i++)
		{
			if (i == 0)
			{
				arr[i] = i;
			}
			else if (i == 1)
			{
				arr[i] = i;
			}
			else
			{
				arr[i] = arr[i - 1] + arr[i - 2];
			}
		}

		//list calculation
		for (int i = 0; i < 20; i++)
		{
			fiblist.push_back(arr[i]);
		}
	
	}

	void printnum()
	{
		cout << "Vector: ";
		for (int i = 0; i < 19; i++) {
			cout << values[i] << ",";
		}
		cout << values[19];

		cout << endl;

		cout << "Array : ";
		for (int i = 0; i < 19; i++)
		{
			cout << arr[i] << ",";
		}
		cout << arr[19];
		
		cout<<endl;

		cout << "List  : ";

		list<int>::iterator it = fiblist.begin();
		while ( it != fiblist.end())
		{
			cout << *it;
			it++;
			if (it != fiblist.end())
			{
				cout << ",";
			}
		}
		cout << endl;

		cout << endl;
	}

	
	

};

//=========================================
//Name of Function: PrinceofPointers
//Input Parameters: stored memory
//Return Type: class
//Description: Points the computer to where the data was stored, loads it onto an array, and displays it to the user in the output.
//=========================================

class PrinceofPointers
{
public:
	long long array2[20];
	long long *ptr;
	void loadArray()
	{
		for (int i = 0; i < 20; i++)
		{
			if (i == 0)
			{
				array2[i] = 1;
			}
			else if (i == 1)
			{
				array2[i] = 1;
			}
			else
			{
				array2[i] = array2[i - 1] * i;
			}
		}
	}

	void displayprints()
	{
		ptr = array2;
		for (long long i = 0; i < 20; i++)
		{
			cout << " Memory Address:  " << hex << ptr + i << "	";
			cout <<"Fibonacci Number:  "<< dec <<*(ptr + i) << endl;


		}
	}
};

//=========================================
//Name of Function: main
//Input Parameters: the arguements presented
//Return Type: int
//Description: It summarizes everything that needs to be run in the program. Everything that needs to be done MUST be present in the function.
//=========================================

int main(int argument_count, char ** argument_vector)    //Main Function that tells the program to run the output name and the menu functions with it.
{
	output_name();
	menu();

	return 0;
}

//=========================================
//Name of Function:output_name
//Input Parameters:none
//Return Type:none
//Description:This just prints name without any input.
//=========================================

void output_name()
{
	cout << "Nasheha Baset" << endl;
}

//=========================================
//Name of Function: menu
//Input Parameters:none
//Return Type:none
//Description:Contains a chain of commands that need to be completed when the user chooses certain options, and the option is executed accordingly.
//=========================================

void menu()							//Taken and modified from homework 3
{
	bool go = true;

	vector<int>values = {};       //To allow the user to see
	OneStopFibonacciShop fibon;
	PrinceofPointers prince;
	   
	while (go) {                      //display of menu options
		int choice = 0;

		cout << "Please choose an option from the menu below by typing the number corresponding to the choice." << endl;
		cout << "1. Test containers." << endl;
		cout << "2. Test pointers." << endl;
		cout << "3. Quit" << endl;
		cout << "-------------------------------------" << endl;

		cin >> choice;


		switch (choice) {           //initializing all of the variables before defining them
		case 1:
			 fibon.fibout();//do I need to put (data) next to it?
			 fibon.printnum();
			break;
		case 2:
			prince.loadArray();
			prince.displayprints();
			break;
		case 3:
			go = 0;                   //0==false
			break;
		default:
			cout << "Please enter a valid menu option." << endl;
			break;
		}

		cout << "--------------" << endl;

	}
	return;
}
