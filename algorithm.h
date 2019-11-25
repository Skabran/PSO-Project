#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

  class Algorithm
  {
	private:
		vector<Solution*> _population;     // individuals in population
		vector<double> _fitness_values_of_current_population;
		const SetUpParams& _setup;
		Solution* _global_best_solution;

	public:
		Algorithm(const Problem& pbm,const SetUpParams& setup);
		~Algorithm();

		const SetUpParams& setup() const;
	  	void initialize();

		// evaluate the current population
        void evaluate();

	 	const vector<Solution*>& current_solutions() const;

		unsigned double global_best_cost() const;

		Solution& solution(const unsigned int index) const;

		Solution& global_best_solution() const;

		// main loop of the algorithm
		void evolution();

  };

#endif // ALGORITHM_H_INCLUDED
