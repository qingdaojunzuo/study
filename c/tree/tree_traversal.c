#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

typedef struct node {
    struct node* left;
    struct node* right;
    int data;
} tree;

static tree* new_tree(int data) {
    tree* new = (tree*)malloc(sizeof(tree));
    new->left = NULL;
    new->right = NULL;
    new->data = data;
    return new;
}

static tree* prepare_tree() {
    tree* root = new_tree(6);
    // left children of root
    root->left = new_tree(4);
    root->left->left = new_tree(2);
    root->left->right = new_tree(5);
    root->left->left->left = new_tree(1);
    root->left->left->right = new_tree(3);
    // right children of root
    root->right = new_tree(8);
    root->right->left = new_tree(7);
    root->right->right = new_tree(9);
    return root;
}

static void pre_order(tree* root) {
    stack* s = NULL;
    while(root || !empty(s)) {
        if (root) {
            printf("%d", root->data);
            push(&s, root);
            root = root->left;
        } else {
            root = (tree*)pop(&s);
            root = root->right;
        }
    }
    printf("\n");
}

static void pre_order_r(tree* root) {
    if (!root)
        return;
    printf("%d", root->data);
    pre_order_r(root->left);
    pre_order_r(root->right);
}

static void in_order(tree* root) {
    stack* s = NULL;
    while (root || !empty(s)) {
        if (root) {
            push(&s, root);
            root = root->left;
        } else {
            root = (tree*)pop(&s);
            printf("%d", root->data);
            root = root->right;
        }
    }
    printf("\n");
}

static void in_order_r(tree* root) {
    if (!root)
        return;
    in_order_r(root->left);
    printf("%d", root->data);
    in_order_r(root->right);
}

static void post_order(tree* root) {
    stack* s = NULL;
    while (root || !empty(s)) {
        if (root) {
            if (root->right)
                push(&s, root->right);
            push(&s, root);
            root = root->left;
        } else {
            root = (tree*)pop(&s);
            if (root->right && root->right == peek(s)) {
                pop(&s);
                push(&s, root);
                root = root->right;
                continue;
            }
            printf("%d", root->data);
            root = NULL;
        }
    }
    printf("\n");
}

static void post_order_ds(tree* root) {
    stack *s = NULL, *out = NULL;
    push(&s, root);
    while(!empty(s)) {
        tree* root = (tree*)pop(&s);
        push(&out, root);
        if (root->left)
            push(&s, root->left);
        if (root->right)
            push(&s, root->right);
    }
    while(!empty(out)) {
        tree* node = (tree*)pop(&out);
        printf("%d", node->data);
    }
    printf("\n");
}

static void post_order_r (tree* root) {
    if (!root)
        return;
    post_order_r(root->left);
    post_order_r(root->right);
    printf("%d", root->data);
}

int main(int argc, char* argv[]) {
    tree* root = prepare_tree();
    // pre order 
    pre_order(root);
    // pre order recursion
    pre_order_r(root);
    printf("\n");

    // in order
    in_order(root);
    // in order recursion
    in_order_r(root);
    printf("\n");

    // post order with 1 stack
    post_order(root);
    // post order with 2 stacks
    post_order_ds(root);
    // post order recursion
    post_order_r(root);
    printf("\n");

    return 0;
}