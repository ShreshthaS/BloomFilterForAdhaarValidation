#include<stdio.h>
#include<stdint.h>
#include <time.h>
#include<stdlib.h>
#include<inttypes.h>
#include <string.h>
#include <math.h>
#include "murmur.c"
#include "fnv.c"
#define SIZE 10000
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ClearBit(A,m) (A[(k/32)]&=~(1<<(k%32)))
uint64_t n1,n2,p,p1;
uint32_t h1=0,h2=0,h11=0,h22=0,seed=1;
int false_prob=0;
int i,count=0,k,k1=2,A[SIZE], ind_murmur,ind_fnv;
size_t len=12;
int i, Access=9567, user_choice,Admin_choice;
void insert(uint64_t p)
{
uint64_t* key= &p;
n1=p;
n2=p;
h1=murmur3_32(key,len,seed);
h2= FNV32(n1,len);
ind_murmur=h1%(int) sizeof(A)/sizeof(A[0]);
ind_fnv=h2%(int) sizeof(A)/sizeof(A[0]);
printf(ANSI_COLOR_GREEN"The murmur hash of Aadhar no %lu is stored at index %d" ANSI_COLOR_RESET"\n",n1,ind_murmur);
printf(ANSI_COLOR_GREEN"The fnv hash of Aadhar no %lu is stored at index %d"ANSI_COLOR_RESET "\n\n",n2,ind_fnv);
printf(ANSI_COLOR_GREEN "Insertion is successful."ANSI_COLOR_RESET"\n\n\n");
//h1=0;
//h2=0;
A[ind_murmur]=1;
A[ind_fnv]=1;


}
/*The false positive probability is the power of count of no of bits turned on divided by the no of bits in filter 
to the no of hash functions we are using */
int count_1s(int A[])
{
for(i=0;i<SIZE;i++)
{
if(A[i]==1)
{
count++;
}
}
return count;
}
void membership(uint64_t p1, int ind_murmur, int ind_fnv)
{
int ind_murmur1,ind_fnv1;
uint64_t* key1= &p1;
h11=murmur3_32(key1,len,seed);
h22= FNV32(p1,len);
ind_murmur1=h11%(int) sizeof(A)/sizeof(A[0]);
ind_fnv1=h22%(int) sizeof(A)/sizeof(A[0]);
A[ind_murmur]=1;
A[ind_fnv]=1;
if(A[ind_murmur1]==A[ind_murmur] && A[ind_fnv1]==A[ind_fnv])
{
false_prob=round((pow(count_1s(A)/SIZE,2))*100);

printf("Aadhar No. %lu may be in the filter\n",p1);
printf(ANSI_COLOR_GREEN"The false positive probability is %d"ANSI_COLOR_RESET "\n\n\n",false_prob);

}
else
{
printf(ANSI_COLOR_GREEN"Aadhar No. do not exist in the filter"ANSI_COLOR_RESET"\n\n\n");
}
}
int main()
{
clock_t start,end;
double cpu_time;
start=clock();
for(k=0;k<SIZE;k++)
{
ClearBit(A,k);
}
while(1)
{
a:
printf("Select The Type of Access.\n");
printf("*********************************************************\n");
printf("1.Admin.\n2.User.\n");
printf("*********************************************************\n");
scanf("%d",&i);
switch(i)
{
case 1:
printf("Please Verify yourself to make changes.\n");
printf("Enter the Admin Access key.\n");
printf("*********************************************************\n");
scanf("%d",&Access);
if(Access==9567)
{
printf(ANSI_COLOR_GREEN"Thank you for verification."ANSI_COLOR_RESET"\n\n\n");
while(1)
{
printf("*********************************************************\n");
printf("Enter The Operation to perform.\n");
printf("*********************************************************\n");
printf("1.About.\n2.Test Membership.\n3.Insert into filter.\n4.Go to Main Menu.\n5.Exit.\n");
printf("*********************************************************\n\n\n");
scanf("%d",&Admin_choice);
switch(Admin_choice)
{
case 1:
printf(ANSI_COLOR_GREEN"Bloom Filter,A probabilistic data structure that allows us to ask set membership queries,\nwith an answer that either an item is *definitely not* in the set;\nor that an item *might be* in the set.\nIn technical terms, we are guaranteed that there will be no *false negatives*,\nat the cost of introducing *false positives*.\nBloom filters are useful when,checking with database is too expensive.\nHere,only Admin can insert the data into the Bloom Filter with the help of access key.\nOn inserting the data, we get the index of the bloom filter\nwhich is calculated using FNV and MURMUR Hash algorithms.\nWhile other users can test for the membership test\nwhether the data is present valid in the bloom filter.\nWe also get the probability of false positives for the query."ANSI_COLOR_RESET"\n\n\n");

break;
case 2: 
printf("Enter the Aadhar no. to test membership.\n");
printf("*********************************************************\n");
scanf("%lu",&p1);
membership(p1,ind_murmur,ind_fnv);
break;
case 3:
printf("Enter Aadhar no. to insert into the filter.\n");
printf("*********************************************************\n");
scanf("%lu",&p);
insert(p);
break;
case 4:
goto a;
break;
case 5:
printf("Exit.\n");
end=clock();
cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
printf(ANSI_COLOR_GREEN"The running time of the system is %f."ANSI_COLOR_RESET"\n",cpu_time);
printf("*********************************************************\n");
exit(0);
break;
default:
printf("Exit\n");
end=clock();
cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
printf(ANSI_COLOR_GREEN"The running time of the system is %f."ANSI_COLOR_RESET"\n",cpu_time);
printf("*********************************************************\n");
exit(0);
}
}
}
else
{
printf(ANSI_COLOR_GREEN"Sorry! wrong Access key. Try Again."ANSI_COLOR_RESET"\n\n\n");
goto a;
}

break;
case 2:
while(1)
{
printf("*********************************************************\n");
printf("Enter your choice.\n");
printf("*********************************************************\n");
printf("1.About.\n2.Test Membership.\n3.Go to main Menu.\n4.Exit.\n");
printf("*********************************************************\n\n\n");
scanf("%d",&user_choice);
switch(user_choice)
{
case 1:
printf(ANSI_COLOR_GREEN"Bloom Filter,A probabilistic data structure that allows us to ask set membership queries,\nwith an answer that either an item is *definitely not* in the set;\nor that an item *might be* in the set.\nIn technical terms, we are guaranteed that there will be no *false negatives*,\nat the cost of introducing *false positives*.\nBloom filters are useful when,checking with database is too expensive.\nHere,only Admin can insert the data into the Bloom Filter with the help of access key.\nOn inserting the data, we get the index of the bloom filter\nwhich is calculated using FNV and MURMUR Hash algorithms.\nWhile other users can test for the membership test\nwhether the data is present valid in the bloom filter.\nWe also get the probability of false positives for the query."ANSI_COLOR_RESET"\n\n\n");
break;
case 2:
printf("Enter the Aadhar no. to test membership.\n");
printf("*********************************************************\n");
scanf("%lu",&p1);
membership(p1,ind_murmur,ind_fnv);
break;
case 3:
goto a;
break;
case 4:
printf("Exit\n");
end=clock();
cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
printf(ANSI_COLOR_GREEN"The running time of the system is %f."ANSI_COLOR_RESET"\n",cpu_time);
printf("*********************************************************\n");
exit(0);
break;
default:
printf("Exit\n");
end=clock();
cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
printf(ANSI_COLOR_GREEN"The running time of the system is %f."ANSI_COLOR_RESET"\n",cpu_time);
printf("*********************************************************\n");
exit(0);
}
}
break;
default:
printf("Exit.\n");
end=clock();
cpu_time=(double)(end-start)/CLOCKS_PER_SEC;
printf(ANSI_COLOR_GREEN"The running time of the system is %f."ANSI_COLOR_RESET"\n",cpu_time);

printf("*********************************************************\n");
exit(0);
}
}

return 0;
}

