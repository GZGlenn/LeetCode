#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	// 检查一个字符串是否为回文
	bool check_palindrome(string s)
	{
		int size = s.size();
		for (int i = 0; i < size / 2; i++)
		{
			if (s[i] != s[size - i - 1])
			{
				return false;
			}
		}

		return true;
	}

	void find_partition_sln(string s,
		vector<string> &sln,
		vector<vector<string> > &result)
	{
		// 边界结束条件
		if (s.size() == 0)
		{
			// 能到这，说明找到了一个可能的解，前面的子串都是符合条件的
			result.push_back(sln);
		}

		int size = s.size();

		// 把字符串从第一个位置到最后一个位置，依次进行分隔
		// 并在每一种情况下，利用深度搜索找到合适的解
		for (int i = 1; i <= size; i++)
		{
			string front;
			string remain;

			front.assign(s, 0, i);
			remain.assign(s, i, size - i);

			if (check_palindrome(front))
			{
				// front符合条件
				sln.push_back(front);

				// 寻找以front开头的可行解，深度优先
				find_partition_sln(remain, sln, result);

				// 重新开始下一个查找
				sln.pop_back();
			}
		}
	}

	vector<vector<string> > partition(string s) {

		vector<string> sln;
		vector<vector<string> > result;

		find_partition_sln(s, sln, result);

		return result;
	}
};

// Time Limit out
//class Solution {
//public:
//	vector<vector<string>> partition(string s) {
//		vector<vector<string>> result = vector<vector<string>>();
//		if (s.empty()) {
//			result.push_back(vector<string>());
//			return result;
//		}
//
//		int** isPalindrome = new int*[s.size()];
//		for (int i = 0; i < s.size(); i++) {
//			isPalindrome[i] = new int[s.size()];
//			for (int j = 0; j < s.size(); j++)
//				isPalindrome[i][j] = 0;
//		}
//
//		findAllPalindrome(s, isPalindrome);
//
//		vector<string> temp = vector<string>();
//		getAllSubString(s, isPalindrome, result, temp, 0);
//
//		return result;
//	}
//
//	void findAllPalindrome(string s, int** isPalindrome) {
//		for (int i = s.size() - 1; i >= 0; i--) {
//			for (int j = i; j < s.size(); j++) {
//				if (i == j) isPalindrome[i][j] = 1;
//				else if (s[i] == s[j]){
//					if (i + 1 == j || isPalindrome[i + 1][j - 1] == 1)
//						isPalindrome[i][j] = 1;
//				}
//			}
//		}
//	}
//
//	void getAllSubString(string s, int** isPalindrome, vector<vector<string>>& result,
//		vector<string> temp, int begin) {
//		if (begin >= s.size()) {
//			result.push_back(temp);
//			//	return;
//		}
//
//		for (int i = begin; i < s.size(); i++) {
//			cout << begin << " " << i << " " << isPalindrome[begin][i]
//				<< " " << temp.size() << endl;
//			if (isPalindrome[begin][i] == 1) {
//				temp.push_back(s.substr(begin, i - begin + 1));
//				getAllSubString(s, isPalindrome, result, temp, i + 1);
//			}
//
//			temp.clear();
//		}
//	}
//};