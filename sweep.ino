

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

int distance = 2300;

void setup() 
{                
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);       
}


void loop() 
{
  if (a < distance)  //sweep 200 step in dir 1
   {
    a++;
    digitalWrite(stp, HIGH);   
    delay(1);               
    digitalWrite(stp, LOW);  
    delay(1);              
   }
  else 
   {
    digitalWrite(dir, HIGH);
    a++;
    digitalWrite(stp, HIGH);  
    delay(1);               
    digitalWrite(stp, LOW);  
    delay(1);
    
    if (a>distance*2)    //sweep 200 in dir 2
     {
      a = 0;
      digitalWrite(dir, LOW);
     }
    }
}
