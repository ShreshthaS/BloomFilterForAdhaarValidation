#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

uint32_t murmur3_32(const uint32_t* key, size_t len, uint32_t seed)
{
uint32_t h1=seed;
if(len>3)
{
const uint32_t* key_x4= (const uint32_t*) key;
size_t i=len>>2;
do{
uint32_t k1=*key_x4++;
k1*=0xcc9e2d51;
k1=(k1<<15)|(k1>>17);
k1*=0x1b873593;
h1^=k1;
h1=(h1<<13)|(h1>>19);
h1=(h1*5)+0xe6546b64;
}
while(--i);
key=(const uint32_t*) key_x4;
}
if(len&3)
{
size_t i=len&3;
uint32_t k1=0;
key=&key[i-1];
do{
k1 <<=8;
k1 |= *key--;
}
while(--i);
k1*=0xcc9e2d51;
k1=(k1<<15)|(k1>>17);
k1*=0x1b873593;
h1^=k1;
}
h1^=len;
h1^=h1>>16;
h1*= 0x85ebca6b;
h1^=h1>>13;
h1*= 0xc2b2ae35;
h1^=h1>>16;
return h1;
}

int main()
{
uint32_t seed=99;
size_t len=12;
uint32_t p= 857394758392;
const uint32_t* key= &p;
uint32_t h1=murmur3_32(key,len,seed);
printf("The hash value of 857394758392 is %hhu ",h1);
return 0;
}
