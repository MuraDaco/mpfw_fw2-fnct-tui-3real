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
 * tuiFnctRealUnit3McuUsart.h
 *
 *  Created on: Feb,  1st 2025 (Sat)
 *      Author: Marco Dau
 */
 

#include "tuiFnctRealUnit3McuUsart.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiFnctRealUnit3McuUsart_t::tuiFnctRealUnit3McuUsart_t      ([[maybe_unused]] pphUsart_t* p_pPphUSART    )   :
        tuiFnctRealUnit2Cntnr_t          ("USART box", &g_unitBoxesCntnr)
        // tuiFnctRealUnit2Cntnr_t          ("USART box")
        // ,g_updCnt                   {0}
        ,g_pPphUsart                {p_pPphUSART}
        ,g_recevingDataCntnr        {g_recevingDataBuffer, sizeof(g_recevingDataBuffer)}
        ,g_recevingDataBox          {"Receving data box", &g_recevingDataCntnr}
        ,g_sendingDataBuffer        {"inserire il messaggio da inviare"}
        ,g_sendingData              {g_sendingDataBuffer, sizeof(g_sendingDataBuffer)}
        ,g_sendingDataBox           {"Sending data box", g_sendingData}
        //,g_sendingDataBox           {"Sending data box", g_sendingData, this, sendMessage}
        ,g_recevingDataBoxGrph      {&g_recevingDataBox,     9}
        ,g_sendingDataBoxGrph       {&g_sendingDataBox,      3}
        ,g_boxesArray               {
                                         &g_recevingDataBoxGrph
                                        ,&g_sendingDataBoxGrph
                                        ,nullptr
                                    }
        ,g_unitBoxesCntnr           {g_boxesArray}
        ,g_dbgSelect                {false}
    {
        g_pPphUsartBuff = g_pPphUsart->rxBuff_getPtr();
    }

    // tuiFnctRealUnit3McuUsart_t::tuiFnctRealUnit3McuUsart_t      (const char* p_strName  ,[[maybe_unused]] mcuUsart_t* p_pMcuUSART    )   :
    //     tuiFnctRealUnit2Cntnr_t          (p_strName, &g_unitBoxesCntnr)
    //     //,g_pPphUsart                {p_pMcuUSART}
    //     ,g_recevingDataBox          {"Receving data box", &g_recevingDataCntnr}
    //     ,g_recevingDataCntnr        {g_recevingDataBuffer, sizeof(g_recevingDataBuffer)}
    //     ,g_sendingDataBox           {"Sending data box", g_sendingData}
    //     ,g_sendingData              {g_sendingDataBuffer, sizeof(g_sendingDataBuffer)}
    //     ,g_sendingDataBuffer        {"inserire il messaggio da inviare"}
    //     ,g_unitBoxesCntnr           {g_boxesArray}
    //     ,g_boxesArray               {
    //                                     // {&g_recevingDataBox,    10}
    //                                      {&g_sendingDataBox,     3}
    //                                     ,{nullptr,               0}
    //                                     ,{nullptr,               0}
    //                                     // {nullptr,               0}
    //                                 }
    //     ,g_dbgSelect                {false}
    // {}

    // section end   **** CONSTRUCTOR *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    // protected:
        bool tuiFnctRealUnit3McuUsart_t::init   	            (dtyIntfcAbstractUnitGraphic_t* p_this)  {
            tuiFnctRealUnit2Cntnr_t::init(p_this);
            g_pPphUsartBuff = g_pPphUsart->rxBuff_getPtr();
            return true;
        }

        bool tuiFnctRealUnit3McuUsart_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
            if(g_sendingDataBox.chkStatusSuspend()) {
                sendMessage(this);
                g_sendingDataBox.setStatus_toEdit();
            }

            uint8_t l_rxBufferSize = g_pPphUsart->rxBuff_receive();
            if(l_rxBufferSize)  {
                g_recevingDataCntnr.add(
                     g_pPphUsartBuff
                    ,l_rxBufferSize
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );

                g_recevingDataCntnr.selectElementLast();
            }

            return true;
        }

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    // private:
        void tuiFnctRealUnit3McuUsart_t::sendMessage    (dtyIntfcAbstractUnitFunctional_t* p_this)     {

            static_cast<tuiFnctRealUnit3McuUsart_t*>(p_this)->g_pPphUsart->txBuff_send(
                 reinterpret_cast<uint8_t*>((static_cast<tuiFnctRealUnit3McuUsart_t*>(p_this)->g_sendingDataBuffer))
                ,20
                );
                        static_cast<tuiFnctRealUnit3McuUsart_t*>(p_this)->g_recevingDataCntnr.add(
                             reinterpret_cast<uint8_t*>((static_cast<tuiFnctRealUnit3McuUsart_t*>(p_this)->g_sendingDataBuffer))
                            ,20
                            ,kMarker_t::deviceTx
                            ,kDataType_t::ascii
                        );
            
                        static_cast<tuiFnctRealUnit3McuUsart_t*>(p_this)->g_recevingDataCntnr.selectElementLast();
            

        }


    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG FUNCTIONS *****

    void tuiFnctRealUnit3McuUsart_t::dbgSet                ([[maybe_unused]] int32_t p_value)   {
        // g_pMcuPinPort->pinRead(0,p_value);
    }

    void tuiFnctRealUnit3McuUsart_t::dbgSetMode            (bool p_select)   {
        g_dbgSelect = p_select;
    }

    void tuiFnctRealUnit3McuUsart_t::dbgRefreshValue       (dtyIntfcAbstractUnitGraphic_t* p_this)      {
        // p_this->frameNnameTest(g_strName, g_pDtyMmyInt32->g_pStringValue);
        display(p_this);
    }

    // section end   **** DEBUG FUNCTIONS *****
    // ****************************************************
    // --------------------------
