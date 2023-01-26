all: queue.c
	gcc -g queue.c -o queue
	./queue
clean:
	rm -f queue
	touch queue.c
