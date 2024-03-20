/*Develop a menu driven program to implement Binary Search tree with the followingoperations.
i) Construction ii) Traversals (Pre, In and Post Order) iii) Searching a node by key and deleting if 
exists ( node to be deleted may be leaf or non- leaf with one child ortwo children)*/
/*14. Develop a menu driven program to implement Binary Search tree with the followingoperations.
i) Construction ii) Traversals (Pre, In and Post Order) iii) Searching a node by key and displaying its 
information along with its parent if exists, otherwise a suitablemessage. iv)Counting all nodes. v) 
Finding height. vi Finding node with the Maximum key value and printing the node details along
with the parent.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}NODE;
NODE* createnode(int data){
    NODE* newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
NODE* insert(NODE* root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(root->data<data){
        root->right=insert(root->right,data);
    }else{
        root->left=insert(root->left,data);
    }
    return root;
}
void postorder(NODE* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void preorder(NODE* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(NODE* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
NODE* findis(NODE* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
NODE* deletebykey(NODE* root,int key){
    if(root==NULL){
        printf("Key not found\n");
        return NULL;
    }
    if(root->data>key){
        root->left=deletebykey(root->left,key);
    }else if(root->data<key){
        root->right=deletebykey(root->right,key);
    }else{
        //case 1
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }else if(root->left==NULL){
            return root->right;
        }else if(root->right==NULL){
            return root->left;
        }else{
            NODE* is=findis(root->right);
            root->data=is->data;
            root->right=deletebykey(root->right,is->data);
        }
    }
    return root;
}
int main(){
    NODE* root=NULL;
    int choice;
    do{
        printf("MENU\n1.Construction\n2.preorder\n3.postorder\n4.inorder\n5.Delete node\n6.exit\n");
        printf("Enter ur choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : int data;
            printf("Enter data\n");
            scanf("%d",&data);
            root=insert(root,data);
            break;
            case 2: preorder(root);
            break;
            case 3:  postorder(root);
            break;
            case 4 : inorder(root);
            break;
            case 5: int key;
            printf("enter key\n");
            scanf("%d",&key);
            root=deletebykey(root,key);
            break;
            case 6:exit(0);
        }
    }while(choice!=7);
    return 0;
}