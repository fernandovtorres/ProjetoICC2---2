all:
	gcc src/main.c lib/impl/bubble.c lib/impl/counting.c lib/impl/heap.c lib/impl/insertion.c lib/impl/merge.c lib/impl/quick.c lib/impl/radix.c lib/impl/selection.c lib/impl/shell.c lib/impl/util.c -o src/main

run:
	./src/main 
clean:
	rm src/main

remake: clean all
