#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


void insert(string name,int roll,int marks) {
  ofstream f("student.txt",ios::app);
  
  f << name << "\t" << roll << "\t" << marks << endl;
  cout << "Student information successfully created!" << endl;
  
  f.close();
}

void display() {
  ifstream f("student.txt");
  
  string name;
  int roll,marks;

  cout << "Name\tRollNumber\tMarks" << endl;

  while(f >> name >> roll >> marks) {
    cout << name << "\t\t" << roll << "\t\t" << marks << endl;
  }
  f.close();
}

void deleteStudent(int rollNumber) {
  ifstream f("student.txt");
  ofstream a("temp.txt");
  
  
  string name;
  int roll,marks;
  bool found = false;
  
  while(f >> name >> roll >> marks) {
   if(rollNumber == roll) {
      found = true;
      continue;
   }
    a << name << "\t" << roll << "\t" << marks << endl;
  }

  f.close();
  a.close();
  
  if(found){
    remove("student.txt");
    rename("temp.txt","student.txt");
    cout << "Student deleted successfully!" << endl;
  }
  else {
    remove("temp.txt");
    cout << "Student not found!" << endl;
  }
  
}

void search(int rollNumber) {
  ifstream f("student.txt");
  
  string name;
  int roll,marks;
  bool found = false;
  
  while(f >> name >> roll >> marks) {
    if(rollNumber == roll) {
     found = true;
      cout << "Student with roll number <" << roll << "> found!" << endl;
    }
  }
  if(!found) { 
      cout << "Student with roll number <" << roll << "> not found!" << endl;
  }

  f.close();
}

int main() {
  
  int choice;
  string name;
  int roll,marks,numberOfStudent,key;
  
  do{
    cout << "\n******************MENU****************" << endl;
    cout << "1) Create student" << endl;
    cout << "2) Search student" << endl;
    cout << "3) Delete student" << endl;
    cout << "4) Display student" << endl;
    cout << "5) Exit" << endl;
    
    cout << "Enter your choice: "; cin >> choice;
    
    
    switch(choice) {
      case 1:
        cout << "Enter how many students you want to create: "; cin >> numberOfStudent;
        for(int i = 0; i < numberOfStudent; i++) {
          
          cout << "Enter student name: "; cin >> name;
          cout << "Enter student roll: "; cin >> roll;
          cout << "Enter student marks: "; cin >> marks;
          
          insert(name,roll,marks);
          cout << "Inserted successfully!\n" << endl;
        }
        break;
        
      case 2:
        cout << "Enter roll number to earch: "; cin >> key;
        search(key);
        break;
        
      case 3:
        cout << "Enter roll number to delete: "; cin >> key;
        deleteStudent(key);
        break;
        
      case 4:
        display();
        break;
        
      case 5:
        cout << "Exited successfully!" << endl;
        break;
        
      default:
        cout << "Invalid Choice!" << endl;
        break;
        
    }
    
    
    
  }while(choice != 5);
  
  return 0;
}
