 import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.Iterable.*;

public class Review {
//code to print odd and even numbers separetely
    public static void main(String[] args) {
        /*Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
     Scanner x=new Scanner(System.in);
     int n=x.nextInt(); 
     x.nextLine();
     String strings[]=new String[100] ;
     for(int i=0;i<n;i++)
     strings[i]=x.nextLine();       
     for(int i = 0;i < n;i++){
        String word = strings[i];
        ArrayList<Integer> oddIndexes  = new ArrayList<>(100);
        for(int j= 0; j < word.length();j++){
            if(j % 2 == 0){
                System.out.print(word.charAt(j));
            }else{
                oddIndexes.add(j);
            }
        }
        System.out.print(" ");
        for(Integer index : oddIndexes){
            System.out.print(word.charAt(index));
        }
        System.out.println();
    }
 }}

