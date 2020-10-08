/*
The question is based on Binary Search. It takes the assumption that first array is smaller than second one.
We maintain two sets of both the arrays and try to find the partition such that 
left half of first array should be lesser than the second half of second array and vice versa.
Thus we achieve a lograthmic time complexity.
*/
import java.util.*;
class abc
{
    static int median(int n,int m,int[] a,int[] b)
    {
        int beg1=0,end1=n;
        while(beg1<=end1)
        {
            int i1=(beg1+end1)/2;
            int i2=(n+m+1)/2-i1;
            
            int max1=i1==0?Integer.MIN_VALUE:a[i1-1];
            int min1=i1==n?Integer.MAX_VALUE:a[i1];
            
            int max2=i2==0?Integer.MIN_VALUE:b[i2-1];
            int min2=i2==m?Integer.MAX_VALUE:b[i2];
            if(max1<=min2 && max2<=min1)
            {
                if((n+m)%2==0)
                return((Math.max(max1,max2)+Math.min(min1,min2))/2);
                else
                return Math.max(max1,max2);
            }
            else if(max1>min2)
            end1=i1-1;
            else
            beg1=i1+1;
        }
        return 0;
    }
    public static void main(String[] args) {
        int n,m;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt(); // Size of first array
        m=sc.nextInt(); // Size of Second Array
        int a[]=new int[n];
        int b[]=new int[m];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        for(int i=0;i<m;i++)
        {
            b[i]=sc.nextInt();
        }
        System.out.println("Median= "+median(n,m,a,b));
        sc.close();
    }
}