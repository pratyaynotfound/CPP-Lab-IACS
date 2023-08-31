#include "stack.h"
#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end)
{
  /*TO DO*/
}

int find_next_start(char str[], int len, int i)
{
  /*TO DO*/
  return -1;
}

int find_next_end(char str[], int len, int i)
{
  /*TO DO*/
  return -1;
}

void reverse_words(char s[])
{
  int len = strlen(s);
  int k = 0;
  for (int i = 0; i <= len; i++)
  {
    // push the char whaen it is alphaneumeric character
    if (isalnum(s[i]) && i!=len)
    {
      push(s[i]);
      k++;
    }
    // if alphaneumeric character is not encountered rearrange the substring
    else
    {
      while (k > 0)
      {
        s[i - k] = pop();
        k--;
      }
    }
  }
}