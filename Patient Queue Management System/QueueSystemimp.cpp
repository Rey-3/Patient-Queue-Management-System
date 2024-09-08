#include "QueueSystem.h"

Queue::Queue(){
	front = rear = nullptr;
	numItem =  0;
}

Queue::~Queue(){
	clear();
}

void Queue::enQueue(const Patient _patient){
	
	QueueNode* newNode = new QueueNode; // Create a new node and allocate memory for the patient details
	newNode->details = new Patient(_patient);
    newNode -> next = nullptr;
    
    if(front == nullptr) // Check if the queue is empty
	{
    	front = rear = newNode; // If the queue is empty, set both front and rear to the new node
	}
	
	else
	{
		rear -> next = newNode;  // If the queue is not empty, add the new node to the end and update the rear
		rear = newNode;	
	}
	
    numItem++;  // Increase the count of items in the queue
}

void Queue::deQueue(Patient& _patient){

	QueueNode* temp;
	
	if(isEmpty())  // Check if the queue is empty
	{
		cout << "[System] The Queue is Empty...." << endl;
	}
	
	else
	{
		_patient = *(front -> details); // Retrieve patient if details is from the front node
		temp = front; // Save the front node to a temporary variable
		front = front -> next;  // Move front to the next node
		delete temp; // Delete the original front node
		numItem--; // Decrease the count of items in the queue
	}
}

void Queue::deleteQueue(int no){

	string patientName= "";
	
	if(isEmpty())
	{
		cout << "[System] The Queue is Empty...." << endl;
		return;
	}
	
	if(front -> details -> getNo() == no)
	{
		QueueNode* temp = front;
		patientName = temp -> details -> getPatientName();
		front = front -> next;
		delete temp;
		numItem--;
		
		cout << "[System] No " << no << "," << patientName << " Has Been Deleted From The Queue" << endl << endl;
		
		if(numItem == 0)  // Update rear if the queue becomes empty
		{
			rear = nullptr;
		}
		
		return;
	}
    
    QueueNode* current = front;
    current = search(current,no);  // Search for the patient to delete
	
	if(current -> next == nullptr) // If patient not found
	{  
		cout << "[System] No " << no << " Not Found In Queue" << endl;
		return;
	}
	
	// Delete the patient
	QueueNode* temp = current -> next;
	current -> next = temp -> next;
	patientName = temp -> details -> getPatientName();
	
	if(temp == rear) // Update rear if the deleted patient was at the end
	{ 
		rear = current;
	}
	
	delete temp;
	numItem--;
 		
    cout << "[System] No " << no << "," << patientName << " Has Been Deleted From The Queue" << endl << endl;
}

void Queue::moveToFront(int no){
	
	if(isEmpty())  // Check if the queue is empty
	{
		cout << "[System] The Queue is Empty...." << endl;
		return;
	}
	
	if(front -> details -> getNo() == no)  // Check if the patient to delete is at the front
	{
		cout << "[System]No " << no << " Is Already In The Front" << endl;
		return;
	}
	
	QueueNode* current = front;
	current = search(current,no);
  
	if(current -> next == nullptr)
	{
		cout << "[System] No " << no << " Not Found In The Queue" << endl;
		return;
	}
	
	QueueNode* temp = current -> next;
	current -> next = temp -> next;
	
	if(temp == rear){
		rear = current;
	}
	
	temp -> next = front;
	front = temp;
	
	cout << "[System] " << front -> details -> getPatientName() << " Will Be Process Before "<< front -> next -> details -> getPatientName() << "." << endl << endl;
}

bool Queue::isEmpty()const{
	return (numItem==0);
}

void Queue::clear(){
	
	Patient patient;
	
	while(!isEmpty()){
		deQueue(patient);
	
	}
}

Patient Queue::findTarget(int target){
   
    QueueNode* temp = front;
    Patient patient;  
    
    if (temp -> details -> getNo() == target) // Check if the patient with the specified ID is at the front
	{ 
        patient = *(temp->details);    // If found, assign the details to the 'patient' variable
        return patient;
    }
   
    temp = search(temp, target);  // Search for the patient with the specified ID
    if (temp -> next != nullptr)  // If the patient is found, assign the details to the 'patient' variable
	{
        patient = *(temp -> next -> details);   
    }
	
	else
	{
    	patient = Patient();  // If the patient is not found, create a default (empty) patient
	}
    
	return patient; // Return the details of the patien
}

void Queue::peek(){
   
    if (front == nullptr) 
	{
        cout << "[System] Queue is empty." << endl;
        return;
    }

    QueueNode* current = front;

    cout << endl << setw(20) << "[Current Queue]" << endl;  // Print header for the current queue

    current->details->print(); // Print details of the patient at the front

    if (numItem > 1)  // Check if there is more than one patient in the queue
	{   
        cout << endl << setw(10) << "|" << endl << setw(11) << "\\ /" << endl << endl;  // Print visual separator
        current->next->details->print(); // Print details of the next patient in the queue
        cout << endl;
    
    }
    
	else // If there is only one patient, print visual separator and a message indicating the queue is empty
	{
        cout << endl << setw(10) << "|" << endl << setw(11) << "\\ /" << endl << endl;
        cout << setw(13) << "Empty " << endl << "-------------------------" << endl;
    }

    if(current-> next != nullptr && current -> next-> next != nullptr) // Check if the current node and the next two nodes are not nullptr
	{
    	upComing(current);
	}
	
	int numItemSize = to_string(numItem).length();
	cout << "+-------------------+" << endl;
	cout << "|Total patient: " << numItem << setw(5 -numItemSize)  << " |" << endl ;
	cout<< "+-------------------+" << endl << endl; // Print the total number of patients in the queue
}

void Queue::upComing(QueueNode* current){
    
	QueueNode* temp = current->next->next;  // Set temp to point to the node two positions ahead of the current node
        
    cout << setw(20) << "[Upcoming Patient]" << endl   // Print header for upcoming patients
         << "----------------------" << endl;
       
	while (temp != nullptr)   // Iterate through the remaining nodes in the queue
	{
        cout << "[" << temp -> details -> getNo() << "] " << temp -> details -> getPatientName() << endl;  // Print details of each upcoming patient
        temp = temp-> next;
    }
        
	cout  << "----------------------" << endl;  // Print footer for upcoming patients
    
}

int Queue::returnItem()const{
	return numItem;
}

Queue::QueueNode* Queue::search(QueueNode* temp, int no)const{
    
	if (temp -> next == nullptr ||  temp -> next -> details -> getNo() == no)   // Check if the next node is nullptr or if the next node contains the target patient
	{
        return temp;
    } 
	
	else
	{ 
        return search(temp -> next, no); // If not found, recursively call the search method on the next node
    }
}



