#include<stdio.h>
#include<stdlib.h>
struct fcfs{
    int pid;
    int atime;
    int btime;
    int ctime;
    int ttime;
    int wtime;
}p[10],temp;
void main(){
    int n;
    float atat,awt,tat,wt;
    printf("---------FCFS------");
    printf("Enter the number of process");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter the arrival time");
        scanf("%d",&p[i].atime);
        printf("Enter the burst time");
        scanf("%d",&p[i].btime);
        p[i].pid=i;
    }p[0].wtime=0;
    p[0].ctime=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(p[i].atime>p[j].atime){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(int i=1;i<=n;i++){
        p[i].ctime=p[i-1].ctime+p[i].btime;
        p[i].ttime=p[i].ctime-p[i].atime;
        p[i].wtime=p[i].ttime-p[i].btime;
        tat=tat+p[i].ttime;
        wt=wt+p[i].wtime;
    }
    for(int i=1;i<=n;i++){
    printf("\n  %d \t %d \t %d \t %d \t %d \t %d \t  \n ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].ttime,p[i].wtime);
  } 
    printf("\n  TurnAroundTime %f \n  Waiting Time %f\n",tat,wt);
    printf("\n Average TurnAroundTime %f \n Average Waiting Time %f\n",tat/n,wt/n);

}   
