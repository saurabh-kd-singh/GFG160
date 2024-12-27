#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int smallestPositiveMissingNumber(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int x = nums[i]; // x = current element

        // x>=1 && x<=n : to check if x is in range[1, n]
        // x != i+1 : skip if at index i correct element is present.
        // nums[x-1]!=x: skip if at index x-1 correct element is present
        while (x >= 1 && x <= n && x != i + 1 && nums[x - 1] != x)
        {
            swap(nums[x - 1], nums[i]);
            x = nums[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == i + 1)
            continue;
        return i + 1;
    }

    return n + 1;
}

int main()
{
    vector<int> prices = {7, 1, -5, 3, -6, 4};
    int result = smallestPositiveMissingNumber(prices);
    cout << result;
    return 0;
}