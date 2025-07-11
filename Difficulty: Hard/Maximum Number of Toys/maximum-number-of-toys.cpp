//Back-end complete function Template for C++

const int N=1e6+5;
int fr[N]; //array to store frequency of elements

class tree{
public:
  vector<long long> bit; //Binary Indexed Tree
  tree(){
    bit=vector<long long>(N); //initialize BIT
  }
  void add(int node,int v)
  {
     for(;node<N;node+=(node&(-node)))
      bit[node]+=v; //updating BIT by adding v to each element
  }
  long long get(int node)
  {
    long long x=0;
    for(;node>0;node-=(node&(-node)))
      x+=bit[node]; //sum of elements in BIT
    return x;
  }
};
tree obj1,obj2; //creating two instances of tree

class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
    vector<int> res;

    for(auto i:A){
      fr[i]++; //counting frequency of each element in A array
    }

    for(int i=0;i<A.size();i++){
      obj1.add(A[i],A[i]); //adding elements to bit1
      obj2.add(A[i],1); //adding 1 to bit2 for each element
    }

    for(auto i:Queries){
      long long C=i[0]; //value of C
      for(int j=2;j<i.size();j++){
        obj1.add(A[i[j]-1],-A[i[j]-1]); //removing element from bit1
        obj2.add(A[i[j]-1],-1); //decrementing 1 from bit2
      }

      long long lw=1,hg=1e6; //lower bound and higher bound
      long long pos=1e6; //position
      while(lw<=hg){
        int mid=(lw+hg)/2;
        if(obj1.get(mid)>=C){ //check if sum of elements till mid is greater or equal to C
          pos=mid;
          hg=mid-1;
        }
        else{
          lw=mid+1;
        }
      }

      long long ans=obj2.get(pos-1); //get sum till position-1 from bit2
      long long mx=min((C-obj1.get(pos-1))/pos,(long long)fr[pos]); //find maximum possible sum
      ans+=mx; //add maximum sum to ans
      res.push_back(ans); //push answer to res
      for(int j=2;j<i.size();j++){
        obj1.add(A[i[j]-1],A[i[j]-1]); //add element back to bit1
        obj2.add(A[i[j]-1],1); //add 1 to bit2
      }
    }
    for(int i=0;i<A.size();i++){
      obj1.add(A[i],-A[i]); //remove element from bit1
      obj2.add(A[i],-1); //decrement 1 from bit2
      fr[A[i]]--; //decrement frequency of element in fr array
    }
    return res; //return result
  }
};