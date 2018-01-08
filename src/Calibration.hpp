#include "cpp/src/interpolation.h"
#include "cpp/src/statistics.h"
#include <cstdio>
#include <vector>

using namespace std;
class Calibration{
public:
  vector<double> index_1;
  vector<double> index_2;
  vector<double> index_3;
  
  double corr(vector<double> index_1, vector<double> index_2);
  double volatility(vector<double> index);
};
    
