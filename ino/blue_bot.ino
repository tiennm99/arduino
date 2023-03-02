#include <SoftwareSerial.h>
#define IN1			7
#define IN2			6
#define IN3			5
#define IN4			4
#define DENTRUOC	8
#define DENSAU		9
#define DENTRAI		10
#define DENPHAI		11
#define RX_PIN		2
#define TX_PIN 		3
#define MAX_SPEED	255
#define MIN_SPEED	0

SoftwareSerial bluetooth(RX_PIN, TX_PIN);
byte blue =0;
unsigned long long time_trai = 0, time_phai = 0;
bool den_trai = 0, den_phai = 0;

void setup()
{
	bluetooth.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	pinMode(DENTRUOC, OUTPUT);
	pinMode(DENSAU, OUTPUT);
	pinMode(DENTRAI, OUTPUT);
	pinMode(DENPHAI, OUTPUT);
}

void motor_1_Dung()
{
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
}

void motor_2_Dung()
{
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}

void motor_1_Tien(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	digitalWrite(IN1, HIGH);
	analogWrite(IN2, 255 - speed);
}

void motor_2_Tien(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	digitalWrite(IN4, HIGH);
	analogWrite(IN3, 255 - speed);
}

void motor_1_Lui(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	digitalWrite(IN1, LOW);
	analogWrite(IN2, speed);
}

void motor_2_Lui(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	digitalWrite(IN4, LOW);
	analogWrite(IN3, speed);
}

void loop()
{
	if (bluetooth.available())
	{
		blue = bluetooth.read();
		bluetooth.println(blue);
	}
	switch (blue)
	{
		case 1:
		{
			motor_1_Dung();
			motor_2_Tien(MAX_SPEED);
			blue = 0;
			delay(5);
			break;
		}
		case 2:
		{
			motor_1_Tien(MAX_SPEED);
			motor_2_Tien(MAX_SPEED);
			blue = 0;
			delay(5);
			break;
		}
		case 3:
		{
			motor_1_Tien(MAX_SPEED);
			motor_2_Dung();
			blue = 0;
			delay(5);
			break;
		}
		case 4:
		{
			motor_1_Lui(MAX_SPEED);
			motor_2_Tien(MAX_SPEED);
			blue = 0;
			delay(5);
			break;
		}
		case 5:
		{
			if (digitalRead(DENTRUOC) == LOW)
			{
				digitalWrite(DENTRUOC, HIGH);
			}
			else
			{
				digitalWrite(DENTRUOC, LOW);
			}
			blue = 0;
			delay(5);
			break;
		}
		case 6:
		{
			motor_1_Tien(MAX_SPEED);
			motor_2_Lui(MAX_SPEED);
			blue = 0;
			delay(5);
			break;
		}
		case 7:
		{
			motor_1_Dung();
			motor_2_Lui(MAX_SPEED);
			blue = 0;
			delay(5);
			break;
		}
		case 8:
		{
			motor_1_Lui(MAX_SPEED);
			motor_2_Lui(MAX_SPEED);
			blue = 0;
			delay(5);
			break;
		}
		case 9:
		{
			motor_2_Dung();
			motor_1_Lui(MAX_SPEED);
			blue = 0;
			delay(5);
			break;
		}
		case 10:
		{
			den_trai = !den_trai;
			if (den_trai == 0)
			{
				digitalWrite(DENTRAI, LOW);
			}
			blue = 0;
			delay(5);
			break;
		}
		case 11:
		{
			if (digitalRead(DENSAU) == LOW)
			{
				digitalWrite(DENSAU, HIGH);
			}
			else
			{
				digitalWrite(DENSAU, LOW);
			}
			blue = 0;
			delay(5);
			break;
		}
		case 12:
		{
			den_phai = !den_phai;
			if (den_phai == 0)
			{
				digitalWrite(DENPHAI, LOW);
			}
			blue = 0;
			delay(5);
			break;
		}
		case 13:
		{
			motor_1_Dung();
			motor_2_Dung();
			blue = 0;
			delay(5);
			break;
		}
	}
	if (den_trai)
	{
		if ((unsigned long long)(millis() - time_trai) > 100)
		{
			if (digitalRead(DENTRAI) == LOW)
			{
				digitalWrite(DENTRAI, HIGH);
			}
			else
			{
				digitalWrite(DENTRAI, LOW);
			}
			time_trai = millis();
		}
	}
	if (den_phai)
	{
		if ((unsigned long long)(millis() - time_phai) > 100)
		{
			if (digitalRead(DENPHAI) == LOW)
			{
				digitalWrite(DENPHAI, HIGH);
			}
			else
			{
				digitalWrite(DENPHAI, LOW);
			}
			time_phai = millis();
		}
	}
	delay(5);
}
