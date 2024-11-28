#include <iostream>

extern "C" {
	void message(char *msg){
		std::cout << msg << std::endl;
	}
}
