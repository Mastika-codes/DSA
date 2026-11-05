#include<iostream>
using namespace std;
struct BSTNode{
int data;
BSTNode*leftchild;
BSTNode*rightchild;
};
class BinarySearchTree{
private:
    BSTNode *root;
public:
    void insertBST(int);
    bool searchBST(int);
    void deleteBST(int);
    void preorderTraversal();
    void preorder(BSTNode*);
    void inorderTraversal();
     void inorder(BSTNode*);
     void postorderTraversal();
     void postorder(BSTNode*);
     BSTNode *findMin(BSTNode*);
       BSTNode *findMax(BSTNode*);
       int findHeight();
       int totalNode();
       int totalLeaTree();
       BinarySearchTree();
       ~BinarySearchTree();
       void destroyNode(BSTNode*);
       bool isTreeEmpty();
};

BinarySearchTree::BinarySearchTree(){
root=NULL;

}
BinarySearchTree::~BinarySearchTree(){
    destroyNode(root);}
void BinarySearchTree:: destroyNode(BSTNode*temp){
if(temp==NULL){
    return;
}
else{
    destroyNode(temp->leftchild);
    destroyNode(temp->rightchild);
    delete temp;
}

}
void BinarySearchTree:: insertBST(int newdata){

BSTNode *temp=new BSTNode;
temp->data=newdata;
temp->leftchild=NULL;
temp->rightchild=NULL;
    if(root==NULL){
        root=temp;

    }
    else{
        BSTNode*current, *prevcurrent;
        current=root;
while(current!=NULL){
    prevcurrent=current;
    if(current->data==newdata){
        cout<<"duplicated data is not allowed in bst";
        return;
    }
    else if(current->data>newdata){
        current=current->leftchild;
    }
    else{
        current=current->rightchild;
    }

}
if(prevcurrent->data>newdata){
        prevcurrent->leftchild=temp;

}
else{
    prevcurrent->rightchild=temp;
}}
cout<<"data succefully stored ";
}
bool BinarySearchTree:: searchBST(int searchKey){
    bool found=false;
    if(root==NULL){
        cout<<"tree is empty ";

    }
    else{
        BSTNode*current=root;
        while(current!=NULL&& !found){
            if(current->data==searchKey){
                found=true;
                break;
            }
            else if(current->data>searchKey){
                current=current->leftchild;
            }
            else{
                current=current->rightchild;
            }
        }
    }
    return found;
}
void BinarySearchTree::preorderTraversal(){
    preorder(root);


}
void BinarySearchTree:: preorder(BSTNode*temp){
if(temp!=NULL){
    cout<<"\t"<<temp->data;
    preorder(temp->leftchild);
    preorder(temp->rightchild);
}

}
void BinarySearchTree:: inorderTraversal(){
inorder(root);
        }
        void BinarySearchTree:: inorder(BSTNode*temp){
if(temp!=NULL){
    inorder(temp->leftchild);
    cout<<"\t"<<temp->data;
    inorder(temp->rightchild);
}}
void BinarySearchTree:: postorderTraversal(){
postorder(root);
        }
void BinarySearchTree:: postorder(BSTNode*temp){
if(temp!=NULL){
    postorder(temp->leftchild);
    postorder(temp->rightchild);
      cout<<"\t"<<temp->data;
}}



void BinarySearchTree:: deleteBST(int deleteKey){


    BSTNode*current,*prevCurrent,*temp;
    bool found = false;
    if(root == NULL){
        cout<<"the tree is empty ";

    }
    else{
        current=root;
        while(current!=NULL){
        prevCurrent = current;
        if(current->data == deleteKey){
                found = true;
        break;

        }
        else if(current->data>deleteKey){
            current = current->leftchild;

        }
        else{
            current = current->rightchild;
        }

        }
        if(!found){
            cout<<"\n item is not found ";\

        }
        else{
                if(prevCurrent->data < deleteKey){
                  if(current->leftchild == NULL&&current->rightchild == NULL){
                    prevCurrent->rightchild=current->rightchild=NULL;
                    delete current;
                  }
                  else if(current->rightchild == NULL){
                     prevCurrent->rightchild=current->leftchild;
                    delete current;
                    }
                    else if(current->leftchild == NULL&&current->rightchild!=NULL){
                    temp=current->leftchild;
                  while(temp->rightchild!=NULL){
                    temp=temp->rightchild;
                  }
                  current->data = temp->data;
                  delete temp;

                    }
                  }
                  else{
                    if(current->leftchild == NULL){
                        prevCurrent->leftchild=current->rightchild;
                        delete current;
                    }
                    else if(current->rightchild == NULL){
                    prevCurrent->leftchild=current->leftchild;
                        delete current;

                            }
                            else if(current->rightchild!=NULL&current->leftchild!=NULL){
                                temp=current->leftchild;
                                while(temp->rightchild!=NULL){
                                    temp=temp->rightchild;
                                }
                                current->data=temp->data;
                                delete temp;
                            }
                  }
                }

        }

    }
int main(){
    BinarySearchTree bst;
char op;
int item;
int searchItem;
int deleteItem;



menu:
    cout<<"\n press 1 to insert item ";
       cout<<"\n press 2 to search item ";
          cout<<"\n press 3 to delete item ";
             cout<<"\n press 4 preorderTraversal";
                cout<<"\n press 5 inordertraversal ";
                   cout<<"\n press 6 postordertraversal ";
                      cout<<"\n exit 0";
                        cout<<"\n select operation: ";
                      cin>>op;
                      switch(op){
                  case '1':
                    cout<<"\n enter new data";
                    cin>>item;
                    bst.insertBST(item);
                    break;
                  case '2' :
                    cout<<"\n enter the item to be searched ";
                    cin>>searchItem;
                    if(bst.searchBST(searchItem)){
                    cout<<"\n item is found in the tree ";

                    }
                    else{
                        cout<<"\n item is not found ";
                    }
                    break;
                  case '3':
                    cout<<"\n enter the item to be deleted";
                    cin>>deleteItem;
                    bst.deleteBST(deleteItem);
                    break;
                  case '4':
                    cout<<"\n preorder: ";
                    bst.preorderTraversal();
                    break;
                  case '5':
                    cout<<"\n inorder: ";
                    bst.inorderTraversal();
                    break;
                  case '6':
                    cout<<"\n postorder: ";
                    bst.postorderTraversal();
                    break;
                  case '0':
                    return 0;
                      }
                      goto menu;
                      return 0;

}
