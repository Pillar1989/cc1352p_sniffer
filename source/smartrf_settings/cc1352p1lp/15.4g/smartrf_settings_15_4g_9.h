#ifndef _SMARTRF_SETTINGS_15_4G_9_H_
#define _SMARTRF_SETTINGS_15_4G_9_H_

//*********************************************************************************
// Generated by SmartRF Studio version 2.19.0 (build#255)
// The applied template is compatible with cc13x2_26x2 SDK version 2.30.xx.xx or newer.
// Device: CC1352P Rev. E (2.1). 
//
//*********************************************************************************
#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/rf_mailbox.h)
#include DeviceFamily_constructPath(driverlib/rf_common_cmd.h)
#include DeviceFamily_constructPath(driverlib/rf_prop_cmd.h)
#include <ti/drivers/rf/RF.h>


// TI-RTOS RF Mode Object
extern RF_Mode Ieee154g9_mode;

// RF Core API Commands
extern rfc_CMD_PROP_RADIO_DIV_SETUP_PA_t Ieee154g9_cmdPropRadioDivSetup;
extern rfc_CMD_FS_t Ieee154g9_cmdFs;
extern rfc_CMD_PROP_TX_ADV_t Ieee154g9_cmdPropTxAdv;
extern rfc_CMD_PROP_RX_ADV_t Ieee154g9_cmdPropRxAdv;

// RF Core API Overrides
extern uint32_t Ieee154g9_pOverrides[];
extern uint32_t Ieee154g9_pOverridesTxStd[];
extern uint32_t Ieee154g9_pOverridesTx20[];

#endif // _SMARTRF_SETTINGS_15_4G_9_H_