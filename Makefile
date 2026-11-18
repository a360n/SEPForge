CC ?= clang
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O0 -g
LAB01 = labs/01-arm64-memory

.PHONY: lab01 test asan clean
lab01:
	mkdir -p build
	$(CC) $(CFLAGS) $(LAB01)/src/registers.c -o build/registers
	$(CC) $(CFLAGS) $(LAB01)/src/safe_copy.c -o build/safe_copy
	./build/registers
	./build/safe_copy

test: lab01
	python3 -m unittest discover -s tests -v

asan:
	mkdir -p build
	$(CC) $(CFLAGS) -fsanitize=address -fno-omit-frame-pointer $(LAB01)/src/unsafe_copy.c -o build/unsafe_copy_asan
	@echo 'Run ONLY in a disposable local lab: ./build/unsafe_copy_asan'

clean:
	rm -rf build
