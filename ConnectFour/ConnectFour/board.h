#ifndef __BOARD_H__
#define __BOARD_H__

#include "Init.h"

/*
	���� ������ ���¸� �����ϱ� ���� Class
*/
class Board
{
public :
	stone arr[6][7]; //6 * 7 �������� ���¸� �����ϰ� �ִ� �迭
	int columnnum[7]; //�� ���� �ִ� ���� ���� �����ϰ� �ִ� �迭
public :
	Board(); //����ִ� ���带 ������ �ִ� ������
	Board(stone** arr); //�迭 ���� �����Ͽ� �������ִ� ������
	Board(const Board& b); //���� ������
	/*
	���� : bool played(int column, player P)
	��� : �÷��̾� P�� column���� ���� ���� �߰��ϴ� �Լ�
	��ȯ : �� �� �ִ� ���� true, ���� �� ���� ���� �� ��쿡�� false�� return �Ѵ�.
	*/
	bool played(int column, player P);
};

/*
	Game Tree���� ������ Node���� ǥ�����ֱ� ���� �Լ�
*/
class Node
{
public :
	Board b; //�ش� Node�� Board ���¸� ����
	Node* parent; //Tree���� �θ��带 ����Ű�� ���� Pointer
	Node* child[7]; //Tree���� �ڽĳ�带 ����Ű�� ���� Pointer. ������ �ڽ��� ���� ������ ���� �÷��� �Ͽ��� ����̹Ƿ� 7�̴�.
	player P; //Node���� ���� ������ �÷��̿�
	int score; //Minmax Value�� �����ϱ� ���� int �� ����
	int bestcolumn; //������ minmax ���� ���޹��� Child�� ǥ���� �ֱ� ���� int �� ����

public :
	Node(); //����ִ� Node�� ������ �ִ� ������
	Node(const Board& b); //Board ���� �����Ͽ� �������ִ� ������
	Node(const Node& n); //���� ������
	/*
	���� : Node* select(int column)
	��� : column���� child(column��° ���� ���� �߰��� ���)�� �����Ѵ�.
	��ȯ : �ش� child�� Pointer�� ��ȯ�Ѵ�. ���� �ش� ���� �� ���ִ� ���, nullptr�� return�Ѵ�.
	*/
	Node* select(int column);
};

#endif