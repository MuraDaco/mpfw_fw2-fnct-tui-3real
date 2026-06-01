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
 * tuiCpltCplx3McuUsartX.h
 *
 *  Created on: Feb,  1st 2025 (Sat)
 *      Author: Marco Dau
 */
 

#include "tuiCpltCplx3McuUsartX.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiCpltCplx3McuUsartX_t::tuiCpltCplx3McuUsartX_t       (box_t p_box, margins_t p_margins, pphUsart_t*   p_pPphUSART)   :
        tuiFnctRealCplx3McuUsartX_t     (   p_pPphUSART
                                            ,&g_dty_recevingDataCntnr
                                            ,g_char_sendingDataBuffer
                                            ,&g_tui_sendingDataBox
                                            ,&g_dty_boxesCntnr)
        ,tuiGrphRealUnit5Base_t         {   this    ,p_box, p_margins}
        ,g_tui_receivingDataBox         (   9   ,"Receving data box" ,&g_dty_recevingDataCntnr)
        ,g_tui_sendingDataBox           (   3   ,"Sending data box"  ,g_char_sendingDataBuffer, sizeof(g_char_sendingDataBuffer))
        ,g_boxesArray                   {
                                             &g_tui_receivingDataBox
                                            ,&g_tui_sendingDataBox
                                            ,nullptr
                                        }
        ,g_dty_boxesCntnr               {g_boxesArray}

    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
