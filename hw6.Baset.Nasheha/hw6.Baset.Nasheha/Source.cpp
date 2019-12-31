//Student Name: Nasheha Baset
//University of Texas at Dallas
//Course: CS 5303-001
//Instructor: Dr. Eric W. Becker
//Homework #6
//December 5, 2018
//Lenovo Ideapad 320 running Windows 10
//Using Visual Studio Professional 2017
//Study Group: NULL

//-------------------------------
// Calls the Libraries and the namespace
//-------------------------------
using namespace std;                                                                //Calling the library

#include <iostream>
#include <math.h>
#include <iomanip>

//-------------------------------
// Prototypes
//-------------------------------
void output_name();
void menu();


//-------------------------------
//Displays my name
//-------------------------------

void output_name()
{
	cout << "Nasheha Baset" << endl;
}

//-------------------------------
//Class for the 3x3 matrix
//-------------------------------

class Matrix
{
private:
	int data[3][3];
public:
	Matrix();
	void CreateMatrix();
	Matrix operator +(Matrix other);
	Matrix operator *(Matrix other);
	void Show();
};

//-------------------------------
//Main
//-------------------------------
int main()
{
	output_name();
	menu();

	return 0;

}

//-------------------------------
//Matrix class rows and col
//-------------------------------
Matrix::Matrix()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (row == col)
			{
				data[row][col] = 1;
			}
			else
			{
				data[row][col] = 0;
			}
		}

	}
}

//-------------------------------
//Shows the rows and col
//-------------------------------

void Matrix::Show()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (col == 0)
			{
				cout << "|";
			}

			cout << setw(10) << data[row][col];

			if (col == 2)
			{
				cout << "|\n";
			}
		}

	}
}

//-------------------------------
//Adding the matrices
//-------------------------------

Matrix Matrix::operator +(Matrix other)
{
	Matrix Temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Temp.data[i][j] = this->data[i][j] + other.data[i][j];
		}
			}
	return Temp;
}

//-------------------------------
//Multiplying the matrices
//-------------------------------

Matrix Matrix::operator *(Matrix other)
{
	Matrix Temp;
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum = 0;
			for (int k = 0; k < 3; k++)
			{
				sum += this->data[i][k] * other.data[k][j];
			}
			Temp.data[i][j] = sum;
		}
	}
	return Temp;
}

//-------------------------------
// Asks the user to input values for the matrices
//-------------------------------
void Matrix::CreateMatrix() {

	for (int row = 0; row < 3; row++) {
		int choice = 0;
		for (int col = 0; col < 3; col++)
		{
			cout << "Please enter an integer value for " << row + 1 << " and column " << col + 1 << " :" << endl;
			cin >> choice;
			data[row][col] = choice;
		}
	}
}

//-------------------------------
//Menu Function
//-------------------------------

void menu()							//Taken and modified from homework 3
{
	bool go = true;
	Matrix A;
	Matrix B;
	Matrix C;
	while (go) 
	{                      //display of menu options
		int choice = 0;

		cout << "Matrix Manipulation" << endl;
		cout << "-------------------------------------" << endl;
		cout << "1. Create first matrix." << endl;
		cout << "2. Create second matrix." << endl;
		cout << "3. Multiply matrices." << endl;
		cout << "4. Add matrices." << endl;
		cout << "5. Show all three matrices." << endl;
		cout << "6. Quit" << endl;
		cout << "-------------------------------------" << endl;

		cin >> choice;


		switch (choice) {
		case 1:
			A.CreateMatrix();
			break;
		case 2:
			B.CreateMatrix();
			break;
		case 3:
			C = A * B;
			break;
		case 4:
			C = A + B;
			break;
		case 5:
			cout << "First Matrix: \n";
			A.Show();

			cout << "Second Matrix: \n";
			B.Show();

			cout << "Result Matrix: \n";
			C.Show();
			break;
		case 6:
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
