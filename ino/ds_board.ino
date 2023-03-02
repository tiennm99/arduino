#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#define RX_PIN 2
#define TX_PIN 3

SoftwareSerial bluetooth(RX_PIN, TX_PIN);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
byte blue = 0;
int i;

void setup()
{
	bluetooth.begin(9600);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, INPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	/*
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
	pinMode(7, INPUT);
	pinMode(8, INPUT);
	pinMode(9, INPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(12, INPUT);
	pinMode(13, INPUT);
	*/
	lcd.backlight();
	lcd.begin(16, 2);
}

void loop()
{
	for (i = 0; i <= 13; i++)
	{
		lcd.setCursor(i, 0);
		lcd.print(digitalRead(i));
	}
	if (bluetooth.available())
	{
		blue = bluetooth.read();
		bluetooth.println(blue);
	}
	if (blue)
	{
		if (digitalRead(blue))
		{
			digitalWrite(blue, LOW);
		}
		else
		{
			digitalWrite(blue, HIGH);
		}
		blue = 0;
		delay(5);
	}
	delay(5);
}
