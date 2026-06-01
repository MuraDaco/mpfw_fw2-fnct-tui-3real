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
 * tuiCpltUnit1FormattedStringCntnr.h
 *
 *  Created on: Feb,  1st 2025 (Sat)
 *      Author: Marco Dau
 */
 

#include "tuiCpltUnit1FormattedStringCntnr.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiCpltUnit1FormattedStringCntnr_t::tuiCpltUnit1FormattedStringCntnr_t       (void)   :
        tuiFnctRealUnit1FormattedStringCntnr_t      {"-", &g_string}
        ,tuiGrphRealUnit5Base_t                     {this, box_t({ 8, 0, 0, 0})}
    {}

    tuiCpltUnit1FormattedStringCntnr_t::tuiCpltUnit1FormattedStringCntnr_t       (box_t p_box)   :
        tuiFnctRealUnit1FormattedStringCntnr_t      {"-",&g_string}
        ,tuiGrphRealUnit5Base_t                     {this, p_box}
    {}

    tuiCpltUnit1FormattedStringCntnr_t::tuiCpltUnit1FormattedStringCntnr_t       (box_t p_box    ,margins_t p_margin)   :
        tuiFnctRealUnit1FormattedStringCntnr_t      {"-",&g_string}
        ,tuiGrphRealUnit5Base_t                     {this, p_box, p_margin}
    {}

    tuiCpltUnit1FormattedStringCntnr_t::tuiCpltUnit1FormattedStringCntnr_t       (box_t p_box    ,margins_t p_margin, char* p_pChar, size_t p_size) :
        tuiFnctRealUnit1FormattedStringCntnr_t      {"-",&g_string}
        ,tuiGrphRealUnit5Base_t                     {this, p_box, p_margin}
        ,g_string                                   {p_pChar, p_size}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
