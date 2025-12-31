class Solution {
public:
    long long int killinSpree(long long int n)
    {
       long long dem=0; 
       long long int i=1;  
       
       while(n-i*i>=0) { 
           dem++; 
           n=n-i*i; 
           i++;
       }  

       return dem;
    }
};