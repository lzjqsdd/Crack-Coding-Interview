/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * larank.h
 * Copyright (C) 2016 lzjqsdd <lzjqsdd@163.com>
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

#ifndef _LARANK_H_
#define _LARANK_H_
#include "guassiankernel.h"
#include "config.h"
#include "floatrect.h"
#include "haarfeatures.h"
#include <iostream>
#include <Eigen/Core>
#include "cv.h"

using namespace Eigen;
using namespace std;

class LaRank
{
public:

protected:

private:
	struct SupportPattern
	{
		vector<Eigen::VectorXd> x; //表示特征向量集合
		vector<FloatRect> yv; //表示变换的集合，一一对应
		vector<IplImage *>images;
		int y;
		int refCount;
	};

	struct SupportVector
	{
		SupportPattern *x;
		int y;
		double b; //beta
		double g; //gradient
		IplImage * img;
	};

	double m_C; //表示KKT中的C
	
	Eigen::MatrixXd m_K;
	
	inline double Loss(FloatRect& y1,FloatRect& y2)
	{
		return 1.0 - y1.Overlap(y2);
	}

	void SMOStep(int ipos,int ineg);
	pair<int,double> MinGradient(int ind);
	void ProcessNew(int ind); //选择当前帧的正样本加入支持向量.
	void Reprocess();
	void ProcessOld(); //从以往的支持向量中随机选择作为正样本
	void Optimize();

	void AddSupportVector(SupportPattern *x,int y,double g);
	void RemoveSupportVector(int ind);
	void RemoveSupportVectors(int ind1,int ind2);
	void SwapSupportVectors(int ind1,int ind2);

	void BudgetMaintenance();
	void BudgetMaintenanceRemove();

	double Evaluate(Eigen::VectorXd& x,FloatRect& y);
};

#endif // _LARANK_H_

