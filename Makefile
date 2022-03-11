CXX = gcc

SOURCE_FILES := $(wildcard Source/*.c)
OBJECT_FILES := $(patsubst Source/%.c,%.o,$(wildcard Source/*.c))

all: main

%.o: Source/%.c
	$(CXX) -c Source/$*.c

main: $(OBJECT_FILES)
	$(CXX) $(OBJECT_FILES) -o main

valgrind:
	valgrind ./main

clean:
	rm -f *.o main vgcore.*