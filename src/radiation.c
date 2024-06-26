
//*********************************************************
//*
//* model-independent, radiation-related utilities.
//* 
//*********************************************************

// header files
#include "decs.h"
#include "radiation.h"
#include "model_radiation.h"

//*********************************************************

// what is this? seems like h/(2*nu*me*c^2*thetae)
double Bnu_inv(double nu, double Thetae)
{
  double x = HPL * nu / (ME * CL * CL * Thetae);

  if (x < 2.e-3) /* Taylor expand */
    return ((2. * HPL / (CL * CL))
        / (x / 24. * (24. + x * (12. + x * (4. + x)))));
  else
    return ((2. * HPL / (CL * CL)) / (exp(x) - 1.));
}

//*********************************************************

/* get frequency in fluid frame, in Hz */
double get_fluid_nu(double Kcon[NDIM], double Ucov[NDIM])
{
    double nu;

    /* this is the energy in electron rest-mass units */
    nu = -(Kcon[0] * Ucov[0] + Kcon[1] * Ucov[1] +
           Kcon[2] * Ucov[2] + Kcon[3] * Ucov[3])
           * ME * CL * CL / HPL;

#if DEBUG
    if (isnan(nu) || nu < 0) {
      fprintf(stderr, "isnan/isnegative get_fluid_nu!\n");
      fprintf(stderr, "K: %g %g %g %g\n", Kcon[0], Kcon[1], Kcon[2], Kcon[3]);
      fprintf(stderr, "U: %g %g %g %g\n", Ucov[0], Ucov[1], Ucov[2], Ucov[3]);
    }
#endif

    return (nu);
}

//*********************************************************

/* return angle between magnetic field and wavevector */
double get_bk_angle(double X[NDIM], double Kcon[NDIM], double Ucov[NDIM], double Bcon[NDIM], double Bcov[NDIM])
{
    double B, k, mu;

    B = sqrt(fabs(Bcon[0]*Bcov[0] + Bcon[1]*Bcov[1] + Bcon[2]*Bcov[2] + Bcon[3]*Bcov[3]));

    if (B == 0.)
    	return (M_PI / 2.);

    k = fabs(Kcon[0]*Ucov[0] + Kcon[1]*Ucov[1] + Kcon[2]*Ucov[2] + Kcon[3] * Ucov[3]);

    mu = (Kcon[0]*Bcov[0] + Kcon[1]*Bcov[1] + Kcon[2]*Bcov[2] + Kcon[3]*Bcov[3]) / (k * B);

    if (fabs(mu) > 1.)
	    mu /= fabs(mu);

#if DEBUG
    if (isnan(mu)) {
	    fprintf(stderr, "isnan get_bk_angle\n");
      fprintf(stderr, "B = %g, k = %g, mu = %g\n", B, k, mu);
      fprintf(stderr, "Ucov: %g %g %g %g\n", Ucov[0], Ucov[1], Ucov[2], Ucov[3]);
    }
#endif

    return (acos(mu));
}
