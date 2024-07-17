#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

int LetterList(char letter, int row_value ,int column_value)
{
    char SetArray[6][8] = {
    {'B','F','P','V'},
    {'C','G','J','K','Q','S','X','Z'},
    {'D','T'},
    {'L'},
    {'M','N'},
    {'R'}
    };

     for (int i = 0; i < column_value; i++)
    {
        if (letter == SetArray[row_value][i])
        {
            return 1;
            break;
        }
    }
    return 0;
}


char ValueCheck6(char c)
{
    int row_value = 5;
    int column_value = 1;
    char letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '6';
    }
    else
    {
        return '0';
    }
}


char ValueCheck5(char c)
{
    int row_value = 4;
    int column_value = 2;
    char letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '5';
    }
    else
    {
        return ValueCheck6(c);
    }
}


char ValueCheck4(char c)
{
    int row_value = 3;
    int column_value = 1;
    char letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '4';
    }
    else
    {
        return ValueCheck5(c);
    }
}


char ValueCheck3(char c)
{
    int row_value = 2;
    int column_value = 2;
    char letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '3';
    }
    else
    {
        return ValueCheck4(c);
    }
}
char ValueCheck2(char c)
{
    int row_value = 1;
    int column_value = 8;
    char letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '2';
    }
    else
    {
        return ValueCheck3(c);
    }
}


char ValueCheck1(char c)
{
    int row_value = 0;
    int column_value = 4;
    char letter = toupper(c);
    if (LetterList(letter,row_value,column_value) == 1)
    {
        return '1';
    }
    else
    {
        return ValueCheck2(c);
    }
}

char getSoundexCode(char c){ 
    return ValueCheck1(c);

}
#endif // SOUNDEX_H
