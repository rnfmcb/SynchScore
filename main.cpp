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
 
using namespace std; 

int main(){ 
	ifstream control; 
	ifstream data; 
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
	double num = 0.0;  
	control.open(controlFile.c_str()); 
	if(control.is_open()) { 
		while(control >> num) { 
			int i; 
			for(i = 0; i < gene; i++){ 
				controlArray[i] = num; 
			} 
		} 
	} 
	//Test control file values 
	for(int i = 0; i < gene;  i++) { 
		cout << controlArray[i] << endl; 
	} 

    control.close(); 

	cout <<"Please enter the data file name " << endl;
	cin.ignore(); 
    getline(cin,testFile);

	//Open data file and fill the data vector
	num = 0.0;  
	data.open(testFile.c_str()); 
	if(data.is_open()){ 
		while(data >> num){
			int i, j;  
			for(i = 0; i < gene; i++) { 
				for( j = 0; j < sample; j++){ 
				   dataArray[i][j] = num; 
				}
			} 
		} 
	}  
			
    data.close(); 
    obj.getSychScore(dataArray,controlArray,gene,sample); 

return 0; 
}
 
