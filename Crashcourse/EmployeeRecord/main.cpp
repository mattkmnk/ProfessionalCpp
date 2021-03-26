#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main() {
    Database DB;
    bool done = false;

    while(!done) {
        int selection = displayMenu();
        switch(selection) {
            case 1:
                doHire(DB);
                break;
            case 2:
                doFire(DB);
                break;
            case 3:
                doPromote(DB);
                break;
            case 4:
                doDemote(DB);
                break;
            case 5:
                DB.displayAll();
                break;
            case 6:
                DB.displayCurrent();
                break;
            case 7:
                DB.displayFormer();
                break;
            case 0:
                done = true;
                break;
            default:
                std::cerr << "Unknown command.\n";
                break;
        }
    }
}

int displayMenu(){
    int selection;
    std::cout << '\n';
    std::cout << "Employee Database\n";
    std::cout << "-----------------\n";
    std::cout << "1) Hire a new employee\n";
    std::cout << "2) Fire an employee\n";
    std::cout << "3) Promote an employee\n";
    std::cout << "4) Demote an employee\n";
    std::cout << "5) List all employees\n";
    std::cout << "6) List all current employees\n";
    std::cout << "7) List all former employees\n";
    std::cout << "0) Quit\n\n";
    std::cout << "---> ";
    std::cin >> selection;
    return selection;
}

void doHire(Database& db) {
    std::cout << "Adding an employee.\n";
    std::cout << "Enter first and last name: ";
    std::string fName, lName;
    std::cin >> fName >> lName;
    try {
        db.addEmployee(fName, lName);
    } catch (const std::exception& exception) {
        std::cerr << "Unable to add new employee: " << exception.what() << '\n';
    }
}

void doFire(Database& db) {
    std::cout << "Enter employee number: ";
    int eNumber;
    std::cin >> eNumber;
    try {
        Employee& emp = db.getEmployee(eNumber);
        emp.fire();
        std::cout << "Employee " << eNumber << " terminated.\n";
    } catch (const std::exception& exception) {
        std::cerr << "Unable to terminate employee: " << exception.what() << '\n';
    }
}

void doPromote(Database& db) {
    int eNumber;
    int raiseAmount;
    std::cout << "Employee number: ";
    std::cin >> eNumber;
    std::cout << "How much of a raise: ";
    std::cin >> raiseAmount;

    Employee& emp = db.getEmployee(eNumber);
    emp.promote(raiseAmount);
}

void doDemote(Database& db) {
    int eNumber;
    int reductionAmount;
    std::cout << "Employee number: ";
    std::cin >> eNumber;
    std::cout << "How much of a reduction: ";
    std::cin >> reductionAmount;

    Employee& emp = db.getEmployee(eNumber);
    emp.demote(reductionAmount);
}