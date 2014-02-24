#include<stdio.h>
#include<conio.h>
int main()
{ int l,i,j,k,n,u ;
char arr[256];
char arr1[256];
    
    while(1)   
    {  n=0; l=0; u=0; k=0; 
       scanf("%d",&n);
       if(n==0)
       break;
       scanf("\n");
       while(1)
       { 
         scanf("%c",&arr[l]); 
         if (arr[l]=='\n')
         break;      
         l++;
       }
       u=(l/n);
       for(i=0;i<n;i++)
       {
         for(j=0;j<u;j++,k++)
         { arr1[k]=arr[i+(j*n)];
           printf("%c",arr1[k]);
         }       
       }
       printf("\n");
    }

return 0;
}
                       
