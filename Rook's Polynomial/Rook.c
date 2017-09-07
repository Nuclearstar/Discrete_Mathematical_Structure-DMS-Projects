#include<stdio.h>
void main()
{
int a[5][5],m,n,s,g,h,q=1,max=0;
int b[10],k,flag=0,i,j,count=0,num,c[10],d[10];
printf("Problem: Design a program to construct the rook polynomial\n\n");
printf("Enter the number of rows and columns\n");
scanf("%d%d",&m,&n);
for(g=0;g<m;g++)
{
  for(h=0;h<n;h++)
    {
     printf("%d\t",q);
     a[g][h]=q;
     q++;
    }
  printf("\n");
 }
printf("Enter the number the shaded positions\n");
scanf("%d",&s);
printf("Enter the shaded positions\n");
for(k=0;k<s;k++)
 {
   scanf("%d",&b[k]);
 }
printf("Now the given chess board is\n");
for(g=0;g<m;g++)
{
  for(h=0;h<n;h++)
   { flag=0;
     for(k=0;k<s;k++)
       { 
        if(a[g][h]==b[k])
        { printf("#\t");
         a[g][h]='$';
         flag=1;}
        } 
        if(flag==0)
        printf("%d\t",a[g][h]);
       }
     printf("\n");
   }
printf("R1 values are: ");
for(g=0;g<m;g++)
{
  for(h=0;h<n;h++)
   {
     if(a[g][h]!='$')
     printf("(%d) ",a[g][h]);
   }
}
k=0;
printf("\nR2 pairs are :\t");
for(g=0;g<m;g++)
{
  for(h=0;h<n;h++)
     {
       for(i=0;i<m;i++)
         {
           for(j=(h+1);j<n;j++)
             {
                if(a[g][h]=='$')
                  continue;
                else if(a[i][j]=='$')
                 continue;
                else if(g!=i&&h!=j)
                 { 
                   if((g*n)+(h+1)<(i*n)+(j+1))
                    {
                     c[k]=(g*n)+(h+1);
                     d[k]=(i*n)+(j+1);
                    }
                   else
                    {
                     d[k]=(g*n)+(h+1);
                     c[k]=(i*n)+(j+1);
                    }
                  printf(" (%d ,%d) ",c[k],d[k]);
                 k++;
               count++;}
             }
          }
      }
}
printf("\nR3 triplets are:  ");
for(g=0;g<count;g++)
   { 
     for(h=g+1;h<count;h++)
    { if(c[g]==c[h])
       {
         for(k=g+1;k<count;k++)
         {
            if(((d[g]==c[k])||(d[g]==d[k]))&&((d[h]==c[k])||(d[h]==d[k])))
             {  max++;
             printf(" ( %d , %d ,",c[g],d[g]);
              if(d[g]==c[k])
              printf(" %d ) ",d[k]);
              else
                printf("%d )",c[k]);
              }
          }
       }
     }
  }
      
printf("\nRooks polynomial is= 1 + %dX ",((m*n)-s));
if(count!=0)
printf("+ %dX^2 ",count);
if(max!=0)
printf("+ %dX^3\n",max);
}
