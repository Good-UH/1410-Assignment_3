/* COSC 1410, Assignment 3
Wednesday, September 23, 2014
Write a program that asks for the person's height, weight, and age,
and then computes clothing sizes according to the formulas: 
Hat Size = weight in pounds divided by height in inches and all that multiplied by 2.9.
Waist in inches = weight divided by 5.7 and then adjusted by adding 1/10 of an inch for 
each 2 years over age 28. Assume that the user will ALWAYS enter a number BUT you
should check if the number is larger than 0(zero) for each variable.
Assume the user will always enter proper type of value (integer or double or char)
*/

#include <iostream>
using namespace std;

//defining functions used in the program
double hatSize(double wt, double ht);
double waistSize(double age, double wt, double ht);
//functions to request and validate the information
double getAge();
double getWeight();
double getHeight();
bool isInfoValid(double x);
char whatisSelection();
//Init a universal variable
char choice = ' ';
double age, height, weight;
double hatsize, waistsize;


int main() {
	//Init the variables
	char selection;

	do {/* I used a {do while} to loop around the program to check the information
		of more than one person and implemented functions to validate the data. 
		After receiving correct input we will calculate the hatsize and waistsize.
		The program will loop around while the user enter y (yes) or unless an invalid input ends it.*/
		age = getAge(); //function to get the age
		height = getHeight(); //function to get the height
		weight = getWeight(); //function to get the weight

		hatsize = hatSize(weight, height); //function to get the hatsize
		waistsize = waistSize(age, weight, height); //function to get the waistsize

		cout << "Hat size: " << hatsize << endl; //Printing to the console/user
		cout << "Waist size: " << waistsize << endl;

		whatisSelection(); //function to make a selection

	} while ( choice == 'y'); //while selection is y (yes)
	
	system("pause"); //end program
	return 0;
}

double hatSize(double wt, double ht) //function to calculate hatsize with 2 varaibles being passed (weight, height)
{
	hatsize = ((wt / ht)*2.9); //calculat size by deviding weight by height anf multiplying the total by 2.9

	return hatsize; //return the hatsize
}

double waistSize(double age, double wt, double ht) //function to calculate waistsize with 3 varaibles being passed (age, weight, height)
{
	if (age < 29) //If the age is past 28 
	{ 
		waistsize = (wt / 5.7); //calculate the waistsize by dividing the weight by 5.7
	}
	else //If the age is greater than 28
	{
		double ageOver = ((age - 28) / 2); //calculate the ageover for each 2 years over age 28
		double inchesEx = (ageOver * 0.1); //calculate the inches(1/10) for the age being over
		waistsize = ((wt / 5.7) + inchesEx); //calculate the waistsize by adding 1/10 of an inch for each 2 years over age 28

	}
	return waistsize; //return waistsize
}

double getAge() //function to getAge
{
	cout << "Enter your age: ";
	cin >> age;
	if (isInfoValid(age)) //function to validate the input 
	{//if age is valid
		return age; //return the age
	}
	else //if the age was not validated
	{
		cout << "That age is invalid.\n"; //Warn the user and end the program
		system("pause");
		exit(0);
	}

}

double getHeight() //function to getHeight 
{
	cout << "Enter your height (in inches): ";
	cin >> height;
	if (isInfoValid(height)) //function to validate the input 
	{//if height is valid
		return height; //return height
	}
	else //if height was not validated
	{
		cout << "That height is invalid.\n"; //warn the user and end the program
		system("pause");
		exit(0);
	}
}

double getWeight() //function to getWeight
{
	cout << "Enter your weight (in pounds): ";
	cin >> weight;
	if (isInfoValid(weight))//function to validate the input 
	{//if weight is valid
		return weight;
	}
	else //if weight was not validated
	{
		cout << "That weight is invalid.\n"; //warn the user and end the program
		system("pause");
		exit(0);
	}

}

bool isInfoValid(double x) //bool function to check if info is valid
{
	if (x > 0) //if info is larger than 0 (zero)
	{
		return true; //return true
	}
	else //if info is less than or equal to 0 (zero)
	{
		return false; //return false
	}
}

char whatisSelection() //char function to ask the user the to continue or end 
{
	do { //I used a {do while} to loop around to check the information of more than one person
		cout << "Do you want to do another calculation?\nPress y for yes, n for no: ";
		cin >> choice;
		if (choice == 'n') //if the char is n then break the loop and end the program
		{
			break; //break the loop
		}
		if (choice != 'y' && 'n') //if the char is not y or n output an error message
		{
			cout << choice << " is not a valid input.\n";
		}
	} while (choice != 'y' && choice != 'n'); //do the loop while y(yes) or n(no) are not inputted

	return ' ';//return the selection/choice
}
