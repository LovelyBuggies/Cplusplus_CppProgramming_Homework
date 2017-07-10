#include "RHTree.hpp"

//constructor destructor
RHTree::RHTree(){
  root=NULL;
}
RHTree::~RHTree(){
  clear(&root);
}
//insertion
void  RHTree::insert(int element){
  assistant(&root,element);
}

node* RHTree::getRoot(void ){
  return root;
}

//traverse
void RHTree::preOrder(node*r){
  if(r==NULL) return;
  cout<< " "<< r->ele ;
  preOrder(r->left);
  preOrder(r->right);
}
void RHTree::inOrder(node*r){
  if(r==NULL) return;
  inOrder(r->left);
  cout<< " "<< r->ele ;
  inOrder(r->right);
}
void RHTree::postOrder(node*r){
  if(r==NULL) return;
  postOrder(r->left);
  postOrder(r->right);
  cout<< " "<< r->ele ;
}
void RHTree::clear(node**r){
  if((*r)==NULL) return;
  clear(&((*r)->left));
  clear(&((*r)->right));
  delete (*r);
}

void RHTree::assistant(node** p,int element){
  if((*p)==NULL) {
    (*p)=new node(element);
    return ;
  }
  if(element<=(*p)->ele)
    assistant(&((*p)->left),element);
  else assistant(&((*p)->right),element);
}