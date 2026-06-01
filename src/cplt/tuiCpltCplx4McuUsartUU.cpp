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
 

#include "tuiCpltCplx4McuUsartUU.h"
#include "sdkClipboard.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiCpltCplx4McuUsartUU_t::tuiCpltCplx4McuUsartUU_t       (box_t p_box, margins_t p_margins, pphUsart_t*   p_pPphUSART)   :
        tuiCpltCplx3McuUsartXX_t     (   p_box
                                        ,p_margins
                                        ,p_pPphUSART
                                        ,&g_tuiButton_copy
                                        ,&g_tuiButton_paste
        )
        ,g_tuiButton_copy           (   "copy to clipboard"    ,this   ,buttonCopyToClip_par    )
        ,g_tuiButton_paste          (   "paste from clipboard" ,this   ,buttonPasteFromClip_par )
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    // private:
        void tuiCpltCplx4McuUsartUU_t::buttonCopyToClip  (void)      {
            sdkClipboard_t::copy("test clipboard");
        }

        void tuiCpltCplx4McuUsartUU_t::buttonPasteFromClip  (void)      {
            sdkClipboard_t::copy((sdkClipboard_t::paste() + " -- prova clip").c_str());
        }


        void tuiCpltCplx4McuUsartUU_t::buttonCopyToClip_par    ([[maybe_unused]] dtyIntfcAbstractUnitFunctional_t* p_this) {
            tuiCpltCplx4McuUsartUU_t* l_this = static_cast<tuiCpltCplx4McuUsartUU_t*>(p_this);
            dtyString_t* l_pString       = static_cast<dtyString_t*>(l_this->g_recevingDataCntnr->getSelectedItemPtrData());
            if(l_pString)   {
                char l_str[300];
                uint16_t l_length = l_pString->copyBufferToString(l_str, sizeof(l_str));
                //const char* l_str = static_cast<const char*>(l_this->g_recevingDataCntnr->getSelectedItem());
                if(l_length) sdkClipboard_t::copy(l_str); else sdkClipboard_t::copy("buffer string to small");
            } else 
                sdkClipboard_t::copy("string is empty.-");
        }

        void tuiCpltCplx4McuUsartUU_t::buttonPasteFromClip_par (dtyIntfcAbstractUnitFunctional_t* p_this) {
            tuiCpltCplx4McuUsartUU_t* l_this = static_cast<tuiCpltCplx4McuUsartUU_t*>(p_this);
            l_this->g_tui_sendingDataBox.insertString(sdkClipboard_t::paste().c_str());
            l_this->g_tui_sendingDataBox.refreshDisplay(&l_this->g_tui_sendingDataBox);
            //if(l_pString)   {
            //    char l_str[300];
            //    l_pString->copyString(l_str, sizeof(l_str));
            //    sdkClipboard_t::paste(l_str);
            //} else sdkClipboard_t::copy("string is empty. ");
        }


    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------

