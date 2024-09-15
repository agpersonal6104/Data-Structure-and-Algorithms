#include <iostream>
#include <vector>
#include<map>
using namespace std;

// Brute Force
class Solution
{
    public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> ret;
        int size = nums.size();
        for (int i = 0; i < size-1 ; i++)
        {
            for(int j = i+1 ; j< size ; j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
                
            }
        }
        return ret;
    }
};

// Optimised

class Solution
{
    public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> ret;
        int size = nums.size();
        int diff;
        unordered_map<int, int>m;
        for (int i = 0; i < size; i++)
        {
            diff=target-nums[i];
        }
        if(m.find)
    }
}