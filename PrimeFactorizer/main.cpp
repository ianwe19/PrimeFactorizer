#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>


const int MIN_NUM = 2;


int getInput();
bool findPrimeFactors(int num, std::vector<int>& primeNums);
bool canBeBrokenDownFurther(std::vector<int>& primeNums);
void breakDownFurther(int num, std::vector<int>& primeNums);
void outputMessage(int num, std::vector<int>& primeNums, bool isPrime);


int main() {
	int num = int(0);
	bool isPrime = NULL;
	std::vector<int> primeNums = {};

	num = getInput();

	isPrime = findPrimeFactors(num, primeNums);

	breakDownFurther(num, primeNums);

	outputMessage(num, primeNums, isPrime);
}


int getInput() {
	int num = int(0);

	while (!(std::cin) || num <= MIN_NUM) { // for input sanitization
		std::cin.clear();
		std::cout << "Enter a number greater than 2: ";
		std::cin >> num;
		rewind(stdin); // clear buffer
	}

	return num;
}


// builds vector of  first 2 prime factors and returns whether input is prime or composite
bool findPrimeFactors(int num, std::vector<int>& primeNums) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) { // runs if composite
			primeNums.push_back(i); // add both factors to primeNums
			primeNums.push_back(num / i);
			break;
		}
	}

	if (primeNums.size() == 0) {
		return true; // input number is prime
	}

	return false; // input number is composite
}


// iterate through primeNums to check for composite numbers and returns true if found
bool canBeBrokenDownFurther(std::vector<int>& primeNums) {
	for (int n : primeNums) {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) { // runs if composite
				return true;
			}
		}
	}
	return false;
}


// find factors of factors
void breakDownFurther(int num, std::vector<int>& primeNums) {
	while (canBeBrokenDownFurther(primeNums)) {
		int index = int(0);
		for (int n : primeNums) {
			for (int i = 2; i < n; i++) {
				if (n % i == 0) { // runs if composite
					primeNums.insert(primeNums.begin(), i);
					primeNums.at(index + 1) = n / i;
					break;
				}
			}
			index++;
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
