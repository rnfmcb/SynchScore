//Rachel Festervand
//SychScore Project 
//4/1/2019 
//This is the main file for the Sych Score Project

#include <iostream>
#include "sych.h" 
#include <fstream>
#include <string>  
 
using namespace std; 

int main(){ 
ifstream infile; 
string controlFile; 
string testFile; 
int sampleNum; 
int geneNum; 

cout << "Please enter the control file name" << endl; 
cin >> controlFile; 
cout << "How many data samples are in the test file?" << endl;
cin >> sampleNum; 
cout << "How many genes are being compared? " << endl; 
cin >> geneNum;  
cout <<"Please enter the data file name " << endl;
cin >> testFile;  

return 0; 
}
 
