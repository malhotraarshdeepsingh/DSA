#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;

const int BIT_SIZE = 16;

string decimalToBinary(int num) {
    return bitset<BIT_SIZE>(num).to_string();
}

string onesComplement(int num) {
    string binary = decimalToBinary(num);
    for (char &c : binary) {
        c = (c == '0') ? '1' : '0';
    }
    return binary;
}

string twosComplement(int num) {
    if (num >= 0) return decimalToBinary(num);
    string ones = onesComplement(abs(num));
    bitset<BIT_SIZE> twos(stoi(ones, 0, 2) + 1);
    return twos.to_string();
}

string signedBinary(int num) {
    bitset<BIT_SIZE> binary(num);
    return binary.to_string();
}

string decimalToHexadecimal(int num) {
    stringstream ss;
    ss << hex << uppercase << num;
    return ss.str();
}

string decimalToOctal(int num) {
    stringstream ss;
    ss << oct << num;
    return ss.str();
}

int binaryToDecimal(string binary) {
    return stoi(binary, 0, 2);
}

string binaryToHexadecimal(string binary) {
    int decimal = binaryToDecimal(binary);
    return decimalToHexadecimal(decimal);
}

string binaryToOctal(string binary) {
    int decimal = binaryToDecimal(binary);
    return decimalToOctal(decimal);
}

int hexadecimalToDecimal(string hex) {
    return stoi(hex, 0, 16);
}

string hexadecimalToBinary(string hex) {
    int decimal = hexadecimalToDecimal(hex);
    return decimalToBinary(decimal);
}

string hexadecimalToOctal(string hex) {
    int decimal = hexadecimalToDecimal(hex);
    return decimalToOctal(decimal);
}

int octalToDecimal(string octal) {
    return stoi(octal, 0, 8);
}

string octalToBinary(string octal) {
    int decimal = octalToDecimal(octal);
    return decimalToBinary(decimal);
}

string octalToHexadecimal(string octal) {
    int decimal = octalToDecimal(octal);
    return decimalToHexadecimal(decimal);
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n===== Number System Calculator =====" << endl;
        cout << "1. Convert from Decimal" << endl;
        cout << "2. Convert from Binary" << endl;
        cout << "3. Convert from Hexadecimal" << endl;
        cout << "4. Convert from Octal" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int decimal;
                cout << "Enter a decimal number: ";
                cin >> decimal;
                cout << "Binary: " << decimalToBinary(decimal) << endl;
                cout << "Hexadecimal: " << decimalToHexadecimal(decimal) << endl;
                cout << "Octal: " << decimalToOctal(decimal) << endl;
                cout << "1's Complement: " << onesComplement(decimal) << endl;
                cout << "2's Complement: " << twosComplement(decimal) << endl;
                cout << "Signed Binary: " << signedBinary(decimal) << endl;
                break;
            }

            case 2: {
                cout << "Enter a binary number: ";
                cin >> input;
                int decimal = binaryToDecimal(input);
                cout << "Decimal: " << decimal << endl;
                cout << "Hexadecimal: " << binaryToHexadecimal(input) << endl;
                cout << "Octal: " << binaryToOctal(input) << endl;
                cout << "1's Complement: " << onesComplement(decimal) << endl;
                cout << "2's Complement: " << twosComplement(decimal) << endl;
                cout << "Signed Binary: " << signedBinary(decimal) << endl;
                break;
            }

            case 3: {
                cout << "Enter a hexadecimal number: ";
                cin >> input;
                int decimal = hexadecimalToDecimal(input);
                cout << "Decimal: " << decimal << endl;
                cout << "Binary: " << hexadecimalToBinary(input) << endl;
                cout << "Octal: " << hexadecimalToOctal(input) << endl;
                cout << "1's Complement: " << onesComplement(decimal) << endl;
                cout << "2's Complement: " << twosComplement(decimal) << endl;
                cout << "Signed Binary: " << signedBinary(decimal) << endl;
                break;
            }

            case 4: {
                cout << "Enter an octal number: ";
                cin >> input;
                int decimal = octalToDecimal(input);
                cout << "Decimal: " << decimal << endl;
                cout << "Binary: " << octalToBinary(input) << endl;
                cout << "Hexadecimal: " << octalToHexadecimal(input) << endl;
                cout << "1's Complement: " << onesComplement(decimal) << endl;
                cout << "2's Complement: " << twosComplement(decimal) << endl;
                cout << "Signed Binary: " << signedBinary(decimal) << endl;
                break;
            }

            case 5:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}