#include<stdio.h>
int bt[10],wt[10],tt[10],n,temp,at[20],pi[10],ct[10],count,f,c,s[10],m,index,bta[50],ata[50],pia[50],btt[10],pr[10],pra[50];
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
	if ((m>pr[i])&&(s[i]!=1))
	{
		m=pr[i];
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
	printf("Enter burst, arrival time and priority \n");
	for(int i=0;i<n;i++)
	{
		printf("For P%d process:",i);
		scanf("%d%d%d",&bt[i],&at[i],&pr[i]);
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
			printf("\nProcess\tBurst time\tArrival time\n");
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
	pra[0]=pr[0];
	if(at[0]==1)
	{
		bta[t]=0;
	pia[0]=0;
	ata[0]=0;
		t=1;
	bta[t]=bt[0];
	pia[t]=pi[0];
	ata[t]=at[0];
	pra[t]=pr[0];
	}
	while(1)
	{
		count=acount(t);
		t++;
	f=min(count);
	pia[t]=pi[f];
	ata[t]=at[f];
	bt[f]=bt[f]-1;
	bta[t]=bt[f];
	pra[t]=pr[f];	
	if(bta[t]==0)
	{
	s[f]=1;
	ct[f]=t;
	b++;
}
if(b==n)
break;
	
}
	printf("\nProcess\tBurst time\tArrival time\n");
		for(int i=0;i<=t;i++)
		{
			printf("p%d\t\t%d\t\t%d\n",pia[i],bta[i],ata[i]);
		}
			printf("\n\n\tPRIORITY SCHEDULING PREEMPTIVE\n\n\n");
		printf("Process\tBurst time\tArrival time\tPriority\tCompilation time\tWaiting time\tTurnaround time\n");
		for(int i=0;i<n;i++)
		{
			tt[i]=ct[i]-at[i];
			wt[i]=tt[i]-btt[i];
			wta=wta+wt[i];
			tta=tta+tt[i];
printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t%d\n",pi[i],btt[i],at[i],pr[i],ct[i],wt[i],tt[i]);
}
	printf("\n\tAverage waiting time %f:",wta/n);
		printf("\n\n\tAverage turnaround time :%f",tta/n);

}