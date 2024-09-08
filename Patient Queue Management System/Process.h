//**************************************************************************************************************************************************
// These codes were written by Chew Zhi Boon
// The `Process` class for managing patient queues in a healthcare system. The class uses 3 instances of a `Queue` class `normalQueue`, 
//`priorityQueue`, and `mergeQueue` to represent different patient queues. The program includes functionalities for patient registration,
// managing different queues, and merging queues based on priority criteria.
//
// 
// The `Process` class has methods like `patientRegistration()`, which collects patient information and enqueues them into either the normal
// or priority queue based on age, pregnancy status, and disability. The `active_Queue_Menu()` method provides a user interface for interacting
// with the queues, allowing users to call patients, move them to the front, delete them, or reset the queue.
//
// The code also features methods for handling patient registration details, checking and processing IC numbers, calculating patient age and gender,
// and displaying patient information. The merging of queues involves combining patients from the normal and priority queues into a `mergeQueue` and
// then merging them back into the normal queue.
//**************************************************************************************************************************************************

#ifndef _PROCESS_H
#define _PROCESS_H

#include "QueueSystem.h"

class Process{
	private: // Private member variables
		Queue normalQueue; // Queue for normal patients
	    Queue priorityQueue; // Queue for priority patients
	    Queue mergeQueue;  // Merged queue for both normal and priority patients

	    // Patient details
	    int patientNumber;
	    int age;
        string registerTime ;
        string patientIc;
        string patientName;
    	bool isPregnant;
    	bool isOku; 
    	bool exit; // Flag to control program exit
    	char gender;
    	
    	
    	 // Private member functions
        void active_Queue_Menu(); // Display Active Queue Menu
		void subMenu(int); // Display Sub Menu
		void manageQueueOptions(Queue&); //Manage each Queue
		void processQueue(int,Queue&); // process the Queue
		void callByPatientNo(Queue&); // call patient
		void dePatient(Queue&); // delete patient
		void mergeQueueConfirmation(); // merge confirmation
		void clearQueueConfirmation(Queue&); // clear qeueue confirmation
		void patientRegistration(); // register patient information
		void icRegisteration(); // ic register
		void nameRegisteration(); // name register
		void pregnantRegisteration(); // is pregnant register 
		void okuRegisteration(); // is oku register
		void isComfirm(); // comfirm registration 
		void combineQueues(int,int); // combine queue
		void merge(int); // merge queue
		bool checkIc(string)const; // checking ic is valid or not
		string getCurrentTime()const; // get current time
		void calculateAge(); // calcualate patient age using ic
		void calculateGender(); // calculate patient gender using ic
		bool modules(int)const; // modules method
		void printPatient(Patient)const; // print patient method

	public:
		Process(); // Constructor
		void mainMenu(int); // Displays the main menu
		bool returnExit()const; // Returns the exit flag
		void enter();
		
};

#endif

