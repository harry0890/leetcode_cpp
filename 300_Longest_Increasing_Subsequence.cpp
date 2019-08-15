#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Time complexity : O(n^2) Two loops of n are there.
//Space complexity : O(n). dp array of size n is used.
class DP {
public:
	int lengthOfLIS(vector<int>& nums ) {
		size_t size = nums.size();
		if( size == 0 ) return 0;

		int longest = 1;
		vector<int> lisLength(size, 1);
		for(int i=0; i<size; i++ ){
			for(int j=0; j<i; j++){
				if(nums[i] > nums[j])
					lisLength[i] = max( lisLength[i], lisLength[j] + 1 );
			}
			longest = max( longest, lisLength[i] );
		}
		return longest;
	}
};

// Time complexity : O(nlog(n)), n is lenght of nums
//Space complexity : O(n)
class BinarySearch {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;
        for (int i = 0; i < nums.size(); i++) {
            if (LIS.size() == 0 || LIS[LIS.size() - 1] < nums[i]) {
                LIS.push_back(nums[i]);
            }else {
                int l = 0, r = LIS.size() - 1;
                while (l < r) {
                    int m = (l + r) / 2;
                    if (LIS[m] >= nums[i])
                        r = m;
                    else
                        l = m + 1;
                }
                LIS[l] = nums[i];
            }
        }
        return LIS.size();
    }
};


// Time complexity : O(nlog(n)), n is lenght of nums
//Space complexity : O(n)
class Greedy {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> v;
        if(nums.empty()) return 0;
        
        v.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            int n = nums[i];
            if(n > v.back())
                v.push_back(n);
            else
                *lower_bound(v.begin(), v.end(), n) = n;
        }
        return v.size();
    }
};

// Time complexity : O(nlog(n))
//Space complexity : O(n)
class simple_solution {
public:
	int lengthOfLIS(vector<int>& nums) {
    	vector<int> res;
    	for(int i=0; i<nums.size(); i++) {
        	auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        	if(it==res.end()) res.push_back(nums[i]);
        	else *it = nums[i];
   		}
    	return res.size();
	}
};

int main(void)
{
	vector<int> input = {10,9,2,5,3,7,101,18};
	DP dp;
	Greedy greedy;
	simple_solution s;
	BinarySearch b;

	cout << "longest of LIS = " << dp.lengthOfLIS(input) << endl;
	cout << "longest of LIS = " << greedy.lengthOfLIS(input) << endl;
	cout << "longest of LIS = " << s.lengthOfLIS(input) << endl;
	cout << "longest of LIS = " << b.lengthOfLIS(input) << endl;
	return 0;
}
