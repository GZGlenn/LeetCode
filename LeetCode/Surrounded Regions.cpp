#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	void process(int i, int j, vector<vector<char> >& board)
	{
		int m = board.size();
		int n = board[0].size();

		typedef pair<int, int> point;
		queue<point> Q;
		Q.push(point(i, j));
		board[i][j] = 'E';
		while (!Q.empty())
		{
			point tmp = Q.front();
			Q.pop();

			int x = tmp.first, y = tmp.second;

			//extending  
			if (x != 0 && board[x - 1][y] == 'O')
			{
				Q.push(point(x - 1, y));
				board[x - 1][y] = 'E';   //extended;  
			}
			if (x != m - 1 && board[x + 1][y] == 'O')
			{
				Q.push(point(x + 1, y));
				board[x + 1][y] = 'E';   //extended;  
			}
			if (y != 0 && board[x][y - 1] == 'O')
			{
				Q.push(point(x, y - 1));
				board[x][y - 1] = 'E';   //extended;  
			}
			if (y != n - 1 && board[x][y + 1] == 'O')
			{
				Q.push(point(x, y + 1));
				board[x][y + 1] = 'E';   //extended;  
			}
		}
	}
	void solve(vector<vector<char> >& board)
	{
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		int i, j;
		for (i = 0; i<m; i++)
		{
			if (board[i][0] == 'O')
				process(i, 0, board);
			if (board[i][n - 1] == 'O')
				process(i, n - 1, board);
		}
		for (j = 0; j<n; j++)
		{
			if (board[0][j] == 'O')
				process(0, j, board);
			if (board[m - 1][j] == 'O')
				process(m - 1, j, board);
		}
		for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
		{
			if (board[i][j] == 'O')
				board[i][j] = 'X';
			else if (board[i][j] == 'E')
				board[i][j] = 'O';
		}
	}
};


//typedef pair<int, int> point;
//
//class Solution {
//public:
//	void solve(vector<vector<char>>& board) {
//		if (board.empty()) return;
//		int rows = board.size();
//		int cols = board[0].size();
//
//		for (int i = 0; i < rows; i++) {
//			if (board[i][0] == 'O') boardSetting(board, i, 0);
//			if (board[i][cols - 1] == 'O') boardSetting(board, i, cols-1);
//		}
//
//		for (int j = 0; j < cols; j++) {
//			if (board[0][j] == 'O') boardSetting(board, 0, j);
//			if (board[rows - 1][j] == 'O') boardSetting(board, rows-1, j);
//		}
//
//		for (int i = 0; i < rows; i++) {
//			for (int j = 0; j < cols; j++) {
//				if (board[i][j] == 'E') board[i][j] = 'O';
//				else if (board[i][j] == 'O') board[i][j] = 'X';
//			}
//		}
//	}
//
//	void boardSetting(vector<vector<char>>& board, int start_row, int start_col) {
//		int rows = board.size();
//		int cols = board[0].size();
//
//		queue<point> myQueue; myQueue.push(point(start_row, start_col));
//		board[start_row][start_col] = 'E';
//		while (!myQueue.empty()) {
//				point p = myQueue.front();
//				myQueue.pop();
//				if (p.first + 1 < rows && board[p.first + 1][p.second] == 'O') {
//					myQueue.push(point(p.first + 1, p.second));
//					board[p.first + 1][p.second] = 'E';
//				}
//
//				if (p.first - 1 >= 0 && board[p.first - 1][p.second] == 'O') {
//					myQueue.push(point(p.first - 1, p.second));
//					board[p.first - 1][p.second] = 'E';
//				}
//
//				if (p.second + 1 < cols && board[p.first][p.second + 1] == 'O') {
//					myQueue.push(point(p.first, p.second + 1));
//					board[p.first][p.second + 1] = 'E';
//				}
//
//				if (p.second - 1 >= 0 && board[p.first][p.second - 1] == 'O') {
//					myQueue.push(point(p.first, p.second - 1));
//					board[p.first][p.second - 1] = 'E';
//				}
//		}
//	}
//};