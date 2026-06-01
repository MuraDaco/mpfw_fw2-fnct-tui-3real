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
 * tuiCpltUnit1DgtInOut.h
 *
 *  Created on: Feb,  25th 2025 (Tue)
 *      Author: Marco Dau
 */
 

#include "tuiCpltUnit1DgtInOut.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiCpltUnit1DgtInOut_t::tuiCpltUnit1DgtInOut_t       (                                       hwPinPort_t* p_pMcuPinPort   )    :
        tuiFnctRealUnit1DgtInOut_t  {"DgtInOut", p_pMcuPinPort}
        ,tuiGrphRealUnit5Base_t     {this, box_t({ 1, 0, 0, 0})}
    {}

    tuiCpltUnit1DgtInOut_t::tuiCpltUnit1DgtInOut_t       (               const char* p_strName  ,hwPinPort_t* p_pMcuPinPort   )    :
        tuiFnctRealUnit1DgtInOut_t  {p_strName, p_pMcuPinPort}
        ,tuiGrphRealUnit5Base_t     {this, box_t({ 1, 0, 0, 0})}
    {}

    tuiCpltUnit1DgtInOut_t::tuiCpltUnit1DgtInOut_t       (box_t p_box                           ,hwPinPort_t* p_pMcuPinPort   )    :
        tuiFnctRealUnit1DgtInOut_t  {"DgtInOut", p_pMcuPinPort}
        ,tuiGrphRealUnit5Base_t     {this   ,p_box}
    {}

    tuiCpltUnit1DgtInOut_t::tuiCpltUnit1DgtInOut_t       (box_t p_box   ,const char* p_strName  ,hwPinPort_t* p_pMcuPinPort   )    :
        tuiFnctRealUnit1DgtInOut_t  {p_strName, p_pMcuPinPort}
        ,tuiGrphRealUnit5Base_t     {this   ,p_box}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
