#include <arrayadapt/arrayadapt.hpp>
#include <arrayadapt/types.hpp>

extern "C"
void mexFunction(int,
                 mxArray*[],
                 int,
                 const mxArray*[]) __attribute__((visibility("default")));

namespace param {
namespace in {
enum {
  in_mat = 0
};
enum {
  num_mand = 1,
  num_max = 1
};
}
namespace out {
enum {
  output = 0
};
}
}

using namespace arrayadapt;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
  if (nrhs < param::in::num_mand) {
    mexErrMsgTxt("Usage: output = example-2d(A)\n");
    return;
  }

  if (mxGetM(prhs[param::in::in_mat]) < 2 ||
      mxGetN(prhs[param::in::in_mat]) < 2) {
    mexErrMsgTxt("'A' must be a double matrix without singleton dimensions.");
    return;
  }

  // "const_double_matrix" is typedef'ed to "ArrayAdapter<const double, 2>"
  const_double_matrix A = ArrayAdapter<const double, 2>::wrap<ptr_access::real>(
      prhs[param::in::in_mat],
      mxGetM(prhs[param::in::in_mat]),
      mxGetN(prhs[param::in::in_mat]));

  const size_t M = A.getRows();  // matrices know getRows() and getCols()
  const size_t N = A.getCols();

  /* output parameters begin */
  plhs[param::out::output] =
      mxCreateNumericMatrix(M, N, mx_traits<double>::classId, mxREAL);
  double_matrix output =
      double_matrix::wrap<ptr_access::real>(plhs[param::out::output], M, N);
  /* output parameters end */

  for (size_t i = 0; i < M; ++i) {
    for (size_t j = 0; j < N; ++j) {
      output(i,j) = 2 * A(i,j);
    }
  }
}
