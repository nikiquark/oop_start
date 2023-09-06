#include <iostream>
#include <string>

#include <BraceChecker.h>

int main() {
	std::string sequence;

	std::getline(std::cin, sequence);

	if (isBalanced(sequence)) {
		std::cout << "Balanced" << std::endl;
	} else {
		std::cout << "Not balanced" << std::endl;
	}

	return 0;
}
