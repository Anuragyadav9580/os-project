#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
  char pname[10][5],temp[5];
  int i,j,ptime[10],wtime[10],totwtime=0,pr[10],temp1,n;
  float avgwtime;
 printf("Enter no of processes:");
 scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  printf("Enter process%d name:",i+1);
 scanf("%s",&pname[i]);
  printf("Enter process time:");
 scanf("%d",&ptime[i]);
  printf("Enter priority:");
  scanf("%d",&pr[i]);
  }
 for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
   if(pr[i]>pr[j])
 {
   temp1=pr[i];
 pr[i]=pr[j];
  pr[j]=temp1;
  temp1=ptime[i];
  ptime[i]=ptime[j];
  ptime[j]=temp1;
 strcpy(temp,pname[i]);
 strcpy(pname[i],pname[j]);
  strcpy(pname[j],temp);
  }
  }
  }
 wtime[0]=0;
  for(i=1;i<n;i++)
  {
   wtime[i]=wtime[i-1]+ptime[i-1];
   totwtime=totwtime+wtime[i];
   }  
avgwtime=(float)totwtime/n;  
printf("P_Name\t P_Time\t Priority\t w_time\n");
for(i=0;i<n;i++)  
{
   printf(" %s\t %d\t %d\t %d\n" ,pname[i],ptime[i],pr[i],wtime[i]);
   }
  printf("total waiting time=%d\n avg waiting time=%f",totwtime,avgwtime);
  return 0;
   }
