#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
#pragma pack(push,1)
#define PACKED
#else
#define PACKED __attribute__((packed))
#endif

typedef enum  _neoRADIO2DIN_InputMode {
	neoRADIO2DIN_MODE_DISABLE	= 0,
	neoRADIO2DIN_MODE_DIGITAL	= 1,
	neoRADIO2DIN_MODE_PWM		= 2,
	neoRADIO2DIN_MODE_PERIOD	= 3,
	neoRADIO2DIN_MODE_FREQ		= 4,
	neoRADIO2DIN_MODE_ANALOG	= 5,
} neoRADIO2DIN_InputMode;

typedef enum  _neoRADIO2DOUT_State {
	neoRADIO2DOUT_SET_HIZ		= 0,
	neoRADIO2DOUT_SET_LOW_REV	= 1,
	neoRADIO2DOUT_SET_HIGH_FWD	= 2,
	neoRADIO2DOUT_SET_BRAKE		= 3,
} neoRADIO2DOUT_OutputState;

typedef enum  _neoRADIO2DOUT_Config {
	neoRADIO2DOUT_CONFIG_DISABLE	= 0,
	neoRADIO2DOUT_CONFIG_DIGITAL	= 1,
	neoRADIO2DOUT_CONFIG_PWM		= 2,
	neoRADIO2DOUT_CONFIG_ONESHOT	= 3,
} neoRADIO2DOUT_Config;

typedef union _neoRADIO2DOUT_header {
	uint8_t byte;
	struct {
		unsigned channel:1;
		unsigned output_config:3;
		unsigned output_state:2;
		unsigned invert:1;
		unsigned hbridge:1;
	} bits;
} neoRADIO2DOUT_header;

typedef union _neoRADIO2DIN_channelConfig{ 
	uint32_t u32;
	struct {
		uint8_t prescale;
		uint8_t tripVoltage;
		uint8_t mode;
		unsigned invert:1;
		unsigned enable:1;
		unsigned reserved:6;
	} data;
} PACKED neoRADIO2DIN_channelConfig;

typedef union _neoRADIO2DOUT_channelConfig{
	uint32_t u32;
	struct {
		uint8_t prescale;
		unsigned enable:1;
		unsigned reserved:3;
	} data;
} PACKED neoRADIO2DOUT_channelConfig;

typedef union _neoRADIO2DIN_frameHeader {
	uint8_t bytes[2];
	struct {
		unsigned mode_ch1:4;
		unsigned write_ch1:1;
		unsigned write_ch2:1;
		unsigned write_ch3:1;
		unsigned store_settings:1;
		unsigned mode_ch3:4;
		unsigned mode_ch2:4;
	} PACKED bits;
} PACKED neoRADIO2DIN_frameHeader;

typedef struct _neoRADIO2DIN_frame
{
	neoRADIO2DIN_frameHeader header;
	uint16_t channel1_data;
	uint16_t channel2_data;
	uint16_t channel3_data;
} PACKED neoRADIO2DIN_frame;

#ifdef _MSC_VER
#pragma pack(pop)
#undef PACKED
#else
#undef PACKED
#endif

#ifdef __cplusplus
}
#endif
