/* On-Demand Random Number Generation
 *
 * (C) Copyright 2010, Mauricio Faria de Oliveira
 * http://mfoliveira.org
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <iostream>
using namespace std;

/* On-Demand Random Number Generator */
#include "Random.h"

int main() {

	/* Randomize seed */
	Random::randomize();
	
	/* Number range: 91 <= value < 123 */
	Random random('a', 'z' + 1);

	/* Numbers */
	int number;

	for (int i = 0; i < 3; ++i) {
		number = random;
		cout << number << endl;
	}

	/* Characters */
	char character;

	for (int i = 0; i < 3; ++i) {
		character = random;
		cout << character << endl;
	}

	/* Direct output needs explicit casting */
	for (int i = 0; i < 3; ++i)
		cout << (int) random << endl;

for (int i = 0; i < 10; ++i) // 10 random chars.
	cout << (char) random;
	/* Done. */
	return 0;
}