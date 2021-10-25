/************************************************************
	Module Name: main.cpp
	Author: Robert Milan
	Date: 10/25/2021

	Description:
		
		Main program.

*************************************************************/

#include <iostream>
#include <string>

#include "TicTacToe.h";

using namespace std;


/************************************************************
	Function name: main()
	Description: This is the main program. It will contain
		a loop to run the game until the user decides they
		don't want to play anymore.

*************************************************************/
int main()
{
	TicTacToe ttt = TicTacToe();

	int nCurrentPlayer = 0;
	string szPlayer_1;
	string szPlayer_2;

	// Date I created this game.
	static const string szCreationDate = "10/25/2021";


	// Welcome message
	cout << "*****************************************************************\n" << 
		     "* Welcome to TicTacToe (written by Robert Milan on (" << szCreationDate << ") *\n" <<
	        "*****************************************************************\n" << endl;


	// Ask the 1st user to enter their name
	cout << "Please enter a name for player 1: ";
	cin >> szPlayer_1;

	// Ask the 2nd user to enter their name
	cout << "\nPlease enter a name for player 2: ";
	cin >> szPlayer_2;


	// Infinite loop (the loop goes forever and doesn't stop unless you stop it)
	// Once the users choose who goes first, we put an end to the loop.
	for (;;)
	{
		cout << endl << "Would you like player [1] or  player [2] to go first?: ";
		cin >> nCurrentPlayer;

		if (nCurrentPlayer == 1 || nCurrentPlayer == 2)
		{
			break;
		}
		else 
		{               
			cout << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << 
				             "!!! Invalid input, please select a 1 or 2 !!!\n" <<
				             "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
		}
	}

	cout << endl;


	// Our game loop, used to determine if they want to keep playing or end the game.
	bool isPlaying = true;
	bool isWinner = false;
	while (isPlaying == true)
	{
		// display the board in it's current state
		ttt.showBoard();
		cout << endl;

		// get the Y and X coordinates where the player wants to put their game piece
		int nYCord = ttt.getYCord();
		int nXCord = ttt.getXCord();

		// Set player 1 to Xs and player 2 to Os
		char cPlayerPiece = NULL;
		if (nCurrentPlayer == 1)
		{
			cPlayerPiece = 'X';
		}
		else 
		{ 
			cPlayerPiece = 'O'; 
		}

		// Attempt to place the X or O in the spot a player species.
		if (ttt.placeMarker(nYCord, nXCord, cPlayerPiece) == true)
		{
			// check to see if there's a winner
			isWinner = ttt.checkForWinner();

			// Change turns if there isn't a winner yet.
			if (isWinner == false)
			{
				if (nCurrentPlayer == 1)
				{
					nCurrentPlayer++;
				}
				else
				{
					nCurrentPlayer--;
				}
			}
		}
		else
		{
			cout << "\nThere is already a player piece at location: [" <<
				(nYCord + 1) << "/" << (nXCord + 1) << "]\nPlease select a new location.\n\n";
		}


		// we have a winner
		if (isWinner == true)
		{
			string szTemp = "";
			if (nCurrentPlayer == 1)
			{
				szTemp = szPlayer_1;
			}
			else
			{
				szTemp = szPlayer_2;
			}
			
			// Congradulate the winner.
			char cYesNo = NULL;
			cout << "We have a winner! Congratulations " << szTemp << "!";
			cout << "\n<Would you like to play again? [Y or N]): ";
			cin >> cYesNo;

			if ((cYesNo =='Y') || (cYesNo == 'y'))
			{
				// Continue playing, and clear the board!
				isPlaying = true;
				ttt.clearBoard();


				// alternate to the other players turn
				if (nCurrentPlayer == 1)
				{
					nCurrentPlayer++;
				}
				else
				{
					nCurrentPlayer--;
				}

				// create some space
				cout << endl << endl << endl << endl;
			}
			else
			{
				isPlaying = false;
				break;
			}
		}

		// we're done playing, end the program
		// maybe ask if they want to play again or quit.
		//isPlaying = false;
	}

	//cout << endl << endl;
	//system("PAUSE");
	return 0;
}