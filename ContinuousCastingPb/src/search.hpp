//
// Created by cspecq1 on 15/01/18.
//

#ifndef SEARCH_HPP
#define SEARCH_HPP

#include "solution.hpp"

class search{
private:
    double bestSolution;
public:
    virtual Solution run(Solution s) = 0;
};


#endif //CC_SIMULATOR_SEARCH_HPP
