#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main() {
  printf("Testing add_song\n");
  add_song("Closer", "Chainsmokers");
  add_song("Faded", "Alan Walker");
  add_song("All We Know", "Chainsmokers");
  
  printf("\nTesting search_song\n");
  printf("%s\n", search_song("Closer")->name);
  printf("%s\n", search_song("Faded")->name);
  printf("%s\n", search_song("All We Know")->name);
  
  printf("\nTesting search_artist\n");
  printf("%s\n", search_artist("Chainsmokers")->artist);
  
  char a = 'c';
  printf("\nTesting print_entry\n");
  print_entry(a);
  
  printf("\nTesting print_artist_songs\n");
  print_artist_songs("Chainsmokers");
  
  printf("\nTesting print_library\n");
  print_library();

  printf("\nTesting shuffle\n");
  shuffle();

  printf("\nTesting remove_song\n");
  remove_song("Closer");
  print_library();
  
  printf("\nTesting remove_all\n");
  remove_all();
  print_library();
}
