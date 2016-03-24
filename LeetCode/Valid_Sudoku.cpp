#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		int rowValid[10] = { 0 };//�����ж�ĳһ���Ƿ�Ϸ�
		int columnValid[10] = { 0 };//�����ж�ĳһ���Ƿ�Ϸ�
		int subBoardValid[10] = { 0 };//�����ж�ĳһ���Ź����Ƿ�Ϸ�
		for (int i = 0; i < 9; i++)
		{
			memset(rowValid, 0, sizeof(rowValid));
			memset(columnValid, 0, sizeof(columnValid));
			memset(subBoardValid, 0, sizeof(subBoardValid));
			for (int j = 0; j < 9; j++)
			{
				if (!checkValid(rowValid, board[i][j] - '0') ||
					!checkValid(columnValid, board[j][i] - '0') ||
					!checkValid(subBoardValid, board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] - '0'))
					return false;
			}
		}
		return true;
	}
	bool checkValid(int vec[], int val)
	{
		if (val < 0)return true;//��Ӧ�����ַ���.��
		if (vec[val] == 1)return false;
		vec[val] = 1;
		return true;
	}
};