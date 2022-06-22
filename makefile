program: build
	teensy_loader_cli -ws --mcu=TEENSYLC build/teensy.avr.teensyLC/reminder-button-arduino.ino.hex

build: reminder-button-arduino.ino.hex

reminder-button-arduino.ino.hex: reminder-button-arduino.ino
	arduino-cli compile --export-binaries --fqbn teensy:avr:teensyLC reminder-button-arduino
	cp build/teensy.avr.teensyLC/reminder-button-arduino.ino.hex .

watch:
	echo "reminder-button-arduino.ino" | entr -c $(MAKE)
