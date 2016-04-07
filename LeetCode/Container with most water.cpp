#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.empty()) return 0;
		if (height.size() == 1) return height[0];

		int left = 0, right = height.size() - 1;
		int minLen = min(height[left], height[right]);
		int maxContain = minLen * (right - left);
		
		int tempH, tempArea;
		while (left < right) {
			if (height[left] < height[right]) {
				left++;
				if (height[left] > minLen) {
					tempH = min(height[left], height[right]);
					tempArea = tempH * (right - left);
					if (tempArea > maxContain) {
						maxContain = tempArea;
					}
					minLen = tempH;
				}
			}
			else {
				right--;
				if (height[right] > minLen) {
					tempH = min(height[left], height[right]);
					tempArea = tempH * (right - left);
					if (tempArea > maxContain) {
						maxContain = tempArea;
					}
					minLen = tempH;
				}
			}
		}

		return maxContain;
	}

};