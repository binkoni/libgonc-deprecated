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
	$(CC) $(CFLAGS) src/test/node_test.c -l cmocka -o build/test/node_test
	$(CC) $(CFLAGS) src/main/gonc_stack.c src/test/stack_test.c -l cmocka -o build/test/stack_test
	$(CC) $(CFLAGS) src/main/gonc_queue.c src/test/queue_test.c -l cmocka -o build/test/queue_test
	$(CC) $(CFLAGS) src/main/gonc_array_list.c src/test/array_list_test.c -l cmocka -o build/test/array_list_test
clean : 
	rm -rf build
