//===========================================================================//
// This file is part of the DIP Solver Framework.                            //
//                                                                           //
// DIP is distributed under the Eclipse Public License as part of the        //
// COIN-OR repository (http://www.coin-or.org).                              //
//                                                                           //
// Authors: Matthew Galati, SAS Institute Inc. (matthew.galati@sas.com)      //
//          Ted Ralphs, Lehigh University (ted@lehigh.edu)                   //
//          Jiadong Wang, Lehigh University (jiw508@lehigh.edu)              //
//                                                                           //
// Copyright (C) 2002-2018, Lehigh University, Matthew Galati, and Ted Ralphs//
// All Rights Reserved.                                                      //
//===========================================================================//


//===========================================================================//
#ifndef DecompSolverResult_h_
#define DecompSolverResult_h_

//===========================================================================//
/**
 * \class DecompSolverResult
 * \brief Storage of solver result.
 *
 */
//===========================================================================//

//===========================================================================//
#include "Decomp.h"
#include "DecompSolution.h"

//===========================================================================//
class DecompSolverResult {

   //----------------------------------------------------------------------//
   /**
    * @name Data.
    * @{
    */
   //----------------------------------------------------------------------//
public :
   int       m_solStatus;
   int       m_solStatus2;
   double    m_objLB;
   double    m_objUB;
   bool      m_isOptimal;
   bool      m_isUnbounded;
   bool      m_isCutoff;
   int       m_nSolutions;
   std::vector< std::vector<double> > m_solution;
   /**
    * @}
    */

public:
   const double* getSolution(const int solIndex) {
      std::vector<double>& solution = m_solution[solIndex];
      return &solution[0];
   }

   /**
    * Default constructors.
    */
   DecompSolverResult(double infinity):
      m_solStatus (-1),
      m_solStatus2(-1),
      m_objLB     (-infinity),
      m_objUB     ( infinity),
      m_isOptimal (false),
      m_isUnbounded (false),
      m_isCutoff  (false),
      m_nSolutions(0) {
   }

 DecompSolverResult(const DecompSolution* solution, double infinity):
      m_solStatus (-1),
      m_solStatus2(-1),
      m_objLB     (-infinity),
      m_objUB     ( infinity),
      m_isOptimal (false),
      m_isUnbounded (false),
      m_isCutoff  (false),
      m_nSolutions(0) {
      const double* values = solution->getValues();

      if (!values) {
         return;
      }

      m_nSolutions = 1;
      m_objUB      = solution->getQuality();
      std::vector<double> sol(values, values + solution->getSize());
      m_solution.push_back(sol);
   }

   /**
    * Destructor.
    */
   ~DecompSolverResult() {
   }
   /**
    * @}
    */
};

#endif
