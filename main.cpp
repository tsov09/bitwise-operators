#include <iostream>
#include <vector>
#include <string>

void prev_hwk() {
	//try {
	//	find_nth_bit(3072, 10);
	//	find_nth_bit(102, 10);
	//	//find_nth_bit(102, 35);
	//}
	//catch (int x) {
	//	std::cout << "The number is out of range of bit's count in int type." << std::endl;
	//}

	//std::vector<int> nums { 2, 7, 8, 5, 4, 8, 5, 2, 4 };
	//
	//std::cout << "Vector: { ";
	//for (int i = 0; i < nums.size(); i++) {
	//	std::cout << nums[i] << " ";
	//}
	//std::cout << "}" << std::endl;

	//std::cout << find_single_element(nums) << " hasn't duplicate in vector." << std::endl;

}

int find_nth_bit(int number, int n) {
	if (n >= 0 && n <= 8 * sizeof(int)) {
		std::cout << "10th bit of " << number << " is " << ((number >> n) & 1) << "." << std::endl; //this line is for demonstartion, need to be removed
		return number >> n;
	}
	else {
		throw -1;
	}
}

int find_single_element(std::vector<int> nums) {
	int single = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		single = single ^ nums[i];
	}

	return single;
}

std::string get_binary_code_of_char(char ch) {
	int x = ch + 0;
	std::string code;
	int indicator = 128;

	for (int i = 0; i < 8 * sizeof(ch); i++) {
		(indicator & x) == 0 ? (code += '0') : (code += '1');
		indicator = indicator >> 1;
	}
	return code;
}

std::string get_binary_code_of_string(std::string str) {
	std::string code;
	for (int i = 0; i < str.length(); i++) {
		code += get_binary_code_of_char(str[i]);
	}
	std::cout << code << std::endl;
	return code;
}

std::string get_binary_code_of_two_strings_sum(std::string str_1, std::string str_2) {
	return get_binary_code_of_string(str_1 + str_2);
}

int main() {
	//Compared counts of bits' values

	std::cout << std::endl;

	int a = 20119574;
	int b = 1;
	int count = 0;

	for (int i = 0; i < 8 * sizeof(a); i++) {
		if (a & b) {
			count++;
			if (count > 4 * sizeof(a)) {
				break;
			}
		}
		b = b << 1;
	}

	std::cout << "Count of 1 in binary code of integer " << a << " is ";
	if (count > 4 * sizeof(a)) {
		std::cout << "greater than ";
	}
	else if (count < 4 * sizeof(a)) {
		std::cout << "less than ";
	}
	else {
		std::cout << "equal to ";
	}
	std::cout << " count of 0." << std::endl;
	std::cout << std::endl;


	//got binary code of two strings' sum

	std::string str_1("Hello ");
	std::string str_2("World!");
	std::cout << "Binary code of '" <<  str_1 << "' and '" << str_2 << "' strings sum is :" << std::endl;
	std::string bin_code = get_binary_code_of_two_strings_sum(str_1, str_2);
	std::cout << std::endl;
	
	return 0;
}