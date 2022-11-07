//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            int[] ans = new Solve().findTwoElement(a, n);
            System.out.println(ans[0] + " " + ans[1]);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solve {
    static void swap(int[]arr,int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    int[] findTwoElement(int arr[], int n) {
        int[] ans = new int[2];
        //1.repeating
        //2. missing
        
        int i=0;
        
        
        while(i<n){
            if(arr[i] == arr[arr[i] - 1]){
                i++;
            }
            else{
                swap(arr,i,arr[i]-1);
            }
        }
        
        for(int k=0;k<n;k++){
            if(arr[k] != k+1){
                ans[0] = arr[k];
                ans[1] = k+1;
            }
        }
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
}