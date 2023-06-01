//*******************************************************************************
//*
//* header files for maxwell_juettner_fits.c
//*
//*******************************************************************************

// conditional compilation
#ifndef SYMPHONY_MAXWELL_JUETTNER_H_
#define SYMPHONY_MAXWELL_JUETTNER_H_

//header files
#include "params.h"
///////////////////////////////////////////////////////
//#include "distribution_function_common_routines.h"
///////////////////////////////////////////////////////

// standard gsl library
#include <gsl/gsl_sf_bessel.h>

//***********************************************************
//* define functions here
//***********************************************************

// maxwell juettner related
double maxwell_juettner_f(double gamma, struct parameters * params);
double differential_of_maxwell_juettner(double gamma, struct parameters * params);
double maxwell_juettner_n_peak(struct parameters * params);

/* Emissivities */
double maxwell_juettner_I(struct parameters * params);
double maxwell_juettner_Q(struct parameters * params);
double maxwell_juettner_V(struct parameters * params);

// planck function
double planck_func(struct parameters * params);

/* Absorptivities */
double maxwell_juettner_I_abs(struct parameters * params);
double maxwell_juettner_Q_abs(struct parameters * params);
double maxwell_juettner_V_abs(struct parameters * params);

/* Faraday rotation/conversion coefficients */
double maxwell_juettner_rho_Q(struct parameters * params);
double maxwell_juettner_rho_V(struct parameters * params);

#endif /* SYMPHONY_MAXWELL_JUETTNER_H_ */
