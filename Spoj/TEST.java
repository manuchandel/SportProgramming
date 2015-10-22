import java.util.*;
 class Test
{
	public static void main(String args[])
	{
		Scanner c=new Scanner(System.in);
		int x=0;
		while(x!=42)
		{
			int i=c.nextInt();
			if(i!=42)
				System.out.println(i);
			x=i;
		}
	}
}

