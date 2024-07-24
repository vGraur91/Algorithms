#include <stdio.h>
#include <stdbool.h>


bool Validation(char p[]) {
    for(int i=0; p[i]!='\0';i++) {
        //printf("%c %d\n", p[i], p[i]);
        if(!((p[i]>='A'&&p[i]<='Z') || (p[i]>=97&&p[i]<=122) || (p[i]>='0'&&p[i]<='9'))) {
            return false;
        }
    }
    return true;
}

void ReverseString(char p[]) {

    char *b;

    int i;
    for(i=0; p[i]!='\0'; i++);

    i--;
    int j;
    for(j=0; i>=0; j++, i--) {
        b[j] = p[i];
    }
    b[j] = '\0';
    printf("%s", b);

}

void ReverseString2(char p[]) {
    int i;
    for(i=0;p[i]!='\0';i++);
    i--;
    int j;
    char tmp;
    for(j=0; j<i; j++, i--) {
        tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
    }

    printf("%s\n", p);
}

int CheckPolindrome(char p[]) {
    int i;
    for(i=0; p[i]!='\0'; i++);

    i--;
    int j;
    for(j=0; j<i; j++, i--) {
        if(p[i]!=p[j]) return 0;
    }

    return 1;
}

int CompareStrings(char p1[], char p2[]) {
    for(int i=0; (p1[i]!='\0' || p2[i]!='\0'); i++) {
        if(!(p1[i]!='\0' && p2[i]!='\0') || (p1[i]!=p2[i])) {
            return 0;
        }
    }
    return 1;
}

int FindDuplicate(char p[]) {


    for(int i=0; p[i]!='\0'; i++)
    for(int j=i+1; p[j]!='\0'; j++) {
        if(p[i]=='0') break;
        if(p[j]=='0') continue;
        if  (p[i] == p[j]) {
            printf("Charachter %c is duplicate.\n",p[i]);
            p[j] = '0';
        }
    }

}

void FindDuplicateBits(char p[]) {

    long int H = 0;
    int position;
    int r;
    for(int i=0;p[i]!='\0';i++) {
        position = p[i]-97;
        r = 1<<position;
        printf("H=%d\n", H);
        if(H&r) {
            printf("%c is duplicate\n", p[i]);
        } else {
            H |= r;
        }

    }

}

int main(void) {


    char string[] = "helleh";
    //char string1[] = "helleh11";

    /*
    if(Validation(string)) {
        printf("passed\n");
    } else {
        printf("Not pass.\n");
    }
    */

    //ReverseString2(string);
    /*
    if(CheckPolindrome(string)) {
        printf("It is polindrom.\n");
    } else {
        printf("It is not polindrom.\n");
    }*/

    /*
    if(CompareStrings(string, string1)) {
        printf("Same values in strings.\n");
    } else {
        printf("Not same values in strings.\n");
    }
    */

    FindDuplicateBits(string);

    //FindDuplicate(string);

    //ReverseString(string);
    //printf("%d\n",sizeof(a)); //one char is 1byte


    //scanf("%s", &string);
    //gets(string);

    /*
    for(int i=0;i<string[i]!='\0'; i++) {
        string[i] = string[i] - 32;
    }
    */

    //printf("%s", string);



}
