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
 * tuiFnctRealUnit1DgtInOut.h
 *
 *  Created on: Jan, 31st 2025 (Fri)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit1DgtInOut.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiFnctRealUnit1DgtInOut_t::tuiFnctRealUnit1DgtInOut_t      (hwPinPort_t* p_pMcuPinPort    )   :
        tuiFnctAbstUnit0_t           (nullptr)
        ,g_updCnt                   {0}
        ,g_pMcuPinPort              {p_pMcuPinPort}
        ,g_dbgSelect                {false}
    {}

    tuiFnctRealUnit1DgtInOut_t::tuiFnctRealUnit1DgtInOut_t      (const char* p_strName  ,hwPinPort_t* p_pMcuPinPort    )   :
        tuiFnctAbstUnit0_t           (p_strName)
        ,g_pMcuPinPort              {p_pMcuPinPort}
        ,g_dbgSelect                {false}
    {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****
    #define X_PIN_STATUS    0
    #define X_SHM_STATUS    10

    bool tuiFnctRealUnit1DgtInOut_t::init   	            (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->setEventStatus(false);
        return true;
    }

bool tuiFnctRealUnit1DgtInOut_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        if(g_pMcuPinPort->update()) {
            g_updCnt++;
            p_this->fmtStringOnly(X_PIN_STATUS, g_pMcuPinPort->getPinStatusFormattedString(), g_updCnt);
        }
        return true;
    }

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    void tuiFnctRealUnit1DgtInOut_t::clear     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->frameClear();
    }

    void tuiFnctRealUnit1DgtInOut_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->fmtStringOnly(X_PIN_STATUS, g_pMcuPinPort->getPinStatusFormattedString());
        p_this->fmtStringOnly(X_SHM_STATUS, g_pMcuPinPort->getInitStatusFormattedString());
    }

    void tuiFnctRealUnit1DgtInOut_t::display     	    (dtyIntfcAbstractUnitGraphic_t* p_this, [[maybe_unused]] bool p_recursively)  {
        display(p_this);
    }


    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    bool tuiFnctRealUnit1DgtInOut_t::select     	        (dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->fmtStringOnly(tuiState_t::select, X_PIN_STATUS, g_pMcuPinPort->getPinStatusFormattedString());
        p_this->fmtStringOnly(tuiState_t::select, X_SHM_STATUS, g_pMcuPinPort->getInitStatusFormattedString());
        return true;
    }

    bool tuiFnctRealUnit1DgtInOut_t::deSelect   	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->fmtStringOnly(tuiState_t::deselect, X_PIN_STATUS, g_pMcuPinPort->getPinStatusFormattedString());
        p_this->fmtStringOnly(tuiState_t::deselect, X_SHM_STATUS, g_pMcuPinPort->getInitStatusFormattedString());
        return true;
    }

    void tuiFnctRealUnit1DgtInOut_t::eventOn    	        ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        g_pMcuPinPort->tglPin();
        p_this->fmtStringOnly(X_PIN_STATUS, g_pMcuPinPort->getPinStatusFormattedString());
        p_this->fmtStringOnly(X_SHM_STATUS, g_pMcuPinPort->getInitStatusFormattedString());
    }

    bool tuiFnctRealUnit1DgtInOut_t::selectByMouse         ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
        p_this->deselectBackNselect();
        eventOn(p_this);
        p_this->parentDeselectBackNeventOn();
        return true;
    }

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** EVENT HANDLER *****


    //    void tuiFnctRealUnit1DgtInOut_t::vEventHndlKey_home	(dtyIntfcAbstractUnitGraphic_t* p_this)  {
    //        p_this->parentDeselectBackNeventOn();
    //    
    //    }

    // section end   **** EVENT HANDLER *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG FUNCTIONS *****

    void tuiFnctRealUnit1DgtInOut_t::dbgSet                (int32_t p_value)   {
         g_pMcuPinPort->pinRead(0,p_value);
    }

    void tuiFnctRealUnit1DgtInOut_t::dbgSetMode            (bool p_select)   {
        g_dbgSelect = p_select;
    }

    void tuiFnctRealUnit1DgtInOut_t::dbgRefreshValue       (dtyIntfcAbstractUnitGraphic_t* p_this)      {
        // p_this->frameNnameTest(g_strName, g_pDtyMmyInt32->g_pStringValue);
        display(p_this);
    }

    // section end   **** DEBUG FUNCTIONS *****
    // ****************************************************
    // --------------------------
