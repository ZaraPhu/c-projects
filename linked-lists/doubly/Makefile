clean:
	rm -rf build/*

test: clean
	mkdir -p build
	mkdir -p logs
	gcc -c -o build/test.o test.c -g
	gcc -c -o build/doubly-linked.o doubly-linked.c -g
	gcc -o build/test build/test.o build/doubly-linked.o -g
	./build/test
