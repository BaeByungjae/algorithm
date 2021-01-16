// 2017029743_BaeByungJae_A
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node {
    int key;
    char value[4];
    struct node* parent;
    int height;
    struct node* left_node;
    struct node* right_node;
}node;
node* inputs[50000];
node* heap[50000];
int size = 0;
void swap(node** arr, int a, int b)
{
    node* temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void heapify(node** arr, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int min_index = i;
    if (l <= size && (arr[i])->key >= (arr[l])->key) min_index = l;
    if (r <= size && (arr[min_index]->key >= (arr[r])->key)) min_index = r;
    if (min_index != i)
    {
        swap(arr, i, min_index);
        heapify(arr, min_index);
    }
}
void build_min_heap(node** arr)
{
    int i = size / 2;
    for (i; i > 0; i--)
    {
        heapify(arr, i);
    }
}


node* extract_min(node** arr) {
    if (size <=0) {
        return NULL;
    }
    node* min = arr[1];
    arr[1] = arr[size--];
    heapify(arr, 1);
    return min;
}


void insert(node** arr, node* node) {
    int key = node->key;
    size++;
    int i = size;
    arr[i] = node;
    while (i > 1 && (arr[i / 2]->key >= arr[i]->key)) {
        swap(arr, i, i / 2);
        i = i / 2;
    }
}



node* make_node() {
    node* node_ = (node*)malloc(sizeof(node));
    node_->parent = NULL;
    return node_;
}

int two(int num) {
    if (num & (num - 1)) return -1;
    else   return 1;
}


int main()
{
    int input;
    scanf("%d", &input);

    for (int i = 0; i < input; i++) {
        node* node_ = make_node();
        scanf("%s", node_->value);
        scanf("%d", &(node_->key));
        insert(heap, node_);
        inputs[i] = node_;
    }
    int sum_;
    scanf("%d", &sum_);
    build_min_heap(heap);

    for (int i = 1; i < input; i++) {
        node* node_ = make_node();
        node_->left_node = extract_min(heap);
        node_->right_node = extract_min(heap);
        node_->left_node->parent = node_;
        node_->right_node->parent = node_;
        node_->key = node_->left_node->key + node_->right_node->key;
        insert(heap, node_);
    }

    int sum = 0;
    for (int i = 0; i < input; i++) {
        int height = 0;
        node* node = inputs[i];
        while (node->parent != NULL) {
            node = node->parent;
            height++;
        }
        inputs[i]->height = height;

        sum = sum + inputs[i]->key * inputs[i]->height;
    }
    int n;
    int t = 2; int i = 1;
    while (1) {
        if (t >= input) {
            n = i;
            break;
        }
        t *= 2;
        i++;
    }

    printf("%d\n", sum_ * n);
    printf("%d", sum);

    return 0;
}