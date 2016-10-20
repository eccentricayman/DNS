song_node * add_song(song_node * toIns);

song_node * search_artist(song_node * start, char artistName[]);

void print_entry(song_node * start, char letter);

void print_artist_songs(song_node * start, char artist[]);

void shuffle(song_node * start);

song_node * remove_song(song_node * start, song_node * toRemove);

void remove_all(song_node * start);
