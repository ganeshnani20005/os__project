#include <stdio.h>
#include <conio.h>
int main()
{
int m[10][10], n[10][10], a[10][10], b[10], c[10], d[10];
int l,s,i,j,process,count;
count=0;

printf("Enter the no of processes : ");
scanf("%d", &l);

for(i = 0; i<l; i++)
	c[i] = 0;

printf("\n\nEnter the no of resources : ");
scanf("%d", &s);

printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i <l; i++)
{
	printf("\nFor process %d : ", i + 1);
	for(j = 0; j <s; j++)
		scanf("%d", &m[i][j]);
}

printf("\n\nEnter the allocation for each process : ");
for(i = 0; i <l; i++)
{
	printf("\nFor process %d : ",i + 1);
	for(j = 0; j <s; j++)
		scanf("%d", &a[i][j]);	
}

printf("\n\nEnter the Available Resources : ");
for(i = 0; i <s; i++)
		scanf("%d", &b[i]);	


	for(i = 0; i <l; i++)
		for(j = 0; j <s; j++)
			n[i][j] = m[i][j] - a[i][j];
		
do
{
	printf("\n Max matrix:\tAllocation matrix:\n");
	for(i = 0; i <l; i++)
	{
		for( j = 0; j <s; j++)
			printf("%d  ", m[i][j]);
		printf("\t\t");
		for( j = 0; j <s; j++)
			printf("%d  ", a[i][j]);
		printf("\n");
	}

	process = -1;

	for(i = 0; i <l; i++)
	{
		if(c[i] == 0)
		{
			process = i ;
			for(j = 0; j <s; j++)
			{
				if(b[j] < n[i][j])
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
			break;
	}

	if(process != -1)
	{
		printf("\nProcess %d runs to completion!", process + 1);
		d[count] = process + 1;
		count++;
		for(j = 0; j <s; j++)
		{
			b[j] += a[process][j];
			a[process][j] = 0;
			m[process][j] = 0;
			c[process] = 1;
		}
	}
}while(count !=l && process != -1);

if(count ==l)
{
	printf("\nThe system is in a safe state!!\n");
	printf("Safe Sequence : < ");
	for( i = 0; i <l; i++)
			printf("%d  ", d[i]);
	printf(">\n");
}
else
	printf("\nThe system is in an unsafe state!!");
getch();
}
