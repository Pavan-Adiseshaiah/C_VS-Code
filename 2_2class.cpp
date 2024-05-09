// By Default, there are 3 built-in functions in the Class - Default Constructor, Copy Constructor, Destructor
// Can have multiple constructors
#include <iostream>

using namespace std;

class Student   {
    public:
    // default constructor
    Student() {                                 // No return type
        name = "NA";
        id = -1;
    }

    Student(const string &name) {               // Mostly use references in func parameters, Student (Student *this) - implicit
        this -> name = name;                    // Similar to self in python. this ==> object pointer
    }

    Student(const string &n, const long &i) {
        name = n;
        id = i;
    }

    // copy constructor
    Student(const Student &other)   {       // This is similar to default copy constructor
        id = other.id;                      // Used to initialize members by passing another object as arg
        name = other.name;
        sex = other.sex;
        type = other.type;
        status = other.status;
    }

    // destructor
    ~ Student() {
        cout << "destructor called!\n";
    }

    // Public access-specifier!
    string name;
    string sex;
    string type;
    string status;
    long id;
};

int main () {
    Student std1;
    std1.name = "Student_1";
    Student std2 (std1);                // Behaves same way without the above copy constructor
    Student std3 ("Student_3", 3);

    Student std4 ("Std_4");              // Explicit construction

    cout << std1.name << endl;
    cout << std2.name << endl;
    cout << std3.name << "\t" << std3.id << endl;
}