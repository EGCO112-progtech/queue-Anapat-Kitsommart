typedef struct node{
   struct node *nextPtr;
   int order_number;
   int qlt;
}new_order_n;

typedef struct node* NodePtr;

typedef struct {
	NodePtr headPtr,tailPtr;
	int size;
}Queue;

void enqueue_struct(Queue* q, int menu, int num){
	new_order_n *new_order=(new_order_n*) malloc(sizeof(new_order_n));
	if(new_order){ 
	
		new_order->order_number=menu;
		new_order->qlt=num;
		new_order->nextPtr=NULL;
		
		if(q->size==0) q->headPtr=new_order;
		else q->tailPtr->nextPtr=new_order;
		q->tailPtr=new_order;
		q->size++;
	}
}


int dequeue_struct(Queue *q){
	NodePtr t=q->headPtr;
	int price,cash;
	if(q->size>0){
		switch(t->order_number){
			case 1: printf("Ramen\n");
					price=100*(t->qlt);
					break;
			case 2: printf("Somtum\n");
					price=200*(t->qlt);
					break;
			case 3: printf("Curry\n");
					price=2000*(t->qlt);
					break;
			default: printf("No Food\n");
					 price=0;
		}
	}
	
	if(t){
		int value= t->order_number;
		q->headPtr = t->nextPtr;
		if(q->headPtr==NULL) q->tailPtr=NULL;
		free(t);
		q->size--;
		return price;
	}
	printf("Empty queue\n");
	return 0;
}

