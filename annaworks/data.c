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
float convert(float fahr);
int fetchline(char line[], int lim);
void reverse(char to[], char from[], int len);
void copy(char to[], char from[]);
void squeeze(char s1[], char s2[]);
void squeezehelper(char s[], int c);
int any(char s1[], char s2[]);
int anyhelper(char s[], int c);

int main() {
    char s[] = "2AF3";
    char h[] = "hokkahokka";
    char h2[] = "0FF3";
    char h3[] = "k";
    char s1[] = "hotdoghot";
    char s2[] = "dg";
    int i = htoi(s);
    int j = htoi(h);
    int k = htoi(h2);
    int k1 = any(h, h3);
    printf("Found at %d\n", k1);
    squeeze(s1, s2);
    printf("%s\n", s1);
    printf("Answer is %d\n", i);
    printf("Answer is %d\n", j);
    printf("Answer is %d\n", k);
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
    for (i = 0; s[i] != '\0'; ++i) {
        n = 16*n;
        if ((s[i] >= 'A' & s[i] <= 'f') && !(s[i] > 'F' && s[i] < 'a')) {
            s[i] -= 7 ;
            if (s[i] >= 'a' && s[i] <= 'f') {
                s[i] -= 32;
            }
        } else if ((s[i] > '9' && s[i] < 'A')) {
            printf("Not a hexadecimal.\n");
            return 0;
        }
        n = n + s[i] - '0';
    }
    return n;
}


float convert(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}

void squeezehelper(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
       if (s[i] != c)
           s[j++] = s[i];
    }
    s[j] = '\0';
}

void squeeze(char s1[], char s2[]) {
    int i;
    for (i = 0; s2[i] != '\0'; i++) {
        squeezehelper(s1, s2[i]);
    }
}

int any(char s1[], char s2[]) {
    int i, k;
    k = -1;
    for (i = 0; s2[i] != '\0'; i++) {
        k = anyhelper(s1, s2[i]);
        if (k != -1) {
            return k;
        }
    }
    return k;
}

int anyhelper(char s[], int c) {
    int i, k;
    k = -1;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return k;
}