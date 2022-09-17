#include <iostream>
#include <vector>


int getInput();
bool isPrime(int num, std::vector<int>& primeNums);
void outputMessage(int num, std::vector<int>& primeNums);

int main() {

	std::vector<int> primeNums = {};



	int num = int(0);
	num = getInput();
	if (isPrime(num, primeNums)) {
		outputMessage(num, primeNums);
	}
	else {
		outputMessage(num, primeNums);
	}
}


int getInput() { // TODO make this sanitize input
	int num = int(0);
	std::cout << "Enter a number: ";
	std::cin >> num;

	return num;
}


bool isPrime(int num, std::vector<int>& primeNums) {
	bool result;
	for (int i = 2; i < num; i++) { // starts at 2 because 0, 1 are not prime
		if (num % i == 0) {
			primeNums.push_back(i);
			if (i * i == num) {
				primeNums.push_back(i);
			}
			result = false;
		}
	}
	return true;
}


void outputMessage(int num, std::vector<int>& primeNums) {
	// std::cout << "is prime";
	
	for (int i: primeNums) {
		std::cout << i << " has been found as a prime factor.\n";
	}
}
