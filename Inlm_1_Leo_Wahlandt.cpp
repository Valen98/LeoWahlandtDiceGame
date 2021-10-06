#include <iostream>
#include <ctime>
#include <regex>

using namespace std;

int main()
{
	//Declaring as many variables in the start to improve readability
	int balance;
	int bet{};
	int bestHumanDice;
	int bestComputerDice;
	int humanGameScore{};
	int computerGameScore{};
	int totalWinnings = 0;
	char addYesNo;
	char rematch;
	bool wish2Continue = true;
	bool diceGame = true;
	bool invalidInput = false;
	bool closeGame = true;
	//Betting loop is how much you want to insert in a loop. If you dont have enough money and dont want to insert more it quits.
	bool betting = true;

	srand(time(NULL));

	cout << "Welcome To Valen's Dice game!" << endl;

	while (betting) {
		cout << "Type in your wishing Balance. (Max 5000): "; cin >> balance;

		//This wish2Continue is set to true if the player want to play again but dont have enough money and have to insert more.
		wish2Continue = true;

		if (balance < 0 || balance > 5001) {
			cout << "Invalid amount";
			wish2Continue = false;

		}

		while (wish2Continue) {
			//The user can only bet 100, 300 or 500 kr. Therefore there's 3 options only.
			cout << "How much do you want to bet?" << endl << "1. 100 kr" << endl << "2. 300 kr" << endl << "3. 500 kr?" << endl; cin >> bet;

			//diceGame is true just because if you insert wrong input u will not go into an infinite loop
			diceGame = true;

			// This if checks how much the bet will be and if  the user has enough balance. 
			if (bet == 1 && balance >= 100) {
				bet = 100;
				balance -= bet;
				cout << "You bet " << bet << " kr " << endl;
			}
			else if (bet == 2 && balance >= 300) {
				bet = 300;
				balance -= bet;
				cout << "You bet " << bet << " kr " << endl;
			}
			else if (bet == 3 && balance >= 500) {
				bet = 500;
				balance -= bet;
				cout << "You bet " << bet << " kr " << endl;
			}
			else {
				cout << "Invalid option or not enough balance" << endl;
				bet = 0;
				diceGame = false;
				invalidInput = true;
			}

			//The score is reset before the game start if the player has already played the game
			int score = 0;
			int computerScore = 0;


			while (diceGame) {

				// Rest of 6 
				int humanDice1 = 1 + (rand() % 6);
				int humanDice2 = 1 + (rand() % 6);

				cout << "--------------You rolls the dices-----------------" << endl;

				cout << "This is both dices for human: " << humanDice1 << " & " << humanDice2 << endl;

				if (humanDice1 > humanDice2) {

					//The first dice is the better one
					bestHumanDice = humanDice1;
					cout << "Your best dice is: " << bestHumanDice << endl << endl;

				}
				else if (humanDice1 < humanDice2) {
					//The second dice is the better one
					bestHumanDice = humanDice2;
					cout << "Your best dice is:  " << bestHumanDice << endl << endl;
				}
				else {
					//Both dices are the same so therefore we send in the first dice
					bestHumanDice = humanDice1;
					cout << "Both dices are the same" << bestHumanDice << endl << endl;
				}

				cout << "--------------Computer rolls the dices-----------------" << endl;

				int computerDice1 = 1 + (rand() % 6);
				int computerDice2 = 1 + (rand() % 6);

				cout << "The Computer rolled: " << computerDice1 << " & " << computerDice2 << endl;


				//All comment is on Human Dice
				if (computerDice1 > computerDice2) {
					bestComputerDice = computerDice1;
					cout << "Best dice is number one " << bestComputerDice << endl << endl;
				}
				else if (computerDice2 > computerDice1) {
					bestComputerDice = computerDice2;
					cout << "Best dice is number two " << bestComputerDice << endl << endl;
				}
				else {
					bestComputerDice = computerDice1;
					cout << "Both dices are the same " << bestComputerDice << endl << endl;
				}

				cout << "--------------The battle-----------------" << endl;

				cout << "The Human dice is: " << bestHumanDice << " Vs Computer dice is: " << bestComputerDice << endl ;

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
				cout << "The score is now for human: " << score << " The computer score: " << computerScore << endl << endl;

				//If the user wins 2 rounds the balance will add 2x the bet. If the user loses the user loses the bet,
				if (score == 2) {
					balance += bet * 2;
					totalWinnings += bet;
					cout << "Nice you won! Your new balance is: " << balance << endl;
					humanGameScore++;
					break;
				}
				else if (computerScore == 2) {
					totalWinnings -= bet;
					cout << "Oh no! You lost! Your new balance is: " << balance << endl;
					computerGameScore++;
					break;

				}
			}


			if (!invalidInput) {
				cout << "-----------------------------------" << endl;

				cout << "The game score is now: Your score: " << humanGameScore << " and computer score: " << computerGameScore << endl;

				//If i put totalwinnings here it will add/remove the bet and even if i say totalwinnings +=/-= bet it will give it x2 because i put balance += (bet * 2)
				cout << "The total winnings right now is: " << totalWinnings << endl;
				cout << "Your current balance is: " << balance << endl;

				cout << "Do you wanna play again (Y)?" << endl; cin >> rematch;

				if (rematch == 'Y' || rematch == 'y') {
					wish2Continue = true;
				}
				else {
					cout << "This is your earnings for today: " << totalWinnings << " Kr " << endl;
					betting = false;
					break;
				}

			}


			//IF the player want to play again but has less the lowest bet, the user will be questioned to add more to balance
			if (balance < 100) {
				cout << "Your balance is: " << balance << "\nYou don't have enough money to play again.\nDo you wanna add money? Yes(Y) or No(N)" << endl;
				cin >> addYesNo;

				if (addYesNo == 'Y' || addYesNo == 'y') {
					//This takes the player out of the game loop back to betting loop. So he/she can insert more money into the game.
					wish2Continue = false;
				}
				else {
					betting = false;
					wish2Continue = false;
				}

			}

		}
	}
}
