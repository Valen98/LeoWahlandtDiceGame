// Inlm_1_Leo_Wahlandt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int balance;
	int bet{};
	int bet;

	//
	bool wish2Continue = true;
	bool diceGame = true;
	int bestHumanDice;
	int bestComputerDice;
	int humanGameScore{};
	int computerGameScore{};

	//Betting loop is how much you want to insert in a loop. If you dont have enough money and dont want to insert more it quits.
	bool Betting = true;

	srand(time(NULL));

	cout << "Welcome To Valen's Dice game!" << endl;

	while (Betting) {
		cout << "Type in your wishing Balance. (Max 5000): "; cin >> balance;

		wish2Continue = true;


		if (balance > 5001 || balance < 0) {
			cout << "Invalid amount";
			wish2Continue = false;

		}

		char removeWhile;

		while (wish2Continue) {
			//The user can only bet 100, 300 or 500 kr. Therefore there's 3 options only.
			cout << "How much do you want to bet?" << endl << "1. 100 kr" << endl << "2. 300 kr" << endl << "3. 500 kr?" << endl; cin >> bet;

			//diceGame is true just because if you insert wrong input u will not go into an infinite loop
			diceGame = true;

			// This if checks how much the bet will be and if  the user has enough balance. 
			if (bet == 1 && balance >= 100) {
				bet = 100;
				balance -= bet;
				cout << "You bet " << bet << endl;
			}
			else if (bet == 2 && balance >= 300) {
				bet = 300;
				balance -= bet;
				cout << "You bet " << bet << endl;
			}
			else if (bet == 3 && balance >= 500) {
				bet = 500;
				balance -= bet;
				cout << "You bet " << bet << endl;
			}
			else {
				cout << "Invalid option or not enough balance" << endl;
				bet = 0;
				diceGame = false;
			}

			int score = 0;
			int computerScore = 0;


			while (diceGame) {

				// Rest of 6 
				int humanDice1 = 1 + (rand() % 6);
				int humanDice2 = 1 + (rand() % 6);

				cout << "This is both dices for human: " << endl << humanDice1 << endl << humanDice2 << endl;

				if (humanDice1 > humanDice2) {

					//The first dice is the better one
					bestHumanDice = humanDice1;
					cout << "Best dice is number one" << bestHumanDice << endl;

				}
				else if (humanDice1 < humanDice2) {
					//The second dice is the better one
					bestHumanDice = humanDice2;
					cout << "Best dice is number two" << bestHumanDice << endl;
				}
				else {
					//Both dices are the same so therefore we send in the first dice
					bestHumanDice = humanDice1;
					cout << "Both dices are the same" << bestHumanDice << endl;
				}

				int computerDice1 = 1 + (rand() % 6);
				int computerDice2 = 1 + (rand() % 6);

				cout << "This is both dices for Computer: " << endl << computerDice1 << endl << computerDice2 << endl;


				//All comment is on Human Dice
				if (computerDice1 > computerDice2) {
					bestComputerDice = computerDice1;
					cout << "Best dice is number one " << bestComputerDice << endl;
				}
				else if (computerDice2 > computerDice1) {
					bestComputerDice = computerDice2;
					cout << "Best dice is number two " << bestComputerDice << endl;
				}
				else {
					bestComputerDice = computerDice1;
					cout << "Both dices are the same " << bestComputerDice << endl;
				}


				//Checks who win with their best dices
				if (bestHumanDice > bestComputerDice) {
					score++;
				}
				else if (bestHumanDice == bestComputerDice) {
					cout << "its A draw, roll them again. " << endl;
				}
				else {
					computerScore++;
				}
				cout << "The score is now for human: " << score << "The computer score: " << computerScore << endl;

				//If the user win 2 rounds the balance will add 2x the bet. If the user loses the user loses the bet,
				if (score == 2) {
					balance += (bet * 2);
					cout << "Nice you won! Your new balance is: " << balance << endl;
					humanGameScore++;
					diceGame = false;
				}
				else if (computerScore == 2) {
					cout << "You lost! Your new balance is: " << balance << endl;
					computerGameScore++;
					diceGame = false;

				}
			}
			char addYesNo;

			char rematch;

			cout << "-----------------------------------" << endl;

			cout << "The game score is now: Your score: " << humanGameScore << " and computer score: " << computerGameScore << endl;

			cout << "Do you wanna play again (Y)?" << endl; cin >> rematch;

			if (rematch == 'Y' || rematch == 'y') {
				wish2Continue = true;
			}
			else {
				wish2Continue = false;
				Betting = false;
			}



			if (balance < 100) {
				cout << balance << "You don't have enough money to play again. \n Do you wanna add money? Yes(Y) or No(N)" << endl;
				cin >> addYesNo;

				if (addYesNo == 'Y' || addYesNo == 'y') {
					wish2Continue = false;

					if (balance > 5001 || balance < 0) {
						cout << "Invalid amount";
						cout << "Type in your wishing Balance again. (Max 5000): "; cin >> balance;
					}
				}
				else {
					wish2Continue = false;
					Betting = false;
				}

			}


			//cout << endl << "Type in R if wanna close";
			//cin >> removeWhile;

			//if (removeWhile == 'R') {
			//	wish2Continue = false;
			//}
		}
	}
}
