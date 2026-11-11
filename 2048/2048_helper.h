#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
int currentnum=0;
int pastnum=0;
void dif(int difficulty) {
	//If we plan to add in difficulty
	cout<<"Please select your difficulty:"<<endl<<
	"1- EASY"<<endl<<
	"2- NORMAL"<<endl<<
	"3- HARD"<<endl;
	while(difficulty<1 || difficulty>3){
		cin>>difficulty;
	}
	//SETS SIZE DEPENDING ON THE DIFFICULTY
	if (difficulty==1){
		difficulty=2;
	}
	else if(difficulty==2){
		difficulty=5;
	}
	else{
		difficulty=20;
	}

}

void move_left(int board[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++) {

    for (int c = 0; c < 5; c++) {

        if (board[r][c] != 0) {

            int previous = c;

            // Move the tile as far right as possible
            while (previous > 0 && board[r][previous - 1] == 0) {
                board[r][previous - 1] = board[r][previous];
                board[r][previous] = 0;
                previous--;
            }

            
            if (previous > 0 && board[r][previous - 1] == board[r][previous]) {

                board[r][previous - 1] *= 2;
                board[r][previous] = 0;
            }
        }
    }
}
}

void move_right(int board[][5], int numrows = 5)
{
	//WORKS PUT HAS AN ISSUE WHERE IT WRAPS DOWN
	for (int r = 0; r < numrows; r++) {

    for (int c = 4; c >= 0; c--) {

        if (board[r][c] != 0) {

            int next = c;

            // Move the tile as far right as possible
            while (next < 4 && board[r][next + 1] == 0) {
                board[r][next + 1] = board[r][next];
                board[r][next] = 0;
                next++;
            }

            // Combine with the next tile if equal
            if (next < 4 &&board[r][next + 1] == board[r][next]) {

                board[r][next + 1] *= 2;
                board[r][next] = 0;
            }
        }
    }
}
}

void move_up(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_down(int board[][5], int numrows = 5)
{

	//CODE HERE
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

