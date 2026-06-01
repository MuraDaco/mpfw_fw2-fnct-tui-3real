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
 * tuiCpltCplx3McuUsartXX.md
 *
 *  Created on: Feb,  20th 2025 (Thu)
 *      Author: Marco Dau
 
    - [class]
        - <input_par><class interface>/<class real>
        - {inside_par}{class}
        - [der]->[class]
            - <input_par><class interface>/<class real>
            - {inside_par}{class}
            - [der]->[class]

    - [tuiCpltCplx3McuUsartXX]
        - <input_par><box_t>
            - destination
                - parent class initialization [tuiGrphRealUnit5Base_t]
        - <input_par><margins_t>
            - destination
                - parent class initialization [tuiGrphRealUnit5Base_t]
        - <input_par><pphUsart_t*>
            - destination
                - parent/deriving class initialization [tuiFnctRealCplx3McuUsartXX_t]
        - {inside_par}{tuiCplt_dtyCntnr2StreamListFStrX_t}      -> {g_dty_recevingDataCntnr}
            - description:
                - [tuiCplt_dtyCntnr2StreamListFStrX_t]
                    - <input_par><no parameters>
                    - {inside_par}{dtyCntnr1StreamUnitStringV1_t}            -> {g_streamUnit}
                        - destination
                            - parent/deriving class initialization [dtyCntnr1StreamListX_t]
                    - {inside_par}{tuiCpltUnit1FormattedStringCntnr_t}  -> {g_tuiCplt_formattedString}
                        - destination
                            - parent/deriving class initialization [dtyCntnr1StreamListX_t]
                    - [der]->[dtyCntnr1StreamListX_t]
                        - <input_par><dtyCntnr0StreamUnitIntfc_t*>
                        - <input_par><dtyIntfcAbstractUnitFunctional_t*>
                        - <input_par><dtyIntfcAbstractUnitGraphic_t*>
                        - {inside_par}{class}
                        - [der]->[class]
            - derived from:
                - [dtyCntnr1StreamListX_t]
            - destination:
                - parent/deriving class initialization [tuiFnctRealCplx3McuUsartXX_t]
                - inside [g_tui_receivingDataBox] object initialization
        - {inside_par}{tuiCpltCtnr2StreamFormattedStringX_t}    -> {g_tui_receivingDataBox}
            - destination:
                - inside [g_boxesArray[3]] array
            - derived from:
                - [tuiFnctRealUnit2Cntnr_t]
                    - [tuiFnctAbstUnit1Cntr_t]
                - [tuiGrphRealUnit5Base_t]
                    - [tuiGrphAbstUnit4InOut_t]
                        - ...
                            - [dtyIntfcAbstractUnitGraphic_t]
        - {inside_par}{char[]}                                  -> {g_char_sendingDataBuffer[300]}
        - {inside_par}{tuiCpltUnit1Ebox_t}                      -> {g_tui_sendingDataBox}
            - destination:
                - parent/deriving class initialization [tuiFnctRealCplx3McuUsartXX_t]
                - inside [g_boxesArray[3]] array
            - derived from:
                - [tuiFnctRealUnit1Ebox_t]
                - [tuiGrphRealUnit5Base_t]
                    - [tuiGrphAbstUnit4InOut_t]
                        - ...
                            - [dtyIntfcAbstractUnitGraphic_t]
        - {inside_par}{dtyIntfcAbstractUnitGraphic_t[]}         -> {g_boxesArray[3]}
            - destination:
                - parent/deriving class initialization [tuiFnctRealCplx3McuUsartXX_t]
                - inside [g_dty_boxesCntnr] container class
        - {inside_par}{dtyCntnr1ArrayTuiList_t}                 -> {g_dty_boxesCntnr}
            - destination:
                - parent/deriving class initialization [tuiFnctRealCplx3McuUsartXX_t]
        - [der]->[tuiFnctRealCplx3McuUsartXX_t]
            - <input_par><pphUsart_t*>
            - <input_par><dtyCntnr1StreamListX_t*>  <- &<g_dty_recevingDataCntnr>
            - <input_par><char*>                    <- <g_char_sendingDataBuffer>
            - <input_par><tuiFnctRealUnit1Ebox_t*>  <- &<g_tui_sendingDataBox>
            - <input_par><dtyCntnr1ArrayTuiList_t*> <- &<g_dty_boxesCntnr>
            - {inside_par}{pphUsart_t*}
            - {inside_par}{uint8_t*}
            - {inside_par}{dtyCntnr1StreamListX_t*}
            - {inside_par}{char*}
            - {inside_par}{tuiFnctRealUnit1Ebox_t*}
            - [der]->[tuiFnctRealUnit2Cntnr_t]
                - <input_par><dtyCntnr0BaseUnit_t*> <- <dtyCntnr1ArrayTuiList_t*> <- &<g_dty_boxesCntnr>
                - {inside_par}{class}
                - [der]->[class]
        - [der]->[tuiGrphRealUnit5Base_t]
            - <input_par><class>
            - {inside_par}{class}
            - [der]->[class]

 */
