/* Yield in C/C++ with GNU C Extensions
 *
 * (C) Copyright 2011, Mauricio Faria de Oliveira
 * http://mfoliveira.org
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include "yield.h"

class Fibonacci {

protected:
  
  /* Yield's internal */
  void *YIELD_POINTER;
  
  /* Fibonacci terms */
  int fib_x, fib_y;
  int term;

public:
  
  /* Constructor */
  Fibonacci() {
    YIELD_POINTER = NULL;
  }
  
  /* Function Object */
  int operator () (int stop_term) {
    
    yield_start();
    
    /* Seed values */
    fib_x = 0;
    fib_y = 1;
    
    /* Calculate Fibonacci Numbers */
    for (term = 0; term < stop_term; term++) {
      
      /* Fib(0) */
      if (term == 0) 
	yield(0);

      /* Fib(1) */
      else if (term == 1)
	yield(1);

      /* Fib(n) */
      else {

	/* Current term */
	int fib_n = fib_x + fib_y;

	/* Update previous terms */
	fib_x = fib_y; 
	fib_y = fib_n;

	yield(fib_n);
      }
    }

    /* Finished. */
    yield_end();
    return -1;
  }
  
};