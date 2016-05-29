CC=gcc
CFLAGS=-O3 -s -Wall
TESTCFLAGS=-O3 -g -Wall
#LDFLAGS
.PHONY : clean
.DEFAULT : all
all : main test 
main : 
	mkdir -p build
	mkdir -p build/main
	$(CC) $(CFLAGS) -shared -fPIC src/main/*.c -o build/main/libgonc.so
test : 
	mkdir -p build
	mkdir -p build/test
	$(CC) $(TESTCFLAGS) src/test/node_test.c -l cmocka -o build/test/node_test
	$(CC) $(TESTCFLAGS) src/main/gonc_stack.c src/test/stack_test.c -l cmocka -o build/test/stack_test
	$(CC) $(TESTCFLAGS) src/main/gonc_queue.c src/test/queue_test.c -l cmocka -o build/test/queue_test
	$(CC) $(TESTCFLAGS) src/main/gonc_array_list.c src/test/array_list_test.c -l cmocka -o build/test/array_list_test
	$(CC) $(TESTCFLAGS) src/main/gonc_linked_list.c src/test/linked_list_test.c -l cmocka -o build/test/linked_list_test
clean : 
	rm -rf build
