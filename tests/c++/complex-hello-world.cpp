#include <iostream>

namespace WordEnv{
	class Word{
		private:
			char size;
			char *chars;
			short checkSpaces(void);
		public:
			Word(void);
			~Word(void);
			bool setSize(int _size);
			bool addChar(char c);
			bool printChar(int id);
			short getSize(void);
	};

	short Word::checkSpaces(void){
		for(short i = 0; i <= size; i++)
			if(chars[i] == '\0')
				return i;

		return -1;
	}

	Word::Word(void){
		chars = NULL;
	}

	Word::~Word(void){
		if(chars != NULL)
			delete chars;
	}

	bool Word::setSize(int _size){
		size = _size;

		if(size < 1)
			return false;

		chars = new char[size];

		for(short i = 0; i <= size; i++)
			chars[i] = '\0';
		
		return true;
	}

	bool Word::addChar(char c){
		short id = checkSpaces();
		if(id == -1)
			return false;

		chars[id] = c;
		return true;
	}

	bool Word::printChar(int id){
		if(checkSpaces() == 0)
			return false;

		std::cout << chars[id];

		return true;
	}

	short Word::getSize(void){
		return size;
	}
}

namespace ErrorEnv{
	class Error{
		public:
			bool invalidSize(bool a);
			bool overflow(int id, bool a);
			bool nonContent(bool a);
	};

	bool Error::invalidSize(bool a){
		if(!a){
			std::cout << "Invalid size" << std::endl;
			return true;
		}

		return false;
	}

	bool Error::overflow(int id, bool a){
		if(!a){
			std::cout << "Overflow (" << id << ")" << std::endl;
			return true;
		}

		return false;
	}
	
	bool Error::nonContent(bool a){
		if(!a){
			std::cout << "None content finded" << std::endl;
			return true;
		}

		return false;
	}
}

using namespace WordEnv;
using namespace ErrorEnv;

int main(void){
	Word welcome;
	Error err;

	const short msgLen = 13;
	char msg[msgLen - 1] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};

	if(err.invalidSize(welcome.setSize(msgLen)))
		return 1;

	for(short i = 0; i < msgLen; i++)
		if(err.overflow(1, welcome.addChar(msg[i])))
			return 1;

	for(short i = 0; i <= welcome.getSize(); i++)
		if(err.nonContent(welcome.printChar(i)))
			return 1;

	std::cout << std::endl;
	
	return 0;
}
