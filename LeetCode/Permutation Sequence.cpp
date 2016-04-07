#include <string>
#include <vector>

using namespace std;

// 康托编码
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nums(n);
		int pCount = 1;
		for (int i = 0; i < n; ++i) {
			nums[i] = i + 1;
			pCount *= (i + 1);
		}

		k--;
		string res = "";
		for (int i = 0; i < n; i++) {
			pCount = pCount / (n - i);
			int selected = k / pCount;
			res += ('0' + nums[selected]);

			for (int j = selected; j < n - i - 1; j++)
				nums[j] = nums[j + 1];
			k = k % pCount;
		}
		return res;
	}
};

// 正常解法，但超时
class Solution {
public:
	string result;
	int count;
	string str;
	vector<bool> num;
	string getPermutation(int n, int k) {
		for (int i = 0; i<n; i++)
		{
			num.push_back(false);
		}
		for (int i = 0; i<n; i++)
		{
			str.push_back('.');
		}
		count = 0;
		permutation(n, 0, k);
		return result;
	}

	void permutation(int n, int k, int c)
	{
		if (k == n)
		{
			if (count == c - 1)
			{
				result = str;
			}
			else
			{
				count++;
			}
		}
		else
		{
			for (int i = 0; i<n; i++)
			{
				if (!num[i])
				{
					str[k] = i + '1';
					num[i] = true;
					permutation(n, k + 1, c);
					str[k] = '.';
					num[i] = false;
				}
			}
		}
	}
};

