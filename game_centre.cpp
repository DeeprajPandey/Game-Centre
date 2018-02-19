/**
 * main.cpp
 *
 * Deepraj Pandey
 * deepraj11pop@gmail.com
 *
 * Asks for user's choice to play
 * either of the 2 games,
 * Casino Number or High/Low,
 * and runs the code for the chosen game.
 */
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// casino_num functions
void casino_num();
void drawLine(int n, char symbol);
void rules();

// high_low functions
void high_low();
int welcome_text();
void game_body(int &, int &, int &, int &, int &, int &);
char end_recursive();
const int totchan = 7;

int main(void)
{
    int ch;
    drawLine(80,'_');
    cout << "\n\n\n\t\t\t    WELCOME TO GAMEZONE\n\n\n\n";
    drawLine(80,'_');

    cout << "Enter the number corresponding to the game you want to play." << endl;
    cout << "1. Casino Number" << "\n2. High/Low" << "\n3. Exit\n";
    cin >> ch;
    switch(ch)
    {
        case 1: casino_num();
                break;
        case 2: high_low();
                break;
        case 3: exit(0);
        default: cout << "Not among listed options. Try again.\n";
    }

    return 0;
}
/*
 * Casino Number
 *
 * Asks user to guess a number from 1 to 10.
 * Before that, user has input a betting amount.
 * If guessed correctly, user gets 10 times the betting value.
 * If not, betting value is deducted from balance.
 */
void casino_num()
{
    system("cls");
    string playerName;

    // hold player's balance amount
    int amount;
    long long bettingAmount;
    int guess;

    // hold computer generated number
    int dice;
    char choice;

    // seeds the random generator
    srand(time(NULL));
    drawLine(80,'_');
    cout << "\n\n\n\t\t\t\t  CASINO GAME\n\n\n\n";
    drawLine(80,'_');
    int xy;
    cout << "\n\nEnter your name:";
    getline(cin, playerName);

    cout << "\n\nEnter initial deposit to play game: $";
    cin >> amount;

    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $" << amount << "\n";

		// get player's betting amount
        do
        {
            cout <<playerName<<", enter amount you wish to bet: $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
            {
                cout << "Your betting amount is more than your current balance\n"
                     <<"\nRe-enter data\n ";
            }
        }while(bettingAmount > amount);

		// get player's guess
        do
        {
            cout << "Guess a number between 1 to 10 to bet on: ";
            cin >> guess;
            if(guess <= 0 || guess > 10)
            {
                cout << "Please check the number! It should be from 1 to 10\n"
                     <<"\nRe-enter data\n ";
            }
        }while(guess <= 0 || guess > 10);

        // hold randomly generated integer from 1 to 10
        dice = rand()%10 + 1;

        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won $" << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $"<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }

        cout << "\nThe winning number was " << dice <<"\n";
        cout << endl << playerName <<", You have $" << amount << endl;
        if(amount == 0)
        {
            cout << "Bummer! You have no money to keep playing.";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)?" << endl;
        cin >> choice;
    }while(choice =='Y'|| choice=='y');

    cout << endl << endl << endl;
    drawLine(80,'=');
    cout << "\n\nYour final balance is $" << amount << "\n";
    cout << "Thanks for playing. :)" << "\n";
    cout << "\n\n\t\t\tGame by Deepraj Pandey"
         << "\n\t\t\t\t2016\n\n\n\n";
    drawLine(80,'=');
}

// draws a line of given character
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; ++i)
        cout << symbol;
    cout << "\n" ;
}

// prints rules of casino_num
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\t\t\tRULES OF THE GAME\n\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number from 1 to 10.\n";
    cout << "\t2. If you win you will get 10 times the money you betted with\n";
    cout << "\t3. If you bet on a wrong number you will lose your betting amount.\n\n";
    drawLine(80,'-');
}

/*
 * High/Low
 *
 * Asks user to guess a number in 7 takes within a range specified by user.
 * After every entry, states whether
 * guessed value is high or low in reference to actual value.
 */
void high_low()
{
    system("cls");
    // the computer's random number
    int number;
    // the user's range
    int ran;
    // chanscore stores score for 1 successful chance
    int guess, chanscore;
    int chances = 0, score = 0;
    char ans;

    do
    {
        // every time game restarts, screen is cleared
        system("cls");
        chances = score = 0;
        ran = welcome_text();

        // seeded with system time
        srand(time(NULL));


        number = (int)(rand()%ran);

        // score for each successful chance
        chanscore = ran/totchan;
        game_body(ran, guess, number, chances, score, chanscore);

        ans = end_recursive();
    }
    while(ans == 'y' || ans == 'Y');

    if (ans != 'y' || ans != 'Y')
    {
        cout << endl << endl << endl;
        drawLine(80,'=');
        cout << "Thanks for playing. :)" << "\n";
        cout << "\n\n\t\t\tGame by Deepraj Pandey"
             << "\n\t\t\t\t2016\n\n\n\n";
        drawLine(80,'=');
    }
}

// text and range input
int welcome_text()
{
    int n;
        system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\t\t   Welcome to the High/Low game\n\n";
    drawLine(80,'-');
    cout << "\t\t\t\t\tRULES\n\n";
    drawLine(80,'-');
    cout << "\tThe computer will pick a random number within a range specified by you.\n";
    cout << "\tYou must try to guess the number in 7 chances. Good luck!\n";
    drawLine(80,'-');

    cout << "\n\nEnter the upper limit of the range, i.e. the range will be from 0 to __ ";
    cin >> n;

    return n;
}

// 7 user inputs for the game
void game_body(int &ran, int &guess, int &number, int &chances, int &score, int &chanscore)
{
    do
        {
            cout << "What is your guess? (0 to " << ran << ")" << endl;
            cin >> guess;

            if ((guess < 0)||(guess > ran))
            {
                cout << "Sorry, but your guess " << guess << " must be from 0 to " << ran << "." << endl;
            }
            else if (guess < number)
            {
                cout << guess << " is low. Try a higher number." << endl;
            }
            else if (guess > number)
            {
                cout << guess << " is high. Try a lower number." << endl;
            }
            else
            {
                // if correct number is guessed the "do" loop will end below
                cout << guess << " is correct. Congratulations!" << endl;

                // score calculated based on number of chances left
                score = chanscore*(totchan-chances);
                cout << "Your score is " << score << endl;
                break;
            }
            chances++;
            if (guess != number)
            {
                cout << "Now you have " << totchan-chances << " chances left." << endl;
            }
            if (chances == totchan)
            {
                cout << endl << "Only " << totchan << " chances are allowed. Better luck next time. ";
                cout << "The actual number was " << number << endl;
                break;
            }
        }
        while (guess != number);
}

// user choice on game replay
char end_recursive()
{
    char rep;
    cout << "Thank you for playing High/Low!" << endl;
    cout << "Want to play again? (y/n)..." << endl;
    cin >> rep;

    return rep;
}
