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
void searchbykey(NODE* root,int key,NODE* par){
    if(root==NULL){
        printf("Key not found\n");
        return;
    }
    if(root->data==key){
        printf("key found\n");
        if(par==NULL){
            printf("NO PARENT EXISTS\n");
        }else{
            printf("%d is parent\n",par->data);
        }
        return;
    }
    par=root;
    if(root->data<key){
        searchbykey(root->right,key,par);
    }else{
        searchbykey(root->left,key,par);
    }
}
int countnodes(NODE* root){
    if(root==NULL){
        return 0;
    }
    int left=countnodes(root->left);
    int right=countnodes(root->right);
    return left+right+1;
}
int max(int a,int b){
    return a>b?a:b;
}
int height(NODE* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
void findmax(NODE* root,NODE* par){
    if(root==NULL){
        printf("tree empty\n");
        return;
    }
    if(root->right==NULL){
        printf("%d is max node \n",root->data);
        if(par==NULL){
            printf("no parent\n");
        }else{
            printf("%d is parent\n",par->data);
        }
        return;
    }
    par=root;
    findmax(root->right,par);
}
int main(){
    NODE* root=NULL;
    int choice;
    do{
        printf("MENU\n1.Construction\n2.preorder\n3.postorder\n4.inorder\n5.no. of nodes\n6.height\n7.searchbykey\n8.maxnode\n9.exit\n");
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
            case 5 : printf("No. of nodes : %d\n",countnodes(root));
            break;
            case 6 : printf("Height of tree : %d\n",height(root));
            break;
            case 7: int key;
            printf("enter key\n");
            scanf("%d",&key);
            searchbykey(root,key,NULL);
            break;
            case 8 : findmax(root,NULL);
            break;
            case 9:exit(0);
        }
    }while(choice!=9);
    return 0;
}