/**************************************
Final Project: 5 Line Menu Based System 
Programmer: Kailey Scruggs
***************************************/
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cctype>
using namespace std;

/***********************
*  Function Prototypes *
************************/
void ClearScreen();
void displayMenu();
void areaOfShapes();
void calculateFishTank();
void getDimensions(double& length, double& depth, double& height);
double calcLargeVolume(double length, double depth, double height);
double calcCharge(double basePrice, double volumeCharge, double premiumCharge);
double calcCharge(double basePrice, double volumeCharge);
const int ARRAY_SIZE = 20;
void populateArray(int arr[], int size);
void searchAndSort();      
void passwordValidation();

int linearSearch(const int arr[], int size, int target);
void sortArray(int arr[], int size);
int binarySearch(const int arr[], int size, int target);
bool validatePassword(const char password[]);

int main() {
displayMenu();

}

/************************
*  Function Definitions *
*************************/
void ClearScreen()
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;
	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;
	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;
	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
// Area of a Square function
double calculateSquareArea(double length) {
	double area;
	area = length * length;
	return area;
}
// Area of a Triangle function 
double calculateTriangleArea(double base, double height) {
	double area;
	area = 0.5 * base * height;
	return area;
}
// Area of a Circle function 
double calculateCircleArea(double diameter) {
	const double PI = 3.14159;
	double area = PI * diameter * diameter;
	return area;
}

void areaOfShapes() {
	int choice;
	double length, height, diameter;
	double base = 0;

	cout << "1. Calculate the Area of a Square" << endl;
	cout << "2. Calculate the Area of a Triangle" << endl;
	cout << "3. Calculate the Area of a Circle" << endl;
	cout << "4. Exit" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Enter the length: " << endl;
		cin >> length;
		cout << fixed << setprecision(2) << "The area of the square is: " << calculateSquareArea(length) << endl;
		break;

	case 2:
		cout << "Enter the length of the triangle's base: " << endl;
		cin >> base;
		cout << "Enter the height of the triangle: " << endl;
		cin >> height;
		cout << fixed << setprecision(2) << "The area of the triangle is: " << calculateTriangleArea(base, height) << endl;
		break;

	case 3:
		cout << "Enter the length of the diameter of the circle: " << endl;
		cin >> diameter;
		cout << fixed << setprecision(2) << "The area of the circle is: " << calculateCircleArea(diameter) << endl;
		break;

	case 4:
		cout << "Do you want to exit? (Y/N): " << endl;
		char exitChoice;
		cin >> exitChoice;
		if (exitChoice == 'Y' || exitChoice == 'y') {
			cout << "Exiting the Area of Shapes Menu." << endl;
		}
		else
		{
			areaOfShapes(); // Redisplays the menu if they choose to stay
		}
		break;

	default:
		if (choice != 4) {
			cout << "Invalid choice. Please pick between 1-4." << endl;
		}
		else {
			cout << "Exiting the Area of Shapes Menu." << endl;
		}

		break;
	}
}
	
void displayMenu() {
	int choice;
	char exitConfirm;
	do {
		cout << "Menu Options: " << endl;
		cout << "1. Calculate Area of Shapes" << endl;
		cout << "2. Calculate Fish Tank Cost" << endl;
		cout << "3. Search and Sort Arrays" << endl;
		cout << "4. Password Validation" << endl;
		cout << "5. Exit" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			ClearScreen();
			areaOfShapes();
			break;

		case 2:
			ClearScreen();
			calculateFishTank();
			break;
		case 3:
			ClearScreen();
			searchAndSort();
			break;
		case 4:
			ClearScreen();
			passwordValidation();
			break;
		case 5:
			cout << "Are you sure you want to exit? (Y/N): " << endl;
			cin >> exitConfirm;
			exitConfirm = toupper(exitConfirm);

			if (exitConfirm != 'Y') {
				ClearScreen();
				choice = 0;
			}

			break;
		}
	} while (choice != 5);
	cout << "Thank you for using this program. Goodbye." << endl;

}

void calculateFishTank() {
    double length, depth, height;
    double basePrice = 150.0;
    double volumeCharge, totalCost;
    char wantPremium, wantFelt;

    getDimensions(length, depth, height);
	// Calculate the volume charge
	volumeCharge = calcLargeVolume(length, depth, height);
	// Asks about premium stand
	cout << "Would you like a premium stand? (Y/N): " << endl;
	cin >> wantPremium;

	while (wantPremium != 'Y' && wantPremium != 'N') {
		cout << "Invalid choice. Please enter Y or N: " << endl;
		cin >> wantPremium;
		wantPremium = toupper(wantPremium);
	}
	// Calculate the total cost
	if (wantPremium == 'Y') {
		totalCost = calcCharge(basePrice, volumeCharge, 300.0);
	}
	else {
		totalCost = calcCharge(basePrice, volumeCharge);
	}
	// Display the cost
	cout << "Fish Tank Summary:" << endl;
	cout << fixed << setprecision(2) << "Tank type: " << (wantPremium == 'Y' ? "Premium" : "Basic") << endl;
	cout << "Dimensions: " << length << "L x " << depth << "D x " << height << "H x inches" << endl;
	cout << "Cost Breakdown: " << endl;
	cout << "Base Tank Cost: $" << basePrice << endl;

	if (volumeCharge > 0) {
		cout << " Large Volume Charge: $" << volumeCharge << endl;
	}
	if (wantPremium == 'Y') {
		cout << " Premium Walnut Stand: $300.00" << endl;
	}

	cout << "\nTotal Cost: $" << totalCost << endl;

	cout << "\nPress Enter to return to main menu...";
	cin.get();
	cin.get();
	ClearScreen();
}
void getDimensions(double& length, double& depth, double& height) {
	cout << "Enter the length of the tank(10-48 inches): " << endl;
	cin >> length;
	if (length < 10 || length > 48) {
		cout << "Length must be between 10 and 48 inches." << endl;
	}
	cout << "Enter the depth of the tank(10-24 inches): " << endl;
	cin >> depth;
	if (depth < 10 || length > 14) {
		cout << "Depth must be between 10 and 24 inches." << endl;
	}
	cout << "Enter the height of the tank(10-24 inches): " << endl;
	cin >> height;
	if (height < 10 || height > 24) {
		cout << "Height must be between 10 and 24 inches." << endl;
	}
}
double calcLargeVolume(double length, double depth, double height) {
	double volume = length * depth * height;
	return (volume > 6000) ? 150.0 : 0.0;
}
double calcCharge(double basePrice, double volumeCharge, double premiumCharge) {
	char wantFelt;
	double feltCharge = 0.0;

	cout << "Would you like custom interior lining? (Y/N): " << endl;
	cin >> wantFelt;
	wantFelt = toupper(wantFelt);

	while (wantFelt != 'Y' && wantFelt != 'N') {
		cout << "Invalid input. Please enter Y/N: " << endl;
		cin >> wantFelt;
		wantFelt = toupper(wantFelt);
	}
	if (wantFelt == 'Y') {
		feltCharge = 50.0; 
		cout << " Custom Felt Lining: $50.00" << endl;
	}
	return basePrice + volumeCharge + premiumCharge + feltCharge;
}
double calcCharge(double basePrice, double volumeCharge) {
	return basePrice + volumeCharge;
}
// Search and Sort Arrays
void searchAndSort() {
	int arr[ARRAY_SIZE];
	int target;
	char repeat;

	do {
		cout << "Search and Sort Arrays" << endl;

		populateArray(arr, ARRAY_SIZE);

		cout << "Enter a value to search for: " << endl;
		cin >> target;
		// Linear search on an unsorted array
		int linearComparisons = linearSearch(arr, ARRAY_SIZE, target);
		// Sort the array
		sortArray(arr, ARRAY_SIZE);
		// Binary search on sorted array
		int binaryComparisons = binarySearch(arr, ARRAY_SIZE, target);
		// Display the results
		cout << "Search Results: " << endl;
		cout << "Linear Search Comparisons: " << linearComparisons << endl;
		cout << "Binary Search Comparisons: " << binaryComparisons << endl;

		if (linearComparisons < binaryComparisons) {
			cout << "Linear search was more effecient for this search." << endl;
		}
		else if (binaryComparisons < linearComparisons) {
			cout << "Binary search was more efficient for this search." << endl;
		}
		else {
			cout << "Both searches made the same number of comparisons." << endl;
		}
		cout << "Would you like to perform this operation again? (Y/N): " << endl;
		cin >> repeat;
		repeat = toupper(repeat);
		if (repeat == 'Y' || repeat == 'y') {
			ClearScreen();
		} 
	} while (repeat == 'Y' || repeat == 'y');
	ClearScreen();
}

void populateArray(int arr[], int size) {
	cout << "Please enter " << size << " UNSORTED integer values: " << endl;

	for (int i = 0; i < size; i++) {
		cout << "Value " << (i + 1) << ": " << endl;
		cin >> arr[i];
	}
}

int linearSearch(const int arr[], int size, int target) {
	int comparisons = 0;

	for (int i = 0; i < size; i++) {
		comparisons++;
		if (arr[i] == target) {
			return comparisons;
		}
	}
	return comparisons;
}
// Bubble sort
void sortArray(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int binarySearch(const int arr[], int size, int target) {
	int left = 0, right = size - 1;
	int comparisons = 0;

	while (left <= right) {
		comparisons++;
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return comparisons;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return comparisons;
}
// Passowrd Validation
void passwordValidation() {
	char password[100];
	char repeat;

	do {
		cout << "PASSWORD VALIDATION" << endl;
		cout << "Password Requirements: " << endl;
		cout << "  - At least 6 characters long" << endl;
		cout << "  - At least one uppercase letter" << endl;
		cout << "  - At least one lowercase letter" << endl;
		cout << "  - At least one digit" << endl;
		cout << "  - At least one special character: ? # % & ! @ { } ^ " << endl;
		
		cout << "Enter a password to validate: " << endl;
		cin >> password;

		bool isValid = validatePassword(password);

		if (isValid) {
			cout << "Password is VALID! All requirements met." << endl;
		}

		cout << "Would you like to validate another password? (Y/N): " << endl;
		cin >> repeat;
		repeat = toupper(repeat);

		if (repeat == 'Y') {
			ClearScreen();
		}
	} while (repeat == 'Y');
		ClearScreen();
}

bool validatePassword(const char password[]) {
	int length = 0;
	bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
	bool isValid = true;

	// Count length and check requirements
	for (int i = 0; password[i] != '\0'; i++) {
		length++;

		if (isupper(password[i])) {
			hasUpper = true;
		}
		if (islower(password[i])) {
			hasLower = true;
		}
		if (isdigit(password[i])) {
			hasDigit = true;
		}
		if (password[i] == '?' || password[i] == '#' || password[i] == '%' ||
			password[i] == '&' || password[i] == '!' || password[i] == '@' ||
			password[i] == '{' || password[i] == '}' || password[i] == '^' ||
			password[i] == '\\') {
			hasSpecial = true;
		}
	}

	cout << "Validation Results" << endl;

	if (length < 6) {
		cout << "Password must be at least 6 characters long.\n";
		isValid = false;
	}

	if (!hasUpper) {
		cout << "Password must contain at least one uppercase letter.\n";
		isValid = false;
	}

	if (!hasLower) {
		cout << "Password must contain at least one lowercase letter.\n";
		isValid = false;
	}

	if (!hasDigit) {
		cout << "Password must contain at least one digit.\n";
		isValid = false;
	}

	if (!hasSpecial) {
		cout << "Password must contain at least one special character (? # % & ! @ { } ^ \\).\n";
		isValid = false;
	}

	return isValid;
}