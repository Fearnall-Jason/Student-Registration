/*This implementation file will be used with the buffStudent class. This file will hold functions to set student data, print student data, and get ID numbers.

    Name: Jason Fearnall
    Date: 10/25/2021

*/

#include <iostream>
#include "buffStudent.h"

void buffStudent::setdata(string N, string bId, string m, double oGpa, double mGpa, double tCr)    //class function to set the data given by the user
{
    fullName=N;
    bannerID=bId;
    major=m;                                                                                       //set parameters to variables
    overallGPA=oGpa;
    majorGPA=mGpa;
    totalCredits=tCr;
}

void buffStudent::print() const                                                                    //class function to print information
{
    cout << "Student Name: " << fullName<< endl;
    cout << "Banner ID: " << bannerID << endl;
    cout << "Major: " << major << endl;                                                            //print given variables with proper headings
    cout << "Overall GPA: " << overallGPA << endl;
    cout << "Major GPA: " << majorGPA << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout <<"\n*******************************" << endl;
}

string buffStudent::getBannerID() const                                                            //class function to get banner ID
{
    return bannerID;                                                                               //return banner Id
}

string buffStudent::getMajor() const
{
    return major;
}

double buffStudent::getGPA() const
{
    return overallGPA;
}
