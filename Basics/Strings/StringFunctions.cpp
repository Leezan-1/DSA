#include <iostream>
#include <string>
using namespace std;

string reverseString(string str)
{
    string reverse_str;
    for (size_t i = 0; str[i] != '\0'; i++)
        reverse_str = str[i] + reverse_str;

    return reverse_str;
}

int stringLength(string str)
{
    int length = 0;
    for (auto i = str.begin(); i != str.end(); i++)
        length++;

    return length;
}

bool checkPalindrome(string str)
{
    string reverse_str = reverseString(str);
    return (str.compare(reverse_str) == 0) ? true : false;
}

void countVowels(string str)
{
    int vowels = 0, consonants = 0;
    for (auto i = str.begin(); i < str.end(); i++)
    {
        if (*i == 'a' or *i == 'e' or *i == 'i' or *i == 'o' or *i == 'u' or *i == 'A' or *i == 'E' or *i == 'I' or *i == 'O' or *i == 'U')
            vowels++;
        else
            consonants++;
    }
    cout << "Vowels: " << vowels << endl
         << "Consonants: " << consonants << endl;
}

void charFrequency(string str)
{

    int freq[256] = {0};
    cout << "Character Frequency of :" << str << endl;
    for (auto i = str.begin(); i < str.end(); i++)
        freq[*i]++;

    for (size_t i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
            cout << char(i) << " : " << freq[i] << "\t";
    }
    cout << endl;
}

void stringCompression(string str)
{

    int freq[256] = {0};
    for (auto i = str.begin(); i < str.end(); i++)
        freq[*i]++;

    for (size_t i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
            cout << char(i) << freq[i];
    }
    cout << endl;
}

bool checkAnagram(string str1, string str2)
{
    int freq_of_str1[256] = {0};
    int freq_of_str2[256] = {0};

    for (auto i = str1.begin(); i < str1.end(); i++)
        freq_of_str1[*i]++;

    for (auto i = str2.begin(); i < str2.end(); i++)
        freq_of_str2[*i]++;

    for (size_t i = 0; i < 256; i++)
    {
        if (freq_of_str1[i] > 0 or freq_of_str2[i] > 0)
            if (freq_of_str1[i] != freq_of_str2[i])
                return false;
    }
    return true;
}

bool checkPangram(std::string sentence)
{
    bool alphabet[26] = {false};
    int count = 0;
    for (char ch : sentence)
    {
        if (std::isalpha(ch))
        {
            int index = std::tolower(ch) - 'a';
            if (!alphabet[index])
            {
                count++;
                alphabet[index] = true;
            }
        }
    }
    return (count == 26) ? true : false;
}

int main()
{
    string s = "hahahahah";
    cout << "String: " << s << endl;
    cout << "Reverse of string: " << reverseString(s) << endl;
    cout << "String length: " << stringLength(s) << endl;

    string boolean = checkPalindrome(s) ? "yes" : "no";
    cout << "Is it a palindrome?: " << boolean << endl;

    countVowels(s);
    charFrequency(s);

    string str1 = "listen", str2 = "silent";
    boolean = checkAnagram(str1, str2) ? "yes" : "no";
    cout << "Is '" << str1 << "' and '" << str2 << "' a anagram?: " << boolean << endl;

    string sentence = "The quick brown fox jumps over a lazy dog";
    boolean = checkPangram(sentence) ? "yes" : "no";
    cout << "Is sentence '" << sentence << "' pangram?: " << boolean << endl;
}