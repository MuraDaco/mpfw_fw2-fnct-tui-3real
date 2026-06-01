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
 
#ifndef TUI_FNCT_REAL_UNIT_1_DGT_IN_OUT_H
#define TUI_FNCT_REAL_UNIT_1_DGT_IN_OUT_H

#include "tuiFnctAbstUnit0.h"
#include "hwPinPort.h"

#include "dtyIntfcAbstractUnitGraphic.h"


class tuiFnctRealUnit1DgtInOut_t :    public tuiFnctAbstUnit0_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiFnctRealUnit1DgtInOut_t       (hwPinPort_t* p_pMcuPinPort   );
    tuiFnctRealUnit1DgtInOut_t       (const char* p_strName  ,hwPinPort_t* p_pMcuPinPort   );

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    protected:
    bool init   	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool loop   	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    uint32_t g_updCnt;
    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DISPLAY *****

    protected:
    void clear                  (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void display                (dtyIntfcAbstractUnitGraphic_t* p_this, bool p_recursively) override;

    // section end   **** DISPLAY *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** STATE MANAGEMENT *****

    protected:
    bool select     	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool deSelect   	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    void eventOn    	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    bool selectByMouse 	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    // section end   **** STATE MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** EVENT HANDLER *****

    // void vEventHndlKey_down	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void vEventHndlKey_up	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void vEventHndlKey_left	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void vEventHndlKey_right	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void vEventHndlKey_enter	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void vEventHndlKey_home	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    // void vEventHndlKey_del	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void vEventHndlKey_backSpace	    (dtyIntfcAbstractUnitGraphic_t* p_this) override;
    // void vEventHndlKey_typeChar	        (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    // section end   **** EVENT HANDLER *****
    // ****************************************************
    // --------------------------
// // ****************************************************
// // section start **** CONTAINER *****
// 
//     public:
//     void cntnrInit           (dtyString_t* p_pString, dtyStringInfo_t* p_pStringInfo) override;
//     void cntnrUpdParams      (dtyIntfcAbstractUnitGraphic_t* p_this) override;
// 
//     // section end   **** CONTAINER *****
//     // ****************************************************
//     // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    private:

        hwPinPort_t* g_pMcuPinPort;

    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG FUNCTIONS *****
    private:
        bool g_dbgSelect;
    public:
        void dbgSet             (int32_t p_value);
        void dbgSetMode         (bool p_select);
        void dbgRefreshValue    (dtyIntfcAbstractUnitGraphic_t* p_this);

    // section end   **** DEBUG FUNCTIONS *****
    // ****************************************************
    // --------------------------

};


#endif 	// TUI_FNCT_REAL_UNIT_1_DGT_IN_OUT_H
