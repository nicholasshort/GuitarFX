/*
 * PCM3060-Codec.h
 *
 *  Created on: Oct 31, 2024
 *      Author: Nicholas Short
 */

#ifndef INC_PCM3060_CODEC_H_
#define INC_PCM3060_CODEC_H_

#include "main.h"

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

extern uint8_t PCM3060_REG_CONFIG_SETTINGS[10];

// I2C handle
extern I2C_HandleTypeDef PCM3060_I2C_HANDLE;

// Functions
uint8_t PCM3060_Init();
void	PCM3060_Reset();

HAL_StatusTypeDef PCM3060_RegWrite(uint8_t regAddr, uint8_t regData);
HAL_StatusTypeDef PCM3060_RegRead(uint8_t regAddr, uint8_t* regData);

#endif /* INC_PCM3060_CODEC_H_ */
