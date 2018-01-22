//
// Created by cspecq1 on 15/01/18.
//

#include "RandomSearch.hpp"


RandomSearch::RandomSearch(){
  nbEval = 10;
  fitnessMax = 255;
}

void RandomSearch::randomSolution(Solution s)
{
  srand(time(NULL));
  for(unsigned i =0; i< s.size();i++){
    int r = rand()%101;
    s[i] = r;
  }
  
}

Solution RandomSearch::run(Solution s) {

  randomSolution(s);
  
  EvalCC eval; 
  Solution sBest;
  Solution sprime = s ;

  for(int i =0; i<nbEval; i++){
   randomSolution(sprime);
    eval(sprime);
    if(sprime > sBest)
      {
	sBest = sprime;
      }
  }

  return sBest;    
}
