#include <iostream>


int getInput();
bool isPrime(int num);
void outputMessage(int num);

int main() {
	int num = int(0);
	num = getInput();
	if (isPrime(num)) {
		outputMessage(num);
	}
}


int getInput() { // TODO make this sanitize input
	int num = int(0);
	std::cout << "Enter a number: ";
	std::cin >> num;

	return num;
}


bool isPrime(int num) {
	for (int i = 2; i < num; i++) { // starts at 2 because 0, 1 are not prime
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}


void outputMessage(int num) {
	std::cout << "is prime";
}
