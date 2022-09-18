#include <iostream>
#include <iomanip>
#include <vector>


int getInput();
bool findPrimeFactors(int num, std::vector<int>& primeNums);
bool breakDownFurther(int num, std::vector<int>& primeNums);
void outputMessage(int num, std::vector<int>& primeNums, bool isPrime);


int main() {
	int num = int(0);
	std::vector<int> primeNums = {};

	num = getInput();

	outputMessage(num, primeNums, findPrimeFactors(num, primeNums));
}


int getInput() { // TODO make this sanitize input
	int num = int(0);
	std::cout << "Enter a number: ";
	std::cin >> num;

	return num;
}


// builds vector of prime factors and returns whether input is prime or composite, kind of a hot mess and really slow
bool findPrimeFactors(int num, std::vector<int>& primeNums) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) { // runs if composite
			primeNums.clear();
			primeNums.push_back(num / i);
			primeNums.push_back(i);
			break;
		}
	}

	if (primeNums.size() == 0) {
		return true; // input number is prime
	}

	return false; // input number is composite
}


bool breakDownFurther(int num, std::vector<int>& primeNums) {
	for (int n : primeNums) {
		for (int i = 2; i < num; i++) {
			if (num % i == 0) { // runs if composite
				primeNums.push_back(num / i);
				primeNums.push_back(i);
				break;
			}
		}
	}
}


void outputMessage(int num, std::vector<int>& primeNums, bool isPrime) {
	if (isPrime) {
		std::cout << num << " is a PRIME number.\n";
	}
	else {
		std::cout << num << " is a COMPOSITE number.\n";
	}
	
	for (int n : primeNums) {
		std::cout << std::setw(3) << n << std::setw(1) << " has been found as a prime factor.\n";
	}
}
