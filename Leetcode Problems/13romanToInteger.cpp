// 13. Roman to Integer
void romanToIntDisplay(string test_case)
{
    static int case_no = 0;
    Solution roman_to_int_solution;

    cout << "\nCase " << ++case_no << ":\n";
    cout << "Input a = " << test_case << endl;

    int output = roman_to_int_solution.romanToInt(test_case);
    cout << "Output: " << output << endl;
}

int Solution::mapSymbol(char sym)
{
    int value = 0;
    switch (sym)
    {
    case 'I':
        value = 1;
        break;

    case 'V':
        value = 5;
        break;

    case 'X':
        value = 10;
        break;

    case 'L':
        value = 50;
        break;

    case 'C':
        value = 100;
        break;

    case 'D':
        value = 500;
        break;

    case 'M':
        value = 1000;
        break;
    }
    return value;
}

int Solution::romanToInt(string s)
{
    int result = 0, a, b;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        a = mapSymbol(s[i]), b = mapSymbol(s[i + 1]);
        if (a < b)
            result -= mapSymbol(s[i]);

        else
            result += mapSymbol(s[i]);
    }

    result += mapSymbol(b);
    return result;
}