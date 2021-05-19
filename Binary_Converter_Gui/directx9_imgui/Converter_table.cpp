#include <string>
#include <iostream>
using namespace std;
#include "Converter_table.h"

//Divides inputed number by 2 and checks to see if it is an integer or not
inline bool check_int_simplify(int inp) {
	double placeholder = inp;

	placeholder = placeholder / 2;
	//If the double is an integer it will equal the converted to int double
	if (placeholder == (int)placeholder) {
		return false;
	}
	else {
		return true;
	};
}

//Adds zeros to make sure all binary strings are 8-bit
inline string eight_bitify(string inp) {
	int add_bits = 8 - inp.length();
	if (add_bits > 0) {
		for (int i = 0; i < add_bits; i++)
			inp = "0" + inp;
	};
	return inp + " ";
}

//Converts decimal to binary by dividing by 2 and using check_int_simplify
inline string decimal_to_bin(int dec) {
	string bin = "";
	while (dec != 0) {
		//If true, binary bit is 1
		if (check_int_simplify(dec) == true) {			
			bin = bin + "1";
		}
		//If false, binary bit is 0
		else {			
			bin = bin + "0";
		}
		//Divide input by 2 as that is how the converson operates
		dec = dec / 2;		
	}
	return (eight_bitify(bin));
}
//Converts binary to ASCII char
inline char bin_to_ascii(string bin) {
	//gets all 8 bits of binary string
	char positions[8] = { bin[0], bin[1], bin[2], bin[3], bin[4], bin[5], bin[6], bin[7] };
	int result = 2;
	for (int i = 0; i < 8; i++) {
		//If bit is one it converts said bit to decimal number
		if (positions[i] == '1') {
			if (8 - (i + 1) != 0) {
				//Multiplies it x times based on it's bit position
				for (int u = 1; u < (8 - (i + 1)); u++) {
					result = result * 2;
				};
			}
			//If the exponent would be 0 then it adds one
			else {
				result++;
			};
		};
	};
	//returns ascii decimal value
	return result;
};

//Gets decimal code for the ASCII character
template <typename ascii_to_decimal_>
inline int ascii_to_decimal(char inp) { return int(inp); };


namespace std {

	//Converts ASCII text to Binary by first converting it to decimal and then converting to binary
	string Convert::ASCII_TO_BIN(char input) {
		if (input == (char)"" || input == NULL) {
			return "";
		}
		else {
			return decimal_to_bin(ascii_to_decimal<char>(input)) + " ";
		};
	};
	

	char Convert::BINARY_TO_HEX(string inp) {
		static char hex_bin;
		//All hex values are easily represented by 4/8 bits of binary so its easy to make a simple table to convert all values
		if (inp == "0000") { hex_bin = '0'; }
		else if (inp == "0001") { hex_bin = '1'; }
		else if (inp == "0010") { hex_bin = '2'; }
		else if (inp == "0011") { hex_bin = '3'; }
		else if (inp == "0100") { hex_bin = '4'; }
		else if (inp == "0101") { hex_bin = '5'; }
		else if (inp == "0110") { hex_bin = '6'; }
		else if (inp == "0111") { hex_bin = '7'; }
		else if (inp == "1000") { hex_bin = '8'; }
		else if (inp == "1001") { hex_bin = '9'; }

		else if (inp == "1010") { hex_bin = 'A'; }
		else if (inp == "1011") { hex_bin = 'B'; }
		else if (inp == "1100") { hex_bin = 'C'; }
		else if (inp == "1101") { hex_bin = 'D'; }
		else if (inp == "1110") { hex_bin = 'E'; }
		else if (inp == "1111") { hex_bin = 'F'; }
		return hex_bin;		
	}


	string Convert::HEX_TO_BINARY(char inp) {
		static string bin_val;
		// All hex values are easily represented by 4 / 8 bits of binary so its easy to make a simple table to convert all values as in the Convert::BINARY_TO_HEX function
		switch (inp) {

		case '0':
			bin_val = "0000";
			break;

		case '1':
			bin_val = "0001";
			break;

		case '2':
			bin_val = "0010";
			break;

		case '3':
			bin_val = "0011";
			break;
			
		case '4':
			bin_val = "0100";
			break;

		case '5':
			bin_val = "0101";
			break;

		case '6':
			bin_val = "0110";
			break;

		case '7':
			bin_val = "0111";
			break;

		case '8':
			bin_val = "1000";
			break;

		case '9':
			bin_val = "1001";
			break;

		case 'A':
			bin_val = "1010";
			break;

		case 'B':
			bin_val = "1011";
			break;

		case 'C':
			bin_val = "1100";
			break;

		case 'D':
			bin_val = "1101";
			break;

		case 'E':
			bin_val = "1110";
			break;

		case 'F':
			bin_val = "1111";
			break;

		case ' ':
			bin_val = "";
			break;

		default:
			break;
		}		
		return bin_val;
	}

	char Convert::BIN_TO_ASCII(string inp) {
		return bin_to_ascii(inp);
	}
}