DefinetelyNotSpotify: songs.c playlist.c main.c
	gcc songs.c playlist.c main.c -o DefinitelyNotSpotify
	./DefinitelyNotSpotify

clean:
	rm *~

run:
	./DefinetelyNotSpotify
