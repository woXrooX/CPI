#include "../source/CPI.hpp"
#include <iostream>

int main(){
	std::string resp = woXrooX::CPI::bridge("Hello from C++!");

	std::cout << resp << '\n';

	return 0;
}
