#include <stdio.h>
void main(){
	int n,i,j,tot_wait=0,tot_turn=0,temp;
	int pro_arr[20],bur_arr[20],wait_time[20],turn_time[20];
	
	
	printf("Enter No. Of Processes: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Enter Process-%d Name:",i+1);
		scanf("%d",&pro_arr[i]);
		
		printf("Enter Process-%d BurstTime:",i+1);
		scanf("%d",&bur_arr[i]);
	}
	
    //sorting
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(bur_arr[j]>bur_arr[j+1]){   
                temp = bur_arr[j];
                bur_arr[j] = bur_arr[j+1];
                bur_arr[j+1] = temp;

                temp = pro_arr[j];
                pro_arr[j] = pro_arr[j+1];
                pro_arr[j+1] = temp;
            }
        }
    }


	printf("\nProcesses: ");
	for(i=0;i<n;i++){
		printf("P%d ",pro_arr[i]);
	}
	
	printf("\nBurst Times: ");
	for(i=0;i<n;i++){
		printf("%d ",bur_arr[i]);
	}
	printf("\n");
	
	wait_time[0] = 0;
	
	for(i=1;i<n;i++){
		wait_time[i] = bur_arr[i-1] + wait_time[i-1];
		tot_wait += wait_time[i];
	}
	
	turn_time[0]=bur_arr[0];
	tot_turn = bur_arr[0];
	
	
	for(i=1;i<n;i++){
		turn_time[i] = turn_time[i-1] + bur_arr[i];
		tot_turn += turn_time[i];
	}
	
	printf("\nWaiting Times: ");
	for(i=0;i<n;i++){
		printf("%d ",wait_time[i]);
	}
	printf("\n");
	
		printf("\nTurn Around Times: ");
	for(i=0;i<n;i++){
		printf("%d ",turn_time[i]);
	}
	printf("\n");
	
	printf("\nTotal Waiting Time: %d\n",tot_wait);
	printf("Average Waiting Time: %d\n",tot_wait/n);
	
	printf("Total Turn Around Time: %d\n",tot_turn);
	printf("Average Turn Around Time: %d\n",tot_turn/n);
	
}
