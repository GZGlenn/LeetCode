#include <vector>

using namespace std;

// faster
class Solution {
public:
	bool isValid(vector<vector<char>> &board, vector<vector<bool>> &visit, int x, int y) {
		int m = board.size(), n = board[0].size();
		if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y]) return false;
		return true;
	}

	bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visit, string word, int idx, int x, int y) {
		if (idx == word.length()) return true;
		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };
		visit[x][y] = true;
		int xx, yy;
		for (int i = 0; i < 4; ++i) {
			xx = x + dx[i]; yy = y + dy[i];
			if (isValid(board, visit, xx, yy) && board[xx][yy] == word[idx] && dfs(board, visit, word, idx + 1, xx, yy)) {
				return true;
			}
		}
		visit[x][y] = false;
		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return false;
		int m = board.size();
		if (m == 0) return false;
		int n = board[0].size();
		if (n == 0) return false;
		vector<vector<bool>> visit(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == word[0] && dfs(board, visit, word, 1, i, j)) return true;
			}
		}
		return false;
	}
};


typedef pair<int, int> point;

class Solution1 {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || word.empty()) return false;
		if (board.size() == 1 && board[0].size() == 1) {
			if (word.size() != 1) return false;
			if (word[0] == board[0][0]) return true;
			return false;
		}

		vector<vector<bool>> isUsed(board.size());
		for (int i = 0; i < board.size(); i++)
			isUsed[i] = vector<bool>(board[i].size(),false);

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					isUsed[i][j] = true;
					if (backtrack(board, word, isUsed, point(i, j), 1))
						return true;
					isUsed[i][j] = false;
				}
			}
		}
		return false;
	}

	bool backtrack(vector<vector<char>> &board, string word, 
		vector<vector<bool>> &isUsed, point pos, int start) {
		if (start >= word.size()) return true;

		vector<point> p = getWayToGo(board, word, isUsed, pos, start);

		if (p.size() == 0) return false;

		for (int i = 0; i < p.size(); i++) {
			isUsed[p[i].first][p[i].second] = true;
			if (backtrack(board, word, isUsed, p[i], start + 1)) return true;
			isUsed[p[i].first][p[i].second] = false;
		}

		return false;
	}

	vector<point> getWayToGo(vector<vector<char>> &board, string word,
		vector<vector<bool>> &isUsed, point pos, int start) {

		vector<point> result;
		int rows = isUsed.size(), cols = isUsed[0].size();

		if (rows == 1) {
			if (pos.second == 0) {
				if (!isUsed[pos.first][pos.second + 1] &&
					word[start] == board[pos.first][pos.second + 1])
					result.push_back(point(pos.first, pos.second+1));
			}
			else if (pos.second == cols - 1) {
				if (!isUsed[pos.first][pos.second - 1] &&
					word[start] == board[pos.first][pos.second - 1])
					result.push_back(point(pos.first, pos.second - 1));
			}
			else {
				if (!isUsed[pos.first][pos.second + 1] &&
					word[start] == board[pos.first][pos.second + 1])
					result.push_back(point(pos.first, pos.second + 1));

				if (!isUsed[pos.first][pos.second - 1] &&
					word[start] == board[pos.first][pos.second - 1])
					result.push_back(point(pos.first, pos.second - 1));
			}
		}

		else if (cols == 1) {
			if (pos.first == 0) {
				if (!isUsed[pos.first + 1][pos.second] &&
					word[start] == board[pos.first + 1][pos.second])
					result.push_back(point(pos.first + 1, pos.second));
			}
			else if (pos.first == rows - 1) {
				if (!isUsed[pos.first - 1][pos.second] &&
					word[start] == board[pos.first - 1][pos.second])
					result.push_back(point(pos.first - 1, pos.second));
			}
			else {
				if (!isUsed[pos.first - 1][pos.second] &&
					word[start] == board[pos.first - 1][pos.second])
					result.push_back(point(pos.first - 1, pos.second));

				if (!isUsed[pos.first + 1][pos.second] &&
					word[start] == board[pos.first + 1][pos.second])
					result.push_back(point(pos.first + 1, pos.second));
			}

		}

		else {
			// four corner
			if (pos.first == 0 && pos.second == 0) {
				if (!isUsed[pos.first + 1][pos.second] &&
					word[start] == board[pos.first + 1][pos.second])
					result.push_back(point(pos.first + 1, pos.second));

				if (!isUsed[pos.first][pos.second + 1] &&
					word[start] == board[pos.first][pos.second + 1])
					result.push_back(point(pos.first, pos.second + 1));
			}
			else if (pos.first == rows - 1 && pos.second == 0) {
				if (!isUsed[pos.first - 1][pos.second] &&
					word[start] == board[pos.first - 1][pos.second])
					result.push_back(point(pos.first - 1, pos.second));

				if (!isUsed[pos.first][pos.second + 1] &&
					word[start] == board[pos.first][pos.second + 1])
					result.push_back(point(pos.first, pos.second + 1));
			}
			else if (pos.first == rows - 1 && pos.second == cols - 1) {
				if (!isUsed[pos.first - 1][pos.second] &&
					word[start] == board[pos.first - 1][pos.second])
					result.push_back(point(pos.first - 1, pos.second));

				if (!isUsed[pos.first][pos.second - 1] &&
					word[start] == board[pos.first][pos.second - 1])
					result.push_back(point(pos.first, pos.second - 1));
			}
			else if (pos.first == 0 && pos.second == cols - 1) {
				if (!isUsed[pos.first + 1][pos.second] &&
					word[start] == board[pos.first + 1][pos.second])
					result.push_back(point(pos.first + 1, pos.second));

				if (!isUsed[pos.first][pos.second - 1] &&
					word[start] == board[pos.first][pos.second - 1])
					result.push_back(point(pos.first, pos.second - 1));
			}

			// four edge
			else if (pos.first == 0) {
				if (!isUsed[pos.first + 1][pos.second] &&
					word[start] == board[pos.first + 1][pos.second])
					result.push_back(point(pos.first + 1, pos.second));

				if (!isUsed[pos.first][pos.second + 1] &&
					word[start] == board[pos.first][pos.second + 1])
					result.push_back(point(pos.first, pos.second + 1));

				if (!isUsed[pos.first][pos.second - 1] &&
					word[start] == board[pos.first][pos.second - 1])
					result.push_back(point(pos.first, pos.second - 1));

			}
			else if (pos.first == rows - 1) {
				if (!isUsed[pos.first - 1][pos.second] &&
					word[start] == board[pos.first - 1][pos.second])
					result.push_back(point(pos.first - 1, pos.second));

				if (!isUsed[pos.first][pos.second + 1] &&
					word[start] == board[pos.first][pos.second + 1])
					result.push_back(point(pos.first, pos.second + 1));

				if (!isUsed[pos.first][pos.second - 1] &&
					word[start] == board[pos.first][pos.second - 1])
					result.push_back(point(pos.first, pos.second - 1));
			}
			else if (pos.second == cols - 1) {
				if (!isUsed[pos.first - 1][pos.second] &&
					word[start] == board[pos.first - 1][pos.second])
					result.push_back(point(pos.first - 1, pos.second));

				if (!isUsed[pos.first + 1][pos.second] &&
					word[start] == board[pos.first + 1][pos.second])
					result.push_back(point(pos.first + 1, pos.second));

				if (!isUsed[pos.first][pos.second - 1] &&
					word[start] == board[pos.first][pos.second - 1])
					result.push_back(point(pos.first, pos.second - 1));
			}
			else if (pos.second == 0) {
				if (!isUsed[pos.first + 1][pos.second] &&
					word[start] == board[pos.first + 1][pos.second])
					result.push_back(point(pos.first + 1, pos.second));

				if (!isUsed[pos.first - 1][pos.second] &&
					word[start] == board[pos.first - 1][pos.second])
					result.push_back(point(pos.first - 1, pos.second));

				if (!isUsed[pos.first][pos.second + 1] &&
					word[start] == board[pos.first][pos.second + 1])
					result.push_back(point(pos.first, pos.second + 1));
			}

			// basic
			else {
				if (!isUsed[pos.first + 1][pos.second] &&
					word[start] == board[pos.first + 1][pos.second])
					result.push_back(point(pos.first + 1, pos.second));

				if (!isUsed[pos.first][pos.second + 1] &&
					word[start] == board[pos.first][pos.second + 1])
					result.push_back(point(pos.first, pos.second + 1));

				if (!isUsed[pos.first - 1][pos.second] &&
					word[start] == board[pos.first - 1][pos.second])
					result.push_back(point(pos.first - 1, pos.second));

				if (!isUsed[pos.first][pos.second - 1] &&
					word[start] == board[pos.first][pos.second - 1])
					result.push_back(point(pos.first, pos.second - 1));

			}
		}
		return result;
	}
};