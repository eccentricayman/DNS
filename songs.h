typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

struct song_node * insert_front(struct song_node * start, char newSong[], char newArtist[]);

struct song_node * insert_order(struct song_node * start, char newSong[], char newArtist[]);

void print_list(struct song_node * start);

struct song_node * find_song(struct song_node * start, char songName[]);

struct song_node * first_artist_song(struct song_node * start, char artistName[]);

struct song_node * random_element(struct song_node * start);

struct song_node * remove_song(struct song_node * start, struct song_node * toDelete);

void free_list(struct song_node * start);
