#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct nodoTree{
    int val;
    struct nodo *left;
    struct nodo *right;
}NodoTree;

NodoTree *createNodo(int val){
    NodoTree *n = (NodoTree*) malloc(sizeof(NodoTree));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

NodoTree* add(NodoTree* root,int val){
    if(root == NULL) return createNodo(val);
    if(val <= root->val) root->left = add(root->left,val);
    else root->right = add(root->right,val);
    return root;
}

NodoTree *search(NodoTree *root,int val){
    if(val == root->val) return root;
    if(root == NULL) return NULL;
    if(val <= root->val) search(root->left,val);
    else search(root->right,val);

}

int height(NodoTree *root){
    if(root == NULL) return 0;
    return 1 + fmax(height(root->left), height(root->right));
}

int level(NodoTree *root,int val,int acc){
    if(root->val == val) return acc;
    if(val <= root->val) level(root->left,val,++acc);
    else level(root->right,val,++acc);
}

bool isSheet(NodoTree *root,int val){
    int h = height(root);
    int l = level(root,val,1);
    return h == l;
}

void preorder(NodoTree *root){
    if(root != NULL){
        printf("%d\n",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NodoTree *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n",root->val);
        inorder(root->right);
    }
}

void postorder(NodoTree *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->val);
    }
}

//test of the bst operation
int main() {
    NodoTree *root = NULL;
    root = add(root, 50);
    add(root, 30);
    add(root, 70);
    add(root,20);
    add(root,40);
    add(root,60);
    preorder(root);
    printf("height: %d\n", height(root));
    printf("level: %d\n", level(root,40,1));
    printf("is sheet? %d\n", isSheet(root,60));
    return 0;
}