// Copyright 2021, Nogroma. All rights reserved.
#include <stdio.h>

void coding() {
    int per;
    char letter, space;
    while ((per = scanf("%c%c", &letter, &space)) && per == 2 && space == ' ') {
        printf("%X ", letter);
    }
    if (per != -1 && (space < 64 || space > 91)) {
        printf("%X", letter);
    } else {
        printf("n/a");
    }
}

void decoding() {
    int per = 0, key;
    char space;
    while ((per = scanf("%X%c", &key, &space)) && per == 2 && space == ' ') {
        printf("%c ", (char)key);
    }
    if (per != -1 && (key > 64 && key < 91)) {
        printf("%c", (char)key);
    } else {
        printf("n/a");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("n/a");
        return 1;
    }

    if (*argv[1] == '0') {
        coding();
    } else if (*argv[1] == '1') {
        decoding();
    } else {
        printf("n/a");
    }
    
    return 0;
}
