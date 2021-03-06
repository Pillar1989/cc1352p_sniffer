//*********************************************************************************
// Generated by SmartRF Studio version 2.16.0 (build#211)
// The applied template is compatible with CC2652RB SDK version 3.10.xx.xx or newer.
// Device: CC2652RB Rev. E (2.1). 
//
//*********************************************************************************


//*********************************************************************************
// Parameter summary
// Adv. Address: 010203040506 
// Adv. Data: dummy 
// BLE Channel: 17 
// Extended Header: 09 09 010203040506 babe 
// Frequency: 2440 MHz
// PDU Payload length: 30 
// TX Power: 5 dBm 
// Whitening: true 

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/rf_mailbox.h)
#include DeviceFamily_constructPath(driverlib/rf_common_cmd.h)
#include DeviceFamily_constructPath(driverlib/rf_ble_cmd.h)
#include <ti/drivers/rf/RF.h>
#include DeviceFamily_constructPath(rf_patches/rf_patch_cpe_multi_protocol.h)
#include "smartrf_settings_ble5_0.h"


// TI-RTOS RF Mode Object
RF_Mode Ble5_0_mode =
{
    .rfMode = RF_MODE_AUTO,
    .cpePatchFxn = &rf_patch_cpe_multi_protocol,
    .mcePatchFxn = 0,
    .rfePatchFxn = 0
};


// Overrides for CMD_BLE5_RADIO_SETUP
uint32_t pOverridesCommon[] =
{
    // override_hposc.xml
    // HPOSC frequency offset override, freqOffset=2^22*(F_nom-F_hposc)/F_hposc
    HPOSC_OVERRIDE(0),
    // override_ble5_setup_override_common.xml
    // DC/DC regulator: In Tx, use DCDCCTL5[3:0]=0x3 (DITHER_EN=0 and IPEAK=3).
    (uint32_t)0x00F388D3,
    // Bluetooth 5: Set pilot tone length to 20 us Common
    HW_REG_OVERRIDE(0x6024,0x2E20),
    // Bluetooth 5: Compensate for reduced pilot tone length
    (uint32_t)0x01280263,
    // Bluetooth 5: Default to no CTE. 
    HW_REG_OVERRIDE(0x5328,0x0000),
    // Synth: Set Fref to 6 MHz
    (uint32_t)0x000884A3,
    // HPOSC: Lower deviation by 5 kHz
    (uint32_t)0x1EA3005B,
    // Synth: Increase mid code calibration time to 5 us
    (uint32_t)0x00058683,
    // Synth: Increase mid code calibration time to 5 us
    HW32_ARRAY_OVERRIDE(0x4004,1),
    // Synth: Increase mid code calibration time to 5 us
    (uint32_t)0x38183C30,
    (uint32_t)0xFFFFFFFF
};


// Overrides for CMD_BLE5_RADIO_SETUP
uint32_t pOverrides1Mbps[] =
{
    // override_ble5_setup_override_1mbps.xml
    // Bluetooth 5: Set pilot tone length to 20 us
    HW_REG_OVERRIDE(0x5320,0x03C0),
    // Bluetooth 5: Compensate syncTimeadjust
    (uint32_t)0x015302A3,
    // SRFSNIFF-475
    HW_REG_OVERRIDE(0x6098, 0x25F8),
    HW_REG_OVERRIDE(0x60A0, 0x0026),
    (uint32_t)0xFFFFFFFF
};


// Overrides for CMD_BLE5_RADIO_SETUP
uint32_t pOverrides2Mbps[] =
{
    // override_ble5_setup_override_2mbps.xml
    // Bluetooth 5: Set pilot tone length to 20 us
    HW_REG_OVERRIDE(0x5320,0x03C0),
    // Bluetooth 5: Compensate syncTimeAdjust
    (uint32_t)0x00F102A3,
    // Bluetooth 5: increase low gain AGC delay for 2 Mbps
    HW_REG_OVERRIDE(0x60A4,0x7D00),
    (uint32_t)0xFFFFFFFF
};


// Overrides for CMD_BLE5_RADIO_SETUP
uint32_t pOverridesCoded[] =
{
    // override_ble5_setup_override_coded.xml
    // PHY: Use MCE ROM, RFE ROM
    MCE_RFE_OVERRIDE(0,9,1,0,3,1),
    // Bluetooth 5: Set pilot tone length to 20 us
    HW_REG_OVERRIDE(0x5320,0x03C0),
    // Bluetooth 5: Compensate syncTimeadjust
    (uint32_t)0x06E602A3,
    // Rx: Set AGC reference level to 0x1B (default: 0x2E)
    HW_REG_OVERRIDE(0x609C,0x001B),
    (uint32_t)0xFFFFFFFF
};


// CMD_BLE5_RADIO_SETUP
// Bluetooth 5 Radio Setup Command for all PHYs
rfc_CMD_BLE5_RADIO_SETUP_t Ble5_0_cmdBle5RadioSetup =
{
    .commandNo = 0x1820,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .defaultPhy.mainMode = 0x0,
    .defaultPhy.coding = 0x0,
    .loDivider = 0x00,
    .config.frontEndMode = 0x0,
    .config.biasMode = 0x0,
    .config.analogCfgMode = 0x0,
    .config.bNoFsPowerUp = 0x0,
    .txPower = 0x7217,
    .pRegOverrideCommon = pOverridesCommon,
    .pRegOverride1Mbps = pOverrides1Mbps,
    .pRegOverride2Mbps = pOverrides2Mbps,
    .pRegOverrideCoded = pOverridesCoded
};


// CMD_FS
// Frequency Synthesizer Programming Command
rfc_CMD_FS_t Ble5_0_cmdFs =
{
    .commandNo = 0x0803,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    
    // Modified for channel 37
    .frequency = 0x0962,
    
    .fractFreq = 0x0000,
    .synthConf.bTxMode = 0x0,
    .synthConf.refFreq = 0x0,
    .__dummy0 = 0x00,
    .__dummy1 = 0x00,
    .__dummy2 = 0x00,
    .__dummy3 = 0x0000
};


// Structure for CMD_BLE5_GENERIC_RX.pParams
rfc_bleGenericRxPar_t bleGenericRxPar =
{
    .pRxQ = 0, // INSERT APPLICABLE POINTER: (dataQueue_t*)&xxx
    .rxConfig.bAutoFlushIgnored = 0x0,
    .rxConfig.bAutoFlushCrcErr = 0x0,
    .rxConfig.bAutoFlushEmpty = 0x0,
    .rxConfig.bIncludeLenByte = 0x1,
    .rxConfig.bIncludeCrc = 0x1,
    .rxConfig.bAppendRssi = 0x1,
    .rxConfig.bAppendStatus = 0x1,
    .rxConfig.bAppendTimestamp = 0x0,
    .bRepeat = 0x01,
    .__dummy0 = 0x0000,
    .accessAddress = 0x8E89BED6,
    .crcInit0 = 0x55,
    .crcInit1 = 0x55,
    .crcInit2 = 0x55,
    .endTrigger.triggerType = 0x1,
    .endTrigger.bEnaCmd = 0x0,
    .endTrigger.triggerNo = 0x0,
    .endTrigger.pastTrig = 0x0,
    .endTime = 0x00000001
};


// CMD_BLE5_GENERIC_RX
// Bluetooth 5 Generic Receiver Command
rfc_CMD_BLE5_GENERIC_RX_t Ble5_0_cmdBle5GenericRx =
{
    .commandNo = 0x1829,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    
    // Modified for channel 37
    .channel = 0x25,
    .whitening.init = 0x65,
    .whitening.bOverride = 0x1,
    
    .phyMode.mainMode = 0x0,
    .phyMode.coding = 0x0,
    .rangeDelay = 0x00,
    .txPower = 0x0000,
    .pParams = &bleGenericRxPar,
    .pOutput = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .tx20Power = 0x00000000
};


// Structure for CMD_BLE_ADV_NC.pParams
rfc_bleAdvPar_t bleAdvPar =
{
    .pRxQ = 0, // INSERT APPLICABLE POINTER: (dataQueue_t*)&xxx
    .rxConfig.bAutoFlushIgnored = 0x0,
    .rxConfig.bAutoFlushCrcErr = 0x0,
    .rxConfig.bAutoFlushEmpty = 0x0,
    .rxConfig.bIncludeLenByte = 0x0,
    .rxConfig.bIncludeCrc = 0x0,
    .rxConfig.bAppendRssi = 0x0,
    .rxConfig.bAppendStatus = 0x0,
    .rxConfig.bAppendTimestamp = 0x0,
    .advConfig.advFilterPolicy = 0x0,
    .advConfig.deviceAddrType = 0x0,
    .advConfig.peerAddrType = 0x0,
    .advConfig.bStrictLenFilter = 0x0,
    .advConfig.chSel = 0x0,
    .advConfig.privIgnMode = 0x0,
    .advConfig.rpaMode = 0x0,
    .advLen = 0x18,
    .scanRspLen = 0x00,
    .pAdvData = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .pScanRspData = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .pDeviceAddress = 0, // INSERT APPLICABLE POINTER: (uint16_t*)&xxx
    .pWhiteList = 0, // INSERT APPLICABLE POINTER: (uint32_t*)&xxx
    .behConfig.scanRspEndType = 0x0,
    .__dummy0 = 0x0000,
    .endTrigger.triggerType = 0x1,
    .endTrigger.bEnaCmd = 0x0,
    .endTrigger.triggerNo = 0x0,
    .endTrigger.pastTrig = 0x0,
    .endTime = 0x00000000
};


// CMD_BLE_ADV_NC
// BLE Non-Connectable Advertiser Command
rfc_CMD_BLE_ADV_NC_t Ble5_0_cmdBleAdvNc =
{
    .commandNo = 0x1805,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .channel = 0x8C,
    .whitening.init = 0x51,
    .whitening.bOverride = 0x1,
    .pParams = &bleAdvPar,
    .pOutput = 0 // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
};
