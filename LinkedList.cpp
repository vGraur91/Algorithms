
#include <stdio.h>
#include <stdlib.h>

//Writing manipulation with linked list

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

void free_nodes(struct LinkedList *l) {
    struct Node *m = l->head;
    while (m!=nullptr) {
        struct Node *tmp = m->next;
        free(m);
        m = tmp;
    }
}

void append(struct LinkedList *l, struct Node *n) {
    if(l->head==nullptr) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
}

void prepend(struct LinkedList *l, struct Node *n) {

    if (l->head == nullptr) {
        l->tail = n;
        l->head = n;
    } else {
        n->next = l->head;
        l->head = n;
    }
}

void delete_node(struct LinkedList *l,int value){
    struct Node *n= l->head, *prev = l->head;
    if(n->data==value) {
        l->head = n->next;
        if(n->next==nullptr) {
            l->tail = n->next;
        }
        free(n);
    } else {
        while(n!=nullptr) {
            if (n->data == value) {
                if (n==l->tail) {
                    l->tail = prev;
                }
                prev->next = n->next;
                free(n);
                break;
            }
            prev = n;
            n=n->next;
        }
    }
}

struct LinkedList * create() {

    struct LinkedList *l;
    l = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    l->head = nullptr;
    l->tail = nullptr;

    struct Node *n;
    int A[10] = {7,3,9,12,8,11,1,15,2,10};
    for(int i = 0; i<10; i++) {
        n = (struct Node *) malloc(sizeof(struct Node));
        n->data = A[i];
        n->next = nullptr;
        append(l,n);
    }

    return l;

}

int length(struct LinkedList *l) {

    int count = 0;
    struct Node *n = l->head;
    while (n!= nullptr) {
        count++;
        n = n->next;
    }

    return count;

}

void display(struct LinkedList *l) {
    struct Node *m = l->head;

    while (m!=nullptr) {
        printf("%d ",m->data);
        m = m->next;
    }

    printf("\n");

}

int sum(struct LinkedList *l) {
    int sum = 0;
    struct Node *n = l->head;
    while (n!=nullptr) {
        sum +=n->data;
        n = n->next;
    }
    return sum;
}

int max(struct LinkedList *l) {
    int max = -32768;
    struct Node *n = l->head;
    while (n!=nullptr) {
        if(n->data>max) max = n->data;
    }
    return max;
}

int min(struct LinkedList *l) {
    int min = 32767;
    struct Node *n = l->head;
    while (n!=nullptr) {
        if(n->data<min) min = n->data;
    }
    return min;
}

struct Node * search(struct LinkedList *l, int value) {
    struct Node *n = l->head;
    while(n!=nullptr) {
        if(n->data==value) {
            printf("Found %d ", n->data);
            return n;
        }
        n=n->next;
    }
    return n;
}

void insert(struct LinkedList *l, int value,int index) {
    struct Node *prev = nullptr,*n = l->head;
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->data = value;
    p->next = nullptr;

    //if head is empty then list is empty so add first node
    if(n==nullptr) {
        append(l,p);
        return;
    }

    if (index == 0) {
        printf("Index out of range. \n");
        return;
    }
    int i = 0;
    while(n!=nullptr) {
        if(i==index) {
            prev->next = p;
            p->next = n;
            return;
        }
        i++;
        prev = n;
        n=n->next;
    }

    if(i>=0) printf("Index out of range. \n");

}

int list_is_sorted(struct LinkedList *l) {
    struct Node *n = l->head;
    while (n!=nullptr) {
        if(n->data > n->next->data) return 0;
        n=n->next;
    }

    return 1;
}

void reverse(struct LinkedList *l) {
    struct Node *r,*q,*n=l->head;
    l->head = l->tail;
    l->tail = n;
    while(n!=nullptr) {
        r=q;
        q=n;
        n=n->next;
        q->next = r;
    }
}

void concat_lists(struct LinkedList *l1, struct LinkedList *l2) {
    struct Node *n1 = l1->tail;
    n1->next = l2->head;
    l1->tail = l2->tail;
}

int main () {

    struct LinkedList *l; //*l2;
    l = create();
    //l2 = create();

    //display(l);



    /*
    delete_node(l, 10);

    //check if everything is ok
    printf("head = %d  tail = %d\n", l->head->data, l->tail->data);
    */

    //insert(l,17,1);
    display(l);
    //reverse(l);

    //concat_lists(l,l2);

    display(l);

    //struct Node *n = search(l, 12);

    //printf("%d", length(l)); //find out length of linked list;

    //printf("%d", sum(l));

    //clear memory
    free_nodes(l);
    free(l);

    return 0;

}