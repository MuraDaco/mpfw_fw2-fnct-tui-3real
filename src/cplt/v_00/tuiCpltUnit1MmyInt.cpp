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
 * tuiCpltUnit1MmyInt.h
 *
 *  Created on: Apr,   2nd 2025 (Wed)
 *      Author: Marco Dau
 */
 

#include "tuiCpltUnit1MmyInt.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiCpltUnit1MmyInt_t::tuiCpltUnit1MmyInt_t       ( void   )    :
         tuiFnctRealUnit1MmyInt_t  {&g_loopDtyData}
        ,tuiGrphRealUnit5Base_t    {this, box_t({ 1, 0, 0, 0})}
    {}

    tuiCpltUnit1MmyInt_t::tuiCpltUnit1MmyInt_t       (dtyUnit1MmyInt32_t* p_loopDtyData)    :
         tuiFnctRealUnit1MmyInt_t  {p_loopDtyData}
        ,tuiGrphRealUnit5Base_t    {this, box_t({ 1, 0, 0, 0})}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
