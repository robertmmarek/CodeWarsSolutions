#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void move_left(char* s, int size)
{
  char* temp = (char*)malloc((size)*sizeof(char));
  
  int i;
  temp[size-1] = s[0];
  for(i=1; i < size; i++)
  {
    temp[i-1] = s[i];
  }
  
  memcpy((void*)s, (void*)temp, (size)*sizeof(char));
  free((void*)temp);

}

void reverse(char* s, int size)
{
  char* temp = (char*)malloc((size)*sizeof(char));
  
  int i;
  for(i=size-1; i >= 0; i--)
  {
    temp[size-1-i] = s[i];
  }
  
  memcpy((void*)s, (void*)temp, sizeof(char)*(size));
  free((void*)temp);
  
}

int test(char* s, int size)
{
  int ret = 0;
  
  //48 = ASCII 0
  long int sum = 0;
  int i;
  for(i=0; i < size; i++)
  {
    sum += (s[i]-48)*(s[i]-48);
  }
  
  if (!(sum % 2)) ret = 1;
  
  return ret;
}

char* revrot(char* s, int sz) {
   int s_len = strlen(s);
   int ret_len = 1;
 
   if(s_len > 0) ret_len = s_len;
   char* ret = malloc((s_len+1)*sizeof(char));
   
   
   if(sz <= 0 || s_len == 0 || sz > s_len)
   {
     ret = "";
   }
   else
   {
     int i;
     int number_of_blocks = s_len/sz;
     ret[number_of_blocks*sz] = '\0';
     memcpy((void*)ret, (void*)s, number_of_blocks*sz*sizeof(char));
     for(i=0; i<number_of_blocks; i++)
     {
       if(test(&ret[i*sz], sz))
       {
         reverse(&ret[i*sz], sz);
       }
       else
       {
         move_left(&ret[i*sz], sz);
       }
     }
     
   }
   
   return ret;
}