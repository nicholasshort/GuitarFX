# GuitarFX

This is a digital guitar effects pedal designed as a generic DSP platform. So far, I've writtsimple algorithms such as volume and simple tone control, however I am planning to implement more exciting effects soon! Namely, hard and soft clipping, digital delay, and much more. The two knobs control various parameters within the current algorithm, such volume or cutoff frequency.

![Assembled board](images/board.jpeg)
![Enclosure](images/enclosure.jpeg)

## Hardware

- **MCU**: STM32H723VGT6 (Cortex-M7 @ 550 MHz)
- **Codec**: TI PCM3060 — 24-bit stereo ADC/DAC
- **Analog I/O**: TLV9161 op-amp buffers with 25 kHz Butterworth anti-aliasing and reconstruction filters
- **Audio**: Standard 1/4" guitar input and output, true-bypass footswitch
- **Controls**: 2 × potentiometers, RGB status LED
- **Power**: 9 V DC barrel jack (USB-C can also power the board for bench work)
- **PCB**: 4-layer, KiCad

## Repository layout

- `GuitarFX-PCB/` — KiCad project (schematics, board, libraries)
- `GuitarFX-PCB/Manufacturing/` — Gerbers, BOM, and pick-and-place files for JLCPCB
- `images/` — Photos of the board and enclosure
