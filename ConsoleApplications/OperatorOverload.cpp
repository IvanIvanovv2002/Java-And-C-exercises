
#include <iostream>
#include <string>
using namespace std;
class Person {
public:

    string name;
    int age;
    int grade;

    Person(string name,int age,int grade) {
        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    friend ostream& operator<<(ostream& out,Person &person) {
        out << person.name << " " << person.age << " " << person.grade;
        return out;
    }

    Person operator++() {
        this->age++;
        this->grade--;
        return *this;
    }

    bool operator>(Person &p2) {
        return this->grade > p2.grade;
    }

    bool operator==(Person& p2) {
        return this->grade == p2.grade && this->name == p2.name && this->age == p2.age;
    }
};

int main()
{
    Person person1 ("ivan",25,6);
    Person person2("georgi", 17, 5);
    cout << person1 << endl;
    cout << person2 << endl;

    ++person1;
    ++person2;

    cout << person1 << endl;
    cout << person2 << endl;

    bool check1 = person1 > person2;
    bool equality = person1 == person2;

    cout << check1 << endl;
    cout << equality << endl;

}

