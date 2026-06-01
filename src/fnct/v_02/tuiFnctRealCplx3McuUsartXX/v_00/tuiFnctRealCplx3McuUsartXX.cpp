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


#include "tuiFnctRealCplx3McuUsartXX_dbgSetup.h"


// ****************************************************
// section start **** CONSTRUCTOR *****

    tuiFnctRealCplx3McuUsartXX_t::tuiFnctRealCplx3McuUsartXX_t  (pphUsartRs485_t*                p_pPphUSART    
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
                sendMessage();
                g_sendingDataBox->setStatus_toEdit();
            }

            uint8_t l_rxBufferSize = g_pPphUsart->rx_packetCheck();
            if(l_rxBufferSize)  {
                g_recevingDataCntnr->add(
                     g_pPphUsartBuff
                    ,l_rxBufferSize
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );

                // unlock the rxBuffer to receive other new packets
                g_pPphUsart->setBufferStatusFree();

                g_recevingDataCntnr->selectElementLast();
            }

// 
// // *********
//             if(g_sendingDataBox->chkStatusSuspend()) {
//                 sendMessage();
//                 g_sendingDataBox->setStatus_toEdit();
//             }
// 
            // error management
            if(
                    (g_pPphUsart->rx_chkError())
                ||  (g_pPphUsart->tx_chkError())
            )  {

                g_errorMsg[7] = '-';
                g_errorMsg[8] = '-';

                g_errorMsg[10] = '-';
                g_errorMsg[11] = '-';

                g_errorMsg[13] = '-';
                // check Tx error status
                if(g_pPphUsart->tx_chkError())  {
                    // tx error management
                    dtyString_t::strncpy(g_errorMsg, "error in sending", sizeof(g_errorMsg));
                    g_errorMsg[0] = 'T';
                    g_error = g_pPphUsart->getError();
                    g_errorMsg[7] = '0' + static_cast<uint8_t>(g_error / 10);
                    g_errorMsg[8] = '0' + static_cast<uint8_t>(g_error % 10);

                    g_error = g_pPphUsart->getError(encSysErrorGroup_t::comProtocolStatus);
                    g_errorMsg[10] = '0' + static_cast<uint8_t>(g_error / 10);
                    g_errorMsg[11] = '0' + static_cast<uint8_t>(g_error % 10);

                    g_errorMsg[13] = g_pPphUsart->getErrorDetails(encSysErrorGroup_t::comProtocolStatus);
                }   

                // check Rx error status
                if(g_pPphUsart->rx_chkError())  {
                    // rx error management
                    dtyString_t::strncpy(g_errorMsg, "error in receiving", sizeof(g_errorMsg));
                    g_errorMsg[0] = 'R';
                    g_error = g_pPphUsart->getError();
                    g_errorMsg[7] = '0' + static_cast<uint8_t>(g_error / 10);
                    g_errorMsg[8] = '0' + static_cast<uint8_t>(g_error % 10);

                    g_error = g_pPphUsart->getError(encSysErrorGroup_t::comProtocolStatus);
                    g_errorMsg[10] = '0' + static_cast<uint8_t>(g_error / 10);
                    g_errorMsg[11] = '0' + static_cast<uint8_t>(g_error % 10);

                    g_errorMsg[13] = g_pPphUsart->getErrorDetails(encSysErrorGroup_t::comProtocolStatus);
                }

                g_errorMsg[1]  = 'x';
                g_errorMsg[2]  = ' ';
                g_errorMsg[3]  = 'e';
                g_errorMsg[4]  = 'r';
                g_errorMsg[5]  = 'r';
                g_errorMsg[6]  = '.';
                g_errorMsg[9]  = '.';
                g_errorMsg[12] = '.';
                g_errorMsg[14] = 0;
                // error management
                g_recevingDataCntnr->add(
                     g_errorMsg
                    ,14
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );

                // release com buffer status
                g_pPphUsart->setBufferStatusFree();

                g_recevingDataCntnr->selectElementLast();
            }
// 
// 
//             uint8_t l_rxBufferSize = g_pPphUsart->rx_packetCheck();
//             if(l_rxBufferSize)  {
//                 g_recevingDataCntnr->add(
//                      g_pPphUsartBuff
//                     ,l_rxBufferSize
//                     ,kMarker_t::deviceTx
//                     ,kDataType_t::ascii
//                 );
// 
//                 g_recevingDataCntnr->selectElementLast();
// 
//                 // release com buffer status
//                 g_pPphUsart->setBufferStatusFree();
//             }
// 
// 
// // *********
// 
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
        void tuiFnctRealCplx3McuUsartXX_t::sendMessage    (void)     {
            uint8_t* l_ptrBuf = reinterpret_cast<uint8_t*>(g_sendingDataBuffer);

            int16_t l_bufferLenghth = g_pPphUsart->send(l_ptrBuf);
            if( 0 < l_bufferLenghth )   {

                // #include "tuiFnctRealCplx3McuUsartXX_dbgToken_exit.h"                
                g_recevingDataCntnr->add(
                     l_ptrBuf
                    ,l_bufferLenghth
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );
    
                g_recevingDataCntnr->selectElementLast();
            }


        }

        void tuiFnctRealCplx3McuUsartXX_t::sendMessage    (dtyIntfcAbstractUnitGraphic_t* p_this)     {
            uint8_t* l_ptrBuf = reinterpret_cast<uint8_t*>(g_sendingDataBuffer);

            int16_t l_bufferLenghth = g_pPphUsart->send(l_ptrBuf);
            if( 0 < l_bufferLenghth )   {

                // #include "tuiFnctRealCplx3McuUsartXX_dbgToken_exit.h"                
                g_recevingDataCntnr->add(
                     l_ptrBuf
                    ,l_bufferLenghth
                    ,kMarker_t::deviceTx
                    ,kDataType_t::ascii
                );
    
                g_recevingDataCntnr->selectElementLast();
            }


        }

//        void tuiFnctRealCplx3McuUsartXX_t::sendMessage    (dtyIntfcAbstractUnitFunctional_t* p_this)     {
//            uint8_t* l_ptrBuf = reinterpret_cast<uint8_t*>((static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_sendingDataBuffer));
//            uint8_t l_packetLenghth = static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_pPphUsart->txGetPacketLength(l_ptrBuf);
//            dbgPrint(4,4, " test debug message ");
//            dbgStep("Test packet Length", l_packetLenghth, l_packetLenghth);
//            sysDebug_t::exit();
//            if( l_packetLenghth )   {
//                static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_pPphUsart->txBuff_send(l_ptrBuf);
//                
//                static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_recevingDataCntnr->add(
//                     l_ptrBuf
//                    ,l_packetLenghth
//                    ,kMarker_t::deviceTx
//                    ,kDataType_t::ascii
//                );
//    
//                static_cast<tuiFnctRealCplx3McuUsartXX_t*>(p_this)->g_recevingDataCntnr->selectElementLast();
//            }
//        }


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
