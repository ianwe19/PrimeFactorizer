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

	if (primeNums.size() == 0) {
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
		for (int i = 2; i < num; i++) {
			for (int j = 0; j < primeNums.size(); j++) {
				if (primeNums.at(j) == num) {
					if (num % i == 0) {
						primeNums.push_back(num / i);
						primeNums.at(j) = i;
					}
				}
			}
		}
	}

	if (primeNums.size() == 0) {
		return true;
	}

	for (int n : primeNums) {
		for (int i = 2; i < n; i++) {
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
