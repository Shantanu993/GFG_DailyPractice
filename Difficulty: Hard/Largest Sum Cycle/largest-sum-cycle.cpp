class Solution
{
  public:
    long long largestSum =-1;
    void dfs(int i,vector<int> &vis1,vector<int> &vis2,vector<int> &Edge){
        vis1[i]=1;
        vis2[i]=1;
        
        if(Edge[i]!=-1){
            int temp=Edge[i];
            if(!vis1[temp]){
                dfs(temp,vis1,vis2,Edge);
                
            }
            else if(vis2[temp]){
                int temp2=temp;
                long long curSum=0;
                
                do{
                    curSum+=temp2;
                    temp2=Edge[temp2];
                    
                }while(temp2!=temp);
                
                largestSum=max(largestSum,curSum);
                
            }
            
            
        }
        vis2[i]=0;
        return;
        
    }
    
    
    
    long long largestSumCycle(int N, vector<int> Edge)
    {
        // code here
        vector<int> vis1(N,0);
        vector<int> vis2(N,0);
      
        for(int i=0;i<N;i++){
            if(!vis1[i])
                dfs(i,vis1,vis2,Edge);
        }
        
        return largestSum;
      
    }
};