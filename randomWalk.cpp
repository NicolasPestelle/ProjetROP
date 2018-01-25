#include "randomWalk.hpp"

void MainRandomWalk(const unsigned int solution_size,int nbExecutions, int nbEval){
  // print the result
  //std::cout << s.to_string() << std::endl;

  EvalCC eval;
  
  ofstream ofsB("RandomWalk.csv");

  int Best = 4000;
  int fit_current;
  for(int j = 0; j < nbExecutions; j++){
    ofsB << "---------------------------------" << endl;
    ofsB << "nombre evaluations    |    fitness" << endl;

    Best = 4000;
    Solution s ; 
    // solution for random selection: all stacks have the same preference 1
    s.resize(solution_size);
    generateRandomSolutionW(s);
    int indiceVoisin;
    for(int i = 0; i < nbEval; i++){
      // Declaration of one solution of the optimization problem
      indiceVoisin = generateVoisinSolution(s);
      eval(s);
      fit_current = s.fitness();
      cout << "Valeur voisin  : " << fit_current << endl;
      if(Best > fit_current){
	Best = fit_current;
	cout << "Trouvé meilleur ! : " << Best << endl;
      }
      backToSolutionInit(s, indiceVoisin);
    }
    ofsB << nbEval << "  " << Best << endl;
    
    ofsB << "----------------------------------------------------" << endl;
  }
}


int generateVoisinSolution(Solution &s){
  int indiceAlea =rand()%s.size();
  s[indiceAlea] = (s[indiceAlea] + 10)%101;
  return indiceAlea;
}

void backToSolutionInit(Solution &s, int indice){
  s[indice] = (s[indice] - 10)%101;
}


void generateRandomSolutionW(Solution &s){
  for(unsigned int i = 0; i < s.size(); i++){
    s[i] = rand()%101;
  }
}
