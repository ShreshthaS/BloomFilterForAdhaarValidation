#include<stdlib.h>
#include<inttypes.h>
#include <stdint.h>
#define FNV_PRIME_32 16777619
#define FNV_OFFSET_32 2166136261U
#include<stdio.h>
#include<stdlib.h>
#ifndef SCNu8
#define SCNu8 "hhu"
#endif

uint32_t FNV32(uint64_t n1,size_t len)
{ 

uint32_t A[len],i,k;
uint64_t j;
//int count=0;
uint32_t hash = FNV_OFFSET_32;
/* while(n!=0)
{
n=n/10;
++count;
}

while(n1!=0)*/
for(i=len;i>0;i--)
{

j=n1%10;
A[i]=j;
n1=n1/10;

}
/*}
for(k1=1;k1<=len;k1++){
printf("%d\n",A[k1]);}*/
      for(k=1;k<=len;k++)
      { 
        hash = hash ^ (A[k]); // xor next byte into the bottom of the hash
        hash = hash * FNV_PRIME_32; // Multiply by prime number found to work well
      }

    return hash;
} 
int main()
{
//int B[1000];
//int index;

uint64_t n,n1,n2;
uint32_t h2=0;
int i,count=0;
size_t len=12;
while(1)
{
printf("enter your choice\n");
scanf("%d",&i);
switch(i)
{
case 1:
printf("Enter a no to hash\n");
scanf("%lu",&n);
n1=n;
n2=n;
/*while(n!=0)
{
n=n/10;
++count;
}
len=count;
//printf("%lu",len);*/

h2= FNV32(n1,len);
printf("The fnv hash value of %lu is %u \n",n2,h2);
h2=0;
//index=h2%(int) sizeof(A)/sizeof(A[0]);
break;
default:
printf("No other operation available. Thank you\n");
}
}

return 0;
}
