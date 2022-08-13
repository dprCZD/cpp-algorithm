#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

/**
* 1. Two Sum
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* You can return the answer in any order.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size();i++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {i, it->second};
            }
            map[nums[i]] = i;
        }
        return {};

    }
};

int main() {
    Solution s;
    vector<int> data{ 3,2,4 };
    vector<int> res = s.twoSum(data, 6);
    for (int num : res) {
        cout << num << endl;
    }

}