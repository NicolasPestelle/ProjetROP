#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "evalCC.hpp"
#include "HillClimberFirst.hpp"



HillClimberFirst::HillClimberFirst(int solutionSize)
{
	fitnessMax = 1000;
	nbEval = 500; // JUSTE POUR LE TEST SUR MACHINE LENTE, A MODIFIER
	s.resize(solutionSize);
}

HillClimberFirst::HillClimberFirst(Solution sol)
{
	s.resize(sol.size());
	fitnessMax = 1000;
	nbEval = 2; // JUSTE POUR LE TEST SUR MACHINE LENTE, A MODIFIER
	s = sol;
}


void HillClimberFirst::randomizeSolution(Solution &sol)
{	

	srand(time(NULL));
 
	for(unsigned i = 0; i < sol.size(); i++)
	{
		int tmp = rand()%101;
		sol[i] = tmp;
	}

}

Solution HillClimberFirst::getSolution()
{
	return s;
}

void HillClimberFirst::set_solution(Solution sol)
{
	s = sol;
}


void HillClimberFirst::run()
{
	EvalCC eval;	
	Solution sTmp; 
	sTmp.resize(s.size());
	randomizeSolution(sTmp);
	eval(sTmp);
	std::cout << sTmp.to_string() << std::endl;

	std::cout << "FITNESS ORIGINALE: " << sTmp.fitness() << std::endl;
	int bestFoundFitness = sTmp.fitness() ;
	int cptIterations = 0;
	bool stop = false;
	bool foundBest = false;

	while(!stop)
	{
		std::cout << "Eval numéro " << cptIterations << std::endl; 
		foundBest = false;
		for(unsigned j = 0; j < sTmp.size(); j++)
		{
			sTmp.targetedNeighborSolution(j);
			eval(sTmp);
			/*std::cout << "MATRICE VOISINE:" << std::endl;
			std::cout << sTmp.to_string() << std::endl;
			std::cout << "Old rank:" << sTmp.get_oldRank() << std::endl;
			std::cout << "Old value" << sTmp.get_oldValue() << std::endl;*/
			if(sTmp.fitness() < bestFoundFitness)
			{
				bestFoundFitness = sTmp.fitness();
				std::cout << "TROUVE MIEUX, VOISIN NUMERO : " << j << std::endl;
				std::cout << "FITNESS TROUVEE : " << sTmp.fitness() << std::endl;
				foundBest = true;
				break;
			}
			else 
			{
				std::cout << "PAS BON, RANG : " << j << std::endl;
				std::cout << "FITNESS TROUVEE : " << sTmp.fitness() << std::endl;
				sTmp.revertNeighbor();
			}

		}
		cptIterations++;
	
		if(foundBest == false)
		{
			std::cout << "Voisins parcours sans en trouver un mieux" << std::endl;
			stop = true; 
		}
		if(cptIterations == nbEval)
		{
			std::cout << "Nombre max d'eval atteint" << std::endl;
			stop = true; 
		}


	}
		
	s = sTmp;		

}

