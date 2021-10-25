/************************************************************
	Module Name: TicTacToe.h
	Author: Robert Milan
	Date: 10/25/2021

	Description:
		Header file for the TicTacToe class. It contains the
			on declerations for the functions used in the
			class file.


*************************************************************/

#pragma once

#include <iostream>

class TicTacToe
{
	public:
		TicTacToe();
		
		void clearBoard();
		int getYCord();
		int getXCord();
		bool placeMarker(int y, int x, char playerPiece);
		void showBoard();
		bool checkForWinner();

	private:
		char m_Board[3][3];
};

