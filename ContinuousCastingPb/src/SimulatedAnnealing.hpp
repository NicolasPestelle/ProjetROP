#ifndef SIMULATEDANNEALING_HPP
#define SIMULATEDANNEALING_HPP

#include "LocalSearch.hpp"
#include "HillClimberFirst.hpp"


class SimulatedAnnealing : public LocalSearch {
	protected:
		float T;

	public:
		SimulatedAnnealing(int solutionSize);
		void run();
		void randomizeSolution(Solution&);
		Solution getSolution();

		
};
#endif //HILLCLIMBERBEST_HPP
