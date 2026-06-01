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
 * tuiCplt_dtyCntnr2StreamListFStr.h
 *
 *  Created on: Nov, 21st 2024 (Thu)
 *      Author: Marco Dau
 */
 
#ifndef TUI_CPLT_DTY_CNTNR_2_STREAM_LIST_F_STR_H
#define TUI_CPLT_DTY_CNTNR_2_STREAM_LIST_F_STR_H

#include "dtyCntnr1StreamList.h"

#include "tuiCpltUnit1FormattedStringCntnr.h"

class tuiCplt_dtyCntnr2StreamListFStr_t: public dtyCntnr1StreamList_t {

    public:

    tuiCplt_dtyCntnr2StreamListFStr_t   (void);
    tuiCplt_dtyCntnr2StreamListFStr_t   (dtyBuffer_t* p_pArrayBufIn, uint16_t p_arrayBufInSize);

    private:
    tuiCpltUnit1FormattedStringCntnr_t  g_tuiCplt_formattedString;

    static uint8_t      g_initBufferIn1[];
    static uint8_t      g_initBufferIn2[];
    static uint8_t      g_initBufferIn3[];
    static dtyBuffer_t  g_initUsartTextCntnr[];
    static uint8_t      g_pBuf[1000000];

};


#endif 	// TUI_CPLT_DTY_CNTNR_2_STREAM_LIST_F_STR_H
