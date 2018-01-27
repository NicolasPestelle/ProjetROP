#ifndef HILLCLIMBERFIRST_HPP
#define HILLCLIMBERFIRST_HPP

#include "LocalSearch.hpp"


class HillClimberFirst : public LocalSearch {
	protected:

	public:
		HillClimberFirst(int solutionSize);
		HillClimberFirst(Solution sol);
		void run();
		void randomizeSolution(Solution&);
		Solution getSolution();

		
};
#endif //HILLCLIMBERFIRST_H
