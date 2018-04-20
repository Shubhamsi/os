#include<stdio.h>
typedef struct
{
int process_id, arrival_time, burst_time, priority;
int  ready;
}process_structure;
int main()
{
	printf("**********************************FIXED PRIORITY IN LEVEL 1 AND ROUND ROBIN IN LEVEL 2**********************************");
	int limit, count, temp_process, time, j, y,a=0,o,b,k,z=0,s,e,i,T=0,B_Sum=0;
	int flag=0;
    process_structure temp;
	printf("Enter the number of process:");
	scanf("%d",&limit);
	process_structure process[limit];
	process_structure down[limit];
	for(count=0;count<limit;count++)
	{
		printf("\nProcess ID:\t");
		scanf("%d",&process[count].process_id);
		printf("Arrival Time:\t");
		scanf("%d",&process[count].arrival_time);
		printf("Burst Time:\t");
		scanf("%d",&process[count].burst_time);
		printf("Process Priority:\t");
		scanf("%d",&process[count].priority);
		process[count].ready=0;
	}	
	for(y=0;y<limit-1;y++)
	{
		for(j=0;j<limit-y-1;j++)
		{
			if(process[j].arrival_time>process[j+1].arrival_time)
			{
				process_structure temp=process[j];
				process[j]=process[j+1];
				process[j+1]=temp;
			}
		}
	}
	for(y=0;y<limit;y++)
	{
		if(y<limit-1){
		
	    for(j=y+1;j<limit;j++)
	    {
	    	if(process[y].arrival_time==process[j].arrival_time&&process[y].priority>process[j].priority)
	    {
	    	process[j].ready=1;
	    	limit++;
	    	process[limit-1]=process[y];}	         
	    	else if(process[y].arrival_time==process[j].arrival_time&&process[y].priority<process[j].priority){
		    process[y].ready=1;
		    process[j].arrival_time++;           }
		    else
	    	process[y].ready=1;}	
	}   	
	else{
		process[y].ready=1;
	}
		for( k=0;k<limit;k++){
		if(process[k].ready==1)
		{
			a=process[k].arrival_time;
			e=process[k].burst_time;
			do{
				for(s=k+1;s<limit;s++)
				{
					if(a==process[s].arrival_time&&process[k].priority>process[s].priority)
					flag=1;
				}
				if(flag==1)
				{
				if(e==process[k].burst_time)
				{
					break;
				}
				else{
				process[k].burst_time=e;
				down[T]=process[k];
				T++;
				break;}
				}
				else{
				
				printf("Process %d is processed for 1 second in queue 1\n",process[k].process_id);
			    e--;
				a++;
				if(e!=process[k].burst_time&&e!=0)
				{
			
		for(z=0;z<limit-k-1;z++){
		for(i=k+1;i<limit-z-1;i++)
		{
			if(process[i].arrival_time>process[i+1].arrival_time)
			{
				process_structure temp=process[i];
				process[i]=process[i+1];
				process[i+1]=temp;		
			}		
		}}
				}}}
					while(e>0);
			    e=0;
				flag=0;
				for(z=0;z<limit;z++)
				{
					if(process[z].ready==1)
					process[z].ready=0;					
				}
		}
		}	
}
printf("****************END OF QUEUE 1****************\n");

if(T!=0){

for(i=0;i<T;i++)
		{
		if(T!=0){
		
		    
		     if(down[i].burst_time>1){
		     printf("Process %d is processed for 1 second in queue 2\n",down[i].process_id);
		     down[i].burst_time--;
		      printf("Process %d is processed for 1 second in queue 2\n",down[i].process_id);
		     down[i].burst_time--;
		     if(down[i].burst_time!=0)
		     {
		     	T++;
		     	down[T-1]=down[i];
			 }
			 
			 }
		     else if(down[i].burst_time==1)
		     
		     {
		     	
		     	printf("Process %d is processed for 1 second in queue 2\n",down[i].process_id);
		     down[i].burst_time--;
			 }
			 else
			 break;
		
	}
}}
}

