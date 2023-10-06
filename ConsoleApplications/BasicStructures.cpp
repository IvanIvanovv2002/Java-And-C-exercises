
#include <iostream>
using namespace std;

struct Employee {
    string name;
    string position;
    float salary;
};

int main()
{
    int countOfEmployees;
    cin >> countOfEmployees;
    Employee* employee = new Employee[countOfEmployees];

    string name, position; float salary;
   
    for (size_t i = 0; i < countOfEmployees; i++)
    {
        cin >> name >> position >> salary;
        employee[i].name = name;
        employee[i].position = position;
        employee[i].salary = salary;
    }

    string neededPosition;
    cin >> neededPosition;
    for (size_t i = 0; i < countOfEmployees; i++)
    {
        if (employee[i].position == neededPosition) {
            cout << "Name: " << employee[i].name << "`Position: " << employee[i].position << " Salary: " << employee[i].salary << endl;
        }
    }

}

