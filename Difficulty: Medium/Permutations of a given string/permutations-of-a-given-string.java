//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            String S = br.readLine().trim();
            Solution obj = new Solution();
            List<String> ans = obj.find_permutation(S);
            for( int i = 0; i < ans.size(); i++)
            {
                out.print(ans.get(i)+" ");
            }
            out.println();
                        
        }
        out.close();
	}
}


// } Driver Code Ends



class Solution {
    
    //private static List<String> list;
    
    private String swap(String s, int l,int r){
        char[]chars=s.toCharArray();
        char temp=chars[l];
        chars[l]=chars[r];
        chars[r]=temp;
        
        return String.valueOf(chars);
    }
    
    public void find_permutation(String str,int start,int end, List<String> list) {
        
        if(start == end && !list.contains(str)){
            list.add(str);
        }
        else{
            
            for(int i= start;i<end;i++){
                str=swap(str, start,i);
                find_permutation(str, start+1,end,list);
                str=swap(str,start,i);
            }
        }
        
    }
    public List<String> find_permutation(String S) {
        List<String> list= new ArrayList<>();
        find_permutation(S, 0,S.length(),list);
        Collections.sort(list);
        return list;
    }
}