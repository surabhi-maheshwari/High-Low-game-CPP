#include<iostream>
#include<stdlib.h>
#include <random>
#include<ctime>
using namespace std;
/*
This program plays a simple game.The computer picks a random number
from
0 to 100, and the user tries to guess the number.
*/
const int totchan = 7;
void main()
{
	int number;        //the computer's random number
	int guess;         //the user's guess
	int chances = 0, score = 0, chanscor;        //chanscor stores score for 1 successful chance.
		char ans;
	do
	{
		chances = score = 0;
		cout << "Welcome to the High / Low game."<<endl;
		cout << "I will pick a random number from 0 to 100."<<endl;
		cout << "You must try to guess the number in 7 chances."<<endl;
		srand(time(NULL));
		number = (int)(rand() % 100);
		chanscor = 100 / totchan;        //score for each successful chance
		do
		{
			cout << "What is your guess ? (0 to 100) "<<endl;
			cin >> guess;
			if ((guess<0) || (guess>100))
			{
				cout << "Sorry, but your guess " << guess << "must be from 0 to 100."<<endl;
			}
			else if (guess < number)
			{
				cout << guess << " is low.Try a higher number."<<endl;
			}
			else if (guess > number)
			{
				cout << guess << " is high.Try a lower number."<<endl;
			}
			else		//if correct number is guessed
			{			//number is correct, and the "do" loop will end below
				cout << guess << " is correct. Congratulations!"<<endl;
				score = chanscor * (totchan - chances);   //score calculated for number of chances left
					cout << "Your score is "<<score<< "\n";
					break;
			}
			chances++;
			if (guess != number)
				cout << "Now you have "<<totchan-chances<<"chances left."<<"\n";
				if (chances == totchan)
				{
					cout << "Only "<<totchan<<"chances are allowed.Better luck next	time";
						cout << "The actual number was "<<number<<"\n";
						break;
				}
		} while (guess != number);
		cout << "Thank you for playing High / Low!"<<endl;
		cout << "Want to play it again? (y/n)..."<<endl;
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
}