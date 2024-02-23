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
        void setdata(string lastN, string firstN, string bId, string m, double oGpa, double mGpa, double tCr);   // sets the private class members to the parameter values
        void print() const;                                                                   // outputs the private class members
        string getBannerID() const;
        string getMajor() const;
        double getGPA() const;
        void setMajor();
        void setOverallGPA();
        void setMajorGPA();
        void setTotCredits();
        string majorList[7] = {"CIS", "MATH", "ENG", "BUS", "PSY", "SCI", "SPEECH"};                     //define array of majors
        char ch;

    private:
        string firstName;
        string lastName;
        string bannerID;
        string major;
        double overallGPA;                                                                    //declare private class variables
        double majorGPA;
        double totalCredits;
        int creditsChoice;
        double gpaChoice;
        string newMajor;


};

#endif // BUFFSTUDENT_H
