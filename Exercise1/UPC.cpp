#include <iostream>
#include <string>

using namespace std;


/**
@file Exercise1_rasare3.cpp
@author Richie
@date 2026 - 10- 14
@brief This program validates UPC-A barcodes performing the UPC-A check digit algorithm. 
*/



// Function prototypes
int calculateCheckDigit(const string& upc) ;
bool isValidUPC(const string& upc) ;
void displayResult(bool valid);
void runUPCValidator();





/**
*@brief Calculates the check digit for a UPC-A code.
*@param upc The UPC-A code being checked.
*@return The calculated check digit.
*/
 int calculateCheckDigit(const string& upc) {

	 int oddSum = 0;
	 int evenSum = 0;

	 for (int i = 0; i < upc.length() - 1; i++) {
		 if (i % 2 == 0) {
			 oddSum += upc[i] - '0';
		 }
		 else {
			 evenSum += upc[i] - '0';
		 }
	 }
	 
	 oddSum *= 3;

	 int totalSum = oddSum + evenSum;
	 int remainder = totalSum % 10;

	 int checkDigit; 

		 if (remainder == 0) {
			 checkDigit = 0;
		 }
		 else {
			 checkDigit = 10 - remainder;
		 }
	 

	 return checkDigit;
 }


 

 /**
 @brief checks whether a UPC-A code is valid.
 @param upc The UPC-A code being checked.
 @return true if the UPC-A code is valid, false otherwise.
 */
 bool isValidUPC(const string& upc) 
 {
	 if (upc.length() != 12) {
		 return false;
	 }
	 for (char digit : upc) {
		 if (digit < '0' || digit > '9') {
			 return false;
		 }
	 }
	 int calculatedCheckDigit = calculateCheckDigit(upc);
	 int actualCheckDigit = upc[upc.length() - 1] - '0';
	 if (calculatedCheckDigit == actualCheckDigit) {
		 return true;
	 }
	 else {
		 return false;
	 }
 }


 /**
 @brief Displays the result of the UPC validation.
 @param valid The validation result (true if valid, false otherwise).
 */
 void displayResult(bool valid) {
	 if (valid) {
		 cout << "The UPC is valid." << endl;
	 }
	 else {
		 cout << "The UPC is invalid." << endl;
	 }
 }


 /**
 * @brief Runs the UPC validator process and hundles user interaction.
 */
 void runUPCValidator() {
	 string upc;
	 char choice;
	 do {
		 cout << "Enter a UPC -A code: ";
		 cin >> upc;
		 bool valid = isValidUPC(upc);
		 displayResult(valid);
		 cout << "would you like to enter another UPC? (y/n): ";
		 cin >> choice;
	 } while (choice == 'y' || choice == 'Y');
 }



/**
*@brief Starts the UPC validator program.
* @p
*@return 0 when the program finishes successfully.
*/
int main() 
{

	runUPCValidator();


	return 0;

}





