
#define FNV_PRIME_32 16777619
#define FNV_OFFSET_32 2166136261U


uint32_t FNV32(uint64_t n1,size_t len)
{ 

uint32_t A[len],i,k;
uint64_t j;

uint32_t hash = FNV_OFFSET_32;

for(i=len;i>0;i--)
{

j=n1%10;
A[i]=j;
n1=n1/10;

}

      for(k=1;k<=len;k++)
      { 
        hash = hash ^ (A[k]); // xor next byte into the bottom of the hash
        hash = hash * FNV_PRIME_32; // Multiply by prime number found to work well
      }

    return hash;
} 


