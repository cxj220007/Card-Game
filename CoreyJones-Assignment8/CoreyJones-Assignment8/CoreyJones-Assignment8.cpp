// CoreyJones-Assignment8.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

const int cRow = 10;
const int cCol = 1;
int row, col;

string theCase(int V) 
{
	string thing;

	switch (V)
	{
		case 1:
			thing = " A";
			break;

		case 2:
			thing = " 2";
			break;

		case 3:
			thing = " 3";
			break;

		case 4:
			thing = " 4";
			break;

		case 5:
			thing = " 5";
			break;

		case 6:
			thing = " 6";
			break;

		case 7:
			thing = " 7";
			break;

		case 8:
			thing = " 8";
			break;

		case 9:
			thing = " 9";
			break;

		case 10:
			thing = "10";
			break;

		case 11:
			thing = " J";
			break;

		case 12:
			thing = " Q";
			break;
		
		case 13:
			thing = " K";
			break;
	}

	return thing;
}

void drawSpades(string N)
{
	string Spades[cRow] = {
		"    .    " ,
		"   ...   " ,
		"  .....  " ,
		" ....... " ,
		"........." ,
		"........." ,
		"   ...   " ,
		"    .    " ,
		"   ...   " ,
		"  .....  " ,
	};

	//Draw Spades Card
	cout << setw(10) << left << setfill(static_cast<char>(196)) << static_cast<char>(218) << static_cast<char>(191) << endl;
	cout << static_cast<char>(179) << N << "       " << static_cast<char>(179) << endl;
	for (row = 0; row < cRow; row++)
		cout << static_cast<char>(179) << Spades[row] << static_cast<char>(179) << endl;
	cout << setw(10) << left << static_cast<char>(192) << static_cast<char>(217) << endl;

}

void drawClubs(string N)
{
	string Clubs[cRow] = 
	{
		"    .    " ,
		"   ...   " ,
		"    .    " ,
		" .. . .. " ,
		"........." ,
		" .. . .. " ,
		"    .    " ,
		"    .    " ,
		"    .    " ,
		"  .....  "
	};


	//Draw Clubs Card
	cout << setw(10) << left << setfill(static_cast<char>(196)) << static_cast<char>(218) << static_cast<char>(191) << endl;
	cout << static_cast<char>(179) << N << "        " << static_cast<char>(179) << endl;
	for (row = 0; row < cRow; row++)
		cout << static_cast<char>(179) << Clubs[row] << static_cast<char>(179) << endl;
	cout << setw(10) << left << static_cast<char>(192) << static_cast<char>(217) << endl;

}

void drawHearts(string N)
{
	string Hearts[cRow] = 
	{
		"         " ,
		"         " ,
		" ..   .. " ,
		".... ...." ,
		"........." ,
		" ....... " ,
		"  .....  " ,
		"   ...   " ,
		"    .    " ,
		"         "
	};


	//Draw Hearts Card
	cout << setw(10) << left << setfill(static_cast<char>(196)) << static_cast<char>(218) << static_cast<char>(191) << endl;
	cout << static_cast<char>(179) << N << "        " << static_cast<char>(179) << endl;
	for (row = 0; row < cRow; row++)
		cout << static_cast<char>(179) << Hearts[row] << static_cast<char>(179) << endl;
	cout << setw(10) << left << static_cast<char>(192) << static_cast<char>(217) << endl;
}

void drawDiamonds(string N)
{
	string Diamonds[cRow] = 
	{
		"    .    " ,
		"   ...   " ,
		"  .....  " ,
		" ....... " ,
		"........." ,
		"........." ,
		" ....... " ,
		"  .....  " ,
		"   ...   " ,
		"    .    "
	};

	
	//Draw Diamonds Card
	cout << setw(10) << left << setfill(static_cast<char>(196)) << static_cast<char>(218) << static_cast<char>(191) << endl;
	cout << static_cast<char>(179) << N << "        " << static_cast<char>(179) << endl;
	for (row = 0; row < cRow; row++)
		cout << static_cast<char>(179) << Diamonds[row] << static_cast<char>(179) << endl;
	cout << setw(10) << left << static_cast<char>(192) << static_cast<char>(217) << endl;
}

int main()
{
	srand(time(0));//Random number generator seed at launch
	int SecretFace = (rand() % 13) + 1;//Number gen after plant seed
	int SecretSuit = (rand() % 4) + 1;//Number gen after plant seed
	int PlayerGuessFace;
	int PlayerGuessSuit;
	char DisplayFace;
	bool flag = false;



	//Player Guess Mechanic
	cout << "Pick a card! Any card! Guess my card, and you win! Use the numbers provided to choose: " << endl;
	while (flag != true)
	{
		cout << left << setw(15) << "\nSuits 1-4:" << setw(15) << "1: Spades" << setw(15) << "2: Clubs" << setw(15) << "3: Hearts" << setw(15) << "4: Diamonds" << endl;
		cin >> PlayerGuessSuit;
		cout << left << setw(90) << "Pick a card: 1 for Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 for Jack, 12 for Queen, 13 for King" << endl;
		cin >> PlayerGuessFace; 


		if (PlayerGuessSuit == SecretSuit)
		{
			cout << "\nYou got the suit value!" << endl;
			
			if (PlayerGuessFace == SecretFace)
			{
				cout << "\nYou got the face value!" << endl << endl;
				if (SecretSuit == 1)
					drawSpades(theCase(PlayerGuessFace));
				else if (SecretSuit == 2)
					drawSpades(theCase(PlayerGuessFace));
				else if (SecretSuit == 3)
					drawSpades(theCase(PlayerGuessFace));
				else if (SecretSuit == 4)
					drawSpades(theCase(PlayerGuessFace));
				cout << "\n\nYou win!" << endl;
				flag = true;
			}

			else if (PlayerGuessFace < SecretFace)
				cout << "\nYour face guess was too low. Try again." << endl;

			else if (PlayerGuessFace > SecretFace)
				cout << "\nYour face guess was too high. Try again." << endl;
		}


		else if (PlayerGuessSuit < SecretSuit)
		{
			cout << "\nYour suit guess was too low. Try again." << endl;
			if (PlayerGuessFace == SecretFace)
				cout << "\nYou got the face value!" << endl;
			else if (PlayerGuessFace < SecretFace)
				cout << "\nYour face guess was too low. Try again." << endl;
			else if (PlayerGuessFace > SecretFace)
				cout << "\nYour face guess was too high. Try again." << endl;
		}


		else if (PlayerGuessSuit > SecretSuit)
		{
			cout << "\nYour suit guess was too high. Try again." << endl;
			if (PlayerGuessFace == SecretFace)
				cout << "You got the face value!" << endl;
			else if (PlayerGuessFace < SecretFace)
				cout << "\nYour face guess was too low. Try again." << endl;
			else if (PlayerGuessFace > SecretFace)
				cout << "\nYour face guess was too high. Try again." << endl;
		}
	}
	
	cout << "\n\nPress any key to close program";
	_getch();
	return 0;
}

