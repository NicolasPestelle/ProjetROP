#ifndef HILLCLIMBERBEST_HPP
#define HILLCLIMBERBEST_HPP

#include "LocalSearch.hpp"


class HillClimberBest : public LocalSearch {
	protected:

	public:
		HillClimberBest(int solutionSize);
		void run();
		void randomizeSolution(Solution&);
		Solution getSolution();

		
};
#endif //HILLCLIMBERBEST_HPP
