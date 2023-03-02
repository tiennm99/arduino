#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
byte temp, i, j;

void setup()
{
	Serial.begin(9600);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(12, INPUT);
	pinMode(13, INPUT);
  lcd.backlight();
  lcd.begin(16, 2);
}

void loop()
{
	if (Serial.available())
	{
		temp = Serial.read();
    temp = temp - 48;
    Serial.println(temp);
    if (digitalRead(temp))
    {
      digitalWrite(temp, LOW);
    }
    else
    {
      digitalWrite(temp, HIGH);
    }
	}
	for (i = 2; i <= 13; i++)
	{
		j = digitalRead(i);
		lcd.setCursor(i, 0);
		lcd.print(j);
	}
}
