#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty()) return 0;

		int* temp = new int[obstacleGrid.size()* obstacleGrid[0].size()];
		int** uniquePath = new int*[obstacleGrid.size()];
		for (int i = 0; i < obstacleGrid.size(); i++) {
			uniquePath[i] = temp + i*obstacleGrid[0].size();
		}

		uniquePath[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

		for (int i = 1; i < obstacleGrid.size(); i++)
			uniquePath[i][0] = obstacleGrid[i][0] == 1 ? 0 : uniquePath[i-1][0];
		
		for (int i = 1; i < obstacleGrid[0].size(); i++)
			uniquePath[0][i] = obstacleGrid[0][i] == 1 ? 0 : uniquePath[0][i-1];

		for (int i = 1; i < obstacleGrid.size(); i++) 
			for (int j = 1; j < obstacleGrid[0].size(); j++) {
				if (obstacleGrid[i][j] == 0)
					uniquePath[i][j] = uniquePath[i - 1][j] + uniquePath[i][j - 1];
				else
					uniquePath[i][j] = 0;
		}

		return uniquePath[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};