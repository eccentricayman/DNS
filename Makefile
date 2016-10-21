GCC = gcc -g -c

compile: songs.h playlist.h songs.c playlist.c main.c songs.o playlist.o
	$(GCC) songs.c playlist.c
	gcc -g -o DefinitelyNotSpotify main.c songs.o playlist.o
	./DefinitelyNotSpotify

clean:
	rm *~

debug:
	gcc songs.h songs.c playlist.c main.c -g -o DefinitelyNotSpotify

