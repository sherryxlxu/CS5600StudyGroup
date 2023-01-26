all: queue.c
	gcc -g queue.c -o qtest
	./qtest
clean:
	rm -f qtest
	touch queue.c
