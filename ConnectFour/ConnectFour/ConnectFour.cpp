#include <iostream>
#include <conio.h>
#include <ctime>

#include "Init.h"
#include "Board.h"
#include "AI.h"
#include "UI.h"
#include "Rule.h"

int main(void)
{
	Board b;
	clock_t currenttime;
	int role;
	int mode;

	int col = -1;

	cout << "선공 : 1, 후공 : 2" << endl;
	cin >> role;
	currentplayer() = (role == 1) ? Player1 : Player2;

	while (true)
	{
		showBoard(b);

		if (col != -1)
		{
			cout << "Last palyed(";
			if (currentplayer() == Player2)
				cout << "User";
			else if (mode == 1)
				cout << "Heuristic";
			else
			{
				cout << "Rule-";
				switch (ruleused())
				{
				case 1:
					cout << "rule1";
					break;
				case 2:
					cout << "rule2";
					break;
				case 3:
					cout << "rule3";
					break;
				case 4:
					cout << "rule4";
					break;
				case 5:
					cout << "claimeven";
					break;
				case 6:
					cout << "baseinverses";
					break;
				case 7:
					cout << "vertical";
					break;
				}
			}
			cout << "): (" << b.columnnum[col] << ", " << col + 1 << ")" << endl;
			cout << "Runtime : " << (double) (clock() - currenttime) / CLOCKS_PER_SEC << "sec" << endl;
		}
		currenttime = clock();
		bool s = finchecker(b);
		if (s)
		{
			cout << "Player " << SWITCHPLAYER(currentplayer()) + 1 << " is winner!!" << endl;
			break;
		}

		if (currentplayer() == Player2)
		{
			cout << "Heuristic : 1, Rule : 2" << endl;
			cin >> mode;
			switch (mode)
			{
			case 1:
				col = findbest(b); break;
			case 2:
				col = ruleplay(b); break;
			default:
				col = -2;
			}
			if (col == -1)
			{
				cout << "---Draw---" << endl;
				break;
			}
			else if (col == -2)
			{
				cout << "Wrong Input!!!" << endl;
				_getch();
				continue;
			}
		}
		else
		{
			bool isfull = true;
			for (int i = 0; i < 7; i++)
				if (b.columnnum[i] != 6)
					isfull = false;
			if (isfull)
			{
				cout << "---Draw---" << endl;
				break;
			}
			col = _getch() - 49;
			if (col > 9 || col < 0)
			{
				cout << "Wrong Input!!!" << endl;
				_getch();
				continue;
			}
			else if (b.columnnum[col] == 6)
			{
				cout << "It's Full!!" << endl;
				_getch();
				continue;
			}
			else
				lastplayed() = col;
		}
		b.played(col, currentplayer());
		currentplayer() = SWITCHPLAYER(currentplayer());
	}

	return 0;
}
//