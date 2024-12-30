#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool areAnagrams1(string &s, string &t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

bool areAnagrams2(string str1, string str2)
{
    // If lengths differ, they cannot be anagrams
    if (str1.length() != str2.length())
    {
        return false;
    }

    // Create a frequency array for 26 letters of the alphabet
    int freq[26] = {0};

    // Increment frequencies for characters in str1
    for (char c : str1)
    {
        freq[c - 'a']++;
    }

    // Decrement frequencies for characters in str2
    for (char c : str2)
    {
        freq[c - 'a']--;
    }

    // Check if all frequencies are zero
    for (int count : freq)
    {
        if (count != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s1 = "geeks";
    string s2 = "skege";
    cout << areAnagrams1(s1, s2) << endl;
    return 1;
}