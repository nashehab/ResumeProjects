//Student Name: Nasheha Baset
//University of Texas at Dallas
//Course: CS 5303-001
//Instructor: Dr. Eric W. Becker
//Homework #3
//October 12, 2018
//Lenovo Ideapad 320 running Windows 10
//Using Visual Studio Professional 2017
//Study Group: NULL

#define _CRT_SECURE_NO_WARNINGS

using namespace std;                                                                //Calling the library

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

class Counter
{
private:
	vector<int>vec;

public:
	Counter();
	void increment(int index);
	void showcount();
	int normalization(int index);
};

void output_name();
void menu();
//vector<string> input_vector();
vector<int> loadString();
void calculate_statistics(vector <int>);
void write_file(double total, double average, double variance, double stdv);
void perform_count(vector <int>);
void display_bargraph(Counter count);
vector <string> split3(string source, string delim);
double find_standard_deviation(vector<int>user_vector);
double find_variance(vector<int>user_vector);
double find_average(vector<int>user_vector);
double find_total(vector<int>user_vector);



//=========================================
//Name of Function: Pause
//Input Parameters: none
//Return Type: none
//Description: Pauses the program.
//=========================================

void pause() //Function to pause the screen
{
	getchar();
	cout << "Press enter to continue.";
	while (getchar() == NULL);
	return;
}

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

	vector <int> data = {};       //To allow the user to see
	double total = 0.0;
	double average = 0.0;
	double variance = 0.0;
	double stdv = 0.0;

	Counter count;

	while (go) {                      //display of menu options
		int choice = 0;

		cout << "Please choose an option from the menu below by typing the number corresponding to the choice." << endl;
		cout << "1. Load From a File" << endl;
		cout << "2. Calculate the Statistics" << endl;
		cout << "3. Write to a File" << endl;
		cout << "4. Perform the Count" << endl;
		cout << "5. Display the Bargraph" << endl;
		cout << "6. Quit" << endl;
		cout << "-------------------------------------" << endl;




		cin >> choice;             //Number chosen by the user.




		switch (choice) {           //initializing all of the variables before defining them
		case 1:
			data = loadString();			//do I need to put (data) next to it?
			break;
		case 2:
			total = find_total(data);
			average = find_average(data);
			variance = find_variance(data);
			stdv = find_standard_deviation(data);
			cout << "Total   :" << fixed << setprecision(2) << total << endl;
			cout << "Average :" << fixed << setprecision(2) << average << endl;
			cout << "Variance:" << fixed << setprecision(2) << variance << endl;
			cout << "StDev	:" << fixed << setprecision(2) << stdv << endl;
			break;
		case 3:
			write_file(total, average, variance, stdv);
			break;
		case 4:
			for (int i = 0; i < data.size(); i++)
			{
				count.increment(data[i]);
			}
			count.showcount();
			break;
		case 5:
			display_bargraph(count);
			break;
		case 6:
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

//=========================================
//Name of Function: This is a vector that holds file data to tokenize.
//Input Parameters:int
//Return Type: Returns a result of an integer.
//Description: Part of the overall tokenizer to analyze the data
//=========================================


vector<int> loadString()		////Taken from Dr. Becker's 2018 sample code "SunSithStreams"
{
	string data;
	vector <int> result;
	vector <string> vstring;

	ifstream inputstream;
	int temp;
	int count;
	char delim;

	string filename;
	cout << "Please type in a file name." << endl;
	cin >> filename;

	inputstream.open(filename);

	while (!inputstream)
	{
		cout << "Error, not the correct file type. Please type in a file name." << endl;
		cin >> filename;

		inputstream.open(filename);

	}
	inputstream >> data;

	inputstream.close();

	string delim_set = ",";

	vstring = split3(data, delim_set);

	for (string d : vstring)
	{
		char *local_d = (char *)d.c_str();
		int intval = atoi(local_d);
		result.push_back(intval);
	}

	return result;
}

//=========================================
//Name of Function: Another vector that helps to conduct the 
//Input Parameters: string
//Return Type: Returns the result in a string.
//Description: Tokenizes the data to make useable for analysis.
//=========================================

vector <string> split3(string source, string delim)		//Taken from Dr. Becker's 2018 sample code "SunSithStreams"
{
	vector<string> result = {};
	char * temp = NULL;
	char * remain = NULL;
	char * str_source = (char *)source.c_str();
	char * str_delim = (char *)delim.c_str();

	//cout << source << endl;
	//cout << delim << endl;

	temp = strtok(str_source, str_delim);
	//cout << "[" << temp << "]" << endl;//1

	result.push_back(temp);

	while (temp != NULL)
	{
		temp = strtok(NULL, str_delim);
		if (temp != NULL)//GUARD CONDITION
		{
			//cout << "[" << temp << "]";//2
			result.push_back(temp);
		}
	}



	return result;
}

//=========================================
//Name of Function: find_total
//Input Parameters: the integer vector created after tokenization
//Return Type: double
//Description: Uses what what tokenized by the vectors above to calculate the total of the data.
//=========================================

double find_total(vector<int>user_vector)
{
	double total = 0;

	for (int i = 0; i < user_vector.size(); i++)
	{
		total += user_vector[i];
	}

	return total;
}

//=========================================
//Name of Function: find_average
//Input Parameters: the integer vector created after tokenization
//Return Type: double
//Description: Uses what what tokenized by the vectors above to calculate the average of the data.
//=========================================

double find_average(vector<int>user_vector)
{
	double average = 0;
	double total = find_total(user_vector);


	for (int i = 0; i < user_vector.size(); i++)
	{
		average = total / user_vector.size();
	}

	return average;
}

//=========================================
//Name of Function: find_variance	
//Input Parameters: the integer vector created after tokenization
//Return Type: double
//Description: Uses what what tokenized by the vectors above to calculate the variance of the data.
//=========================================

double find_variance(vector<int>user_vector)
{
	double variance = 0;
	double average = find_average(user_vector);
	double numerator = 0;

	for (int i = 0; i < user_vector.size(); i++)
	{
		numerator += pow(average - user_vector[i], 2);
	}

	variance = numerator / user_vector.size();

	return variance;
}

//=========================================
//Name of Function: find_standard_deviation
//Input Parameters: the integer vector created after tokenization
//Return Type: double
//Description: Uses what what tokenized by the vectors above to calculate the standard deviation of the data.
//=========================================

double find_standard_deviation(vector<int>user_vector)
{
	double stdv = 0;
	double variance = find_variance(user_vector);

	stdv = sqrt(variance);

	return stdv;
}

//=========================================
//Name of Function: write_file
//Input Parameters: Total, average, variance, and standard deviation as calculated by the four functions above.
//Return Type: none
//Description: Writes what was found in the calculations into a new file, but first creating the file, opening the file, putting the stats in the file, and closing the file.
//=========================================


void write_file(double total, double average, double variance, double stdv)
{
	string oname;
	cout << "Please enter a name you would like of the output file: " << endl;
	cin >> oname;

	ofstream ost;			//initialized the output stream
	ost.open(oname);

	while (!ost)
	{
		cout << "Please input another file name." << endl;
		cin >> oname;

		ost.open(oname);
	}


	ost << "Nasheha Baset" << endl;
	ost << "---------------" << endl;
	ost << "Total    : " << fixed << setprecision(2) << total << endl;		//setprecision from cplusplus.com/reference.iomanip/setprecision/
	ost << "Average  : " << fixed << setprecision(2) << average << endl;
	ost << "Variance : " << fixed << setprecision(2) << variance << endl;
	ost << "StDev    : " << fixed << setprecision(2) << stdv << endl;




	ost.close();			//closes the output file

	return;
}

//=========================================
//Name of Function: counter
//Input Parameters: none (technically the information present in the vector)
//Return Type: none
//Description: A class created to count the ammount of each number present in the file.
//=========================================

Counter::Counter()
{
	for (int i = 0; i < 13; i++)
	{
		vec.push_back(0);		//creates and empty object for the counter class. The constructor is called automatically whenever you create a counter object, for example Counter count;
	}
}

//=========================================
//Name of Function: increment
//Input Parameters: int
//Return Type: none
//Description: This takes the number counted from the counter above, and incremently counts it.
//=========================================

void Counter::increment(int index)
{
	vec[index] += 1;

}

//=========================================
//Name of Function: showcount
//Input Parameters: none (technically the information that is present from the counter function above)
//Return Type: none
//Description: This shows what was counted and how many.
//=========================================

void Counter::showcount()
{
	for (int i = 2; i < 10; i++)
	{
		cout << i << " |" << vec[i] << endl;
	}
	for (int i = 10; i < 13; i++)
	{
		cout << i << "|" << vec[i] << endl;
	}
}

//=========================================
//Name of Function: normalization
//Input Parameters: int
//Return Type: int
//Description: This takes the counted data and divides it by 1000 to later display on a bar graph.
//=========================================


int Counter::normalization(int index)
{
	vec[index] = vec[index] / 1000;

	return vec[index];
}

//=========================================
//Name of Function: display_bargraph
//Input Parameters: the count from the counter
//Return Type: none
//Description: Displays a bargraph of the results from the counted data.
//=========================================

void display_bargraph(Counter count)
{
	int rowmax = 0;				//Taken from Dr. Becker's homework 3 instructions
	for (int i = 2; i < 10; i++)
	{
		cout << i;
		cout << " | ";
		rowmax = count.normalization(i);
		for (int j = 0; j < rowmax; j++)
		{
			cout << "X";
		}
		cout << endl;
	}
	for (int i = 10; i <= 12; i++)
	{
		cout << i;
		cout << "| ";
		rowmax = count.normalization(i);
		for (int j = 0; j < rowmax; j++)
		{
			cout << "X";
		}
		cout << endl;
	}
}
