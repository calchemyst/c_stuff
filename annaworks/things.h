//
// Created by Anna Fuller on 7/18/15.
//

#ifndef ANNAWORKS_THINGS_H
#define ANNAWORKS_THINGS_H
#define MAXLINE 1000
#define THELINE 80
#define NUM_OF_BITS 32

int htoi(char s[]);
int fetchline(char line[], int lim);
void reverse(char to[], char from[], int len);
void squeeze(char s1[], char s2[]);
void squeezehelper(char s[], int c);
int any(char s1[], char s2[]);
int anyhelper(char s[], int c);
unsigned add(unsigned x, unsigned y);
unsigned multiply(unsigned x, unsigned y);
unsigned divide(unsigned x, unsigned y);
unsigned longdivide(unsigned x, unsigned y);


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
#endif //ANNAWORKS_THINGS_H
