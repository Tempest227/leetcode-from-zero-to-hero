class Solution {
public:
    class mycmp{
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计元素出现的频率
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        //对频率排序，定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pri_que;
        //用固定大小为k的小顶堆，扫描所有频率的数值
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++)
        {
            pri_que.push(*it);
            if (pri_que.size() > k)
            {
                pri_que.pop();//如果堆的大小大于k，则队列弹出，保证堆的大小为k
            }
        }
        //找出前k个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};