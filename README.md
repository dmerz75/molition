# Emolsion
Emolsion evaluates microtubule properties, particularly contacts and topologies, by reading the dcd
into the pdb. It is capable of reading in a wide range of sizes and number of segments (i.e. the
microtubule is often up to 312 chains of 427 to 438 atoms per segment for a total of 135k atoms).

The contacts, often determined by a spherical 8 angstrom cutoff, are evaluated both by monomer
(alpha/beta) and by dimer. They are also evaluated by
North, South, East, and West neighbors. They are further subdivided by their localization in each
monomer as N-term, Middle term, or C-term contacts. As the coordinates evolve in time (reading the dcd),
the contacts are tracked according to a tolerance criterion of 10 - 13 Angstroms. Their persistence is
output to data files, easily plotted with the combination of numpy and matplotlib.

## Quickstart:
1. DCD reading: To read a pdb with corresponding dcd (from frames 6 - 27, stepping by 3 frames) ..

        make dcdr
        emol_dcdreader mt.ref.pdb mt_partial.dcd 6 27 3

2. DCD writing: To write a dcd from the pdb with corresponding dcd (from frames 4 - 30,
stepping by 2 frames)..

        make dcdw
        emol_dcdwriter mt.ref.pdb mt_partial.dcd 4 30 2


## Investigating severing by Katanin: Indentation of a microtubule.
Microtubule indentation is in silico way to match the in vitro experiment, Atomic Force Microscopy (AFM).
It is also representative of how severing proteins will apply force to the microtubule lattice to aid in or
induce depolymerization. The 600 piconewtons measured in silico is comparable to AFM experiments.
The first break usually occurs at 300 piconewtons, and the critical break occurs at the peak force.
Contact analysis reveals the pathways and fractures behind these breaks.

This microtubule is arranged from South, the alpha-orange monomer end (negative), to North,
the beta-blue/cyan monomer end(positive). (See figure below) Indentation positions, 1,2,3,4 shown,
result in a distribution of forces (see Force-Indentation plot, below, on left). The distribution of forces
can be explained by the fracturing patterns (see fracturing patterns for indentation positions 1,3 on right, below)
and quantified by contact analysis.

Figure of microtubule:
<!-- ![Figure of Microtubule](https://github.com/dmerz75/emolsion/blob/master/fig/microtubule.png) -->
<img src="https://github.com/dmerz75/emolsion/blob/master/fig/microtubule.png" width=900>

## Analysis: Curvature during breaking.
Figure of the Alpha/Beta monomers' curvature.
<!-- ![Figure of the curvature](https://github.com/dmerz75/emolsion/blob/master/fig/alphabetacurvaturedesc.png {width=400px height=400px}) -->
<img src="https://github.com/dmerz75/emolsion/blob/master/fig/alphabetacurvaturedesc.png" width=800>


## Microtubules' Contacts:
Contacts were evaluated according to the following diagram:

            West
            4  7
         2  0  1  5
            3  6
            East


Only external (not intra-alpha, intra-beta, or intra-dimer) contacts are shown.
West (left), East (right),
South (bottom), and North (top) are subdivided into the N-term (red), Middle (green), C-term (blue) subdomains for
each tubulin monomer.

The alpha monomer (0) and the beta monomer (1) have internal contacts (designated intra) and interfacial contacts
(designated external) by way of 9 situations:
* 0    intra-alpha  (internal)
* 1    intra-beta   (internal)
* 0-1  intra-dimer  (internal)
* 0-2  alpha-south  (external)
* 0-3  alpha-east   (external)
* 0-4  alpha-west   (external)
* 1-5  beta-north   (external)
* 1-6  beta-east    (external)
* 1-7  beta-west    (external)

The external contacts (the sum of the longitudinal north and south, the lateral east and west) are plotted by dimer.
(see the Contacts vs. Frame plots on the left, below). The external contacts can be further understood by their points of
origin, the N-term(red), M-term(green), or C-term(blue) on the longitudinal and lateral interfaces (see 6 plots on the right, below).
The top is the longitudinal north (beta monomer) interface, followed by the west and east beta lateral interfaces, followed again by the
west and east alpha lateral interfaces, finally followed by longitudinal south (alpha monomer) interface.

<!-- ![Figure of representative contacts](https://github.com/dmerz75/emolsion/blob/master/fig/contacts65.png) -->
<img src="https://github.com/dmerz75/emolsion/blob/master/fig/contacts65.png" width=900>


<!-- ![Figure of representative contacts](https://github.com/dmerz75/emolsion/blob/master/fig/contacts79.png) -->
<img src="https://github.com/dmerz75/emolsion/blob/master/fig/contacts79.png" width=900>


## Analysis: Compile histograms.
From the five positions described above, multiple indentation trajectories were acquired. Getting meaningful information about
the fracturing patterns and breaking methods would prove quite difficult if the force-indentation curves were all we had.

Figure of Force-Indentation by position:
<!-- ![Figure of Force-Indentation by position](https://github.com/dmerz75/emolsion/blob/master/fig/forceextensiondoz1thru5.png) -->
<img src="https://github.com/dmerz75/emolsion/blob/master/fig/forceextensiondoz1thru5.png" width=950>

Instead, by evaluating each force-indentation curve by the first and critical breaking points, corroborated by analysis of the loss
of contacts, we identify the exact points at which the cantilever disrupts the microtubule's lattice, initially and critically.

Figure of the first and critical breaking forces:
<!-- ![Figure of the first and critical breaking forces](https://github.com/dmerz75/emolsion/blob/master/fig/doz3firstcritbreak.png {width=400px height=800px}) -->
<img src="https://github.com/dmerz75/emolsion/blob/master/fig/doz3firstcritbreak.png" height=800>


By collecting the first and critical breaking forces, statistics and histograms of the forces required at each break reveal the position dependence
of severing by katanin or the corresponding cantilever.
Histogram of preliminary/example results:
<!-- ![Histogram of the example results](https://github.com/dmerz75/emolsion/blob/master/fig/examplehistogram.png {width=800px height=400px}) -->
<img src="https://github.com/dmerz75/emolsion/blob/master/fig/examplehistogram.png" width=950>

## Analysis: Upon Retraction of cantilever.
Retraction, recovery, and healing of the lattice was also investigated to identify its resilience. By revealing the point of no
return (a permanent lack of recovery), the extent of contact loss reveals the kinetic limitations of the lattice to reform.

Figure of contact recovery during retraction of the cantilever:
<!-- ![Figure of contact recovery](https://github.com/dmerz75/emolsion/blob/master/fig/contactsbyretraction.png {width=800px height=600px}) -->
<img src="https://github.com/dmerz75/emolsion/blob/master/fig/contactsbyretraction.png" width=950px>


## Dependencies:
Other softwares I often use with this project include:
* cscope - developer's tool for browsing program code. Run `./scope.sh`, creates cscope.files and cscope.out.
* [Boost](http://www.boost.org/) - provides free peer-reviewed portable C++ source libraries.


## Notes/ Disclaimer/ Acknowledgements:
Six header files are not mine. They are currently used because I believe permission was given
provided the copyrights were retained and credit/notice given. They are:

* [Zed A. Shaw's] (https://learncodethehardway.org/c/) awesome debug macros.
  * debug.h
* These 5 headers are from UIUC, for use with their proprietary 'dcd' format. Information is
provided [here.] (http://www.ks.uiuc.edu/Research/vmd/plugins/doxygen/files.html)

        (C) Copyright 1995-2006 The Board of Trustees of the
                        University of Illinois
                         All Rights Reserved

  * dcdio.h ([dcdplugin.h](http://www.ks.uiuc.edu/Research/vmd/plugins/doxygen/dcdplugin_8c.html))
  * [endianswap.h] (http://www.ks.uiuc.edu/Research/vmd/plugins/doxygen/endianswap_8h.html)
  * [fastio.h] (http://www.ks.uiuc.edu/Research/vmd/plugins/doxygen/fastio_8h.html)
  * [largefiles.h] (http://www.ks.uiuc.edu/Research/vmd/plugins/doxygen/largefiles_8h.html)
  * [molfile_plugin.h] (http://www.ks.uiuc.edu/Research/vmd/plugins/doxygen/molfile__plugin_8h.html)

* Some of the coordinates in the test directory are straight from the [PDB] (http://www.rcsb.org/).
  * [2KHO.pdb] (http://www.rcsb.org/pdb/explore.do?structureId=2kho)
