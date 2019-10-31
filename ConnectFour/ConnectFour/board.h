#ifndef __BOARD_H__
#define __BOARD_H__

#include "Init.h"

/*
	현재 보드의 상태를 저장하기 위한 Class
*/
class Board
{
public :
	stone arr[6][7]; //6 * 7 게임판의 상태를 저장하고 있는 배열
	int columnnum[7]; //각 열에 있는 돌의 수를 저장하고 있는 배열
public :
	Board(); //비어있는 보드를 생성해 주는 생성자
	Board(stone** arr); //배열 값을 복사하여 생성해주는 생성자
	Board(const Board& b); //복사 생성자
	/*
	정의 : bool played(int column, player P)
	기능 : 플레이어 P가 column번쨰 열에 돌을 추가하는 함수
	반환 : 둘 수 있는 경우는 true, 만약 그 열이 꼬가 찬 경우에는 false를 return 한다.
	*/
	bool played(int column, player P);
};

/*
	Game Tree에서 각각의 Node들을 표시해주기 위한 함수
*/
class Node
{
public :
	Board b; //해당 Node의 Board 상태를 저장
	Node* parent; //Tree에서 부모노드를 가리키기 위한 Pointer
	Node* child[7]; //Tree에서 자식노드를 가리키기 위한 Pointer. 가능한 자식의 수는 각각의 행을 플레이 하였을 경우이므로 7이다.
	player P; //Node에서 현재 차례인 플레이여
	int score; //Minmax Value를 저장하기 위한 int 형 변수
	int bestcolumn; //현재의 minmax 값을 전달받은 Child를 표시해 주기 위한 int 형 변수

public :
	Node(); //비어있는 Node를 생성해 주는 생성자
	Node(const Board& b); //Board 값을 복사하여 생성해주는 생성자
	Node(const Node& n); //복사 생성자
	/*
	정의 : Node* select(int column)
	기능 : column번쨰 child(column번째 열에 돌을 추가한 경우)를 생성한다.
	반환 : 해당 child의 Pointer를 반환한다. 만약 해당 열이 꽉 차있는 경우, nullptr를 return한다.
	*/
	Node* select(int column);
};

#endif