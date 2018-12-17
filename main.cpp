#include <vector>
#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct studInfo{
	string fName;
	string lName;
	string studCourse;
	string sex;
	int age;
	string idNum;
	string level;
	char studGrade;
	double studScore;
}studFile[50];

struct staffInfo{
	string staffFName;
	string staffLName;
	string staffSex;
	int staffAge;
	string staffQualif;
	string staffCourse;
	string staffID;
	int numOfCourses;
	int numOfClasses;
	double salary;
	int staffNum = 00;
}staffFile[10];


void newStudRec();
void studRecUp();
void newStaffRec();
void staffRecUp();
void delStudRec();
void delStaffRec();

int main (){
	ofstream sOutput;
	ofstream stOutput;
	char choice;
	string searchItem;
	int found = 1;
	
	cout << "  *****************************************************  " << endl;
	cout <<setw(5) <<" ABC SCHOOL MANAGEMENT SYSTEM " << endl;
	cout <<"\n-------------------------------------------------"<<endl;
	cout << " 1. Enter 1 for student " << endl;
	cout << " 2. Enter 2 for staff "<<endl;
	cout << " 3. Enter 3 to exit the program " <<endl;
	cin >> choice;
	
	while(choice != '3'){
		
	
	
		switch (choice){
			case '1':
				while(1){
					system("cls");
					cout << "  *****************************************************  " << endl;
					cout <<setw(5) <<" ABC SCHOOL MANAGEMENT SYSTEM " << endl;
					cout <<"\n-------------------------------------------------"<<endl;
					cout << "Enter 1 to create new student file"<<endl;
					cout << "Enter 2 to edit an existing student file"<<endl;
					cout << "Enter 3 to delete a file"<<endl;
					cout << "Enter 4 to go back"<<endl;
					cin >> choice;
					
					switch(choice){
						case '1':
							sOutput.open("student.txt");
							
							for (int i = 0; i<50; i++){
								if((choice == 'Y') || (choice == 'y')){
									newStudRec();
									cout << " Press 'y' or 'Y' to continue else press 'n' or 'N' "<< endl;
									cin >> choice;
									
								}
								
							}
							sOutput.close();
							continue;
							
						case '2':
							studRecUp();
							continue;
					
							
						case '3':
							delStudRec();
							continue;
						case '4':
							break;
							
					}
				}
				continue;
				
				
			case '2':
				system("cls");
				while(2){
					cout << "  *****************************************************  " << endl;
					cout <<setw(5) <<" ABC SCHOOL MANAGEMENT SYSTEM " << endl;
					cout <<"\n-------------------------------------------------"<<endl;
					
					cout << "Enter 1 for new record"<<endl;
					cout << "Enter 2 to edit record"<<endl;
					cout << "Enter 3 to delete "<<endl;
					cout << "Enter 4 to exit "<<endl;
					cin >> choice;
					
					switch(choice){
						case '1':
							sOutput.open("staff.txt");
							
							for (int i = 0; i<50; i++){
								if((choice == 'Y') || (choice == 'y')){
									newStaffRec();
									cout << " Press 'y' or 'Y' to continue else press 'n' or 'N' "<< endl;
									cin >> choice;
									
								}
								else{
									break;
								}
								
							}
							sOutput.close();
							continue;
							
						case '2':
							staffRecUp();
							continue;
							
						case '3':
							delStaffRec();
							continue;
						case '4':
							break;
					}
					
					
				}
				continue;
				
			case '3':
				break;
			default:
				cout << "Invalid Input"<<endl;
				cout << "Enter '3' to exit program"<<endl;
				cin >>choice;
				break;
					
				
		}
	
	}
	
	return 0;
}

void newStudRec(){
	
	
	studInfo newRec;
	fstream sfile;
	
	sfile.open("stud.txt");
	cout << "Enter student full name : ";
	cin >> newRec.fName >> newRec.lName;
	cout << endl;
	cout << "Enter student sex : ";
	cin >> newRec.sex;
	cout << "Enter student age : ";
	cin >> newRec.age;
	cout << "Enter student level : ";
	cin >> newRec.level;
	cout << "Enter student program of study : ";
	cin >> newRec.studCourse;
	cout << "Create student ID : ";
	cin >> newRec.idNum;
									
	sfile << newRec.fName<< newRec.lName<< newRec.sex << newRec.age
			<< newRec.level << newRec.studCourse << endl;	
	sfile.close();
}

void newStaffRec(){
	staffInfo newStaff;
	fstream stfile;
	
	stfile.open("staff.txt"); 
	
	cout << "Enter staff first name : ";
	cin >> newStaff.staffFName >> newStaff.staffLName;
	cout << "Enter staff age : ";
	cin >> newStaff.staffAge;
	cout << "Enter staff sex : ";
	cin >> newStaff.staffSex;
																			
	cout << "Enter staff Qualification : ";
	cin >> newStaff.staffQualif;
	cout << "Enter course to be taught : ";
	cin >> newStaff.staffCourse;
	cout << "Enter number of classes assigned : ";
	cin >> newStaff.numOfClasses;
	cout << "Enter monthly salary : ";
	cin >> newStaff.salary; 
										
	stfile << newStaff.staffFName << newStaff.staffLName
			 << newStaff.staffAge << newStaff.staffAge
			 << newStaff.staffSex << newStaff.staffQualif
			 << newStaff.staffCourse << newStaff.numOfClasses
			 << newStaff.salary << endl;
	stfile.close();
}

void delStudRec(){
	int id;
	cout << "Enter ID number : ";
	cin >> id;
	
	studInfo delStud;
	fstream temp;
	string line;
	fstream in;
	
	in.open("student.txt");
	temp.open("tempfile.txt",ios::app);
	
	while(getline(in,line)){
		istringstream ss(line);
		std::istream_iterator<std::string>begin(ss),end;
		std::vector<std::string>arrayToken(begin, end);
		
		vector<string>::iterator vec;
		int flg = 0;
		int i;
		for(vec = arrayToken.begin(); vec != arrayToken.end(); vec++){
			if(i == 0 && id == *vec){
				flg = 1;
			}
			else{
				break;
				i++;
			}
		}
			
		if(flg!=1){
			temp << line << endl;
		}
			
		else{
			cout << "\nDeleted!" << endl;	
		}
		
	}
	
	in.close();
	temp.close();
	remove("student.txt");
	rename("temp.txt","student.txt");
}

void delStaffRec(){
	//int id;
	cout << "Enter Staff ID number : ";
	cin >> staffID;
	
	studentInfo delStaff;
	fstream temp;
	string line;
	fstream in;
	
	in.open("staff.txt");
	temp.open("tempfile.txt",ios::app);
	
	while(getline(in,line)){
		istringstream ss(line);
		std::istream_iterator<std::string>begin(ss),end;
		std::vector<std::string>arrayToken(begin, end);
		
		vector<string>std::iterator vec;
		int flg, i = 0;
		
		for(vec = arrayToken.begin(); vec != arrayToken.end(); vec++){
			if(i == 0 && id ==* vec){
				flg = 1;
			}
			else{
				break;
				i++;
			}
		}
			
		if(flg!=1){
			temp << line << endl;
		}
			
		else{
			cout << "\nDeleted!" << endl;	
		}
		
	}
	
	in.close();
	temp.close();
	remove("staff.txt");
	rename("temp.txt","staff.txt");
}

void studRecUp(){
	string item, choice;
	studentInfo studUp;
	cout << "Enter student ID : ";
	cin >> item;
							
	for (int j = 0; j<50; j++){
		if (studUp.idNum == item){
			cout << "First Name : " << studUp.fName<<endl;
			cout << "Last Name : " << studUp.lName<<endl;
			cout << "Sex : " << studUp.sex<<endl;
			cout << "Age : " << studUp.age<<endl;
			cout << "Program Of Study : " << studUp.studCourse<<endl;
			cout << "Level : " << studUp.level<<endl;
									
			cout << "\nEnter 1 to edit name "<<endl;
			cout << "Enter 2 to edit age "<<endl;
			cout << "Enter 3 to edit course "<<endl;
			cout << "Enter 4 to edit sex "<<endl;
			cout << "Enter 5 to edit class"<<endl;
			cin>>choice;
									
			switch(choice){
				case '1':
					cout << "\nEnter new name : "<<endl;
					cin >> studUp.fName >> studUp.lName;
					sOutput<<studUp.fName << studUp.lName << endl;
					break;
				case '2':
					cout << "\nEnter new age : "<<endl;
					cin >> studUp.age;
					sOutput<<studUp.age;
					break;
				case '3':
					cout << "\nEnter new course : "<<endl;
					cin >> studUp.studCourse;
					sOutput<<studUp.studCourse;
					break;
											
				case '4':
					cout << "\nEnter new sex : "<<endl;
					cin >> studUp.studCourse;
					sOutput<<studUp.studCourse;
					break;
											
				case '5':
					cout << "\nEnter new class : "<<endl;
					cin >> studUp.studCourse;
					sOutput<<studUp.studCourse;
					break;
			}
		}
		break;
	}
}

void staffRecUp(){
	string item, choice;
	studentInfo staffUp;
	cout << "Enter student ID : ";
	cin >> item;
							
	for (int j = 0; j<50; j++){
		if (studUp.idNum == item){
			cout << "First Name : " << staffUp.staffFName<<endl;
			cout << "Last Name : " << staffUp.staffLName<<endl;
			cout << "Sex : " << staffUp.staffSex<<endl;
			cout << "Age : " << staffUp.staffAge<<endl;
			cout << "Qualification : " << staffUp.staffQualif<<endl;
			cout << "Course teaching : " << staffUp.staffCourses<<endl;
			cout << "Classes to be taught : "<<staffUp.staffClasses<<endl;
			cout << "Salary : " <<staffUp.salary << endl;	
										
			cout << "\nEnter 1 to edit name "<<endl;
			cout << "Enter 2 to edit sex "<<endl;
			cout << "Enter 3 to edit age "<<endl;
			cout << "Enter 4 to edit Qualification "<<endl;
			cout << "Enter 5 to edit classes teaching"<<endl;
			cout << "Enter 6 to edit salary"<<endl;
			cin>>choice;
									
			switch(choice){
				fstream stfile;
				stfile.open("staff.txt");
				case '1':
					cout << "\nEnter new name : "<<endl;
					cin >> staffUp.staffFName >> staffUp.staffLName;
					stfile<<studUp.staffFName << studUp.staffLName << endl;
					break;
				case '2':
					cout << "\nEnter new sex : "<<endl;
					cin >> staffUp.staffSex;
					stfile<<staffUp.staffSex;
					break;
				case '3':
					cout << "\nEnter new age : "<<endl;
					cin >> staffUp.staffAge;
					stfile<<staffUp.staffAge;
					break;
											
				case '4':
					cout << "\nEnter new Qualification : "<<endl;
					cin >> staffUp.staffQualif;
					stfile<<staffUp.staffQualif;
					break;
											
				case '5':
					cout << "\nEnter new class : "<<endl;
					cin >> staffUp.staffClasses;
					stfile<<staffUp.staffClasses;
					break;
				
				case '6':
					cout << "\nEnter new salary : "<<endl;
					cin >> staffUp.salary;
					stfile<<staffUp.salary;
					break;
					
				default:
					cout << "Invalid input"<<endl;
					break;
				stfile.close();
			}
		}
		break;
	}
}


/*
refences
https://github.com/manju07/School-Management-System/tree/master/Main
https://fahad-cprogramming.blogspot.com/2016/03/school-management-cpp-project-source-code.html?m=1

*/