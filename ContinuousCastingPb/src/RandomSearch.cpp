#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <evalCC.hpp>
#include <RandomSearch.hpp>
#include <time.h>



RandomSearch::RandomSearch(int solutionSize)
{
	fitnessMax = 1000;
	nbEval = 100;
	s.resize(solutionSize);
}

Solution RandomSearch::getSolution()
{
	return s;
}

void RandomSearch::run()
{
	EvalCC eval;
	int bestFoundFitness = 10000;
	Solution sTmp; 
	sTmp.resize(s.size());
	std::cout << sTmp.to_string() << std::endl;

	for( int i = 0; i< nbEval; i++)
	{
		std::cout << "Eval numéro " << i << std::endl; 
		randomizeSolution(sTmp);
		eval(sTmp);
		if(sTmp.fitness() < bestFoundFitness)
		{
			std::cout << "NOUVEAU BEST TROUVE: " << sTmp.fitness() << std::endl; 
			s = sTmp;
			bestFoundFitness = sTmp.fitness();
		}
		
	}
	
}

void RandomSearch::randomizeSolution(Solution &sol)
{
  srand(time(NULL));
 
  for(unsigned i = 0; i < sol.size(); i++)
    {
      int tmp = rand()%101;
      sol[i] = tmp;
    }
}

