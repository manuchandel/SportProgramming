//to find the maximum occurring character
import java.util.*;
public class Main {
 static final int N = 256;
 public static void main(String args[]){
  Scanner x=new Scanner(System.in);
   int n=x.nextInt();
   x.nextLine();
  
  String str[]=new String[100];
   for(int i=0;i<n;i++)
   str[i]=x.nextLine();
   for(int k=0;k<n;k++)
   {  int ctr[] = new int[N];
      String str1=str[k];
  int l = str1.length();
  for (int i = 0; i < l; i++)
   ctr[str1.charAt(i)]++;
  int max = -1;
  char result = ' ';

  for (int i = 0; i < l; i++) {
   if (max < ctr[str1.charAt(i)]) {
    max = ctr[str1.charAt(i)];
    result = str1.charAt(i);
   }
  }

  System.out.println( result);
  
 }
 
 
}}
