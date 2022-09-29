/*
 Austin Bergum
 C++ Fall 2022
 Due: 28 September 2022
 Lab Name: Lab 3 User and File I/O
 Description: Write an interactive C++ program that computes and outputs the mean and population standard deviation of a set of four integers that are inputted by a file called “inMeanStd.dat” and the user (should handle both). Although the individual values are integers, the results are floating-point values. Be sure to use proper formatting and appropriate comments in your code. Provide appropriate prompts to the user. The output should be to the screen for the user inputted values and to a file called “outMeanStd.dat”. The programs output should be labeled clearly and formatted neatly. You must calculate the mean and standard deviation in separate functions.
 */

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

//defining string values
string inputFile = "/Users/austinbergum/Desktop/Xcode Projects/Lab 3/inMeanStd.dat";
string outputFile = "/Users/austinbergum/Desktop/Xcode Projects/Lab 3/outMeanStd.dat";

//defining integer variables
int first;
int second;
int third;
int fourth;
int data1;
int data2;
int data3;
int data4;

//defining float variables
float x;
float y;
float z;
float v;
float a;
float b;
float c;
float d;
float mean;
float meanvariance;
float standardDev;
float outMean;
float outMeanVariance;
float outStandardDev;

//defining functions
void meanCalc();
void standardDeviation();
void calculations();
void inputFunction();
void outputFunction();
void outMeanCalc();
void outStandardDeviation();

//main function
int main()
{
//User input and output statements
    cout << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number: ";
    cin >> second;
    cout << "Enter the third number: ";
    cin >> third;
    cout << "Enter the fourth number: ";
    cin >> fourth;
   
//Calling the functions
    meanCalc();
    standardDeviation();
    inputFunction();
    outMeanCalc();
    outStandardDeviation();
    outputFunction();
    
    return 0;
}

//mean calculation
void meanCalc()
{
    mean = (first + second + third + fourth) / 4.0;
        
    cout << endl << "The mean value is: " << mean << endl << endl;
}
    
//standard deviation calculation
void standardDeviation()
{
    x = pow((first - mean),2.0);
    y = pow((second - mean),2.0);
    z = pow((third - mean),2.0);
    v = pow((fourth - mean),2.0);
    
    meanvariance = (x + y + z + v) / (4.0) ;
    standardDev = sqrt(meanvariance);
        
    cout << "The standard deviation value is: " << standardDev << endl << endl;
}

//combination of mean and standard deviation calculations
void calculations()
{
    meanCalc();
    standardDeviation();
}

//input file function
void inputFunction()
{
    ifstream inFile;
    inFile.open(inputFile);
    
    if (!inFile)
        cout << "Can't find the file..." << endl << endl;
    
    inFile >> data1 >> data2 >> data3 >> data4;
}

//output file function
void outputFunction()
{
    ofstream outfile;
    outfile.open(outputFile);

    outfile << "The mean is: " << outMean << endl << endl;
    outfile << "The standard deviation is: " << outStandardDev;
}

//mean calculation for output file
void outMeanCalc()
{
    outMean = (data1 + data2 + data3 + data4) / 4.0;

}

//standard deviation calculation for output file
void outStandardDeviation()
{
    a = pow((data1 - outMean),2.0);
    b = pow((data2 - outMean),2.0);
    c = pow((data3 - outMean),2.0);
    d = pow((data4 - outMean),2.0);
    
    outMeanVariance = (a + b + c + d) / (4.0) ;
    outStandardDev = sqrt(outMeanVariance);
}
