#include <iostream>
#include <vector>


int getInput();
bool isPrime(int num, std::vector<int>& primeNums);
void outputMessage(int num, std::vector<int>& primeNums, bool isPrime);


int main() {

	std::vector<int> primeNums = {};

	int num = int(0);

	num = getInput();

	/*if (isPrime(num, primeNums)) {
		std::cout << ""
	}
	else {
		
	}*/

	outputMessage(num, primeNums, isPrime(num, primeNums));
}


int getInput() { // TODO make this sanitize input
	int num = int(0);
	std::cout << "Enter a number: ";
	std::cin >> num;

	return num;
}


bool isPrime(int num, std::vector<int>& primeNums) {
	bool result;

	for (int i = 2; i < num; i++) { // starts at 2 because 0 and 1 are not prime
		if (num % i == 0) { // runs if composite
			primeNums.push_back(i);
			if (i * i == num) {
				primeNums.push_back(i);
			}
			result = false;
		}
		else { // runs if prime
			result = true;
		}
	}
	return result;
}


void outputMessage(int num, std::vector<int>& primeNums, bool isPrime) {
	if (isPrime) {
		std::cout << num << " is a PRIME number.\n";
	}
	else {
		std::cout << num << " is a COMPOSITE number.\n";
	}
	
	for (int i: primeNums) {
		std::cout << i << " has been found as a prime factor.\n";
	}
}
