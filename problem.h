#ifndef PROBLEM_H_INCLUDED
#define PROBLEM_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

  class Problem
  {
	public:
		Problem();
		~Problem();

		int dimension() const;

	private:

		int _dimension;
		double LowerBound, UpperBound;
  };


#endif // PROBLEM_H_INCLUDED
