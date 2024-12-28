#include <vector>
#include <iostream>
using namespace std;

void swap(vector<int> &arr, int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void pushZerosToEnd(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right;

    while (arr[left] != 0 && left < n)
    {
        left++;
    }

    if (left < n - 1)
    {
        right = left + 1;

        for (int i = left; i < n; i++)
        {
            if (arr[left] == 0)
            {
                if (right < n)
                {
                    if (arr[right] != 0)
                    {
                        swap(arr, left, right);
                        left++;
                        right++;
                    }
                    else
                    {
                        while (arr[right] == 0 && right < n)
                        {
                            right++;
                        }
                    }
                }
            }
            else
            {
                left++;
                right++;
            }
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}