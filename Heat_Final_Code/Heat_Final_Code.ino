#include <LiquidCrystal.h> 
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 7


/*ThermoCouple Pins*/
/**********************************/
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celcius = 0;

/*********************************/

/*LCD Pins*/
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 1, d7 = 2;
LiquidCrystal lcd(12, 11, 5, 4, 1, 2);
/*************************************/

/*Bridge Pins*/
const int pwm = 3 ;  //initializing pin 3 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;
/*********************/




void setup() 
{
sensors.begin();  
lcd.begin(16, 2);
lcd.clear();
pinMode(10, OUTPUT);
analogWrite(10, 0);
pinMode(in_1, OUTPUT);
pinMode(in_2, OUTPUT);
Serial.begin(9600); 
}


void loop() 
{
sensors.requestTemperatures(); 
Celcius=sensors.getTempCByIndex(0);
lcd.setCursor(0, 0);
lcd.print("Temp = ");
lcd.setCursor(10, 0);
lcd.print(Celcius);
delay(1000);
/*digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW) ;
analogWrite(pwm,255) ;*/
Serial.print(Celcius);
Serial.print("\n");
lcd.setCursor(0, 0);
lcd.print("Temp = ");
lcd.print(Celcius);


 if(Celcius >= 26 )
   {
    digitalWrite(in_1,LOW) ;
    digitalWrite(in_2,LOW) ;

   }

   
   else  if(Celcius < 26)
   {
     digitalWrite(in_1,HIGH) ;
     digitalWrite(in_2,LOW) ;
     analogWrite(pwm,255) ;
   }
   

   else if( Celcius < 25)
   {
    digitalWrite(in_1,HIGH) ;
    digitalWrite(in_2,LOW) ;
    analogWrite(pwm,255) ;
   }
 


}
