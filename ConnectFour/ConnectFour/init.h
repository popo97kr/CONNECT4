#ifndef __INIT_H__
#define __INIT_H__

enum player {Player1, Player2}; // 현재 player를 표시해 주기 위한 열거형 상수

using stone = _int8; // 놓여진 돌을 표시하기 위한 자료형
/*
	0  : 비어 있음
	1  : Player 1
	-1 : Player 2
*/

inline stone PTOS(player p) { return (p == Player1) ? 1 : -1; } //현재의 Player 값은 stone 값으로 바꿔주는 inline 함수
inline player SWITCHPLAYER(player p) { return (p == Player1) ? Player2 : Player1; } //Player를 switch 하기 위한 inline 함수 

const int SCORE_MAX = 100000; // +∞
const int SCORE_MIN = -100000; // -∞
const int depth = 10; //minmax algorithm에서 partial tree의 높이

player& currentplayer(); //현재 차례의 player를 저장해 주기위한 변수()

int& lastplayed(); //가장 최근에 놓은 돌을 저장한다
int& ruleused(); //가장 최근에 사용한 Rule을 저장한다.

#endif