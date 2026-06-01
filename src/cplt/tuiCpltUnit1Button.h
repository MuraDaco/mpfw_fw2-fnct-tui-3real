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
 * tuiCpltUnit1Button.h
 *
 *  Created on: Feb,  25th 2025 (Tue)
 *      Author: Marco Dau
 */
 
#ifndef TUI_CPLT_UNIT_1_BUTTON_H
#define TUI_CPLT_UNIT_1_BUTTON_H

#include "tuiFnctRealUnit1Button.h"
#include "tuiGrphRealUnit5Base.h"


class tuiCpltUnit1Button_t :    
    public tuiFnctRealUnit1Button_t
    ,public tuiGrphRealUnit5Base_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiCpltUnit1Button_t       (const char* p_strName  ,func_t p_func);
    tuiCpltUnit1Button_t       (const char* p_strName  ,tuiFnctAbstUnit0_t* p_pFuncOwner ,tuiUnitFunc_t p_func);

    tuiCpltUnit1Button_t       (uint8_t p_h   ,const char* p_strName  ,func_t p_func    );
    tuiCpltUnit1Button_t       (box_t p_box    ,margins_t p_margin,   const char* p_strName  ,func_t p_func  );


    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------


};


#endif 	// TUI_CPLT_UNIT_1_BUTTON_H   
