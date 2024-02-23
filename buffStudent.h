/*This header file will be used for the buffStudent class to be used within the main.

    Name: Jason Fearnall
    Date: 10/25/2021

*/

#include <iostream>
#include <string>
#ifndef BUFFSTUDENT_H
#define BUFFSTUDENT_H

using namespace std;

class buffStudent
{
public:
        void setdata(string N, string bId, string m, double oGpa, double mGpa, double tCr);   // sets the private class members to the parameter values
        void print() const;                                                                   // outputs the private class members
        string getBannerID() const;
        string getMajor() const;
        double getGPA() const;

    private:
        string fullName;
        string bannerID;
        string major;
        double overallGPA;                                                                    //declare private class variables
        double majorGPA;
        double totalCredits;
};

#endif // BUFFSTUDENT_H
