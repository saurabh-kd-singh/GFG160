#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string trimLeadingZeros(string s)
{
    size_t firstOne = s.find('1');
    return (firstOne != string::npos) ? s.substr(firstOne) : "0";
}

string addBinary(string &s1, string &s2)
{
    // Trim leading zeros
    s1 = trimLeadingZeros(s1);
    s2 = trimLeadingZeros(s2);

    int n = s1.size();
    int m = s2.size();

    // Swap the strings if s1 is smaller than s2
    if (n < m)
    {
        swap(s1, s2);
        swap(n, m);
    }

    int j = m - 1, carry = 0;
    string result = "";

    // Traverse both strings from the end
    for (int i = n - 1; i >= 0; --i)
    {
        int bit1 = s1[i] - '0';
        int bitSum = bit1 + carry;

        if (j >= 0)
        {
            int bit2 = s2[j--] - '0';
            bitSum += bit2;
        }

        result += (bitSum % 2) + '0';
        carry = bitSum / 2;
    }

    // If there's carry left, add it to the result
    if (carry)
    {
        result += '1';
    }

    // Reverse the result to get the final binary sum
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string s1 = "1001";
    string s2 = "1010";
    cout << addBinary(s1, s2) << endl;
    return 1;
}