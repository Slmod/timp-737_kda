#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} node;

typedef node* list;

int init(list *l){
    *l = NULL;
    return 1;
}

int destroy(list *l){
    list tmp;
    while(*l != NULL){
        tmp = *l;
        *l = (*l)->next;
        free(tmp);
    }
    return 1;
}

bool isEmpty(list root){
    if(root != NULL){
        return 1;
    }else{
        return 0;
    }
}

list find(list root, int value){
    while(root->value != value){
        if(root == NULL){
            return NULL;
        }
        root = root->next;
    }
    return root;
}

int append(list *lst, int value){
    if(((*lst) == NULL)){
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        *lst = tmp;
        return 1;
    }else if((*lst)->next == NULL){
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = *lst;
        (*lst)->next = tmp;
        return 1;
    }else{
        list tmp = (list)malloc(sizeof(node));
        tmp->next = (*lst)->next;
        tmp->value = value;
        tmp->prev = *lst;
        (*lst)->next->prev = tmp;
        (*lst)->next = tmp;
        return 1;
    }
}
int prepend(list *lst, int value){
    if(((*lst) == NULL)){
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        *lst = tmp;
        return 1;
    }else if((*lst)->prev == NULL){
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = *lst;
        tmp->prev = NULL;
        (*lst)->prev = tmp;
        (*lst) = (*lst)->prev;
        return 1;
    }else{
        list tmp = (list)malloc(sizeof(node));
        tmp->prev = (*lst)->prev;
        tmp->value = value;
        tmp->next = *lst;
        (*lst)->prev->next = tmp;
        (*lst)->prev = tmp;
        return 1;
    }
}

int remove1(list *lst){
    if (*lst != NULL) {
        list tmp = *lst;
        if (((*lst)->next != NULL) && ((*lst)->prev != NULL)) {
            (*lst)->prev->next = (*lst)->next;
            (*lst)->next->prev = (*lst)->prev;
        }
        if (((*lst)->next != NULL) && ((*lst)->prev == NULL)) {
            (*lst)->next->prev = NULL;
            (*lst) = (*lst)->next;
        }
        if (((*lst)->next == NULL) && ((*lst)->prev != NULL)) {
            (*lst)->prev->next = NULL;
        }
        free(tmp);
    }
    return 1;
}
int print(list *lst){
    list tmp = *lst;
    do{
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    while( tmp != NULL);

    printf("\n");

    return 1;
}

int main()
{
    list root, tmp;
    init(&root);

    int n, i, k, m, a, c, x, b, d;
    // 1
    scanf("%d", &n);

    scanf("%d", &x);
    append(&root, x);

    tmp = root;
    // 2
    for(i = 1; i<n; i++){
        scanf("%d", &x);
        append(&tmp, x);
        tmp = tmp->next;
    }
    print(&root);

    // 3
    scanf("%d", &k);


    if(k==1){
        remove1(&root);
    }else{
        tmp = root;
        for(i=1; i<k; i++){
            tmp = tmp->next;
        }
        remove1(&tmp);
    }
    print(&root);

    // 4
    scanf("%d", &m);

    tmp = find(root, m);

    if(tmp == root){
        remove1(&root);
    }else{
        remove1(&tmp);
    }
    print(&root);

    // 5
    scanf("%d%d", &a, &b);
    tmp = root;
    for(i=1; i<a; i++){
        tmp=tmp->next;
    }
    append(&tmp, b);

    print(&root);

    // 6
    scanf("%d%d", &c, &d);
    if(c==1){
        prepend(&root, d);
    }else{
        tmp = root;
        for(i=1; i<c; i++){
            tmp=tmp->next;
        }
        prepend(&tmp, d);
    }

    print(&root);

    return 0;
}
