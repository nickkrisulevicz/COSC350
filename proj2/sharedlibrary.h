//Nick Krisulevicz
//COSC 350
//Project 2
//05/06/2022
//Shared library for the compress and decompress programs
//05/06/2022

//struct definitions
struct pair{
        char value;
        int freq;
};

struct tnode{
        struct tnode *nodeaddress;
        struct tnode *next;
        struct tnode *parent;
        struct tnode *left;
        struct tnode *right;
};


//function definitions
struct tnode * createnode(struct pair selectpair){
        struct tnode *newnode;
        newnode = malloc(sizeof(struct tnode));
        newnode->parent = NULL;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->next = NULL;
        return newnode;
}

