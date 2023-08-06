#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <string_view>

int init(std::string_view LCAGENT_DIR);
void add(int argc, char **argv);
void help();

int main(int argc, char **argv) {
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

	// Grab the necessary environment variables
	std::string ENV_PWD{std::filesystem::current_path()};

	// Produce the necessary shared metadata
	std::string LCAGENT_DIR = ENV_PWD + "/.lcagent";

	if (subCommand == "init") {
		return init(LCAGENT_DIR);
	} else if (subCommand == "add") {
		add(argc, argv);
	} else if (subCommand == "help") {
		help();
	} else {
		std::cerr << "lcagent: I don't quite recognize that sub-command \"" << subCommand << "\"! \n"
				  << "lcagent: Try the command \"lcagent help\" to see a list of sub-commands I support!\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int init(std::string_view LCAGENT_DIR) {
	if (std::filesystem::exists(LCAGENT_DIR) && std::filesystem::is_directory(LCAGENT_DIR)) {
		std::cerr << "lcaagent: The lcagent is already initialized in your current directory!\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void add(int argc, char **argv) {}

void help() {}
