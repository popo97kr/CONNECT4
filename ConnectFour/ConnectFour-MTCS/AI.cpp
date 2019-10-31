#include "AI.h"

int insert(Board *b, player P)
{
	int valid[7];
	int i, count = -1;
	int newcol, insertval;
	insertval = PTOS(P);
	for (i = 0; i < 7; i++)valid[i] = -1;
	if (b->arr[5][0] != 0 && b->arr[5][1] != 0 && b->arr[5][2] != 0 && b->arr[5][3] != 0 && b->arr[5][4] != 0 && b->arr[5][5] != 0 && b->arr[5][6] != 0)return -1;
	for (i = 0; i < 7; i++)
		if (b->arr[5][i] == 0)valid[++count] = i;
	count++;
	newcol = valid[(rand() % count)];
	for (i = 0; i < 6; i++)
	{
		if (b->arr[i][newcol] == 0)
		{
			b->arr[i][newcol] = insertval;
			break;
		}
	}
	return newcol;
}

int checkWin(Board *b, int lastcol)
{
	int i;
	int row;
	int num;
	int startrow, startcol;
	for (i = 0; i < 6; i++)
		if (b->arr[i][lastcol] == 0)break;
	row = i - 1;
	int p = b->arr[row][lastcol];
	for (i = 0; i < 3; i++)
		if (b->arr[i][lastcol] == p && b->arr[i][lastcol] == b->arr[i + 1][lastcol] && b->arr[i][lastcol] == b->arr[i + 2][lastcol] && b->arr[i][lastcol] == b->arr[i + 3][lastcol])return p;
	for (i = 0; i < 4; i++)
		if (b->arr[row][i] == p && b->arr[row][i] == b->arr[row][i + 1] && b->arr[row][i] == b->arr[row][i + 2] && b->arr[row][i] == b->arr[row][i + 3])return p;
	num = lastcol + row;
	if (num >= 6 && num <= 8)
	{
		for (i = 0; i < (9 - num); i++)
			if (b->arr[i][6 - i] == p && b->arr[i][6 - i] == b->arr[i + 1][5 - i] && b->arr[i][6 - i] == b->arr[i + 2][4 - i] && b->arr[i][6 - i] == b->arr[i + 3][3 - i])return p;
	}
	else if (num >= 3 && num <= 5)
	{
		for (i = 0; i < (num - 2); i++)
		{
			startcol = num - i;
			if (b->arr[i][startcol] == p && b->arr[i][startcol] == b->arr[i + 1][startcol - 1] && b->arr[i][startcol] == b->arr[i + 2][startcol - 2] && b->arr[i][startcol] == b->arr[startcol - 3][i])return p;
		}
	}
	num = row - lastcol;
	if (num >= 0 && num <= 2)
	{
		for (i = 0; i < 3 - num; i++)
		{
			startrow = num + i;
			if (b->arr[startrow][i] == p && b->arr[startrow][i] == b->arr[startrow + 1][i + 1] && b->arr[startrow][i] == b->arr[startrow + 2][i + 2] && b->arr[startrow][i] == b->arr[startrow + 3][i + 3])return p;
		}
	}
	else if (num >= -3 && num <= -1)
	{
		for (i = 0; i < 4 + num; i++)
		{
			startcol = i - num;
			if (b->arr[i][lastcol] == p && b->arr[i][startcol] == b->arr[i + 1][startcol + 1] && b->arr[i][startcol] == b->arr[i + 2][startcol + 2] && b->arr[i][startcol] == b->arr[i + 3][startcol + 3])return p;
		}
	}
	return 0;
}

int finchecker(const Board& b)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i > 2 && j > 2)
			{
				switch (b.arr[i][j] + b.arr[i - 1][j - 1] + b.arr[i - 2][j - 2] + b.arr[i - 3][j - 3])
				{
				case 4: return 1;
				case -4: return 2;
				}
			}
			if (i > 2)
			{
				switch (b.arr[i][j] + b.arr[i - 1][j] + b.arr[i - 2][j] + b.arr[i - 3][j])
				{
				case 4: return 1;
				case -4: return 2;
				}
			}
			if (i > 2 && j < 4)
			{
				switch (b.arr[i][j] + b.arr[i - 1][j + 1] + b.arr[i - 2][j + 2]  + b.arr[i - 3][j + 3])
				{
				case 4: return 1;
				case -4: return 2;
				}
			}
			if (j > 2)
			{
				switch (b.arr[i][j] + b.arr[i][j - 1]  + b.arr[i][j - 2]  + b.arr[i][j - 3])
				{
				case 4: return 1;
				case -4: return 2;
				}
			}
		}
	}
	return 0;
}

int getscore(int arr[4])
{
	int p1num = 0;
	int p2num = 0;
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		switch (arr[i])
		{
		case 1: p1num++; break;
		case -1: p2num++; break;
		}
	}

	if (p1num > 0)
	{
		if (p2num == 0)
			result = p1num * p1num * p1num;
	}
	else
	{
		if (p2num > 0)
			result = -p2num * p2num * p2num;
	}

	if (result == 64)
		result = SCORE_MAX;
	if (result == -64)
		result = SCORE_MIN;
	return result;
}

int heuristicfunc_mcts(Node* n, player P)
{
	int result = 0;
	
	int i, j;
	int col, row;
	Board *board, *newboard;
	
	/*
	if (PTOS(P) == 1)
	{
		if (lastcol != -1) {
			for (i = 0; i < 6; i++)
				if (n->b.arr[i][lastcol] == 0)break;
			i--;
			board = new Board(n->b);
			board->arr[i][lastcol] = 1;
			if (checkWin(board, lastcol) == 1)
			{
				delete board;
				return 100000;
			}
			delete board;
		}
	}
	*/
	if (P == Player2)
	{
		for (i = 0; i < 5000; i++) {
			board = new Board(n->b);
			for (j = 0; j < 45; j++)
			{
				if ((col = insert(board, Player2)) == -1)break;
				else
				{
					if (checkWin(board, col) == -1)
					{
						result += 1;
						break;
					}
				}
				if ((col = insert(board, Player1)) == -1)break;
				else
				{
					if (checkWin(board, col) == 1)
					{
						result -= 50;
						break;
					}
				}
				result++;
			}
			delete board;
		}
	}
	else
	{
		for (i = 0; i < 5000; i++)
		{
			board = new Board(n->b);
			for (j = 0; j < 20; j++)
			{
				if ((col = insert(board, Player1)) == -1)break;
				else
				{
					if (checkWin(board, col) == 1)
					{
						result -= 50;
						break;
					}
				}
				if ((col = insert(board, Player2)) == -1)break;
				else
				{
					if (checkWin(board, col) == -1)
					{
						result += 1;
						break;
					}
				}
				result++;
			}
			delete board;
		}
	}
	return result;
}

int minmax(Node* n, int height, player currentplayer)
{
	
	int s = finchecker(n->b);
	if (s)
	{
		switch (s)
		{
		case 1:
			return (currentplayer == Player1) ? SCORE_MAX : SCORE_MIN;
		case 2:
			return (currentplayer == Player1) ? SCORE_MIN : SCORE_MAX;
		}
	}
	
	if (height == 0)
		n->score = heuristicfunc_mcts(n, currentplayer);
	else
	{
		if (currentplayer == n->P)
		{
			n->score = SCORE_MIN;
			for (int i = 0; i < 7; i++)
			{
				n->child[i] = n->select(i);
				if (n->child[i] == nullptr)
					continue;
				int s = minmax(n->child[i], height - 1, currentplayer);
				if (n->score < s)
				{
					n->score = s;
					n->bestcolumn = i;
					if (n->parent != nullptr && s >= n->parent->score)
						break;
				}
				delete n->child[i];
			}
		}
		else
		{
			n->score = SCORE_MAX;
			for (int i = 0; i < 7; i++)
			{
				n->child[i] = n->select(i);
				if (n->child[i] == nullptr)
					continue;
				int s = minmax(n->child[i], height - 1, currentplayer);
				if (n->score > s)
				{
					n->score = s;
					n->bestcolumn = i;
					if (s <= n->parent->score)
						break;
				}
				delete n->child[i];
			}
		}
	}

	return n->score;
}

int findbest_mcts(const Board& b, player P)
{

	int checksum = 0;
	int i, j;
	Board *board;

	for (i = 0; i < 7; i++)
		checksum += b.columnnum[i];

	if (checksum == 0)
		return 2;
	else
	{
		
		for (i = 0; i < 7; i++)
		{
			if (b.arr[5][i] != 0)continue;
			board = new Board(b);
			for (j = 0; j < 6; j++)
			{
				if (board->arr[j][i] == 0)break;
			}
			board->arr[j][i] = 1;
			if (checkWin(board, i) == 1)
			{
				delete board;
				return i;
			}
			delete board;
		}
		Node* n = new Node(b);
		n->P = P;
		minmax(n, depth, P);

		if(n->bestcolumn == -1 || !n->b.played(n->bestcolumn, P))
			for (int i = 0; i < 7; i++)
				if (n->b.columnnum[i] != 6)
					n->bestcolumn = i;
		return  n->bestcolumn;
	}
}