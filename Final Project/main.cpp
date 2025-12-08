/**************************************
Final Project: 5 Line Menu Based System 
Programmer: Kailey Scruggs
***************************************/
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

/***********************
*  Function Prototypes *
************************/
void ClearScreen();
void displayMenu();
void areaOfShapes();
void calculateFishTankCost();


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

// Fish Tank Calculations
double calculateVolume(double length, double width, double height) {
	return length * width * height;
}

double calculateCost(double volume, double costPerGallon) {
	const double cubicInches = 231.0;
	double gallons = volume / cubicInches;
	return gallons * costPerGallon;
}

void calculateFishTankCost() {
	double length, width, height, costPerGallon;

	cout << "Fish Tank Cost Calculator" << endl;
	cout << "Enter the length of the tank (inches): ";
	cin >> length;
	cout << "Enter the width of the tank (inches): ";
	cin >> width;
	cout << "Enter the height of the tank (inches): ";
	cin >> height;
	cout << "Enter the cost per gallon: $";
	cin >> costPerGallon;

	double volume = calculateVolume(length, width, height);
	double totalCost = calculateCost(volume, costPerGallon);

	cout << "Tank Volume: " << volume << " cubic inches" << endl;
	cout << fixed << setprecision(2) << "Total Cost: $" << totalCost << endl;
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
}

// Search and Sort Arrays

void bubbleSort(int arr[], int size) {
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
int linearSearch(int arr[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}
int binarySearch(int arr[], int size, int target) {
	int left = 0, right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) return mid;
		if (arr[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
void searchAndSortArrays() {
	const int SIZE = 10;
	int arr[SIZE];
	int choice, target, result;

	cout << "Enter " << SIZE << " integers: " << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Element " << (i + 1) << ": ";
		cin >> arr[i];
	}
	cout << "1. Sort Array" << endl;
	cout << "2. Linear Search" << endl;
	cout << "3. Binary Search (sorts first)" << endl;
	cout << "Enter your choice: "<< endl;
	cin >> choice;
	switch (choice) {
	case 1:
		bubbleSort(arr, SIZE);
		cout << "Sorted Array: ";
		for (int i = 0; i < SIZE; i++) {
			cout << arr[i] << " ";
		}
		break;
	case 2:
		cout << "Enter value to search: ";
		cin >> target;
		result = linearSearch(arr, SIZE, target);
		if (result != -1)
			cout << "Found at index: " << result;
		else
			cout << "Not found in array.";
		break;
	case 3:
		bubbleSort(arr, SIZE);
		cout << "Array sorted for binary search.";
		cout << "Enter value to search: ";
		cin >> target;
		result = binarySearch(arr, SIZE, target);
		if (result != -1)
			cout << "Found at index: " << result;
		else
			cout << "Not found in array.";
		break;
	default:
		cout << "Invalid choice!";
	}

	cout << "\nPress Enter to continue...";
	cin.ignore();
	cin.get();
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
			cout << "You have selected Calculate Area of Shapes." << endl;
			areaOfShapes();
			break;

		case 2:
			cout << "You have selected Fish Tank Cost" << endl;
			calculateFishTankCost();
			break;
		case 3:
			ClearScreen();
			searchAndSortArrays();
			ClearScreen();
			break;
		case 4:
			cout << "You have selected Password Validation" << endl;
			break;
		case 5:
			cout << "Are you sure you want to exit? (y/n) " << endl;
			cin >> exitConfirm;
			if (exitConfirm == 'y' || exitConfirm == 'Y') {
				cout << "Goodbye!" << endl;
				return;
			}
			else {
				ClearScreen();
			}
			break;
		default:
			cout << "Invalid choice. Please pick between 1-5." << endl;
			break;
		}
	} while (choice != 5);
}