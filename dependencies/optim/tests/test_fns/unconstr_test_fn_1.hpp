/*################################################################################
  ##
  ##   Copyright (C) 2016-2018 Keith O'Hara
  ##
  ##   This file is part of the OptimLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

//
// this example is from Matlab's help page
// https://www.mathworks.com/help/optim/ug/fminunc.html
//
// f(x) = 3*x_1^2 + 2*x_1*x_2 + x_2^2 − 4*x_1 + 5*x_2
// 
// solution is: (2.25,-4.75)
//

#ifndef _optim_test_fn_1_HPP
#define _optim_test_fn_1_HPP

double unconstr_test_fn_1(const arma::vec& vals_inp, arma::vec* grad_out, void* opt_data);

double
unconstr_test_fn_1(const arma::vec& vals_inp, arma::vec* grad_out, void* opt_data)
{
    double x_1 = vals_inp(0);
    double x_2 = vals_inp(1);

    double obj_val = 3*std::pow(x_1,2) + 2*x_1*x_2 + std::pow(x_2,2) - 4*x_1 + 5*x_2;

    if (grad_out) {
        (*grad_out)(0) = 6*x_1 + 2*x_2 - 4;
        (*grad_out)(1) = 2*x_1 + 2*x_2 + 5;
    }
    //
    return obj_val;
}

#endif
