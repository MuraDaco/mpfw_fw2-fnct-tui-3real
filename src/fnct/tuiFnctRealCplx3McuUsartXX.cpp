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
 * tuiFnctRealCplx3McuUsartXX.h
 *
 *  Created on: Feb,  1st 2025 (Sat)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealCplx3McuUsartXX.h"



// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiFnctRealCplx3McuUsartXX_t::tuiFnctRealCplx3McuUsartXX_t  (pphUsart_t*                p_pPphUSART    
                                                                ,dtyCntnr1StreamListX_t*    p_recevingDataCntnr
                                                                ,char*                      p_sendingDataBuffer
                                                                ,tuiFnctRealUnit1Ebox_t*    p_sendingDataBox
                                                                ,dtyCntnr1ArrayTuiList_t*   p_unitBoxesCntnr
    )   :
        tuiFnctRealUnit2Cntnr_t          ("USART box", p_unitBoxesCntnr)
        ,g_pPphUsart                {p_pPphUSART}
        ,g_recevingDataCntnr        {p_recevingDataCntnr}
        ,g_sendingDataBuffer        {p_sendingDataBuffer}
        ,g_sendingDataBox           {p_sendingDataBox}
        ,g_dbgSelect                {false}
    {
        g_pPphUsartBuff = g_pPphUsart->rxBuff_getPtr();
    }

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    // protected:
        bool tuiFnctRealCplx3McuUsartXX_t::init   	            (dtyIntfcAbstractUnitGraphic_t* p_this)  {
            tuiFnctRealUnit2Cntnr_t::init(p_this);
            g_pPphUsartBuff = g_pPphUsart->rxBuff_getPtr();
            return true;
        }

        bool tuiFnctRealCplx3McuUsartXX_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
            if(g_sendingDataBox->chkStatusSuspend()) {
                sendMessage(this);
                g_sendingDataBox->setStatus_toEdit();
            }

            uint8_t l_rxBufferSize = g_pPphUsart->rxBuff_receive();
            if(l_rxBufferSize)  {
                g_recevingDataCntnr->add(
                     g_pPphUsartBuff
                    ,l_rxBufferSize
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );

                g_recevingDataCntnr->selectElementLast();
            }

            return true;
        }

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    // private:
        // N.B.: 
        // a) p_this is used here because it is a static function
        // b) this function is defined as static for pass it to Ebox child
        void tuiFnctRealCplx3McuUsartXX_t::sendMessage    (dtyIntfcAbstractUnitFunctional_t* p_this)     {

            static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_pPphUsart->txBuff_send(
                 reinterpret_cast<uint8_t*>((static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_sendingDataBuffer))
                ,20
                );
                        static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_recevingDataCntnr->add(
                             reinterpret_cast<uint8_t*>((static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_sendingDataBuffer))
                            ,20
                            ,kMarker_t::deviceTx
                            ,kDataType_t::ascii
                        );
            
                        static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_recevingDataCntnr->selectElementLast();
            

        }


    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG FUNCTIONS *****

    void tuiFnctRealCplx3McuUsartXX_t::dbgSet                ([[maybe_unused]] int32_t p_value)   {
        // g_pMcuPinPort->pinRead(0,p_value);
    }

    void tuiFnctRealCplx3McuUsartXX_t::dbgSetMode            (bool p_select)   {
        g_dbgSelect = p_select;
    }

    void tuiFnctRealCplx3McuUsartXX_t::dbgRefreshValue       (dtyIntfcAbstractUnitGraphic_t* p_this)      {
        // p_this->frameNnameTest(g_strName, g_pDtyMmyInt32->g_pStringValue);
        display(p_this);
    }

    // section end   **** DEBUG FUNCTIONS *****
    // ****************************************************
    // --------------------------
