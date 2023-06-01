//**************************************************************************
//*
//* header file for bremss_fits.c
//*
//**************************************************************************

// conditional compilation
#ifndef SYMPHONY_BREMSS_FITS_H_
#define SYMPHONY_BREMSS_FITS_H_

// include headers
#include "params.h"

// gsl library
#include <gsl/gsl_sf_bessel.h>

//**************************************************************************
//* define function 
//**************************************************************************

// Initialize necessary cached values
void init_bremss_spline();

/* Emissivities */
double bremss_I(struct parameters * params, int bremss_type);

/* Absorptivities */
double bremss_I_abs(struct parameters * params, int bremss_type);

#endif /* SYMPHONY_MAXWELL_JUETTNER_H_ */
