/* Single-variable List Comprehension in C++ using Preprocessor Macros
 *
 * (C) Copyright 2011, Mauricio Faria de Oliveira
 * http://mfoliveira.org
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <iostream>
using namespace std;

#include "list_comprehension.h"

int main(int argc, char** argv) {
  
	/* Input set */
	list<int> input;
	for (int i = 0; i < 5; ++i)
		input.push_back(i);

	/* Output set */
	list<double> output;

	/* List Comprehension */
	output << list_comprehension(3.1415 * x, x, input, x < 3);

	/* Input set contents */
	for (list<int>::iterator it = input.begin();
		 it != input.end();
		 ++it)
		 cout << *it << endl;

	cout << endl;

	/* Output set contents */
	for (list<double>::iterator it = output.begin();
		 it != output.end();
		 ++it)
		 cout << *it << endl;

	return 0;
}
