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
 * tuiCpltCplx4McuUsartUU.h
 *
 *  Created on: Apr,  19th 2025 (Sat)
 *      Author: Marco Dau
 */
 
#ifndef TUI_CPLT_CPLX_4_MCU_USART_UU_H
#define TUI_CPLT_CPLX_4_MCU_USART_UU_H

#include "tuiCpltCplx3McuUsartXX.h"


class tuiCpltCplx4McuUsartUU_t :    
    public tuiCpltCplx3McuUsartXX_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiCpltCplx4McuUsartUU_t       (box_t p_box    ,margins_t p_margin, pphUsartRs485_t*  p_pPphUSART);


    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    private:
        // 1. elements definition
            // 1.1. elements definition
                tuiCpltUnit1Button_t    g_tuiButton_copy;
                tuiCpltUnit1Button_t    g_tuiButton_paste;

    static void buttonCopyToClip    (void);
    static void buttonPasteFromClip (void);

    static void buttonCopyToClip_par    (dtyIntfcAbstractUnitFunctional_t* p_this);
    static void buttonPasteFromClip_par (dtyIntfcAbstractUnitFunctional_t* p_this);


    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------


};


#endif 	// TUI_CPLT_CPLX_4_MCU_USART_UU_H
