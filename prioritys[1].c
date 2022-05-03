#include<stdio.h>
int bt[10],wt[10],tt[10],n,temp,at[20],pi[10],ct[10],count,f,c,s[10],m,index,bta[10],ata[10],pia[10],pr[10],pra[10];
float wta,tta;
int acount(int c)
{
	int co=0;
	for(int i=1;i<n;i++)
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
for(int i=1;i<=p;i++)
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
	printf("enter the number of process\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter burst time and arrival and priority for P%d process:",i);
		scanf("%d%d%d",&bt[i],&at[i],&pr[i]);
		pi[i]=i;
		s[i]=0;
		}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(at[i]>=at[j])
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
				temp=pr[i];
				pr[i]=pr[j];
				pr[j]=temp;
			}
					
			}
		}
	wt[0]=wta=0;
	c=bt[0]+at[0];
	ct[0]=c;
	count=0;
	bta[0]=bt[0];
	tt[0]=tta=ct[0]-at[0];
	s[0]=1;
	pia[0]=pi[0];
	pra[0]=pr[0];
	ata[0]=at[0];
	for(int i=1;i<n;i++)
	{
		count=acount(c);
	f=min(count);
	pra[i]=pr[f];
	pia[i]=pi[f];
	ata[i]=at[f];
	bta[i]=bt[f];
	s[f]=1;
	ct[i]=ct[i-1]+bt[f];
	tt[i]=ct[i]-at[f];
	wt[i]=tt[i]-bta[i];
	wta=wta+wt[i];
	tta=tta+tt[i];
		c=ct[i];
}
		printf("process\tburst time\tarrival time\tpriority\tcompilation time\twaiting time\tturnaround time\n");
		for(int i=0;i<n;i++)
		{
			printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pia[i],bta[i],ata[i],pra[i],ct[i],wt[i],tt[i]);
		}
		printf("average waiting time %f:",wta/n);
		printf("\naverage turnaround time :%f",tta/n);

}