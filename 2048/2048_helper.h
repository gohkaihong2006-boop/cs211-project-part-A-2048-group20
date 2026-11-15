#include <iostream>
#include <random>
#include <iomanip>

using namespace std;
int currentnum=0;
int pastnum=0;
int gained = 0;

int move_left(int board[][5], int numrows = 5)
{
	int changed = 0;
	gained = 0;
	for (int r = 0; r < numrows; r++) {

		int merged = -1;
		for (int c = 0; c < 5; c++) {

			if (board[r][c] != 0) {

				int previous = c;

				// Move the tile as far left as possible
				while (previous > 0 && board[r][previous - 1] == 0) {
					board[r][previous - 1] = board[r][previous];
					board[r][previous] = 0;
					previous--;
					changed = 1;
				}

				// Combine with the previous tile if equal and it hasn't merged yet
				if (previous > 0 && board[r][previous - 1] == board[r][previous] && merged != previous - 1) {
					board[r][previous - 1] *= 2;
					board[r][previous] = 0;
					gained += board[r][previous - 1];
					merged = previous - 1;
					changed = 1;
				}
			}
		}
	}
	return changed;
}

int move_right(int board[][5], int numrows = 5)
{
	int changed = 0;
	gained = 0;
	for (int r = 0; r < numrows; r++) {

		int merged = -1;
		for (int c = 4; c >= 0; c--) {

			if (board[r][c] != 0) {

				int next = c;

				// Move the tile as far right as possible
				while (next < 4 && board[r][next + 1] == 0) {
					board[r][next + 1] = board[r][next];
					board[r][next] = 0;
					next++;
					changed = 1;
				}

				// Combine with the next tile if equal and it hasn't merged yet
				if (next < 4 && board[r][next + 1] == board[r][next] && merged != next + 1) {
					board[r][next + 1] *= 2;
					board[r][next] = 0;
					gained += board[r][next + 1];
					merged = next + 1;
					changed = 1;
				}
			}
		}
	}
	return changed;
}

int move_up(int board[][5], int numrows = 5)
{
	int changed = 0;
	gained = 0;
	for (int c = 0; c < 5; c++)
	{
		int merged = -1;
		for (int r = 1; r < numrows; r++)
		{
			if (board[r][c] != 0)
			{
				int upnum = r;

				// Move the tile as far up as possible
				while (upnum > 0 && board[upnum - 1][c] == 0)
				{
					board[upnum - 1][c] = board[upnum][c];
					board[upnum][c] = 0;
					upnum--;
					changed = 1;
				}

				// Combine with the tile above if equal and it hasn't merged yet
				if (upnum > 0 && board[upnum - 1][c] == board[upnum][c] && merged != upnum - 1)
				{
					board[upnum - 1][c] *= 2;
					board[upnum][c] = 0;
					gained += board[upnum - 1][c];
					merged = upnum - 1;
					changed = 1;
				}
			}
		}
	}
	return changed;
}

int move_down(int board[][5], int numrows = 5)
{
	int changed = 0;
	gained = 0;
	for (int c = 0; c < 5; c++)
	{
		int merged = -1;
		for (int r = numrows - 1; r >= 0; r--)
		{
			if (board[r][c] != 0)
			{
				int downnum = r;

				// Move the tile as far down as possible
				while (downnum < numrows - 1 && board[downnum + 1][c] == 0)
				{
					board[downnum + 1][c] = board[downnum][c];
					board[downnum][c] = 0;
					downnum++;
					changed = 1;
				}

				// Combine with the tile below if equal and it hasn't merged yet
				if (downnum < numrows - 1 && board[downnum + 1][c] == board[downnum][c] && merged != downnum + 1)
				{
					board[downnum + 1][c] *= 2;
					board[downnum][c] = 0;
					gained += board[downnum + 1][c];
					merged = downnum + 1;
					changed = 1;
				}
			}
		}
	}
	return changed;
}

void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}
//Game Saving

bool saveGame(const int board[5][5], int score, int movecount, const char* filename) {
	std::ofstream outFile(filename);
	if (!outFile) {
		return false;
		// File failed
	}

	// Write the score on the first line
	outFile << score << "\n";
	//Saves the Moves
	outFile << movecount << "\n";

	// Write the 2D array row by row
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			outFile << board[i][j] << " ";
		}
		outFile << "\n";
	}

	outFile.close();
	return true;
}
//Game Loading
bool loadGame(int board[5][5], int& score, int& movecount, const char* filename) {
	std::ifstream inFile(filename);
	if (!inFile) {
		return false; // Save file does not exist or cannot be opened
	}

	// Read the score first
	if (!(inFile >> score)) {
		cout<<"Error Loading File"<<endl;
		return false; // Corrupted file
	}
	if (!(inFile >> movecount)) {
		cout<<"Error Loading File"<<endl;
		return false; // Corrupted file
	}

	//Loads Saved Game
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (!(inFile >> board[i][j])) {
				cout<<"Error Loading File"<<endl;
				return false;
			}
		}
	}

	inFile.close();
	return true;
}