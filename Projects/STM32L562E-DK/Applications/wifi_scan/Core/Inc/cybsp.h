/***********************************************************************************************//**
 * \file cybsp.h
 *
 * \brief
 * Basic API for setting up boards containing a STM32 MCU.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2020 Cypress Semiconductor Corporation
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **************************************************************************************************/

#pragma once

/** These names are explicitly referenced in the support libraries */
#define  CYBSP_WIFI_WL_REG_ON           PF5
#define  CYBSP_WIFI_HOST_WAKE           PB13

/** WiFi host-wake IRQ event */
#define CYBSP_WIFI_HOST_WAKE_IRQ_EVENT (CYHAL_GPIO_IRQ_RISE)
#define CYHAL_ISR_PRIORITY_DEFAULT     (7)

/* Override the SDMMC Clock frequency configured in WiFi Host Driver

   The actual clock can be different from what is defined by SDMMC_CLK_FREQ_OVERRIDE.
   This is a limitation caused by the SDMMC clock source.

   The actual SDMMC clock = SDMMC clock source / 2 / sdmmc_div

       Where, sdmmc_div = SDMMC clock source / (2 * SDMMC_CLK_FREQ_OVERRIDE)

       NOTE: This is done with integer math, so any fractions created by an operation
             will be lost (ex. 4.8 becomes 4).

       Example: The �SDMMC clock source� for the STM32L562 is 48 MHz.
           SDMMC_CLK_FREQ_OVERRIDE = 5000000
           sdmmc_div = 48000000 / (2 * 5000000) = 4.8 => 4
           actual SDMMC clock = 48000000 / 2 / 4 = 6000000 => 6 MHz
 */
#define SDMMC_CLK_FREQ_OVERRIDE        (6000000) /* Hz */