#include "ScreenDimmer.hpp"
#include "Main.hpp"

int main(int argc, char** argv) {
	int code = 0;

	std::string command = argc > 1 ? argv[1] : "";
	if (command.compare("start") == 0) {
		ScreenDimmer screenDimmer;
		code = screenDimmer.run(1, argv);
	}
	else if (command.compare("stop") == 0) {
		std::system("killall 'screendimmer' &");
	}
	else {
		std::cout <<  "Missing argument 'start' or 'stop'"<< std::endl;
	}

	return code;
}
