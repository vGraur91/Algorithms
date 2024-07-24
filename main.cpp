
#include <future>
#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[12];
    int size;
    int length;
};

bool checkArrayHaveSpace(struct Array arr) {
    if(arr.size == arr.length) {
        printf("It's imposible to add a new element to array size exceed.");
        return false;
    }
    return true;
}

void Display(struct Array arr) {
    for(int i=0; i<arr.length;i++) {
        printf(" %d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int value) {

    if(!checkArrayHaveSpace(*arr)) {
        return;
    }

    arr->A[arr->length] = value;

    arr->length+=1;

}

void Insert(struct Array *arr, int index, int value) {

    if(!checkArrayHaveSpace(*arr)) {
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

int Get(struct Array arr, int index) {
    if(index>(arr.length-1) || index <= 0) {
        printf("Index out of array range.");
        return 0;
    }

    return arr.A[index];

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

int BinarySearch(struct Array arr, int value) {

    int middle, high = arr.length-1, low = 0;

    while(low<=high) {
        middle = (high + low)/2;

        if(arr.A[middle]==value) {
            return middle;
        } else if(arr.A[middle]>value) {
            high = middle-1;
        }
        else if (arr.A[middle]<value) {
            low = middle+1;
        }

    }

    return -1;
}

int Max(struct Array arr) {
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++) {
        if(arr.A[i]>max) {
            max = arr.A[i];
        }
    }

    return max;
}

int Min(struct Array arr) {
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++) {
        if(arr.A[i]<min) {
            min=arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr) {
    int sum=0;
    for(int i=0;i<arr.length;i++) {
        sum+=arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr) {
    return Sum(arr)/arr.length;
}

void Reverse(struct Array *arr) {
    int tmp;
    for(int i=0, j=arr->length-1; i<j; i++, j--) {
        tmp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = tmp;
    }
}

void InsertSorted(struct Array *arr, int value) {

    if(arr->length==arr->size) {
        return;
    }

    for(int i=arr->length-1;  i>=0; i--) {
        if(arr->A[i]>value) {
            arr->A[i+1] = arr->A[i];
        } else {
            arr->A[i+1] = value;
            arr->length++;
            break;
        }
    }
}

bool IsSorted(struct Array arr) {
    for(int i=1; i<arr.length;i++) {
        if(arr.A[i] < arr.A[i-1]) {
            return false;
        }
    }
    return true;
}

void NegativeToLeft(struct Array *arr) {
    int i=0,j=arr->length;
    while(i<j) {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0) j--;
        printf("%d %d \n", arr->A[i], arr->A[j]);
        if(i<j){
            std::swap(arr->A[i], arr->A[j]);
        }
    }
}

struct Array MergeArrays(struct Array arr1, struct Array arr2) {
    struct Array arr3;
    arr3.length =  arr1.length+arr2.length;
    arr3.size = arr1.length+arr2.length;

    int i=0,j=0,k=0;
    while (i<arr1.length&&j<arr2.length) {


        if(arr1.A[i]<arr2.A[j]) {
            arr3.A[k++] = arr1.A[i++];
        } else {
            arr3.A[k++] = arr2.A[j++];
        }
    }

    for(;i<arr1.length;i++) {
        arr3.A[k++] = arr1.A[i];
    }

    for(;j<arr2.length;j++) {
        arr3.A[k++] = arr2.A[j];
    }

    return arr3;
}

int main() {

    struct Array arr = {{2,3,7,8,9},8,5};
    struct Array arr2 = {{1,4,5,6}, 5, 4};

    /*int n,i;
    printf("Enter size of array =");
    scanf("%d",&arr.size);

    arr.A=(int *) malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter how many numbers are in array = ");
    scanf("%d",&n);

    printf("Enter all elements: \n");
    for(i=0;i<n;i++) {
        scanf("%d",&arr.A[i]);
    }

    arr.length = n;*/

    ///Append(&arr, 10);
    //Display(arr);


    //Insert(&arr,0,10);

    //printf("min = %d\n", Min(arr));
    //printf("max = %d\n", Max(arr));
    //printf("avg = %f\n", Avg(arr));
    //printf("sum = %d\n", Sum(arr));

    //Delete(&arr, 2);
    //Display(arr);
    //Reverse(&arr);


    //Display(arr);
    //InsertSorted(&arr,6);
    //NegativeToLeft(&arr);
    //Display(arr);



    Display(MergeArrays(arr, arr2));

    //free(arr.A);
    return 0;
}
