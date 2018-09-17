#include "node.h"
#include <iostream>

using namespace std;

node::node(int data){                                                           //class to allocate memory for each node
    this->data = data;
    rank = 1;
    lftchild = NULL;
    rtchild  = NULL;
}
