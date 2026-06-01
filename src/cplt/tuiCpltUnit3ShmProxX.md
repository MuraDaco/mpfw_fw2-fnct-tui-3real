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
 * tuiCpltUnit3ShmProx.md
 *
 *  Created on: Mar, 16th 2025 (Sun)
 *      Author: Marco Dau

    - [class]
        - <input_par><class interface>/<class real>
        - {inside_par}{class}
        - [der]->[class]
            - <input_par><class interface>/<class real>
            - {inside_par}{class}
            - [der]->[class]

    - [tuiCpltUnit3ShmProxX]
        - <input_par><box_t>
            - destination
                - to  [der]->[tuiGrphRealUnit5Base_t]
        - <input_par><margins_t>
            - destination
                - to  [der]->[tuiGrphRealUnit5Base_t]
        - {inside_par}{tuiCplt_dtyCntnr2StreamListShmProxX_t} -> [derived_from]{dtyCntnr0BaseUnit_t}
            - scope:
            - description:
                - [tuiCplt_dtyCntnr2StreamListShmProxX]
                    - <input_par><no parameters>
                    - {inside_par}{dtyCntnr1StreamUnitShmProx_t} -> [derived_from]-[dtyCntnr0StreamUnitIntfc_t]       -> {g_streamUnit}
                        - scope
                            - it implements the stream block data protocol
                        - description   
                            - [dtyCntnr1StreamUnitShmProx_t]
                                - <input_par><void*>        -> <p_pBufIn>       
                                - <input_par><uint32_t>     -> <p_bufInSize>    
                                - {inside_par}{shm_process_struct_t*} -> {g_pBuf} <- <p_pBufIn>
                                - [der]->[class]
                    - {inside_par}{tuiCpltUnit1MmyInt_t}         -> [derived_from]-[dtyIntfcAbstractUnitFunctional_t] -> {g_tuiCplt_mmyInt}    
                        - scope
                            - it is a [tuiFnct] module to display the elements of container
                        - description
                            - [tuiCpltUnit1MmyInt_t]
                                - <input_par><no parameters>
                                - {inside_par}{dtyUnit1MmyInt32_t} -> {g_loopDtyData}
                                    - destination
                                        - to [der]->[tuiFnctRealUnit1MmyInt_t]
                                - [der]->[tuiFnctRealUnit1MmyInt_t]
                                - [der]->[tuiGrphRealUnit5Base_t]
                    - [der]->[dtyCntnr1StreamListX_t]
                        - <input_par><dtyCntnr0StreamUnitIntfc_t*>          -> <p_streamUnit>      <- &{g_streamUnit}          
                        - <input_par><dtyIntfcAbstractUnitFunctional_t*>    -> <p_loopTuiUnit>     <- &{g_tuiCplt_mmyInt}       
                        - <input_par><dtyIntfcAbstractUnitGraphic_t*>       -> <p_loopTuiGraphic>  <- &{g_tuiCplt_mmyInt}   
                        - {inside_par}{dtyCntnr0StreamUnitIntfc_t*}         -> {g_streamUnit}
                        - {inside_par}{dtyIntfcAbstractUnitFunctional_t*}   -> {g_loopTuiUnit}
                        - {inside_par}{dtyIntfcAbstractUnitGraphic_t*}      -> {g_loopTuiGraphic}
                        - [der]->[dtyCntnr0BaseUnit_t]
            - destination:
                - to [der]->[tuiFnctRealUnit2Cntnr_t]
        - [der]->[tuiFnctRealUnit2Cntnr_t]
            - <input_par><dtyCntnr0BaseUnit_t*>
            - {inside_par}{class}
            - [der]->[class]
        - [der]->[tuiGrphRealUnit5Base_t]

 */
