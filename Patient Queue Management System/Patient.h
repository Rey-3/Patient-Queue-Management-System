//***************************************************************************************************************************************************
// These codes were written by Chew Zhi Boon And Goay Wei Jun.
// The `Patient` class to represent individual patient. Constructors initialize patient information, and setter methods allow modification. 
// The class includes getter methods for retrieving specific details and a print function for formatted output. The print function dynamically 
// adjusts formatting based on the length of patient information, ensuring a visually appealing presentation. It enables easy access, modification,
// and display of patient information while maintaining a clear and organized structure.
//***************************************************************************************************************************************************

#ifndef _PATIENT_H
#define _PATIENT_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <limits>
using namespace std;

class Patient{
	private: // Private member variables
		string icNo; 
		string patientName;
		string registerTime;
		int no;
		int age;
		char gender;
		bool isPregnant;
		bool isOku;
		
	public:
		Patient(); // Default constructor
	    Patient(string,string,string,int,int,char,bool,bool); // Parameterized constructor
		
		// Setter methods to set the values of private member variables
		void setIcNo(string);
		void setPatientName(string);
		void setRegisterTime(string);
		void setNo(int);
		void setAge(int);
		void setGender(char);
		void setIsPregnant(bool);
		
		// Getter methods to retrieve the values of private member variables
		string getIcNo()const;
		string getPatientName()const;
		string getRegisterTime()const;
		int getNo()const;
		int getAge()const;
		char getGender()const;
		bool getIsPregnant()const;
		bool getIsOku()const;
		
		// Method to print patient information
		void print()const;
		
};


#endif
