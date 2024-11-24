#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
void ins_beg(struct node *new1){
    if(head==NULL)
        head=new1;
    else{
        new1->next=head;
        head=new1;
    }   
}
void middle(){
    temp=head;
    struct node *temp1=head;
    while(temp1->next !=NULL && temp1!=NULL && temp1->next->next!=NULL){
        temp=temp->next;
        temp1=temp1->next->next;
    } 
    printf("data in middle = %d",temp->data);
}
void del_beg(){
    if(head==NULL)
        printf("No nodes\n");
    else
    {    
        head=head->next;
    }
}
void traverse(){
    temp = head;
	if(head == NULL)
	    printf("no item to traverse\n");
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main(){
    int choice;
	struct node *new1;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. Ins Beg\n2. Middle Element\n3. Del Beg\n4. Traverse\n5. Exit: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
                new1 = (struct node*)malloc(sizeof(struct node));
                printf("enter the data\n");
                scanf("%d",&new1->data);
                new1->next = NULL;
                ins_beg(new1);
                break;
            case 2:
                middle();
                break;
            case 3:
                del_beg();
                break;
            case 4:
                traverse();    
                break;
            default:
                exit(1);        
        }
    }
}