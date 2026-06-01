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
 * tuiCplt_MacroDefCtnr2StreamFormattedString.h
 *
 *  Created on: Feb, 21st 2025 (Fri)
 *      Author: Marco Dau
 */
 


#ifndef TUI_CPLT_MACRO_DEF_CTNR_2_STREAM_FORMATTED_STRING_H
#define TUI_CPLT_MACRO_DEF_CTNR_2_STREAM_FORMATTED_STRING_H

// ****************************************************
// section start **** STREAM OF FORMATTED STRINGS UNIT *****

    // sub-section .... header definition .....
        #define TUI_DEF_H___GRPH_CTNR_STREAM_FORMATTED_STRING( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                                        \
            static  uint8_t     g_initBufferIn1_##name[];                                                                                                       \
            static  uint8_t     g_initBufferIn2_##name[];                                                                                                       \
            static  uint8_t     g_initBufferIn3_##name[];                                                                                                       \
            static  dtyBuffer_t g_initTextCntnr_##name[];                                                                                                       \
            static uint8_t      g_dataBuffer_##name[1000000];                                                                                                   \
            static tuiCpltUnit1FormattedStringCntnr_t  g_tuiCpltFormattedString_##name;                                                                         \
            static dtyCntnr1StreamList_t               g_dtyCntnrStreamList_##name;                                                                             \
            static tuiFnctRealUnit2Cntnr_t  g_tuiFnct_##name;                                                                                                   \
            static tuiGrphRealUnit5Base_t   g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

        #define TUI_DEF_H___CPLT_CTNR_STREAM_FORMATTED_STRING( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                                        \
            static  uint8_t     g_initBufferIn1_##name[];                                                                                                       \
            static  uint8_t     g_initBufferIn2_##name[];                                                                                                       \
            static  uint8_t     g_initBufferIn3_##name[];                                                                                                       \
            static  dtyBuffer_t g_initTextCntnr_##name[];                                                                                                       \
            static tuiCpltCtnr2StreamFormattedString_t  g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

    // sub-section .... cpp definition .....
        #define TUI_DEF_CPP_GRPH_CTNR_STREAM_FORMATTED_STRING( class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                               \
            uint8_t class_t::g_initBufferIn1_##name[] = {                                                                                                       \
                '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11               \
            };                                                                                                                                                  \
            uint8_t class_t::g_initBufferIn2_##name[] = {                                                                                                       \
                '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22               \
            };                                                                                                                                                  \
            uint8_t class_t::g_initBufferIn3_##name[] = {                                                                                                       \
                '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33               \
            };                                                                                                                                                  \
            dtyBuffer_t class_t::g_initTextCntnr_##name[] = {                                                                                                   \
                 {g_initBufferIn1, sizeof(g_initBufferIn1_##name)}                                                                                              \
                ,{g_initBufferIn2, sizeof(g_initBufferIn2_##name)}                                                                                              \
                ,{g_initBufferIn3, sizeof(g_initBufferIn3_##name)}                                                                                              \
                };                                                                                                                                              \
            uint8_t                             class_t::g_dataBuffer_##name[1000000];                                                                          \
            tuiCpltUnit1FormattedStringCntnr_t  class_t::g_tuiCpltFormattedString_##name;                                                                       \
            dtyCntnr1StreamList_t               class_t::g_dtyCntnrStreamList_##name (                                                                          \
                                            g_dataBuffer_##name        ,sizeof(g_dataBuffer_##name)                                                             \
                                            ,g_initTextCntnr_##name    ,sizeof(g_initTextCntnr_##name)                                                          \
                                            ,&g_tuiCpltFormattedString_##name                                                                                   \
                                            ,&g_tuiCpltFormattedString_##name);                                                                                 \
            tuiFnctRealUnit2Cntnr_t class_t::g_tuiFnct_##name    ("Receving data box",   &g_dtyCntnrStreamList_##name);                                         \
            tuiGrphRealUnit5Base_t  class_t::g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  (                  \
                &g_tuiFnct_##name, box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt}) )

        #define TUI_DEF_CPP_CPLT_CTNR_STREAM_FORMATTED_STRING( class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                               \
            uint8_t class_t::g_initBufferIn1_##name[] = {                                                                                                       \
                '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11               \
            };                                                                                                                                                  \
            uint8_t class_t::g_initBufferIn2_##name[] = {                                                                                                       \
                '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22               \
            };                                                                                                                                                  \
            uint8_t class_t::g_initBufferIn3_##name[] = {                                                                                                       \
                '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33               \
            };                                                                                                                                                  \
            dtyBuffer_t class_t::g_initTextCntnr_##name[] = {                                                                                                   \
                 {g_initBufferIn1, sizeof(g_initBufferIn1_##name)}                                                                                              \
                ,{g_initBufferIn2, sizeof(g_initBufferIn2_##name)}                                                                                              \
                ,{g_initBufferIn3, sizeof(g_initBufferIn3_##name)}                                                                                              \
                };                                                                                                                                              \
            tuiCpltCtnr2StreamFormattedString_t  class_t::g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  (     \
                box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt}),  g_initTextCntnr_##name, sizeof(g_initTextCntnr_##name))


    // sub-section .... pointer definition

    // section end   **** STREAM OF FORMATTED STRINGS UNIT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** <ELEMENT NAME> UNIT *****

    // sub-section .... header definition .....
    // sub-section .... cpp definition .....
    // sub-section .... pointer definition

    // section end   **** <ELEMENT NAME> UNIT *****
    // ****************************************************
    // --------------------------

#endif 	// TUI_CPLT_MACRO_DEF_CTNR_2_STREAM_FORMATTED_STRING_H
