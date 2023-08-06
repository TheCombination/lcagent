#include <cstdlib>
#include <iostream>

void add(int argc, char** argv);
void help();

int main(int argc, char** argv){
	// Ignore the first argument (the file path of the executable)
	--argc;
	++argv;
	
	// Ensures there is at least one argument
	if (argc < 1) {
		std::cerr << "lcagent: I require at least one argument.\n"
			 << "lcagent: Try the command \"lcagent help\" for more information on what I can do for you!\n";
		return EXIT_FAILURE;
	}

	std::string subCommand{argv[0]};
	
	// Now, ignore the sub-command
	--argc; 
	++argv;

	if (subCommand == "add") {
 		add(argc, argv);
	} else if (subCommand  == "help") {
		help();
	} else {
		std::cerr << "lcagent: I don't quite recognize that sub-command \"" << subCommand << "\"! \n" 
				  << "lcagent: Try the command \"lcagent help\" to see a list of sub-commands I support!\n";
		return EXIT_FAILURE;
	}
		
	return EXIT_SUCCESS;
}

void add(int argc, char** argv) {}

void help(){}


