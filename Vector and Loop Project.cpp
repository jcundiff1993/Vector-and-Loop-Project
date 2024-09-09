#include<iostream>
#include<vector>


using namespace std;


int main() {
	char user_input{};
	vector <int> user_numbers{};

	do {
		//Display Menu
		cout << "P - Print Number(s)" << endl;
		cout << "A - Add a Number" << endl;
		cout << "M - Display the Mean of the numbers" << endl;
		cout << "S - Display the Smallest number" << endl;
		cout << "L - Display the Largest number" << endl;
		cout << "Q - Quit" << endl;
		cout << endl;
		cin >> user_input;
		cout << endl;

		user_input = toupper(user_input); // Changing all inputs to uppercase

		switch (user_input) {
		case 'P':
			cout << "Printing numbers now:" << endl;
			if (user_numbers.size() == 0) {
				cout << "[] The list is empty" << endl;
				cout << endl;
			}
			else {
				cout << "------------" << endl;
				for (auto num : user_numbers)
					cout << num << " " << endl;
				cout << "____________" << endl;

			}
			break;

		case 'A':
		{
			int new_numbers{};
			do {
				cout << "Enter the numbers you would like to add below or enter 0 to return" << endl;
				cin >> new_numbers;
				cout << endl;
				if (new_numbers == 0) {
					cout << "";
				}
				else if (new_numbers > 0) {
					user_numbers.push_back(new_numbers);
					cout << new_numbers << " added!" << endl;
				}
			} while (new_numbers != 0);
			cout << "Returning..." << endl;
			break;
		}
		case 'M':
			if (user_numbers.size() == 0) {
				cout << "Unable to calculate mean: Insufficient Data" << endl;
			}
			else {
				int total{};
				for (auto num : user_numbers)
					total += num;
				cout << "The mean is: " << static_cast<double>(total) / user_numbers.size() << endl;
			}
			break;

		case 'S':
			if (user_numbers.size() == 0) {
				cout << "There aren't any numbers present." << endl;
			}
			else {
				int smallest = user_numbers.at(0);
				for (auto num : user_numbers)
					if (num < smallest)
						smallest = num;
				cout << "The smallest number is currently: " << smallest << endl;
			}
			break;
		case 'L':
			if (user_numbers.size() == 0) {
				cout << "There aren't any numbers present." << endl;
			}
			else {
				int largest = user_numbers.at(0);
				for (auto num : user_numbers)
					if (num > largest)
						largest = num;
				cout << "The largest number is currently: " << largest << endl;
			}
			break;

		case 'Q':
			cout << "Closing Program Now..." << endl;
			break;

		default:
			cout << "Please select from the options provided." << endl;
		}
	} while (user_input != 'Q');

	return 0;
}