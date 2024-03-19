#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct linkqueuenode{
	DataType data;
	struct linkqueuenode *next;
}linkqueuenode;

typedef struct{
	linkqueuenode *front;
	linkqueuenode *rear;

}linkqueue;

void initqueue(linkqueue *lq){
	lq->front=lq->rear=NULL;
}

int isemptyqueue(linkqueue *lq){
	return lq->front==NULL; 
}

void enterlinkqueue(linkqueue *lq,DataType value){
	linkqueuenode *newnode=(linkqueuenode*)malloc(sizeof(linkqueuenode));
	if(newnode==NULL){
		printf("memory allocation failed\n");
		return;
	}
	
	newnode->data=value;
	newnode->next=NULL;
	if(lq->rear==NULL){
		lq->front=lq->rear=newnode;
	}else{
		lq->rear->next=newnode;
		lq->rear=newnode;
	}
}

int deletelinkqueue(linkqueue *lq,DataType *value){
	if(isemptyqueue(lq)){
		printf("queue is null\n");
		return 0;
	}
	linkqueuenode *p=lq->front->next;
	*value=p->data;
	lq->front->next=p->next;
	if(lq->rear==p){
		lq->rear=lq->front;
	}
	free(p);
//    linkqueuenode * p=lq->front;
//    *value=p->data;
//    lq->front=lq->front->next;
//    free(p);
//    if(lq->front==NULL){
//    	lq->rear=NULL;
//	}
	return 1;
	
}


int getheaddata(linkqueue *lq,DataType *value){
	if(isemptyqueue(lq)){
		printf("queue is null\n");
		return 0;
	}
	
	*value=lq->front->data;
	return 1;
}


int getqueuelength(linkqueue *lq){
	int length=0;
	linkqueuenode *i=lq->front;
	while(i!=NULL){
		length++;
		i=i->next;
	}
	return length;
}


void printlinkqueue(linkqueue *lq){
	linkqueuenode *i=lq->front;
	while(i!=NULL){
		printf("%d",i->data);
		i=i->next;
	}
	printf("\n");
}

void clearqueue(linkqueue *lq){
	while(lq->front!=NULL){
	linkqueuenode*temp=lq->front;
	lq->front=lq->front->next;
	free(temp);	
	}
	lq->rear=NULL;
}

void test_queue(){
	DataType value;
	linkqueue *lq=(linkqueue*)malloc(sizeof(linkqueue));
	if(lq==NULL){
		printf("memory allocation failed\n");
		return;
	}
	initqueue(lq);
	enterlinkqueue(lq,1);
	enterlinkqueue(lq,3);
	enterlinkqueue(lq,5);
	printf("queue elements:");
	printlinkqueue(lq);
	
	value=getqueuelength(lq);
	printf("queue length:%d",value);
	
	
	getheaddata(lq,&value);
	printf("first element:%d",value);
	
	
	deletelinkqueue(lq,&value);
	printf("delete element:%d",value);
	
	printf(" after queue elements :");
	
	printlinkqueue(lq);
	
	clearqueue(lq);
	free(lq);
}

int main(){
	test_queue();
	return 0;
}
