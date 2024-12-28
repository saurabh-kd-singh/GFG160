#include <vector>
#include <iostream>
using namespace std;

void reverseArray(vector<int> &arr, int left, int right)
{
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotateArr(vector<int> &arr, int k)
{
    k = k % (arr.size());
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, arr.size() - 1);
    reverseArray(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    int k = 2;
    rotateArr(arr, k);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}