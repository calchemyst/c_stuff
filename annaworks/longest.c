//
//  longest.c
//  annaworks
//
//  Created by Anna Fuller on 7/13/15.
//  Copyright (c) 2015 Anna Fuller. All rights reserved.
//
//
//#include <stdio.h>
//#define MAXLINE 1000
//#define THELINE 80
//
//int fetchline(char line[], int lim);
//void reverse(char to[], char from[], int len);
//void copy(char to[], char from[]);
//
//
//int main() {
//    int len;
//    char line[MAXLINE];
//    char reverser[MAXLINE];
//    
//    while ((len = fetchline(line, MAXLINE)) > 0) {
//            reverse(reverser, line, len);
//            printf("Reversed it! %s\n", reverser);
//            printf("Line had this size! %d\n", len);
//            printf("Resetting for next word.\n");
//            int i;
//            i = 0;
//            for (i =0 ; i < len -1; i++) {
//                reverser[i] = '\0';
//            }
//    }
//    return 0;
//}
//
//
//void reverse(char to[], char from[], int len) {
//    int i, j;
//    i = len -1;
//    j = 0;
//    while((to[j] = from[i]) != '\0') {
//        --i;
//        ++j;
//    }
//}
//
//int fetchline(char s[], int lim) {
//    int c, i;
//    
//    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c!= '\n'; ++i)
//        s[i] = c;
//    s[i] = '\0';
//    return i;
//}
//
//void copy(char to[], char from[]) {
//    int i ;
//    
//    i = 0;
//    while((to[i] = from[i]) != '\0')
//        ++i;
//}
