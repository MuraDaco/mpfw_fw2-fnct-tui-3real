#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       library that contains the "main" entry point and, 
#       eventualy, application code that is platform dependent
#   Copyright (C) (2023) Marco Dau
#   
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU Affero General Public License as published
#   by the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU Affero General Public License for more details.
#   
#   You should have received a copy of the GNU Affero General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
#   
#   You can contact me by the following email address
#   marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
#   
#   *******************************************************************************

include_guard()

    set(CURR_MOD_NAME       FNCT-TUI-3REAL)

    set(${CURR_MOD_NAME}_cmmn_SOURCE_FILES_CPP

        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/tuiFnctRealCplx3McuUsart.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/tuiFnctRealCplx3McuUsartX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/tuiFnctRealCplx3McuUsartXX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/tuiFnctRealUnit3McuUsart.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/tuiFnctRealUnit3McuUsartX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/fnct/tuiFnctRealUnit1DgtInOut.cpp ## si potrebbe anche eliminare

        ${${CURR_MOD_NAME}_SRC_DIR}/grph/tuiGrphRealUnit5Base.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/grph/tuiGrphRealUnit5Root/v_${${CURR_MOD_NAME}_tuiGrphRealUnit5Root_VER}/tuiGrphRealUnit5Root.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/grph/tuiGrphRealUnit5Win.cpp

        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCplt_0dtyCntnr2StreamListFStr.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCplt_dtyCntnr2StreamListFStr.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCplt_dtyCntnr2StreamListFStrX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCplt_dtyCntnr2StreamListShmProxX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltCplx3McuUsartX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltCplx3McuUsartXX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltCplx4McuUsartUU.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltCtnr2StreamFormattedString.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltCtnr2StreamFormattedStringX.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltUnit1Button.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltUnit1Debug.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltUnit1DgtInOut.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltUnit1Ebox.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltUnit1FormattedStringCntnr.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltUnit1MmyInt.cpp
        ${${CURR_MOD_NAME}_SRC_DIR}/cplt/tuiCpltUnit3ShmProxX.cpp

        ${${CURR_MOD_NAME}_SRC_DIR}/mngr/tuiManager/v_${${CURR_MOD_NAME}_tuiManager_VER}/tuiManager.cpp

    )
