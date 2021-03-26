#include <iostream>
#include "Employee.h"

using namespace std;

namespace Records {
    Employee::Employee()
        : mFirstName("")
        , mLastName("")
        , mEmployeeNumber(-1)
        , mSalary(kDefaultStartingSalary)
        , mHired(false)
        {}

    void Employee::promote(int RaiseAmount) {
        setSalary(getSalary() + RaiseAmount);
    }

    void Employee::demote(int demeritAmount) {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() {
        mHired = true;
    }

    void Employee::fire() {
        mHired = false;
    }

    void Employee::display() const {
        cout << "Employee: " << getLastName() << ", " << getFirstName() << '\n';
        cout << "----------------------\n";
        cout << (mHired ? "Current Employee" : "Former Employee") << '\n';
        cout << "Employee Number: " << getEmployeeNumber() << '\n';
        cout << "Salary: $" << getSalary() << "\n\n";
    }

    void Employee::setFirstName(const std::string& fname) {
        mFirstName = fname;
    }

    const std::string& Employee::getFirstName() const {
        return mFirstName;
    }

    void Employee::setLastName(const std::string& lname) {
        mLastName = lname;
    }

    const std::string& Employee::getLastName() const {
        return mLastName;
    }

    void Employee::setEmployeeNumber(int employeeNumber) {
        mEmployeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const {
        return mEmployeeNumber;
    }

    void Employee::setSalary(int newSalary) {
        mSalary = newSalary;
    }

    int Employee::getSalary() const {
        return mSalary;
    }

    bool Employee::isHired() const {
        return mHired;
    }
}