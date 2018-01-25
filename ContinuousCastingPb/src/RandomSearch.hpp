#ifndef RANDOMSEARCH_HPP
#define RANDOMSEARCH_HPP

#include "LocalSearch.hpp"


class RandomSearch : public LocalSearch {
	protected:
	//	int nbEval;
	//	double bestFitness;
	//	Solution s;
	//	double fitnessMax;
	public:
		RandomSearch(int solutionSize);
		void run();
		void randomizeSolution(Solution&);
		Solution getSolution();

		
};
#endif //RECHERCHEOP_LOCALSEARCH_H
