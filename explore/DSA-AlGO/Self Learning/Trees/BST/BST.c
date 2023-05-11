#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *findElement(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        return findElement(root->left, data);
    } else if (data > root->data) {
        return findElement(root->right, data);
    }
    return root;
}

struct node *findElementNR(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    while (root) {
        if (data == root->data) {
            return root;
        } else if (data > root->data) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return NULL;
}

struct node *findMinElement(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return findMinElement(root->left);
    }
}

struct node *findMinElementNR(struct node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node *findMaxElement(struct node *root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right == NULL) {
        return root;
    } else {
        return findMaxElement(root->right);
    }
}

struct node *findMaxElementNR(struct node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node *insertElement(struct node *root, int data) {
    if (root == NULL) {
        root = (struct node *) malloc(sizeof(struct node));
        if (root == NULL) {
            printf("Memory Error");
            exit(0);
        } else {
            root->data = data;
            root->left = root->right = NULL;
        }
    } else {
        if (data < root->data) {
            root->left = insertElement(root->left, data);
        } else if (data > root->data) {
            root->right = insertElement(root->right, data);
        }
    }
}

struct node *deleteElement(struct node *root, int data) {
    struct node *temp;
    if (root == NULL) {
        printf("Element not found");
    } else if (data < root->data) {
        root->left = deleteElement(root->left, data);
    } else if (data > root->data) {
        root->right = deleteElement(root->right, data);
    }
    else{
        if(root->left&&root->right){
            temp = findMaxElement(root->left);
            root->data = temp->data;
            root->left = deleteElement(root->left,root->data);
        }
        else{
            temp = root;
            if(root->left==NULL){
                root=root->right;
            }
            if(root->right==NULL){
                root=root->left;
            }
            free(temp);
        }
    }
    return root;
}

int main(void) {
    return 0;
}