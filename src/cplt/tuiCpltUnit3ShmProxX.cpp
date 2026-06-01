//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork
//  Copyright (C) (2023) Marco Dau
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//  
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  
//  You can contact me by the following email address
//  marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
//  
//  *******************************************************************************

/*
 * tuiCpltUnit3ShmProxX.cpp
 *
 *  Created on: Mar, 16th 2025 (Sun)
 *      Author: Marco Dau
 */
 

#include "tuiCpltUnit3ShmProxX.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiCpltUnit3ShmProxX_t::tuiCpltUnit3ShmProxX_t       (box_t p_box, margins_t p_margins)   :
        tuiFnctRealUnit2Cntnr_t      ("-", &g_streamListProx)
        ,tuiGrphRealUnit5Base_t         {   this    ,p_box, p_margins}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
