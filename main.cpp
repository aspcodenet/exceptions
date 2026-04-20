#include <iostream>

/*
Exceptions
----------------
what?
how?
Own exceptions (throw)
when only option (constructors, destructors)

what for? overuse?
Lets see "Golang"-style

minus: performance
plus: performance (collecting all errors in one place, not having to check for errors after every function call)



*/

int divide(int a, int b) {
    return a / b;
}


void test(){
    int x = 10;
    int y = 0;


    int result = divide(x, y);
    std::cout << "Hello, World!" << result << std::endl;
}



int main() {
    int x = 10;
    int y = 0;

    std::cout << "Running!" << std::endl;

    test();
    std::cout << "Ending" << std::endl;
    return 0;
}



