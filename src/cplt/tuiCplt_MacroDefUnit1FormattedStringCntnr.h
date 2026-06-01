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
 * tuiCplt_MacroDefUnit1FormattedStringCntnr.h
 *
 *  Created on: Feb, 20th 2025 (Thu)
 *      Author: Marco Dau
 */
 


#ifndef TUI_CPLT_MACRO_DEF_UNIT_1_FORMATTED_STRING_CNTNR_H
#define TUI_CPLT_MACRO_DEF_UNIT_1_FORMATTED_STRING_CNTNR_H

// ****************************************************
// section start **** FORMATTED STRINGS UNIT *****

    // sub-section .... header definition .....
        #define TUI_DEF_H___GRPH_UNIT_FORMATTED_STRING_CNTNR( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                         \
            static char g_fmtString_##name[150];                                                                                                \
            static dtyString_t  g_dtyString_##name;                                                                                             \
            static tuiFnctRealUnit1FormattedStringCntnr_t g_tuiFnct_##name;                                                                     \
            static tuiGrphRealUnit5Base_t g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt  

        #define TUI_DEF_H___GRPH_UNIT_FORMATTED_STRING_CNTNR_PAR( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                     \
            static dtyString    g_dtyString_##name;                                                                                             \
            static tuiFnctRealUnit1FormattedStringCntnr_t     g_tuiFnct_##name;                                                                 \
            static tuiGrphRealUnit5Base_t   g_tuiGrph_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

        #define TUI_DEF_H___CPLT_UNIT_FORMATTED_STRING_CNTNR( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                                     \
            static char g_fmtString_##name[150];                                                                                                            \
            static tuiCpltUnit1FormattedStringCntnr_t  g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

        #define TUI_DEF_H___CPLT_UNIT_FORMATTED_STRING_CNTNR_PAR( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt)                                  \
            static tuiCpltUnit1FormattedStringCntnr_t  g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

    // sub-section .... cpp definition .....
        #define TUI_DEF_CPP_CPLT_UNIT_FORMATTED_STRING_CNTNR( class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                                \
            char class_t::g_fmtString_##name[150] = "test formatted string container";                                                                          \
            tuiCpltUnit1FormattedStringCntnr_t  class_t::g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt     (   \
                box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                                                                          \
                ,g_fmtString_##name, sizeof(g_fmtString_##name)                                                                                                 \
            )

        #define TUI_DEF_CPP_CPLT_UNIT_FORMATTED_STRING_CNTNR_PAR( class, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt, ... )                         \
            tuiCpltUnit1FormattedStringCntnr_t  class_t::g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt     (   \
                box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                                                                          \
                , __VA_ARGS__                                                                                                                                   \
            )


    // sub-section .... pointer definition

    // section end   **** FORMATTED STRINGS UNIT *****
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

#endif 	// TUI_CPLT_MACRO_DEF_UNIT_1_FORMATTED_STRING_CNTNR_H
