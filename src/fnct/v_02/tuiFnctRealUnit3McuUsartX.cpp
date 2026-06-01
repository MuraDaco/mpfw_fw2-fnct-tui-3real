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
 

#include "tuiFnctRealUnit3McuUsartX.h"


#include "dtyString.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    TUI_DEF_CPP_STREAM_FRMTD_STR_SEC_STC    (tuiFnctRealUnit3McuUsartX_t);
    
    tuiFnctRealUnit3McuUsartX_t::tuiFnctRealUnit3McuUsartX_t      ([[maybe_unused]] pphUsartRs485_t* p_pPphUSART    )   :
        tuiFnctRealUnit2Cntnr_t          ("USART box", &g_unitBoxesCntnr)
        // tuiFnctRealUnit2Cntnr_t          ("USART box")
        // ,g_updCnt                   {0}
        ,g_pPphUsart                {p_pPphUSART}
        //,g_recevingDataCntnr        {g_recevingDataBuffer, sizeof(g_recevingDataBuffer)}
        //,g_recevingDataBox          {"Receving data box", &g_recevingDataCntnr}
        ,TUI_DEF_CPP_STREAM_FRMTD_STR_SEC_DYN(recevingDataBoxGrph)
        ,g_sendingDataBuffer        {"inserire il messaggio da inviare"}
        ,g_sendingData              {g_sendingDataBuffer, sizeof(g_sendingDataBuffer)}
        ,g_sendingDataBox           {"Sending data box", g_sendingData}
        //,g_sendingDataBox           {"Sending data box", g_sendingData, this, sendMessage}
        //,g_recevingDataBoxGrph      {&g_recevingDataBox,     9}
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

    // tuiFnctRealUnit3McuUsartX_t::tuiFnctRealUnit3McuUsartX_t      (const char* p_strName  ,[[maybe_unused]] mcuUsart_t* p_pMcuUSART    )   :
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
        bool tuiFnctRealUnit3McuUsartX_t::init   	            (dtyIntfcAbstractUnitGraphic_t* p_this)  {
            tuiFnctRealUnit2Cntnr_t::init(p_this);
            g_pPphUsartBuff = g_pPphUsart->rxBuff_getPtr();
            return true;
        }

        bool tuiFnctRealUnit3McuUsartX_t::loop   	            ([[maybe_unused]] dtyIntfcAbstractUnitGraphic_t* p_this)  {
            if(g_sendingDataBox.chkStatusSuspend()) {
                sendMessage(this);
                g_sendingDataBox.setStatus_toEdit();
            }

            // error management
            if(
                    (g_pPphUsart->rx_chkError())
                ||  (g_pPphUsart->tx_chkError())
            )  {
                uint8_t l_errorMsg[50];

                // check Tx error status
                if(g_pPphUsart->tx_chkError())  {
                    // tx error management
                    dtyString_t::strncpyU(l_errorMsg, "error in sending", sizeof(l_errorMsg));
                }

                // check Rx error status
                if(g_pPphUsart->rx_chkError())  {
                    // rx error management
                    dtyString_t::strncpyU(l_errorMsg, "error in receiving", sizeof(l_errorMsg));
                }
                // release com buffer status
                g_pPphUsart->setBufferStatusFree();

                // error management
                g_recevingDataCntnr.add(
                     l_errorMsg
                    ,sizeof(l_errorMsg)
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );
                g_recevingDataCntnr.selectElementLast();
            }

//            uint8_t l_rxBufferSize = g_pPphUsart->rxBuff_receive();
//            if(l_rxBufferSize)  {
//                g_recevingDataCntnr.add(
//                     g_pPphUsartBuff
//                    ,l_rxBufferSize
//                    ,kMarker_t::deviceTx
//                    ,kDataType_t::ascii
//                );
//
//                g_recevingDataCntnr.selectElementLast();
//            }

            uint8_t l_rxBufferSize = g_pPphUsart->rx_packetCheck();
            if(l_rxBufferSize)  {
            // if(g_pPphUsart->rx_packetCheck())  {
                g_recevingDataCntnr.add(
                     g_pPphUsartBuff
                    ,l_rxBufferSize
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );

                g_recevingDataCntnr.selectElementLast();

                // release com buffer status
                g_pPphUsart->setBufferStatusFree();
            }

            return true;
        }

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** SPECIFIC DATA *****

    // private:
        void tuiFnctRealUnit3McuUsartX_t::sendMessage    (dtyIntfcAbstractUnitFunctional_t* p_this)     {
            tuiFnctRealUnit3McuUsartX_t* l_this = static_cast<tuiFnctRealUnit3McuUsartX_t*>(p_this);
            uint8_t* l_ptrBuf = reinterpret_cast<uint8_t*>(l_this->g_sendingDataBuffer);
            // pphUsartRs485_t* l_pPphUsart = static_cast<tuiFnctRealUnit3McuUsartX_t*>(p_this)->g_pPphUsart;
            // dtyCntnr1StreamList_t* l_recevingDataCntnr = static_cast<tuiFnctRealUnit3McuUsartX_t*>(p_this)->g_recevingDataCntnr;

//            // ****************
//            // mode 1 - begin
//            uint8_t l_packetLenghth = l_pPphUsart->txGetPacketLength(l_ptrBuf, SIZEOF_SENDING_DATA_BUFFER);
//            // dbgPrint(4,4, " test debug message ");
//            // sysDebug_t::exit();
//            if( l_packetLenghth )   {
//                l_pPphUsart->txBuff_send(l_ptrBuf);
//                
//                l_recevingDataCntnr->g_recevingDataCntnr.add(
//                     l_ptrBuf
//                    ,l_packetLenghth
//                    ,kMarker_t::deviceTx
//                    ,kDataType_t::ascii
//                );
//    
//                l_recevingDataCntnr->g_recevingDataCntnr.selectElementLast();
//            }
//            // mode 1 - end
//            // ****************

            // ****************
            // mode 2 - begin

            // dbgPrint(4,4, " test debug message ");
            // sysDebug_t::exit();
            if( l_this->g_pPphUsart->tx_packetSent(l_ptrBuf, SIZEOF_SENDING_DATA_BUFFER) )   {
                
                l_this->g_recevingDataCntnr.add(
                     l_ptrBuf
                    ,l_this->g_pPphUsart->getBufferLength()
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );
    
                l_this->g_recevingDataCntnr.selectElementLast();
            }

            // mode 2 - end
            // ****************

        }


    // section end   **** SPECIFIC DATA *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** DEBUG FUNCTIONS *****

    void tuiFnctRealUnit3McuUsartX_t::dbgSet                ([[maybe_unused]] int32_t p_value)   {
        // g_pMcuPinPort->pinRead(0,p_value);
    }

    void tuiFnctRealUnit3McuUsartX_t::dbgSetMode            (bool p_select)   {
        g_dbgSelect = p_select;
    }

    void tuiFnctRealUnit3McuUsartX_t::dbgRefreshValue       (dtyIntfcAbstractUnitGraphic_t* p_this)      {
        // p_this->frameNnameTest(g_strName, g_pDtyMmyInt32->g_pStringValue);
        display(p_this);
    }

    // section end   **** DEBUG FUNCTIONS *****
    // ****************************************************
    // --------------------------
