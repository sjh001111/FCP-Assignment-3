#include <stdio.h>
#include "../user.h"
#include "binary_search.h"

int binary_search(User users[], int count, int search)
{
   int first, last, middle;
   first = 0;
   last = count - 1;
   middle = (first + last) / 2;

   while (first <= last)
   {
      if (users[middle].ID < search)
         first = middle + 1;
      else if (users[middle].ID == search)
         return middle;
      else
         last = middle - 1;
      middle = (first + last) / 2;
   }

   return -1;
}