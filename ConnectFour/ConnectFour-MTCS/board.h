#ifndef __BOARD_H__
#define __BOARD_H__

#include "Init.h"

class Board
{
public :
	stone arr[6][7];
	int columnnum[7];
public :
	Board();
	Board(stone** arr);
	Board(const Board& b);

	bool played(int column, player P);
};

class Node
{
public :
	Board b;
	Node* parent;
	Node* child[7];
	player P;
	int score;
	int bestcolumn;

public :
	Node();
	Node(const Board& b);
	Node(const Node& n);
	Node* select(int column);
};

#endif