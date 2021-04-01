#include <iostream>
#include "Super.h"

int main() {

    Super mySuper;
    mySuper.someMethod();
    Sub mySub;
    mySub.someMethod();
    mySub.someOtherMethod();
    return 0;
}