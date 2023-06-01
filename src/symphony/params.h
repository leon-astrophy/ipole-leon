//*********************************************************************
//*
//* header files for params.c
//*
//*********************************************************************

// conditional compilation
#ifndef SYMPHONY_PARAMS_H_
#define SYMPHONY_PARAMS_H_

// import math library
#include <math.h>

//*********************************************************************

// data structures
// parameters of calculation
// we use Gaussian CGS units
struct parameters
{
  // math and phys constants 
  double pi;        
  double mass_electron;
  double plancks_constant;
  double speed_light;
  double electron_charge;
  double n_max;
  int    C;     

  /*Keys for the distributions*/
  int    MAXWELL_JUETTNER;
  int    POWER_LAW;
  int    KAPPA_DIST;

  /*Keys for the polarization modes*/
  int    STOKES_I;
  int    STOKES_Q;
  int    STOKES_U;
  int    STOKES_V;

  /*Keys for the mode: absorptivity or emissivity*/
  int    ABSORPTIVITY;
  int    EMISSIVITY;

  /*Keys for alpha_nu computation method*/
  int SYMPHONY_METHOD;
  int SUSCEPT_METHOD;

  /*USER PARAMS:*/
  /* frequency in GHz */
  double nu;

  /* B-field in Gauss */               
  double magnetic_field;

  /* electron number density in 1/cc */   
  double electron_density; 

  /* observer angle in rad */  
  double observer_angle;   
  
  /* key for chossing electronic distributions */
  int    distribution;     

  /* key for polarization */
  int    polarization; 

  /*key for Emissivity or Absorptivity*/
  int    mode;     

  /*cut off value for gamma (lorentz factor?)*/        
  double gamma_cutoff;

  /* Options for fits */
  /*Use approximate Bessel functions for speed*/
  int approximate;

  /*Use jason dexter's fitting functions*/        
  int dexter_fit;

  /*Thermal distribution parameters, kt/mc^2*/
  double theta_e;

  /*power law parameters*/
  double power_law_p;
  double gamma_min;
  double gamma_max;

  /*kappa distribution parameters*/
  double kappa;
  double kappa_width;
  double kappa_interp_begin;
  double kappa_interp_end;

  /*Choose if n-space peak is known, or if it must be found adaptively */
  int use_n_peak;
  double (*n_peak)(struct parameters *);

  /*Set distribution_function */
  double (*distribution_function)(double gamma, struct parameters *);

  /*analytic_differential_of_f, which can be used as a test of the numerical differential_of_f */
  double (*analytic_differential)(double gamma, struct parameters *);

  // switch for stokes V
  int stokes_v_switch;

  /* if not NULL, records source of error in current calculation */
  char *error_message; 

  /*susceptibility tensor paramsS */
  double gamma;
  double epsilon0;
  double epsilon;
  double omega;
  double omega_c;
  double omega_p;
  double real;
  double (*tau_integrand)(double, void * parameters);
  double (*gamma_integrand)(double, void * parameters);
};

//*********************************************************************

//* parameters for GSL library
struct parametersGSL
{
  struct parameters params;
  double n;
};

//*********************************************************************

//* define functions here
void setConstParams(struct parameters *params);
double get_nu_c(struct parameters params);
double get_omega_p(struct parameters params);

#endif /* SYMPHONY_PARAMS_H_ */
