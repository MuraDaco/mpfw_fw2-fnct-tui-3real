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
 * tuiCplt_MacroDefUnit1Debug.h
 *
 *  Created on: Feb, 24th 2025 (Mon)
 *      Author: Marco Dau
 */
 


#ifndef TUI_MACRO_DEF_UNIT_1_DEBUG_H
#define TUI_MACRO_DEF_UNIT_1_DEBUG_H

// ****************************************************
// section start **** SIMPLY UNIT *****

    // sub-section .... header definition .....
        #define TUI_DEF_H___UNIT(typeGrph_t, typeFnct_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                           \
            static  typeFnct_t g_tuiFnct_##name;                                                                                            \
            static  typeGrph_t g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt
        #define TUI_DEF_H___UNIT_GRPH(typeGrph_t, typeFnct_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                      \
            static  typeGrph_t g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt
    // sub-section .... cpp definition .....
        #define TUI_DEF_CPP_UNIT(typeGrph_t, typeFnct_t, class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                  \
                    typeFnct_t class_t::g_tuiFnct_##name      (#name);                                                                      \
                    typeGrph_t class_t::g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  (   \
                        &g_tuiFnct_##name, box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                           \
                    )
        #define TUI_DEF_CPP_UNIT_GRPH(typeGrph_t, typeFnct_t, class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)             \
                    typeGrph_t class_t::g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  (   \
                        &g_tuiFnct_##name, box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                           \
                    )
        #define TUI_DEF_CPP_UNIT_PAR(typeGrph_t, typeFnct_t, class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt, ... )        \
                    typeFnct_t class_t::g_tuiFnct_##name      ( __VA_ARGS__ );                                                              \
                    typeGrph_t class_t::g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  (   \
                        &g_tuiFnct_##name, box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                           \
                    )
    // sub-section .... pointer definition
        #define TUI_PTR_UNIT(parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                                                       \
                    &g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  

        #define TUI_PTR_CPLT(parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                                                       \
                    &g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  

    // section end   **** SIMPLY UNIT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** ROOT WINDOW UNIT *****

    // sub-section .... header definition .....
        #define TUI_DEF_H___WINDOW_ROOT(typeGrph_t, typeFnct_t, name)                                           \
            static  dtyIntfcAbstractUnitGraphic_t* g_tuiArry_root_##name[];                                     \
            static  typeFnct_t g_tuiFnct_root_##name;                                                           \
            static  typeGrph_t g_tuiGrph_root_##name
    // sub-section .... cpp definition .....
        #define TUI_DEF_CPP_WINDOW_ROOT(typeGrph_t, typeFnct_t, class_t, name, top, btm, lft, rgt, ... )        \
                    dtyIntfcAbstractUnitGraphic_t* class_t::g_tuiArry_root_##name[] = { __VA_ARGS__ nullptr};   \
                    typeFnct_t class_t::g_tuiFnct_root_##name      (#name, g_tuiArry_root_##name);              \
                    typeGrph_t class_t::g_tuiGrph_root_##name  (                                                \
                        &g_tuiFnct_root_##name, margins_t({top, btm, lft, rgt})                                 \
                    )
    // section end   **** ROOT WINDOW UNIT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** WINDOW UNIT *****

    // sub-section .... header definition .....
        #define TUI_DEF_H___WINDOW(typeGrph_t, typeFnct_t, disposition, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                \
            static  dtyIntfcAbstractUnitGraphic_t* g_tuiArry_##parent_wnd_name##_##name[];                                                      \
            static  dtyCntnr1ArrayTui##disposition g_dtyCntnr_##parent_wnd_name##_##name;                                                       \
            static  typeFnct_t g_tuiFnct_##parent_wnd_name##_##name;                                                                            \
            static  typeGrph_t g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt
    // sub-section .... cpp definition .....
        #define TUI_DEF_CPP_WINDOW(typeGrph_t, typeFnct_t, disposition, class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt, ... ) \
                    dtyIntfcAbstractUnitGraphic_t* class_t::g_tuiArry_##parent_wnd_name##_##name[] = { __VA_ARGS__ nullptr};                    \
                    dtyCntnr1ArrayTui##disposition class_t::g_dtyCntnr_##parent_wnd_name##_##name (g_tuiArry_##parent_wnd_name##_##name);       \
                    typeFnct_t class_t::g_tuiFnct_##parent_wnd_name##_##name      (#name, &g_dtyCntnr_##parent_wnd_name##_##name);              \
                    typeGrph_t class_t::g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  (       \
                        &g_tuiFnct_##parent_wnd_name##_##name, box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                           \
                    )
    // sub-section .... pointer definition
        #define TUI_PTR_WINDOW(parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                                                         \
                    &g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  
    // section end   **** WINDOW UNIT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STREAM/BUFFER OF FORMATTED STRINGS UNIT *****

    // sub-section .... header definition .....
        #define TUI_DEF_H___STREAM_FRMTD_STR(typeGrph_t, typeFnct_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                   \
            static typeGrph_t   g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt;                 \
            static tuiFnctRealUnit2Cntnr_t  g_tuiFnct_##name;                                                                                   \
                static dtyCntnr1StreamList_t g_cntrStreamData_2;                                                                                \
                    static uint8_t                  g_stringBuffer[1000000];                                                                    \
                    static dtyBuffer_t              g_initUsartTextCntnr[];                                                                     \
                        static uint8_t                  g_initBufferIn1[];                                                                      \
                        static uint8_t                  g_initBufferIn2[];                                                                      \
                        static uint8_t                  g_initBufferIn3[];                                                                      \
                    static tuiGrphRealUnit5Base_t          g_cntnrStreamGraphicUnit;                                                            \
                        static tuiFnctRealUnit1FormattedStringCntnr_t    g_cntnrStreamString

        #define TUI_DEF_H___STREAM_FRMTD_STR_SEC_STC           \
            static dtyBuffer_t              g_initUsartTextCntnr[];                                                                             \
                static uint8_t                  g_initBufferIn1[];                                                                              \
                static uint8_t                  g_initBufferIn2[];                                                                              \
                static uint8_t                  g_initBufferIn3[]

        #define TUI_DEF_H___STREAM_FRMTD_STR_SEC_DYN(name)                                                                              \
            uint8_t                  g_stringBuffer[1000000];                                                                            \
            tuiFnctRealUnit1FormattedStringCntnr_t    g_cntnrStreamString;                                                               \
            tuiGrphRealUnit5Base_t      g_cntnrStreamGraphicUnit;                                                                   \
            dtyCntnr1StreamList_t       g_recevingDataCntnr;                                                                                   \
            tuiFnctRealUnit2Cntnr_t     g_tuiFnct_##name;                                                                                  \
            tuiGrphRealUnit5Base_t      g_##name

    // sub-section .... cpp definition .....
        #define TUI_DEF_CPP_STREAM_FRMTD_STR(typeGrph_t, typeFnct_t, class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)              \
            uint8_t tuiGrphZAppMain_t::g_initBufferIn1[] = {                                                                                        \
                '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',   \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',   \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11   \
            };                                                                                                                                      \
            uint8_t tuiGrphZAppMain_t::g_initBufferIn2[] = {                                                                                        \
                '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',   \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',   \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22   \
            };                                                                                                                                      \
            uint8_t tuiGrphZAppMain_t::g_initBufferIn3[] = {                                                                                        \
                '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',   \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',   \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33   \
            };                                                                                                                                      \
            dtyBuffer_t tuiGrphZAppMain_t::g_initUsartTextCntnr[] = {                                                                               \
                 {g_initBufferIn1, sizeof(g_initBufferIn1)}                                                                                         \
                ,{g_initBufferIn2, sizeof(g_initBufferIn2)}                                                                                         \
                ,{g_initBufferIn3, sizeof(g_initBufferIn3)}                                                                                         \
                };                                                                                                                                  \
            uint8_t tuiGrphZAppMain_t::g_stringBuffer[1000000];                                                                                     \
            typeGrph_t class_t::g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  (                   \
                &g_tuiFnct_##name, box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                                           \
            );                                                                                                                                      \
            tuiFnctRealUnit2Cntnr_t  tuiGrphZAppMain_t::g_tuiFnct_##name   ("New Text Usart 2", &g_cntrStreamData_2);                               \
                dtyCntnr1StreamList_t tuiGrphZAppMain_t::g_cntrStreamData_2     (                                                                   \
                        g_stringBuffer          ,sizeof(g_stringBuffer)                                                                             \
                        ,g_initUsartTextCntnr   ,sizeof(g_initUsartTextCntnr)                                                                       \
                        ,&g_cntnrStreamString                                                                                                       \
                        ,&g_cntnrStreamGraphicUnit);                                                                                                \
                    tuiGrphRealUnit5Base_t      tuiGrphZAppMain_t::g_cntnrStreamGraphicUnit  (&g_cntnrStreamString, box_t({8, 0, 0,  0}));          \
                        tuiFnctRealUnit1FormattedStringCntnr_t      tuiGrphZAppMain_t::g_cntnrStreamString

        #define TUI_DEF_CPP_STREAM_FRMTD_STR_SEC_STC(class_t)                                                                                 \
            uint8_t class_t::g_initBufferIn1[] = {                                                                                                  \
                '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',   \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',   \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11   \
            };                                                                                                                                      \
            uint8_t class_t::g_initBufferIn2[] = {                                                                                                  \
                '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',   \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',   \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22   \
            };                                                                                                                                      \
            uint8_t class_t::g_initBufferIn3[] = {                                                                                                  \
                '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',   \
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',   \
                0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33   \
            };                                                                                                                                      \
            dtyBuffer_t class_t::g_initUsartTextCntnr[] = {                                                                                         \
                 {g_initBufferIn1, sizeof(g_initBufferIn1)}                                                                                         \
                ,{g_initBufferIn2, sizeof(g_initBufferIn2)}                                                                                         \
                ,{g_initBufferIn3, sizeof(g_initBufferIn3)}                                                                                         \
                };                                                                                                                                  \

        #define TUI_DEF_CPP_STREAM_FRMTD_STR_SEC_DYN(name)                              \
            g_cntnrStreamGraphicUnit  (&g_cntnrStreamString, box_t({8, 0, 0,  0}) )     \
            ,g_recevingDataCntnr     (                                                   \
                    g_stringBuffer          ,sizeof(g_stringBuffer)                     \
                    ,g_initUsartTextCntnr   ,sizeof(g_initUsartTextCntnr)               \
                    ,&g_cntnrStreamString                                               \
                    ,&g_cntnrStreamGraphicUnit \
            )                                         \
            ,g_tuiFnct_##name   (#name, &g_recevingDataCntnr)                            \
            ,g_##name   (                                                       \
                &g_tuiFnct_##name, box_t({8, 0, 0,  0})                                \
            )

    // sub-section .... pointer definition

    // section end   **** STREAM/BUFFER OF FORMATTED STRINGS UNIT *****
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

#endif 	// TUI_MACRO_DEF_UNIT_1_DEBUG_H
