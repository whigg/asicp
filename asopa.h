#pragma once
#include <Eigen/Dense>

    /*
      The solution is based on:
      Mohammed Bennani Dosse and Jos Ten Berge (2010),
      "Anisotropic Orthogonal Procrustes Analysis"
      Journal of Classification 27:111-128
    
      Ansiotropically Scaled Orthogonal Procrustes Algorithm:
      Finds 3D Transformation from X to Y. Note that this is
      algorithm finds the prescaling solution, i.e. the 
      scaling happens before the rotation. This algorithm
      also uses majorisation to solve for the rotation matrix
      not block relaxation.
      
      Inputs: 3xn Matrix - X
              3xn Matrix - Y
	      error threshold to halt iteration - threshold
      Outputs: 3x3 Rotation Matrix - R,
               3x3 Scaling Matrix  - A
	       1x3 Translation vector - t
	       Fiducial Registration Error - FRE
	       Row-wise squared FRE values - FRE_mag
    */

int asopa(Eigen::MatrixXd X, Eigen::MatrixXd Y,
	  double threshold,
	  Eigen::Matrix3d &Q, Eigen::Matrix3d &A, Eigen::RowVector3d &t,
	  double &FRE);
