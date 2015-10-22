import java.util.*;
 class ToAndFro {
    
    public static void main(String[] args)
    {
    	Scanner c=new Scanner(System.in);
    	int w=1;
		while(w==1)
		{
		int n=c.nextInt();
		if(n==0)
			break;
		String t=c.next();
		int m=(int)(t.length()/n)+1;
		char a[][]=new char[m][n];
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		a[i][j]='0';
		int k=0;
		for(int i=0;i<m;i++)
		{
			if(i%2==0)
			for(int j=0;j<n&&k<t.length();j++)
			{
			a[i][j]=t.charAt(k);
			k++;
			}
			else
			{for(int j=n-1;j>=0&&k<t.length();j--)
			{
			a[i][j]=t.charAt(k);
			k++;
			}}
			
			if(k==t.length())
			break;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[j][i]!='0')
				System.out.print(a[j][i]);
			}
		}
		System.out.println();
	}
	}
}

