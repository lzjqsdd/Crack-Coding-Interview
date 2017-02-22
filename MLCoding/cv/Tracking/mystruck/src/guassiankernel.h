/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * guassiankernel.h
 * Copyright (C) 2016 lzjqsdd <lzjqsdd@lzjqsdd-Inspiron-N5110>
 *
 * mystruck is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mystruck is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GUASSIANKERNEL_H_
#define _GUASSIANKERNEL_H_
#include "Eigen/Core"
using namespace Eigen;

class GuassianKernel
{
public:
    GuassianKernel(double sigma) : m_sigma(sigma) {}
	GuassianKernel(){}
    inline double Eval(const Eigen::VectorXd& x1, const Eigen::VectorXd& x2) const
    {   
        return exp(-m_sigma*(x1-x2).squaredNorm());
    }   
    
    inline double Eval(const Eigen::VectorXd& x) const
    {   
        return 1.0;
    }
private:
   double m_sigma;

};

#endif // _GUASSIANKERNEL_H_

