//********************************
//*
//* Header file for the par.c 
//*
//********************************

//conditional compilation
#ifndef PAR_H
#define PAR_H

//include header files
#include "decs.h"

//***************************************************************************************************8

//define data type
#define TYPE_INT (1)
#define TYPE_DBL (2)
#define TYPE_STR (3)

// data, structure, feel free to change any part of this
typedef struct params_t {

  // my patch, only output luminosity? //
  int only_lum;

  // Camera radius in r_g
  double rcam;        

  // Camera position, in degrees from the pole  
  double thetacam;      

  // Camera position, in degrees along the phi directions
  double phicam;        

  // Rotating camera, in degrees, so that jets is along different axis
  double rotcam;        

  // field of view (FOV) in-plane in r_g (or do you mean the grid size?)
  double dx, dy;        

  // FOV (from Earth) in muas
  double fovx_dsource, fovy_dsource; 

  // image dimensions in px
  int nx, ny;           

  // source distance in pc
  double dsource;       

  // observing frequency in cgs
  double freqcgs;      

  // 0 uses k_phi=0 "ZAMO" new centering, 1 uses k^phi=0 old centering 
  int old_centering;   

  // Geodesic accuracy
  double eps;

  // maixmum integration step
  int maxnstep;

  // Whether to additionally make a ppm image of I
  int add_ppm;          

  // Convention for Stokes Q,U.  0 (default) -> East of North (observer).  1 -> North of West
  int qu_conv;          

  // Quench output, i.e. "quench" argument
  int quench_output;    

  // Unpolarized transport only
  int only_unpolarized;

  // Output check & recheck images 
  int perform_check;   

  // Which electron energy distributions/emissivities to use
  int emission_type;

  // Whether to apply I > 0 "floor" when integrating forward the Stokes parameters,  Probably harmless!
  int stokes_floors;

  // what is this ??
  int isolate_counterjet;

  const char dump[STRLEN];
  const char outf[STRLEN];

  // Subrings
  int target_nturns;

  // Adaptive tracing
  int nx_min, ny_min;   // dimensions of lowest resolution image
  double refine_abs, refine_rel; // Refinement tolerances
  double refine_cut;    // minimum intensity at which to bother refining
  int nearest_neighbor; // use nearest-neighbor instead of matching-order interpolation

  // ML parameters
  double xoff, yoff;    // in pixels

  // slow light
  double img_cadence;
  double restart_int;

  // Save out variables along a geodesic
  int trace;
  int trace_stride;
  int trace_i, trace_j;
  const char trace_outf[STRLEN];

  // Histogram observer-visible emission from each zone
  int histo, histo_polar;
  const char histo_outf[STRLEN];

} Params;

//***************************************************************************************************

//****************************************
//* function definition
//****************************************

// modify this to set default values
void load_par_from_argv(int, char *[], Params *);

// modify this to actually add the reading subroutines
void try_set_parameter(const char *, const char *, Params *);

// only modify if you add/modify types
void load_par(const char *, Params *);
void set_by_word_val(const char *word, const char *value, const char *key, void *val, int type);

#endif // PAR_H
