#ifndef RANDOMWALK_HPP
#define RANDOMWALK_HPP

#include "LocalSearch.hpp"


class RandomWalk : public LocalSearch {
	protected:
	//	int nbEval;
	//	double bestFitness;
	//	Solution s;
	//	double fitnessMax;
	public:
		RandomWalk(int solutionSize);
		void run();
		void randomizeSolution(Solution&);
		void getNeighborSolution(Solution&);
		Solution getSolution();

		
};
#endif //RECHERCHEOP_LOCALSEARCH_H
