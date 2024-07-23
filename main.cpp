
#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

bool checkArrayHaveSpace(struct Array *arr) {
    if(arr->size == arr->length) {
        printf("It's imposible to add a new element to array size exceed.");
        return false;
    }
    return true;
}

void Display(struct Array *arr) {
    for(int i=0; i<arr->length;i++) {
        printf(" %d ", arr->A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int value) {

    if(!checkArrayHaveSpace(arr)) {
        return;
    }

    arr->A[arr->length] = value;

    arr->length+=1;

}

void Insert(struct Array *arr, int index, int value) {

    if(!checkArrayHaveSpace(arr)) {
        return;
    }

    if(index>(arr->size-1) || index<=0) {
        printf("Index exceeds size of current array.");
        return;
    }



    if(index > (arr->length-1)) {
        arr->A[index] = value;
        arr->length++;
    }
    else {


        arr->length++;
        printf("%d", arr->length);
        for(int i=arr->length; i>=(index+1); i--) {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = value;
    }


}

void Delete(struct Array *arr, int index) {

    if(index>(arr->length-1) || index<=0) {
        printf("Index out of array range.");
        return;
    }



    for(int i=index; i<arr->length; i++) {
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;


}

int Get(struct Array *arr, int index) {
    if(index>(arr->length-1) || index <= 0) {
        printf("Index out of array range.");
        return 0;
    }

    return arr->A[index];

}

void Set(struct Array *arr, int index, int value) {
    if(index>(arr->length-1) || index<=0) {
        printf("Index out of array range.");
        return;
    }

    arr->A[index] = value;

}

int LinearSearch(struct Array *arr, int value) {
    for(int i=0; i<arr->length; i++) {
        if(arr->A[i]==value) return i;
    }
    return -1;
}

int BinarySearch(struct Array *arr, int value) {

    return -1;
}

int main() {


    struct Array arr;
    int n,i;
    printf("Enter size of array ");
    scanf("%d",&arr.size);

    arr.A=(int *) malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter how many numbers = ");
    scanf("%d",&n);

    printf("Enter all elements: \n");


    for(i=0;i<n;i++) {
        scanf("%d",&arr.A[i]);
    }
    arr.length = n;

    Append(&arr, 10);
    Display(&arr);

    //Insert(&arr,0,10);

    Delete(&arr, 2);
    Display(&arr);

    free(arr.A);
    return 0;
}
