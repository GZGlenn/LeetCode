#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if (gas.size() != cost.size()) return -1;
		if (gas.size() == 0) return -1;
		int MAX = gas[0] - cost[0], MIN = gas[0] - cost[0], max = gas[0] - cost[0], min = gas[0] - cost[0];
		int stmax = 0, stMAX = 0, endMIN = 0;
		int total = 0, diff = 0;
		for (int i = 0; i < gas.size(); ++i){
			diff = gas[i] - cost[i];
			total += diff;

			if (max < 0){
				max = diff;
				stmax = i; //stmax用来存储当前序列的起始点
			}
			else max += diff;
			if (max > MAX){
				MAX = max;
				stMAX = stmax; //stmax用来存储最大序列的起始点
			}

			if (min > 0) min = diff;
			else min += diff;
			if (min < MIN){
				MIN = min;
				endMIN = i; //endMIN用来存储最小序列的末尾点
			}
		}
		return total < 0 ? -1 : (MAX >= (total - MIN) ? stMAX : (endMIN + 1) % gas.size()); //通过比较 MAX 和 (total - MIN) 返回相应结果。
	}
};