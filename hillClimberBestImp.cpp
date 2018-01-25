#include "hillClimberBestImp.hpp"

void MainBestImp(const unsigned int solution_size,int nbExecutions, int nbEvalMax){
  // print the result
  //std::cout << s.to_string() << std::endl;

  EvalCC eval;
  ofstream ofsB("BestImprove.csv");
  int fit_Best;  
  int indice_fit_best;
  
  //On a pas le nb Execution

  Solution s; 
  // solution for random selection: all stacks have the same preference 1
  s.resize(solution_size);
  
  int nbEval;

  for(int j = 0; j < nbExecutions; j++){
    fit_Best = 4000;
    generateRandomSolutionBHC(s);
    nbEval = 0;
    ofsB << "---------------------------------" << endl;
    ofsB << "nombre evaluations    |    fitness" << endl;
    while (nbEval < nbEvalMax){
      int fit_current = fit_Best;
      indice_fit_best = -1;
      for(unsigned int i = 0; i < s.size(); i++){
	// Declaration of one solution of the optimization problem
	generateVoisinSolutionBHC(s, i);
	eval(s);
	nbEval++;
	fit_current = s.fitness();

	if(fit_Best > fit_current){
	  fit_Best = fit_current;
	  cout << " new fit best !!! " << fit_Best << endl;
	  indice_fit_best = i;
	}
	backToSolutionInitBHC(s, i);
	if(nbEval >= nbEvalMax){
	  break;
	}
      }
      if(indice_fit_best!=-1){
	generateVoisinSolutionBHC(s, indice_fit_best);
      }else{
	break;
      }
    }
    cout<<"Sortie!"<<endl;
    ofsB << nbEval << "  " << fit_Best << endl;
    ofsB << "----------------------------------------------------" << endl;
  } 
}

void generateVoisinSolutionBHC(Solution &s, int indice){
  s[indice] = (s[indice] + 10)%101;
}

void backToSolutionInitBHC(Solution &s, int indice){
  s[indice] = (s[indice] - 10)%101;
}


void generateRandomSolutionBHC(Solution &s){
  for(unsigned int i = 0; i < s.size(); i++){
    s[i] = rand()%101;
  }
}
