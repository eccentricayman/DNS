GCC = gcc -g

compile: NOTspotify.c
	gcc NOTspotify.c -o tuneztest

clean:
	rm -rf tuneztest
	rm -rf *~

run:
	./tuneztest

debug:
	gcc NOTspotify.c -g -o tuneztest
