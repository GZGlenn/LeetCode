#include<vector>
#include<iostream>
#include<set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int split = 0;
		int sum = 0;

		set<int> myset;
		set<int>::iterator it;

		while (sum != 1)
		{
			do
			{
				split = n % 10;
				n = n / 10;
				sum = split* split + sum;
			} while (n>0);

			if (sum == 1) {
				break;
			}
			else {
				it = myset.find(sum);
				if (it != myset.end())
				{
					return false;
				}
				myset.insert(sum);
				n = sum;
				sum = 0;
			}
		}

		return true;
	}
};