/* 

A calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.

*/


#include <iostream>

int main() {
    char operations;
    float number1, number2;

    std::cout << "Enter the first number: ";
    std::cin >> number1;

    std::cout << "Enter the second number: ";
    std::cin >> number2;

    std::cout << "Enter the operations (+, -, *, /): ";
    std::cin >> operations;

    switch(operations) {
        case '+':
            std::cout << "Result: " << number1 << " + " << number2 << " = " << number1 + number2;
            break;
        case '-':
            std::cout << "Result: " << number1 << " - " << number2 << " = " << number1 - number2;
            break;
        case '*':
            std::cout << "Result: " << number1 << " * " << number2 << " = " << number1 * number2;
            break;
        case '/':
            if (number2 != 0)
                std::cout << "Result: " << number1 << " / " << number2 << " = " << number1 / number2;
            else
                std::cout << "Error! Division by zero is not allowed.";
            break;
        default:
            std::cout << "Invalid operations!";
    }

    return 0;
}
