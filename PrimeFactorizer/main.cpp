#include <iostream>
#include <iomanip>
#include <vector>


int getInput();
bool findPrimeFactors(int num, std::vector<int>& primeNums);
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
	if (primeNums.size() == 0) { // runs if function is not being run recursively
		for (int i = 2; i < num; i++) {
			if (num % i == 0) { // runs if composite
				primeNums.clear();
				primeNums.push_back(num / i);
				primeNums.push_back(i);
				break;
			}
		}
	}
	else { // runs if function is being run recursively
		for (int i = 2; i < num; i++) {
			for (int j = 0; j < primeNums.size(); j++) {
				if (primeNums.at(j) == num && num % i == 0) {
					primeNums.push_back(i); // append and write factors 
					primeNums.at(j) = num / i;
				}
			}
		}
	}

	if (primeNums.size() == 0) {
		return true; // input number is prime
	}

	for (int n : primeNums) {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				findPrimeFactors(n, primeNums);
			}
		}
	}

	return false; // input number is composite
}


void outputMessage(int num, std::vector<int>& primeNums, bool isPrime) {
	if (isPrime) {
		std::cout << num << " is a PRIME number.\n";
	}
	else {
		std::cout << num << " is a COMPOSITE number.\n";
	}
	
	for (int n: primeNums) {
		std::cout << std::setw(3) << n << std::setw(1) << " has been found as a prime factor.\n";
	}
}

