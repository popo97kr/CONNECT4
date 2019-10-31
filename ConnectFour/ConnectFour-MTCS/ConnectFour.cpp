#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <ctime>

#include "Init.h"
#include "Board.h"
#include "AI.h"
#include "UI.h"

int main(void)
{
	Board b;
	player currentplayer;
	clock_t currenttime;
	int role;

	srand((unsigned)time(NULL));

	int row = -1;

	cout << "선공 : 1, 후공 : 2" << endl;
	cin >> role;
	currentplayer = (role == 1) ? Player1 : Player2;

	while (true)
	{
		showBoard(b);

		if (row != -1)
		{
			cout << "Last palyed : " << row + 1 << endl;
			cout << "Runtime : " << (double) (clock() - currenttime) / CLOCKS_PER_SEC << "sec" << endl;
		}
		currenttime = clock();
		bool s = finchecker(b);
		if (s)
		{
			cout << "Player " << SWITCHPLAYER(currentplayer) + 1 << " is winner!!" << endl;
			break;
		}

		if (currentplayer == Player2)
			row = findbest_mcts(b, currentplayer);
		else
		{
			row = _getch() - 49;
			if (row > 9 || row < 0)
			{
				cout << "Wrong Input!!!" << endl;
				_getch();
				continue;
			}
			if (b.columnnum[row] == 6)
			{
				cout << "It's Full!!" << endl;
				_getch();
				continue;
			}
		}
		b.played(row, currentplayer);
		currentplayer = SWITCHPLAYER(currentplayer);
	}

	return 0;
}
//