#include "AI.h"

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

int getscore(stone arr[4])
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

int heuristicfunc(Node* n, player P)
{
	int result = 0;
	if (n->parent)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i > 2 && j > 2)
				{
					stone temp[4] = { n->b.arr[i][j], n->b.arr[i - 1][j - 1], n->b.arr[i - 2][j - 2], n->b.arr[i - 3][j - 3] };
					int scr = getscore(temp);
					result += scr * PTOS(P);
					if (scr == SCORE_MAX || scr == SCORE_MIN)
						return scr * PTOS(P);;
				}
				if (i > 2)
				{
					stone temp[4] = { n->b.arr[i][j], n->b.arr[i - 1][j], n->b.arr[i - 2][j], n->b.arr[i - 3][j] };
					int scr = getscore(temp);
					result += scr * PTOS(P);
					if (scr == SCORE_MAX || scr == SCORE_MIN)
						return scr * PTOS(P);;
				}
				if (j > 2)
				{
					stone temp[4] = { n->b.arr[i][j], n->b.arr[i][j - 1], n->b.arr[i][j - 2], n->b.arr[i][j - 3] };
					int scr = getscore(temp);
					result += scr * PTOS(P);
					if (scr == SCORE_MAX || scr == SCORE_MIN)
						return scr * PTOS(P);;
				}
				if (i > 2 && j < 4)
				{
					stone temp[4] = { n->b.arr[i][j], n->b.arr[i - 1][j + 1], n->b.arr[i - 2][j + 2], n->b.arr[i - 3][j + 3] };
					int scr = getscore(temp);
					result += scr * PTOS(P);
					if (scr == SCORE_MAX || scr == SCORE_MIN)
						return scr * PTOS(P);;
				}
			}
		}
	}

	return result;
}

int minmax(Node* n, int height)
{
	
	int s = finchecker(n->b);
	if (s)
	{
		switch (s)
		{
		case 1:
			return (currentplayer() == Player1) ? SCORE_MAX : SCORE_MIN;
		case 2:
			return (currentplayer() == Player1) ? SCORE_MIN : SCORE_MAX;
		}
	}
	
	if (height == 0)
		n->score = heuristicfunc(n, currentplayer());
	else
	{
		if (currentplayer() == n->P)
		{
			n->score = SCORE_MIN;
			for (int i = 0; i < 7; i++)
			{
				n->child[i] = n->select(i);
				if (n->child[i] == nullptr)
					continue;
				int s = minmax(n->child[i], height - 1);
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
				int s = minmax(n->child[i], height - 1);
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


int findbest(const Board& b)
{

	int checksum = 0;

	for (int i = 0; i < 7; i++)
		checksum += b.columnnum[i];

	if (checksum == 0)
		return 2;
	else
	{
		Node* n = new Node(b);
		n->P = currentplayer();
		minmax(n, depth);

		if(n->bestcolumn == -1 || !n->b.played(n->bestcolumn, currentplayer()))
			for (int i = 0; i < 7; i++)
				if (n->b.columnnum[i] != 6)
					n->bestcolumn = i;
		return  n->bestcolumn;
	}
}