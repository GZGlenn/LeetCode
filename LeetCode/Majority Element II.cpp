#include <vector>

using namespace std;

struct counter {
	int element;
	int time;
	counter(int e, int t) :element(e), time(t){}
};

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		if (nums.size() < 2) return nums;

		counter counter1(nums[0], 1), counter2(0, -1);
		for (int i = 1; i < nums.size(); i++) {
			if (counter1.element == nums[i]) counter1.time++;

			else if (counter2.time < 0) {
				counter2.element = nums[i];
				counter2.time = 1;
			}

			else if (counter2.element == nums[i]) counter2.time++;

			else if (counter1.time == 0) {
				counter1.element = nums[i];
				counter1.time = 1;
			}

			else if (counter2.time == 0) {
				counter2.element = nums[i];
				counter2.time = 1;
			}

			else {
				counter1.time--;
				counter2.time--;
			}
		}

		int time1 = 0, time2 = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == counter1.element) time1++;
			else if (nums[i] == counter2.element) time2++;
		}

		vector<int> result;
		if (time1 > nums.size() / 3.0) result.push_back(counter1.element);
		if (time2 > nums.size() / 3.0) result.push_back(counter2.element);

		return result;
	}
};