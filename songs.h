typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * insert_front(song_node * start, char newSong[], char newArtist[]);

song_node * insert_order(song_node * start, char newSong[], char newArtist[]);

void print_list(song_node * start);

song_node * find_song(song_node * start, char songName[]);

song_node * first_artist_song(song_node * start, char artistName[]);

song_node * random_element(song_node * start);

song_node * remove_song_node(song_node * start, char songName[], char artistName[]);

song_node * free_list(song_node * start);
