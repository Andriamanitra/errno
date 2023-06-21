.PHONY: run clean

run: errno
	./errno

errno: errno.c
	$(CC) -lc -O2 -o errno errno.c

clean:
	rm errno
