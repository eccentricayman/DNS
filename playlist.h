#include "songs.h"

song_node * add_song(char songName[], char artistName[]);

song_node * search_artist(char artistName[]);

void print_entry(char letter);

void print_artist_songs(char artistName[]);

void shuffle(song_node * start);

song_node * remove_song(song_node * start, song_node * toRemove);

void remove_all(song_node * start);
