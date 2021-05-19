#pragma once
#include <string>
using namespace std;
namespace std {

	class Convert {

	public:
		//Converts ASCII text to Binary
		static string ASCII_TO_BIN(char input);
		//Converts Binary to ASCII text
		static char BIN_TO_ASCII(string inp);		
		//Converts Hexadecimal to Binary
		static string HEX_TO_BINARY(char inp);
		//Converts Binary to Hexadecimal
		static char BINARY_TO_HEX(string inp);
	};
}