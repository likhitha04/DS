//SPARSE MATRIX OR NOT
#include<stdio.h>
int main()
{
    int n,m,a[100][100],i,j,k=0,t=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }

    }
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)
                k++;
            else
                t++;
        }
    }
    if(k>t)
        printf("given matrix is a sparse matrix\n");
     else
        printf("not a sparse matrix\n");
    printf("triplet representation\n");
    printf("%d %d %d\n",t,t,t);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
                printf("%d %d %d",i,j,a[i][j]);
        }
        printf("\n");
    }
return 0;
}
