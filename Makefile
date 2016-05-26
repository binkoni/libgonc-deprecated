CC=gcc
CFLAGS=-O3 -s
#LDFLAGS
.PHONY : clean
.DEFAULT : all
all : main test 
main : 
	mkdir -p build
	mkdir -p build/main
test : 
	mkdir -p build
	mkdir -p build/test
	$(CC) $(CFLAGS) src/main/gonc_stack.c src/test/stack_test.c -o build/test/stack_test
	$(CC) $(CFLAGS) src/main/gonc_queue.c src/test/queue_test.c -o build/test/queue_test
	$(CC) $(CFLAGS) src/main/gonc_vector.c src/test/vector_test.c -o build/test/vector_test
clean : 
	rm -rf build
