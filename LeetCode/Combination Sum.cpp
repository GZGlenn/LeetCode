#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty()) return vector<vector<int>>();

		sort(candidates.begin(), candidates.end());

		vector<vector<int>> result;
		dfs(candidates, target, vector<int>(), result, 0);
		return result;
	}

	void dfs(vector<int>& candidates, int target, vector<int> curr, 
		vector<vector<int>> &result, int start) {
		if (target == 0) {
			result.push_back(curr); 
			return;
		}

		for (int i = start; i < candidates.size(); i++) {
			if (target < candidates[i]) continue;
			curr.push_back(candidates[i]);
			dfs(candidates, target-candidates[i], curr, result, i);
			curr.pop_back();
		}
	}
};

class Solution1 {
private:
	const int index_count;
	vector<vector<int> > results;
public:
	Solution1() : index_count(10000) {};
	// index记录当前找到的候选数字，n表示当前正在找第几个，n是index的下标不是candidates的下标  
	void backtrace(int target, int sum, vector<int> &candidates, int index[], int n)
	{
		if (sum > target)
		{
			return; // 回溯  
		}
		if (sum == target)
		{
			vector<int> result;
			for (int i = 1; i <= n; ++i)
			{
				result.push_back(candidates[index[i]]);
			}
			results.push_back(result);
			return; // 此处可以不加，如果不加return由于都是正整数，到下面的计算时会多进行一次无用的递归。  
		}

		// 深度搜索，为了避免重复，每次从当前候选项索引到结尾，上面的i=index[n]可以看出  
		for (int i = index[n]; i < candidates.size(); ++i)
		{
			index[n + 1] = i; // 记录当前考察的候选项索引  
			backtrace(target, sum + candidates[i], candidates, index, n + 1);
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		sort(candidates.begin(), candidates.end());

		int *index = new int[index_count];
		memset(index, 0, sizeof(int)*index_count);

		results.clear();    // 提交到leetcode的测试系统上必须添加，它应该是使用一个对象测试所有测试用例。  
		backtrace(target, 0, candidates, index, 0);

		delete[] index;

		return results;
	}
};