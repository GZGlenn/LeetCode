#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	int data;
	int pos;
};

bool operator<(const Node& a, const Node& b) {
	return a.data <= b.data;
}


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;
		vector<int> result = vector<int>();

		vector<Node> nodes = vector<Node>(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			Node node = { nums[i], i };
			nodes[i] = node;
		}

		sort(nodes.begin(), nodes.end());
		while (start < end) {
			if (nodes[start].data + nodes[end].data == target) {
				result.push_back(nodes[start].pos);
				result.push_back(nodes[end].pos);
				break;
			}
			else if (nodes[start].data + nodes[end].data > target) {
				end--;
			}
			else if (nodes[start].data + nodes[end].data < target) {
				start++;
			}
		}
		return result;
	}
};