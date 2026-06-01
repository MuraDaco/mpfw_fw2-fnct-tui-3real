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
 * tuiCpltCplx4McuUsartWW.h
 *
 *  Created on: Apr,  18th 2025 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiCpltCplx4McuUsartWW.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiCpltCplx4McuUsartWW_t::tuiCpltCplx4McuUsartWW_t       (box_t p_box, margins_t p_margins, pphUsart_t*   p_pPphUSART)   :
        tuiFnctRealCplx4McuUsartWW_t     (   p_pPphUSART
                                            ,&g_dty_recevingDataCntnr
                                            ,g_char_sendingDataBuffer
                                            ,&g_tui_sendingDataBox
                                            ,&g_tuiButton_copy;
                                            ,&g_tuiButton_paste;
                                            ,&g_dty_boxesCntnr)
        ,tuiGrphRealUnit5Base_t         {   this    ,p_box, p_margins}
        ,g_tui_receivingDataBox         (   9   ,"Receving data box" ,&g_dty_recevingDataCntnr)
        ,g_tui_sendingDataBox           (   3   ,"Sending data box"  ,g_char_sendingDataBuffer, sizeof(g_char_sendingDataBuffer))
        ,g_tuiButton_copy               ("", copyToClipboard)
        ,g_tuiButton_paste              ("", pasteFromClipboard)
        ,g_boxesArray                   {
                                             &g_tui_receivingDataBox
                                            ,&g_tui_sendingDataBox
                                            ,&g_tuiButton_copy
                                            ,&g_tuiButton_paste
                                            ,nullptr
                                        }
        ,g_dty_boxesCntnr               {g_boxesArray}

    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
