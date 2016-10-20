#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

song_node *table[26];

song_node * add_song(char songName[], char artistName[]) {
    song_node * tableP = *table;
    while (tableP) {
        if (tableP->artist[0] == artistName[0]) {
            break;
        }
        tableP++;
    }
    return insert_order(tableP, songName, artistName);
}

song_node * search_artist(char artistName[]) {
    song_node * tableP = *table;
    while (tableP) {
        if (tableP->artist[0] == artistName[0]) {
            break;
        }
        tableP++;
    }
    return first_artist_song(tableP, artistName);
}

void print_entry(char letter) {
    song_node * tableP = *table;
    int ctr = 0;
    while (tableP) {
        if (ctr == letter - 97) {
            break;
        }
        tableP++;
        ctr++;
    }
    print_list(tableP);
}

void print_artist_songs(char artistName[]) {
    song_node * artistP = search_artist(artistName);
    while (strcmp(artistP -> artist, artistName)) {
        printf("%s by %s \n", artistP -> name, artistP -> artist);
    }
}
