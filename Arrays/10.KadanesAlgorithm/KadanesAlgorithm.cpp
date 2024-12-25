#include <vector>
#include <iostream>
#include <map>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = nums[0], maximumSum = nums[0];

    int i = 1;
    while (i < nums.size())
    {
        if (sum < 0)
        {
            sum = 0;
            sum = sum + nums[i];
        }
        else
        {
            sum = sum + nums[i];
        }
        maximumSum = max(maximumSum, sum);

        i++;
    }

    return maximumSum;
}

int main()
{
    vector<int> prices = {2, 3, -8, 7, -2, 6, 4};
    int answer = maxSubArray(prices);
    cout << answer;
    return 0;
}