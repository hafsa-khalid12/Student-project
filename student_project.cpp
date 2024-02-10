#include <iostream>
using namespace std;
class Student
{

private:
  string name;
  int rollno;
  float cgpa;

public:
  Student(string name, int rollno, float cgpa);

  string get_name();
  int get_rollno();
  float get_cgpa();

  void set_name(string name);
  void set_rollno(int rollno);
  void set_cgpa(float cgpa);

  void study();

  char grade();

  void print_details();

  ~Student();

  static int count;
  static int countstudent();
 friend bool compareCgpa(Student s1, Student s2);
};
Student::Student(string name, int rollno, float cgpa)
    : name{name}, rollno{rollno}, cgpa{cgpa}
{
 // cout << "constructor called for " << name << endl;
}

string Student::get_name()
{
  return name;
}
int Student::get_rollno()
{
  return rollno;
}
float Student::get_cgpa()
{
  return cgpa;
}

void Student::set_name(string name)
{
  this->name = name;
}
void Student::set_rollno(int rollno)
{
  this->rollno = rollno;
}
void Student::set_cgpa(float cgpa)
{
  this->cgpa = cgpa;
}
void Student::study()
{
  cout << name << " is studying." << endl;
}

char Student::grade()
{
  if (cgpa >= 3.50)
  {
    return 'A';
  }
  else if (cgpa >= 3.00)
  {
    return 'B';
  }
  else if (cgpa >= 2.50)
  {
    return 'C';
  }
  else if (cgpa >= 2.00)
  {
    return 'D';
  }
  else
  {
    return 'F';
  }
}
bool compareCgpa(Student s1, Student s2) {
  return (s1.cgpa > s2.cgpa);
}

void Student::print_details()
{
  cout << "Name : " << this->name << endl;
  cout << "Rollno : " << this->rollno << endl;
  cout << "Cgpa : " << this->cgpa << endl;
}

Student::~Student()
{

}

int Student::count = 0;
int Student::countstudent()
{
  count++;
  return count;
}

int main()
{

  string name;
  int rollno;
  float cgpa;

  cout << "Enter the name" << endl;
  cin >> name;
  cout << "Enter the rollno" << endl;
  cin >> rollno;
  cout << "Enter the cgpa" << endl;
  cin >> cgpa;

  Student s1(name, rollno, cgpa);

  s1.print_details();

  s1.study();

  cout << "Grade : " << s1.grade() << endl;

  cout << "Number of students: " << Student::countstudent << endl;

  int operation;
  char ans = 'Y';
  do
  {
    cout << "Select the Operation: " << endl;
    cout << "1. Change name" << endl;
    cout << "2. Change roll number" << endl;
    cout << "3. Change cgpa" << endl;
    cout<<"4.Compare cgpa with other student"<<endl;
    cout << "Choosen Operation is: ";
    cin >> operation;

    switch (operation)
    {
    case 1:

      cout << "Enter the new name of the student: ";
      cin >> name;
      s1.set_name(name);
      cout << "The name of the student is changed to " << s1.get_name() << endl;
      s1.study();
      cout << "Grade " << s1.grade() << endl;
      cout << "Number of students: " << Student::countstudent << endl;
      break;
    case 2:

      cout << "Enter the new roll number of the student: ";
      cin >> rollno;
      s1.set_rollno(rollno);
      cout << "The roll number of the student is changed to " << s1.get_rollno() << endl;
      s1.study();
      cout << "Grade " << s1.grade() << endl;
      cout << "Number of students: " << Student::countstudent << endl;
      break;
    case 3:

      cout << "Enter the new cgpa of the student: ";
      cin >> cgpa;
      s1.set_cgpa(cgpa);
      cout << "The cgpa of the student is changed to " << s1.get_cgpa() << endl;
      s1.study();
      cout << "Grade " << s1.grade() << endl;
      cout << "Number of students: " << Student::countstudent << endl;
      break;
 case 4:
  cout << "Enter the name of the other student: ";
      cin >> name;
      cout << "Enter the roll number of the other student: ";
      cin >> rollno;
      cout << "Enter the cgpa of the other student: ";
      cin >> cgpa;
      
      Student s2(name,rollno,cgpa);
     
  
      if (compareCgpa(s1, s2)) {
        cout << s1.get_name() << " has higher cgpa than " << s2.get_name() << endl;
      }
      else if (compareCgpa(s2, s1)) {
      	cout << s2.get_name() << " has higher cgpa than " << s1.get_name() << endl;
      }
      else {
        cout << s1.get_name() << " and " << s2.get_name() << " have equal cgpa" << endl;
      }
      break;
    
    Default:
      cout << "Please enter a valid operation." << endl;
      break;
    }
    cout << "Do you want to continue (Y/N)?\n";

    cin >> ans;
  } while (ans == 'Y' || ans == 'y');

  return 0;
}
