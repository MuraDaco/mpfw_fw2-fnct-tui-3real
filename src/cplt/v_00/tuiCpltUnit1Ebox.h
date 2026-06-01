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
 * tuiCpltUnit1Ebox.h
 *
 *  Created on: Feb,  20th 2025 (Thu)
 *      Author: Marco Dau
 */
 
#ifndef TUI_CPLT_UNIT_1_EBOX_H
#define TUI_CPLT_UNIT_1_EBOX_H

#include "tuiFnctRealUnit1Ebox.h"
#include "tuiGrphRealUnit5Base.h"


class tuiCpltUnit1Ebox_t :    
    public tuiFnctRealUnit1Ebox_t
    ,public tuiGrphRealUnit5Base_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiCpltUnit1Ebox_t       (               const char* p_strName  ,char* p_string, uint16_t p_stringSize  );
    tuiCpltUnit1Ebox_t       (uint8_t p_h   ,const char* p_strName  ,char* p_string, uint16_t p_stringSize  );
    tuiCpltUnit1Ebox_t       (box_t p_box    ,margins_t p_margin,   const char* p_strName  ,char* p_string, uint16_t p_stringSize  );


    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    private:

        dtyBaseArray_t g_string;

    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------


};


#endif 	// TUI_CPLT_UNIT_1_EBOX_H   
