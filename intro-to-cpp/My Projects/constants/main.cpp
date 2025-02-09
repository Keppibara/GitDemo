#include <iostream>


void displayCallCount() {
	static int callCount = 0;
	callCount++;
	std::cout << "I have been called " << callCount << " times" << std::endl;
}

int main() {
	for (int i = 0; i < 10; i++) {
		displayCallCount();
	}

	return 0;
}