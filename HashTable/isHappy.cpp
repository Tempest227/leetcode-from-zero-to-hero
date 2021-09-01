class Solution {
public:
    int getSum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> result;
        
        while(1)
        {
            if (n == 1)
            {
                return true;
            }
            else if (result.find(n) != result.end())
            {
                return false;
            }
            else
            {
                result.insert(n);
                n = getSum(n);
            }
        }
        return false;
    }
};