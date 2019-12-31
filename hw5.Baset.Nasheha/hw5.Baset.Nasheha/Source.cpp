//Student Name: Nasheha Baset
//University of Texas at Dallas
//Course: CS 5303-001
//Instructor: Dr. Eric W. Becker
//Homework #5
//November 16, 2018
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

// Prototypes
void output_name();
void menu();

//------------------------------
//Container Class
//Contains the Base Class: MobilPhone, Member Data: TelephoneNumber and RingTone, Member Function: "RING!" and Show Number, and Virtual Fuctions: virtual fuction "Ring()"
//------------------------------

class MobilePhone {
protected:
	string TelephoneNumber;
	string RingTone;

public:

	MobilePhone() {}
	void ShowNumber() {
		cout << TelephoneNumber;
	}
	void SetNumber(string number) {
		TelephoneNumber = number;
	}
	virtual void Ring() {
		ShowNumber();
		cout << RingTone << endl;
	}

};

//-------------------------------------------------
//Derived classes that are inherited from Mobile Phone: Goggle Phone, Doors Phone, and Robot Phone, with each derived classes having its own Ring() fuction.
//-------------------------------------------------

class DoorsPhone : public MobilePhone {
public:
	DoorsPhone() {
		RingTone = ":  brt!";
	}
	void Ring() {
		ShowNumber();
		cout << RingTone << endl;
	}
};

class GogglePhone : public MobilePhone {
public:
	GogglePhone() {
		RingTone = ":  Beep!";
	}
	void Ring() {
		ShowNumber();
		cout << RingTone << endl;
	}
};

class RobotPhone : public MobilePhone {
public:
	RobotPhone() {
		RingTone = ":  Go! Go! Ro! Bot! Phone!";
	}
	void Ring() {
		ShowNumber();
		cout << RingTone << endl;
	}
};
//----------------------------------------------------
//Vector to create random phone numbers with each class of phone
//----------------------------------------------------

vector <MobilePhone*> LoadPhonebook()
	{

		vector <MobilePhone*> vec;
		int n = -1;
		int m = -1;

	for (int i = 0; i < 37; i++)
	{
		n = rand();
		string num = "123-000-00";
		m = rand() %10;
		num += to_string(m);
		m = rand() % 10;
		num += to_string(m);

		if (n % 3 == 0) 
		{					
			GogglePhone* temp = new GogglePhone;
			temp->SetNumber(num);
			vec.push_back(temp);
		}
		else if (n % 3 == 1) 
		{
			RobotPhone* temp = new RobotPhone;
			temp->SetNumber(num);
			vec.push_back(temp);
		}
		else if(n % 3 == 2) 
		{
			DoorsPhone* temp = new DoorsPhone;
			temp->SetNumber(num);
			vec.push_back(temp);
		}
	}

	return vec;
}

//-------------------------------------------------------
// Main fuction that displays my name and the menu in order to choose everything.
//-------------------------------------------------------
int main(void) {

	output_name();
	menu();

	return 0;
}

//-------------------------------------------------------
// Prints my name on the screen.
//-------------------------------------------------------
void output_name()
{
	cout << "Nasheha Baset" << endl;
}

//-------------------------------------------------------
// Prints the menu for the user to choose their option
//-------------------------------------------------------

void menu()							//Taken and modified from homework 3
{
	bool go = true;
	vector <MobilePhone*> phoneList;

	while (go) {                      //display of menu options
		int choice = 0;

		cout << "Please choose an option from the menu below by typing the number corresponding to the choice." << endl;
		cout << "1. Load the container." << endl;
		cout << "2. Traverse." << endl;
		cout << "3. Quit" << endl;
		cout << "-------------------------------------" << endl;

		cin >> choice;


		switch (choice) {
		case 1:
			phoneList = LoadPhonebook();						//How do I get the containers to load for this option?
			break;
		case 2:
			for (int i = 0; i < 37; i++)
			{
				(*phoneList[i]).Ring();// issue!!!!!!
			}
			break;
		case 3:
			go = 0;                 //0==false
			break;
		default:
			cout << "Please enter a valid menu option." << endl;
			break;
		}

		cout << "-------------------------------------" << endl;

	}
	return;
}