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
 * tuiCpltCplx3McuUsartXX.h
 *
 *  Created on: Feb,  20th 2025 (Thu)
 *      Author: Marco Dau
 */
 
#ifndef TUI_CPLT_CPLX_3_MCU_USART_XX_H
#define TUI_CPLT_CPLX_3_MCU_USART_XX_H

#include "tuiCpltCtnr2StreamFormattedStringX.h"
#include "tuiCpltUnit1Button.h"
#include "tuiCpltUnit1Ebox.h"
#include "dtyCntnr1ArrayTuiList.h"

#include "tuiFnctRealCplx3McuUsartXX.h"
#include "tuiGrphRealUnit5Base.h"


class tuiCpltCplx3McuUsartXX_t :    
    public tuiFnctRealCplx3McuUsartXX_t
    ,public tuiGrphRealUnit5Base_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiCpltCplx3McuUsartXX_t  (  box_t p_box, margins_t p_margins, pphUsartRs485_t*   p_pPphUSART
                                ,tuiCpltUnit1Button_t*  p_pTuiButton_copy
                                ,tuiCpltUnit1Button_t*  p_pTuiButton_paste
    );
    tuiCpltCplx3McuUsartXX_t       (box_t p_box    ,margins_t p_margin, pphUsartRs485_t*  p_pPphUSART);


    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    public:
        // 1. elements definition
            //  1.1. receiving box definition
                tuiCplt_dtyCntnr2StreamListFStrX_t    g_dty_recevingDataCntnr;
                tuiCpltCtnr2StreamFormattedStringX_t g_tui_receivingDataBox;
            //  1.2. sending box definition
                char                                g_char_sendingDataBuffer[PPH_TX_BUFFER_SIZE];
                tuiCpltUnit1Ebox_t                  g_tui_sendingDataBox;
        // 2. elements conatiner definiton
            dtyIntfcAbstractUnitGraphic_t*           g_boxesArray[5];
            dtyCntnr1ArrayTuiList_t                 g_dty_boxesCntnr;

    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------


};


#endif 	// TUI_CPLT_CPLX_3_MCU_USART_XX_H
