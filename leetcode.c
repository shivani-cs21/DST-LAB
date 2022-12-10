#include<stdio.h>
#define size 10
int height[size],answer[size],i,j,k,l,n,p,q,temp,count=0,max,t;
void main()
{ printf("\n enter number of people \n");
scanf("%d",&n);
 printf("enter heights\n");

 for(k=0;k<n;k++)
scanf("%d",&height[k]);
t=height[0];
for(p=0;p<n;p++)
{ if (t<height[p])
t=height[p];

}

    for(i=0;i<n;i++)
    {count=0;
        for(j=i+1;j<n;j++)
        {
            if(height[j]<height[i] )

            {
                if(j>i+1)
            { if(height[j]>height[j-1])
            count++;}


            else if(j==i+1)
            count++;
            else
                continue;

}
            }
            if(i==n-1 ||(height[i]==t))
            {answer[i]=count;}
            else answer[i]=count+1;
             }
              for(l=0;l<n;l++)
    printf("%d \t",answer[l]);

        }
