#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void printsparse(int b[MAX][3]);
void readsparse(int b[MAX][3]);
void addsparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3]);
void main()
{
   
	int b1[MAX][3],b2[MAX][3],b3[MAX][3];
	
	printf("\nReading 1st sparse matrix..\n");   
	readsparse(b1);
	
	printf("\nReading 2nd sparse matrix..\n");   
	readsparse(b2);
	   
	addsparse(b1,b2,b3);
	
	printf("\nSum\n"); 
	printsparse(b3);
	printf("\n");
}
void readsparse(int b[MAX][3])
{
	int i,t,m,n;
	   
	printf("\nEnter no. of rows and columns of the matrix: ");
	   
	scanf("%d%d",&m,&n);
	    
	printf("No. of non-zero elements: ");
	   
	scanf("%d",&t);
	   
	b[0][0]=m;
	   
	b[0][1]=n;
	   
	b[0][2]=t;
	   
	for(i=1;i<=t;i++)
	    {
	       
	printf("Enter the triples: ");
	       
	scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
	    }
}
void addsparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3])
{
	   
	int t1,t2,i,j,k;
	   
	if(b1[0][0]!=b2[0][0]||b1[0][1]!=b2[0][1])
	    {
	       
		printf("\nYou have entered invalid matrix!!Size must be equal");
		       
		exit(0);
	    }
	   
	t1=b1[0][2];
	   
	t2=b2[0][2];
	   
	i=j=k=0;
	   
	b3[0][0]=b1[0][0];
	   
	b3[0][1]=b1[0][1];
	   
	while(i<=t1 && j<=t2)
	{
	       
	if(b1[i][0]<b2[j][0])      
	
	{
		   
	b3[k][0]=b1[i][0];
		   
	b3[k][1]=b1[i][1];
		   
	b3[k][2]=b1[i][2];
		   
	k++;
		   
	i++;
	       
	}
	       
	else if(b2[j][0]<b1[i][0])      
	     
	{
		   
	b3[k][0]=b2[j][0];
		   
	b3[k][1]=b2[j][1];
		   
	b3[k][2]=b2[j][2];
	       
	k++;
		   
	j++;
	       
	}
	       
	else if(b1[i][1]<b2[j][1])      
	     
	{
		   
	b3[k][0]=b1[i][0];
		   
	b3[k][1]=b1[i][1];
		   
	b3[k][2]=b1[i][2];
		   
	k++;
		   
	i++;
	}
	       
	else if(b2[j][1]<b1[i][1])      
	     
	{
		   
	b3[k][0]=b2[j][0];
		   
	b3[k][1]=b2[j][1];
		   
	b3[k][2]=b2[j][2];
		   
	k++;
		   
	j++;
	       
	}
	       
	else
	       
	{
		   
	b3[k][0]=b1[i][0];      
		   
	b3[k][1]=b1[i][1];
		   
	b3[k][2]=b1[i][2]+b2[j][2];
		   
	k++;
		   
	i++;
		   
	j++;
	       
	}
	}
	   
	while(i<=t1)       
	
	{
	       
	b3[k][0]=b1[i][0];
	       
	b3[k][1]=b1[i][1];
	       
	b3[k][2]=b1[i][2];
	       
	i++;
	       
	k++;
	}
	   
	while(j<=t2)  
	
	{
	       
	b3[k][0]=b2[j][0];
	       
	b3[k][1]=b1[j][1];
	       
	b3[k][2]=b1[j][2];
	       
	j++;
	       
	k++;
	}
	   
	b3[0][2]=k-1;      
	
	}
void printsparse(int b[MAX][3])
{
	   
	int i,t;
	   
	t=b[0][2];
	   
	printf("\n%d\t%d\t%d",b[0][0],b[0][1],b[0][2]);
	   
	for(i=1;i<=t;i++)
	{
	       
	printf("\n%d\t%d\t%d",b[i][0],b[i][1],b[i][2]);
	}
}
