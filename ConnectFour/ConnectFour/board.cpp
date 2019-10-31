#include "Board.h"

Board::Board()
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
			arr[i][j] = 0;
	for (int i = 0; i < 7; i++)
		columnnum[i] = 0;
}
Board::Board(stone** arr)
{
	for (int i = 0; i < 7; i++)
		columnnum[i] = 0;

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
		{
			this->arr[i][j] = arr[i][j];
			if (arr[i][j] != 0)
				columnnum[j]++;
		}
}
Board::Board(const Board& b)
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
			arr[i][j] = b.arr[i][j];

	for (int i = 0; i < 7; i++)
		columnnum[i] = b.columnnum[i];
}

bool Board::played(int column, player P)
{
	if (columnnum[column] == 6)
		return false;
	else
	{
		arr[columnnum[column]++][column] = PTOS(P);
		return true;
	}
}

Node::Node()
	: b(), parent(nullptr), P(Player1), score(0), bestcolumn(-1)
{
	for (int i = 0; i < 7; i++)
		child[i] = nullptr;
}

Node::Node(const Board& b)
	: b(b), parent(nullptr), P(Player1), score(0), bestcolumn(-1)
{
	for (int i = 0; i < 7; i++)
		child[i] = nullptr;
}

Node::Node(const Node& n)
	: b(n.b), parent(n.parent), P(n.P), score(n.score), bestcolumn(n.bestcolumn)
{
	for (int i = 0; i < 7; i++)
		child[i] = n.child[i];
}

Node* Node::select(int column)
{
	Node* result = new Node(*this);

	if (!result->b.played(column, P))
		result = nullptr;
	else
	{
		result->P = SWITCHPLAYER(P);
		result->parent = this;
		for (int i = 0; i < 7; i++)
		{
			result->child[i] = nullptr;
		}
		result->score = 0;
		result->bestcolumn = -1;
	}

	return result;
}