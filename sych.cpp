//Rachel Festervand 4/1/2019
//This is the class file for the Sych Project

#include <iostream> 
#include <string>
#include <cstdlib> 
#include <vector> 
#include "sych.h" 

using namespace std; 


Sych::Sych(){

} 
 

void Sych::getSychScore(double **data, double control[],int genes, int samples){ 
     float dataNum, controlNum; 
	 float sum,difference,avg; 
	 avg = 0.0; 
        
	for(int i = 0; i < genes; i++) { 
		for(int j = 0; j < samples; j++) { 
			dataNum = data[i][j]; 
			controlNum = control[i]; 
			difference  = findDiff(dataNum,controlNum);
			sum += difference;  		 
         }   
      }	 
	//Get sych score
	avg = ((float)sum)/samples; 
    cout << "Sych Score is : " << avg << endl;
} 

int Sych::findDiff(int val, int control) { 
	double diff = abs(control - val); 
	return diff; 
} 



