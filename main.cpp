#include <iostream>
#include <string>
using namespace std;
#include "EmployeeList.h"
#include <fstream>


void addNewEmployees(EmployeeList&);
void modifyEmployeeData(EmployeeList&);
void deleteEmployees(EmployeeList&);
void displayEmployeeData(EmployeeList&);
void printOutput(EmployeeList&);

int main()
{
    int choice;
    EmployeeList employeeList;
    cout<<"Create the Employee Database"<<endl;
    addNewEmployees(employeeList);
    cout << "The employee database has been created." << endl;
    do {
        cout << "******************************************************************************" << endl;
        cout << "**                                   Menu                                   **" << endl;
        cout << "** 1. Add new employees to the database.                                    **" << endl;
        cout << "** 2. Modify employees data in the data base.                               **" << endl;
        cout << "** 3. Delete employees from the database.                                   **" << endl;
        cout << "** 4. Display employee data to the screen.                                  **" << endl;
        cout << "** 5. Quit the system                                                       **" << endl;
        cout << "******************************************************************************" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                addNewEmployees(employeeList);
                break;
            case 2:
                modifyEmployeeData(employeeList);
                break;
            case 3:
                deleteEmployees(employeeList);
                break;
            case 4:
                displayEmployeeData(employeeList);
                break;
            case 5:
                cout << "Thanks for using XXXX Company Payroll System! All employee information can be viewed in the file 'employees.dat'" << endl;
                printOutput(employeeList);
                break;
            default:
                cout << "Invalid option selected!"<<endl;
                break;
        }
    } while (choice != 5);
    return 0;
}

void addNewEmployees(EmployeeList& employeeList)
{
    int id;
    string fname, lname;
    float rate, hour;
    char response;
    do {
        cout << "Enter an employee's data by the order of ID number, first name, last name, rate, hours:" << endl;
        cin >> id >> fname >> lname >> rate >> hour;
        while ((id < 0) || (rate < 0) || (hour < 0)) {
            cout << "You must enter a non negative value. Try again!"<<endl;
            cin >> id >> rate >> hour;
        }
        Employee employee(id, fname, lname, rate, hour);
        employeeList.addEmployee(employee);
        cout << "Another employee? y/n -->" ;
        cin >> response;
    } while(response != 'n');
}

void modifyEmployeeData(EmployeeList& employeeList)
{
    char response;
    do {
        int id;
        cout << "Enter Employees current id: " << endl;
        cin >> id;
        int index = employeeList.searchEmployee(id);
        if (index >= 0) {
            cout << "This employee has following data: "<< endl;
            cout << employeeList.getEmployee(index);
            employeeList.modifyEmployeeData(index);
        } else {
            cout << "No such employee in the database." << endl;
        }
        cout << "Modify another employee? y/n -->";
        cin >> response;
    } while (response != 'n');
    cout << "The employees data have been updated." << endl;
}

void deleteEmployees(EmployeeList& employeeList)
{
    char response;
    do {
        int id;
        string fname, lname;
        float rate, hour;
        cout << "Enter the employee's data to delete by the order of id, first Name, last Name, rate, hours:" << endl;
        cin>>id>>fname>>lname>>rate>>hour;
        Employee employee(id, fname, lname, rate, hour);
        if (employeeList.deleteEmployee(employee)) {
            cout << "This employee's data is deleted." << endl;
        } else {
            cout << "No such employee." <<endl;
        }
        cout << "Another employee to delete? y/n -->";
        cin >> response;
    } while (response != 'n');
}

void displayEmployeeData(EmployeeList& employeeList)
{
    cout << "XXX Company Payroll System: " << endl;
    cout << "ID\tFirstName\tLastName\tRate\tHours\tWage" << endl;
    for (int i = 0; i < employeeList.getNumberOfEmployees(); i++) {
        cout << employeeList.getEmployee(i) << endl;
    }
}

void printOutput(EmployeeList& employeeList)
{
    ofstream fout("employees.dat");
    fout << "ID\tFirstName\tLastName\tRate\tHours\tWage" << endl;
    for (int i = 0; i < employeeList.getNumberOfEmployees(); i++) {
        fout << employeeList.getEmployee(i) << endl;
    }
    fout.close();
}