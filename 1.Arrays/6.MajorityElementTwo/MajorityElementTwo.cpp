#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> findMajority(vector<int> &arr)
{
    vector<int> answer;
    int count1 = 0, count2 = 0, element1, element2;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count1 == 0 && element2 != arr[i])
        {
            element1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0 && element1 != arr[i])
        {
            element2 = arr[i];
            count2 = 1;
        }
        else if (arr[i] == element1)
        {
            count1++;
        }
        else if (arr[i] == element2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    vector<int> result;
    int threshold = arr.size() / 3;

    count1 = 0, count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (element1 == arr[i])
        {
            count1++;
        }
        else if (element2 == arr[i])
        {
            count2++;
        }
    }

    if (count1 > threshold)
    {
        answer.push_back(element1);
    }
    if (count2 > threshold)
    {
        answer.push_back(element2);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 3, 3};
    vector<int> result = findMajority(arr);

    // Just printing results
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << ", "; // Add a comma and space for all but the last element
        }
    }
    cout << "]";

    return 0;
}
