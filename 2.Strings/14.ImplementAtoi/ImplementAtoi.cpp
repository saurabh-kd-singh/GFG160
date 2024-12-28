#include <vector>
#include <iostream>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;

int myAtoi(char *s)
{
    int i = 0;
    int n = strlen(s); // Use strlen for char*
    long result = 0;
    int sign = 1;

    // Step 1: Skip leading whitespaces
    while (i < n && s[i] == ' ')
    {
        i++;
    }

    // Step 2: Check for the sign
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Read digits and construct the number
    while (i < n && isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');

        // Handle overflow
        if (result > INT_MAX)
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        i++;
    }

    // Step 4: Return the result with the appropriate sign
    return sign * result;
}

int main()
{
    char input[] = "-123";
    cout << myAtoi(input) << endl;
    return 1;
}