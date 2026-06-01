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
 * tuiCpltCtnr2StreamFormattedStringX.h
 *
 *  Created on: Feb,  1st 2025 (Sat)
 *      Author: Marco Dau
 */
 

#include "tuiCpltCtnr2StreamFormattedStringX.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    uint8_t tuiCpltCtnr2StreamFormattedStringX_t::g_initBufferIn1[] = {                                                                   
        '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11
    };                                                                                                                                   
    uint8_t tuiCpltCtnr2StreamFormattedStringX_t::g_initBufferIn2[] = {                                                                   
        '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22
    };                                                                                                                                   
    uint8_t tuiCpltCtnr2StreamFormattedStringX_t::g_initBufferIn3[] = {                                                                   
        '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33
    };                                                                                                                                   
    dtyBuffer_t tuiCpltCtnr2StreamFormattedStringX_t::g_initTextCntnr[] = {                                                               
         {g_initBufferIn1, sizeof(g_initBufferIn1)}                                                                                      
        ,{g_initBufferIn2, sizeof(g_initBufferIn2)}                                                                                      
        ,{g_initBufferIn3, sizeof(g_initBufferIn3)}                                                                                      
        };

    tuiCpltCtnr2StreamFormattedStringX_t::tuiCpltCtnr2StreamFormattedStringX_t       (box_t p_box)   :
        tuiFnctRealUnit2Cntnr_t     {"Receving data box",   &g_dtyCntnrStreamList}
        ,tuiGrphRealUnit5Base_t     {this, p_box}
        ,g_dtyCntnrStreamList       {g_initTextCntnr    ,sizeof(g_initTextCntnr)}
    {}

    tuiCpltCtnr2StreamFormattedStringX_t::tuiCpltCtnr2StreamFormattedStringX_t       (box_t p_box    ,margins_t p_margin)   :
        tuiFnctRealUnit2Cntnr_t     {"Receving data box",   &g_dtyCntnrStreamList}
        ,tuiGrphRealUnit5Base_t     {this, p_box, p_margin}
        ,g_dtyCntnrStreamList       {g_initTextCntnr    ,sizeof(g_initTextCntnr)}
    {}

    tuiCpltCtnr2StreamFormattedStringX_t::tuiCpltCtnr2StreamFormattedStringX_t       (box_t p_box    ,margins_t p_margin, dtyBuffer_t* p_initBuffersArray, size_t p_initBuffersArraySize) :
        tuiFnctRealUnit2Cntnr_t     {"Receving data box",   &g_dtyCntnrStreamList}
        ,tuiGrphRealUnit5Base_t     {this, p_box, p_margin}
        ,g_dtyCntnrStreamList       {p_initBuffersArray     ,static_cast<uint16_t>(p_initBuffersArraySize)}
    {}

    tuiCpltCtnr2StreamFormattedStringX_t::tuiCpltCtnr2StreamFormattedStringX_t       (uint8_t p_h    ,const char* p_strName    ,tuiCplt_dtyCntnr2StreamListFStrX_t* p_dtyCntnrStreamList)   :
        tuiFnctRealUnit2Cntnr_t     {p_strName,   p_dtyCntnrStreamList}
        ,tuiGrphRealUnit5Base_t     {this, p_h}
    {}


    tuiCpltCtnr2StreamFormattedStringX_t::tuiCpltCtnr2StreamFormattedStringX_t       (box_t p_box    ,margins_t p_margin  ,tuiCplt_dtyCntnr2StreamListFStrX_t* p_dtyCntnrStreamList) :
        tuiFnctRealUnit2Cntnr_t     {"Receving data box",   p_dtyCntnrStreamList}
        ,tuiGrphRealUnit5Base_t     {this, p_box, p_margin}
    {}



    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
