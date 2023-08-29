#include "stack.h"
#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end)
{
  for(int i = start;i<=end;i++){
    
  }
}

int find_next_start(char str[], int len, int i)
{
  int k = i;
  while (k < len)
  {
    if (isalnum(str[k]))
      return k + 1;
    k++;
  }
  return -1;
}

int find_next_end(char str[], int len, int i)
{
  int k = find_next_start(str, len, i);
  while (k < len)
  {
    if (str[k] == ' ' || str[k] == '\n')
      return k;
    k++;
  }
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
