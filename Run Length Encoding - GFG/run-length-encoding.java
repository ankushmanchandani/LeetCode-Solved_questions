//{ Driver Code Starts
import java.util.*;
 
class RLEncoding
{
   public static void main(String[] args) 
   {
 
      Scanner sc = new Scanner(System.in);
    
	  int T = sc.nextInt();
	  sc.nextLine();
	  while(T>0)
	  {
		  
		String str = sc.nextLine();
		
		GfG g = new GfG();
		System.out.println(g.encode(str));
		
      
        T--;
	  }
   }
}


// } Driver Code Ends


class GfG
 {
	String encode(String str)
	{
         StringBuilder sb = new StringBuilder("");
         
         for(int i=0; i<str.length(); i++){
             Integer count = 1;
             while(i<str.length()-1 && str.charAt(i) == str.charAt(i+1)){
                 count++;
                 i++;
             }
             sb.append(str.charAt(i));
             if(count > 1){
                 sb.append(count.toString());
             }
             else{
                 sb.append(count.toString());
             }
         }
         return sb.toString();
	}
	
 }