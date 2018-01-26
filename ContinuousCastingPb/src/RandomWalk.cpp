#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "evalCC.hpp"
#include "RandomWalk.hpp"



RandomWalk::RandomWalk(int solutionSize)
{
	fitnessMax = 1000;
	nbEval = 100;
	s.resize(solutionSize);
}


void RandomWalk::randomizeSolution(Solution &sol)
{	

	srand(time(NULL));
 
	for(unsigned i = 0; i < sol.size(); i++)
	{
		int tmp = rand()%101;
		sol[i] = tmp;
	}

}

Solution RandomWalk::getSolution()
{
	return s;
}


void RandomWalk::run()
{
	EvalCC eval;	
	Solution sTmp; 
	sTmp.resize(s.size());
	randomizeSolution(sTmp);
	eval(sTmp);
	int bestFoundFitness = sTmp.fitness() ;
	for( int i = 0; i< nbEval; i++)
	{
		std::cout << "Eval numéro " << i << std::endl; 
		sTmp.neighborSolution();
		eval(sTmp);
		
		if(sTmp.fitness() < bestFoundFitness)
		{
			std::cout << "NOUVEAU BEST TROUVE: " << sTmp.fitness() << std::endl; 
			bestFoundFitness = sTmp.fitness();
			s = sTmp;	
		}
		
		
	}


}


