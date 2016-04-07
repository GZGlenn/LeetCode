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
				stmax = i; //stmax�����洢��ǰ���е���ʼ��
			}
			else max += diff;
			if (max > MAX){
				MAX = max;
				stMAX = stmax; //stmax�����洢������е���ʼ��
			}

			if (min > 0) min = diff;
			else min += diff;
			if (min < MIN){
				MIN = min;
				endMIN = i; //endMIN�����洢��С���е�ĩβ��
			}
		}
		return total < 0 ? -1 : (MAX >= (total - MIN) ? stMAX : (endMIN + 1) % gas.size()); //ͨ���Ƚ� MAX �� (total - MIN) ������Ӧ�����
	}
};