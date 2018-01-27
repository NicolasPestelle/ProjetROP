#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "evalCC.hpp"
#include "HillClimberBest.hpp"



HillClimberBest::HillClimberBest(int solutionSize)
{
	fitnessMax = 1000;
	nbEval = 2; // JUSTE POUR LE TEST SUR MACHINE LENTE, A MODIFIER
	s.resize(solutionSize);
}


void HillClimberBest::randomizeSolution(Solution &sol)
{	

	srand(time(NULL));
 
	for(unsigned i = 0; i < sol.size(); i++)
	{
		int tmp = rand()%101;
		sol[i] = tmp;
	}

}

Solution HillClimberBest::getSolution()
{
	return s;
}


void HillClimberBest::run()
{
	EvalCC eval;	
	Solution sTmp; 
	sTmp.resize(s.size());
	randomizeSolution(sTmp);
	eval(sTmp);
	std::cout << sTmp.to_string() << std::endl;

	std::cout << "FITNESS ORIGINALE: " << sTmp.fitness() << std::endl;
	int bestFoundFitness = sTmp.fitness() ;
	int bestNeighborRank = -1;
	int affectedValue = -1;
	int cptIterations = 0;
	bool stop = false;


	while(!stop)
	{
		std::cout << "Eval numéro " << cptIterations << std::endl; 
		bestNeighborRank = -1;
		affectedValue = -1;
		int bestFoundFitness = sTmp.fitness();
		std::cout << "LA MEILLEUR FITNESS TROUVEE POUR LE MOMENT" << bestFoundFitness << std::endl;
		std::cout << sTmp.to_string() << std::endl;
		for(unsigned j = 0; j < sTmp.size(); j++)
		{
			std::cout << "Test du rang: " << j << std::endl; 
			sTmp.targetedNeighborSolution(j);
			eval(sTmp);
			
			if(sTmp.fitness() < bestFoundFitness)
			{
				bestFoundFitness = sTmp.fitness();
				bestNeighborRank = j;
				affectedValue = sTmp[j];
				std::cout << "TROUVE MIEUX, VOISIN NUMERO : " << j << " FITNESS TROUVEE : " << sTmp.fitness() << std::endl;
				//std::cout << sTmp.to_string() << std::endl;
			
				
			}
			sTmp.revertNeighbor();

		}
		cptIterations++;
	
		
		if(bestNeighborRank == -1) // Optimum local
		{
			std::cout << "Voisins parcours sans en trouver un mieux" << std::endl;
			stop = true; 
		}
		else
		{
			std::cout << "toto" << std::endl;
			sTmp[bestNeighborRank] = affectedValue;
			sTmp.set_fitness(bestFoundFitness);
			//std::cout << sTmp.to_string() << std::endl;
			s = sTmp;
		}
		if(cptIterations == nbEval) // Critère d'arret
		{
			std::cout << "Nombre max d'eval atteint" << std::endl;
			stop = true; 
		}
			
		

	}
		
	
}

