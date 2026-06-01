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
 * tuiCpltCtnr2StreamFormattedString.h
 *
 *  Created on: Feb,  20th 2025 (Thu)
 *      Author: Marco Dau
 */
 
#ifndef TUI_CPLT_UNIT_2_STREAM_FORMATTED_STRING_H
#define TUI_CPLT_UNIT_2_STREAM_FORMATTED_STRING_H

#include "tuiFnctRealUnit2Cntnr.h"
#include "tuiCplt_dtyCntnr2StreamListFStr.h"

#include "tuiGrphRealUnit5Base.h"


class tuiCpltCtnr2StreamFormattedString_t :    
    public tuiFnctRealUnit2Cntnr_t
    ,public tuiGrphRealUnit5Base_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiCpltCtnr2StreamFormattedString_t       (box_t p_box );
    tuiCpltCtnr2StreamFormattedString_t       (box_t p_box    ,margins_t p_margin);
    tuiCpltCtnr2StreamFormattedString_t       (box_t p_box    ,margins_t p_margin       ,dtyBuffer_t* p_initBuffersArray, size_t p_initBuffersArraySize);
    tuiCpltCtnr2StreamFormattedString_t       (uint8_t p_h    ,const char* p_strName    ,tuiCplt_dtyCntnr2StreamListFStr_t* p_dtyCntnrStreamList);
    tuiCpltCtnr2StreamFormattedString_t       (box_t p_box    ,margins_t p_margin       ,tuiCplt_dtyCntnr2StreamListFStr_t* p_dtyCntnrStreamList);

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    private:
        static  uint8_t g_initBufferIn1[];
        static  uint8_t g_initBufferIn2[];
        static  uint8_t g_initBufferIn3[];
        static  dtyBuffer_t g_initTextCntnr[];

        tuiCplt_dtyCntnr2StreamListFStr_t    g_dtyCntnrStreamList;

    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------


};


#endif 	// TUI_CPLT_UNIT_2_STREAM_FORMATTED_STRING_H
