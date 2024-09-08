//****************************************************************************************************************************************************************
// These codes were written by Chew Zhi Boon And Goay Wei Jun.
// The linked-list-based queue algorithm efficiently manages patient queues through a Queue class, where each node stores patient details. Enqueuing involves
// adding patients to the queue's end, while dequeuing removes patients from the front, ensuring a first-in-first-out (FIFO) order. The algorithm supports 
// priority-based operations, enabling specific patients to be prioritized by moving them to the front. Patient searching is implemented recursively, efficiently
// locating patients based on specified criteria. This algorithm provides a flexible and dynamic approach to healthcare queue management, accommodating varying
// priorities and ensuring systematic patient processing within the medical service system.
//****************************************************************************************************************************************************************

#ifndef _QUEUESYSTEM_H
#define _QUEUESYSTEM_H

#include "Patient.h"     
#include <string>

class Queue{
	private:		
	    
		struct QueueNode
		{
	    	Patient* details; // Pointer to Patient object
		    QueueNode* next; // Pointer to the next node in the queue
	    	 
		};
		
	    QueueNode* front;  // Pointer to the front of the queue
	    QueueNode* rear;  // Pointer to the rear of the queue
        int numItem;     // Number of items in the queue
	
    public:
    	Queue();  // Constructor: Initializes an empty queue
    	~Queue(); // Destructor: Deallocates memory used by the queue
    	void enQueue(const Patient);
    	void deQueue(Patient&);
    	void deleteQueue(int);
    	void moveToFront(int);
    	bool isEmpty()const;
    	void clear();
    	Patient findTarget(int);
    	void peek();
    	void upComing(QueueNode*);
    	int returnItem()const;
    	QueueNode* search(QueueNode*,int no)const;
    	  	
};

#endif
