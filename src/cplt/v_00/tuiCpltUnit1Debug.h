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
 * tuiCpltUnit1Debug.h
 *
 *  Created on: Feb, 24th 2025 (Mon)
 *      Author: Marco Dau
 */
 
#ifndef TUI_CPLT_UNIT_1_DEBUG_H
#define TUI_CPLT_UNIT_1_DEBUG_H

#include "tuiFnctRealUnit1Debug.h"
#include "tuiGrphRealUnit5Base.h"


class tuiCpltUnit1Debug_t :    
    public tuiFnctRealUnit1Debug_t
    ,public tuiGrphRealUnit5Base_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiCpltUnit1Debug_t       (uint8_t p_h                          ,const char* p_strName  ,dtyUnit1MmyInt32_t* p_pDtyStatus = nullptr   );
    tuiCpltUnit1Debug_t       (box_t p_box  ,margins_t p_margin     ,const char* p_strName  ,dtyUnit1MmyInt32_t* p_pDtyStatus = nullptr   );

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------


};


#endif 	// TUI_CPLT_UNIT_1_DEBUG_H
