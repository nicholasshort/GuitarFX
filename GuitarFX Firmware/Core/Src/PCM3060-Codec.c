/*
 * PCM3060-Codec.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Nicholas Short
 */

#include "PCM3060-Codec.h"

uint8_t PCM3060_REG_CONFIG_SETTINGS[10] = {	0xC1, /* (REG_64) Enable single ended mode for DAC */
											0xFF, /* (REG_65) No attenuation for left channel of DAC */
											0x00, /* (REG_66) Mute right channel for DAC */
											0x80, /* (REG_67) Select SCK1 for DAC */
											0x02, /* (REG_68) Default oversampling rate, soft mute right channel DAC */
											0x00, /* (REG_69) */
											0xD7, /* (REG_70) No attenuation for left channel of ADC */
											0x00, /* (REG_71) Mute right channel for ADC */
											0x00, /* (REG_72) */
											0x02  /* (REG_73) Mute right channel for ADC on DOUT*/ };

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

HAL_StatusTypeDef PCM3060_RegWrite(uint8_t regAddr, uint8_t regData) {

	return HAL_I2C_Mem_Write(&PCM3060_I2C_HANDLE, PCM3060_I2C_ADDRESS, regAddr, I2C_MEMADD_SIZE_8BIT, &regData, 1, HAL_MAX_DELAY);

}

HAL_StatusTypeDef PCM3060_RegRead(uint8_t regAddr, uint8_t* regData) {

	return HAL_I2C_Mem_Read(&PCM3060_I2C_HANDLE, PCM3060_I2C_ADDRESS, regAddr, I2C_MEMADD_SIZE_8BIT, regData, 1, HAL_MAX_DELAY);

}


