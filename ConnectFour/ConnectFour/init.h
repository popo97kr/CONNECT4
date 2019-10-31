#ifndef __INIT_H__
#define __INIT_H__

enum player {Player1, Player2}; // ���� player�� ǥ���� �ֱ� ���� ������ ���

using stone = _int8; // ������ ���� ǥ���ϱ� ���� �ڷ���
/*
	0  : ��� ����
	1  : Player 1
	-1 : Player 2
*/

inline stone PTOS(player p) { return (p == Player1) ? 1 : -1; } //������ Player ���� stone ������ �ٲ��ִ� inline �Լ�
inline player SWITCHPLAYER(player p) { return (p == Player1) ? Player2 : Player1; } //Player�� switch �ϱ� ���� inline �Լ� 

const int SCORE_MAX = 100000; // +��
const int SCORE_MIN = -100000; // -��
const int depth = 10; //minmax algorithm���� partial tree�� ����

player& currentplayer(); //���� ������ player�� ������ �ֱ����� ����()

int& lastplayed(); //���� �ֱٿ� ���� ���� �����Ѵ�
int& ruleused(); //���� �ֱٿ� ����� Rule�� �����Ѵ�.

#endif