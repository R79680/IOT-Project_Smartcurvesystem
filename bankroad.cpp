

#include<math.h>

enum declare{
Low,
High,};
//Declare Pins for Leds
const int Green_led=9;
const int Yellow_led=8;
const int Red_led=7;
const int Buzzer=6;
const int radius=20;//Radius of curveture of that road
const int gravity=10;
bool execute=false;

 int velocity=0;//velocity to get input of user;
int Evelocity=0;//Expected velocity on that turn of mountains;

void setup(){
Serial.begin(9600);
//Setup pins for ardino
pinMode(Green_led,OUTPUT);
pinMode(Yellow_led,OUTPUT);
pinMode(Red_led,OUTPUT);
pinMode(Buzzer,OUTPUT);


}
void loop(){

	if(execute==false){

Evelocity=sqrt(radius*gravity*1);
Serial.println("For this road safe speed is:  ");
Serial.println(Evelocity);
execute=true;	}
	Serial.println("Please enter Speed of your Car : ");
	while(Serial.available() == 0){
	}
	velocity= Serial.parseInt();
	if(velocity<Evelocity){
		digitalWrite(Green_led,High);
		delay(1000);
		digitalWrite(Green_led,Low);
	}
	if(velocity==Evelocity){
	digitalWrite(Yellow_led,High);
	delay(1000);
	digitalWrite(Yellow_led,Low);



	}
	if(velocity>Evelocity){
	digitalWrite(Red_led,High);
	digitalWrite(Buzzer,High);
	delay(1000);
	digitalWrite(Red_led,Low);
	digitalWrite(Buzzer,Low);
	delay(1000);


	}



}





