#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"

song_node * insert_front(song_node * start, char newSong[], char newArtist[]) {
  song_node *toAdd = (song_node *)malloc(sizeof(song_node));
  strcpy(toAdd->name, newSong);
  strcpy(toAdd->artist, newArtist);
  toAdd->next = start;
  return toAdd;
}

song_node * insert_order(song_node * start, char newSong[], char newArtist[]) {
  if (!start || strcmp(start->artist, newArtist) > 0) {
    return insert_front(start, newSong, newArtist);
  }
  song_node * beginning = start;
  while (start->next) {
    if (strcmp(start->next->artist, newArtist) < 0) {
      start = start->next;
    }
    else if (strcmp(start->next->artist, newArtist) == 0) {
      if (strcmp(start->next->name, newSong) < 0) {
	start = start->next;
      }
      else {
	break;
      }
    }
    else {
      break;
    }
  }
  song_node * toAdd = insert_front(start->next, newSong, newArtist);
  start->next = toAdd;
  return beginning;
}

void print_list(song_node * start) {
  while (start) {
    printf("%s - %s\n", start->artist, start->name);
    start = start->next;
  }
}

song_node * find_song(song_node * start, char songName[]) {
  while (start) {
    if (!strcmp(start->name, songName)) {
      return start;
    }
    start = start->next;
  }
  return NULL;
}

song_node * first_artist_song(song_node * start, char artistName[]) {
  while (start) {
    if (!strcmp(start->artist, artistName)) {
      return start;
    }
    start = start->next;
  }
  return NULL;
}

int length(song_node * start) {
  int ctr = 0;
  while (start) {
    ctr++;
    start = start->next;
  }
  return ctr;
}
  
song_node * random_element(song_node * start) {
  srand(time(NULL));
  int ctr = rand() % length(start);
  int i;
  for (i = 0 ; i < ctr ; i++) {
    start = start->next;
  }
  return start;
}

song_node * remove_song_node(song_node * start, char songName[], char artistName[]) {
  song_node * temp = start;
  if (!strcmp(start->name, songName) && !strcmp(start->artist, artistName)) {
    start = start->next;
    free(temp);
    return start;
  }
  song_node * beginning = start;
  while (start->next) {
    if (!strcmp(start->next->name, songName) && !strcmp(start->next->artist, artistName)) {
      temp = start->next;
      start->next = start->next->next;
      free(temp);
      break;
    }
    start = start->next;
  }
  return beginning;
}

song_node * free_list(song_node * start) {
  song_node * temp = start;
  while (start) {
    start = start->next;
    free(temp);
    temp = start;
  }
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
  printf("\n");
  printf("Finding Everlong: %s\n", find_song(list, "Everlong")->name);
  printf("Finding first name by foo fighters: %s\n", first_artist_song(list, "Foo Fighters")->name);
  printf("Getting random name: %s\n", random_element(list)->name);
  printf("\n");
  printf("Removing 'Highway to Hell'...\n");
  list = remove_song_node(list, "Highway to Hell", "AC/DC");
  print_list(list);/*
  printf("\nRemoving 'American Idiot'...\n");
  list = remove_song_node(list, "American Idiot", "Green Day");
  printf("\nRemoving 'Something Good Can Work'...\n");
  list = remove_song_node(list, "Something Good Can Work", "Two Door Cinema Club");
  print_list(list);*/
  
  printf("\nRemoving nonexistent name 'Hello'...\n");
  list = remove_song_node(list, "Hello", "LOLOALDAOPWDNSBGERJNREK");
  print_list(list);
  
  printf("\nFreeing list...\n");
  list = free_list(list);
  print_list(list);
  return 0;
}

