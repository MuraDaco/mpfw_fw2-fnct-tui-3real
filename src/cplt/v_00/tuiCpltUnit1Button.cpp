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
 

#include "tuiCpltUnit1Button.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiCpltUnit1Button_t::tuiCpltUnit1Button_t       (const char* p_strName  ,func_t p_func)    :
        tuiFnctRealUnit1Button_t    {p_strName, p_func}
        ,tuiGrphRealUnit5Base_t     {this, box_t({ 1, 0, 0, 0})}
    {}

    tuiCpltUnit1Button_t::tuiCpltUnit1Button_t       (const char* p_strName  ,tuiFnctAbstUnit0_t* p_pFuncOwner ,tuiUnitFunc_t p_func)    :
        tuiFnctRealUnit1Button_t    {p_strName, p_pFuncOwner, p_func}
        ,tuiGrphRealUnit5Base_t     {this, box_t({ 1, 0, 0, 0})}
    {}

    tuiCpltUnit1Button_t::tuiCpltUnit1Button_t       (uint8_t p_h   ,const char* p_strName  ,func_t p_func    )   :
        tuiFnctRealUnit1Button_t    {p_strName, p_func}
        ,tuiGrphRealUnit5Base_t     {this, p_h}
    {}

    tuiCpltUnit1Button_t::tuiCpltUnit1Button_t       (box_t p_box    ,margins_t p_margin,   const char* p_strName  ,func_t p_func  )    :
        tuiFnctRealUnit1Button_t    {p_strName, p_func}
        ,tuiGrphRealUnit5Base_t     {this   ,p_box    ,p_margin}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
