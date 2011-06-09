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

#ifndef MFOLIVEIRA_LISTCOMPREHENSION_H
#define MFOLIVEIRA_LISTCOMPREHENSION_H

#include <list>

/* Pointer to Output Set */
typedef void list_comprehension_set;
list_comprehension_set *list_comprehension_output_set;

/* List-Comprehension Assignment Operator */
template <typename T>
void operator << (std::list<T> &output_set, list_comprehension_set* &output_set_pointer) {
  
  /* Store output_set's address for the macro. */
  output_set_pointer = (list_comprehension_set *) &output_set;
}

/* List Comprehension */
#define list_comprehension(output_function, variable, input_set, predicate)			\
												\
list_comprehension_output_set;									\
												\
{												\
	typeof((input_set).begin()) iterator = (input_set).begin();				\
	typeof((input_set).front()) variable = *iterator;					\
												\
	std::list< typeof(output_function) > *output_set = 					\
		(std::list< typeof(output_function) > *) list_comprehension_output_set;		\
												\
	for (;								 			\
		 iterator != (input_set).end();	 						\
	   ++iterator)										\
	{											\
		variable = *iterator;								\
												\
		if (predicate)									\
			output_set->push_back(output_function);					\
	}											\
}

#endif // MFOLIVEIRA_LISTCOMPREHENSION_H