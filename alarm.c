#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
int i;
int q;
wiringPiSetup();
pinMode(0, INPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);


while(1) {

printf("Waiting for reset\n");
while(digitalRead(0) == 0) {
	printf("Waiting for event \n");
	digitalWrite(1, HIGH);
	delay(200);
	digitalWrite(1, LOW);
	delay(200);
}


while(digitalRead(0) == 1){
	printf("Alarm\n");
	 ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "215428659", "Lab4", "Alarm");
	printf("Sending data to server\n");
	for(i = 0; i < 5; i++) { 
	digitalWrite(2, HIGH);
	delay(200);
	digitalWrite(2, LOW);
	delay(200);
	}
	}
	

}
/*NOTREACHED*/
return 0;
}
