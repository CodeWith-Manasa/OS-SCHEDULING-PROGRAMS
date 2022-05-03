#include<stdio.h>
int bt[10],wt[10],tt[10],n,temp,at[20],pi[10],ct[10],count,f,c,s[10],m,index,bta[40],ata[40],pia[40],btt[10];
float wta=0,tta=0;
int acount(int c)
{
	
	int co=0;
	for(int i=0;i<n;i++)
	{
		if(c>=at[i])
		co++;
}
	return co;	
}
int min(int p)
{
     m=999;
     index=0;
for(int i=0;i<p;i++)
{
	if ((m>bt[i])&&(s[i]!=1))
	{
		m=bt[i];
		index=i;
	}
}
return index;
}
int main()
{
	int t,b;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter burst time and arrival for P%d process:",i);
		scanf("%d",&bt[i]);
		scanf("%d",&at[i]);
		pi[i]=i;
		s[i]=0;
		}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(at[i]>at[j])
			{
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=pi[i];
				pi[i]=pi[j];
				pi[j]=temp;
			}
				if(at[i]==at[j])
				{
					if(bt[i]>bt[j])
					{
				temp=at[i];
				at[i]=at[j];
				at[j]=temp;
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=pi[i];
				pi[i]=pi[j];
				pi[j]=temp;
			}
			}
			}
		}
			printf("Process\tBurst time\tArrival time\n");
for(int i=0;i<n;i++)
{
printf("%d\t%d\t\t%d\n",pi[i],bt[i],at[i]);
btt[i]=bt[i];
}
	t=0;
	b=0;
	bta[t]=bt[0];
	pia[0]=pi[0];
	ata[0]=at[0];
	if(at[0]==1)
	{
		bta[t]=0;
	pia[0]=0;
	ata[0]=0;
		t=1;
	bta[t]=bt[0];
	pia[t]=pi[0];
	ata[t]=at[0];
	}
	while(1)
	{
		if(t<=n)
		count=acount(t);
		t++;
	f=min(count);
	pia[t]=pi[f];
	ata[t]=at[f];
	bt[f]=bt[f]-1;
	bta[t]=bt[f];	
	if(bta[t]==0)
	{
	s[f]=1;
	ct[f]=t;
	b++;
}
if(b==n)
break;
	
}
	printf("Process\tBurst time\tArrival time\n");
		for(int i=0;i<=t;i++)
		{
			printf("p%d\t\t%d\t\t%d\n",pia[i],bta[i],ata[i]);
		}
			printf("\n\n\tSHORTEST JOB FIRST SCHEDULING PREEMPTIVE\n\n\n");
		printf("Process\tBurst time\tArrival time\tCompilation time\tWaiting time\tTurnaround time\n");
		for(int i=0;i<n;i++)
		{
			tt[i]=ct[i]-at[i];
			wt[i]=tt[i]-btt[i];
			wta=wta+wt[i];
			tta=tta+tt[i];
printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",pi[i],btt[i],at[i],ct[i],wt[i],tt[i]);
}
	printf("\n\tAverage waiting time %f:",wta/n);
		printf("\n\n\tAverage turnaround time :%f",tta/n);

}