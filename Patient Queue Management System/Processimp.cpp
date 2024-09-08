#include "Process.h"

Process::Process() : normalQueue(), priorityQueue(),mergeQueue() {
    patientNumber = 1;
    age = 0;
    registerTime = "";
    patientIc = "";
    patientName = "";
    isPregnant = false;
    isOku = false;
    exit = false;
    gender = ' ';
}
	
void Process::mainMenu(int option){
	
	switch(option)  // Switch statement to handle different menu options
	{
		case 1:  // Option 1: Patient Registration
		{
			cout << "[System] Loading......" << endl << endl;
			patientRegistration();
			
			if(!exit)  // Check if registration was successful or if the program is exiting
			{
                cout << "[System] Registration Successful." << endl << endl;
            }
			
			else
			{
                cout << "[System] Exit Successful." << endl << endl;
            }
			
			break;
		}
		
		case 2:  // Option 2: Active Queue Menu
		{
			cout << "[System] Loading......" << endl << endl;
			active_Queue_Menu(); // Call the active_Queue_Menu method
			
			break;
		}
		
		case 3: // Option 3: Exit
		{
			exit = true; // Set the exit flag to true
			
			break;
		}
		
	}
}

void Process::active_Queue_Menu(){
	
	int option = 0;
	while(option != 4) // Display menu until the user chooses to return (option 4)
	{   
	     // Display options for Normal Queue, Priority Queue, and Merge Queue
	    cout << "[Active Queue Menu]" << endl
             << "1. Normal Queue " << "(" << normalQueue.returnItem() << " Patient)" << endl
             << "2. Priority Queue " << "(" << priorityQueue.returnItem() << " Patient)" << endl
             << "3. Merge Queue" << endl
             << "4: Return" << endl;
        
		cout << "Enter Option: "; // Prompt user for option
        
		if(cin >> option)  // Validate user input
		{
			cout << endl;
        	
			if(option >0 && option <= 4) // Check if the entered option is within the valid range
			{
                subMenu(option);
			}
			
			else
			{
				cout << "[System] Please Enter The Number Between 1 To 4." << endl << endl; //ask user only enter 1 to 4
			}
			
		}
		
		else
		{
			cout << "[System] Invalid Value, Please Try Again." << endl << endl;  // Handle invalid input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
	}
}

void Process::subMenu(int option){
	
	switch(option)
	{
		case 1: // Option 1: Manage Normal Queue
		{	
		    cout << "[System] Loading Normal Queue......" << endl;
		    
			if(!normalQueue.isEmpty()) // Check if the Normal Queue is not empty
			{   
		    	manageQueueOptions(normalQueue);
			}
			
			else
			{
				cout << "[System] Normal Queue is Empty." << endl << endl;
			}
			
			break;
		}
		
		case 2: // Option 2: Manage Priority Queue
		{
			cout << "[System] Loading Priority Queue......" << endl;
			
			if(!priorityQueue.isEmpty())  // Check if the Priority Queue is not empty
			{  
		    	manageQueueOptions(priorityQueue);
			}
			
			else
			{
				cout << "[System] Priority Queue Is Empty." << endl << endl;
			}

			break;
		}
		
		case 3:  // Option 3: Merge Queues
		{
			cout << "[System] Loading......" << endl;
            
            if(normalQueue.isEmpty() && priorityQueue.isEmpty()) // Check if both normalQueue and priorityQueue are empty
			{
            	cout << "[System] Normal Queue And Priority Queueis Is Empty." << endl << endl;
            	return;
			}
			
			mergeQueueConfirmation(); // Call the mergeQueueConfirmation function
	
			break;
		}
		
		case 4:  // Option 4: Return to Main Menu
		{ 
		    cout << "[System] Return To Main Menu......" << endl << endl;	
			
			break;
		}
	}
	
}

void Process::manageQueueOptions(Queue &queue){
	
	int option = 0;
	
    while (option != 5)  // Display options until the user chooses to return (option 5)
	{
		if(queue.isEmpty()) // Check if the queue is empty
		{  
			cout << "[System] The Queue is Empty, Return Back To Active Queue Menu." << endl << endl;
			return;
		}
		
		queue.peek();
		
        cout << "[1] Call Next Patient" << endl  // Display menu options for managing the queue
             << "[2] Call Patient No# " << endl
             << "[3] Delete Patient" << endl
             << "[4] Reset Queue" << endl
             << "[5] Return" << endl;

        cout << "Enter Option: "; // Prompt user for option

        if(cin >> option)  // Validate user input
		{
            cout << endl;

            if (option > 0 && option <= 5)  // Check if the entered option is within the valid range
			{
				exit = false;
                processQueue(option,queue);
                
                if(exit)
				{
                	cout << "[System] Exit Successful." << endl << endl; 
				}
               		
            }
			
			else
			{
                cout << "[System] Please Enter The Number Between 1 And 5." << endl << endl; // Make sure user enter 1 to 5
            }
            
        }
		
		else
		{
            cout << "[System] Invalid Value, Please Try Again." << endl << endl;  // Handle invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }	
}

void Process::processQueue(int option, Queue& queue) {
    
	switch (option) 
	{
        case 1:   // Option 1: Call Next Patient
		{
            Patient dePatient;
            queue.deQueue(dePatient);

            if (dePatient.getNo() != 0)  // Check if a patient was dequeued
			{
                cout << "[System] Calling "; // Display calling message and patient details

                if (dePatient.getGender() == 'M') 
				{
                    cout << "Mr ";
                } 
				
				else
				{
                    cout << "Ms ";
                }

                cout << dePatient.getPatientName() << "..... NO" << dePatient.getNo() << endl << endl;
                printPatient(dePatient);
   
            }
            
			break;
        }
        
        case 2:  // Option 2: Call Specific Patient
		{
			callByPatientNo(queue);
			break;
		}
		
		case 3:  // Option 3: Delete Specific Patient
		{
			dePatient(queue);
			break;
		}
		
		case 4: // Option 4: Reset Queue
		{   
	        if(!queue.isEmpty())
			{
	        	clearQueueConfirmation(queue);
			}
			break;
		}
		
		case 5:  // Option 5: Return to Active Queue Menu
		{	
		    cout << "[System] Return To Active Queue Menu...... " << endl << endl;
			return;
		}		
    }
}

void Process::callByPatientNo(Queue& queue){

	int no = 0;
	bool isValid = false;
			
	while(!isValid) 
	{
		isValid = true;
		cout << "Enter 0 to Exit." << endl;
		cout << "Please Enter Patient Number: ";
		
		if(cin >> no) // Validate user input
		{
			if(no == 0) // If user want to exit
			{
				exit = true;
				return;
			}
					
			queue.moveToFront(no);			
		}
				
		else
		{
			cout << "[System] Invalid Value, Please Try Again." << endl << endl;  // Handle invalid input
			isValid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');	
		}
	}
}

void Process::dePatient(Queue& queue){
	
	int no = 0;
	bool isValid = false;
			
	while(!isValid)
	{
		isValid = true;
				
		cout << "Enter 0 to Exit." << endl;
		cout << "Please Enter Patient Number: ";
			
		if(cin >> no)   // Validate user input
		{
			if(no == 0) // If user want to exit
		{
			exit = true;
			return;
		}
	
			queue.deleteQueue(no);
					
		}
				
		else // Handle invalid input
		{   
			cout << "[System] Invalid value, Please Try Again." << endl << endl;
			isValid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');	
		}
			
	}
}

void Process::mergeQueueConfirmation(){
    
	bool isValid = false; // Flag to track the validity of the user's input
    char option = ' ';
    while(!isValid)
	{
    	isValid = true; // Assume the input is valid initially

    	
    	cout << "[System] Are You Sure You Want to Merge Queue? [Y/N]: ";
    	cin >> option;
    	
    	if(option == 'Y' || option == 'y') // If the user chooses to merge the queues
		{
			cout << "[System] Loading......" << endl;
    		combineQueues(1,0);	
		}
		
		if(option == 'N' || option == 'n') // If the user chooses not to merge the queues
		{
			cout << "[System] Exit Successful." << endl << endl;
			return;
		}
		
		if(option != 'Y' && option != 'y' && option != 'N' && option != 'n') // If the user provides an invalid input
		{
			cout << "[System] Invalid Value, Please Try Again." << endl;
			isValid = false; // Set the flag to false to repeat the loop
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');	// Clear the input buffer
		} 
	}
}

void Process::clearQueueConfirmation(Queue& queue){
	
	bool isValid = false; // Flag to track the validity of the user's input
	char choice = ' '; // Variable to store the user's choice
	 
	while(!isValid) // Loop until a valid choice is made
	{
		isValid = true; // Assume the input is valid initially
		
		 // Ask the user whether they want to delete the queue
		cout << "[System] The Queue Still Having Patient Information, Do You Want To Delete? [Y/N]: ";
		cin >> choice;
		
		if(choice == 'Y' || choice == 'y') // If the user chooses to delete the queue
		{
			queue.clear();
			cout << "[System] Loading........." << endl;
			cout << "[System] Queue cleared Successfully." << endl << endl;
		}
		
		if(choice == 'N' || choice == 'n')  // If the user chooses not to delete the queue
		{
			cout << "[System] Exit Successful." << endl << endl; 
		}
		
		if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')  // If the user provides an invalid input
		{
			cout << "[System] Invalid Value, Please Try Again." << endl;
			isValid = false; // Set the flag to false to repeat the loop
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
	}
}

void Process::patientRegistration(){
	
	exit = false;
	registerTime = getCurrentTime();
	
	cout << "Enter 0 to Exit." << endl;	   // Display registration information
	cout << "Time: " << registerTime << endl;
	cout << "Counter Number: " << patientNumber << endl;
   
	icRegisteration();  // Perform IC registration
    if (exit) return; // If user want to exit
    
    calculateAge();   // Calculate age and gender
	calculateGender();
	    
	nameRegisteration();   // Perform name registration
	if (exit) return; // If user want to exit
	
    if(gender == 'F') // For female patients, perform pregnant registration
	{  
    	pregnantRegisteration();
	    if (exit) return; // If user want to exit
	}
	
	okuRegisteration();  // Perform OKU registration
	if (exit) return; // If user want to exit
	
	isComfirm();  // Confirm registration
	if (exit) return; // If user want to exit
	
	if(age >= 55 || isPregnant || isOku) // Enqueue patient based on priority criteria
	{ 
		priorityQueue.enQueue(Patient(patientIc,patientName,registerTime,patientNumber,age,gender,isPregnant,isOku));
	}
	
	else
	{
		normalQueue.enQueue(Patient(patientIc,patientName,registerTime,patientNumber,age,gender,isPregnant,isOku));
	}
	
	patientNumber++;  // Increment patient number
}

void Process::icRegisteration(){
	
	bool isValid = false;
	
	while(!isValid) // Continue prompting until a valid IC is entered or the user exits
	{
		isValid = true;
		
		cout << "Enter Patient IC: ";
		cin >> patientIc;
		cin.ignore();
		
		if(patientIc == "0") // Check if the user wants to exit
		{  
			exit = true;
			patientIc = "";
			return;
		}
		
		if(patientIc.length() != 12 )  // Validate IC length
		{
			std::cout << "[System] Error: Invalid input. Please Enter  12-Digit IC number." << std::endl;
			isValid = false;
			continue;
		}
		
		for(size_t i= 0; i < patientIc.length();++i)   // Validate IC contains only digits
		{
			char check = patientIc[i];
			if(!std::isdigit(check))
			{
				cout << "[System] Error: IC Number Must Consist Of Digits Only. Please Enter A Valid IC Number." << std::endl;
				isValid = false;
				break;
			}
		}
		
		if(isValid)  // Validate IC using a custom checkIc function
		{
			
			isValid = checkIc(patientIc);
			
			if(!isValid)
			{
				cout << "[System] Please Enter Correct IC Number." << endl;
			}
		}			
		
	}
}

void Process::nameRegisteration(){

	bool isValid = false;
	
	while(!isValid)  // Continue prompting until a valid name is entered or the user exits
	{
		isValid = true;
		cout << "Enter Name: ";
		getline(cin,patientName); 
		
		if(patientName == "0") // Check if the user wants to exit
		{ 
			exit = true;
			patientName = "";
			return;
		}
		
		if(patientName.empty())  // Validate if the name is not empty
		{
			cout << "[System] Invalid Value, Please Try Again." << endl;
			isValid = false;
		}
	}
	patientName[0] = toupper(patientName[0]);  // Capitalize the first letter of the patient's name
}

void Process::pregnantRegisteration(){
	
	char is_Pregnant =' ';
	bool isValid = false; // Flag to track the validity of the user's input
	
	
    // Loop until a valid choice is made
	while(!isValid)
	{
		isValid = true; // Assume the input is valid initially
		
		cout << "Pregnant [Y/N]: ";
		cin >> is_Pregnant;
		
		if(is_Pregnant == '0') // If the user chooses to exit (assuming '0' means exit)
		{ 
			exit = true;
			return;
		}
		
		if(is_Pregnant != 'Y' && is_Pregnant != 'y' && is_Pregnant != 'N' && is_Pregnant != 'n' )  // Check if the input is a valid choice (Y/y or N/n)
		{
			cout << "[System] Invalid Value, Please Try Again." << endl;
			isValid = false;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
		}	
		
	}
	
	isPregnant = (is_Pregnant == 'Y' || is_Pregnant == 'y');  // Set the 'isPregnant' member variable based on the user's input
}

void Process::okuRegisteration(){
	
	char is_Oku =' ';
	bool isValid = false;
	
	while(!isValid) // Continue prompting until a valid response is entered or the user exits
	{
		isValid = true;
		
		cout << "Are you OKU? [Y/N]: ";
		cin >> is_Oku;
		
		if(is_Oku == '0') // Check if the user wants to exit
		{  
			exit = true;
			return;
		}
		
		if(is_Oku != 'Y' && is_Oku != 'y' && is_Oku != 'N' && is_Oku != 'n' )  // when user enter invalid value
		{ 
			cout << "[System] Invalid Value, Please Try Again." << endl;
			isValid = false;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}	
		
	
	}
	
	isOku = (is_Oku == 'Y' || is_Oku == 'y');	 // Set the isPregnant flag based on the entered response
}

void Process::isComfirm(){
	
	char iscomfirm =' ';
	bool isValid = false;
	
	while(!isValid) // Continue prompting until a valid response is entered or the user exits
	{
		isValid = true;
		
		cout << "Confirm [Y/N]: ";
		cin >> iscomfirm;
		 
		if(iscomfirm != 'Y' && iscomfirm != 'y' && iscomfirm != 'N' && iscomfirm != 'n' ) // when user enter invalid value
		{
			cout << "[System] Invalid Value, Please Try Again." << endl;
			isValid = false;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
		}		
	}
	
	if(iscomfirm == 'N' || iscomfirm == 'n')  // Set the exit flag if the user chooses not to confirm
	{
		exit = true;
		iscomfirm = ' ';
		return;
	}
}

void Process::combineQueues(int counter, int item){
    
	Patient normalPatient;  // Create instances of Patient for normal and priority patients
    Patient priorityPatient;

    // If the counter is greater than the total patient number,
    // clear both normalQueue and priorityQueue, then call the merge function
    if (counter > patientNumber) 
	{
		normalQueue.clear(); 
        priorityQueue.clear();
        merge(item);
		
		if(normalQueue.returnItem() == item)  // Check if the merged item is successfully at the front of the normalQueue
		{
		 	cout << "[System] Merge Queue Succesffuly." << endl << endl;	
		}
		
		else
		{
			cout << "[System] Merge failed" << endl << endl;
		}
		
        return; // Exit the function
    }

    if (!normalQueue.isEmpty()) // If normalQueue is not empty, find the target patient with the given counter
	{
        normalPatient = normalQueue.findTarget(counter);
        
        // If the found patient has the same number as the counter,
        // enqueue the patient in the mergeQueue and increment the item
		if (normalPatient.getNo() == counter)
		{
            mergeQueue.enQueue(normalPatient);
            item++;
        }
    }

    if (!priorityQueue.isEmpty())   // If priorityQueue is not empty, find the target patient with the given counter
	{
        priorityPatient = priorityQueue.findTarget(counter);
        
        // If the found patient has the same number as the counter,
        // enqueue the patient in the mergeQueue and increment the item
		if (priorityPatient.getNo() == counter) 
		{
            mergeQueue.enQueue(priorityPatient);
            item++;
        }
    }

    combineQueues(counter + 1, item);  // Recursive call with the next counter value
}

void Process::merge(int no){
	
	Patient patient; // Create an instance of the Patient class
	
	if(no == 0){  // Base case: if 'no' is 0, return from the function
		return;
	}
	
	else{
		// Recursive case:
        // Dequeue a patient from the mergeQueue
		mergeQueue.deQueue(patient);
		normalQueue.enQueue(patient);
	}
	
	merge(no-1); // Recursive call with a decremented 'no' value
}

bool Process::checkIc(string lol)const{
		
	int birthYear = std::stoi(patientIc.substr(0, 2));  // Extract birth year, month, day, and place of birth from the IC number
	int birthMonth = stoi(lol.substr(2, 2));
    int birthday = stoi(lol.substr(4, 2));
    string pb = lol.substr(6,2);
    
    // Define an array of invalid place of birth values
    string invalidPb[] = {"00", "17", "18", "19", "20", "69", "70", "73","80", "81", "94", "95", "96", "97"};
    int invalidPbLength = sizeof(invalidPb) / sizeof(invalidPb[0]);
    
     // Check if the place of birth is invalid
    for(int i=0; i < invalidPbLength; i++)
	{
    	if(pb == invalidPb[i]) return false;
		
	}
     // Check if the birth month and day are valid
    return ((birthMonth == 2 && birthday > 0 && birthday <= 28) || (birthMonth != 2 && birthMonth > 0 && birthMonth <= 12 && birthday > 0 && birthday <= 31));
}

string Process::getCurrentTime()const{
    
	time_t now = time(0); // Get the current time
    tm* current_time = localtime(&now);

    char timeStr[10];  // Format the time as a string
    strftime(timeStr, sizeof(timeStr), "%I:%M %p", current_time);

    return timeStr; // Return the formatted time string
}

void Process::calculateAge(){
	
	time_t currentTime = std::time(nullptr); // Get the current date
    tm* timeInfo = std::localtime(&currentTime);
    int year = timeInfo->tm_year + 1900;
    int month = timeInfo->tm_mon + 1;
    int day = timeInfo->tm_mday;
    
    int birthYear = std::stoi(patientIc.substr(0, 2));  // Extract birth year, month, and day from the IC number
	int birthMonth = stoi(patientIc.substr(2, 2));
    int birthday = stoi(patientIc.substr(4, 2));
    
    birthYear = year - (birthYear >= 0 && birthYear <= year - 2000 ? birthYear + 2000 : birthYear + 1900); // Adjust birth year based on the century

    if (birthMonth > month || (birthMonth == month && birthday > day))  // Check if the birthday has occurred this year
	{
        birthYear--;
    }
    
    age = birthYear; // Set the age based on the calculated birth year
}

void Process::calculateGender(){
	
	int _gender = std::stoi(patientIc.substr(11, 1));  // Extract the gender information from the IC number

	bool isValid = modules(_gender);  // Check the validity of the gender information
	
	if(isValid) // Set the gender based on the validity
	
		gender = 'F';
	else
		gender = 'M';
}

bool Process::modules(int num)const{
	
	if(num == 0)  // Check if num is zero (Even Number)
		return true;
	else if (num <0) // Check if num is negative (odd number)
		return false;
	else
		return modules(num - 2); // Recursively call modules with num decreased by 2
}

bool Process::returnExit()const{
	return exit;
}

void Process::printPatient(Patient patient)const{
	
	// Get the sizes of various fields for formatting
	int nameSize = patient.getPatientName().length(); 
    int icSize = patient.getIcNo().length(); 
    int counterSize =  to_string(patient.getNo()).length();
    int ageSize = to_string(patient.getAge()).length();
    int genderSize = (patient.getGender() == 'F'? 6 : 4);
    int pregnantSize = (patient.getIsPregnant() ? 3 : 2);
    int okuSize = (patient.getIsOku() ? 3 : 2);
	
	// Print the patient information
	cout << setw(29) << "[Patient Infomation]" << endl;
	cout << "+";
    
    int size = 40;
	for(int i =0; i < size; i++)
	{
		cout << "-";
	}
	
	cout << "+" << endl;
	
	cout << "| Patient Name: " << patient.getPatientName() << setw(size - 14 -nameSize) << "|" << endl
	     << "| Counter Number: " << patient.getNo() << setw(size - 16 - counterSize) << "|" << endl
		 << "| IC Number: " << patient.getIcNo() << setw(size - 23) << "|" << endl
		 << "| Age: " << patient.getAge() << setw(size - 5 - ageSize) << "|" << endl
		 << "| Gender: " << (patient.getGender()  == 'F' ? "Female" : "Male") << setw(size - 8 - genderSize) << "|" << endl;
				     
		if(patient.getGender() == 'F')
		{
			cout << "| Pregnant: " << (patient.getIsPregnant() ? "YES" : "NO") << setw(size - 10 -pregnantSize) << "|" <<endl;
		}
					 
	cout << "| OKU: " << (patient.getIsOku() ? "YES" : "NO") << setw(size - 5 - okuSize) << "|" << endl << "+";
		
	for(int i =0;i  < size; i++)
	{
		cout << "-";
	}
	
	cout << "+" << endl << endl;	
}

void Process::enter(){ // Just for convenience of testing (Not used in the program at all)

	normalQueue.enQueue(Patient("021202070587", "JohnDoe", "5:30am", 7, 21, 'M', false, false));
	normalQueue.enQueue(Patient("061013070532", "JaneDoe", "6:20am", 4, 17, 'F', false, false));
	normalQueue.enQueue(Patient("971019070589", "BobSmith", "7:10am", 6, 26, 'M', false, false));
	normalQueue.enQueue(Patient("001020070432", "AliceJohnson", "8:00am", 9, 23, 'F', false, false));
	normalQueue.enQueue(Patient("041203078313", "ChrisBrown", "8:30am", 2, 19, 'M', false, false));
	
	priorityQueue.enQueue(Patient("610910075842", "EmilyWhite", "5:45am", 5, 62, 'F', false, false));
	priorityQueue.enQueue(Patient("031019070589", "MichaelGreen", "6:40am", 3, 20, 'M', false, true));
	priorityQueue.enQueue(Patient("980419074188", "SaraMiller", "7:25am", 8, 25, 'F', true, true));
	priorityQueue.enQueue(Patient("020217071378", "DavidJones", "8:15am", 1, 21, 'F', true, false));

	patientNumber = 9;
}
