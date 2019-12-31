//Student Name: Nasheha Baset
//University of Texas at Dallas
//Course: CS 5303-001
//Instructor: Dr. Eric W. Becker
//Homework #2
//September 21, 2018
//Lenovo Ideapad 320 running Windows 10
//Using Visual Studio Community 2017
//Study Group: NULL



using namespace std;                                                                //Calling the library

#include <iostream>
#include <vector>
#include <string>
#include <math.h>



void output_name();
void menu();
vector<double> input_vector();
void show_vector(vector <double>);
void find_min(vector <double>);
void find_max(vector <double>);
double find_total(vector <double>);
double find_average(vector <double>);
double find_variance(vector <double>);
void find_standard_deviation(vector <double>);




void pause() //Function to pause the screen
{
	getchar();
	cout << "Press enter to continue.";
	while (getchar() == NULL);
	return;
}



int main(int argument_count, char ** argument_vector)    //Main Function that tells the program to run the output name and the menu functions with it.
{
	output_name();
	menu();

	return 0;
}



void output_name()
{
	cout << "Nasheha Baset" << endl;
}



void menu()
{
	bool go = true;

	vector <double> data = {};                                  //To allow the user to see


	while (go) {                                                  //display of menu options
		int choice = 0;

		cout << "Please choose an option from the menu below by typing the number corresponding to the choice." << endl;
		cout << "1. Input Vector" << endl;
		cout << "2. Show Vector" << endl;
		cout << "3. Find Min" << endl;
		cout << "4. Find Max" << endl;
		cout << "5. Total" << endl;
		cout << "6. Average" << endl;
		cout << "7. Variance" << endl;
		cout << "8. Standard Deviation" << endl;
		cout << "9. Quit" << endl;
		cout << "--------------" << endl;




		cin >> choice;                                               //Number chosen by the user.




		switch (choice) {                                             //initializing all of the variables before defining them
		case 1:
			data = input_vector();
			break;
		case 2:
			show_vector(data);
			break;
		case 3:
			find_min(data);
			break;
		case 4:
			find_max(data);
			break;
		case 5:
			find_total(data);
			break;
		case 6:
			find_average(data);
			break;
		case 7:
			find_variance(data);
			break;
		case 8:
			find_standard_deviation(data);
			break;
		case 9:
			go = 0;                                                        //0==false
			break;
		default:
			cout << "Please enter a valid menu option." << endl;
			break;
		}

		cout << "--------------" << endl;

	}
	return;
}



vector<double>input_vector()                                      //not sure how to get the user to input a number into the vector
{
	vector<double>user_vector = {};                               
	string input_value;                                           
	bool check_q = 1;                                             //checking if a q is present after the cout statement
	double temp;										  		  //defining temp for use for string to double conversion (done in else statement)

	cout << "Please enter one or more floating point numbers. When finished, enter 'q'." << endl;

	while (check_q!=0)
	{
		cin >> input_value;

		if (input_value == "q")
		{
			check_q = 0;                                               //checks to see if "q" has been entered, which means that the user is done
		}
		else {
			temp = stod(input_value);                                  //convert the values in the vector from string to double
			user_vector.push_back(temp);                               //using the pushback function to put the user values in the vector list
		}
	}

	return user_vector;
}



void show_vector(vector<double>user_vector)
{
	for (int i = 0; i < user_vector.size(); i++)                         //parameters include that the ??????
	{
		cout << user_vector[i] << endl;                                  //displays what is currently in the vector
	}
	cout << "\n";

	return;
}



void find_min(vector<double>user_vector)
{
	double min = 1000000.00;                                          //initializing the min value

	for (int i = 0; i < user_vector.size(); i++)
	{
		if (user_vector[i] < min)
		{
			min = user_vector[i];
		}
	}
	cout << "The minimum value is " << min << "."<< endl;
	cout << "\n";

	return;
}



void find_max(vector < double > user_vector)
{
	double max = -1000000.00;                                            //initializing the max value
	for (int i = 0; i < user_vector.size(); i++)
	{
		if (user_vector[i] > max)
		{
			max = user_vector[i];
		}
	}

	cout << "The maximum value is " << max<<"." << endl;
	cout << "\n";

	return;
}



double find_total(vector<double>user_vector)
{
	double total = 0;

	for (int i = 0; i < user_vector.size(); i++)
	{
		total += user_vector[i];
	}

	cout << "The total is " << total << "." << endl;

	return total;
}



double find_average(vector<double>user_vector)
{
	double average = 0;
	double total = find_total(user_vector);


	for (int i = 0; i < user_vector.size(); i++)
	{
		average = total / user_vector.size();
	}

	cout << "The average is " << average << "." << endl;

	return average;
}



double find_variance(vector<double>user_vector)
{
	double variance = 0;
	double average = find_average(user_vector);
	double numerator = 0;

	for (int i = 0; i < user_vector.size(); i++)
	{
		numerator += pow(average - user_vector[i], 2);
	}

	variance = numerator / user_vector.size();

	cout << "The variance is " << variance << "." << endl;

	return variance;
}



void find_standard_deviation(vector<double>user_vector)
{
	double stdv = 0;
	double variance = find_variance(user_vector);

	stdv = sqrt(variance);

	cout << "The standard deviation is " << stdv << "." << endl;

	return;
}