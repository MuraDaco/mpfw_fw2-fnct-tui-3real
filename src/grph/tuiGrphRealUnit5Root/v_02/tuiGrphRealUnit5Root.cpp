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
 * tuiGrphRealUnit5Root.cpp
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiGrphRealUnit5Root.h"

#include <iostream>
#include <stdexcept>


tuiGrphRealUnit5Root_t::tuiGrphRealUnit5Root_t      (dtyIntfcAbstractUnitFunctional_t* p_pUnit) :
     tuiGrphAbstUnit4InOut_t       (p_pUnit    )
{}

tuiGrphRealUnit5Root_t::tuiGrphRealUnit5Root_t      (dtyIntfcAbstractUnitFunctional_t* p_pUnit ,box_t p_box    ) :
     tuiGrphAbstUnit4InOut_t       (p_pUnit    ,p_box  )
{}

tuiGrphRealUnit5Root_t::tuiGrphRealUnit5Root_t      (dtyIntfcAbstractUnitFunctional_t* p_pUnit                 ,margins_t p_margin) :
     tuiGrphAbstUnit4InOut_t       (p_pUnit            ,p_margin)
{}

#define RECURSIVE_DISPLAY       true
#define NOT_RECURSIVE_DISPLAY   false

bool tuiGrphRealUnit5Root_t::init       (void) 	{
    // 1. init TUI environment
    setParent(nullptr);

    initGraphEnv();
    initGraphEnvColor();

    initWinRootDims();
    initBoundsWinRoot();

    if(g_pUnit) {

                            // try { 
                            //     throw 11; 
                            // } catch (int i) {
                            //     std::cout << " the integer exception was caught, with value: " << i << '\n';
                            //     std::exit(i);
                            // }

        // init its unit "friend"
        // 2.a init children and nephew graphic unit (recursive procedure)
        g_pUnit->init(this);

                            // try { 
                            //     throw 12; 
                            // } catch (int i) {
                            //     std::cout << " the integer exception was caught, with value: " << i << '\n';
                            //     std::exit(i);
                            // }
        // 2.b activate the handler event array of the current root window
        selectNeventOnInit();
        g_pUnit->eventOn(this);

        // 4. display children and nephew graphic unit (recursive procedure) 
        g_pUnit->display(this, true);
    }


    return true;

}

bool tuiGrphRealUnit5Root_t::init       ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_pParent) 	{
    return false;
}


bool tuiGrphRealUnit5Root_t::loop            (void)  {
    bool l_result = true;
    tuiEventCode_t l_handlerEventCode = tuiEventCode_t::noEvent;

    g_pUnit->loop(this);

    if(uiEventStatus())   {
        int l_uiEventKeyCode = uiEventKeyCode();
        if((TUI_KEY_CTRL_Q == l_uiEventKeyCode) || (TUI_KEY_CTRL_X == l_uiEventKeyCode) ){
            l_result = false;
            deinitGraphEnv();
        } else {
            l_handlerEventCode = uiHandlerEventCode();
        }
    }

    if(
            (tuiEventCode_t::noEvent != l_handlerEventCode)
        &&  (tuiEventCode_t::mouse   <= l_handlerEventCode)
    ) {
        if(uiMouseEventStatus())
        {

            if(uiMouseEventCode_ButtonPressed())
            {
                if(!g_pUnit->clickingChild(this)) {
                    deselectBackNeventOn();
                }
            } else {
                if(tuiEventCode_t::mouse < l_handlerEventCode)  {
                    g_eventMouseArray[tuiEventCodeNum(l_handlerEventCode) - (static_cast<uint8_t>(tuiEventCode_t::mouse)+1)](static_cast<tuiGrphAbstUnit3Event_t*>(g_poEventOn));
                    
                }
            }

        }
    } else {
        if(tuiEventCode_t::noEvent != l_handlerEventCode)   {
            g_eventKeyArray[tuiEventCodeNum(l_handlerEventCode)](static_cast<tuiGrphAbstUnit3Event_t*>(g_poEventOn));
        }
    }

    return l_result;
}


void tuiGrphRealUnit5Root_t::end 	        (void)      {
    endGraphEnv();
}

void tuiGrphRealUnit5Root_t::refreshWinChildren       (void)  {
    g_pUnit->displayChildren(this, false);
}


