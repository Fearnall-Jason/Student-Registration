/*The purpose of this program will be to store and update basic student information and provide summary information.
The main program will offer users a menu to make selections from. Add student, modify student and print options are the
menu options for the user. The main program will use various functions that will implement the class functions and variables.

This program will use the class header file 'buffStudent.h' and the class implementation file 'buffStudentImp.cpp'

    Name: Jason Fearnall
    Date: 10/25/2021


*/

#include <iostream>
#include "buffStudent.h"

using namespace std;

void mainMenu();
void addStudent(buffStudent studentInfo[], int& length);                       //define function prototypes
int search(buffStudent studentInfo[], int length, string BannerID);
void printStudentData(buffStudent studentInfo[], int length);
double deptAvgGPA(buffStudent studentInfo[], string dept, int len);

int main()                                                                     //main function
{

    int userSelect=0, length=0, len=0, index=0;
    string idInput, deptInput;                                                 //declare working variables
    char ch;
    int const NUMACCOUNT = 10;                                                 //declare constant variable to hold number of students

    buffStudent studentInfo[NUMACCOUNT];                                       //declare an array of class objects

    do                                                                         //do while user does not enter '9'
    {
        mainMenu();                                                            //call main menu function
        cout << "Enter Choice: ";
        cin >> userSelect;                                                     //accept user input
        cin.get(ch);                                                           //store unused characters in variable
        cout << endl;

        switch(userSelect)                                                     //switch statement using user input
        {
            case 1:                                                            //if user enters '1'
            {
                if(length<NUMACCOUNT)                                           //if length of array less than number of allowed accounts
                {
                   addStudent(studentInfo, length);                            //call function to add student to array
                }
                else
                    cout << "ERROR: The Student list is currently FULL!\n";    //if array is full, print error
                break;
            }
            case 2:                                                            //if user enters '2'
            {
                cout << "\nPlease enter the ID number of the student: ";
                cin >> idInput;                                                //accept user input
                index=search(studentInfo, length, idInput);
                cout << "Here is the index: " << index;


                break;
            }

            case 3:                                                            //if user enters '3'
            {
                if(length!=0)                                                  //if current array is not empty
                    printStudentData(studentInfo, length);                     //call function to print array
                else
                    cout << "ERROR. The student list is EMPTY.\n" << endl;     //else, if array is empty, print error
                break;
            }

            case 4:
            {
                cout << "\nPlease enter the department name. ie, CIS, MATH: ";
                cin >> deptInput;
                cout << endl;
                deptAvgGPA(studentInfo, deptInput, length);
                break;
            }

            case 9:                                                            //if user enters 9
            {
                cout << "Goodbye!\n" << endl;                                  //end program
                return 1;
            }

            default:                                                           //if user enters invalid selection, print error
            {
                cout << "ERROR. Please make a valid selection.\n" << endl;
                break;
            }
        }
    }
    while(userSelect != 9);                                                    //do while user does not enter '9'

    return 0;
}

void mainMenu()                                                                //main menu function
{
    cout << "  Buffalo State Registrar System\n" << endl;
    cout << "1: Enter 1 to add a new student" << endl;
    cout << "2: Ender 2 to update an existing student" << endl;                //print options
    cout << "3: Enter 3 to print all students data" << endl;
    cout << "4: Enter 4 to show a departments average GPA" << endl;
    cout << "9: Enter 9 to exit the program\n" << endl;
}

void subMenu()
{
    cout << "\nEnter 1: Update the major" << endl;
    cout << "Enter 2:  Update Overall GPA" << endl;
    cout << "Enter 3: Update the major GPA" << endl;
    cout << "Enter 4: Update the total credits" << endl;
    cout << "Enter 5: Show the student's information" << endl;
    cout << "Enter 9: Exit the program" << endl;
    cout << "\nEnter Choice: ";
}

void addStudent(buffStudent studentInfo[], int& length)                        //function to add student
{
    string name, idNum, major;                                                 //declare local working variables
    double oGPA, mGPA, credits;

    cout << "ADD STUDENT\n" << endl;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Banner ID: ";
    cin >> idNum;
    cout << "Enter Major: ";                                                   //accept user input for student info array
    cin >> major;
    cout << "Enter OverallGPA: ";
    cin >> oGPA;
    cout << "Enter majorGPA: ";
    cin >> mGPA;
    cout << "Enter totalCredits: ";
    cin >> credits;
    cout << endl;

    studentInfo[length].setdata(name, idNum, major, oGPA, mGPA, credits);      //call class function to add student info
    length++;                                                                  //increase length tracker
}

void processStudent(buffStudent list[], int length, string BID)
{

}

void printStudentData(buffStudent studentInfo[], int length)                   //function to print student info
{
    for(int i=0; i<length; i++)                                                //for each element in the array
        studentInfo[i].print();                                                //call class print function
}

int search(buffStudent studentInfo[], int length, string BannerID)
{
    int temp=0, userSelection=0;
    string tempString;

    for(int i=0; i<length; i++)
    {
        tempString=studentInfo[i].getBannerID();
        if(tempString == BannerID)
        {
            cout << "\nStudent Found!" << endl;
            temp=i;
            return temp;
        }
        else if(tempString != BannerID)
        {
            cout << "\nERROR! This ID number was not found in the list!" << endl;
        }
    }
}

double deptAvgGPA(buffStudent studentInfo[], string dept, int len)
{
    double deptAvg=0, sum=0, gpa=0;;
    int count=0;
    string temp;


    for(int i=0; i<len; i++)
    {
        temp=studentInfo[i].getMajor();
        if(temp == dept)
        {
            gpa=studentInfo[i].getGPA();
            sum=sum+gpa;
            count++;
        }
    }

    cout << "There are " << count << " number of students in this major." << endl;

    deptAvg = sum/count;

    cout << "The department average is: " << deptAvg;

    return deptAvg;
}





