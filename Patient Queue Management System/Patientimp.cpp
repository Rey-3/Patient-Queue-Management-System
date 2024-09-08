#include "Patient.h"

Patient::Patient(){
	icNo = "";
	patientName = "";
	registerTime = "";
	no = 0;
	age = 0;
	gender = ' ';
	isPregnant = false;
	isOku = false;
}

Patient::Patient(string _icNo, string _patientName, string _registerTime, int _no, int _age, char _gender, bool _isPregnant, bool _isOku){
	icNo = _icNo;
	patientName = _patientName;
	registerTime = _registerTime;
	no = _no;
	age = _age;
	gender = _gender;
	isPregnant = _isPregnant;
	isOku = _isOku;
	
}

void Patient::setIcNo(string _icNo){
	icNo = _icNo;
}

void Patient::setPatientName(string _patientName){
	patientName = _patientName;
}

void Patient::setRegisterTime(string _registerTime){
	registerTime = _registerTime;
}

void Patient::setNo(int _no){
	no = _no;
}

void Patient::setAge(int _age){
	age = _age;
}

void Patient::setGender(char _gender){
	gender = _gender;
}

void Patient::setIsPregnant(bool _isPregnant){
	isPregnant = _isPregnant;
}

string Patient::getIcNo()const{
	return icNo;
}

string Patient::getPatientName()const{
	return patientName;
}

string Patient::getRegisterTime()const{
	return registerTime;
}

int Patient::getNo()const{
	return no;
}

int Patient::getAge()const{
	return age;
}

char Patient::getGender()const{
	return gender;
}

bool Patient::getIsPregnant()const{
	return isPregnant;
}

bool Patient::getIsOku()const{
	return isOku;
}

void Patient::print() const{
    
	int size = to_string(no).length() + registerTime.length() + patientName.length() + 11; // Calculate the size required for the formatting
    
     // Print the top border of the formatted section
    cout << "+";
    
	for (int i = 0; i < size; i++) 
	{
        cout << "-";
    }

    cout << "+\n|[" << no << "] " << registerTime << "," << patientName << ",(" << gender << ")," << age << "|\n+";
    
    for (int i = 0; i < size; i++) 
	{
        cout << "-";
    }

    cout << "+ \n";
}

