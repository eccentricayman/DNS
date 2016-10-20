<<<<<<< HEAD
song_node * add_song(song_node * toIns);

song_node * search_artist(song_node * start, char artistName[]);

void print_entry(song_node * start, char letter);

void print_artist_songs(song_node * start, char artist[]);

void shuffle(song_node * start);

song_node * remove_song(song_node * start, song_node * toRemove);

=======
#include "songs.h"

song_node * add_song(char songName[], char artistName[]);

song_node * search_artist(char artistName[]);

void print_entry(char letter);

void print_artist_songs(char artistName[]);

void shuffle(song_node * start);

song_node * remove_song(song_node * start, song_node * toRemove);

>>>>>>> c024689a7fb637c87623e6df62771a21aa6235ad
void remove_all(song_node * start);
