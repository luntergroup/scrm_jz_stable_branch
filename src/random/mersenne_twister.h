/*
 * scrm is an implementation of the Sequential-Coalescent-with-Recombination Model.
 * 
 * Copyright (C) 2013 Paul R. Staab, Sha (Joe) Zhu and Gerton Lunter
 * 
 * This file is part of scrm.
 * 
 * scrm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef scrm_src_random_mersenne_twister
#define scrm_src_random_mersenne_twister

#include <vector>
#include <ctime> 
#include <boost/random.hpp>

#include "random_generator.h"

class MersenneTwister : public RandomGenerator
{
  public:
   MersenneTwister();
   MersenneTwister(int seed);
   virtual ~MersenneTwister();
                         
   void initialize() {};
   double sample();
   void set_seed(const int &seed);

  protected:
   typedef boost::mt19937 rng_type;
   boost::uniform_01<double> unif;
   rng_type rng;
};

#endif
