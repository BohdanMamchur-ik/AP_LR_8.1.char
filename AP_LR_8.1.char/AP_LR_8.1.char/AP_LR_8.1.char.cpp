// Алгоритмізація та програмування
// Лабораторна робота № 8.1 (стандартні функції мови С для рядків char[])
// Мамчур Богдан Тарасович ІК-12
// Варіант 9

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;


int Count(char* s);
char* Change(char* s);

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 4 identical characters." << endl;

    char* dest = new char[101];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}


int Count(char* s)
{
    size_t len = strlen(s);
    if (len < 4)
        return 0;

    int k = 0;
    size_t pos = 0;
    char* t;
    char pattern[5]; 

    while (pos <= len - 4)
    {
        
        pattern[0] = pattern[1] = pattern[2] = pattern[3] = s[pos];
        pattern[4] = '\0';

       
        if (strncmp(s + pos, pattern, 4) == 0)
        {
            k++;
            pos += 4;
        }
        else
        {
           
            t = strchr(s + pos + 1, s[pos]);
            if (t != NULL && (size_t)(t - s) == pos + 1)
                pos++;
            else
                pos++;
        }
    }
    return k;
}


char* Change(char* s)
{
    size_t len = strlen(s);
    if (len < 4)
        return s;

    char* t = new char[len + 1];
    *t = '\0';

    size_t pos1 = 0;
    char pattern[5];
    char* p;

    while (pos1 <= len - 4)
    {
        pattern[0] = pattern[1] = pattern[2] = pattern[3] = s[pos1];
        pattern[4] = '\0';

        
        p = strstr(s + pos1, pattern);
        if (p != NULL)
        {
            size_t matchPos = p - s;
           
            strncat(t, s + pos1, matchPos - pos1);
            
            strcat_s(t, len + 1, "**");
            pos1 = matchPos + 4;
        }
        else
        {
            pos1++;
        }
    }

    
    *t = '\0';
    pos1 = 0;
    while (pos1 <= len - 4)
    {
        pattern[0] = pattern[1] = pattern[2] = pattern[3] = s[pos1];
        pattern[4] = '\0';

        if (strncmp(s + pos1, pattern, 4) == 0)
        {
            strcat(t, "**");
            pos1 += 4;
        }
        else
        {
            strncat(t, s + pos1, 1);
            pos1++;
        }
    }

    
    strcat(t, s + pos1);
    strcpy_s(s, len + 1, t);
    return t;
}