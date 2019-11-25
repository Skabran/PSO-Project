#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
class Solution
  {

  	private:
        vector<double> _solution;
        double _fitness_current;
		const Problem& _pbm;

	public:
		Solution (const Problem& pbm);
		Solution (const Solution& sol);
		~Solution();

		const Problem& pbm() const;

		void initialize();
		double fitness();
		double get_fitness();

		vector<double>& get_solution();

		double& get_position_in_solution(const int index);
        void  set_position_in_solution(const int index, const double value);

  };

#endif // SOLUTION_H_INCLUDED
