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
 * tuiGrphRealUnit5Win.h
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 
#ifndef TUI_GRPH_REAL_UNIT_5_WIN_H
#define TUI_GRPH_REAL_UNIT_5_WIN_H

#include "tuiGrphAbstUnit4InOut.h"

class tuiGrphRealUnit5Win_t : public tuiGrphAbstUnit4InOut_t  {

public:

    tuiGrphRealUnit5Win_t        (dtyIntfcAbstractUnitFunctional_t* p_pUnit = nullptr);
    tuiGrphRealUnit5Win_t        (dtyIntfcAbstractUnitFunctional_t* p_pUnit ,box_t p_box    );
    tuiGrphRealUnit5Win_t        (dtyIntfcAbstractUnitFunctional_t* p_pUnit ,box_t p_box    ,margins_t p_margin);


    // --------------------- Process section - START
    bool init                   (void)      override;
    bool init                   (dtyIntfcAbstractUnitGraphic_t* p_pParent)       override;
    // bool initChildren           (void)      override;
    // --------------------- Process section - START


};


#endif 	// TUI_GRPH_REAL_UNIT_5_WIN_H
