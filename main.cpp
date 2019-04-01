//Rachel Festervand
//SychScore Project 
//4/1/2019 
//This is the main file for the Sych Score Project

#include <iostream>
#include "sych.h" 
#include <fstream>
#include <string> 
#include <vector> 
#include <cstdlib>  
#include <stdlib.h> 
#include <stdio.h> 
 
using namespace std; 

int main(){ 
	ifstream control;  
	string controlFile; 
	string testFile;
	int sample,gene;    
	double **dataArray; 
	

	cout << "How many data samples are in the test file?" << endl;
	cin >> sample; 
	cout << "How many genes are being compared? " << endl; 
	cin >> gene;
   	
  
	//Create class object 
	Sych obj; 
	dataArray = new double *[gene]; 
		for(int i = 0; i < gene; i++){ 
			dataArray[i] = new double[sample]; 
		} 
	double controlArray[gene];
 
    cout << "Please enter the control file name" << endl;
	cin.ignore(); 
     getline(cin,controlFile);

	//Open control file and fill the control vector  
	int num = 0;   
	control.open(controlFile.c_str()); 
	if(control.is_open()) { 
		while(!control.eof()) {
		
			control >> controlArray[num];
			num++;  
		} 
	} 
	//Test control file values 
	cout << "Control values " << endl; 
	for(int i = 0; i < gene;  i++) { 
		cout << controlArray[i] << 
	} 
	cout << endl; 

    control.close(); 

	/*cout <<"Please enter the data file name " << endl;
	cin.ignore(); 
    getline(cin,testFile);*/
   

	//Open data file and fill the data vector
    ifstream data("data.txt");   
	if(!data.is_open()) { 
		cout << "Error opening file " << endl; 
	    exit(EXIT_FAILURE); 
	}  	
		while(!data.eof()){
			for(int i = 0; i < gene; i++) { 
				for(int j = 0; j < sample; j++){ 
				   data >> dataArray[i][j]; 
				}
			} 
		 	 
        }     
		//Test input file 
		cout << "Data file " << endl; 
		for (int i = 0; i < gene; ++i) {
    	    for (int j = 0; j < sample; ++j){
        	    cout << dataArray[i][j] << ' ';
       		 }
        cout << endl;
   		 }			
    data.close(); 
    obj.getSychScore(dataArray,controlArray,gene,sample); 
    
 
return 0; 
}
 
