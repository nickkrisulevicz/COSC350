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

//tnode structure to hold each pair and a pointer to the next node to be stored in a lpriority queue and the huffman tree
struct tnode{
	struct pair nodevalue;
	struct tnode *next;
	struct tnode *parent;
	struct tnode *left;
	struct tnode *right;
};


//push function allows created nodes to be pushed onti the queue
//NOTE: there are many test printf statements used for testing for issues with this function
void pushqueue(struct tnode **front, struct tnode *newnode){
	//initialize node pointers
	//struct tnode *nodeptr1 = *front;
	//struct tnode *nodeptr2 = newnode;
	struct tnode *nodeptr = *front;

	//if there is no front, create a front with the new node


	while(nodeptr != NULL){
		nodeptr = nodeptr->next;
	}
	newnode->next = nodeptr;
	
	/*
	if(!(*front)){
		(*front) = newnode;
	}
	
	//otherwise, traverse through the queue until the target destination is found to push
	else{
		//printf("passed the first node pushed, beginning if statement\n");
		//if the front is lower value than the new node, make the new node the new front
		if(((*front)->nodevalue).freq > (newnode->nodevalue).freq){
			nodeptr2->next = *front;
			*front = nodeptr2;
		}
		//otherwise, find the location in the queue based on the frequency of the nodevalue
		else{
			while(nodeptr1->next != NULL && (nodeptr1->nodevalue).freq < (newnode->nodevalue).freq){
				nodeptr1 = nodeptr1->next;			
			}
			nodeptr2->next = nodeptr1->next;
			nodeptr1->next = nodeptr2;
		}
	}
	*/
}

//popqueue function removes a qnode from the front of the queue and frees dynamically allocated space
struct tnode * popqueue(struct tnode **front){
	//create a node to pop
	struct tnode *popnode = *front;
	//assign the front to the pointee of front->next
	*front = (*front)->next;
	//get rid of the old front once the front pointer is relocated
	free(popnode);
}

struct tnode * poppriority(struct tnode **front){
	struct tnode *nodeptr = *front;
	struct tnode *min = *front;
	struct tnode *prev = NULL;
	while(nodeptr != NULL){
		prev = nodeptr;
		nodeptr = nodeptr->next;
		if((nodeptr->nodevalue).freq < (min->nodevalue).freq){
			min = nodeptr;
			prev = nodeptr->next;
			free(nodeptr);
			return min;
		}
	}
	printf("End of while loop reached\n");
}

//createnode function takes a pair, and allocates memory for it, then sets the next pointer to null, and then returns it
struct tnode * createnode(struct pair selectpair){
	//dynamically allocate the memory for the node
	struct tnode *newnode = malloc(sizeof(struct tnode));
	//initialize the values for the new node
	newnode->next = NULL;
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->nodevalue = selectpair;
	//return the new node
	return newnode;
}

//top function used to go along with pop function for the time being to print the queue
struct tnode * topnode(struct tnode **front){
	return *front;
}


//Use huffman coding to make a binary tree
//greedy algorithm
//use this tree as a shared library in compress and decompress program


#endif
