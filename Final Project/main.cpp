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

int main() {
	// Display the menu
	displayMenu();
	areaOfShapes();




	// Clear Screen
	char charVar = 0;;
	cout << "Type a key and press the enter key to clear the screen." << endl;
	cin.get();
	ClearScreen();
	cout << "The Screen has been cleared and all console data prior has been wiped out.\n";
	return 0;

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
		} else 
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

double getDimensions(double length, double depth, double height) {
	cout << "What is the length of the tank in inches? " << endl;
	cin >> length;
	cout << "What is the depth of the tank in inches? " << endl;
	cin >> depth;
	cout << "What is the height of the tank in inches? " << endl;
	cin >> height;
	if (length <= 0 || depth <= 0 || height <= 0) {
		cout << "Invalid input. Dimensions must be greater than 0." << endl;
	}
}




































void displayMenu() {
	int choice;
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
			break;
		case 3:
			cout << "You have selected Search and Sort Arrays" << endl;
			break;
		case 4:
			cout << "You have selected Password Validation" << endl;
			break;
		case 5:
			cout << "You have selected to exit the program. Goodbye. " << endl;
			break;
		default:
			cout << "Invalid choice. Please pick between 1-5." << endl;
			break;
		}
	} while (choice != 5);
}