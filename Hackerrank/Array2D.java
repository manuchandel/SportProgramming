 import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
//HOUR GLASS PROBLEM
public class Array2D {
   static int r=6;
   static int c=6;
   public static int sumat(int arr[][])
   {     if (r < 4 || c < 4) 
        return -1; 
      
        int max=Integer.MIN_VALUE,sum=0;
        for (int i = 0; i < r-2; i++) {
            for(int j=0;j<c-2;j++)
            {
              sum=(arr[i][j]+arr[i][j+1]+arr[i][j+2])+(arr[i+1][j+1])+(arr[i+2][j]
              +arr[i+2][j+1]+arr[i+2][j+2]);
              max = Math.max(max, sum); }}return max;
   }

   
    public static void main(String[] args) {
          Scanner sc = new Scanner(System.in);

        int[][] mat = new int[6][6];
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
              
              mat[i][j]=sc.nextInt();
            }
        }
        int n=sumat(mat);
        
              
            
    
    if(n!=-1)
    System.out.println(n);}
}

