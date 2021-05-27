#include "../user.h"
#include "binary_search.h"

//search by binary search algorithm
int binary_search(User users[], int count, int search)
{
   int start, end, center;
   start = 0;
   end = count - 1;
   center = (start + end) / 2;
   
   /* Divides in half and compares until 
    *the center matches searching value*/
   while (start <= end)
   {
      if (users[center].ID < search)
         start = center + 1;
      else if (users[center].ID == search)
         return center;
      else
         end = center - 1;
      center = (start + end) / 2;
   }

   return -1;
}
