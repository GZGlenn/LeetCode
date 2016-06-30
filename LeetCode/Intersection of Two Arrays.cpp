#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;

		if (nums1.size() == 0 || nums2.size() == 0) return result;

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
			if (nums1[i] < nums2[j]) i++;
			else if (nums1[i] > nums2[j]) j++;
			else {
				if (result.empty() || result.back() != nums1[i]) result.push_back(nums1[i]);
				i++; j++;
			}

		}
		return result;
	}
};