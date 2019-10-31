#ifndef __AI_H_
#define __AI_H_

#include "Board.h"
#include "Init.h"

/*
	���� : int finchecker(const Board& b)
	��� : ���� board�� ������ ����� ����(�� �÷��̾��� �� 4���� ���ӵ� ����)������ �˻��Ѵ�.
	��ȯ : ������ ���� ���� 0, Player1�� �̱�� ���� 1, Player2�� �̱�� ���� 2�� return �Ѵ�.
*/
int finchecker(const Board& b);
/*
	���� : int getscore(stone arr[4])
	��� : parameter�� stone �� 4���� ���޹ް�, �ش� stone 4���� ���� ������ ����Ѵ�.
	��ȯ : ���� ������ ��ȯ�Ѵ�.
*/
int getscore(stone arr[4]);
/*
	���� : int heuristicfunc(Node *n, player P)
	��� : parameter�� ���޹��� Node�� ���Ե� Board�� heuristic ���� P �÷��̾� �������� ����Ѵ�.
	��ȯ : ���� heuristic ���� ��ȯ�Ѵ�.
*/
int heuristicfunc(Node* n, player P);
/*
	���� : int minmax(Node* n, int height)
	��� : parameter�� Node�� height�� ���޹޾� minmax algorithm�� �����Ѵ�. (alpha-beta pruning ���� ���� �����Ѵ�)
	��ȯ : �ش� Node�� minmax value�� ��ȯ�Ѵ�.
*/
int minmax(Node* n, int height);
/*
	���� : int findbest(const Board& b)
	��� : parameter�� Board�� �Է¹޾� AI �˰����� ���� ������ column�� ã�´�
	��ȯ : ���� column�� return �Ѵ�.
*/
int findbest(const Board& b);

#endif 