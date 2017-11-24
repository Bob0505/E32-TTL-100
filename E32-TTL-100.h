/**
 * E32-TTL-100 Transceiver Interface
 *
 * @author Bob Chen (bob-0505@gotmail.com)
 * @date 1 November 2017
 * https://github.com/Bob0505/E32-TTL-100
 */
#ifndef E32-TTL-100_H_
#define E32-TTL-100_H_

typedef enum {
  RET_SUCCESS = 0,
  RET_ERROR_UNKNOWN,	/* something shouldn't happened */
  RET_NOT_SUPPORT,
  RET_NOT_IMPLEMENT,
  RET_NOT_INITIAL,
  RET_INVALID_PARAM,
  RET_DATA_SIZE_NOT_MATCH,
  RET_BUF_TOO_SMALL,
  RET_TIMEOUT,
  RET_HW_ERROR,
} RET_STATUS;

enum MODE_TYPE
{
  MODE_0_NORMAL = 0,
  MODE_1_WAKE_UP,
  MODE_2_POWER_SAVIN,
  MODE_3_SLEEP,
  MODE_INIT = 0xFF
};

//SPED+
enum SLEEP_MODE_CMD_TYPE
{
  W_CFG_PWR_DWN_SAVE = 0xC0,
  R_CFG              = 0xC1,
  W_CFG_PWR_DWN_LOSE = 0xC2,
  R_MODULE_VERSION   = 0xC3,
  W_RESET_MODULE     = 0xC4
};

enum UART_FORMAT_TYPE
{
  UART_FORMAT_8N1 = 0x00,  /*no   parity bit one stop*/
  UART_FORMAT_8O1 = 0x01,  /*odd  parity bit one stop*/
  UART_FORMAT_8E1 = 0x02   /*even parity bitone stop*/
};

enum UART_BPS_TYPE
{
  UART_BPS_1200 = 0x00,
  UART_BPS_9600 = 0x03,
  UART_BPS_115200 = 0x07
};

enum AIR_BPS_TYPE
{
  AIR_BPS_300   = 0x00,
  AIR_BPS_2400  = 0x02,
  AIR_BPS_19200 = 0x05
};
//SPED-

//410~441MHz : 410M + CHAN*1M
enum AIR_CHAN_TYPE
{
  AIR_CHAN_410M = 0x00,
  AIR_CHAN_433M = 0x17,
  AIR_CHAN_441M = 0x1F
};

//OPTION+
#define TRSM_TT_MODE		0x00	/*Transparent Transmission*/
#define TRSM_FP_MODE		0x01	/*Fixed-point transmission mode*/

#define OD_DRIVE_MODE		0x00
#define PP_DRIVE_MODE		0x01

enum WEAK_UP_TIME_TYPE
{
  WEAK_UP_TIME_250  = 0x00,
  WEAK_UP_TIME_1000 = 0x03,
  WEAK_UP_TIME_2000 = 0x07
};

#define DISABLE_FEC			0x00
#define ENABLE_FEC			0x01

//Transmit power
enum TSMT_PWR_TYPE
{
  TSMT_PWR_20DB = 0x00,
  TSMT_PWR_17DB = 0x01,
  TSMT_PWR_14DB = 0x02,
  TSMT_PWR_10DB = 0x03
};
//OPTION-

#pragma pack(push, 1)
struct SPEDstruct {
  uint8_t air_bps : 3; //bit 0-2
  uint8_t uart_bps: 3; //bit 3-5
  uint8_t uart_fmt: 2; //bit 6-7
};

struct OPTIONstruct {
  uint8_t tsmt_pwr    : 2; //bit 0-1
  uint8_t enFWC       : 1; //bit 2
  uint8_t wakeup_time : 3; //bit 3-5
  uint8_t drive_mode  : 1; //bit 6
  uint8_t trsm_mode   : 1; //bit 7
};

struct CFGstruct {
  uint8_t HEAD;
  uint8_t ADDH;
  uint8_t ADDL;
  struct SPEDstruct   SPED_bits;
  uint8_t CHAN;
  struct OPTIONstruct OPTION_bits;
};

struct MVerstruct {
  uint8_t HEAD;
  uint8_t Model;
  uint8_t Version;
  uint8_t features;
};
#pragma pack(pop)


#define Device_A

#define TIME_OUT_CNT	100
#define MAX_TX_SIZE		58

#define DEVICE_A_ADDR_H 0x05
#define DEVICE_A_ADDR_L 0x01
#define DEVICE_B_ADDR_H 0x05
#define DEVICE_B_ADDR_L 0x02

#endif /* E32-TTL-100_H_ */
