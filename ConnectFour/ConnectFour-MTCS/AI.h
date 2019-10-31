#ifndef __AI_H_
#define __AI_H_

#include "Board.h"
#include "Init.h"

#include <iostream>
#include <conio.h>
#include "UI.h"
using namespace std;//나중에 ㅈㅣ우기

int finchecker(const Board& b);
int getscore(int arr[4]);
int heuristicfunc_mcts(Node* n, player P);
int minmax(Node* n, int height, player currentplayer);
int findbest_mcts(const Board& b, player P);

int insert(Board *b, player P);
int checkWin(Board *b, int lastcol);

#endif 