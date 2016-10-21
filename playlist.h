#include "songs.h"

song_node * add_song(char songName[], char artistName[]);

song_node * search_song(char songName[]);

song_node * search_artist(char artistName[]);

void print_entry(char letter);

void print_artist_songs(char artistName[]);

void print_library();

void shuffle();

void remove_song(char songName[]);

void remove_all();
