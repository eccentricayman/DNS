GCC = gcc -g

compile: songs.c playlists.c
	gcc NOTspotify.c songs.c -o DefinetelyNotSpotify

clean:
	rm -rf DefinetelyNotSpotify
	rm -rf *~

run:
	./DefinetelyNotSpotify

debug:
	gcc NOTspotify.c -g -o DefinetelyNotSpotify
