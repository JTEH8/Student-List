//This is a program that allows you to create a list of students with their First and Last names, GPAs, and Student IDS. The program utilizes vectors and lots of pointers to function.
//Created by Jeffrey Teh
//Finished on October 30, 2021
#include <iostream>
//For setprecision()
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;
//Struct Student w/ First Name, Last Name, Student ID, and GPA.
struct Student{
  char firstname[21];
  char lastname[21];
  int ID;
  float GPA;
};
//Prototyping
void add(vector<Student*> &in);
void print(vector<Student*> &in);
void deleteStudent(vector<Student*> &in);
//Main method
int main(){
  char input[5]; 
  vector <Student*> v;
  cout <<"Welcome to Student List! Enter a student into a list by adding their first and lastnames, student ID, and GPA." << endl;
  cout << "TO add a student, type 'ADD'. To delte a student, type 'DELETE'. To print the list, type 'PRINT'. To quit, type 'QUIT'." << endl;
    while(true){
      cin >> input;
      if(strcmp(input, "ADD") == 0){
	add(v);
      }
      if(strcmp(input, "PRINT") == 0){
	print(v);
      }
      if(strcmp(input, "DELETE") == 0){
	deleteStudent(v);
      }
      if(strcmp(input, "QUIT") == 0){
	cout << "Thanks for using student list!";
	exit(0);
      }
    }
}
//Adding a new student
void add(vector<Student*> &in){
  //Student pointer
  Student* s = new Student();
  cout << "You're adding a new student!" << endl;
  cout << "Enter their name." << endl;
  cin >> s->firstname;
  cout << "Enter their lastname." << endl;
  cin >> s->lastname;
  cout << "Enter their student ID." << endl;
  cin >> s->ID;
  cout << "Enter their GPA." << endl;
  cin >> s->GPA;
  in.push_back(s);
}
//Print method
void print(vector<Student*> &in){
  //Iterator
  vector<Student*>::iterator ptr;
  //Going through the vector from beginning to end
  for(ptr = in.begin(); ptr < in.end(); ptr++){
    cout << (*ptr)->firstname << ", ";
    cout << (*ptr)->lastname << ", ";
    cout << (*ptr)->ID << ", ";
    cout << setprecision(3) <<(*ptr)->GPA << endl;
  }
}
//Deleting a student
void deleteStudent(vector<Student*> &in){
   int id;
   cout << "Enter the Student ID of the student you want to remove" << endl;
   cin >> id;
   //Another iterator
   vector<Student*>::iterator ptr2;
   for(ptr2 = in.begin(); ptr2 < in.end(); ptr2++){
     //If the student ID is the one entered
     if((*ptr2)->ID == id){
       //Erasing the student
       in.erase(ptr2);
     }
 }
   cout << "They have been removed." << endl;
}
