.PHONY: build run clean

build: errno

run: errno
	./errno

clean:
	rm errno

errno: errno.c
	$(CC) -lc -O2 -o errno errno.c
