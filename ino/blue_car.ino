#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
#define MAX_SPEED 255	//SPEED: tu 0 den 255
#define MIN_SPEED 0

byte blue =0;	//bien nhan du lieu qua bluetooth

void setup()
{
	Serial.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
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

void motor_1_Tien(int speed)	//speed: tu 0 den MAX_SPEED
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);	//dam bao gia tri nam trong mot khoang tu 0 den MAX_SPEED
	digitalWrite(IN1, HIGH);	//chan nay khong co PWM
	analogWrite(IN2, 255 - speed);
}

void motor_2_Tien(int speed)	//speed: tu 0 den MAX_SPEED
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);	//dam bao gia tri nam trong mot khoang tu 0 den MAX_SPEED
	digitalWrite(IN4, HIGH);	//chan nay khong co PWM
	analogWrite(IN3, 255 - speed);
}

void motor_1_Lui(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);	//dam bao gia tri nam trong mot khoang tu 0 den MAX_SPEED
	digitalWrite(IN1, LOW);	//chan nay khong co PWM
	analogWrite(IN2, speed);
}

void motor_2_Lui(int speed)
{
	speed = constrain(speed, MIN_SPEED, MAX_SPEED);	//dam bao gia tri nam trong mot khoang tu 0 den MAX_SPEED
	digitalWrite(IN4, LOW);	//chan nay khong co PWM
	analogWrite(IN3, speed);
}

void loop()
{
	if (Serial.available() > 0)
	{
		blue = Serial.read();
	}
	if (blue == 49)	//tien((ma ASCII cua 1 la 49)
	{
		motor_1_Tien(MAX_SPEED);
		motor_2_Tien(MAX_SPEED);
		blue = 0;
		delay(5);
	}
	if (blue == 50)	//lui((ma ASCII cua 2 la 50)
	{
		motor_1_Lui(MAX_SPEED);
		motor_2_Lui(MAX_SPEED);
		blue = 0;
		delay(5);
	}
	if (blue == 51)	//xoay trai((ma ASCII cua 3 la 51)
	{
		motor_1_Lui(MAX_SPEED);
		motor_2_Tien(MAX_SPEED);
		blue = 0;
		delay(5);
	}
	if (blue == 52)	//xoay phai(ma ASCII cua 4 la 52)
	{
		motor_1_Tien(MAX_SPEED);
		motor_2_Lui(MAX_SPEED);
		blue = 0;
		delay(5);
	}
	if (blue == 54)	//dung(ma ASCII cua 6 la 54)
	{
		motor_1_Dung();
		motor_2_Dung();
		blue = 0;
		delay(5);
	}
	delay(5);
}
