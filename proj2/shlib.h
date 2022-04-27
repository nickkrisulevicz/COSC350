//Nick Krisulevicz
//COSC 350
//Project 2
//Create a shared library to build the binary tree to store the character bits
//04/29/2022
//shlib.h

#ifndef SHLIB_H
#define SHLIB_H

//pair structure holds each ASCII character read from the input file and the amount of times it appears
struct pair{
	int freq;
	char value;
};

//qnode structure to hold each pair and a pointer to the next node to be stored in a linked list
struct qnode{
	struct pair nodevalue;
	struct qnode *next;
};

//-------------------------------------------------------------------------------------------------------------------------------

//Begin code for Phase 2 of project

/*

struct qnode{
	struct tnode *nodeaddress;
	struct qnode * next;
}

struct tnode
	struct pair nodevalue;
	struct tnode *parent;
	struct tnode *left;
	struct tnode *right;
}

struct tnode * createtreenode(struct pair selectpair){
	struct tnode * newnode;
	newnode = malloc(sizeof(struct tnode));
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

*/

//-------------------------------------------------------------------------------------------------------------------------------

//push function allows created nodes to be pushed onti the queue
//NOTE: there are many test printf statements used for testing for issues with this function
void pushqueue(struct qnode **front, struct qnode *newnode){
	//initialize node pointers
	struct qnode *nodeptr1 = *front;
	struct qnode *nodeptr2 = newnode;
	//printf("initialized node pointers\n");

	//if there is no front, create a front with the new node
	if(!(*front)){
		//printf("front -> next does not exist\n");
		(*front) = newnode;
		//printf("made front -> next the new node\n");
	}
	//otherwise, traverse through the queue until the target destination is found to push
	else{
		//printf("passed the first node pushed, beginning if statement\n");
		//if the front is lower value than the new node, make the new node the new front
		if((*front)->nodevalue.freq < newnode->nodevalue.freq){
			//printf("successfully entered if statement\n");
			nodeptr2->next = *front;
			*front = nodeptr2;
			//printf("if statement complete\n");
		}
		//otherwise, find the location in the queue based on the frequency of the nodevalue
		else{
			//printf("Entered else statement\n");
			while(nodeptr1->next != NULL && (nodeptr1->nodevalue).freq < (newnode->nodevalue).freq){
				//printf("entered while loop\n");
				nodeptr1 = nodeptr1->next;			
			}
			//printf("while loop complete\n");
			nodeptr2->next = nodeptr1->next;
			nodeptr1->next = nodeptr2;
		}
	}
//-------------------------------------------------------------------------------------------------------------------------------
	
	//SPARE CODE FOR PUSH FUNCTION THAT WAS NOT WORKING BUT I DON'T WANT TO GET RID OF IT YET

	/*
	//initialize each node pointer
	struct qnode *min = *front;
	struct qnode *prevnode = ;
	struct qnode *nodeptr = *front;

	if((*front)->next == NULL){
		(*front)->next = newnode;
	}

	//traverse through queue and find min
	while(nodeptr != ){
		if(nodeptr->nodevalue.freq < newnode->nodevalue.freq){
			prevnode = nodeptr;
			prevnode->next = newnode;
			newnode->next = nodeptr;
		}
		prevnode = nodeptr;
		nodeptr = nodeptr->next;
	}

	/*
	//reset the node pointers back to beginning of queue
	nodeptr->next = *front;
	prevnode = NULL;

	//reach the end of the list
	while(nodeptr != NULL){
		prevnode = nodeptr;
		nodeptr = nodeptr->next;
	}

	//insert the min at the end
	if(nodeptr->next == NULL){
		prevnode = nodeptr;
		nodeptr->next = min;
		min->next = NULL;
	}
	*/
//-------------------------------------------------------------------------------------------------------------------------------
}

//popqueue function removes a qnode from the front of the queue and frees dynamically allocated space
struct qnode * popqueue(struct qnode **front){
	//create a node to pop
	struct qnode *popnode = *front;
	//assign the front to the pointee of front->next
	*front = (*front)->next;
	//get rid of the old front once the front pointer is relocated
	free(popnode);
}

//-------------------------------------------------------------------------------------------------------------------------------

//createnode function takes a pair, and allocates memory for it, then sets the next pointer to null, and then returns it
struct qnode * createnode(struct pair selectpair){
	//dynamically allocate the memory for the node
	struct qnode *newnode = malloc(sizeof(struct qnode));
	//initialize the values for the new node
	newnode->next = NULL;
	newnode->nodevalue = selectpair;
	//return the new node
	return newnode;
}

//-------------------------------------------------------------------------------------------------------------------------------

//THE FUNCTIONS BELOW ARE SIMILAR TO THE ONES DISCUSSED IN CLASS

/*

//pushqueue function takes a node from createnode function, and then inserts it into the queue
void pushqueue(struct qnode **front, struct qnode *newnode){
	newnode->next = *front;
	*front = newnode;
}

//structure to pop a node from the front of the queue
//it only pops one at a time so a for loop will be needed in the main function to pop all of them
struct qnode * popqueue(struct qnode **front){
	//create a minimum node to use for the priority queue to be popped
	struct qnode *min = *front;
	//create a node pointer to iterate through the queue
	struct qnode *nodeptr = *front;
	//create a previous node pointer to reconnect the linked list when the pop operation is done
	struct qnode *prevnode = NULL;
	//iterate through the list
	while(nodeptr != NULL){
		//if a lower value is found, set that as the new min
		if((nodeptr->nodevalue).freq < (min->nodevalue).freq){
			min = nodeptr;
		}
		prevnode = nodeptr;
		nodeptr = nodeptr->next;
	}
	//need to change front's pointer once the rest of the nodes have been taken care of
	if(!front){
		prevnode->next = min->next;
	}
	else{
		*front = (*front)->next;
	}
	//pop the min
	return min;
}

*/

//-------------------------------------------------------------------------------------------------------------------------------

//print function to iterate through the list and print the value and frequency of every node
//currently causes a segmentation fault for reason not yet figured out
void printqueue(struct qnode *front){
	struct qnode *nodeptr = front;
	while(nodeptr != NULL){
		printf("Value: %s Frequency: %d\n", (nodeptr->nodevalue).value, (nodeptr->nodevalue.freq));
		nodeptr = nodeptr->next;
	}
}

//top function used to go along with pop function for the time being to print the queue
struct qnode * topnode(struct qnode **front){
	return *front;
}


//Use huffman coding to make a binary tree
//greedy algorithm
//use this tree as a shared library in compress and decompress program


#endif
