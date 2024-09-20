
#include <iostream>
#include <cmath>
using namespace std;



int main()
{
	cout << "Welcome to the game of Nim!" << std::endl;
	cout << "You and the computer will take turns removing marbles from a pile." << "\n";
	cout << "On each turn, you can take 1 to half of the marbles in the pile." << "\n";
	cout << "The player forced to take the last marble loses." << "\n\n";
	cout << "Best of 3 wins" << "\n\n\n";

	int humanWins = 0, compWins = 0, Gamestotal = 0;
	while (Gamestotal!=3) {
		srand(time(0));   //set the random seed

		//welcome to the game, how to play, rules
		
		std::cout << "\n\nScore: " << humanWins << " - " << compWins << "\n";
		//Determine the random number of marbles in the bowl: 10 to 100
		int numMarbles = rand() % 91 + 10;
		//Determine who goes first: Comp or Player
		int turn = rand() % 2;
		//Determine whether or not the Comp is Smart or Dumb.
		bool smart = rand() % 2;

		int legalaction = numMarbles / 2;
		int PlayerTakes;
		int dumbmove = rand() % legalaction + 1;

		

		/* How to check for smart or dump computer.
		 * smart equals 1 means computer is smart.
		 * smart equals 0 means computer is dumb.
		*/
		if (smart) {
			std::cout << "The computer is smart" << "\n";
		}
		//Notify Player that Comp is smart.
		else {
			std::cout << "The computer is dumb" << "\n";
		}
		//Notify Player that Comp is Dumb.


	//Make a move: Comp or Player, depending on who goes first
	//This portion of the code requires loops.
	//Play until there is 1 marble left.
		int choice;
		int oneLessThanAPowerOf2;

		while (numMarbles > 1) {
			std::cout << "there are " << numMarbles << " Left\n\n";
			int legalaction = numMarbles / 2;

			if (turn == 1) {
				//Player goes first; how many marbles does the Player choose?
				//Make sure their move is not more than half the total number of marbles left.
					bool canTake = false;

					while (!canTake) {
						std::cout << "how many marbles would you like to take?" << "\n";
						std::cin >> PlayerTakes;


						if (PlayerTakes > legalaction || PlayerTakes < 1) {

							std::cout << "This is not a legal action, reinput your action: " << "\n";
							std::cout << "\n";

						}
						else {
							numMarbles -= PlayerTakes;
							canTake = true;
							turn = 0;
						}

					}



				
			}
			else {
				cout << "computers turn" << std::endl;
				//Comp goes first; how many marbles does the Comp choose?
				//Make sure its move is not more than half the total number of marbles left.
				//Also, make the appropriate move regarding smart or dumb.
				if (smart) {
					oneLessThanAPowerOf2 = pow(2, int(log2(numMarbles))) - 1;
					if (numMarbles == oneLessThanAPowerOf2) {
						choice = rand() % legalaction + 1;
						if (choice > legalaction) {
							choice = legalaction;
						}
					}
					else {
						choice = numMarbles - oneLessThanAPowerOf2;
					}
				}
				else {
					choice = rand() % legalaction + 1;
					
				}


				if (choice > legalaction) {
					choice = legalaction;
				}
				std::cout << "computer takes " << choice << "\n\n";
				
				numMarbles -= choice;
				turn = 1;




			}

		}

		//Check to see who won
		if (turn == 1 && PlayerTakes <= legalaction && numMarbles ==1) {
			std::cout << "The remaining number of marbles is 1, you are forced to take it you lose" << std::endl;
			compWins++;
			Gamestotal++;
		}
		else if (numMarbles == 1 && turn == 0 && PlayerTakes <= legalaction) {
			std::cout << "The remaining # of marbles is 1, the computer is forced to take it computer loses.";
			humanWins++;
			Gamestotal++;
		}
		//Display a message at the end of the game
		else {
			"\n\n";
		}


	}
	std::cout << humanWins << "  -  " << compWins;

	if (humanWins > compWins) {
		std::cout << "\nHuman wins!!!";
	}
	else {
		std::cout << "\nYou lost to a robot :(";
	}
	return 0;
}
