/*
LEDs WS2812B
 Copy of the Biegert&Funk QlockTwo reprogramming by volvodani. 
 Licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
 Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file 
 except in compliance with the License.  You may obtain a copy of the License at
 http://www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software distributed under the 
 License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, 
 either express or implied. See the License for the specific language governing permissions 
 and limitations under the License.
 */

#include <Wire.h>
#include <EEPROM.h>
#include "FastLED.h"
#include <avr/wdt.h>


#define RTC_ADDRESS 0x68       // I2C Address of RTC 0x68
#define STELLEN 8               // REED STELLEN Pin
#define MINUS 9                 // REED MINUS
#define PLUS 10                 // REED PLUS
#define SEKUNDEN 11             // REED SEKUNDEN
#define RTCIN 4                // SQW Output of RTC connected here
#define TIME 750               // Split time between short and lognpress

#define DATA_PIN     5
#define NUM_LEDS    114
#define CHIPSET     WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];


unsigned long ptime;
unsigned long start;
boolean druck=false;
boolean ldruck=true;
boolean M_minus=false;
boolean FM_minus=true;
boolean M_plus=false;
boolean FM_plus=true;
boolean M_sek=false;
boolean FM_sek=true;
//boolean tasterlesen=true;
boolean update,last=true;
boolean sec=false;
boolean lsec=false;
boolean save,one=false;
boolean Minus,Plus=false;
boolean once=false;
boolean done=false;
boolean M_timeout=false;
byte setmode=0;
byte timeout=0;
//byte lm=0;                                  // 0=Normal 1=Display Seconds 2=Set minutes 3=Set hours
//byte lCase=0;
byte ss,mm,lmm,hh,hhdisplay,mmset,lmmset,hhset,lhhset,mm5er,mm5erRest=0;                // Save Variables for time
byte R=0,G=0,B=0;                            // Farbe für den Start alles weis
byte Rpointer,Gpointer,Bpointer;
byte PWMArray[23]={
  2,7,10,15,20,25,30,35,40,50,60,70,80,90,100,120,140,160,180,200,220,240,255};


void setup() {
  wdt_enable(WDTO_2S);
  pinMode(RTCIN,INPUT);                          // SQW Output of RTC connected here
  pinMode(STELLEN,INPUT_PULLUP);                         // Taster Eingang
  pinMode(MINUS,INPUT_PULLUP);
  pinMode(PLUS,INPUT_PULLUP);
  pinMode(SEKUNDEN,INPUT_PULLUP);


  digitalWrite(RTCIN,HIGH);
  digitalWrite (STELLEN,HIGH);                    // internal Pullup
  FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
 // Serialbegin(115200);
  Wire.begin();                                  // Start I2C Kommunikation
  Wire.beginTransmission(RTC_ADDRESS);           // Beginn Kommunikation auf  Adresse 0x68 
  Wire.write(0x0E);                               // Pointer auf Control Register 0x07   
  Wire.write(0x00);                               // Controlbyte for RTC to set the sqw Output to 1Hz  
  Wire.endTransmission();                        // Beenden der I2C Kommunitkation
  update=true;
  Rpointer=EEPROM.read(0);
  Gpointer=EEPROM.read(1);
  Bpointer=EEPROM.read(2);
  if (Rpointer>=24||Gpointer>=24||Bpointer>=24){
	  EEPROM.write(0, 20);
      EEPROM.write(1, 20);
      EEPROM.write(2, 20);
  }
  TimeRead();
  RTC_Start();
}


// Start Main Loop
void loop() {
  wdt_reset();                      // Watchdog timer falls sich der Controller mal aufhängt
  /*=>Routine OneButton Control<=*/
  druck=digitalRead(STELLEN);
  M_minus=digitalRead(MINUS);
  M_plus=digitalRead(PLUS);
  M_sek=digitalRead(SEKUNDEN);
  R=PWMArray[Rpointer];
  G=PWMArray[Gpointer];
  B=PWMArray[Bpointer];
  /*One Button End*/

  if (druck==false&&ldruck==true){        // Longress >750ms change to setmode 3+4  to set Hours an Minutes
    if (setmode<=1){
      setmode=2;
    }
    else
      setmode++;  
    if (setmode==2){          // Setmode 2 Hour Setting
      hhset=hh;
    }
    if (setmode==3){          // Setmode 3 Minutes Setting
      mmset=mm;
    }
    if (setmode==4){         // Save the changes and go backt mode 0 (normal operation)
      if(save==true){
        hh=hhset;
        mm=mmset;
        ss=0;
        RTC_Set();
        save=false;
        update=true;
      }
    }
    if (setmode==7){          // Save Values
      EEPROM.write(0, Rpointer);
      EEPROM.write(1, Gpointer);
      EEPROM.write(2, Bpointer);
      setmode=0;  
    }
    ldruck=false;  
    one=false;
    FastLED.show();
  }
  if (druck==true&&ldruck==false){        // Zurücksetzten der Merker
    ldruck=true;  
  }
  // Minus
  if (M_minus==false&&FM_minus==true){
    Minus=true;
    FM_minus=false;
  }
  if (M_minus==true&&FM_minus==false){
    FM_minus=true;
  }
  // Plus
  if (M_plus==false&&FM_plus==true){
    Plus=true;
    FM_plus=false;
  }
  if (M_plus==true&&FM_plus==false){
    FM_plus=true;
  }

  if (M_sek==false&&FM_sek==true){
    setmode=1;
  }
  if (M_sek==true&&FM_sek==false){
    FM_sek=true;
  }




  sec=digitalRead(RTCIN);                          // Read the RTC SQWPulse 
  digitalWrite(13,sec);
  if (sec==true && lsec==false){
    ++ss;                                          // Sekunden Zähler aufadieren 
    if (ss==60){                                   // Bei 60 Sekunden eine Minute weiter
      ss=0;
      mm=mm+1;
    }
    if (setmode==1){                                // Im Setmode=1 werden hier die Sekunden angezeigt
      ++timeout;
      FastLED.clear();
      print_numbers(ss);                            // Sekunden Anezige Funktion mir übergabe der Sekunden
      FastLED.show();
      if (timeout>=15){
        setmode=0;
        timeout=0;
        update=true;  
      }  
    } 
    lsec=true;  
  }

  if (setmode==0){                                  // Im Modus 0 (normale Anzeige)
    if(mm!=lmm||update==true){                      // Wenn die Miunten nicht gleich der Minuten letzten durchlauf sind oder der update Merker gesetzt  
      FastLED.clear();
      TimeRead();                                   // RTC auslesen
      update=false;                                 // Hilfsmerker zurücksetzten
      mm5erRest=mm%5;                               // Mit Modulo die 5er "überhang" auswerten
      mm5er=mm-mm5erRest;                           // den 5er Teiler berechen 0,5,10,15,20....55 etc.
      if (hh>=13){                                   // Bei Stunden über 13 Uhr zurück auf 13=1 14=2 etc.
        hhdisplay=hh-12;            
      }
      if (mm5erRest==1) P_EINS();                   // Reste der Fünfer 1-4 die entsprechenden "Ecken" anmachen
      else if (mm5erRest==2) P_ZWEI();
      else if (mm5erRest==3) P_DREI();
      else if (mm5erRest==4) P_VIER();
      /*  Zeitanzeigeausgabe in Worten */
      W_ESIST();
      if (mm5er==5||mm5er==25||mm5er==35||mm5er==55){
        M_FUENF();
      }
      if (mm5er==10||mm5er==50){
        M_ZEHN();
      }
      if (mm5er==15||mm5er==45){
        M_VIERTEL();
      }
      if (mm5er==20||mm5er==40){
        M_ZWANZIG();
      }        
      if (mm5er==25||mm5er==30||mm5er==35){
        M_HALB();
      }
      if (mm5er==0){  
        W_UHR();
      }
      if (mm5er==5||mm5er==10||mm5er==15||mm5er==20||mm5er==35){
        W_NACH();
      }
      if (mm5er==25||mm5er==40||mm5er==45||mm5er==50||mm5er==55){
        W_VOR();
      }
      hhdisplay=hh;
      if (mm>=25){                                          // ab der 25 Minuten ist es immer "vor" der nächsetn Stunde 
        if (hh==0||hh==12){                                 // bei 12 Uhr vor "Ein" Uhr 
          hhdisplay=1;
        }
        else
          hhdisplay=hh+1;
      }
      if (hhdisplay==1&&mm5er==0) H_EIN();               // Bei Voller Stunde ohne Minute "Ein" Uhr
      else if (hhdisplay==1||hhdisplay==13) H_EINS();                   // Normale "Stunden" Auswahl
      else if (hhdisplay==2||hhdisplay==14) H_ZWEI();
      else if (hhdisplay==3||hhdisplay==15) H_DREI();
      else if (hhdisplay==4||hhdisplay==16) H_VIER(); 
      else if (hhdisplay==5||hhdisplay==17) H_FUENF();
      else if (hhdisplay==6||hhdisplay==18) H_SECHS(); 
      else if (hhdisplay==7||hhdisplay==19) H_SIEBEN(); 
      else if (hhdisplay==8||hhdisplay==20) H_ACHT();  
      else if (hhdisplay==9||hhdisplay==21) H_NEUN();
      else if (hhdisplay==10||hhdisplay==22) H_ZEHN();
      else if (hhdisplay==11||hhdisplay==23) H_ELF();
      else if (hhdisplay==12||hhdisplay==24||hhdisplay==0) H_ZWOELF();

    }
    lmm=mm;
    FastLED.show();
  }
  if (sec==false && lsec==true){                          // Flankenerkenung des Sekunden Impusles
    lsec=false;
  }

  if (setmode==2){                                          // Stunden stellen und anzeige des Zahlenwertes
    TimeRead();                                             // aktuelle zeit auslesen
    FastLED.clear();
    print_numbers(hhset);
    hhset=INCDEC(hhset);     
    // Serialprint("Std: ");
    // Serialprintln(hhset);
    leds[110].setRGB( R, G, B);  // OL
    leds[113].setRGB( R, G, B);  // OL
    lhhset=hhset;
    FastLED.show();
    one=true;
    save=true;  

  }
  if (setmode==3){                                          // Minuten stellen
    TimeRead();
    FastLED.clear();
    print_numbers(mmset); 
    mmset=INCDEC(mmset);
    // Serialprint("Min: ");
    // Serialprintln(mmset);
    leds[111].setRGB( R, G, B);  // OL
    leds[112].setRGB( R, G, B);  // OL
    lmmset=mmset;
    FastLED.show();
    one=true;
    save=true;  
  }
  if(setmode==4){                                            // Farbe Rot einstellen
    FastLED.clear();
    leds[113] = CRGB( 128,0,0);
    leds[112] = CRGB( 128,0,0);
    Rpointer=INCDEC(Rpointer);
    for (int x=0; x<Rpointer; x++){
      leds[x] = CRGB( 128,0,0);
    }
  }
  if (setmode==5){                                          // Farbe Grün einstellen
    FastLED.clear();
    leds[113] = CRGB( 0,128,0);
    leds[112] = CRGB( 0,128,0);
    Gpointer=INCDEC(Gpointer);
    for (int x=0; x<Gpointer; x++){
      leds[x] = CRGB( 0,128,0);
    }
  }

  if (setmode==6){                                          // Farbe Blau einstellen
    FastLED.clear();
    leds[113] = CRGB( 0,0,128);
    leds[112] = CRGB( 0,0,128);
    Bpointer=INCDEC(Bpointer);
    for (int x=0; x<Bpointer; x++){
      leds[x] = CRGB( 0,0,128);
    }
  }
  if (setmode==4||setmode==5||setmode==6){
    for (int x=88; x<NUM_LEDS-4; x++){
      leds[x] = CRGB( R,G,B);
    }
    FastLED.show();
  }


  if (sec==true&& once==false){
    // Serialprint("Setmode: ");
    // Serialprint(setmode);
    // Serialprint("P:");
    // Serialprint(Plus);
    // Serialprint("M:");
    // Serialprint(Minus);
    // Serialprint(" Zeit: ");
    // Serialprint(hh);
    // Serialprint(":");
    // Serialprint(mm);
    // Serialprint(":");
    // Serialprintln(ss);
    // Serialprintln(hhdisplay);
    once=true;
  }
  if (sec==false && once==true)
    once=false;
}
// End Main Loop


void print_numbers(byte num){   // Funktion zum Dartellen von Dezimalzahlen auf der Matrix
  byte num10;
  byte num1;
  num1=num%10;
  num10=(num-num1)/10;
  switch (num10){                                          // Zehner stelle ausgeben
  case 0:
    L_ZERO();
    break;
  case 1:
    L_ONE();
    break;
  case 2:
    L_TWO();
    break;
  case 3:
    L_THREE();
    break;
  case 4:
    L_FOUR();
    break;
  case 5:
    L_FIVE();
    break;
  }
  switch (num1){                                           // Einer Stelle ausgeben
  case 0:
    R_ZERO();
    break;
  case 1:
    R_ONE();
    break;
  case 2:
    R_TWO();
    break;
  case 3:
    R_THREE();
    break;
  case 4:
    R_FOUR();
    break;
  case 5:
    R_FIVE();
    break;
  case 6:
    R_SIX();
    break;
  case 7:
    R_SEVEN();
    break;
  case 8:
    R_EIGHT();
    break;
  case 9:
    R_NINE();
    break;
  }

}




byte INCDEC(byte Wert){
  if (Minus==true){
    if((setmode==4||setmode==5||setmode==6)&&Wert>=1){
      Wert--;
    }
    if(setmode==3){
      Wert--;
      if (Wert>60)
        Wert=59;
    }
    if(setmode==2){
      Wert--;
      if (Wert>24)
        Wert=23;
    }
    Minus=false;
  }
  if (Plus==true){
    if((setmode==4||setmode==5||setmode==6)&&(Wert<=21)){
      Wert++;
    }
    if(setmode==3){
      Wert++;
      if (Wert>59)
        Wert=0;
    }
    if(setmode==2){
      Wert++;
      if (Wert>23)
        Wert=0;
    }
    Plus=false;
  }
  return Wert;

}










































