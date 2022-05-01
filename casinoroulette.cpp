#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rules();
int main()
{
    string name;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========WELCOME TO THE CASINO ROULETTE=======\n\n";
    cout << "\n\nPlayer, Enter your name : ";
    getline(cin, name);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do
    {
        system("reset");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
// Get player's betting balance
        do
        {
            cout << "Hey, " << name<<", enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"<<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
// Get player's numbers
        do
        {
            cout << "Guess any betting number between 1 & 36 :";
            cin >> guess;
            if(guess <= 0 || guess > 36)
                cout << "\nNumber should be between 1 to 36\n"<<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 36);
        dice = rand()%36 + 1;
        if(dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<name<<", You have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("reset");
    cout << "\t\t======CASINO ROULETTE RULES!======\n";
    cout << "\t1. Choose a number between 1 to 36\n";
    cout << "\t2. Winner gets 10 times of the betting amount\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
