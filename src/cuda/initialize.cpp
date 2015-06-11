//-----------------------------------------------------------------------------
//
// This source file is part of the VAMPIRE open source package under the
// GNU GPL (version 2) licence (see licence file for details).
//
// (c) R F L Evans 2015. All rights reserved.
//
//-----------------------------------------------------------------------------

// C++ standard library headers

#include <vector>

// Thrust library headers

#include <thrust/device_vector.h>
#include <thrust/copy.h>

// Vampire headers
#include "atoms.hpp"
#include "cuda.hpp"

// Local cuda headers
#include "internal.hpp"

namespace cuda{

   //-------------------------------------------------------------------------------
   // Function to initialize GPU data
   //-------------------------------------------------------------------------------
   bool initialize(){

#ifdef CUDA

      // send the spin information

      /*
       * Allocate memory in the device and transfer the
       * spins of the atoms.
       */

      x_spin_array.resize(atoms::num_atoms);
      y_spin_array.resize(atoms::num_atoms);
      z_spin_array.resize(atoms::num_atoms);

      thrust::copy(
            atoms::x_spin_array.begin(),
            atoms::x_spin_array.end()
            x_spin_array.begin()
            );

      thrust::copy(
            atoms::y_spin_array.begin(),
            atoms::y_spin_array.end()
            y_spin_array.begin()
            );

      thrust::copy(
            atoms::z_spin_array.begin(),
            atoms::z_spin_array.end()
            z_spin_array.begin()
            );

      /*
       * Allocate memory in the device and transfer the
       * coordinates of the atoms.
       */

      x_coord_array.resize(atoms::num_atoms);
      y_coord_array.resize(atoms::num_atoms);
      z_coord_array.resize(atoms::num_atoms);

      thrust::copy(
            atoms::x_coord_array.begin(),
            atoms::x_coord_array.end()
            cuda::internal::x_coord_array.begin()
            );

      thrust::copy(
            atoms::y_coord_array.begin(),
            atoms::y_coord_array.end()
            y_coord_array.begin()
            );

      thrust::copy(
            atoms::z_coord_array.begin(),
            atoms::z_coord_array.end()
            z_coord_array.begin()
            );

      /*
       * Allocate memory in the device and transfer the
       * total spin field in each atom.
       */

      x_total_spin_field_array.resize(atoms::num_atoms);
      y_total_spin_field_array.resize(atoms::num_atoms);
      z_total_spin_field_array.resize(atoms::num_atoms);

      thrust::copy(
            atoms::x_total_spin_field_array.begin(),
            atoms::x_total_spin_field_array.end()
            x_total_spin_field_array.begin()
            );

      thrust::copy(
            atoms::y_total_spin_field_array.begin(),
            atoms::y_total_spin_field_array.end()
            y_total_spin_field_array.begin()
            );

      thrust::copy(
            atoms::z_total_spin_field_array.begin(),
            atoms::z_total_spin_field_array.end()
            z_total_spin_field_array.begin()
            );

      /*
       * Allocate memory in the device and transfer the
       * total external field in each atom.
       */

      cuda::internal::x_total_external_field_array.resize(atoms::num_atoms);
      cuda::internal::y_total_external_field_array.resize(atoms::num_atoms);
      cuda::internal::z_total_external_field_array.resize(atoms::num_atoms);

      thrust::copy(
            atoms::x_total_external_field_array.begin(),
            atoms::x_total_external_field_array.end()
            x_total_external_field_array.begin()
            );

      thrust::copy(
            atoms::y_total_external_field_array.begin(),
            atoms::y_total_external_field_array.end()
            y_total_external_field_array.begin()
            );

      thrust::copy(
            atoms::z_total_external_field_array.begin(),
            atoms::z_total_external_field_array.end()
            z_total_external_field_array.begin()
            );

      /*
       * Allocate memory and send information about the types of
       * atoms
       */

      type_array.resize(atoms::num_atoms);

      thrust::copy(
            atoms::type_array.begin(),
            atoms::type_array.end(),
            type_array.begin()
            );

      // send the material information
      // send the macro-cell information

      // Successful initialization
      return true;

#endif

      // Default (initializtion failed)
      return false;

   }

} // end of namespace cuda
