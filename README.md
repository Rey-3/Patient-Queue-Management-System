
To develop a Patient Queue Management System for a local clinic, the prototype is designed to effectively process and track patient flows, aiming to reduce patient wait times and provide prioritized services for elderly, disabled, and pregnant patients. The system operates in a console mode environment with a simple user interface for clinical staff to manage the queue efficiently.

System Overview
The main menu of the system presents three options:

Patient Registration: Allows clinical staff to register new patients.
Queue Processing: Enables doctors and staff to manage patient queues.
Exit: Closes the system.
The menu operates in a loop, allowing users to continuously interact with the system until they choose to exit.

Patient Registration
When a staff member selects Patient Registration:

The system prompts for patient details including IC number, name, and pregnancy status (for female patients).
The system captures the current registration time using the system clock and automatically generates a counter number for reference.
The system calculates the patient's age and determines the gender based on the IC number. Patients aged 55 and above, pregnant women, and disabled individuals (OKU) are automatically added to a priority queue for expedited service.
Queue Management
Patient details are added to the appropriate queue after confirmation:

Normal Queue: For regular patients.
Priority Queue: For elderly, pregnant, and disabled patients.
Doctors can access the Queue Processing menu from the main interface, where they can view the status of both queues:

Normal Queue: Displays the count of regular patients.
Priority Queue: Displays the count of priority patients.
Merge Queue: Combines the priority queue with the normal queue, merging records sequentially based on the counter number.
Return: Returns to the main menu.
Queue Processing
A submenu allows doctors to manage the patient queues:

Call Next Patient: Processes the next patient in line and updates the queue accordingly.
Call Patient No#: Allows the doctor to process a specific patient by entering their queue number.
Delete Patient: Removes a patient from the queue who has left early.
Reset Queue: Clears all patient details from the queue.
Return: Returns to the active queue menu.
User Interface
The interface for displaying the patient queues is designed to provide clear and concise information:

Boxed Format: Displays patient details such as counter number, registration time, name, gender, and age. Priority patients have a special indicator to differentiate them from regular patients.
System Design
The system utilizes Abstract Data Type (ADT) classes to encapsulate patient details and queue management logic. This design ensures that patient data is stored efficiently and is easily accessible for processing.

