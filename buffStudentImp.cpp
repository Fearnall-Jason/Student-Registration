/*This implementation file will be used with the buffStudent class. This file will hold functions to set student data, print student data, and get ID numbers.

    Name: Jason Fearnall
    Date: 10/25/2021

*/

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <cctype>

#include "buffStudent.h"

void buffStudent::setdata(string firstN, string lastN, string bId, string m, double oGpa, double mGpa, double tCr)  //class function to set the data given by the user
{
    firstName=firstN;
    lastName=lastN;
    bannerID=bId;
    major=m;                                                                                       //set parameters to variables
    overallGPA=oGpa;
    majorGPA=mGpa;
    totalCredits=tCr;
}

void buffStudent::print() const                                                                    //class function to print information
{
    cout <<"\n*******************************" << endl;
    cout << "Student Name: " << firstName << " " << lastName << endl;
    cout << "Banner ID: " << bannerID << endl;
    cout << "Major: " << major << endl;                                                            //print given variables with proper headings
    cout << "Overall GPA: " << overallGPA << endl;
    cout << "Major GPA: " << majorGPA << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << endl;
}

string buffStudent::getBannerID() const                                                            //class function to get banner ID
{
    return bannerID;                                                                               //return banner Id
}

string buffStudent::getMajor() const                                                               //class function to get major of student
{
    return major;                                                                                  //return the major
}

double buffStudent::getGPA() const                                                                 //class function to get the student's GPA
{
    return majorGPA;                                                                               //return the GPA
}

void buffStudent::setOverallGPA()                                                                  //class function to set the student's GPA
{
    cout << "Enter the new Overall GPA: ";                                                         //accept user input
    cin >> gpaChoice;
    cin.get(ch);                                                                                   //store unused characters in variable

    while(1)                                                                                       //while result is '1'
        {
            if(cin.fail())                                                                         //if user entry is not of valid type
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout <<"\nERROR! That is the wrong input." << endl;                                //reset entry, print error, and accept new entry
                cout << "Please make a valid selection. \n" << endl;
                cout << "Enter Choice: ";
                cin >> gpaChoice;
                cin.get(ch);                                                                       //store unused characters in variable
            }
            if(!cin.fail())                                                                        //if user entry is valid, break from loop
                break;
        }
    overallGPA=gpaChoice;
    cout << "\nSuccessfully Updated!\n" << endl;
}

void buffStudent::setMajorGPA()                                                                    //class function to set MajorGPA
{
    cout << "Enter the new GPA for the major: ";                                                   //accept user input
    cin >> gpaChoice;
    cin.get(ch);                                                                                   //store unused characters in variable

    while(1)                                                                                       //while result is '1'
        {
            if(cin.fail())                                                                         //if user entry is not of valid type
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout <<"\nERROR! That is the wrong input." << endl;                                //reset entry, print error, and accept new entry
                cout << "Please make a valid selection. \n" << endl;
                cout << "Enter Choice: ";
                cin >> gpaChoice;
                cin.get(ch);                                                                       //store unused characters in variable
            }
            if(!cin.fail())                                                                        //if user entry is valid, break from loop
                break;
        }
    major=gpaChoice;                                                                               //set GPA
    cout << "\nSuccessfully Updated!\n" << endl;
}

void buffStudent::setTotCredits()                                                                  //class function to set total credits
{
    cout << "Enter the total credits: ";                                                           //accept user input
    cin >> creditsChoice;
    cin.get(ch);                                                                                   //store unused characters in variable

    while(1)                                                                                       //while result is '1'
        {
            if(cin.fail())                                                                         //if user entry is not of valid type
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout <<"\nERROR! That is the wrong input." << endl;                                //reset entry, print error, and accept new entry
                cout << "Please make a valid selection. \n" << endl;
                cout << "Enter Choice: ";
                cin >> creditsChoice;
                cin.get(ch);                                                                       //store unused characters in variable
            }
            if(!cin.fail())                                                                        //if user entry is valid, break from loop
                break;
        }
    totalCredits=creditsChoice;                                                                    //set the total credits
    cout << "\nSuccessfully Updated!\n" << endl;
}

void buffStudent::setMajor()
{
    string listVar="list";
    int result=0;

    while(result!=1)
    {
         cout << "Enter the new major: ";
         cin >> newMajor;
         cin.get(ch);                                                                              //store unused characters in variable

        while(1)                                                                                   //while result is '1'
        {
            if(cin.fail())                                                                         //if user entry is not of valid type
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout <<"\nERROR! That is the wrong input." << endl;                                //reset entry, print error, and accept new entry
                cout << "Please make a valid selection. \n" << endl;
                cout << "Enter Choice: ";
                cin >> newMajor;
                cin.get(ch);                                                                       //store unused characters in variable

            }
            if(!cin.fail())                                                                        //if user entry is valid, break from loop
                break;
        }

        if(strcasecmp(newMajor.c_str(), listVar.c_str())==0)                                       //if user requests to view list of majors
        {
            cout << "\nList of available Majors: \n" << endl;

            for(int i=0; i<5; i++)
                cout << majorList[i] << endl;                                                      //print all majors in the majors array
            cout << endl;
            result=0;
        }
        else
        {
            for(int i=0; i<5; i++)                                                                 //for each index in array
            {
                if(strcasecmp(majorList[i].c_str(), newMajor.c_str())==0)                          //if the user entry matches an array value
                {
                    major=newMajor;
                    result=1;
                    cout << "\nSuccessfully Updated!\n" << endl;
                }
            }
        if(result==0)                                                                              //if user entry is not a valid major, print error
            cout << "\nThat major is not available, re-enter or type " <<
            "'list' to see a list of majors: \n" << endl;
        }
    }
}
