#ifndef LOCALSEARCH_HPP
#define LOCALSEARCH_HPP

#include "solution.hpp"

class LocalSearch {
	protected:
		int nbEval;
		double bestFitness;
		Solution s;
		double fitnessMax;
	public:
		virtual void run() = 0;
};
#endif //RECHERCHEOP_LOCALSEARCH_H
