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
 * tuiGrphRealUnit5Win.cpp
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiGrphRealUnit5Win.h"

#define MIN(a,b) (a < b) ? a : b
#define MAX(a,b) (a > b) ? a : b

tuiGrphRealUnit5Win_t::tuiGrphRealUnit5Win_t      (dtyIntfcAbstractUnitFunctional_t* p_pUnit )   :
     tuiGrphAbstUnit4InOut_t       (p_pUnit    )
{}

tuiGrphRealUnit5Win_t::tuiGrphRealUnit5Win_t      (dtyIntfcAbstractUnitFunctional_t* p_pUnit ,box_t p_box    )   :
     tuiGrphAbstUnit4InOut_t       (p_pUnit    ,p_box)
{}

tuiGrphRealUnit5Win_t::tuiGrphRealUnit5Win_t      (dtyIntfcAbstractUnitFunctional_t* p_pUnit ,box_t p_box    ,margins_t p_margin )   :
     tuiGrphAbstUnit4InOut_t       (p_pUnit    ,p_box  ,p_margin)
{}

bool tuiGrphRealUnit5Win_t::init                  (void) 	{
    return true;
}

bool tuiGrphRealUnit5Win_t::init       (dtyIntfcAbstractUnitGraphic_t* p_pParent) 	{
    setParent(p_pParent);
 
    initCoordWin();
    initWin();

    g_status = tuiState_t::undefined;
    g_pUnit->init(this);

    return true;
}




