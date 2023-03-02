#include <SoftwareSerial.h>

#define	RX_PIN	2
#define	TX_PIN	3
#define	MAX_SPEED	255
#define MIN_SPEED	0
#define	IN1	4
#define	IN2	5
#define	PIN	12

SoftwareSerial bluetooth(RX_PIN, TX_PIN);

String s = "", key = "WT%u1FylV5UD@9*q";
bool b = 1;

void setup()
{
	bluetooth.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(PIN, INPUT_PULLUP);
}

void go(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	digitalWrite(IN1, HIGH);
	analogWrite(IN2, 255 - speed);
}

void back(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);
	digitalWrite(IN1, LOW);
	analogWrite(IN2, speed);
}

void stop()
{
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
}

void loop()
{
  b = digitalRead(PIN);
	if (bluetooth.available())
	{
		s = s + char(bluetooth.read());
	}
	if (s == key)
	{
    s = "";
    go(MAX_SPEED);
    delay(3000);
    stop();
  }
  if (b == 0)
  {
    b = 1;
    back(MAX_SPEED);
    delay(2750);
    stop();
	}
}
