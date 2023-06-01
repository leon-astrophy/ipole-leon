//*************************************************
//*
//* iharm simulation parameters, used in model.c
//*
//*************************************************

//conditional compilation
#ifndef MODEL_PARAMS_H
#define MODEL_PARAMS_H

// slow light approximation
#define SLOW_LIGHT (0)

// keys for GRMHD fluid primitive variables, see iharm for details
#define KRHO 0
#define UU   1
#define U1   2
#define U2   3
#define U3   4
#define B1   5
#define B2   6
#define B3   7
#define KEL  8
#define KTOT 9

//****************************************************
//* These two will never be used simultaneously,
//* and never with KEL.
//****************************************************

// temperature of fluid in Kelvin
#define TFLK 8 

// fluid temperature in me c^2
#define THF  8 

// dumps file output intervals
extern double DTd;

// cutoff value of sigma (lorentz factor)
extern double sigma_cut;

#endif // MODEL_PARAMS_H
