#include <cstdlib>
#include <iostream>

int main(int argc, char** argv){
	// Ignore the first argument (the file path of the executable)
	--argc;
	++argv;
	
	// Ensures there is at least one argument
	if (argc < 1) {
		std::cerr << "lcagent: I require at least one argument.\n"
			 << "lcagent: Try the command 'lcagent help' for more information on what I can do for you!\n"; 
	}	
	
	return EXIT_SUCCESS;
}
