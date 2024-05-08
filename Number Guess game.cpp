/* 

A program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.

*/


#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main() 
{
int total_attempts = 0;
int guessbyuser;
    srand(time(nullptr)); 
    int secretNumber = rand() % 100 + 1;
 cout << "Welcome to the Number Guessing Game By CodSoft Intern Aditya ! \n";
    cout << "The System Has selected a number between 1 and 100. Can you guess it?\n";

do {
        cout << "Enter the number guessed by you : ";
        cin >> guessbyuser;
        total_attempts++;

        if (guessbyuser == secretNumber) {
            cout << "Congratulations! You guessed the correct number in " << total_attempts << " total attempts.\n";
            break;
        } else if (guessbyuser < secretNumber - 10) {
            cout << "Way too low ! Try again.\n";
        } else if (guessbyuser < secretNumber) {
            cout << "A little low ! Try again. \n";
        } else if (guessbyuser > secretNumber + 10) {
            cout << "Way too high! Try again.\n";
        } else {
            cout << "A little high! Try again. \n";
        }
    } while (true);

    return 0;
}























    