#include <iostream>
#include "Super.h"

Super::Super(){}

void Super::someMethod() {
    std::cout << "Super class\n";
}

Sub::Sub(){}

void Sub::someMethod() {
    std::cout << "Sub class override\n";
}

void Sub::someOtherMethod() {
    std::cout << "Sub class\n";
}