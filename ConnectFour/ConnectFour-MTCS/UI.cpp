#include "UI.h"

void showBoard(const Board& b)
{
	system("CLS");
	cout << "忙式式式式式成式式式式式成式式式式式成式式式式式成式式式式式成式式式式式成式式式式式忖" << endl;

	for (int i = 5; i >= 0; i--)
	{
		cout << "弛     弛     弛     弛     弛     弛     弛     弛" << endl << "弛";
		for (int j = 0; j < 7; j++)
		{
			char c;
			switch (b.arr[i][j])
			{
			case 1: c = 'O'; break;
			case -1: c = 'X'; break;
			default: c = ' '; break;
			}
			cout << "  " << c << "  弛";
		}
		cout << endl << "弛     弛     弛     弛     弛     弛     弛     弛" << endl;
		if (i != 0) cout << "戍式式式式式托式式式式式托式式式式式托式式式式式托式式式式式托式式式式式托式式式式式扣" << endl;
	}
	cout << "戌式式式式式扛式式式式式扛式式式式式扛式式式式式扛式式式式式扛式式式式式扛式式式式式戎" << endl;
	cout << "   1     2     3     4     5     6     7" << endl;

	return;
}