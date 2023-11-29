#include<stdio.h>
void main(){
    int i,j,n,at[10],bt[10],ct[10],tat[10],wt[10],currenttime=0;
    float total_tat=0,total_wt=0;
    printf("enter the no of processes:");
    scanf("%d",&n);
    printf("enter the details of each process   ::");
    
    for(i=0;i<n;i++){
        printf("\nenter the arrival time and burst time of p[%d]:",i+1);
        scanf("\n%d %d",&at[i],&bt[i]);
    }
    for(i=0;i<n;i++){
        if(currenttime>=at[i]){
            currenttime=currenttime+bt[i];
            ct[i]=currenttime;
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
        }
        else
        {
            currenttime++;
            i--;
        }
    }
    
    printf("Process  AT BT CT TAT WT\n");
    for(i=0;i<n;i++){
        printf("%d %d %d %d %d \n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    for(i=0;i<n;i++){
        total_tat=total_tat+tat[i];
        total_wt=total_wt+wt[i];
    }
    printf("Average TAT is %.2f\n",total_tat/n);
     printf("Average WT is %.2f\n",total_wt/n);
    
}
