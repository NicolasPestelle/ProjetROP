#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "IteratedLocalSearch.hpp"



IteratedLocalSearch::IteratedLocalSearch(int solutionSize)
{
	fitnessMax = 1000;
	nbEval = 2; // JUSTE POUR LE TEST SUR MACHINE LENTE, A MODIFIER
	s.resize(solutionSize);
}


void IteratedLocalSearch::randomizeSolution(Solution &sol)
{	

	srand(time(NULL));
 
	for(unsigned i = 0; i < sol.size(); i++)
	{
		int tmp = rand()%101;
		sol[i] = tmp;
	}

}

Solution IteratedLocalSearch::getSolution()
{
	return s;
}


void IteratedLocalSearch::run()
{	
	Solution sTmp; 
	sTmp.resize(s.size());
	randomizeSolution(sTmp);
	HillClimberFirst hcf(sTmp);
	hcf.run();
	s = hcf.getSolution();
	std::cout << "SOlution initiale:" << std::endl;
	std::cout << s.to_string() << std::endl;

	std::cout << "ENTREE DANS LE FOR, SOLUCE RANDOM" << std::endl;
	for(int i = 0; i< nbEval; i++)
	{
		//randomizeSolution(sTmp);
		HillClimberFirst hcf(s.size());
		hcf.run();
		
		if(hcf.getSolution().fitness() < s.fitness())
		{
			s = hcf.getSolution();
			std::cout << "Nouvelle solution:" << std::endl;
			std::cout << s.to_string() << std::endl;
		}
	}
			
	
}

