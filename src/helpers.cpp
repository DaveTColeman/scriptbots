#include "include/helpers.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

// uniform random in [a,b)
float randf(float a, float b) {
  return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

// uniform random int in [a,b)
int randi(int a, int b) { return (rand() % (b - a)) + a; }

// normalvariate random N(mu, sigma)
double randn(double mu, double sigma) {
  static int deviateAvailable = 0; //	flag
  static float storedDeviate;           //	deviate from previous calculation
  double polar, rsquared, var1, var2;
  if (!deviateAvailable) {
    do {
      var1 = 2.0 * ( ((double) rand()) / ((double) (RAND_MAX))) - 1.0;
      var2 = 2.0 * ( ((double) rand()) / ((double) (RAND_MAX))) - 1.0;
      rsquared = var1 * var1 + var2 * var2;
    } while (rsquared >= 1.0 || rsquared == 0.0);
    polar = sqrt(-2.0 * log(rsquared) / rsquared);
    storedDeviate = var1 * polar;
    deviateAvailable = 1;
    return var2 * polar * sigma + mu;
  } else {
    deviateAvailable = 0;
    return storedDeviate * sigma + mu;
  }
}

// cap value between 0 and 1
float cap(float a) {
  if (a < 0)
    return 0;
  if (a > 1)
    return 1;
  return a;
}

// Get number of processors in the system
long get_nprocs() {
  return sysconf(_SC_NPROCESSORS_ONLN);
}
