#include <iostream>
#include <fstream>
#include "2048_helper.h"
#include <conio.h>
using namespace std;
const std::string saveFile = "saved_game(2048).txt";
int has2048(int board[][5], int size)
{
	for(int r =0; r < size; r++)
	{
		for(int c =0; c < 5; c++)
		{
			if(board[r][c] == 2048)
			{
				return 1;
			}
		}
	}
	return 0;
}

int canmove(int board[][5], int size)
{
	for(int r = 0; r < size; r++)
	{
		for(int c =0; c < 5;c++)
		{
			if(board[r][c] == 0)
			{
				return 1;
			}
			if(c < 4 && board[r][c] == board[r][c + 1])
			{
				return 1;
			}
			if(r < size - 1 && board[r][c] == board[r + 1][c])
			{
				return 1;
			}
		}
	}
	return 0;
}


int main()
{
	//Adding a difficulty slider might be a bit more of a pain than initially thought.
	//Will try to add at later date
	int size = 5;
	int board[5][5] = {
		{0, 4, 2, 4, 0},
		{0, 0, 0, 0, 0},
		{2, 0, 2, 0, 2},
		{0, 0, 2, 0, 0},
		{2, 2, 2, 2, 2},
	};

	int score = 0;
	int movecount = 0;
	int win = 0;
	int gameover =0;
	//while getch == x loop for up down left right

	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);
bool exit=false;
char choice = 'w';		//initialized
	while (exit != true)
	{
		cout << "Score: " << score << " Move: " << movecount << endl;
		cout << "Please enter choice:{W,S,A,D,E,H,N} for UP, DOWN, LEFT, RIGHT, Exit, Help, Game Options: " << endl;
		cout << "Choice: "<<endl;
		cin>>choice;

		
		if (choice == 'w' || choice == 's' || choice == 'a' || choice == 'd')
		{
			if (gameover == 1)
			{
				cout << "Game over. Use n (new game), h (help) or e (exit)." << endl;
			}
			else
			{
				int moved = 0;
				if (choice == 'w')
					moved = move_up(board, size);
				else if (choice == 's')
					moved = move_down(board, size);
				else if (choice == 'a')
					moved = move_left(board, size);
				else
					moved = move_right(board, size);

				if (moved == 1)
				{
					score += gained;
					movecount++;
					insert_random(board, size);
					print_board(board);

					if (has2048(board, size) == 1 && win == 0)
					{
						cout << "You win!" << endl;
						win = 1;
					}
					if (canmove(board, size) == 0)
					{
						cout << "Game over! No moves left. Final Score: " << score << endl;
						gameover = 1;
					}
				}
				else
				{
					cout << "The move changes nothing." << endl;
				}
			}
		}
		else if(choice =='h')
		{
			cout << "Commands: " << endl;
			cout << "  W / S / A / D : slide up, down, left, right" << endl;
			cout << "  n : new/save/load game" << endl;
			cout << "  h : show this help" << endl;
			cout << "  O / L : Save game, Load game" << endl;
			cout << "  e : exit" << endl;

		}
		else if(choice == 'n')
		{
			char answer;
			cout << "Start a new game? Enter 'y' for yes or 'n' for no: "<<endl<<
				"Save Game 'o'"<<endl<<"Load Game 'l'"<<endl;
			cin >> answer;
			if(answer == 'y')
			{
				for(int r = 0; r < size; r++)
				{
					for(int c = 0; c < 5; c++)
					{
						board[r][c] = 0;
					}
				}
				score = 0;
				movecount = 0;
				win =0;
				gameover = 0;
				insert_random(board, size);
				insert_random(board, size);
				print_board(board);
			}
			else if (answer =='o') {
//saves the board then reprints the current board
				if (saveGame(board, score, "savegame.txt")) {
					cout << "Saving Game"<<endl;
				}
				print_board(board);
			}
			else if (answer == 'l') {
				//erases board
				score = 0;
				int board[5][5] = {0};
				if (loadGame(board, score, "savegame.txt")) {
					std::cout << "Game loaded! Score: " << score << "\n";
				}

//prints new board
				print_board(board);
			}
			else if (answer == 'n') {
				cout << "New game canceled." << endl;
				print_board(board);
			}
		}
		else if (choice=='e') {
			exit=true;
		}
		else if(choice != 'e')
		{
			cout << "Invalid Comment." << endl;
		}
	}
	return 0;
}
