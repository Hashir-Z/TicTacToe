#include <iostream>
#include <conio.h>
#include "windows.h"
#include <cstring>
#include <time.h>

//FUNCTION DECLERATION

void findBestMove();
int Who_Goes_First();
int MakeBoard();
int Get_User_Move();
int Get_Bot_Move(int depth, bool isMax);
int evaluate(bool caller);
bool isMovesLeft(bool caller);
void GameOver(char winner);
void SDTG();
void NLines();
void Loading();
void Color();
void BColor();
void UBorder();
void BBorder();
void ShowConsoleCursor(bool showFlag);
using namespace std;

//GLOBAL VARIABLE
int row = 0, col = 0;
int counter = 0;
int run = 0;
int stime = 15;
char arr[3][3] = { {'1','2','3'},{'4','5','6'}, {'7','8','9'} };
char character = '\0';
char ans = '\0';
char botchar = '\0';

void main()
{
	ShowConsoleCursor(false); //Disable the Cursor
	srand(time(NULL));
	int i = 0;

	Sleep(5000);

	//MAKE THE LOADING SCREEN
	{
		for (i = 0; i < 87; i++)
		{
			UBorder(); // Upper Border
			NLines(); // New Lines
			cout << "\t\t\t\t\tLoading" << endl;
			Loading(); // Progress Bar
			BBorder(); // Bottom Border
			if (i % 3 == 0)//Change Color Every 3rd Iteration
			{
				Color();
			}
			Sleep(80);
			system("CLS");
		}
		system("CLS");
	}

	//MAKE THE GAME LOADED SCREEN
	{
		UBorder(); //Upper Border
		NLines(); // New Lines
		cout << "\t\t\t\t\tGame Loaded!\n\t\t\t\t Press any key to continue";
		BBorder(); // Bottom Border
	}
	

	//CHANGE THE BACKGROUND COLOR
	{
		for (i = 0; i < 3; i++)
		{
			Sleep(800);
			BColor();
		}
	}

	system("CLS");
	system("color 60"); // CHANGE BACKGROUND COLOR TO YELLOW
	SDTG();
	
	//LOAD THE GAME BOARD
	{
		MakeBoard();
	}
	system("pause");
}

//FUNCTIONS

int MakeBoard()
{
	int i = 0, j = 0, left = 0, k = 0, n = 0;
	char v = 179, h = 196; // LOADING CHARACTERS
	char winner = '\0';
	bool caller = 0;
	
	// LOOP TO DRAW BOARD
	{
		for (i = 1; i <= 17; i++)
		{
			// DRAW HORIZONTAL LINES
			{
				if (i == 6) // DRAW FIRST HORIZONTAL LINE
				{
					cout << "\t";
					for (int j = 0; j < 50; j++)
					{
						Sleep(stime);
						cout << h;
					}
					cout << endl;
					continue;
				}
				if (i == 12) // DRAW SECOND HORIZONTAL LINE
				{
					cout << "\t";
					for (int j = 0; j < 50; j++)
					{
						Sleep(stime);
						cout << h;
					}
					cout << endl;
					continue;
				}
			}
			Sleep(stime);
			// ENTER ROW NUMBERS + DRAW VERTICAL LINES
			{
				if (i == 3) // FIRST ROW
				{
					cout << "\t\t" << arr[0][0] << "\t" << v << "\t" << arr[0][1] << "\t" << v << "\t" << arr[0][2];
					cout << endl;
				}
				else if (i == 9) // SECOND ROW
				{
					cout << "\t\t" << arr[1][0] << "\t" << v << "\t" << arr[1][1] << "\t" << v << "\t" << arr[1][2];
					cout << endl;
				}
				else if (i == 15) // THIRD TOW
				{
					cout << "\t\t" << arr[2][0] << "\t" << v << "\t" << arr[2][1] << "\t" << v << "\t" << arr[2][2];
					cout << endl;
				}
				else //DRAWS VERTICAL LINEs
				{
					cout << "\t\t\t" << v << "\t\t" << v;
					cout << endl;
				}
			}
		}
	}
	
	stime = 1;
	
	// CHECK IF ANYONE HAS WON
	{
		if (evaluate(caller) == 1)
			return(0);
	}
	
	// CHECK IF BOARD HAS BEEN COMPLETELY FILLED
	{
		if (isMovesLeft(caller) == 1)
			return (0);
	}

	// IF FIRST RUN, PLAYER CHOOSES HIS CHARACTER
	{
		if (run == 0)
		{
			cout << "\n\nEnter Your Character: ";
			cin >> character;
			if (!(((character >= 65) && character <= 90) || (character >= 97 && character <= 122)))
			{
				cout << "Character Can Only Be Alphabet!";
				_getch();
				system("CLS");
				SDTG();
				MakeBoard();
				return (0);
			}
			//TO CLEAR THE SCREEN AND DRAW BOARD AGAIN
			system("CLS");
			run = 1;
			SDTG();
			MakeBoard();
			return (0);
		}
	}

	// IF SECOND RUN, ASK PLAYER IF HE WOULD LIKE TO GO FIRST
	{
		if (run == 1)
		{
			Who_Goes_First();
			return (0);
		}
	}

	// IF THIRD RUN, CHECK TO SEE IF ITS PLAYERS TURN OR BOTS TURN
	{
		if (run == 2 && (ans == 'Y' || ans == 'y'))
		{
			Get_User_Move();
			return(0);
		}
		else if (run == 2 && (ans == 'n' || ans == 'N'))
		{
			findBestMove();
			return(0);
		}
	}

	// IF > THIRD RUN, CALL FUNCTION AGAIN
	{
		if (run >= 3 && run % 2 != 0)
		{
			Get_User_Move();
			return(0);
		}
		else if (run >= 3)
		{
			findBestMove();
			return(0);
		}
	}

}

bool isMovesLeft(bool caller)
{
	int i = 0, j = 0, left = 0;
	// LOOP TO CHECK IF BOARD HAS BEEN COMPLETELY FILLED
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (((arr[i][j] >= 'A') && (arr[i][j] <= 'Z')) || ((arr[i][j] >= 'a') && (arr[i][j] <= 'z')))
			{
				left++;
			}
		}
	}
	if (left == 9)
	{
		if (caller == 0)
		{
			GameOver(0);
			return(1);
		}
		else
		{
			return(false);
		}
	}
}

int evaluate(bool caller)
{
	// LOOP TO CHECK IF ANYONE HAS WON
	int i = 0;
	char winner = '\0';
		// HORIZONTAL & VERTICAL CHECK
	for (i = 0; i < 3; i++)
	{
		// VERTICAL CHECK
		if (((arr[i][0] == arr[i][1]) && (arr[i][0] == arr[i][2])))
		{
			winner = arr[i][0];
			if (caller == 0)
			{
				GameOver(winner);
				return(1);
			}
			else
			{
				if (winner == character)
				{
					return(-10);
				}
				else
				{
					return(10);
				}
			}
		}
		// HORIZONTAL CHECK
		else if (((arr[0][i] == arr[1][i]) && (arr[0][i] == arr[2][i])))
		{
			winner = arr[0][i];
			if (caller == 0)
			{
				GameOver(winner);
				return(1);
			}
			else
			{
				if (winner == character)
				{
					return(-10);
				}
				else
				{
					return(10);
				}
			}
		}
	}

	// DIAGONAL CHECK
	if ((((arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2])) || ((arr[0][2] == arr[1][1]) && (arr[0][2] == arr[2][0]))))
	{
		winner = arr[1][1];
		if (caller == 0)
		{
			GameOver(winner);
			return(1);
		}
		else
		{
			if (winner == character)
			{
				return(-10);
			}
			else
			{
				return(10);
			}
		}
	}
	return(0);
}

int Who_Goes_First()
{
	cout << "\n\nWould You Like To Go First: ";
	cin >> ans;
	switch (ans)
	{
	case 'y': case 'Y':
	{
		run = 3;
		system("CLS");
		SDTG();
		MakeBoard();
		return(0);
		break;
	}
	case 'n': case 'N':
	{
		run = 2;
		system("CLS");
		SDTG();
		MakeBoard();
		return(0);
		break;
	}
	default:
	{
		cout << "Invalid Input. Please enter Y for Yes and N for No." << endl;
		_getch();
		system("CLS");
		SDTG();
		MakeBoard();
		Who_Goes_First();
		return(0);
		break;
	}
	}
}

int Get_User_Move()
{
	int num = 0, i = 0, j = 0;
	cout << "\n\nEnter The Number Where You'd Like To Place Your Character: ";
	cin.clear(); // If user enters a character value, it might cause the variable num to become corrupted.
	cin.ignore(); //  We use these two functions to clear any garbage stored in the variables.
	cin >> num;
	if (!(num > 0 && num < 10))
	{
		cout << "Please Enter A Valid Location!";
		_getch();
		system("CLS");
		SDTG();
		MakeBoard();
		return(0);

	}
	//CHECKS WHERE TO PUT USER CHARACTER AND ENSURES LOCATION NOT ALREADY TAKEN!
	{
		if (num <= 3)
		{
			if (arr[0][num - 1] != character && arr[0][num - 1] != botchar)
			{
				arr[0][num - 1] = character;
			}
			else
			{
				cout << "Location Alread Taken!";
				Sleep(1000);
				_getch();
				system("CLS");
				SDTG();
				MakeBoard();
				return(0);
			}
		}
		else if (num <= 6)
		{
			if (arr[1][num - 4] != character && arr[1][num - 4] != botchar)
			{
				arr[1][num - 4] = character;
			}
			else
			{
				cout << "Location Alread Taken!";
				Sleep(1000);
				_getch();
				system("CLS");
				SDTG();
				MakeBoard();
				return(0);
			}
		}
		else if (num <= 9)
		{
			if (arr[2][num - 7] != character && arr[2][num - 7] != botchar)
			{
				arr[2][num - 7] = character;
			}
			else
			{
				cout << "Location Alread Taken!";
				Sleep(1000);
				_getch();
				system("CLS");
				SDTG();
				MakeBoard();
				return(0);
			}
		}
	}
	if (run == 2)
	{
		run = 3;
	}
	else
	{
		run++;
	}
	system("CLS");
	SDTG();
	MakeBoard();
	return(0);
}

void findBestMove()
{
	botchar = 'X';
	//CHANGE BOTS CHARACTER IF SAME AS PLAYER CHARACTER
	if (botchar == character || character == 'x')
	{
		botchar = 'Y';
	}
	system("color 40"); // CHANGE COLOR
	cout << "\n\n\t\t     Calculating, Please Wait...";
	int bestVal = -1000, i = 0;
	bool caller = 1;
	row = -1;
	col = -1;
	char temp = '\0';
	stime = 0;
	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal 
	// value. 
	for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// Check if cell is empty 
			if (arr[i][j] >= '1' && arr[i][j] <= '9')
			{
				temp = arr[i][j];

				// Make the move 
				arr[i][j] = botchar;

				// compute evaluation function for this 
				// move. 
				//int moveVal = Get_Bot_Move(0, true);
				int moveVal = Get_Bot_Move(0, 0);

				// Undo the move 
				arr[i][j] = temp;

				// If the value of the current move is 
				// more than the best value, then update 
				// best
				if (moveVal > bestVal)
				{
					row = i;
					col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	arr[row][col] = botchar;
	run++;
	Sleep((rand() % (500 - 100 - 1) + 100));
	system("CLS");
	system("color 60");
	SDTG();
	MakeBoard();
}

int Get_Bot_Move(int depth, bool isMax)
{
	bool caller = 1;
	int score = evaluate(caller);
	char temp = '\0';

	// If Bot has won the game return his/her 
	// evaluated score 
	if (score == 10)
		return score;

	// If Human has won the game return his/her 
	// evaluated score 
	if (score == -10)
		return score;

	// If there are no more moves and no winner then 
	// it is a tie 
	if (isMovesLeft(caller) == false)
	{
		return 0;
	}
	int best = -1000;
	// If it's Bots move 
	if (isMax)
	{
		best = -1000;
		// Traverse all cells 
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty 
				if (arr[i][j] >= '1' && arr[i][j] <= '9')
				{
					temp = arr[i][j];

					// Make the move 
					arr[i][j] = botchar;

					// Call minimax recursively and choose 
					// the maximum value 
					best = max(best, Get_Bot_Move(depth + 1, !isMax));

					// Undo the move 
					arr[i][j] = temp;
				}
			}
		}
		return best;
	}

	// If it's Humans move 
	else
	{
		best = 1000;

		// Traverse all cells 
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty 
				if (arr[i][j] >= '1' && arr[i][j] <= '9')
				{
					temp = arr[i][j];
					// Make the move 
					arr[i][j] = character;

					// Call minimax recursively and choose 
					// the minimum value 
					best = min(best, Get_Bot_Move(depth + 1, !isMax));

					// Undo the move 
					arr[i][j] = temp;
				}
			}
		}
		return best;
	}

	//SIMPLE CODE THAT PUTS BOTS CHARACTER ANYWHERE WITHOUT TRYING TO WIN
/*{ 
	int i = 0, j = 0, k = 0;
	cout << "\n\n\t\t     Calculating, Please Wait...";
	botchar = 'X';
	//CHANGE BOTS CHARACTER IF SAME AS PLAYER CHARACTER
	if (botchar == character || character == 'x')
	{
		botchar = 'Y';
	}

	Sleep(rand()%(1000-500+1)+500);
	run++;

	//CHECK IF RANDOM NUMBER BOX IS ALREADY TAKEN

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j < 3; j = j + 2)
		{
			for (k = 2; k >= 0; k = k - 2)
			{
				// IF VERTICALLY FILLED
				if (((arr[j][i] == character) && (arr[1][i] == character)) && ((arr[k][i] != botchar) && (arr[k][i] != character)))
				{
					arr[k][i] = botchar;
				}
				// IF HORIZONTALLY FILLED
				else if (((arr[i][j] == character) && (arr[i][1] == character)) && ((arr[i][k] != botchar) && (arr[i][k] != character)))
				{
					arr[i][k] = botchar;
				}
				// IF DIAGONALLY FILLED
				else if (((arr[j][0] == character) && (arr[i][1] == character)) && ((arr[i][k] != botchar) && (arr[i][k] != character)))
				{

				}
			}
		}
	}
	*/
}

void GameOver(char winner)
{
	int count = 49;
	char uchoice = '\0';
	if (winner == character)
	{
		cout << "\n\n\t\t\t     You Win!\n";
	}
	else if (winner == botchar)
	{
		cout << "\n\n\t\t\tComputer Wins!\n";
	}
	else
	{
		cout << "\n\n\t\t\t     Draw!\n";
	}
	cout << "Would You Like To Play Again: ";
	cin >> uchoice;
	switch (uchoice)
	{
	case 'y':case 'Y':
	{
		counter = 0;
		run = 0;
		stime = 15;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = count;
				count++;
			}
		}
		character = '\0';
		ans = '\0';
		botchar = '\0';
		main();
	}
	case 'n':case 'N':
	{
		system("exit");
		break;
	}
	default:
		cout << "Invalid Input. Enter Y for Yes and N for No";
		_getch();
		system("CLS");
		SDTG();
		MakeBoard();
		break;
	}
}

//LOADING SCREEN ELEMENTS

void NLines()
{
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		cout << endl;
	}
}
void SDTG()
{
	int i = 0;
	cout << "\t\t\t\t     TIC TAC TOE\n\t\t\tMADE IN HONOR OF SIR DANISH THE GREAT";
	for (i = 0; i < 2; i++)
	{
		cout << endl;
	}
}
void Loading()
{
	int j = 1, i = 0;
	char a = 219;
	for (j = counter+1; j <= 87; j++) //Progress Bar
	{
		if (j > counter) //J Starts With 1 + Counter. If J > Counter, It Will Load Progress Bar Rapidly Till J = Counter.
			for (i = 0; i <= counter; i++)
				cout << a;
		cout << a;
		counter++;
		break; // Break and go back to main to change screen color
	}
}
void UBorder()
{
	int i = 0;
	for (i = 0; i < 88; i++)
	{
		cout << "=";
	}
}
void BBorder()
{
	int i = 0;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	for (i = 0; i < 88; i++)
	{
		cout << "=";
	}
}
void Color()
{
	int rn = rand() % 10;
	switch (rn)
	{
	case 1:
	{
		system("color 01");
		break;
	}
	case 2:
	{
		system("color 02");
		break;
	}
	case 3:
	{
		system("color 03");
		break;
	}
	case 4:
	{
		system("color 04");
		break;
	}
	case 5:
	{
		system("color 05");
		break;
	}
	case 6:
	{
		system("color 06");
		break;
	}
	case 7:
	{
		system("color 07");
		break;
	}
	case 8:
	{
		system("color 08");
		break;
	}
	case 9:
	{
		system("color 09");
		break;
	}
	}
}
void BColor()
{
	int rn = rand() % 10;
	switch (rn)
	{
	case 1:
	{
		system("color 10");
		break;
	}
	case 2:
	{
		system("color 20");
		break;
	}
	case 3:
	{
		system("color 30");
		break;
	}
	case 4:
	{
		system("color 40");
		break;
	}
	case 5:
	{
		system("color 50");
		break;
	}
	case 6:
	{
		system("color 60");
		break;
	}
	case 7:
	{
		system("color 70");
		break;
	}
	case 8:
	{
		system("color 80");
		break;
	}
	case 9:
	{
		system("color 90");
		break;
	}
	}
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

//REFERENCES USED:
/*
minimax algorithm
https://towardsdatascience.com/tic-tac-toe-creating-unbeatable-ai-with-minimax-algorithm-8af9e52c1e7d?#14e6 //TIC TAC TOE AI
https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/ //TIC TAC TOE AI
https://www.quora.com/Is-there-a-way-to-never-lose-at-Tic-Tac-Toe //TIC TAC TOE WINNING STRATEGIES
http://www.cplusplus.com/forum/beginner/36978/ // WHY CIN FUNCTION SOMETIMES DOES NOT WORK
https://ee.hawaii.edu/~tep/EE160/Book/chap4/subsection2.1.1.1.html // ASCII CODES OF CHARACTERS
*/