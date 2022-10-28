#include <iostream>
#include <cstdlib>
#include "colors.hpp"

int pseudoLiterals(std::string pseudo_literal) {

	std::string pseudo_literal_arr[8] = {"-inf", "inf", "+inf", "nan", "-inff", "inff", "+inff", "nanf"};
	int i = 0;

	for (i = 0; i < 8; i++) {
		if (pseudo_literal == pseudo_literal_arr[i])
			break;	
	}
	if (i < 8) {
		//~~~~~~~~~~~~~~~~ CHAR ~~~~~~~~~~~~~~~~~//
		std::cout << COLOR_BOLD_CYAN << "char :" << END << COLOR_ON_RED << COLOR_BOLD_BLACK <<  " Non displayable" << END << std::endl;

		//~~~~~~~~~~~~~~~~ INT ~~~~~~~~~~~~~~~~~//
		std::cout << COLOR_BOLD_CYAN << "int :" << END << COLOR_ON_RED << COLOR_BOLD_BLACK << "Non displayable" << END << std::endl;

		//~~~~~~~~~~~~~~~~ FLOAT ~~~~~~~~~~~~~~~~~//
		if (i < 4) {
			std::cout << COLOR_BOLD_CYAN << "float : " << END << COLOR_ON_GREEN << COLOR_BOLD_BLACK << pseudo_literal_arr[i + 4] << END << std::endl;
			std::cout << COLOR_BOLD_CYAN << "double : " << END << COLOR_ON_GREEN << COLOR_BOLD_BLACK << pseudo_literal << END << std::endl;
		}
		else {
			//~~~~~~~~~~~~~~~~ DOUBLE ~~~~~~~~~~~~~~~~~//
			std::cout << COLOR_BOLD_CYAN << "float : " << END << COLOR_ON_GREEN << COLOR_BOLD_BLACK << pseudo_literal << END << std::endl;
			std::cout << COLOR_BOLD_CYAN << "double : " << END << COLOR_ON_GREEN << COLOR_BOLD_BLACK << pseudo_literal_arr[i - 4] << END << std::endl;

		}
	return 1;
	}
	return 0;
}

void printChar(double nb) {
	//~~~~~~~~~~~~~~~~ CHAR ~~~~~~~~~~~~~~~~~//
	std::cout << COLOR_BOLD_CYAN << "char : " << END;
	if (nb < 0 || nb > 255)
		std::cout << COLOR_ON_RED << COLOR_BOLD_BLACK << " Impossible" << END << std::endl;
	else if (!isprint(nb)) {
		std::cout << COLOR_ON_RED << COLOR_BOLD_BLACK << " Non displayable" << END << std::endl;
	}
	else
		std::cout << COLOR_ON_GREEN << COLOR_BOLD_BLACK << "'" << static_cast<char>(nb) << "'" << END << std::endl;
} 

void printInt(double nb) {
	//~~~~~~~~~~~~~~~~ INT ~~~~~~~~~~~~~~~~~//
	std::cout << COLOR_BOLD_CYAN << "int : " << END;
	if (nb > INT_MAX || nb < INT_MIN) {
		std::cout << COLOR_ON_RED << COLOR_BOLD_BLACK << " Impossible" << END << std::endl;
	}
	else
		std::cout << COLOR_ON_GREEN << COLOR_BOLD_BLACK << static_cast<int>(nb) << END << std::endl;
}

void printFloat(double nb) {
	//~~~~~~~~~~~~~~~~ FLOAT ~~~~~~~~~~~~~~~~~//
	std::cout << COLOR_BOLD_CYAN << "float : " << END << COLOR_ON_GREEN << COLOR_BOLD_BLACK << static_cast<float>(nb);
	if (!fmod(nb, 1))
		std::cout << ".0";
	std::cout << "f" << END << std::endl;
}

void printDouble(double nb) {
	//~~~~~~~~~~~~~~~~ DOUBLE ~~~~~~~~~~~~~~~~~//
	std::cout << COLOR_BOLD_CYAN << "double : " << END << COLOR_ON_GREEN << COLOR_BOLD_BLACK << static_cast<double>(nb);
	if (!fmod(nb, 1))
		std::cout << ".0" << END;
	std::cout << "" << END << std::endl;
}

void castHandler(double double_value) {

	printChar(double_value);
	printInt(double_value);
	printFloat(double_value);
	printDouble(double_value);
	delimiter
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << COLOR_STRIKETHROUGH << COLOR_BOLD_RED
                  << "Invalid number of arguments! Expected input is :"
                  << std::endl;
        std::cerr << "[EXECUTABLE] [ARG1]" << END << std::endl;
        return 1;
    }
	std::cout << COLOR_BOLD_YELLOW << "*********** [CONVERSION OF SCALAR TYPES] ***********" << END << std::endl;
	delimiter
    std::string input(argv[1]);
    if (pseudoLiterals(input)) return 0;

    double double_value;
    if (input.size() > 1 || isdigit(input[0])) {
        char *end;
        double_value = strtod(argv[1], &end);
        if (*end && *end != 'f') {
            std::cout << COLOR_STRIKETHROUGH << COLOR_BOLD_RED
                      << "The input contains trailing characters! Please "
                         "provide a valid input!"
                      << END << std::endl;
            return 1;
        }
    } else
        double_value = static_cast<double>(input[0]);
    castHandler(double_value);
}
