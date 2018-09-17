#ifndef NODE_H
#define NODE_H

class node{
	public:
	       node(int data);                                                      //function to allocate memory for each node

	       int data;                                                            //data or key in the node
	       int rank;                                                            //rank of each node (only for Leftist heap)
	       node* lftchild;                                                      //left child
	       node* rtchild;                                                       //right child
};

#endif
