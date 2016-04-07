#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty()) return vector<vector<int>>();

		int N = nums.size();
		if (N == 1) {
			return vector<vector<int>>(1,vector<int>(1,nums[0]));
		}

		vector<vector<int>> result;
		for (int i = 0; i < nums.size(); i++) {
			vector<int> dummyNums(nums);
			dummyNums.erase(dummyNums.begin()+i);
			vector<vector<int>> temp = permute(dummyNums);
			for (int j = 0; j < temp.size(); j++) {
				temp[j].insert(temp[j].begin(), nums[i]);
				result.push_back(temp[j]);
			}
		}

		return result;
	}

};

// 递归改成了while
class Solution1 {
public:
	int factorial(int n){
		return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
	}

	void plusp(vector<int> &p, const vector<int> &bound){
		int i = p.size() - 1;
		while (i >= 0){
			if (p[i] < bound[i]){
				p[i]++;
				break;
			}
			else{
				p[i] = 0;
				i--;
			}
		}

	}



	vector<vector<int> > permute(vector<int> &num) {
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		vector<vector<int> > ret;
		vector<int> ori_num = num;
		vector<int> tmp = num;

		int N = num.size();

		vector<int> p(N, 0);

		vector<int> bound = num;
		for (int i = 0; i < N; i++){
			bound[i] = N - 1 - i;
		}

		for (int i = 0; i < factorial(N); i++){
			num = ori_num;
			for (int j = 0; j < N; j++){
				tmp[j] = num[p[j]];
				num.erase(num.begin() + p[j]);
			}
			ret.push_back(tmp);
			plusp(p, bound);

		}

		return ret;

	}
};

// 最快
class Solution2 {
public:
	void nextPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  

		//5,4,7,5,3,2  
		//    |   |  
		//    i   j  
		//5,5,7,4,3,2  
		//5,5,2,3,4,7  
		int i = num.size() - 1;
		while (i > 0 && num[i - 1] >= num[i]){
			i--;
		}

		int j = i;

		while (j < num.size() && num[j] > num[i - 1]) j++;

		if (i == 0){
			reverse(num.begin(), num.end());
		}
		else{
			swap(num[i - 1], num[j - 1]);
			reverse(num.begin() + i, num.end());
		}


	}

	int factorial(int n){
		return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
	}


	vector<vector<int> > permute(vector<int> &num) {
		// Start typing your C/C++ solution below  
		// DO NOT write int main() function  
		int N = num.size();
		vector<vector<int> > ret;

		ret.push_back(num);

		for (int i = 1; i < factorial(N); i++){
			nextPermutation(num);
			ret.push_back(num);
		}

		return ret;

	}
};
