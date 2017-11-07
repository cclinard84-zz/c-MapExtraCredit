#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>  

using std::string;
using std::cout;
using std::ostream;
using std::endl;
using std::map;
using std::cin;

class Student{
public:
    string firstName;
    string lastName;
    string id;
    double gpa;
    Student();
    Student(string, string, string, double);
};

Student::Student(){
    this->firstName = "default";
    this->lastName = "default";
    this->id = "default";
    this->gpa = 0.0;
};

Student::Student(string lastName, string firstName, string id, double gpa){
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    this->gpa = gpa;
};

class DescendingOrder{
    public:
        bool operator()(const string& s1, const string& s2) const {
            return s1 > s2;
        }
};

ostream& operator<<( ostream& out, const Student& student ){
       out << student.firstName << ", " << student.lastName 
           << "\n\t" << student.id << "\n\t" << student.gpa << endl;
        return out;
}


bool operator<(const Student s1, const Student s2){
    return strcmp(s1.id.c_str(), s2.id.c_str());
}

bool compareStudents(std::pair<string,Student> , std::pair<string,Student>);
void createStudents(Student[]);
void buildMap(map<string, Student, DescendingOrder>&, Student[]);

int main(int argc, char **argv)
{
    map<string, Student, DescendingOrder> mymap;
    Student students[10];
    map<string, Student, DescendingOrder>::const_iterator cIt;   
    string userInput = "-1";

	cout << "Hello! Welcome to student mapper!" << endl;
    createStudents(students);
    buildMap(mymap, students);
    cout << "The smallest element is " << std::min_element(mymap.begin(),mymap.end(), compareStudents)->second << endl;
    cout << "Now printing reverse order by student id:" << endl;
   for(auto cIt = mymap.cbegin(); cIt != mymap.cend(); ++cIt){
        cout << (*cIt).second << endl;
    }
    cout << "Input the student ID of the student you want to search for or 0 to exit: ";
    cin >> userInput;
    while(userInput != "0"){
        if(mymap.count(userInput) > 0){
            cout << mymap.find(userInput)->second;
        }
        else{
            cout << "Could not find the student" << endl;
        }
        
        cout << "Input the student ID of the student you want to search for: ";
        cin >> userInput;
    }
   
	return 0;
}


bool compareStudents(std::pair<string,Student> pair1, std::pair<string,Student> pair2){ 
    return pair1.second.lastName < pair2.second.lastName;
}

void createStudents(Student students[10]){
    students[0] = Student( "Lovelace", "Ada", "P20112845", 4.0 );
    students[1] = Student( "Von Neumann", "John", "P20112844", 3.9 );
    students[2] = Student( "Torvald", "Linus", "P20112843", 3.8 );
    students[3] = Student( "Turing", "Alan", "P20112842", 3.7 );
    students[4] = Student( "Hamilton", "Margaret", "P20112841", 3.6 );
    students[5] = Student( "Knuth", "Donald", "P20112840", 3.5 );
    students[6] = Student( "Bloom", "Burton", "P20112839", 3.4 );
    students[7] = Student( "Hooper", "Grace", "P20112838", 3.2 );
    students[8] = Student( "Holberton", "Betty", "P20112837", 3.1 );
    students[9] = Student( "Sammet", "Jean", "P20112836", 3.0 );
}
void buildMap(map<string, Student, DescendingOrder> &mymap, Student students[10]){
    mymap.insert( std::pair<string,Student>( students[5].id, students[5]) );
    mymap.insert( std::pair<string,Student>( students[4].id, students[4]) );
    mymap.insert( std::pair<string,Student>( students[3].id, students[3]) );
    mymap.insert( std::pair<string,Student>( students[2].id, students[2]) );
    mymap.insert( std::pair<string,Student>( students[1].id, students[1]) );
    mymap.insert( std::pair<string,Student>( students[0].id, students[0]) );
    mymap.insert( std::pair<string,Student>( students[6].id, students[6]) );
    mymap.insert( std::pair<string,Student>( students[7].id, students[7]) );
    mymap.insert( std::pair<string,Student>( students[8].id, students[8]) );
    mymap.insert( std::pair<string,Student>( students[9].id, students[9]) );
}