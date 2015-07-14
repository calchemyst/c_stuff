//
//  data.c
//  annaworks
//
//  Created by Anna Fuller on 7/14/15.
//  Copyright (c) 2015 Anna Fuller. All rights reserved.
//

#include <stdio.h>
#define MAXLINE 1000
#define THELINE 80

int htoi(char s[]);
char itoh(int i);
float convert(float fahr);
int fetchline(char line[], int lim);
void reverse(char to[], char from[], int len);
void copy(char to[], char from[]);

int main() {
    char s[] = { '2', 'A', 'F', '3'};
    int i = htoi(s);
    printf("Answer is %d\n", i);
    
}


void reverse(char to[], char from[], int len) {
    int i, j;
    i = len -1;
    j = 0;
    while((to[j] = from[i]) != '\0') {
        --i;
        ++j;
    }
}

int fetchline(char s[], int lim) {
    int c, i;
    
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c!= '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i ;
    
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}

int htoi(char s[]) {
    int i, n;
    
    n = 0;
    for (i = 0; (s[i] >= '0' && s[i] <= '9')
                 || (s[i] >= 'A' && s[i] <= 'F')
                 || (s[i] >= 'a' && s[i] <= 'f'); ++i) {
        n = 16*n;
        if (s[i] >= 'A' && s[i] <= 'F') {
            s[i] = s[i] -7 ;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            // Convert to upper case first.
            s[i] = s[i] - 32;
            s[i] = s[i] - 7;
        }
        n = n + s[i] - '0';
     
    }
    return n;
}


float convert(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}