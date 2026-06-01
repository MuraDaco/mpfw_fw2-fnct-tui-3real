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
 * tuiCplt_MacroDefCplx3McuUsart.h
 *
 *  Created on: Feb, 18th 2025 (Tue)
 *      Author: Marco Dau
 */
 


#ifndef TUI_CPLT_MACRO_DEF_CPLX_3_MCU_USART_H
#define TUI_CPLT_MACRO_DEF_CPLX_3_MCU_USART_H

// ****************************************************
// section start **** STREAM/BUFFER OF FORMATTED STRINGS UNIT *****

    // sub-section .... header definition .....
        #define TUI_DEF_H___CPLT_CPLX_MCU_USART_UU( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt  )                                                \
            static tuiCpltCplx4McuUsartUU_t  g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

        #define TUI_DEF_H___CPLT_CPLX_MCU_USART_XX( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt  )                                                \
            static tuiCpltCplx3McuUsartXX_t  g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

        #define TUI_DEF_H___CPLT_CPLX_MCU_USART( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt  )                                                \
            static tuiCpltCplx3McuUsartX_t  g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt


        #define TUI_DEF_H___CPLX_MCU_USART( typeGrph_t, typeFnct_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                               \
            /* tuiGHrph objects object instances that compose the complex module McuUsart */                                                                \
            /* 1. tuiGrph receiving box object */                                                                                                           \
            static  uint8_t g_mcuUstart_initBufferIn1[];                                                                                                    \
            static  uint8_t g_mcuUstart_initBufferIn2[];                                                                                                    \
            static  uint8_t g_mcuUstart_initBufferIn3[];                                                                                                    \
            static  dtyBuffer_t g_mcuUstart_initTextCntnr[];                                                                                                \
            static  uint8_t g_mcuUstart_stringBuffer[1000000];                                                                                              \
            static  tuiFnctRealUnit1FormattedStringCntnr_t    g_mcuUstart_cntnrStreamString;                                                                \
            static  tuiGrphRealUnit5Base_t      g_mcuUstart_cntnrStreamGraphicUnit;                                                                         \
            static  tuiFnctRealUnit2Cntnr_t     g_recevingDataBox;                                                                                          \
            static  dtyCntnr1StreamList_t       g_recevingDataCntnr;                                                                                        \
            static  tuiGrphRealUnit5Base_t      g_recevingDataBoxGrph;                                                                                      \
            /* 2. tuiGrph transmitting box object */                                                                                                        \
            static  char                        g_sendingDataBuffer[];                                                                                      \
            static  dtyBaseArray_t              g_sendingData;                                                                                              \
            static  tuiFnctRealUnit1Ebox_t      g_sendingDataBox;                                                                                           \
            static  tuiGrphRealUnit5Base_t      g_sendingDataBoxGrph;                                                                                       \
            /* array of tuiGrph objects that compose the complex module McuUsart */                                                                         \
            static  dtyIntfcAbstractUnitGraphic_t*  g_boxesArray[];                                                                                         \
            /* container object that is associated to previous defined array */                                                                             \
            static  dtyCntnr1ArrayTuiList_t         g_unitBoxesCntnr;                                                                                       \
            /*  */                                                                                                                                          \
            static  typeFnct_t     g_tuiFnct_##name;                                                                                                        \
            static  typeGrph_t          g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

    // sub-section .... cpp definition .....

        #define TUI_DEF_CPP_CPLT_CPLX_MCU_USART_UU( class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt, ... )                                    \
            tuiCpltCplx4McuUsartUU_t  class_t::g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt     (          \
                box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                                                                      \
                , __VA_ARGS__                                                                                                                               \
            )

        #define TUI_DEF_CPP_CPLT_CPLX_MCU_USART_XX( class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt, ... )                                    \
            tuiCpltCplx3McuUsartXX_t  class_t::g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt     (          \
                box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                                                                      \
                , __VA_ARGS__                                                                                                                               \
            )

        #define TUI_DEF_CPP_CPLT_CPLX_MCU_USART( class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt, ... )                                    \
            tuiCpltCplx3McuUsartX_t  class_t::g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt     (          \
                box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                                                                      \
                , __VA_ARGS__                                                                                                                               \
            )

        #define TUI_DEF_CPP_CPLX_MCU_USART(typeGrph_t, typeFnct_t, class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt, ... )                  \
        /* tuiGrph objects instances that compose the complex module McuUsart */                                                                            \
        /* 1. tuiGrph receiving box object */                                                                                                               \
        uint8_t class_t::g_mcuUstart_initBufferIn1[] = {                                                                                                    \
            '1', '1', '1', '1', '1', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
            0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x11,0x11,0x11,0x11               \
        };                                                                                                                                                  \
        uint8_t class_t::g_mcuUstart_initBufferIn2[] = {                                                                                                    \
            '2', '2', '2', '2', '2', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
            0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x22,0x22,0x22,0x22               \
        };                                                                                                                                                  \
        uint8_t class_t::g_mcuUstart_initBufferIn3[] = {                                                                                                    \
            '3', '3', '3', '3', '3', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5',               \
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',               \
            0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x33,0x33,0x33,0x33               \
        };                                                                                                                                                  \
        dtyBuffer_t class_t::g_mcuUstart_initTextCntnr[] = {                                                                                                \
             {g_initBufferIn1, sizeof(g_mcuUstart_initBufferIn1)}                                                                                           \
            ,{g_initBufferIn2, sizeof(g_mcuUstart_initBufferIn2)}                                                                                           \
            ,{g_initBufferIn3, sizeof(g_mcuUstart_initBufferIn3)}                                                                                           \
            };                                                                                                                                              \
        uint8_t                                 class_t::g_mcuUstart_stringBuffer[1000000];                                                                 \
        tuiFnctRealUnit1FormattedStringCntnr_t  class_t::g_mcuUstart_cntnrStreamString;                                                                     \
        tuiGrphRealUnit5Base_t                  class_t::g_mcuUstart_cntnrStreamGraphicUnit  (&g_mcuUstart_cntnrStreamString, box_t({8, 0, 0,  0}) );       \
        dtyCntnr1StreamList_t                   class_t::g_recevingDataCntnr     (                                                                          \
                g_stringBuffer          ,sizeof(g_mcuUstart_stringBuffer)                                                                                   \
                ,g_initUsartTextCntnr   ,sizeof(g_mcuUstart_initTextCntnr)                                                                                  \
                ,&g_mcuUstart_cntnrStreamString                                                                                                             \
                ,&g_mcuUstart_cntnrStreamGraphicUnit );                                                                                                     \
        tuiFnctRealUnit2Cntnr_t                 class_t::g_recevingDataBox       ("Receving data box", &g_recevingDataCntnr);                               \
        tuiGrphRealUnit5Base_t                  class_t::g_recevingDataBoxGrph   (&g_recevingDataBox ,  9);                                                 \
        /* 2. tuiGrph transmitting box object */                                                                                                            \
        char                            class_t::g_sendingDataBuffer[] = {"inserire il messaggio da inviare"};                                              \
        dtyBaseArray_t                  class_t::g_sendingData           (g_sendingDataBuffer, sizeof(g_sendingDataBuffer));                                \
        tuiFnctRealUnit1Ebox_t          class_t::g_sendingDataBox        ("Sending data box", g_sendingData);                                               \
        tuiGrphRealUnit5Base_t          class_t::g_sendingDataBoxGrph    (&g_sendingDataBox  ,  3);                                                         \
        /* array of tuiGrph objects that compose the complex module McuUsart */                                                                             \
        dtyIntfcAbstractUnitGraphic_t*  class_t::g_boxesArray[] =   {                                                                                       \
             &g_recevingDataBoxGrph                                                                                                                         \
            ,&g_sendingDataBoxGrph                                                                                                                          \
            ,nullptr                                                                                                                                        \
        };                                                                                                                                                  \
        /* container object that is associated to previous defined array */                                                                                 \
        dtyCntnr1ArrayTuiList_t         class_t::g_unitBoxesCntnr        (g_boxesArray);                                                                    \
        typeFnct_t     class_t::g_tuiFnct_##name    (                                                                                                       \
            /* pphUsartRs485_t*               */     __VA_ARGS__                                                                                                 \
            /* dtyCntnr1StreamList_t*    */     ,&g_recevingDataCntnr                                                                                       \
            /* char*                     */     ,g_sendingDataBuffer                                                                                        \
            /* tuiFnctRealUnit1Ebox_t*   */     ,&g_sendingDataBox                                                                                          \
            /* dtyCntnr1ArrayTuiList_t*  */     ,&g_unitBoxesCntnr );                                                                                       \
        typeGrph_t class_t::g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  (                               \
            &g_tuiFnct_##name, box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt}) )

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

#endif 	// TUI_CPLT_MACRO_DEF_CPLX_3_MCU_USART_H
