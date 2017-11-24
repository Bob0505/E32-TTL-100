#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2017-11-24 23:50:56

#include "Arduino.h"
#include <SoftwareSerial.h>
#include "E32-TTL-100.h"
bool ReadAUX() ;
RET_STATUS WaitAUX_H() ;
bool chkModeSame(MODE_TYPE mode) ;
void SwitchMode(MODE_TYPE mode) ;
void cleanUARTBuf() ;
void triple_cmd(SLEEP_MODE_CMD_TYPE Tcmd) ;
RET_STATUS Module_info(uint8_t* pReadbuf, uint8_t buf_len) ;
RET_STATUS Write_CFG_PDS(struct CFGstruct* pCFG) ;
RET_STATUS Read_CFG(struct CFGstruct* pCFG) ;
RET_STATUS Read_module_version(struct MVerstruct* MVer) ;
void Reset_module() ;
RET_STATUS SleepModeCmd(uint8_t CMD, void* pBuff) ;
RET_STATUS SettingModule(struct CFGstruct *pCFG) ;
RET_STATUS ReceiveMsg(uint8_t *pdatabuf, uint8_t *data_len) ;
RET_STATUS SendMsg() ;
void setup() ;
void blinkLED() ;
void loop() ;


#include "E32-TTL-100.ino"

#endif
