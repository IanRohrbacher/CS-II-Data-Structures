#include <iostream>
#include <fstream>

void newLine();
void addTwo();

int main() {
	newLine();

	std::cout << "--------------------" << '\n';

	addTwo();

	return 0;
}

// read "fileio-text.txt" all spaces as end line '\n'
void newLine() {
	std::ifstream file("fileio-text.txt");
	if (!file.is_open()) {
		std::cout << "Unable To Open File\n";
	}
	else {
		char ch;
		file.get(ch);
		while (!file.eof()) {
			std::cout << (ch == ' ' ? '\n' : ch);
			file.get(ch);
		}
	}
}

// read "fileio-data-1.txt" and add the lines together
void addTwo() {
	std::ifstream file("fileio-data-1.txt");
	if (!file.is_open()) {
		std::cout << "Unable To Open File\n";
	}
	else {
		int num;
		int total = 0;
		char buffer = ' ';
		int flag = true;
		while (file >> num) {
			std::cout << num;
			total += num;
			file >> buffer;
			if (flag) {
				std::cout << "+";
				flag = !flag;
			}
			else {
				std::cout << "=" << total << '\n';
				total = 0;
				flag = !flag;
			}
		}
		file.close();
	}
}