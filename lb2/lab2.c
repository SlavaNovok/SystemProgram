#include <stdio.h>

int main ()

{
  int arr[10] = {64, 4, 65, 32, 128, 16, 96, 48, 80, 15};
  int s = 0;
  int i;

  for (i=0; i<=9; i++)
    {
      if (((arr[i] & 64)==64))
        {
           arr[i] >>=1;
           s=arr[i]+s;
        }
        else
        {
           s=arr[i]+s;
        }
    }
    printf("sum: %d \n", s);
    return 0;
}
