#include "physics.h"


double modelAStep(double phi_curr,
		  double phi_prec,
		  double phi_secc,
		  double phi_up,
		  double phi_down,
		  double delta_t,
		  double delta_x)
{
  return phi_curr + delta_t / (delta_x * delta_x) * laplace(phi_curr, phi_prec, phi_secc, phi_up, phi_down);
}

double laplace(double phi_curr,
	       double phi_prec,
	       double phi_secc,
	       double phi_up,
	       double phi_down)
{
  return phi_secc + phi_prec + phi_up + phi_down - 4 * phi_curr;
}
