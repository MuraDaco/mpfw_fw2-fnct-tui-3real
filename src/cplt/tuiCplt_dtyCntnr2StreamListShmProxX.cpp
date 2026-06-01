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
 * tuiCplt_dtyCntnr2StreamListShmProxX.cpp
 *
 *  Created on: Mar, 30th 2025 (Sun)
 *      Author: Marco Dau
 */
 
#include "tuiCplt_dtyCntnr2StreamListShmProxX.h"
#include "pphManager.h"

tuiCplt_dtyCntnr2StreamListShmProxX_t::tuiCplt_dtyCntnr2StreamListShmProxX_t   (void) :
     dtyCntnr1StreamListX_t  (     &g_streamUnit
                                        ,&g_tuiCplt_mmyInt
                                        ,&g_tuiCplt_mmyInt
                                    )
    ,g_streamUnit                   {GET_PTR_BUFFER_PROX_FUNC, PROCESS_MAX_NUMBER   }
{}

