#include "Employee.h"

#define MAX_EMPLOYEE_LIMIT 50

class EmployeeList
{
private:
    Employee employees[MAX_EMPLOYEE_LIMIT];
    int numberOfEmployees;

public:
    EmployeeList() {
        numberOfEmployees = 0;
    }

    bool addEmployee(Employee employee) {
        if ((searchEmployee(employee.getId()) >=  0) || numberOfEmployees >= MAX_EMPLOYEE_LIMIT)
            return false;
        else {
            employees[numberOfEmployees] = employee;
            numberOfEmployees++;
            return true;
        }

    }

    bool deleteEmployee(Employee employee) {
        int index = searchEmployee(employee.getId());
        if (index != -1) {
            for (int i = index; i < numberOfEmployees; i++) {
                employees[i] = employees[i+1];
            }
            numberOfEmployees--;
            return true;
        }
        return false;
    }

    int searchEmployee(int id) {
        for (int i = 0; i < numberOfEmployees; i++) {
            if (employees[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }

    bool modifyEmployeeData(int index) {
        int id;
        string fname, lname;
        float rate, hours;
        char answer;

        cout << "Change id? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new ID: " ;
            cin >> id;
            employees[index].setId(id);
        }

        cout << "Change first name? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new first name: " ;
            cin >> fname;
            employees[index].setFirstName(fname);
        }

        cout << "Change last name? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new last name: " ;
            cin >> lname;
            employees[index].setLastName(lname);
        }

        cout << "Change rate? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new rate: " ;
            cin >> rate;
            employees[index].setRate(rate);
        }

        cout << "Change hours worked? y/n -->" ;
        cin >> answer;
        if(answer == 'y'){
            cout << "Enter new hours: " ;
            cin >> hours;
            employees[index].setHours(hours);
        }
        return true;
    }

    int getNumberOfEmployees(){
        return numberOfEmployees;
    }

    Employee getEmployee(int index){
        return employees[index];
    }
};