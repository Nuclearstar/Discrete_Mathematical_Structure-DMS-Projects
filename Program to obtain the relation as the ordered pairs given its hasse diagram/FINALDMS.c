#include<stdio.h>
#include<stdlib.h>
void input(int a[],int m)
{
    int i,j,k,c;
   abc:printf("\nENTER THE PARTIAL ORDER SET ELEMENTS:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<=0)
        {
            printf("\n DOMAIN IS SET OF ALL POSITIVE INTEGERS\n");
            printf("\n RE ENTER THE SET ELEMENTS\n");
            goto abc;
        }

    }
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(a[j]==a[i])
            {
                printf("\nDUPLICATE FOUND\nPLEASE RE ENTER THE SET ELEMENTS\n");
                goto abc;
            }

        }

    }
    printf("\n PO SET ENTERED IS==>\n");
    printf("\n A={");
    for(i=0;i<m;i++)
    {

        printf("%d ",a[i]);
        if(i==m-1)
            break;
        else
        printf(",");


    }
    printf(" }");

}

void particular()
{
    int pos[]={1,2,3,4,5,6},a[5],i;
    printf("\n\n\t\tPREDEFINED HASSE DIAGRAM IS :\n");
    hasee1(pos);
    printf("\n\n\t\tENTER THE VALUE FOR POSITIONS : \n");
    for(i=0;i<6;i++)
    {
        printf("\n\t\tVALUE FOR POSITION %d : ",i+1);
        scanf("%d",&a[i]);
    }

    printf("\n\t\tTHE GIVEN HASSE DIAGRAM IS :");
    hasee1(a);
    printf("\n\n");

    display(a,6);

}

void hasee1(int *pos)
{
    printf("\n\n\n\t\t%d<-------",pos[5]);
    printf("\n\t\t^\t^\n\t\t|\t|\n\t\t%d\t%d\n\t\t^\t^\n\t\t|\t|\n\t\t%d\t%d\n\t\t^\t^\n\t\t|\t|\n\t\t%d------->",pos[3],pos[4],pos[1],pos[2],pos[0]);
}

void hasseeven(int a[],int m)
{
    int i;
    int n;
    n=m;
    printf("\t%d\n",a[n-1]);
    for(i=0;i<=n-2;i++)
    {
        if(n-i-3<0)
            break;
        else
        {
            printf("\n\n\n%d\t\t%d\n\n\n",a[n-i-3],a[n-i-2]);
            n=n-1;
        }

    }
    printf("\t%d\n",a[0]);
}

void hasseodd(int a[],int m)
{
    int i;
    int n;
    n=m;
    for(i=0;i<=n-1;i++)
    {
        if(n-i-2<0)
            break;
        else{
        printf("\n\n\n%d\t\t%d\n\n\n",a[n-i-2],a[n-i-1]);
        n=n-1;
        }
    }
    printf("\t%d\n",a[0]);

}

void hasse(int a[],int m)
{
    int i;
    if(m%2==0)
        hasseeven(a,m);
    else
        hasseodd(a,m);
}

void display(int a[],int m)
{
    int c,i;
    printf("\nTHE REQUIRED PARTIAL ORDER RELATION IS =====>>:\n");
        printf("\nR={");
  for(i=0;i<m;i++)
  {
    c=0;
    while(c<m)
    {
      if(a[i]%a[c]==0)
      {
        printf("(%d,%d)",a[c],a[i]);

      }
      c++;
    }
  }
  printf("}");
  printf("\n");

}

main()
{

    int a[20],m,ch;
    printf("\n\nDMS EVENT 2\n\n");
    printf("\nTEAM MEMBERS:\n 1:AJEYA B JOIS\n2.AJAY KB\n3.NITHIN PRABHU\n");
    printf("\n($) PROBLEM : GIVEN HASSE DIAGRAM OBTAIN THE PARTIAL ORDER RELATION:\n");
    printf("\n($) WE HAVE CONSIDERED THE DIVISIBILTY RELATION ON SET OF ALL POSITIVE INTEGERS FOR OUR PROBLEM\n");
    printf("\n($) ie R={(x,y <<Z+) | x divides y}\n");
    printf("\n($) USERS MUST ASSUME THE EDGES IN HASSE DIAGRAM IN BETWEEN THE NODES\n");
    printf("\n($) USER MUST ENTER THE ELEMENTS OF POSET IN ASCENDING ORDER ONLY\n");
    printf("\n($) OR ELSE HASSE DIAGRAM THAT WE OBTAIN WILL BE INCORRECT\n");
    printf("\n($) USER MUST GIVE THE POSET BEFORE PROCEEDING FURTHER\n");

    printf("\nENTER THE NUMBER OF ELEMENTS YOU REQUIRE IN THE POSET:\n");
    scanf("%d",&m);

    while(1)
    {

        printf("\n1.INPUT THE POSET\n2.DISPLAY HASSE DIAGRAM\n3.DISPLAY PARTIAL ORDER RELATION\n4.EXIT\n5.PARTICULAR PROBLEM\n");
        printf("\nENTER YOUR CHOICE:\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:input(a,m);
                   break;
            case 2:hasse(a,m);
                   break;
            case 3:display(a,m);
                   break;
            case 4:exit(0);
            case 5:particular();

                   break;
            default:printf("\nINVALID CHOICE:\n");
        }
    }
}
