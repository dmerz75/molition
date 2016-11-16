// dcd.h
#ifndef _DCD_H_
#define _DCD_H_

// libraries:
/* #include <stdio.h> */

/* #include "dcdio.h" */ // fails


// Definitions:
/* #define BUFFERSIZE 900 */

/* ---------------------------------------------------------
   Class declarations
   --------------------------------------------------------- */
/* #ifndef CHAIN_H */
/* #define CHAIN_H */
/* #include "chain.h" */
#include "dcdio.h"
/* #include "" */
/* #endif */


/* ---------------------------------------------------------
   function declarations
   --------------------------------------------------------- */
int my_dcd_start(int frame);
int advance_dcd(int numframes,int frame,dcdhandle *v,int natoms,molfile_timestep_t *timestep);
void load_dcd_to_chain(dcdhandle *dcd,Chain *chain,int num_chains);
void load_dcd_to_atoms(dcdhandle *dcd,Atom *aa);
void load_chain_to_timestep(System *chain,int num_chains,   \
                            const molfile_timestep_t *ts);


#endif
