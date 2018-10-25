/*!
 * \file   Integrate.h
 * \brief    
 * \author Thomas Helfer
 * \date   02/08/2018
 * \copyright (C) Copyright Thomas Helfer 2018.
 * Use, modification and distribution are subject
 * to one of the following licences:
 * - GNU Lesser General Public License (LGPL), Version 3.0. (See accompanying
 *   file LGPL-3.0.txt)
 * - CECILL-C,  Version 1.0 (See accompanying files
 *   CeCILL-C_V1-en.txt and CeCILL-C_V1-fr.txt).
 */

#ifndef LIB_MGIS_BEHAVIOUR_INTEGRATE_H
#define LIB_MGIS_BEHAVIOUR_INTEGRATE_H

#include "MGIS/Config.h"
#include "MGIS/Status.h"
#include "MGIS/ThreadPool.h"
#include "MGIS/Behaviour/BehaviourDataView.h"
#include "MGIS/Behaviour/Behaviour.h"
#include "MGIS/Behaviour/MaterialDataManager.h"

#ifdef __cplusplus
extern "C" {
#endif /*  __cplusplus */

/*!
 * \brief integrate the behaviour. The returned value has the following
 * meaning:
 * - -1: integration failed
 * -  0: integration succeeded but results are unreliable
 * -  1: integration succeeded and results are reliable
 *
 * \param[out] r: result
 * \param[in,out] d: behaviour data
 * \param[in,out] b: behaviour
 */
MGIS_C_EXPORT mgis_status mgis_bv_integrate(int* const,
                                            mgis_bv_BehaviourDataView* const,
                                            const mgis_bv_Behaviour* const);
/*!
 * \brief integrate the behaviour for a range of integration points. The
 * returned value has the following meaning:
 * - -1: integration failed for at least one Gauss point
 * -  0: all integrations succeeded but results are unreliable for at least
 *       one Gauss point
 * -  1: integration succeeded and results are reliable.
 *
 * \param[out] r: result
 * \param[in,out] m: material data manager
 * \param[in] dt: time step
 * \param[in] b: first index of the range
 * \param[in] e: last index of the range
 */
MGIS_C_EXPORT mgis_status
mgis_bv_integrate_material_data_manager_part(int* const,
                                             mgis_bv_MaterialDataManager* const,
                                             const mgis_real,
                                             const mgis_size_type,
                                             const mgis_size_type);
/*!
 * \brief integrate the behaviour for a range of integration points. The
 * returned value has the following meaning:
 * - -1: integration failed for at least one Gauss point
 * -  0: all integrations succeeded but results are unreliable for at least
 *       one Gauss point
 * -  1: integration succeeded and results are reliable.
 *
 * \param[out] r: result
 * \param[in,out] p: thread pool
 * \param[in,out] m: material data manager
 * \param[in] dt: time step
 */
MGIS_C_EXPORT mgis_status
mgis_bv_integrate_material_data_manager(int* const,
                                        mgis_ThreadPool* const,
                                        mgis_bv_MaterialDataManager* const,
                                        const mgis_real);

#ifdef __cplusplus
}
#endif /*  __cplusplus */

#endif /*LIB_MGIS_BEHAVIOUR_INTEGRATE_H */