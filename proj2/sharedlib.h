//Nick Krisulevicz
//COSC 350
//Project 2
//05/06/2022
//shared library for both huff and unhuff programs
//sharedlib.h

//-------------------------------------------------------------------------------
//STRUCT DEFINITIONS

//pair struct definition
struct pair{
	char value;
	int freq;
};

//tree node struct definition
struct tnode{
	//struct pair contained within the tnode
	struct pair *nodevalue;
	//pointers for the other nodes in the tree
	struct tnode *parent;
	struct tnode *left;
	struct tnode *right;
};

//queue node struct definition
struct qnode{
	//struct tnode contained within teh qnode
	struct tnode *nodeaddress;
	//pointer to the next qnode in the queue
	struct qnode *next;
};

//-------------------------------------------------------------------------------
//TREE NODE FUNCTIONS

//create a tnode function
struct tnode * createtreenode(struct pair selectpair){
	struct tnode * newnode;
	//dynamically allocate memory for the new node
	newnode = malloc(sizeof(struct tnode));
	//assign all the pointers
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	//return the new node to the main function
	return newnode;
}

//-------------------------------------------------------------------------------
//QUEUE NODE FUNCTIONS

//top function used to go along with pop function for the time being to print the queue
struct qnode *topqueuenode(struct qnode **pqueuetop){
	return *pqueuetop;
}

//createnode function takes a pair, and allocates memory for it, then sets the next pointer to null, and then returns it
struct qnode *createqueuenode(struct tnode selectnode){
	//dynamically allocate memory for the new node
	struct qnode *newnode = malloc(sizeof(struct tnode));
	//assign the pointers
	newnode->next = NULL;
	newnode->nodeaddress = &selectnode;
	//return the new node to the main function
	return newnode;
}

//popqueue function removes a qnode from the front of the queue and frees dynamically allocated space
struct qnode *popqueue(struct qnode **pqueue){
	//initialize a temporary node to get rid of the front of the queue
	struct qnode *popnode = *pqueue;
	//assign the front of the queue to the next one
	*pqueue = (*pqueue)->next;
	//free the memory from the dynamically allocated node
	free(popnode);
}

//poppriority function removes a qnode from the queue in order of its priority, take the minimum node out
struct qnode *poppriority(struct qnode **pqueue){
	//establish node pointers
	struct qnode *nodeptr = *pqueue;
	struct qnode *prev = *pqueue;
	struct qnode *min = NULL;
	//until the end of the queue, traverse through the queue
	while(nodeptr != NULL){
		prev = nodeptr;
		nodeptr = nodeptr->next;
		//if a new minimum is found, assign that one as the new minimum
		if(nodeptr->nodeaddress->nodevalue->freq < min->nodeaddress->nodevalue->freq){
			min = nodeptr;
			prev->next = nodeptr->next;
		}
	}
	//free the memory for the popped node
	free(nodeptr);
	//return the minimum node to the main function
	return min;
}

struct qnode *printpriority(struct qnode **pqueue){
	//create the node pointer
	struct qnode *nodeptr = *pqueue;
	//until the end of the queue, traverse the queue
	while(nodeptr != NULL){
		//print the value of the pair struct inside the tnode struct inside the qnode struct
		printf("Value: %c, Frequency: %d\n", nodeptr->nodeaddress->nodevalue->value, nodeptr->nodeaddress->nodevalue->freq);
		popnode = nodeptr;
		nodeptr = nodeptr->next;
		//call the pop priority function to pop the minimum node and show the next minimum one
		poppriority(&pqueue);
	}
}

//pushqueue function takes a tree node and inserts it into the priority queue as a queue node
void pushqueue(struct qnode **pqueue, struct tnode *newnode){
	//create nodepointers
	struct qnode *front = *pqueue;
	struct qnode *tempnode = createqueuenode(*newnode);
	//if there is no front, make the new node the front
	if(front == NULL){
		front = tempnode;
		front->next = NULL;
	}
	//if the new node is less than the front, make the new node the new front
	if(front->nodeaddress->nodevalue->freq > tempnode->nodeaddress->nodevalue->freq){
		tempnode->next = front;
		front = tempnode;
	}
	//otherwise traverse the rest of the queue
	else{
		//until minimum is found, keep traversing
		while(front->next != NULL && front->next->nodeaddress->nodevalue->freq < newnode->nodevalue->freq){
			front = front->next;
		}

		//assign the pointers to the correct positions to insert the new node into the queue
		tempnode->next = front->next;
		front->next = tempnode;
	}
}

//function to determine if the queue is empty and returns true if it is empty, and false if it contains at least one node
int isqueueempty(struct qnode **pqueue){
	return (*pqueue) == NULL;
}


//print function to print nodes in queue and then pop them
//print function currently has issues
void printqueue(struct qnode **pqueue){
	//initialize node pointer
	struct qnode *nodeptr = *pqueue;
	//while the is empty function is not true, traverse until the end of the queue
	while(!isqueueempty(pqueue)){
		//print the value and frequency within the pair struct within the tnode struct within the qnode struct
		printf("Value: %c Frequency: %d", topqueuenode(&(nodeptr->nodeaddress->nodevalue->value)), topqueuenode(&(nodeptr->nodeaddress->nodevalue->freq)));
		popqueue(&pqueue);
	}
}