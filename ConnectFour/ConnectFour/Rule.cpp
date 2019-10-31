#include "Rule.h"

int checknum(int arr[4])
{
	int p1num = 0;
	int p2num = 0;
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		switch (arr[i])
		{
		case 1: p1num++; break;
		case -1: p2num--; break;
		}
	}
	if (p1num > 0 && p2num == 0)
		result = p1num;
	if (p1num == 0 && p2num < 0)
		result = p2num;
	if (currentplayer() == Player2)
		result *= -1;
	return result;
}

//RULE1: �̱�� ���� ������, ��������.
int rule1(const Board& b)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i > 2 && j > 2)//�밢��üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j - 1], b.arr[i - 2][j - 2], b.arr[i - 3][j - 3] };
				if (checknum(temp) == 3)
				{
					if (b.arr[i][j] == 0 && b.arr[i - 1][j] != 0) return j;
					else if (b.arr[i - 1][j - 1] == 0 && b.arr[i - 2][j - 1] != 0) return j - 1;
					else if (b.arr[i - 2][j - 2] == 0 && b.arr[i - 3][j - 2] != 0) return j - 2;
					else if (b.arr[i - 3][j - 3] == 0 && (i == 3 || b.arr[i - 4][j - 3] != 0)) return j - 3;
				}
			}

			if (i > 2 && j < 4)//�밢��üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j + 1], b.arr[i - 2][j + 2], b.arr[i - 3][j + 3] };
				if (checknum(temp) == 3)
				{
					if (b.arr[i][j] == 0 && b.arr[i - 1][j] != 0) return j;
					else if (b.arr[i - 1][j + 1] == 0 && b.arr[i - 2][j + 1] != 0) return j + 1;
					else if (b.arr[i - 2][j + 2] == 0 && b.arr[i - 3][j + 2] != 0) return j + 2;
					else if (b.arr[i - 3][j + 3] == 0 && (i == 3 || b.arr[i - 4][j + 3] != 0)) return j + 3;
				}
			}

			if (i > 2)//����üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j], b.arr[i - 2][j], b.arr[i - 3][j] };
				if (checknum(temp) == 3)
				{
					return j;
				}
			}

			if (j > 2)//����üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i][j - 1], b.arr[i][j - 2], b.arr[i][j - 3] };
				if (checknum(temp) == 3)
				{
					if (b.arr[i][j] == 0 && (i == 0 || b.arr[i - 1][j] != 0)) return j;
					else if (b.arr[i][j - 1] == 0 && (i == 0 || b.arr[i - 1][j - 1] != 0)) return j - 1;
					else if (b.arr[i][j - 2] == 0 && (i == 0 || b.arr[i - 1][j - 2] != 0)) return j - 2;
					else if (b.arr[i][j - 3] == 0 && (i == 0 || b.arr[i - 1][j - 3] != 0)) return j - 3;
				}
			}

		}
	}
	return -1;
}


//RULE2: ������ �̱�� ���� ������, �� ���� �������� ������ �̱��� ���ϵ��� �Ѵ�.
int rule2(const Board& b)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i > 2 && j > 2)//�밢��üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j - 1], b.arr[i - 2][j - 2], b.arr[i - 3][j - 3] };
				if (checknum(temp) == -3)
				{
					if (b.arr[i][j] == 0 && b.arr[i - 1][j] != 0) return j;
					else if (b.arr[i - 1][j + 1] == 0 && b.arr[i - 2][j + 1] != 0) return j + 1;
					else if (b.arr[i - 2][j + 2] == 0 && b.arr[i - 3][j + 2] != 0) return j + 2;
					else if (b.arr[i - 3][j + 3] == 0 && (i == 3 || b.arr[i - 4][j + 3] != 0)) return j + 3;
				}
			}

			if (i > 2 && j < 4)//�밢��üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j + 1], b.arr[i - 2][j + 2], b.arr[i - 3][j + 3] };
				if (checknum(temp) == -3)
				{
					if (b.arr[i][j] == 0 && b.arr[i - 1][j] != 0) return j;
					else if (b.arr[i - 1][j + 1] == 0 && b.arr[i - 2][j + 1] != 0) return j + 1;
					else if (b.arr[i - 2][j + 2] == 0 && b.arr[i - 3][j + 2] != 0) return j + 2;
					else if (b.arr[i - 3][j + 3] == 0 && (i == 3 || b.arr[i - 4][j + 3] != 0)) return j + 3;
				}
			}

			if (i > 2)//����üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j], b.arr[i - 2][j], b.arr[i - 3][j] };
				if (checknum(temp) == -3)
				{
					return j;
				}
			}

			if (j > 2)//����üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i][j - 1], b.arr[i][j - 2], b.arr[i][j - 3] };
				if (checknum(temp) == -3)
				{
					if (b.arr[i][j] == 0 && (i == 0 || b.arr[i - 1][j] != 0)) return j;
					else if (b.arr[i][j - 1] == 0 && (i == 0 || b.arr[i - 1][j - 1] != 0)) return j - 1;
					else if (b.arr[i][j - 2] == 0 && (i == 0 || b.arr[i - 1][j - 2] != 0)) return j - 2;
					else if (b.arr[i][j - 3] == 0 && (i == 0 || b.arr[i - 1][j - 3] != 0)) return j - 3;
				}
			}

		}
	}
	return -1;
}

//RULE3: ������ 3���� ����� �� ���ٸ�, �� ���� ��������.
int rule3(const Board& b)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i > 2 && j > 2)//�밢��üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j - 1], b.arr[i - 2][j - 2], b.arr[i - 3][j - 3] };
				if (checknum(temp) == -2)
				{
					if (b.arr[i][j] != 0 && b.arr[i - 1][j - 1] != 0 && b.arr[i - 3][j - 2] != 0) return j - 2;
					else if (b.arr[i - 1][j - 1] != 0 && b.arr[i - 2][j - 2] != 0 && (i == 3 || b.arr[i - 4][j - 3] != 0)) return j - 3;
					else if (b.arr[i - 1][j - 1] != 0 && b.arr[i - 2][j - 2] != 0 && b.arr[i - 1][j] != 0) return j;
					else if (b.arr[i - 2][j - 2] != 0 && b.arr[i - 3][j - 3] != 0 && b.arr[i - 2][j - 1] != 0) return j - 1;
					else if (b.arr[i - 2][j - 2] != 0 && b.arr[i][j] != 0 && b.arr[i - 2][j - 1] != 0) return j - 1;
					else if (b.arr[i - 3][j - 3] != 0 && b.arr[i - 1][j - 1] != 0 && b.arr[i - 3][j - 2] != 0) return j - 2;
				}
			}

			if (i > 2 && j < 4)//�밢��üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j + 1], b.arr[i - 2][j + 2], b.arr[i - 3][j + 3] };
				if (checknum(temp) == -2)
				{
					if (b.arr[i][j] != 0 && b.arr[i - 1][j + 1] != 0 && b.arr[i - 3][j + 2] != 0) return j + 2;
					else if (b.arr[i - 1][j + 1] != 0 && b.arr[i - 2][j + 2] != 0 && (i == 3 || b.arr[i - 4][j + 3] != 0)) return j + 3;
					else if (b.arr[i - 1][j + 1] != 0 && b.arr[i - 2][j + 2] != 0 && b.arr[i - 1][j] != 0) return j;
					else if (b.arr[i - 2][j + 2] != 0 && b.arr[i - 3][j + 3] != 0 && b.arr[i - 2][j + 1] != 0) return j + 1;
					else if (b.arr[i - 2][j + 2] != 0 && b.arr[i][j] != 0 && b.arr[i - 2][j + 1] != 0) return j + 1;
					else if (b.arr[i - 3][j + 3] != 0 && b.arr[i - 1][j + 1] != 0 && b.arr[i - 3][j + 2] != 0) return j + 2;
				}
			}

			if (i > 2)//����üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j], b.arr[i - 2][j], b.arr[i - 3][j] };
				if (checknum(temp) == -2)
				{
					return j;

				}
			}

			if (j > 2)//����üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i][j - 1], b.arr[i][j - 2], b.arr[i][j - 3] };
				if (checknum(temp) == -2)
				{
					if (b.arr[i][j] != 0 && b.arr[i][j - 1] != 0 && (i == 0 || b.arr[i - 1][j - 2] != 0)) return j - 2;
					else if (b.arr[i][j - 1] != 0 && b.arr[i][j - 2] != 0 && (i == 0 || b.arr[i - 1][j - 3] != 0)) return j - 3;
					else if (b.arr[i][j - 1] != 0 && b.arr[i][j - 2] != 0 && (i == 0 || b.arr[i - 1][j] != 0)) return j;
					else if (b.arr[i][j - 2] != 0 && b.arr[i][j - 3] != 0 && (i == 0 || b.arr[i - 1][j - 1] != 0)) return j - 1;
					else if (b.arr[i][j] != 0 && b.arr[i][j - 2] != 0 && (i == 0 || b.arr[i - 1][j - 1] != 0)) return j - 1;
					else if (b.arr[i][j - 1] != 0 && b.arr[i][j - 3] != 0 && (i == 0 || b.arr[i - 1][j - 2] != 0)) return j - 2;
				}
			}

		}
	}
	return -1;
}


//RULE4: ���� 3���� ����� �� ���ٸ�, �� ���� ��������.
int rule4(const Board& b)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i > 2 && j > 2)//�밢��üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j - 1], b.arr[i - 2][j - 2], b.arr[i - 3][j - 3] };
				if (checknum(temp) == 2)
				{
					if (b.arr[i][j] != 0 && b.arr[i - 1][j - 1] != 0 && b.arr[i - 3][j - 2] != 0) return j - 2;
					else if (b.arr[i - 1][j - 1] != 0 && b.arr[i - 2][j - 2] != 0 && (i == 3 || b.arr[i - 4][j - 3] != 0)) return j - 3;
					else if (b.arr[i - 1][j - 1] != 0 && b.arr[i - 2][j - 2] != 0 && b.arr[i - 1][j] != 0) return j;
					else if (b.arr[i - 2][j - 2] != 0 && b.arr[i - 3][j - 3] != 0 && b.arr[i - 2][j - 1] != 0) return j - 1;
					else if (b.arr[i - 2][j - 2] != 0 && b.arr[i][j] != 0 && b.arr[i - 2][j - 1] != 0) return j - 1;
					else if (b.arr[i - 3][j - 3] != 0 && b.arr[i - 1][j - 1] != 0 && b.arr[i - 3][j - 2] != 0) return j - 2;
				}
			}

			if (i > 2 && j < 4)//�밢��üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j + 1], b.arr[i - 2][j + 2], b.arr[i - 3][j + 3] };
				if (checknum(temp) == 2)
				{
					if (b.arr[i][j] != 0 && b.arr[i - 1][j + 1] != 0 && b.arr[i - 3][j + 2] != 0) return j + 2;
					else if (b.arr[i - 1][j + 1] != 0 && b.arr[i - 2][j + 2] != 0 && (i == 3 || b.arr[i - 4][j + 3] != 0)) return j + 3;
					else if (b.arr[i - 1][j + 1] != 0 && b.arr[i - 2][j + 2] != 0 && b.arr[i - 1][j] != 0) return j;
					else if (b.arr[i - 2][j + 2] != 0 && b.arr[i - 3][j + 3] != 0 && b.arr[i - 2][j + 1] != 0) return j + 1;
					else if (b.arr[i - 2][j + 2] != 0 && b.arr[i][j] != 0 && b.arr[i - 2][j + 1] != 0) return j + 1;
					else if (b.arr[i - 3][j + 3] != 0 && b.arr[i - 1][j + 1] != 0 && b.arr[i - 3][j + 2] != 0) return j + 2;
				}
			}

			if (i > 2)//����üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i - 1][j], b.arr[i - 2][j], b.arr[i - 3][j] };
				if (checknum(temp) == 2)
				{
					return j;

				}
			}

			if (j > 2)//����üũ
			{
				int temp[4] = { b.arr[i][j], b.arr[i][j - 1], b.arr[i][j - 2], b.arr[i][j - 3] };
				if (checknum(temp) == 2)
				{
					if (b.arr[i][j] != 0 && b.arr[i][j - 1] != 0 && (i == 0 || b.arr[i - 1][j - 2] != 0)) return j - 2;
					else if (b.arr[i][j - 1] != 0 && b.arr[i][j - 2] != 0 && (i == 0 || b.arr[i - 1][j - 3] != 0)) return j - 3;
					else if (b.arr[i][j - 1] != 0 && b.arr[i][j - 2] != 0 && (i == 0 || b.arr[i - 1][j] != 0)) return j;
					else if (b.arr[i][j - 2] != 0 && b.arr[i][j - 3] != 0 && (i == 0 || b.arr[i - 1][j - 1] != 0)) return j - 1;
					else if (b.arr[i][j] != 0 && b.arr[i][j - 2] != 0 && (i == 0 || b.arr[i - 1][j - 1] != 0)) return j - 1;
					else if (b.arr[i][j - 1] != 0 && b.arr[i][j - 3] != 0 && (i == 0 || b.arr[i - 1][j - 2] != 0)) return j - 2;
				}
			}

		}
	}
	return -1;
}

//RULE5: claimeven - ������ �ٷ� ���� ���� ���� odd��� �� ���� even square�� �����Ѵ�.
int claimeven(const Board& b)
{
	int col = lastplayed();//������ ���� ���� column no.
	if (b.columnnum[col] % 2 == 1) //������ odd��° row�� ���� ���Ҵٸ�
		return col;
	return -1;
}

//RULE6: baseinverse - ������ �ٷ� ���� ���� ���� �ٸ� column�� �ִ� �������ִ� ���� four(�밢���̳� ����)�� �̷� ���ɼ��� �ִٸ� �� �ڸ��� �����Ѵ�.
int baseinverses(const Board& b)
{
	int col = lastplayed();//������ ���� ���� column no.
	for (int j = 0; j < 7; j++)
	{
		if (j != col && abs(col - j) < 5)
		{
			if (abs(b.columnnum[j] - b.columnnum[col]) == abs(col - j))//�밢������ four�� �̷�ٸ�
			{
				return col;
			}
			else if (b.columnnum[j] == b.columnnum[col])//���η� four�� �̷�ٸ�
			{
				return col;
			}
		}
	}
	return -1;
}

//RULE7: last - ������ �ٷ� ���� ���� ���� even�̶�� �� ���� odd square�� �����Ѵ�. ���� full�̶�� ������ column���� ������ ���� �ִ´�.
int vertical(const Board& b)
{
	int col = lastplayed();//������ ���� ���� column no.
	if (b.columnnum[col] == 2 || b.columnnum[col] == 4) //������ even��° row�� ���� ���Ҵٸ�
		return col;
	else if (b.columnnum[col] == 6)
	{
		for (int k = 1; k < 7; k++)
		{
			if (col - k >= 0 && b.columnnum[col - k] != 6)
			{
				return col - k;
			}
			else if (col + k < 7 && b.columnnum[col + k] != 6)
			{
				return col + k;
			}
		}
	}
	return -1;
}

int ruleplay(const Board& b)
{
	int checksum = 0;

	for (int i = 0; i < 7; i++)
		checksum += b.columnnum[i];

	if (checksum == 0)
		return 2;
	int result;
	if ((result = rule1(b)) != -1)
	{
		ruleused() = 1;
		return result;
	}
	else if ((result = rule2(b)) != -1)
	{
		ruleused() = 2;
		return result;
	}
	else if ((result = rule3(b)) != -1)
	{
		ruleused() = 3;
		return result;
	}
	else if ((result = rule4(b)) != -1)
	{
		ruleused() = 4;
		return result;
	}
	else if ((result = claimeven(b)) != -1)
	{
		ruleused() = 5;
		return result;
	}
	else if ((result = baseinverses(b)) != -1)
	{
		ruleused() = 6;
		return result;
	}
	else
	{
		ruleused() = 7;
		return vertical(b);
	}
}