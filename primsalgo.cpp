#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int SpanningTree(int V, vector<vector<int>> obj[])
    {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int> vis(V,0);
        pq.push({0,0});
        while (pq.empty())
        {
            auto it=pq.top();
        }
        
    }
};