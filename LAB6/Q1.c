#include<stdio.h>
#include<string.h>

#define SIZE 100

void E(), E_(), T(), T_(), F();

int i=0;

char s[SIZE];

int main() {
    printf("\n Enter the string: ");
    scanf("%s",s);
    E();
    if(i==strlen(s)) {
        printf("\n String successfully parsed.");
    } else {
        printf("\n String parsing failed.");
    }
}

void E() {
    T();
    E_();
}

void E_() {
    if(s[i]=='+') {
        i++;
        T();
        E_();
    }
}

void T() {
    F();
    T_();
}

void T_() {
    if(s[i]=='*') {
        i++;
        F();
        T_();
    }
}

void F() {
    if(s[i]=='(') {
        i++;
        E();
        if(s[i]==')') {
            i++;
        } 
    } else if(s[i]=='i') {
        i++;
    } else {
        return;
    }
}
