//
//  data.c
//  annaworks
//
//  Created by Anna Fuller on 7/14/15.
//  Copyright (c) 2015 Anna Fuller. All rights reserved.
//

#include <stdio.h>

int htoi(char s[]);

int main() {
    char s[] = { '2', 'A', 'F', '3'};
    int i = htoi(s);
    printf("Answer is %d\n", i);
    
}

int htoi(char s[]) {
    int i, n;
    
    n = 0;
    for (i = 0; (s[i] >= '0' && s[i] <= '9')
                 || (s[i] >= 'A' && s[i] <= 'F')
                 || (s[i] >= 'a' && s[i] <= 'f'); ++i) {
        
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 *n + (s[i] - '0');
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            s[i] = s[i] - '0' -7 ;
            n = 16*n + s[i];
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            // Convert to upper case first.
            s[i] = s[i] - 32;
            s[i] = s[i] - '0' - 7;
            n = 16*n +s[i];
        }
     
    }
    return n;
    
}