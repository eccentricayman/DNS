#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"

struct song_node * insert_front(struct song_node * start, char newSong[], char newArtist[]) {
    struct song_node *toAdd = (struct song_node *)malloc(sizeof(struct song_node));
    strcmp(toAdd -> name, newSong);
    strcmp(toAdd -> artist, newArtist);
    toAdd -> next = start;
    return toAdd;
}

struct song_node * insert_order(struct song_node * start, char newSong[], char newArtist[]) {
    if (!start || strcmp(start -> artist, newArtist)) {
        return insert_front(start, newSong, newArtist);
    }
    song_node * beginning = start;
    while (start -> next) {
        if (strcmp(start -> next -> artist, newArtist)) {
            start = start -> next;
        }
        else {
            break;
        }
    }
    song_node * toAdd = insert_front(start -> next, newSong, newArtist);
    start -> next = toAdd;
    return beginning;
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

struct song_node * find_song(struct song_node * start, char songName[]) {
    while (start) {
        if (strcmp(start -> name, songName)) {
            return start;
        }
        else {
            start = start -> next;
        }
    }
    return NULL;
}

struct song_node * first_artist_song(struct song_node * start, char artistName[]) {
    while (start) {
        if (strcmp(start -> artist, artistName)) {
            break;
        }
        start = start -> next;
    }
    return start;
}

struct song_node * random_element(struct song_node * start) {
    srand(time(NULL));
    int ctr = rand() % 2;
    for (int i = 0 ; i <= ctr ; i++) {
        start = start -> next;
    }
    return start;
}

void remove_song(struct song_node * start, char songName[], char artistName[]) {
    while (start -> next) {
        if (strcmp(start -> next -> name, songName) && strcmp(start -> next -> name, artistName)) {
            struct song_node * temp = start -> next;
            start -> next = start -> next -> next;
            free(temp);
            break;
        }
    }
}

struct song_node * free_list(struct song_node * start) {
    if (start -> next) {
        free_list(start -> next);
    }
    free(start);
    return start;
}

int main() {
    //stolen from calvin and giovanni
    song_node *list = insert_order(NULL, "Highway to Hell", "AC/DC");
    list = insert_order(list, "Everlong", "Foo Fighters");
    list = insert_order(list, "Hips Don't Lie", "Shakira");
    list = insert_order(list, "Something Good Can Work", "Two Door Cinema Club");
    list = insert_order(list, "American Idiot", "Green Day");
  
    print_list(list);
    printf("Finding Everlong: %s\n", find_song(list, "Everlong")->name);
    printf("Finding first name by foo fighters: %s\n", first_artist_song(list, "Foo Fighters")->name);
    printf("Getting random name: %s\n", random_element(list)->name);
    printf("Removing 'Hips Don't Lie'...\n");
    remove_song(list, "Hips Don't Lie", "Shakira");
    printf("\nRemoving 'American Idiot'...\n");
    remove_song(list, "American Idiot", "Green Day");
    printf("\nRemoving 'Something Good Can Work'...\n");
    remove_song(list, "Something Good Can Work", "Two Door Cinema Club");
    print_list(list);
  
    printf("\nRemoving nonexistent name 'Hello'...\n");
    remove_song(list, "Hello", "LOLOALDAOPWDNSBGERJNREK");
    print_list(list);
  
    list = free_list(list);
    print_list(list);
    return 0;
}

