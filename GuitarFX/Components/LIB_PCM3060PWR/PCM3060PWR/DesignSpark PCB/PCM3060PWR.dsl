SamacSys ECAD Model
343680/1063637/2.50/28/3/Integrated Circuit

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r147.5_45"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.45) (shapeHeight 1.475))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "SOP65P640X120-28N" (originalName "SOP65P640X120-28N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r147.5_45) (pt -2.938, 4.225) (rotation 90))
			(pad (padNum 2) (padStyleRef r147.5_45) (pt -2.938, 3.575) (rotation 90))
			(pad (padNum 3) (padStyleRef r147.5_45) (pt -2.938, 2.925) (rotation 90))
			(pad (padNum 4) (padStyleRef r147.5_45) (pt -2.938, 2.275) (rotation 90))
			(pad (padNum 5) (padStyleRef r147.5_45) (pt -2.938, 1.625) (rotation 90))
			(pad (padNum 6) (padStyleRef r147.5_45) (pt -2.938, 0.975) (rotation 90))
			(pad (padNum 7) (padStyleRef r147.5_45) (pt -2.938, 0.325) (rotation 90))
			(pad (padNum 8) (padStyleRef r147.5_45) (pt -2.938, -0.325) (rotation 90))
			(pad (padNum 9) (padStyleRef r147.5_45) (pt -2.938, -0.975) (rotation 90))
			(pad (padNum 10) (padStyleRef r147.5_45) (pt -2.938, -1.625) (rotation 90))
			(pad (padNum 11) (padStyleRef r147.5_45) (pt -2.938, -2.275) (rotation 90))
			(pad (padNum 12) (padStyleRef r147.5_45) (pt -2.938, -2.925) (rotation 90))
			(pad (padNum 13) (padStyleRef r147.5_45) (pt -2.938, -3.575) (rotation 90))
			(pad (padNum 14) (padStyleRef r147.5_45) (pt -2.938, -4.225) (rotation 90))
			(pad (padNum 15) (padStyleRef r147.5_45) (pt 2.938, -4.225) (rotation 90))
			(pad (padNum 16) (padStyleRef r147.5_45) (pt 2.938, -3.575) (rotation 90))
			(pad (padNum 17) (padStyleRef r147.5_45) (pt 2.938, -2.925) (rotation 90))
			(pad (padNum 18) (padStyleRef r147.5_45) (pt 2.938, -2.275) (rotation 90))
			(pad (padNum 19) (padStyleRef r147.5_45) (pt 2.938, -1.625) (rotation 90))
			(pad (padNum 20) (padStyleRef r147.5_45) (pt 2.938, -0.975) (rotation 90))
			(pad (padNum 21) (padStyleRef r147.5_45) (pt 2.938, -0.325) (rotation 90))
			(pad (padNum 22) (padStyleRef r147.5_45) (pt 2.938, 0.325) (rotation 90))
			(pad (padNum 23) (padStyleRef r147.5_45) (pt 2.938, 0.975) (rotation 90))
			(pad (padNum 24) (padStyleRef r147.5_45) (pt 2.938, 1.625) (rotation 90))
			(pad (padNum 25) (padStyleRef r147.5_45) (pt 2.938, 2.275) (rotation 90))
			(pad (padNum 26) (padStyleRef r147.5_45) (pt 2.938, 2.925) (rotation 90))
			(pad (padNum 27) (padStyleRef r147.5_45) (pt 2.938, 3.575) (rotation 90))
			(pad (padNum 28) (padStyleRef r147.5_45) (pt 2.938, 4.225) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 30)
			(line (pt -3.925 5.15) (pt 3.925 5.15) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 3.925 5.15) (pt 3.925 -5.15) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 3.925 -5.15) (pt -3.925 -5.15) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt -3.925 -5.15) (pt -3.925 5.15) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -2.2 4.85) (pt 2.2 4.85) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 2.2 4.85) (pt 2.2 -4.85) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 2.2 -4.85) (pt -2.2 -4.85) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -2.2 -4.85) (pt -2.2 4.85) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -2.2 4.2) (pt -1.55 4.85) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.85 4.85) (pt 1.85 4.85) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.85 4.85) (pt 1.85 -4.85) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.85 -4.85) (pt -1.85 -4.85) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.85 -4.85) (pt -1.85 4.85) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3.675 4.8) (pt -2.2 4.8) (width 0.2))
		)
	)
	(symbolDef "PCM3060PWR" (originalName "PCM3060PWR")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 4) (pt 0 mils -300 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -325 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 5) (pt 0 mils -400 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -425 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 6) (pt 0 mils -500 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -525 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 7) (pt 0 mils -600 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -625 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 8) (pt 0 mils -700 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -725 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 9) (pt 0 mils -800 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -825 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 10) (pt 0 mils -900 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -925 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 11) (pt 0 mils -1000 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -1025 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 12) (pt 0 mils -1100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -1125 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 13) (pt 0 mils -1200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -1225 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 14) (pt 0 mils -1300 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -1325 mils) (rotation 0]) (justify "Left") (textStyleRef "Default"))
		))
		(pin (pinNum 15) (pt 1900 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 16) (pt 1900 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 17) (pt 1900 mils -200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -225 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 18) (pt 1900 mils -300 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -325 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 19) (pt 1900 mils -400 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -425 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 20) (pt 1900 mils -500 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -525 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 21) (pt 1900 mils -600 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -625 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 22) (pt 1900 mils -700 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -725 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 23) (pt 1900 mils -800 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -825 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 24) (pt 1900 mils -900 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -925 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 25) (pt 1900 mils -1000 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -1025 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 26) (pt 1900 mils -1100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -1125 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 27) (pt 1900 mils -1200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -1225 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(pin (pinNum 28) (pt 1900 mils -1300 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 1670 mils -1325 mils) (rotation 0]) (justify "Right") (textStyleRef "Default"))
		))
		(line (pt 200 mils 100 mils) (pt 1700 mils 100 mils) (width 6 mils))
		(line (pt 1700 mils 100 mils) (pt 1700 mils -1400 mils) (width 6 mils))
		(line (pt 1700 mils -1400 mils) (pt 200 mils -1400 mils) (width 6 mils))
		(line (pt 200 mils -1400 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 1750 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "PCM3060PWR" (originalName "PCM3060PWR") (compHeader (numPins 28) (numParts 1) (refDesPrefix IC)
		)
		(compPin "1" (pinName "MC/SCL/FMT") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "MD/SDA/DEMP") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "DOUT") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "4" (pinName "LRCK1") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "5" (pinName "BCK1") (partNum 1) (symPinNum 5) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "6" (pinName "SCKI1") (partNum 1) (symPinNum 6) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "7" (pinName "VDD") (partNum 1) (symPinNum 7) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "8" (pinName "DGND") (partNum 1) (symPinNum 8) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "9" (pinName "SCKI2") (partNum 1) (symPinNum 9) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "10" (pinName "BCK2") (partNum 1) (symPinNum 10) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "11" (pinName "LRCK2") (partNum 1) (symPinNum 11) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "12" (pinName "DIN") (partNum 1) (symPinNum 12) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "13" (pinName "ZEROR") (partNum 1) (symPinNum 13) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "14" (pinName "ZEROL") (partNum 1) (symPinNum 14) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "28" (pinName "MODE") (partNum 1) (symPinNum 15) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "27" (pinName "__MS__/ADR/IFMD") (partNum 1) (symPinNum 16) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "26" (pinName "VINR") (partNum 1) (symPinNum 17) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "25" (pinName "VINL") (partNum 1) (symPinNum 18) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "24" (pinName "VCC") (partNum 1) (symPinNum 19) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "23" (pinName "AGND1") (partNum 1) (symPinNum 20) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "22" (pinName "AGND2") (partNum 1) (symPinNum 21) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "21" (pinName "VCOM") (partNum 1) (symPinNum 22) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "20" (pinName "VOUTL+") (partNum 1) (symPinNum 23) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "19" (pinName "VOUTL-") (partNum 1) (symPinNum 24) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "18" (pinName "VOUTR+") (partNum 1) (symPinNum 25) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "17" (pinName "VOUTR-") (partNum 1) (symPinNum 26) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "16" (pinName "SGND") (partNum 1) (symPinNum 27) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "15" (pinName "__RST") (partNum 1) (symPinNum 28) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "PCM3060PWR"))
		(attachedPattern (patternNum 1) (patternName "SOP65P640X120-28N")
			(numPads 28)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
				(padNum 5) (compPinRef "5")
				(padNum 6) (compPinRef "6")
				(padNum 7) (compPinRef "7")
				(padNum 8) (compPinRef "8")
				(padNum 9) (compPinRef "9")
				(padNum 10) (compPinRef "10")
				(padNum 11) (compPinRef "11")
				(padNum 12) (compPinRef "12")
				(padNum 13) (compPinRef "13")
				(padNum 14) (compPinRef "14")
				(padNum 15) (compPinRef "15")
				(padNum 16) (compPinRef "16")
				(padNum 17) (compPinRef "17")
				(padNum 18) (compPinRef "18")
				(padNum 19) (compPinRef "19")
				(padNum 20) (compPinRef "20")
				(padNum 21) (compPinRef "21")
				(padNum 22) (compPinRef "22")
				(padNum 23) (compPinRef "23")
				(padNum 24) (compPinRef "24")
				(padNum 25) (compPinRef "25")
				(padNum 26) (compPinRef "26")
				(padNum 27) (compPinRef "27")
				(padNum 28) (compPinRef "28")
			)
		)
		(attr "Manufacturer_Name" "Texas Instruments")
		(attr "Manufacturer_Part_Number" "PCM3060PWR")
		(attr "Mouser Part Number" "595-PCM3060PWR")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/PCM3060PWR?qs=W5eanQMd1BA4oHiQoX9kuw%3D%3D")
		(attr "Arrow Part Number" "PCM3060PWR")
		(attr "Arrow Price/Stock" "https://www.arrow.com/en/products/pcm3060pwr/texas-instruments?utm_currency=USD&region=nac")
		(attr "Description" "24-bit Asynchronous Stereo Audio Codec with 96/192kHz sampling rate")
		(attr "Datasheet Link" "https://www.ti.com/lit/ds/symlink/pcm3060.pdf?ts=1606824200789&ref_url=https%253A%252F%252Fwww.ti.com%252Fstore%252Fti%252Fen%252Fp%252Fproduct%252F%253Fp%253DPCM3060PWR%2526keyMatch%253DPCM3060PWR%2526tisearch%253DSearch-EN-everything%2526usecase%253DOPN")
		(attr "Height" "1.2 mm")
	)

)
