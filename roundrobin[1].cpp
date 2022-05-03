#include<stdio.h>
int main()
{
	int bt[10],wt[10],tt[10],ct[10],t,pi[10],c=0,f=0,n,bta[10],st[10];
	float wta,tta;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter burst time for P%d process:",i);
		scanf("%d",&bt[i]);
		pi[i]=i;
		bta[i]=bt[i];
		st[i]=0;
		}
		printf("\n\nEnter time slice\n");
		scanf("%d",&t);
		while(f<n)
		{
			for(int i=0;i<n;i++)
			{
			if(bt[i]>=0 && st[i]!=1)
			{
				if(bt[i]<=t)
				{
						c=c+bt[i];
					bt[i]=0;
					ct[i]=c;
					st[i]=1;
					f++;				
				}
				else
				{
			bt[i]=bt[i]-t;
			c=c+t;
		}
		}
		
	}
}
printf("\n\n\tROUND-ROBIN SCHEDULING\n\n");
		printf("Process id\tBurst time\tWaiting time\tTurnaround time\n");
		for(int i=0;i<n;i++)
		{
			wt[i]=ct[i]-bta[i];
			wta=wta+wt[i];
			tta=tta+ct[i];
		printf("%d\t\t%d\t\t%d\t\t\t%d\n",pi[i],bta[i],wt[i],ct[i]);
	}
	printf("\n\n\tAverage waiting time : %f\n",wta/n);
		printf("\n\n\tAverage Turnaround time : %f\n",tta/n);
	}