#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*first,*last,*newnode,*temp;
int start,num;
struct node mem[50];
int isallocated(){
    for(int i=start;i<=start+num;i++){
        if(mem[i].data==1){
            printf("Cannot Allocate");
            return 1;
        }
    }
    return 0;
}
void linked(){
    printf("Enter the starting block");
    scanf("%d",&start);
    printf("Enter the number of block");
    scanf("%d",&num);
    int flag=isallocated();
    if(flag==0){
        for(int i=start;i<start+num;i++){
            int n;
            printf("Enter the block number");
            scanf("%d",&n);
            mem[i].data=1;
            newnode=(struct node *)malloc(sizeof(struct node ));
            newnode->data=n;
            newnode->link=NULL;
            if(first==NULL){
                first=newnode;
                last=newnode;
            }
            else{
                last->link=newnode;
                last=newnode;
            }
        }
        printf("Linked List Is");
        temp=first;
        first=last=NULL;
        for(int i=start;i<start+num;i++){
            printf("%d ->",temp->data);
            temp=temp->link;
        }
    }
    else{
        printf("Already Allocated");
    }
    
}
void main(){
    printf("----------LINKED ALLOCATION------------");
    while (1)
    {   int ch;
        printf("\nEnter :\n1 for new new file \nor 2 for exit\n");
        scanf("%d",&ch);
        if(ch==1){
            linked();
        }
        else{
            break;
        }
    }
