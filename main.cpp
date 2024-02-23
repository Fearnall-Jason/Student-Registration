/*The purpose of this program will be to store and update basic student information and provide summary information.
The main program will offer users a menu to make selections from. Add student, modify student and print options are the
menu options for the user. The main program will use various functions that will implement the class functions and variables.

This program will use the class header file 'buffStudent.h' and the class implementation file 'buffStudentImp.cpp'

    Name: Jason Fearnall
    Date: 10/25/2021

*/

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <cctype>
#include <fstream>
#include <string>

#include "buffStudent.h"

using namespace std;

void mainMenu();
void subMenu();
void addStudent(buffStudent studentInfo[], int& length);                                      //define function prototypes
int search(buffStudent studentInfo[], int length, string banID);
void processStudent(buffStudent studentInfo[], int length, string banID);
void printStudentData(buffStudent studentInfo[], int length);
double deptAvgGPA(buffStudent studentInfo[], string dept, int len);
int loadStudentData(buffStudent studentInfo[], int& length);

string majorList[] = {"CIS", "MATH", "ENG", "BUS", "PSY", "SCI", "SPEECH"};                   //define array of majors
string listVar = "list";
char ch;                                                                                      //declare variable to hold list option

int main()                                                                                    //main function
{
    int userSelect=0, length=0, result=0, ret_Value=0;
    double deptAvg=0;
    string idInput, deptInput;                                                                //declare working variables
    int const NUMACCOUNT = 25;                                                                //declare constant variable to hold number of students

    buffStudent studentInfo[NUMACCOUNT];                                                      //declare an array of class objects

    ret_Value = loadStudentData(studentInfo, length);                                         //call function to load data and store return value in variable

    if(ret_Value == 99)                                                                       //if load data function returns a '99'
    {
        cout << "ERROR loading DATA file! Program will now end!";                             //print error, terminate program
        return 1;
    }

    do                                                                                        //do while user does not enter '9'
    {
        mainMenu();                                                                           //call main menu function
        cout << "Enter Choice: ";
        cin >> userSelect;                                                                    //accept user input
        cin.get(ch);                                                                          //store unused characters in variable

        while(1)                                                                              //while result is '1'
        {
            if(cin.fail())                                                                    //if user entry is not of valid type
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout <<"\nERROR! That is the wrong input." << endl;                           //reset entry, print error, and accept new entry
                cout << "Please make a valid selection. \n" << endl;
                cout << "Enter Choice: ";
                cin >> userSelect;
                cin.get(ch);                                                                  //store unused characters in variable
            }
            if(!cin.fail())                                                                   //if user entry is valid, break from loop
                break;
        }

        cout << endl;

        switch(userSelect)                                                                    //switch statement using user input
        {
            case 1:                                                                           //if user enters '1'
            {
                if(length<NUMACCOUNT)                                                         //if length of array less than number of allowed accounts
                {
                   addStudent(studentInfo, length);                                           //call function to add student to array
                }
                else
                    cout << "ERROR: The Student list is currently FULL!\n";                   //if array is full, print error
                break;
            }
            case 2:                                                                           //if user enters '2'
            {
                if(length != 0)                                                               //if array is not empty
                {
                    cout << "\nPlease enter the ID number of the student: ";
                    cin >> idInput;                                                           //accept user input
                    cin.get(ch);                                                              //store unused characters in variable
                    processStudent(studentInfo, length, idInput);                             //call function to process student
                }
                else
                    cout << "ERROR! The list is currently EMPTY!\n" << endl;;                 //if list is empty, print error

                break;
            }

            case 3:                                                                           //if user enters '3'
            {
                if(length!=0)                                                                 //if current array is not empty
                {
                    printStudentData(studentInfo, length);                                    //call function to print array
                }
                else
                    cout << "ERROR. The student list is EMPTY.\n" << endl;                    //else, if array is empty, print error
                break;
            }

            case 4:                                                                           //if user enters '4'
            {
                while(result!=1)                                                              //while result not '1'
                {
                    cout << "\nIf known, enter the department name or type 'list': ";         //accept user input
                    cin >> deptInput;
                    cin.get(ch);                                                              //store unused characters in variabl

                    while(1)                                                                  //while true
                    {
                        if(cin.fail())                                                        //if user input is invalid
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout <<"\nERROR! That is the wrong input." << endl;               //clear input, print error, accept new input
                            cout << "Please make a valid selection. \n" << endl;
                            cout << "Enter Choice: ";
                            cin >> deptInput;
                            cin.get(ch);                                                      //store unused characters in variable
                        }
                        if(!cin.fail())                                                       //if input is valid, break from loop
                            break;
                    }

                    cout << endl;
                    if(strcasecmp(deptInput.c_str(), listVar.c_str())==0)                     //if user requests to view list of majors
                    {
                        cout << "\nList of available Majors: \n" << endl;
                        for(int i=0; i<7; i++)
                            cout << majorList[i] << endl;                                     //print all majors in the majors array
                        cout << endl;
                        result=0;
                    }
                    else
                    {
                        for(int i=0; i<7; i++)                                                //for each index in array
                        {
                            if(strcasecmp(majorList[i].c_str(), deptInput.c_str())==0)        //if the user entry matches an array value
                            {
                                deptAvg=deptAvgGPA(studentInfo, deptInput, length);           //call the department Avg function and store in variable
                                cout << "The class Average of " << majorList[i] <<
                                " is: " << deptAvg << "\n" << endl;;
                                result=1;
                            }
                        }
                        if(result==0)                                                         //if user entry is not a valid major, print error
                            cout << "\nThat major is not available, re-enter or type " <<
                                      "'list' to see a list of majors: \n" << endl;
                    }
                }
                result=0;
            }
            break;

            case 9: {                                                                         //if user enters 9
                cout << "Goodbye!\n" << endl;                                                 //end program
                return 1;
            }

            default: {                                                                        //if user enters invalid selection, print error
                cout << "ERROR. Please make a valid selection.\n" << endl;
                break;
            }
        }
    }
    while(userSelect != 9);                                                                   //do while user does not enter '9'

    return 0;
}



void mainMenu()                                                                               //main menu function
{
    cout << "**************************************************" << endl;
    cout << "         Buffalo State Registrar System\n" << endl;
    cout << "******************MAIN MENU***********************\n" << endl;
    cout << "1: Enter 1 to add a new student" << endl;
    cout << "2: Enter 2 to update an existing student" << endl;                               //print options
    cout << "3: Enter 3 to print all students data" << endl;
    cout << "4: Enter 4 to show a departments average GPA" << endl;
    cout << "9: Enter 9 to exit the program\n" << endl;
}



void subMenu()                                                                                //sub menu function
{
    cout << "\n********STUDENT UPDATE MENU**********\n" << endl;
    cout << "Enter 1: Update the major" << endl;
    cout << "Enter 2: Update Overall GPA" << endl;
    cout << "Enter 3: Update the major GPA" << endl;                                          //print selections
    cout << "Enter 4: Update the total credits" << endl;
    cout << "Enter 5: Show the student's information" << endl;
    cout << "Enter 9: Exit to the MAIN MENU" << endl;
    cout << "\nEnter Choice: ";
}



void addStudent(buffStudent studentInfo[], int& length)                                       //function to add student
{
    string firstName, lastName, idNum, major;                                                 //declare local working variables
    double oGPA, mGPA, credits;
    int result=0;

    cout << "ADD STUDENT\n" << endl;
    cout << "Enter Student First Name: ";
    cin >> firstName;                                                                         //accept user input for name and ID
    cin.get(ch);                                                                              //store unused characters in variable
    cout << "Enter Student Last Name: ";
    cin >> lastName;                                                                          //accept user input for name and ID
    cin.get(ch);
    cout << "Enter Banner ID: ";
    cin >> idNum;
    cin.get(ch);                                                                              //store unused characters in variable

    while(result!=1)                                                                          //while result is not 1
    {
        cout << "Enter Major: ";
        cin >> major;                                                                         //accept user input for major
        cin.get(ch);                                                                          //store unused characters in variable

        if(strcasecmp(major.c_str(), listVar.c_str())==0)                                     //if user requests to view the list of majors
        {
            cout << "\nList of available Majors: \n" << endl;
            for(int i=0; i<5; i++)
                cout << majorList[i] << endl;                                                 //print majors array
            cout << endl;
            result=0;
        }
        else                                                                                  //if user does not request the list
        {
            for(int i=0; i<5; i++)                                                            //for each element in the majors array
            {
                if(strcasecmp(majorList[i].c_str(), major.c_str())==0)                        //if user entry is found in array, report as valid
                    result=1;
            }
            if(result==0)                                                                     //if user entry is not in array, print error
                cout << "\nThat major is not available, re-enter or type " <<
                        "'list' to see a list of majors: \n" << endl;
        }
    }

    while(result!=0)                                                                          //while not valid
    {
        cout << "Enter OverallGPA: ";                                                         //accept user input for overall GPA
        cin >> oGPA;
        cin.get(ch);                                                                          //store unused characters in variable

        if(oGPA <0 || oGPA >4.0)                                                              //if GPA not within valid range
        {
            cout << "ERROR! GPA must be between 0 and 4.0, Please Re-Enter \n" << endl;       //print error
            result = 1;
        }
        else                                                                                  //if user input is within range, mark as valid
            result=0;
    }

    while(result!=1)                                                                          //while not valid
    {
        cout << "Enter majorGPA: ";                                                           //accept user input
        cin >> mGPA;
        cin.get(ch);                                                                          //store unused characters in variable

        if(mGPA <0 || mGPA >4.0)                                                              //if GPA not within valid range
        {
            cout << "ERROR! GPA must be between 0 and 4.0, Please Re-Enter \n" << endl;       //print error
            result = 0;
        }
        else                                                                                  //if user input is within range, mark as valid
            result=1;
    }

    cout << "Enter totalCredits: ";                                                           //accept user input for total credits
    cin >> credits;
    cin.get(ch);                                                                              //store unused characters in variable

    while(1)                                                                                  //while result is '1'
    {
        if(cin.fail())                                                                        //if user entry is not of valid type
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout <<"\nERROR! That is the wrong input." << endl;                               //reset entry, print error, and accept new entry
            cout << "Please make a valid selection. \n" << endl;
            cout << "Enter Choice: ";
            cin >> credits;
            cin.get(ch);                                                                      //store unused characters in variable
        }
        if(!cin.fail())                                                                       //if user entry is valid, break from loop
            break;
    }

    cout << endl;

    studentInfo[length].setdata(firstName, lastName, idNum, major, oGPA, mGPA, credits);      //call class function to add student info with user input
    length++;                                                                                 //increase length tracker

    cout << "Student Added Successfully!\n" << endl;                                          //print success message
}



void processStudent(buffStudent studentInfo[], int length, string banID)                      //function to process student
{
    int index, userSelect;
    char ch;                                                                                  //declare working variables

    index=search(studentInfo, length, banID);                                                 //call function to search for ID number

    if(index!=-1)                                                                             //if index returned is valid
    {
        do                                                                                    //do while user does not input '9'
        {
            subMenu();                                                                        //call function to display sub menu
            cin >> userSelect;                                                                //accept user input
            cin.get(ch);                                                                      //store unused characters in variable

            while(1)                                                                          //while result is '1'
            {
                if(cin.fail())                                                                //if user entry is not of valid type
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout <<"\nERROR! That is the wrong input." << endl;                       //reset entry, print error, and accept new entry
                    cout << "Please make a valid selection. \n" << endl;
                    cout << "Enter Choice: ";
                    cin >> userSelect;
                    cin.get(ch);                                                              //store unused characters in variable
                }
                if(!cin.fail())                                                               //if user entry is valid, break from loop
                    break;
            }

            switch(userSelect)                                                                //switch selection using user input
            {
                case 1:
                {
                    studentInfo[index].setMajor();                                            //for case 1, call class function to set major
                    break;

                }
                case 2:
                {
                    studentInfo[index].setOverallGPA();                                       //for case 2, call class function to set overall GPA
                    break;

                }
                case 3:
                {
                    studentInfo[index].setMajorGPA();                                         //for case 3, call class function to set Major GPA
                    break;

                }
                case 4:
                {
                    studentInfo[index].setTotCredits();                                       //for case 4, call class function to set total credits
                    break;

                }
                case 5:
                {
                    cout << "\nStudent's current information: " << endl;                      //for case 5, call class function to print info
                    studentInfo[index].print();
                    break;
                }
                case 9:
                {
                    cout << "MAIN MENU\n" << endl;                                            //for case 9, return to main menu
                    break;

                }
                default:                                                                      //if user enters invalid input, print error
                    cout << "ERROR! That is not a valid selection.\n" << endl;
            }
        }
        while(userSelect!=9);                                                                 //while user does not select quitting option
    }
}



void printStudentData(buffStudent studentInfo[], int length)                                  //function to print student info
{
    for(int i=0; i<length; i++)                                                               //for each element in the array
        studentInfo[i].print();                                                               //call class print function
}



int search(buffStudent studentInfo[], int length, string BannerID)                            //search function to search student IDs
{
    int temp=0;
    string tempString;

    for(int i=0; i<length; i++)                                                               //for each element in the student array
    {
        tempString=studentInfo[i].getBannerID();                                              //store element in variable

        if(strcasecmp(tempString.c_str(), BannerID.c_str()) == 0)                             //if IDs match
        {
            cout << "\nStudent Found!" << endl;                                               //print message, save index and return
            temp=i;
            return temp;
        }
    }

    cout << "\nERROR! This ID number was not found in the list!\n" << endl;                   //if not match found, print error

    return temp = -1;
}



double deptAvgGPA(buffStudent studentInfo[], string dept, int len)                            //function to calculate class average
{
    double deptAvg=0, sum=0, gpa=0;;
    int count=0;                                                                              //declare working variables
    string temp;

    for(int i=0; i<len; i++)                                                                  //for each element in the array
    {
        temp=studentInfo[i].getMajor();                                                       //set the major to temp variable
        if(strcasecmp(temp.c_str(), dept.c_str()) == 0)                                       //if temp variable matches user input
        {
            gpa=studentInfo[i].getGPA();                                                      //set the students GPA to the GPA variable
            sum=sum+gpa;                                                                      //add the GPA to the running sum
            count++;                                                                          //increase count variable
        }
    }
    cout << "There are " << count << " students in the " << dept << " major.\n" << endl;      //print message with number of students in the major

    deptAvg = sum/count;                                                                      //calculate the department average and return

    return deptAvg;
}



int loadStudentData(buffStudent studentInfo[], int& length)                                   //function to load data from data file
{
    int numOfStudents;
    string fname, lname, bID, major;                                                          //declare local variables
    double oGpa=0, mGpa=0, tCr=0;

    ifstream inFile;                                                                          //declare variable for input file

    inFile.open("P5P3Data.txt");                                                              //open the file

    if(!inFile)
    {
        cout << "There was an error opening the Data File!" << endl;                          //if the file does not open, print error, return 99
        return 99;
    }

    inFile >> numOfStudents;                                                                  //store first line in variable to hold number of students

    for(int i=0;i<numOfStudents; i++)                                                         //for the length of the student file
    {
        inFile >> fname >> lname >> bID >> major >> oGpa >> mGpa >> tCr;                      //store line in proper variable
        studentInfo[length].setdata(fname, lname, bID, major, oGpa, mGpa, tCr);               //call class function to add student info with user input
        length++;                                                                             //increase length
    }
    return 1;
}

