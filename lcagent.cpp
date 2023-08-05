#include <cstdlib>
#include <iostream>

int main(int argc, char** argv){
	// Ignore the first argument (the file path of the executable)
	--argc;
	++argv;
	
	return EXIT_SUCCESS;
}
