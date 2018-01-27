#ifndef ITERATEDLOCALSEARCH_HPP
#define ITERATEDLOCALSEARCH_HPP

#include "LocalSearch.hpp"
#include "HillClimberFirst.hpp"


class IteratedLocalSearch : public LocalSearch {
	protected:

	public:
		IteratedLocalSearch(int solutionSize);
		void run();
		void randomizeSolution(Solution&);
		Solution getSolution();

		
};
#endif //HILLCLIMBERBEST_HPP
