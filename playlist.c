#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "playlist.h"

song_node *table[26];

song_node * add_song(char songName[], char artistName[]) {
  int i = tolower(artistName[0]) - 97;
  table[i] = insert_order(table[i], songName, artistName);
  return table[i];
}

song_node * search_song(char songName[]) {
  int i = 0;
  song_node * ret = NULL;
  while (!ret) {
    ret = find_song(table[i], songName);
    i++;
  }
  return ret;
}

song_node * search_artist(char artistName[]) {
  int i = tolower(artistName[0]) - 97;
  return first_artist_song(table[i],artistName);
}

void print_entry(char letter) {
  int i = tolower(letter) - 97;
  printf("%c Artists:\n", i+65);
  print_list(table[i]);
}

void print_artist_songs(char artistName[]) {
  int i = tolower(artistName[0]) - 97;
  song_node * temp = table[i];
  printf("%s Songs:\n", artistName);
  while (temp) {
    if (!strcmp(temp->artist,artistName)) {
      printf("%s\n", temp->name);
    }
    temp = temp->next;
  }
}

void print_library() {
  int i;
  for (i = 0; i < 26; i++) {
    printf("%c Artists:\n", i+65);
    print_list(table[i]);
    printf("\n");
  }
}

void shuffle() {
    printf("something?");
    song_node * newTable;
    printf("made table2");
    for (int i = 0 ; i < 26 ; i++) {
        song_node * letterP = table[i];
        printf("letterz");
        while (letterP) {
            strcpy(newTable -> name, letterP -> name);
            strcpy(newTable -> artist, letterP -> artist);
            printf("newtablunext");
            newTable -> next = letterP -> next;
            letterP = letterP -> next;
        }
    }
    while (newTable) {
        printf("tempnodee");
        song_node * temp = remove_song_node(newTable, random_element(newTable) -> name);
        printf("%s by %s", temp -> name, temp -> artist);
        newTable = newTable -> next;
    }
}

void remove_song(char songName[]) {
  int i = 0;
  for (; i < 26; i++) {
    if (find_song(table[i], songName))
      table[i] = remove_song_node(table[i], songName);
  }
}

void remove_all() {
  int i = 0;
  for (; i < 26; i++)
    table[i] = free_list(table[i]);
}
