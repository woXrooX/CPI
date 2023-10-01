#include "../source/CPI.hpp"
#include <iostream>

int main(){
	woXrooX::CPI::absolute_path = "/home/woxroox/Desktop/test";
	woXrooX::CPI::file_name = "test.py";

	std::string resp = woXrooX::CPI::bridge("Hello from main.cpp!");

	std::cout << resp << '\n';

	return 0;
}
