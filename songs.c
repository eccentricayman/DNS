#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songs.h"

struct song_node * insert_front(struct song_node * start, char newSong[], char newArtist[]) {
    struct song_node *toAdd = (struct song_node *)malloc(sizeof(struct song_node));
    strcmp(toAdd -> name, newSong);
    strcmp(toAdd -> artist, newArtist);
    toAdd -> next = start;
    return toAdd;
}

void print_list(struct song_node * start) {
    printf("%s by %s \n", start -> name, start -> artist);
    if (start -> next) {
        print_list(start -> next);
    }
    else {
        printf("\n");
    }
}


