 
//Complete this code or write your own from scratch
import java.util.*;
import java.io.*;

class Hashmap{
   public static void main(String []argh)
   {
      Scanner x = new Scanner(System.in);
      int n=x.nextInt();
      x.nextLine();
      Map<String, Integer> map = new HashMap<String, Integer>();
      for(int i=0;i<n;i++)
      {
          String name = x.next();
          int phone = x.nextInt();
          x.nextLine();
         map.put(name, phone);
      }
      while(x.hasNext())
      {
         String s=x.nextLine();
         if (map.get(s) != null) {
             System.out.println(s+"="+map.get(s));
         } else {
             System.out.println("Not found");
         }
      }
   }
}
