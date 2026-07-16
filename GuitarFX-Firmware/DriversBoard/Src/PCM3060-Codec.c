/*
 * PCM3060-Codec.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Nicholas Short
 */

#include "PCM3060-Codec.h"
#include "i2c.h"

// I2C handle and reset pin definitions
#define PCM3060_I2C_HANDLE 		hi2c2
#define PCM3060_NRST_GPIO_PORT 	CODEC_NRST_GPIO_Port
#define PCM3060_NRST_GPIO_PIN 	CODEC_NRST_Pin

// I2C address
#define PCM3060_I2C_ADDRESS		(0x46 << 1) // 0b[100011 ADR], ADR set to 0 on PCB --> 0b1000110 = 0x46

// Register addresses
#define PCM3060_REG_64		0x40
#define PCM3060_REG_65		0x41
#define PCM3060_REG_66		0x42
#define PCM3060_REG_67		0x43
#define PCM3060_REG_68		0x44
#define PCM3060_REG_69		0x45
#define PCM3060_REG_70		0x46
#define PCM3060_REG_71		0x47
#define PCM3060_REG_72		0x48
#define PCM3060_REG_73		0x49

static uint8_t PCM3060_REG_CONFIG_SETTINGS[10] = {	0xC1, /* (REG_64) Enable single ended mode for DAC */
											0xFF, /* (REG_65) No attenuation for left channel of DAC */
											0x00, /* (REG_66) Mute right channel for DAC */
											0x80, /* (REG_67) Select SCK1 for DAC */
											0x02, /* (REG_68) Default oversampling rate, soft mute right channel DAC */
											0x00, /* (REG_69) */
											0xD7, /* (REG_70) No attenuation for left channel of ADC */
											0x00, /* (REG_71) Mute right channel for ADC */
											0x00, /* (REG_72) */
											0x02  /* (REG_73) Mute right channel for ADC on DOUT*/ };


static HAL_StatusTypeDef PCM3060_RegWrite(uint8_t regAddr, uint8_t regData) {

	return HAL_I2C_Mem_Write(&PCM3060_I2C_HANDLE, PCM3060_I2C_ADDRESS, regAddr, I2C_MEMADD_SIZE_8BIT, &regData, 1, HAL_MAX_DELAY);

}

static HAL_StatusTypeDef PCM3060_RegRead(uint8_t regAddr, uint8_t* regData) {

	return HAL_I2C_Mem_Read(&PCM3060_I2C_HANDLE, PCM3060_I2C_ADDRESS, regAddr, I2C_MEMADD_SIZE_8BIT, regData, 1, HAL_MAX_DELAY);

}

uint8_t PCM3060_Init() {

	HAL_StatusTypeDef i2c_status;

	PCM3060_Reset();

	int8_t regIndex;
	uint8_t regData;

	for (regIndex = PCM3060_REG_73; regIndex >= PCM3060_REG_64; regIndex--) {

		i2c_status = PCM3060_RegWrite(regIndex, PCM3060_REG_CONFIG_SETTINGS[regIndex - PCM3060_REG_64]);

		if(i2c_status != HAL_OK) {

			return regIndex;

		}

		i2c_status = PCM3060_RegRead(regIndex, &regData);

		if ((i2c_status != HAL_OK) || (regData != PCM3060_REG_CONFIG_SETTINGS[regIndex - PCM3060_REG_64])) {

			return regIndex;

		}

	}

	return 0;

}

void PCM3060_Reset() {

	HAL_GPIO_WritePin(PCM3060_NRST_GPIO_PORT, PCM3060_NRST_GPIO_PIN, GPIO_PIN_RESET);
	HAL_Delay(25);

	HAL_GPIO_WritePin(PCM3060_NRST_GPIO_PORT, PCM3060_NRST_GPIO_PIN, GPIO_PIN_SET);
	HAL_Delay(25);

}


