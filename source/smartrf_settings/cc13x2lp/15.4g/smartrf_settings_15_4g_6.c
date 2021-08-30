//*********************************************************************************
// Generated by SmartRF Studio version 2.19.0 (build#255)
// The applied template is compatible with cc13x2_26x2 SDK version 2.10.xx.xx or newer.
// Device: CC1352R Rev. E (2.1). 
//
//*********************************************************************************


//*********************************************************************************
// Parameter summary
// Frequency: 915.20001 MHz
// Data Format: Serial mode disable 
// Deviation: 37.500 kHz
// IEEE 802.15.4g Packet Length: 20 
// Select bit order to transmit PSDU octets: 1 
// Packet Data: 255 
// Preamble Count: 4 Bytes 
// Preamble Mode: Send 0 as the first preamble bit 
// RX Filter BW: 273.1 kHz
// Symbol Rate: 150.00000 kBaud
// Sync Word: 0x0055904e 
// Sync Word Length: 24 Bits 
// TX Power: 14 dBm (requires define CCFG_FORCE_VDDR_HH = 1 in ccfg.c, see CC13xx/CC26xx Technical Reference Manual)
// Whitening: Dynamically IEEE 802.15.4g compatible whitener and 16/32-bit CRC 

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/rf_mailbox.h)
#include DeviceFamily_constructPath(driverlib/rf_common_cmd.h)
#include DeviceFamily_constructPath(driverlib/rf_prop_cmd.h)
#include <ti/drivers/rf/RF.h>
#include DeviceFamily_constructPath(rf_patches/rf_patch_cpe_multi_protocol.h)
#include "smartrf_settings_15_4g_6.h"


// TI-RTOS RF Mode Object
RF_Mode Ieee154g6_mode =
{
    .rfMode = RF_MODE_AUTO,
    .cpePatchFxn = &rf_patch_cpe_multi_protocol,
    .mcePatchFxn = 0,
    .rfePatchFxn = 0
};


// Overrides for CMD_PROP_RADIO_DIV_SETUP
uint32_t Ieee154g6_pOverrides[] =
{
    // override_prop_common.xml
    // DC/DC regulator: In Tx, use DCDCCTL5[3:0]=0x7 (DITHER_EN=0 and IPEAK=7).
    (uint32_t)0x00F788D3,
    // override_prop_common_sub1g.xml
    // Set RF_FSCA.ANADIV.DIV_SEL_BIAS = 1. Bits [0:16, 24, 30] are don't care..
    (uint32_t)0x4001405D,
    // Set RF_FSCA.ANADIV.DIV_SEL_BIAS = 1. Bits [0:16, 24, 30] are don't care..
    (uint32_t)0x08141131,
    // override_tc142.xml
    // Synth: Set loop bandwidth after lock to 20 kHz (K2)
    (uint32_t)0x0A480583,
    // Synth: Set loop bandwidth after lock to 20 kHz (K2)
    (uint32_t)0x000005A3,
    // Synth: Set loop bandwidth after lock to 20 kHz (K3, LSB)
    (uint32_t)0x7AB80603,
    // Synth: Set loop bandwidth after lock to 20 kHz (K3, MSB)
    (uint32_t)0x00000623,
    // Synth: Set FREF = 4 MHz
    (uint32_t)0x000C84A3,
    // Synth: Set FREF dither to 4.36 MHz
    (uint32_t)0x000B84B3,
    // Set LNA IB offset to 0xF
    (uint32_t)0x000F8883,
    // Synth: Set dTxM value factor to -50
    (uint32_t)0x00CE87E3,
    // Synth: Set dTxM value threshold to 37
    (uint32_t)0x00250803,
    // Synth: Set calibration fine point code to 60 (default: 64)
    HW_REG_OVERRIDE(0x4064,0x003C),
    // Tx: Configure PA ramp time, PACTL2.RC=0x3 (in ADI0, set PACTL2[4:3]=0x3)
    ADI_2HALFREG_OVERRIDE(0,16,0x8,0x8,17,0x1,0x1),
    // Tx: Set wait time before turning off ramp to 0x1A (default: 0x1F)
    HW_REG_OVERRIDE(0x6028,0x001A),
    // Rx: Set AGC reference level to 0x16 (default: 0x2E)
    HW_REG_OVERRIDE(0x609C,0x0016),
    // Rx: Set RSSI offset to adjust reported RSSI by -4 dB (default: -2), trimmed for external bias and differential configuration
    (uint32_t)0x000488A3,
    // Rx: Set anti-aliasing filter bandwidth to 0xB (in ADI0, set IFAMPCTL3[7:4]=0xB)
    ADI_HALFREG_OVERRIDE(0,61,0xF,0xB),
    // TX power override
    // Tx: Set PA trim to max to maximize its output power (in ADI0, set PACTL0=0xF8)
    ADI_REG_OVERRIDE(0,12,0xF8),
    (uint32_t)0xFFFFFFFF
};


// CMD_PROP_RADIO_DIV_SETUP
// Proprietary Mode Radio Setup Command for All Frequency Bands
rfc_CMD_PROP_RADIO_DIV_SETUP_t Ieee154g6_cmdPropRadioDivSetup =
{
    .commandNo = 0x3807,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .modulation.modType = 0x1,
    .modulation.deviation = 0x96,
    .modulation.deviationStepSz = 0x0,
    .symbolRate.preScale = 0xF,
    .symbolRate.rateWord = 0x18000,
    .symbolRate.decimMode = 0x0,
    .rxBw = 0x58,
    .preamConf.nPreamBytes = 0x4,
    .preamConf.preamMode = 0x0,
    .formatConf.nSwBits = 0x18,
    .formatConf.bBitReversal = 0x0,
    .formatConf.bMsbFirst = 0x1,
    .formatConf.fecMode = 0x0,
    .formatConf.whitenMode = 0x7,
    .config.frontEndMode = 0x0,
    .config.biasMode = 0x1,
    .config.analogCfgMode = 0x0,
    .config.bNoFsPowerUp = 0x0,
    .config.bSynthNarrowBand = 0x0,
    .txPower = 0x013F,
    .pRegOverride = Ieee154g6_pOverrides,
    .centerFreq = 0x0393,
    .intFreq = 0x08CC,
    .loDivider = 0x05
};


// CMD_FS
// Frequency Synthesizer Programming Command
rfc_CMD_FS_t Ieee154g6_cmdFs =
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
    .frequency = 0x0393,
    .fractFreq = 0x3334,
    .synthConf.bTxMode = 0x0,
    .synthConf.refFreq = 0x0,
    .__dummy0 = 0x00,
    .__dummy1 = 0x00,
    .__dummy2 = 0x00,
    .__dummy3 = 0x0000
};


// CMD_PROP_RX_ADV
// Proprietary Mode Advanced Receive Command
rfc_CMD_PROP_RX_ADV_t Ieee154g6_cmdPropRxAdv =
{
    .commandNo = 0x3804,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = TRIG_NOW,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .pktConf.bFsOff = 0x0,
    .pktConf.bRepeatOk = 0x0,
    .pktConf.bRepeatNok = 0x0,
    .pktConf.bUseCrc = 0x1,
    .pktConf.bCrcIncSw = 0x0,
    .pktConf.bCrcIncHdr = 0x0,
    .pktConf.endType = 0x0,
    .pktConf.filterOp = 0x0,
    .rxConf.bAutoFlushIgnored = 0x0,
    .rxConf.bAutoFlushCrcErr = 0x0,
    .rxConf.bIncludeHdr = 0x1,
    .rxConf.bIncludeCrc = 0x1,
    .rxConf.bAppendRssi = 0x1,
    .rxConf.bAppendTimestamp = 0x0,
    .rxConf.bAppendStatus = 0x1,
    .syncWord0 = 0x0055904E,
    .syncWord1 = 0,
    .maxPktLen = 0,
    .hdrConf.numHdrBits = 16,
    .hdrConf.lenPos = 0,
    .hdrConf.numLenBits = 11,
    .addrConf.addrType = 0,
    .addrConf.addrSize = 0,
    .addrConf.addrPos = 0,
    .addrConf.numAddr = 0,
    .lenOffset = -4,
    .endTrigger.triggerType = TRIG_NEVER,
    .endTrigger.bEnaCmd = 0x0,
    .endTrigger.triggerNo = 0x0,
    .endTrigger.pastTrig = 0x0,
    .endTime = 0x00000000,
    .pAddr = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .pQueue = 0, // INSERT APPLICABLE POINTER: (dataQueue_t*)&xxx
    .pOutput = 0 // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
};


// CMD_PROP_TX_ADV
// Proprietary Mode Advanced Transmit Command
rfc_CMD_PROP_TX_ADV_t Ieee154g6_cmdPropTxAdv =
{
    .commandNo = 0x3803,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .pktConf.bFsOff = 0x0,
    .pktConf.bUseCrc = 0x1,
    .pktConf.bCrcIncSw = 0x0,
    .pktConf.bCrcIncHdr = 0x0,
    .numHdrBits = 16,
    .pktLen = 0x0000,
    .startConf.bExtTxTrig = 0x0,
    .startConf.inputMode = 0x0,
    .startConf.source = 0x0,
    .preTrigger.triggerType = 0x0,
    .preTrigger.bEnaCmd = 0x0,
    .preTrigger.triggerNo = 0x0,
    .preTrigger.pastTrig = 0x0,
    .preTime = 0x00000000,
    .syncWord = 0x0055904E,
    .pPkt = 0 // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
};
