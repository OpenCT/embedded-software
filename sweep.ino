

//simple A4988 connection
//jumper reset and sleep together
//connect  VDD to Arduino 3.3v or 5v
//connect  GND to Arduino GND (GND near VDD)
//connect  1A and 1B to stepper coil 1
//connect 2A and 2B to stepper coil 2
//connect VMOT to power source (9v battery + term)
//connect GRD to power source (9v battery - term)


int stp = 13;  //connect pin 13 to step
int dir = 12;  // connect pin 12 to dir
int a = 0;     //  gen counter
int goal = 0;
int distance = 2300;
String inString = "";

void setup() 
{                
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  Serial.begin(9600);  
}


void loop() 
{
   getGoal();
   while (a != goal){
     if(a < goal){
       digitalWrite(dir, LOW);
       a++;
     }else{
       digitalWrite(dir, HIGH);
       a--;.
       
     }
     step();
   }
}
void getGoal(){
  while (Serial.available() > 0) {
      int inChar = Serial.read();
      if (isDigit(inChar)) {
        // convert the incoming byte to a char
        // and add it to the string:
        inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      
      int tmp = inString.toInt();
      if(tmp >= 0 && tmp < distance){
        Serial.print("Going to ");
        goal = tmp;
        Serial.println(tmp);
      }else{
        Serial.println("No, I'm not going there");
      }
      // clear the string for new input:
      inString = "";
    }
  }
}
void step(){
    digitalWrite(stp, HIGH);  
    delay(1);      
    digitalWrite(stp, LOW);  
    delay(1);
}
