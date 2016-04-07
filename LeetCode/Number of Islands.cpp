#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> point;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;

		int rows = grid.size();
		int cols = grid[0].size();

		int islandNum = 0;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i][j] == '1') {
					islandNum++;
					bfsIsland(grid, i, j);
				}
			}
		}

		return islandNum;
	}

	void bfsIsland(vector<vector<char>>& grid, int startRow, int startCol) {
		grid[startRow][startCol] = '2';
		int rows = grid.size();
		int cols = grid[0].size();

		queue<point> Q;
		Q.push(point(startRow, startCol));

		while (!Q.empty()) {
			point p = Q.front();
			Q.pop();

			if (p.first + 1 < rows && grid[p.first + 1][p.second] == '1') {
				Q.push(point(p.first + 1, p.second));
				grid[p.first + 1][p.second] = '2';
			}

			if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == '1') {
				Q.push(point(p.first - 1, p.second));
				grid[p.first - 1][p.second] = '2';
			}

			if (p.second + 1 < cols && grid[p.first][p.second + 1] == '1') {
				Q.push(point(p.first, p.second + 1));
				grid[p.first][p.second + 1] = '2';
			}

			if (p.second - 1 >= 0 && grid[p.first][p.second - 1] == '1') {
				Q.push(point(p.first, p.second - 1));
				grid[p.first][p.second - 1] = '2';
			}
		}
	}
};