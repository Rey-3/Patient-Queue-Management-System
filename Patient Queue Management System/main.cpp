//*****************************************************************************************************************************************
// These codes were written by Chew Zhi Boon
// The provided C++ code defines a program for managing patient queues in a healthcare setting.The program utilizes three different queues,
// Normal Queue, Priority Queue, and Merge Queue. It allows users to register patients, enqueue them based on priority criteria, and manage 
// the queues through various options,the queues through various options, Patient registration involves capturing essential details such as
// IC number, name, age, gender, pregnancy status, and OKU status. The code demonstrates effective queue management, patient registration 
// validation, and merging of queues for streamlined operations. The program is designed for use in a counter-based patient service system, 
// providing a comprehensive solution for healthcare queue management.
//******************************************************************************************************************************************

#include <iostream>
#include <iomanip>
#include "Process.h" 
using namespace std;

int main(int argc, char** argv) {
    
	Process process; // Creating an object of the Process class
    int option = 0; // Variable to store the user's menu option

    process.enter(); //Just for convenience of testing (Not used in the program at all)
    
    while (option != 3)  // Main loop for menu and user interaction
    {
        // Displaying the menu
        cout << setw(38) << "Patient Queue Management System" << endl
             << "_____________________________________________" << endl;
        
		cout << "1 [Patient Registration ]" << endl
             << "2 [Queue Processing ]" << endl
             << "3 [Exit ]" << endl;

        cout << "Enter Option: "; // Prompting the user for input
        
		if (cin >> option)  // Checking if the input is a valid integer
        {
            cout << endl;
            
			if (option > 0 && option <= 3) // If the entered option is within the valid range
            {
                process.mainMenu(option); // Calling the mainMenu method with the chosen option
            } else {
                cout << "[System] Please Enter The Number Between 1 To 3." << endl << endl; // Displaying an error message for invalid options
            }
        } 
		
		else 
		{
            cout << "[System] Invalid Value, Please Try Again." << endl << endl; // Handling invalid non-integer input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Displaying a farewell message based on the exit status
    if (process.returnExit()) 
	{
        cout << "[System] Goodbye! Have a great day!" << endl;
    }
    
    else
	{
    	cout << "[System] Something Went Wrong, Exit Failed." << endl;
	}

    return 0;
}
