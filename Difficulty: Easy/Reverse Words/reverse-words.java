//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            String s = sc.next();
            Solution obj = new Solution();
            System.out.println(obj.reverseWords(s));
            t--;
        }
    }
}

// } Driver Code Ends




class Solution 
{
    //Function to reverse words in a given string.
    String reverseWords(String S)
    {
        // code here 
        char str [] = S.toCharArray();
        int start = 0;
        for(int end = 0; end<str.length; end ++){
            if(str[end]=='.'){
                rev(str, start, end-1);
                start = end +1;
            }
        }
        rev(str, start, str.length-1);
        rev(str, 0, str.length-1);
        return  new String(str);
    }
    static void rev(char str[], int start, int end){
        char temp;
        while(start<end){
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start ++;
            end --;
        }
    }
}