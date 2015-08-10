//
//  data.c
//  annaworks
//
//  Created by Anna Fuller on 7/14/15.
//  Copyright (c) 2015 Anna Fuller. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "things.h"

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
    printf("%d\n", longdivide(100, 3));
}


unsigned divide(unsigned x, unsigned y) {
    int i = 0;
    unsigned z = x;
    unsigned a = 0;
    unsigned mask = 1;
    if (y == 1) {
        return x;
    }
    while (z >= y) {
        z = add(z, -y);
        i++;
    }
    if (z!=0 ) {
        printf("Modulo was %d\n", z);
    }
    return i;
}

unsigned longdivide(unsigned x, unsigned y) {
    int i;
    unsigned a = 0;
    unsigned z = 0;
    unsigned mask = 1;
    unsigned carry_bit = 0;
    for (i = 0; i < NUM_OF_BITS; i++) {
        unsigned x_bit = x & mask;
        while (a <= y) {
            a = a | x_bit;
            mask <<= 1;
            x_bit = x & mask;
        }
        if (a == y) {
            z = z | 
        }

    }
}


unsigned add(unsigned x, unsigned y) {
    int i;
    unsigned a = 0;
    unsigned mask = 1;
    unsigned carry_bit = 0;
    for (i = 0; i < NUM_OF_BITS; i++) {
        unsigned x_bit = x & mask;
        unsigned y_bit = y & mask;
        unsigned cool_bit;
        if ((x_bit & y_bit) | (x_bit & carry_bit) | (y_bit & carry_bit)){
            if(carry_bit) {
                carry_bit = mask << 1;
                cool_bit = x_bit & y_bit;
            } else {
                carry_bit = mask << 1;
                cool_bit = x_bit ^ y_bit;
            }
        } else {
            cool_bit = x_bit ^ y_bit;
            a = a | carry_bit;
            carry_bit = 0;
        }
        a = a | cool_bit;
        mask <<= 1;
    }
    a = a | carry_bit;
    return a;
}

unsigned multiply(unsigned x, unsigned y) {
    unsigned j;
    unsigned total = 0;
    unsigned y_mask = 1;
    unsigned y_bit;
    for (j = 0; j < NUM_OF_BITS; j++) {
        y_bit = y & y_mask;
        if (y_bit) {
            total = add(x, total);
        }
        x <<=1;
        y_mask <<=1;
    }
    return total;
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

