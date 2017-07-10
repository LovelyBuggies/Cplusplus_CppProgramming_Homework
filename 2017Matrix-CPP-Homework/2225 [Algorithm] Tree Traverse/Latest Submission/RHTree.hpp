#include <iostream>
using namespace std;
struct node {
  int ele;
  node* left;
  node* right;
  node(int e):left(0), right(0){
    ele = e;
  }
};


class RHTree {
private:
    node* root;
public:
  	//constructor destructor
    RHTree();
    ~RHTree();
    //insertion
    void insert(int element);
    node* getRoot(void );
    //traverse
    void preOrder(node*);
    void inOrder(node*);
    void postOrder(node*);
    void clear(node**);
    void assistant(node**, int);
};

