#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
	/*NodePtr headPtr=NULL;
	NodePtr tailPtr=NULL;*/
//For struct Queue
	Queue  q;
	q.headPtr=NULL;
	q.tailPtr=NULL;
	q.size=0;

   int i,x,count=1;
   

 for(i=1;i<argc;i++){
    if(strcmp(argv[i],"x")==0){
        //x=dequeue(&headPtr,&tailPtr);
		printf("Customer number: %d\n",count);
		x=dequeue_struct(&q);
		
		if(x!=0){
			printf("You have to pay %d\n",x);
			mark:
			printf("Cash: ");
			int cash;
			scanf("%d",&cash);
			if(cash<x) goto mark;
			printf("Thank you\n");
			if(cash>x) printf("Change: %d\n", cash-x);
		}
		count++;
    }
    else {
		//enqueue(&headPtr,&tailPtr, atoi(argv[i])); 
		enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
		i++;
    }
 }
 
 printf("===============================\n");
 if(q.size==1) printf("There is 1 people left in the queue.\n");
 else if(q.size==0) printf("There is no person left in the queue.\n");
 else printf("There are %d people left in the queue.\n",q.size);
 
 while(q.size>0){
		dequeue_struct(&q);
	}
	
  return 0;
}