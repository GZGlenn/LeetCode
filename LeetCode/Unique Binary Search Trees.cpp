#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> num;
		num.push_back(1);
		for (int i = 1; i <= n; i++){
			num.push_back(0);
			if (i<3)
				num[i] = i;
			else{
				for (int j = 1; j <= i; j++)
					num[i] += num[j - 1] * num[i - j];
			}
		}
		return num[n];
	}
};