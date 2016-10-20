struct song_node add_song(struct song_node * toIns);

struct song_node search_artist(struct song_node * start, char artistName[]);

void print_entry(struct song_node * start, char letter);

void print_artist_songs(struct song_node * start, char artist[]);

void shuffle(struct song_node * start);

struct song_node * remove_song(struct song_node * start, struct song_node * toRemove);

void remove_all(struct song_node * start);
