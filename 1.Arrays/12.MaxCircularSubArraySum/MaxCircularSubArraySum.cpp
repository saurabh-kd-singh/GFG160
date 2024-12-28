#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int circularSubarraySum(vector<int> &arr)
{
    int currMinSum = arr[0], minSum = arr[0], currMaxSum = arr[0], maxSum = arr[0], n = arr.size();

    // totalSum
    int totalSum = accumulate(begin(arr), end(arr), 0);

    // minSum
    for (int i = 1; i < n; i++)
    {
        currMinSum = min(currMinSum + arr[i], arr[i]);
        minSum = min(minSum, currMinSum);
    }

    // maxSum
    for (int i = 1; i < n; i++)
    {
        currMaxSum = max(currMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, currMaxSum);
    }

    int circSum = totalSum - minSum;
    if (maxSum > 0)
    {
        return max(circSum, maxSum);
    }
    return maxSum;
}

int main()
{
    vector<int> prices = {7, -1, -5, 3, -6, 4};
    int result = circularSubarraySum(prices);
    cout << result;
    return 0;
}