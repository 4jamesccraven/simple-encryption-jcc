#include <iostream>
#include <string>
#include <algorithm>

void caesarEncryption(std::string& toEncrypt, char shiftBy);

int main() {
	std::string inputString = "";
	char shiftByChar = ' ';
	
	//get string to encrypt an encryption key
	std::cout << "String to encrypt:" << std::endl;
	std::getline(std::cin >> std::ws, inputString);
	std::cout << "Character to shift by:" << std::endl;
	std::cin >> shiftByChar;

	caesarEncryption(inputString, shiftByChar);

	//output encrypted string
	std::cout << inputString << std::endl;

	return 0;
}

void caesarEncryption(std::string& toEncrypt, char shiftBy) {
	int increment = 0; //amount to increase ascii value by
	int asciiStart = (std::isupper(shiftBy)) ? 64 : 96; //amount removed due to the location of the ascii character values

	increment = int(shiftBy) - asciiStart;

	std::for_each(toEncrypt.begin(), toEncrypt.end(), [increment, asciiStart](char& c) {
		if (std::isalpha(c)) { //if is a letter
			int x = int(c); //cast as int
			x += increment; //increment
			if (x > asciiStart + 26) x -= 26; //wrap to start of alphabet range if necessary
			c = char(x); //set char to value casted as char
		}
	});
}
