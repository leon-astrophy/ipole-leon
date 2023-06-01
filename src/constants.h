//*********************************************************************
//*
//* == Definition of constants in CGS units == 
//*
//*********************************************************************

//*********************************************************************
//* Fundamental constants
//*********************************************************************

/* electron charge */
#define EE (4.80320680e-10)

/* speed of light */
#define CL (2.99792458e10) 

/* electron mass */
#define ME (9.1093826e-28) 

/* proton mass */
#define MP (1.67262171e-24) 

/* neutron mass */
#define MN (1.67492728e-24) 

/* atomic mass unit */
#define AMU (1.66053886e-24)

/* Planck constant */
#define HPL (6.6260693e-27) 

/* hpl/m_ec^2*/
#define HPL_MECL2 (8.09e-21) 

 /* Planck's consant / 2pi */
#define HBAR (HPL/(2.*M_PI))

/* Boltzmann constant */
#define KBOL (1.3806505e-16)

/* Gravitational constant */
#define GNEWT (6.6742e-8) 

/* Stefan-Boltzmann constant */
#define SIG (5.670400e-5) 

/* erg K^-1 mole^-1: ideal gas const */
#define RGAS (8.3143e7)

/* electron volt in erg */
#define EV (1.60217653e-12) 

/* classical electron radius */
#define RE (EE*EE/ME/CL/CL) 

 /* Thomson cross section in cm^2 */
#define SIGMA_THOMSON (0.665245873e-24)

 /* Jansky (flux/freq. unit) in cgs */
#define JY (1.e-23)

/* Micro-arcseconds in 1 radian */
#define MUAS_PER_RAD (2.06265e11) 

/* (fine-structure constant)^-1 */
#define ALPHAF (7.29735e-3) 

/*kiloelectronovolt*/
#define KEV (1.602e-9) 

//*********************************************************************
//* Astrophysical constants
//*********************************************************************

/* parsec */
#define PC (3.085678e18) 

/* Astronomical Unit */
#define AU (1.49597870691e13) 

/* No. of seconds in year */
#define YEAR (31536000.) 

/* No. of seconds in day */
#define DAY (86400.) /*Day Day >3<*/

/* No. of seconds in hour */
#define HOUR (3600.) 

/* solar mass */
#define MSUN (1.989e33) 

/* Radius of Sun */
#define RSUN (6.96e10)

/* Luminousity of Sun */
#define LSUN (3.827e33)

/* Temperature of Sun's photosphere */
#define TSUN (5.78e3) 

/* Earth's mass */
#define MEARTH (5.976e27) 

/* Earth's radius */
#define REARTH (6.378e8) 

/////////////////////////////////
//#define DSGRA_PC (8.27e3)
/////////////////////////////////

/* Distance from Earth to Sgr A* */
#define DSGRA_PC (8.127e3) 

/* Distance from Earth to M87 */
#define DM87_PC (16.9e6)

/* Distance from Earth to M87 gaseous */
#define DM87_GAS_PC (17.9e6)

//#define DSGRA (8.27e3 * PC )

/* Distance from Earth to Sgr A* (cm) */
#define DSGRA (DSGRA_PC * PC) 

/* Distance from Earth to M87 (cm) */
#define DM87 (DM87_PC * PC) 

 /* From Walsh+ 2013 (cm) */
#define DM87_gas (DM87_GAS_PC * PC)

/* Distance from Earth to A0620-00 (cm) */
#define DABHB (1.2e3 * PC) 

/* CBR temperature, from COBE */
#define TCBR (2.726) 


//*********************************************************************
//* solar abundances, from M & B, p. 99
//*********************************************************************

/* H */
#define SOLX (0.70) 

/* He */
#define SOLY (0.28) 

/* Metals */
#define SOLZ (0.02) 

/* Small numbers */
#define SMALL 1.e-40
