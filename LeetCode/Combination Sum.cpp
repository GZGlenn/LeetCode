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
	// index��¼��ǰ�ҵ��ĺ�ѡ���֣�n��ʾ��ǰ�����ҵڼ�����n��index���±겻��candidates���±�  
	void backtrace(int target, int sum, vector<int> &candidates, int index[], int n)
	{
		if (sum > target)
		{
			return; // ����  
		}
		if (sum == target)
		{
			vector<int> result;
			for (int i = 1; i <= n; ++i)
			{
				result.push_back(candidates[index[i]]);
			}
			results.push_back(result);
			return; // �˴����Բ��ӣ��������return���ڶ�����������������ļ���ʱ������һ�����õĵݹ顣  
		}

		// ���������Ϊ�˱����ظ���ÿ�δӵ�ǰ��ѡ����������β�������i=index[n]���Կ���  
		for (int i = index[n]; i < candidates.size(); ++i)
		{
			index[n + 1] = i; // ��¼��ǰ����ĺ�ѡ������  
			backtrace(target, sum + candidates[i], candidates, index, n + 1);
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		sort(candidates.begin(), candidates.end());

		int *index = new int[index_count];
		memset(index, 0, sizeof(int)*index_count);

		results.clear();    // �ύ��leetcode�Ĳ���ϵͳ�ϱ�����ӣ���Ӧ����ʹ��һ������������в���������  
		backtrace(target, 0, candidates, index, 0);

		delete[] index;

		return results;
	}
};