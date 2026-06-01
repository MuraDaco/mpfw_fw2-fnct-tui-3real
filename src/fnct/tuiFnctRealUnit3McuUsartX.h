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
 * tuiFnctRealUnit3McuUsartX.h
 *
 *  Created on: Feb,  1st 2025 (Sat)
 *      Author: Marco Dau
 */
 
#ifndef TUI_FNCT_REAL_UNIT_3_MCU_USART_X_H
#define TUI_FNCT_REAL_UNIT_3_MCU_USART_X_H

#include "tuiFnctRealUnit2Cntnr.h"
#include "dtyCntnr1StreamList.h"
#include "tuiFnctRealUnit1FormattedStringCntnr.h"
#include "pphUsart.h"

#include "tuiFnctRealUnit1Ebox.h"
#include "dtyCntnr1ArrayTuiList.h"

#include "tuiGrphRealUnit5Base.h"

#include "tuiMacroDefine.h"

class tuiFnctRealUnit3McuUsartX_t :    public tuiFnctRealUnit2Cntnr_t
{

// ****************************************************
// section start **** CONSTRUCTOR *****

    public:
    tuiFnctRealUnit3McuUsartX_t       (pphUsart_t* p_pPphUSART   );
    //tuiFnctRealUnit3McuUsartX_t       (const char* p_strName  ,mcuUsart_t* p_pMcuUSART   );

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    protected:
        bool init   	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;
        bool loop   	            (dtyIntfcAbstractUnitGraphic_t* p_this) override;

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    private:

        pphUsart_t* g_pPphUsart;

        // uint8_t g_recevingDataBuffer[1000000];
        // dtyCntnr2StreamListFrmtStr_t   g_recevingDataCntnr;
        // //  dtyCntnr2StreamList_t   g_recevingDataCntnr;
        // //      tuiFnctRealUnit1FormattedStringCntnr_t g_formattedString;
        // tuiFnctRealUnit2Cntnr_t  g_recevingDataBox;

        uint8_t* g_pPphUsartBuff;

        TUI_DEF_H___STREAM_FRMTD_STR_SEC_STC;
        TUI_DEF_H___STREAM_FRMTD_STR_SEC_DYN(recevingDataBoxGrph);

        char    g_sendingDataBuffer[1000];
        dtyBaseArray_t  g_sendingData;
        tuiFnctRealUnit1Ebox_t   g_sendingDataBox;

        //tuiGrphRealUnit5Base_t    g_recevingDataBoxGrph;
        tuiGrphRealUnit5Base_t    g_sendingDataBoxGrph;
        dtyIntfcAbstractUnitGraphic_t*    g_boxesArray[3];
        dtyCntnr1ArrayTuiList_t g_unitBoxesCntnr;

        static void sendMessage    (dtyIntfcAbstractUnitFunctional_t* p_this);

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


#endif 	// TUI_FNCT_REAL_UNIT_3_MCU_USART_X_H
