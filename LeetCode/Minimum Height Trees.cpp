#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
	struct TreeNode {
		set<int> list;
		bool isLeaf(){ return list.size() == 1; }
	};
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 1) return{ 0 };

		vector<TreeNode> tree(n);
		for (int i = 0; i < edges.size(); i++) {
			tree[edges[i].first].list.insert(edges[i].second);
			tree[edges[i].second].list.insert(edges[i].first);
		}

		vector<int> curLeaf;
		vector<int> nextLeaf;

		for (int i = 0; i < n; i++) {
			if (tree[i].isLeaf()) curLeaf.push_back(i);
		}

		while (true) {
			for (int i = 0; i < curLeaf.size(); i++) {
				for (set<int>::iterator iter = tree[curLeaf[i]].list.begin();
					iter != tree[curLeaf[i]].list.end(); iter++) {
					tree[*iter].list.erase(curLeaf[i]);
					if (tree[*iter].isLeaf())
						nextLeaf.push_back(*iter);
				}
			}

			if (nextLeaf.empty()) {
				break;
			}

			curLeaf.clear();
			swap(curLeaf, nextLeaf);
		}

		return curLeaf;
	}
};