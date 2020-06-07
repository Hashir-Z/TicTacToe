#include <iostream>
#include <conio.h>
#include "windows.h"
#include <time.h>
using namespace std;

//FUNCTION DECLERATION

void ShowConsoleCursor(bool showFlag);

void main()
{
	ShowConsoleCursor(false); //Disable the Cursor
	srand(time(NULL));
	char winner = '\0';
	int i = 0, counter = 0, j = 0;
	char arr[3][3] = { {'1','2','3'},{'4','5','6'}, {'7','8','9'} };
	Sleep(1000);
	
	//MAKE THE LOADING SCREEN
	{
		for (i = 0; i < 87; i++)
		{
			// Upper Border
			{
				for (j = 0; j < 88; j++)
				{
					cout << "=";
				}
			}

			// New Lines
			{
				for (j = 0; j < 9; j++)
				{
					cout << endl;
				}
			}

			cout << "\t\t\t\t\tLoading" << endl;

			// Progress Bar
			{
				int j = 1;
				char a = 219;
				for (j = counter + 1; j <= 87; j++) //Progress Bar
				{
					if (j > counter) //J Starts With 1 + Counter. If J > Counter, It Will Load Progress Bar Rapidly Till J = Counter.
						for (i = 0; i <= counter; i++)
							cout << a;
					cout << a;
					counter++;
					break; // Break and go back to main to change screen color
				}
			}

			// Bottom Border
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
				for (j = 0; j < 88; j++)
				{
					cout << "=";
				}
			}

			// Change Color Every 3rd Iteration
			if (i % 3 == 0)
			{
				int rn = (rand() % (9 + 1 - 1)) + 1; // (rand() % (MAX + 1 - MIN)) + MIN
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
			Sleep(80);
			system("CLS");
		}
		system("CLS");
	}

	//MAKE THE GAME LOADED SCREEN
	{
		{
			//Upper Border
			{
				for (i = 0; i < 88; i++)
				{
					cout << "=";
				}
			}

			// New Lines
			{
				for (i = 0; i < 9; i++)
				{
					cout << endl;
				}
			}

			cout << "\t\t\t\t\tGame Loaded!\n\t\t\t\t Press any key to continue";

			// Bottom Border
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
				for (i = 0; i < 88; i++)
				{
					cout << "=";
				}
			}

		}
	}

	//CHANGE THE BACKGROUND COLOR
	{
		for (i = 0; i < 5; i++)
		{
			Sleep(800);
			{
				int rn = (rand() % 10) + 1;
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
		}
	}

	system("CLS");
	
	system("color 60"); // CHANGE BACKGROUND COLOR TO YELLOW

	//GAME LOGIC
	{
		int j = 0, left = 0, k = 0, n = 0, stime = 15, run = 1, randcol = 0, randrow = 0;
		char v = 179, h = 196, character = '\0', ans = '\0', botchar = 'X'; // LOADING CHARACTERS
		bool caller = 0;
		char str[1000] = { '\0' };
		for (int loop = 0; loop != 1000; )
		{
			// SIR DANISH THE GREAT
			{
				int i = 0;
				cout << "\t\t\t\t     TIC TAC TOE\n\t\t\tMADE IN HONOR OF SIR DANISH THE GREAT";
				for (i = 0; i < 2; i++)
				{
					cout << endl;
				}
			}

			//MakeBoard
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

			stime = 1; //TO MAKE BOARD DRAW QUICKER AFTER FIRST TIME

			// CHECK IF ANYONE HAS WON
			{
				bool win = 0;
				// HORIZONTAL & VERTICAL CHECK
				for (i = 0; i < 3; i++)
				{
					// VERTICAL CHECK
					if (((arr[i][0] == arr[i][1]) && (arr[i][0] == arr[i][2]))) 
					{
						winner = arr[i][0];
						loop = 1000;
						win = 1;
 						break; // TO BREAK OUT OF LOCAL LOOP
					}
					// HORIZONTAL CHECK
					else if (((arr[0][i] == arr[1][i]) && (arr[0][i] == arr[2][i])))
					{
						winner = arr[0][i];
						loop = 1000;
						win = 1;
						break; // TO BREAK OUT OF LOCAL LOOP
					}
				}

				// DIAGONAL CHECK
				if ((((arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2])) || ((arr[0][2] == arr[1][1]) && (arr[0][2] == arr[2][0]))))
				{
					winner = arr[1][1];
					loop = 1000;
					win = 1;
					break;
				}
				if (win == 1)
				{
					break; // TO BREAK OUT OF MAIN LOOP
				}
			}

			// CHECK IF BOARD HAS BEEN COMPLETELY FILLED
			{
				// LOOP TO CHECK IF BOARD HAS BEEN COMPLETELY FILLED
				left = 0;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						if (((arr[i][j] >= 'A') && (arr[i][j] <= 'Z')) || ((arr[i][j] >= 'a') && (arr[i][j] <= 'z'))) // IF A CHARACTER IS FOUND AT INDEX I OF J
						{
							left++;
						}
					}
				}
				if (left == 9) // IF ALL 9 SPACES HAVE BEEN FILLED, BREAK MAIN LOOP
				{
					break;
				}
			}

			// IF FIRST RUN, PLAYER CHOOSES HIS CHARACTER
			{
				if (run == 1)
				{
					cout << "\n\nEnter Your Character: ";
					cin >> str;
					character = str[0];
					if (!(((character >= 65) && character <= 90) || (character >= 97 && character <= 122))) //IF USER CHARACTER IS NOT CAPTIAL/SMALL ALPHABET
					{
						cout << "Character Can Only Be Alphabet!";
						_getch();
						system("CLS");
						continue;
					}
					//TO CLEAR THE SCREEN AND DRAW BOARD AGAIN
					system("CLS");
					run = 2; // TO ENSURE THAT THIS CODE DOES NOT RUN AGAIN
					continue; // GOES TO END OF LOOP BODY/NEXT ITERATION
				}
			}

			// IF SECOND RUN, ASK PLAYER IF HE WOULD LIKE TO GO FIRST
			{
				if (run == 2) // RUNS AFTER PLAYER HAS CHOSEN HIS CHARACTER
				{
					{
						cout << "\n\nWould You Like To Go First: ";
						cin >> ans;
						switch (ans)
						{
						case 'y': case 'Y':
						{
							run = 3; // SO THAT CONDITION DOES NOT RUN AGAIN - USER TURN 
							system("CLS");
							continue;
						}
						case 'n': case 'N':
						{
							run = 4;  // SO THAT CONDITION DOES NOT RUN AGAIN  - BOT TURN
							system("CLS");
							continue;
						}
						default:
						{
							cout << "Invalid Input. Please enter Y for Yes and N for No." << endl;
							_getch();
							system("CLS");
							continue;
						}
						}
					}
				}
			}

			// IF >= THIRD RUN, CALL FUNCTION AGAIN
			{
				if (run >= 3 && run % 2 != 0) //ODD: USER TURN - EVEN: BOT TURN
				{
					{
						int num = 0;
						cout << "\n\nEnter The Number Where You'd Like To Place Your Character: ";
						cin.clear(); // The cin. clear() clears the error flag on cin (so that future I/O operations will work correctly)
						cin.ignore(); // Used to ignore or clear one or more characters from the input buffer
						cin >> num;
						if (!(num > 0 && num < 10)) // IF NUMBER NOT IN BETWEEN 1 - 9
						{
							cout << "Please Enter A Valid Location!";
							_getch();
							system("CLS");
							continue;
						}
						//CHECKS WHERE TO PUT USER CHARACTER AND ENSURES LOCATION NOT ALREADY TAKEN!
						{
							if (num <= 3) // IF USER HAS ENTERED VALUE B/W 1 - 3
							{
								if (arr[0][num - 1] != character && arr[0][num - 1] != botchar) // CHECK TO SEE IF LOCATION IS TAKEN
								{
									arr[0][num - 1] = character; // (USER VALUE) - 1, BECAUSE RANGE IS 0 - 2, WHEREAS USER RANGE IS 1 - 3
								}
								else
								{
									cout << "Location Alread Taken!";
									Sleep(1000);
									_getch(); // WAIT TILL USER PRESSES A KEY BEFORE CONTINUING
									system("CLS");
									continue;
								}
							}
							else if (num <= 6)
							{
								if (arr[1][num - 4] != character && arr[1][num - 4] != botchar) // CHECK TO SEE IF LOCATION IS TAKEN
								{
									arr[1][num - 4] = character; // (USER VALUE) - 4, BECAUSE RANGE IS 0 - 2, WHEREAS USER RANGE IS 4 - 6
								}
								else
								{
									cout << "Location Alread Taken!";
									Sleep(1000);
									_getch();
									system("CLS");
									continue;
								}
							}
							else if (num <= 9)
							{
								if (arr[2][num - 7] != character && arr[2][num - 7] != botchar) // CHECK TO SEE IF LOCATION IS TAKEN
								{
									arr[2][num - 7] = character; // (USER VALUE) - 7, BECAUSE RANGE IS 0 - 2, WHEREAS USER RANGE IS 7 - 9
								}
								else
								{
									cout << "Location Alread Taken!";
									Sleep(1000);
									_getch();
									system("CLS");
									continue;
								}
							}
							run++;
							system("CLS");
							continue;
						}
					}
				}
				else if (run >= 4) //BOTS TURN
				{
					{
						int i = 0, j = 0, k = 0;
						cout << "\n\n\t\t     Calculating, Please Wait...";

						//CHANGE BOTS CHARACTER IF SAME AS PLAYER CHARACTER
						if (botchar == character || character == 'x')
						{
							botchar = 'Y';
						}

						Sleep(rand() % (1000 - 500 + 1) + 500);  // TO MAKE IT SEEM AS IF COMPUTER IS ACTUALLY CALCULATING
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
										i = 3, j = 3, k = -1;
										break;
									}
									// IF HORIZONTALLY FILLED
									else if (((arr[i][j] == character) && (arr[i][1] == character)) && ((arr[i][k] != botchar) && (arr[i][k] != character)))
									{
										arr[i][k] = botchar;
										i = 3, j = 3, k = -1;
										break;
									}
									else if (i == 2 && j == 2 && k == 0) // TO ENSURE ALL POSIBILITIES HAVE BEEN CHECKED
									{
										randcol = (rand() % (2 + 1)); // STORES RANDOM COLOMN NUMBER // FORMULA: [rand() % (MAX + 1 - MIN)] + MIN
										randrow = (rand() % (2 + 1)); // STORES RANDOM ROW NUMBER // FORMULA: [rand() % (MAX + 1 - MIN)] + MIN
										for (; (arr[randcol][randrow] == botchar) || (arr[randcol][randrow] == character);) //RUN LOOP UNTIL LOCATION NOT TAKEN
										{
											randcol = (rand() % (2 + 1));
											randrow = (rand() % (2 + 1));;
										}
										arr[randcol][randrow] = botchar;
										i = 3, j = 3, k = -1;
										break;
									}
								}
							}
						}
						system("CLS");
						continue;
					}
				}
			}
		}
		if (winner == character) // IF WINNER IS USER
		{
			cout << "You Are The Winner!"<< endl;
		}
		else if (winner == botchar) // IF WINNER IS BOT
		{
			cout << "Computer Wins!" << endl;
		}
		else // IF NO ONE WON
		{
			cout << "Its a Draw!" << endl;
		}
		system("pause");
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

/*
										LOGIC BEHIND GAME
GAME LOADING SCREEN
GAME LOADED SCREEN
LOOP THAT RUNS IF VALUE != 1000
{
	DRAW BOARD
	CHECK IF ANYONE HAS WON. WINNER CHARACTER WILL BE STORED IN WINNER VAR, LOOP WILL BE TERMINATED
	CHECK IF GAME IS DRAW; IF ALL POSITIONS TAKEN, LOOP WILL BE TERMINATED
	RUN = 1: ASK USER FOR WHAT CHARACTER HE WANTS + SET VALUE OF RUN TO 2 
	RUN = 2: ASK USER IF HE WANTS TO GO FIRST. IF YES; RUN = 3; ELSE RUN = 4
	IF RUN IS EVEN, ITS BOT TURN, IF RUN IS ODD, IT'S USERS TURN
	AFTER EACH TURN, RUN VAR WILL INCREASE BY ONE!
}
IF VAR WINNER = USER CHAR; USER IS WINNER
ELSE IF VAR WINNER = BOT CHAR, BOT IS WINNER
ELSE GAME IS DRAW
*/