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

#ifndef MFOLIVEIRA_RANDOM_H
#define MFOLIVEIRA_RANDOM_H

#include <cstdlib>
#include <ctime>

class Random {

protected:

	/* Base Value:
	 * all random numbers >= base */
	int base;

	/* Limit Value:
	 * all random numbers < limit */
	int limit;

public:

	/* Constructor */
	Random(int base = 0, int limit = 0) {

		/* Initialization */
		this->base  = base;
		this->limit = limit;
	}

	/* Seed Randomizer */
	static void randomize() {

		/* Initialize seed based on current time */
		srand(std::time(0));
	}

	/* Cast Operator overload */
	template <typename T>
	operator T() {

		/* Arbitrarily casting to type T.
		 * This returns 1 <= sizeof(T) <= sizeof(int) random bytes. ;-) */
		if (0 == limit)
			return static_cast<T>
				(base + std::rand());

		else
			return static_cast<T>
				(base + std::rand() % (limit - base));
	}

};

#endif // MFOLIVEIRA_RANDOM_H