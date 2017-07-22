import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main{
	public static void main(String[] args){
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		BigInteger b;
		int n,x;
		int T;
		int a[] = new int[2010];
		int cas=1;
		T=cin.nextInt();
		for(x=0;x<T;x++){
			n=cin.nextInt();
			BigInteger c;
			c=cin.nextBigInteger();
			b=BigInteger.valueOf(0);
			int i;
			for(i=1;i<=n;i++){
				a[i]=cin.nextInt();
			}
			a[0]=a[1]+1;
			a[n+1]=a[n]-1;
			for(i=1;i<=n;i++){
				if(a[i]>a[i-1]&&a[i]>a[i+1]){
					c=c.add(b.multiply(BigInteger.valueOf(a[i])));
				}
				if(a[i]<a[i-1]&&a[i]<a[i+1]){
					b=c.divide(BigInteger.valueOf(a[i]));
					c=c.mod(BigInteger.valueOf(a[i]));
				}
			}
			System.out.print("Case #"+cas+": ");
			System.out.println(c.mod(BigInteger.valueOf(1000000007)));
			cas++;
		}
	}
}
