#ifndef RANDOMWALK_HPP
#define RANDOMWALK_HPP

#include "LocalSearch.hpp"


class RandomWalk : public LocalSearch {
	protected:

	public:
		RandomWalk(int solutionSize);
		void run();
		void randomizeSolution(Solution&);
		void getNeighborSolution(Solution&);
		Solution getSolution();

		
};
#endif //RECHERCHEOP_LOCALSEARCH_H
