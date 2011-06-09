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

#include <iostream>
using namespace std;

#include "Fibonacci.h"

int main() {
 
  /* Print 11 Fibonacci numbers */
  Fibonacci fib;
  int terms = 11;
  
  int value;
  while ( (value = fib(terms)) >= 0 ) {
    cout << value << endl;
  }
  
  return 0;
}