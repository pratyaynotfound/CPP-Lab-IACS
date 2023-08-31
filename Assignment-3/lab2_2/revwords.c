#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end)
{
  while (start < end)
  {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

// find the next word starting point
int find_next_start(char str[], int len, int i)
{
  for (int j = i; j < len; j++)
  {
    if ((j == -1) || (!isalnum(str[j]) && isalnum(str[j + 1])))
    {
      return j + 1;
    }
  }
  return -1;
}

int find_next_end(char str[], int len, int i)
{
  for (int k = i; k < len; k++)
  {
    if (!isalnum(str[k]))
    {
      return k - 1;
    }
    else if (k == len - 1)
    {
      return k;
    }
  }
  return -1;
}

void reverse_words(char s[])
{
  int i = -1;
  int len = strlen(s);
  do
  {
    int start = find_next_start(s, len, i);
    int end = find_next_end(s, len, start);
    reverse_substring(s, start, end);
    if (start == -1)
      break;
    i = end + 1;
  } while (i + 1 < len);
}
