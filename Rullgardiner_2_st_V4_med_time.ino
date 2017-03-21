int timeLimitUp1 = 22;   // Max antal sekunder som gardin 1 får åka uppåt
int timeLimitDown1 = 13; // Max antal sekunder som gardin 1 får åka nedåt
int timeLimitUp2 = 22;   // Max antal sekunder som gardin 2 får åka uppåt
int timeLimitDown2 = 13; // Max antal sekunder som gardin 1 får åka nedåt

int checkTimeLimitUp1;
int checkTimeLimitDown1;
int checkTimeLimitUp2;
int checkTimeLimitDown2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(0, OUTPUT); //Rullgardin 1 NER
  pinMode(1, OUTPUT); //Rullgardin 1 UPP
  pinMode(2, OUTPUT); //Rullgardin 2 NER
  pinMode(3, OUTPUT); //Rullgardin 2 UPP
  pinMode(4, INPUT);  //Rullgardin 1 NERE
  pinMode(5, INPUT);  //Rullgardin 1 UPPE
  pinMode(6, INPUT);  //Rullgardin 2 NERE
  pinMode(7, INPUT);  //Rullgardin 2 UPPE
  pinMode(12, INPUT); //Uppe eller nere HIGH UPPE / LOW NERE
  checkTimeLimitUp1 = 0;
  checkTimeLimitDown1 = 0;
  checkTimeLimitUp2 = 0;
  checkTimeLimitDown2 = 0;
  timeLimitUp1 = timeLimitUp1 * 100;  
  timeLimitDown1 = timeLimitDown1 * 100;
  timeLimitUp2 = timeLimitUp2 * 100;  
  timeLimitDown2 = timeLimitDown2 * 100; 

}

// the loop function runs over and over again forever
void loop() {


  
  while (digitalRead(12) == LOW ) //Rullgardinerna ska åka upp eller vara uppe
  {      
      checkTimeLimitDown1 = 0;
      checkTimeLimitDown2 = 0;
      
      digitalWrite(1, HIGH);
      digitalWrite(3, HIGH);
      
      if (digitalRead(4) == LOW && checkTimeLimitUp1 < timeLimitUp1) { digitalWrite(0, LOW); checkTimeLimitUp1++; } //Rullgardin 1 UPP
      else digitalWrite(0, HIGH);                                                                 //Rullgardin 1 UPPE
   
      if (digitalRead(6) == LOW && checkTimeLimitUp2 < timeLimitUp2) { digitalWrite(2, LOW); checkTimeLimitUp2++; } //Rullgardin 2 UPP
      else digitalWrite(2, HIGH);                                                                 //Rullgardin 2 UPPE
  
      delay(10);
   }  
  
  while (digitalRead(12) == HIGH) //Rullgardinerna ska åka ned eller vara nere
  {    
      checkTimeLimitUp1 = 0;
      checkTimeLimitUp2 = 0;
      
      digitalWrite(0, HIGH);
      digitalWrite(2, HIGH);
  
      if (digitalRead(5) == LOW && checkTimeLimitDown1 < timeLimitDown1) { digitalWrite(1, LOW); checkTimeLimitDown1++; } //Rullgardin 1 NED
      else digitalWrite(1, HIGH);                                                                     //Rullgardin 1 NERE
   
      if (digitalRead(7) == LOW && checkTimeLimitDown2 < timeLimitDown2) { digitalWrite(3, LOW); checkTimeLimitDown2++; } //Rullgardin 2 NED
      else digitalWrite(3, HIGH);                                                                     //Rullgardin 2 NERE
  
      delay(10);
  }
  
 
}
