#ifndef __AI_H_
#define __AI_H_

#include "Board.h"
#include "Init.h"

/*
	정의 : int finchecker(const Board& b)
	기능 : 현재 board가 게임이 종료된 상태(한 플레이어의 돌 4개가 연속된 상태)인지를 검사한다.
	반환 : 끝나지 않은 경우는 0, Player1이 이기는 경우는 1, Player2가 이기는 경우는 2를 return 한다.
*/
int finchecker(const Board& b);
/*
	정의 : int getscore(stone arr[4])
	기능 : parameter로 stone 값 4개를 전달받고, 해당 stone 4개에 대한 점수를 계산한다.
	반환 : 계산된 점수를 반환한다.
*/
int getscore(stone arr[4]);
/*
	정의 : int heuristicfunc(Node *n, player P)
	기능 : parameter로 전달받은 Node에 포함된 Board의 heuristic 값을 P 플레이어 기준으로 계산한다.
	반환 : 계산된 heuristic 값을 반환한다.
*/
int heuristicfunc(Node* n, player P);
/*
	정의 : int minmax(Node* n, int height)
	기능 : parameter로 Node와 height를 전달받아 minmax algorithm을 시행한다. (alpha-beta pruning 또한 같이 실행한다)
	반환 : 해당 Node의 minmax value를 반환한다.
*/
int minmax(Node* n, int height);
/*
	정의 : int findbest(const Board& b)
	기능 : parameter로 Board를 입력받아 AI 알고리즘을 통해 최적의 column을 찾는다
	반환 : 구한 column을 return 한다.
*/
int findbest(const Board& b);

#endif 