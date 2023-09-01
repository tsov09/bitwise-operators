#include <iostream>
#include <vector>
int find_nth_bit(int number, int n) {
	if (n >= 0 && n <= 8 * sizeof(int)) {
		std::cout << "10th bit of " << number << " is " << (number >> n) << "." << std::endl; //this line is for demonstartion, need to be removed
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

int main() {

	try {
		find_nth_bit(1025, 10);
		find_nth_bit(102, 10);
		//find_nth_bit(102, 35);
	}
	catch (int x) {
		std::cout << "The number is out of range of bit's count in int type." << std::endl;
	}

	std::vector<int> nums { 2, 7, 8, 5, 4, 8, 5, 2, 4 };
	
	std::cout << "Vector: { ";
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}
	std::cout << "}" << std::endl;

	std::cout << find_single_element(nums) << " hasn't duplicate in vector.";

	return 0;
}