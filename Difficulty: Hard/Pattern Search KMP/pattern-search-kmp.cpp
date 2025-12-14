void computeLPSArray(string pat, int M, int* lps) 
{ 
// Your code here
 
int len=0,i=1;
lps[0]=0;
while(i<M){
    if(pat[i]==pat[len]){ 
 
        len++;
    lps[i]=len;
            i++;
    }
    else {
        if(len==0) {
            lps[i]=0;
            i++;
        }else {
            len=lps[len-1];
        }
    }
}
} 
 
//Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) 
{
    // Your code here
    int M=pat.length();
    int N=txt.length();
    int lps[M];
    
    computeLPSArray(pat,M,lps);
    
    int i=0,j=0;
    
    while(i<N){
        if(pat[j]==txt[i])
        {
            i++;
            j++;
            
        }
        
        if(j==M){
        return true;
        }
        else if(i<N && pat[j]!=txt[i]){
            
            if(j==0)
            i++;
            else j=lps[j-1];
        }
    }
    
    return false;
    
}