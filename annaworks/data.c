//
//  data.c
//  annaworks
//
//  Created by Anna Fuller on 7/14/15.
//  Copyright (c) 2015 Anna Fuller. All rights reserved.
//

#include <stdio.h>
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */
#define MAXLINE 1000
#define THELINE 80
#define NUM_OF_BITS 8




int htoi(char s[]);
float convert(float fahr);
int fetchline(char line[], int lim);
void reverse(char to[], char from[], int len);
void copy(char to[], char from[]);
void squeeze(char s1[], char s2[]);
void squeezehelper(char s[], int c);
int any(char s1[], char s2[]);
int anyhelper(char s[], int c);
unsigned multiply(unsigned x, unsigned y);
unsigned add(unsigned x, unsigned y);
const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';
    
    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }
    
    return b;
}

int main() {

    printf("%s\n", byte_to_binary(add(1, 1)));

}

unsigned add(unsigned x, unsigned y) {
    int i;
    short a = 0;
    short mask = 1;
    short carry_bit = 0;
    for (i = 0; i < NUM_OF_BITS; i++) {
        short x_bit = x & mask;
        short y_bit = y & mask;
        short cool_bit;
        if ((x_bit & y_bit) & carry_bit){
            // Might be a carry situation.
            if (x_bit & y_bit) {
                carry_bit = mask << 1;
                cool_bit = x_bit & y_bit;
            } else {
                cool_bit = x_bit ^ y_bit;
                carry_bit = 0;
            }
        } else if (x_bit & y_bit) {
            // Definitely need to create a carry bit here.
            carry_bit = mask << 1;
            cool_bit = x_bit ^ y_bit;
        } else {
            cool_bit = x_bit ^ y_bit;
        }
        a = a | cool_bit;
        mask <<= 1;
    }
    a = a | carry_bit;
    return a;
}

unsigned multiply(unsigned x, unsigned y) {
    int i;
    short mask = 1;

    short z;
    short z2, y_bit;
    y_bit = y & mask;
    z = x & y_bit;
    for (i = 0; i < NUM_OF_BITS; i++) {
        mask <<= 1;
        y_bit = y & mask;
        z2 = x & y_bit;
        z2 <<= 1;


    }
    return z;
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
        } else if (s[i] > '9') {
            return -1;
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
