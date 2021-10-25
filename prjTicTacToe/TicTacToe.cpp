/************************************************************
	Module Name: TicTacToe.h
	Author: Robert Milan 
	Date: 10/25/2021

	Description:
				Class implementation of TicTacToe.
*************************************************************/
#include "TicTacToe.h"
#include <iostream>

using namespace std;

/************************************************************
	Function name: TicTacToe()
	Description: constructor for the class.
*************************************************************/
TicTacToe::TicTacToe()
{
	clearBoard();
}

/************************************************************
	Function name: clearBoard()
	Description: Function to clear the game board and reset
		it back to its default position.

*************************************************************/
void TicTacToe::clearBoard()
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			m_Board[y][x] = '*';
		}
	}
}

/************************************************************
	Function name: getYCord
	Description: Retreives input of Y-coordinate the user
		would like to attempt to place a piece at.

*************************************************************/
int TicTacToe::getYCord()
{
	int y = 0;

	while (y < 1 || y > 3)
	{
		cout << "Enter the 'Y' coordinate [1-3]: ";
		cin >> y;

		if (y < 1 || y > 3)
		{
			cout << "Bad input, please keep your 'Y' coordinate between 1 - 3!\n\n";
		}
	}

	cout << endl;

	return y - 1;
}

/************************************************************
	Function name: getXCord
	Description: Retreives input of X-coordinate the user
		would like to attempt to place a piece at.

*************************************************************/
int TicTacToe::getXCord()
{
	int x = 0;

	while (x < 1 || x > 3)
	{
		cout << "Enter the 'X' coordinate [1-3]: ";
		cin >> x;

		if (x < 1 || x > 3)
		{
			cout << "Bad input, please keep your 'X' coordinate between 1 - 3!\n\n";
		}
	}

	cout << endl;

	return x - 1;
}

/************************************************************
	Function name: placeMarker 

	Arguments: 
					y - y-coordinate of the game grid.
					x - x-coordinate of the game grid.
					playerPiece - character player wants to use.

	Description:
						Will search the game board for the character
						the user inputted to place on the board.

						The placement must have a '*' and not be
						occupied by another players piece.

*************************************************************/
bool TicTacToe::placeMarker(int y, int x, char playerPiece)
{
	// Check the coordinates y/x to see if it's occupied.
	if (m_Board[y][x] != '*')
		return false;

	// The piece isn't occupied so set the y/x coordinates to the chosen character.
	m_Board[y][x] = playerPiece;
	return true;
}

/************************************************************
	Function name: showBoard
	Description: Loops through the game boards coordinates
		and displays them 1 by 1 until a 3 x 3 game board
		is displayed for the end user/'s.

*************************************************************/
void TicTacToe::showBoard()
{
	// Iterate through all the y's and x's, and display them to the screen.
	//    to create a tic/tac/toe board.
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << '[' << m_Board[y][x] << ']';
		}

		cout << endl;
	}
}

/************************************************************
	Function name: checkForWinner
	Description: Iterate through the 2d array and see if
		any of the rows match.

*************************************************************/
bool TicTacToe::checkForWinner()
{
	//      1  2  3  x
	//   1 [0][1][2] |
	//   2 [0][1][2] |
	//   3 [0][1][2] |
	//   y ----------

	// check each row, 1 by 1
	for (int y = 0; y < 3; y++)
	{
		// this means we have a winner, if 1/1 = 1/2 and 1/2 = 1/3 we have a winner.
		//    and so forth.
		if ((m_Board[y][0] != '*') && (m_Board[y][0] == m_Board[y][1] && m_Board[y][1] == m_Board[y][2]))
		{
			return true; // winner
		}
	}

	// check each column, 1 by 1
	for (int x = 0; x < 3; x++)
	{
		// this means we have a winner, if 1/1 = 1/2 and 1/2 = 1/3 we have a winner.
		//    and so forth.
		if ((m_Board[0][x] != '*') && (m_Board[0][x] == m_Board[1][x] && m_Board[1][x] == m_Board[2][x]))
		{
			return true; // winner
		}
	}


	// check top left diagnol
	if (m_Board[0][0] != '*' && (m_Board[0][0] == m_Board[1][1]) && (m_Board[1][1] == m_Board[2][2]))
	{
		return true; // we have a winner
	}

	// check top right diagnol
	if (m_Board[2][0] != '*' && (m_Board[0][2] == m_Board[1][1]) && (m_Board[1][1] == m_Board[2][0]))
	{
		return true; // we have a winner
	}

	return false; // no winner identified
}