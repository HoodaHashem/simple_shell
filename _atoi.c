#include "main.h"

	int check_mode(str_r *p) {
	return (isatty(STDIN_FILENO) && p->str_input <= 2);
}



	int _atoi(char *conv_str) {

	int count, buffer = 1, is_count = 0, x;
	unsigned int output = 0;

	for (count = 0; conv_str[count] != '\0' &&
			is_count != 2; count++) {

	if (conv_str[count] == '-')
	buffer *= -1;


	if (conv_str[count] >= '0' && conv_str[count] <= '9') {
	is_count = 1;
	output *= 10;
	output += (conv_str[count] - '0');
		}	

		else if (is_count == 1)
		is_count = 2;
		}	

		if (buffer == -1)
		x = -output;
		else
		x = output;


	return (x);

}
