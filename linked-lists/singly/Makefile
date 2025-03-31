clean:
	rm -rf build/*

test: clean
	mkdir -p build
	gcc -c -o build/test.o test.c
	gcc -c -o build/singly-linked.o singly-linked.c
	gcc -o build/test build/test.o build/singly-linked.o
	./build/test
