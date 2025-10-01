int countSetBits(int n)
{
    int count = 0;
    while(n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

class Solution {
  public:
    int minVal(int a, int b) {

        b = countSetBits(b) - countSetBits(a);
        
        int ans = a;

 

// From the below two for loops, only one will run depending on whether the bits in b are more or in a is more.

 

// This runs when number of bits in b is more
        for(int i = 0; i <= 31 && b > 0; i++)
        {
            if((1 << i) & ans) continue;
            else 
            {
                ans += (1 << i);
                b--;
            }
        }

// This runs when number of bits in a is more

        for(int i = 0; i <= 31 && b < 0; i++)
        {
            if((1 << i) & ans) 
            {
                ans -= (1 << i);
                b++;
            }
        }
        return ans;
    }
};