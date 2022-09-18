#include <iostream>
#include <vector>


int getInput();
bool findPrimeFactors(int num, std::vector<int>& primeNums);
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

	outputMessage(num, primeNums, findPrimeFactors(num, primeNums));
}


int getInput() { // TODO make this sanitize input
	int num = int(0);
	std::cout << "Enter a number: ";
	std::cin >> num;

	return num;
}


bool findPrimeFactors(int num, std::vector<int>& primeNums) {

	if (!primeNums.empty()) {
		for (int i = 2; i < num; i++) {
			if (num % i == 0) { // runs if composite

				primeNums.clear();
				primeNums.push_back(i);
				primeNums.push_back(num / i);

				break;
			}
		}
	}
	else {

	}

	if (primeNums.empty()) {
		return true;
	}

	for (int n : primeNums) {
		for (int i = 2; i < num; i++) {
			if (n % i == 0) {
				findPrimeFactors(n, primeNums);
			}
		}
	}

	return false;
}


void outputMessage(int num, std::vector<int>& primeNums, bool isPrime) {
	if (isPrime) {
		std::cout << num << " is a PRIME number.\n";
	}
	else {
		std::cout << num << " is a COMPOSITE number.\n";
	}
	
	for (int n: primeNums) {
		std::cout << n << " has been found as a prime factor.\n";
	}
}
