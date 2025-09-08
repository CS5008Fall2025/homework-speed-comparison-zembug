CC = gcc   # This variable is which compiler to use, we will use the variable later by $(CC)
CFLAGS = -Wall  # this variable is command line arguments
MOVIE_FILES =   lib/movie.c # this variable is the list of files to compile, notice .h files are not included only .c files
LINKED_LIST_FILES = lib/linked_list.c lib/sorted_list.c $(MOVIE_FILES) 
VECTOR_FILES = lib/vector.c lib/sorted_vector.c $(MOVIE_FILES)
BST_FILES = lib/bst.c $(MOVIE_FILES)
SPEED_COMPARE_FILES = speed_compare_app/speed_compare.c 
# Detect the OS
ifeq ($(OS),Windows_NT)
	EXT = .exe
else
	EXT = .out
endif
#while linux/mac doesn't care about the extension, windows does, so we 
#want to check the OS and set the extension accordingly. Technically, we 
#could just set the extension to .exe and it would work on all OS's, but
#.out for (in progress) executables is more common on linux/mac, so we will use that.
#often a final release uses no extension (ls, cd, etc are all programs in linux/mac)




all: all-tests  speed-compare # this is the default target, it will run if you just type "make" in the terminal

all-tests: list-test vector-test bst-test 

list-test: $(LINKED_LIST_FILES) 
	$(CC) $(CFLAGS) -O3 -o list-test$(EXT) tests/linked_list_tester.c $^

vector-test: $(VECTOR_FILES)  
	$(CC) $(CFLAGS) -O3 -o vector-test$(EXT) tests/vector_tester.c $^

bst-test: $(BST_FILES)
	$(CC) $(CFLAGS) -O3 -o bst-test$(EXT) tests/bst_tester.c $^

speed-compare: $(LINKED_LIST_FILES) $(VECTOR_FILES) $(BST_FILES) $(SPEED_COMPARE_FILES)
    # this is the command to run, it compiles the files in CFILES and outputs the executable to speed compare  
	$(CC) $(CFLAGS) -o speed_compare$(EXT) $^


clean: #this is a clean target, it removes all the .exe/.out files, called via "make clean"
	rm  *$(EXT)