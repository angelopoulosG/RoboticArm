#include <Servo.h>  //Xrhsh ths vivliothikis Servo.h 
Servo base;
Servo lower1;
Servo lower2;
Servo mid;
Servo upper;
Servo grip;
               
//Arxikopoihsh vashs tou vraxiona sto pin A0			   
const int pot = A0;        
// Arxikopoihsh twn buttons
const int button1 = 7;     
const int button2 = 6;
const int button3 = 5;
const int button4 = 4;
const int button5 = 3;
const int button6 = 2;
const int button7 = A3;
const int button8 = A4;

int potState;
int buttonState1;
int buttonState2;            
int buttonState3;
int buttonState4;
int buttonState5;
int buttonState6;
int buttonState7;
int buttonState8;

//Orismos twn thesewn twn arthrwsewn
int posB = 0;
int posL = 90;               
int posM = 90;
int posU = 90;
int posG = 120;

//Kathysterhsh gia tis kinhseis twn servo 
const int Delay = 10; 


void setup() {
 //Orismos twn pin twn koumpiwn etsi wste na symperiferontai ws eisodoi
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
  
  //Dhlwsh ths min kai max theshs twn arthrwsewn
  base.attach(8, 600, 2100);     
  lower1.attach(9, 600, 2100);
  lower2.attach(10, 600, 2100);
  mid.attach(11, 600, 2100);
  upper.attach(12, 600, 2100);
  grip.attach(13, 600, 2400);
  
  //Arxikopoihsh twn arthrwsewn se sygkekrimenes endiameses theseis 
  base.write(posB);         
  lower1.write(posL);
  lower2.write(180-posL);
  mid.write(posM);
  upper.write(posU);
  grip.write(posG);
  
  
  potState = analogRead(pot); //Diavazoume thn timh ths vashs

}


void loop(){
	//Diavazoume tis times apo ta pins
  potState = analogRead(pot); 
  int buttonState1 = digitalRead(button1);    
  int buttonState2 = digitalRead(button2);   
  int buttonState3 = digitalRead(button3);    
  int buttonState4 = digitalRead(button4);
  int buttonState5 = digitalRead(button5);    
  int buttonState6 = digitalRead(button6); 
  int buttonState7 = digitalRead(button7);
  int buttonState8 = digitalRead(button8);
 
    posB = map(potState, 0, 1023, 0, 179); 
    base.write(posB); 
    delay(Delay); 
 
  //Analoga me tis theseis twn koumpiwn allazei h thesh ths kathe arthrwshs 
  
//Bash
    if (buttonState1 == HIGH){
        posL += 1; // aukshsh ths theshs tou servo kata 1 
        if (posL > 175){ posL = 175;} // se periptwsh pou to servo kseperasei to orio ths timhs pou mporei na parei
        lower1.write(posL); // Vazoume to servo sth nea thesh
        lower2.write(180-posL);
        delay(Delay); //Kathysterhsh gia thn epomenh kinhsh tou servo    
    }
//Katw arthrwsh
  if (buttonState2 == HIGH){
        posL -= 1; // Meiwsh ths theshs tou servo kata 1
        if (posL < 4){ posL = 4;}
        lower1.write(posL); 
        lower2.write(180-posL);
        delay(Delay);      
    }
  
//Mesaia arthrwsh
      if (buttonState3 == HIGH){
        posM += 1; 
        if (posM > 180){ posM = 180;} 
        mid.write(posM);
        delay(Delay);    
    }
      if (buttonState4 == HIGH){
        posM -= 1; 
        if (posM < 0){ posM = 0;}
        mid.write(posM); 
        delay(Delay);     
    }

//Panw arthrwsh
        if (buttonState5 == HIGH){
        posU += 1; 
        if (posU > 180){ posU = 180;} 
        upper.write(posU); 
        delay(Delay);       
    }
      if (buttonState6 == HIGH){
        posU -= 1; 
        if (posU < 0){ posU = 0;}
        upper.write(posU); 
        delay(Delay);      
    }

//Dagkana
      if (buttonState7 == HIGH){
        posG += 1; 
        if (posG > 180){ posG = 180;} 
        grip.write(posG); 
        delay(Delay);       
    }
      if (buttonState8 == HIGH){
        posG -= 1; 
        if (posG < 60){ posG = 60;}
        grip.write(posG); 
        delay(Delay);     
    }
}
