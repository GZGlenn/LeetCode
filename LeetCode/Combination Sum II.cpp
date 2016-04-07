#include <vector>
#include <algorithm>

using namespace std;

// 有一点需要注意，如何避免重复。如果两个数相同，
// 我们先用前一个数，只有当前一个数用了，这个数才能使用。
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty()) return vector<vector<int>>();

		sort(candidates.begin(), candidates.end());

		vector<vector<int>> result;
		dfs(candidates, target, result, vector<int>(),
			0, vector<bool>(candidates.size(), false));
		return result;
	}

	void dfs(vector<int> &candidiates, int target, vector<vector<int>> &result,
		vector<int> curr, int index, vector<bool> isUsed) {
		if (target < 0) return;
		if (target == 0) {
			result.push_back(curr);
			return;
		}

		for (int i = index; i < candidiates.size(); i++) {
			if (target < candidiates[i]) return;
			if (i != 0 && candidiates[i] == candidiates[i - 1] && !isUsed[i - 1])
				continue;
			curr.push_back(candidiates[i]);
			isUsed[i] = true;
			dfs(candidiates, target - candidiates[i], result, curr, i + 1, isUsed);
			curr.pop_back();
			isUsed[i] = false;
		}
	}
};

//
class Solution1 {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		DFS(candidates, target, 0);
		return result;
	}

	void DFS(vector<int> candidates, int target, int start){
		if (target == 0)
			result.push_back(temp);
		else
		for (int i = start; i < candidates.size(); ++i){
			if (target < candidates.at(i))
				return;
			temp.push_back((candidates.at(i)));
			DFS(candidates, target - candidates.at(i), i + 1);
			temp.pop_back();
			while (i + 1 < candidates.size() && candidates.at(i) == candidates.at(i + 1))
				++i;
		}
	}
private:
	vector<vector<int>> result;
	vector<int> temp;
};