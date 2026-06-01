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
 * tuiCplt_MacroDefUnit3ShmProxX.h
 *
 *  Created on: Apr, 3rd 2025 (Thu)
 *      Author: Marco Dau
 */
 


#ifndef TUI_CPLT_MACRO_DEF_UNIT_3_SHM_PROX_X_H
#define TUI_CPLT_MACRO_DEF_UNIT_3_SHM_PROX_X_H

// ****************************************************
// section start **** STREAM/BUFFER OF FORMATTED STRINGS UNIT *****

    // sub-section .... header definition .....
        #define TUI_DEF_H___CPLT_UNIT_3_SHM_PROX_X( parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt  )                                            \
            static tuiCpltUnit3ShmProxX_t  g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt

    // sub-section .... cpp definition .....

        #define TUI_DEF_CPP_CPLT_UNIT_3_SHM_PROX_X( class_t, parent_wnd_name, h, w, y0, x0, name, top, btm, lft, rgt )                                    \
            tuiCpltUnit3ShmProxX_t  class_t::g_tuiCplt_##parent_wnd_name##_##h##_##w##_##y0##_##x0##_##name##_##top##_##btm##_##lft##_##rgt     (          \
                box_t({h, w, y0, x0}), margins_t({top, btm, lft, rgt})                                                                                      \
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

#endif 	// TUI_CPLT_MACRO_DEF_UNIT_3_SHM_PROX_X_H
