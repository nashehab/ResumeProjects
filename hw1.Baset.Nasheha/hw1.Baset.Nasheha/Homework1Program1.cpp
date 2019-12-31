//Student Name: Nasheha Baset
//University of Texas at Dallas
//Course: CS 5303-001
//Instructor: Dr. Eric W. Becker
//Homework #1
//September 7, 2018
//Lenovo Ideapad 320 running Windows 10
//Using Visual Studio Community 2017
//Study Group: NULL

using namespace std;
#include <iostream>

void pause()
{
	cout << "Press enter to continue\n";
	while (getchar() == NULL);
	return;
}


void first_contact()
{
	cout << "Greetings, human.\n";
	cout << "This is your computer speaking to you.\n";
	cout << "My name is Lenny Lenovo. I come in peace.\n";
	cout << "Take me to your leader, meat-bag.\n";
}


int main(int argument_count, char ** argument_array)
{
	first_contact();
	pause();
	return 0;
}
