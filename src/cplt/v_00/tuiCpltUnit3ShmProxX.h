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
 * tuiCpltUnit3ShmProxX.h
 *
 *  Created on: Apr,  3rd 2025 (Thu)
 *      Author: Marco Dau
 */
 
#ifndef TUI_CPLT_UNIT_3_SHM_PROX_X_H
#define TUI_CPLT_UNIT_3_SHM_PROX_X_H

#include "tuiFnctRealUnit2Cntnr.h"
#include "tuiGrphRealUnit5Base.h"

#include "tuiCplt_dtyCntnr2StreamListShmProxX.h"


class tuiCpltUnit3ShmProxX_t :    
     public tuiFnctRealUnit2Cntnr_t
    ,public tuiGrphRealUnit5Base_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiCpltUnit3ShmProxX_t       (box_t p_box    ,margins_t p_margin);


    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    private:
        tuiCplt_dtyCntnr2StreamListShmProxX_t          g_streamListProx;

    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------


};


#endif 	// TUI_CPLT_UNIT_3_SHM_PROX_X_H
