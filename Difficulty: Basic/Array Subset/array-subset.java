//{ Driver Code Starts
//Initial Template for Java

//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            StringTokenizer stt = new StringTokenizer(br.readLine());
            
            long n = Long.parseLong(stt.nextToken());
            long m = Long.parseLong(stt.nextToken());
            long a1[] = new long[(int)(n)];
            long a2[] = new long[(int)(m)];
            
            
            String inputLine[] = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a1[i] = Long.parseLong(inputLine[i]);
            }
            String inputLine1[] = br.readLine().trim().split(" ");
            for (int i = 0; i < m; i++) {
                a2[i] = Long.parseLong(inputLine1[i]);
            }
            
            
            Compute obj = new Compute();
            System.out.println(obj.isSubset( a1, a2, n, m));
            
        }
	}
}

// } Driver Code Ends




class Compute {
    public String isSubset( long a1[], long a2[], long n, long m) {
        if(n<m)
        isSubset(a2,a1,m,n);
        Map<Long,Long> map=new HashMap<>();
        for(long x:a1)
        map.put(x,map.getOrDefault(x,0L)+1);
        for(long x:a2)
        {
            if(!map.containsKey(x))
            return "No";
            map.put(x,map.get(x)-1);
            if(map.get(x)==0)
            map.remove(x);
            
        }
        return "Yes";
        
    }
}