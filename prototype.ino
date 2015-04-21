#define G0   1
#define G1   2
#define G4   3
#define G28  4
#define M0   5
#define M1   6
#define M3   7
#define M5   8
#define M100 9
#define M102 0

#define MAX_X_SPEED 10
#define MAX_Y_SPEED 10

#define X_AXIS 0
#define Y_AXIS 1

byte buffer[16];
byte bufI,length;
boolean bufferFull, running, cancel;

unsigned int x,y,goalX,goalY;
unsigned long wait;
boolean moving,waiting;

void setup() {
  Serial.begin(9600);
}

void loop() {
  recieve();
  runCommands();
}
//Commands and fills a one command buffer
void recieve(){
  while(Serial.available()&&!bufferFull){
    if(bufI = 1){
      length = buffer[bufI]&15; //4 bits on right
      //4 left bits will be extra if we need them
      if(buffer[bufI]>>15){
        cancel = true;
      }
    }else{
      buffer[bufI++] = Serial.read();
    }
    if(length==0){
      if(running){
        bufferFull = true;
      }else{
        setCommand();
        bufI = 0;
      }
    }else{
      length--;
    }
  }
}
//called once per command sent
//sets flags and variables based on commands
void setCommand(){
  byte tmp;
  switch(buffer[0] & 31){
    case G0:
    case G1:
      moving = true;
      tmp = buffer[0]>>5; //get rid of command data
      if(tmp&1){ //get x value
        goalX = buffer[1]<<8+buffer[2];
        bufI=2;
      }else{
        bufI=1;
      }
      if(tmp&2){ //get y value
        goalY = buffer[bufI]<<8+buffer[bufI+1];
      }
      running = true;
      break;
    case G4:
      wait = millis()+buffer[1]<<8+buffer[2];
      waiting = true;
      running = true;
      break;
    case G28:
      moving = true;
      tmp = buffer[0]>>5; //get rid of command data
      if(tmp&1){ //get x value
        goalX = -1;
      }
      if(tmp&2){ //get y value
        goalY = -1;
      }
      running = true;
      break;
    case M0:
      break;
    case M1:
      break;
    case M3:
      break;
    case M5:
      break;
    case M100:
      break;
    case M102:
      version();
      break;
    default:
      break;
  }
  if(!running){
    done();
  }
}

void done(){
  Serial.println("Done");
  running = false;
}

//called repeatedly
void runCommands(){
  int tmp;
  if(moving){
    if(goalX == -1){
      moveStepper(-MAX_X_SPEED,X_AXIS);
      x -= MAX_X_SPEED;
      if(lowerX()){
        x = 0;
        goalX = 0;
        if(goalY != -1){
          done();
        }
      }
    }else if(goalX != x){
      tmp = goalX - x;
      tmp = (tmp > MAX_X_SPEED)?MAX_X_SPEED:(tmp > -MAX_X_SPEED)?tmp:-MAX_X_SPEED; //clamp tmp to +MAX_X_SPEED and -MAX_X_SPEED
      moveStepper(tmp,X_AXIS);
    }
    if(goalY == -1){
      moveStepper(-MAX_Y_SPEED,Y_AXIS);
      y -= MAX_Y_SPEED;
      if(lowerY()){
        y = 0;
        goalY = 0;
        if(goalX != -1){
          done();
        }
      }
    }else if(goalY != y){
      tmp = goalY - y;
      tmp = (tmp > MAX_Y_SPEED)?MAX_Y_SPEED:(tmp > -MAX_Y_SPEED)?tmp:-MAX_Y_SPEED; //clamp tmp to +MAX_Y_SPEED and -MAX_Y_SPEED
      moveStepper(tmp,Y_AXIS);
    }
  }
  if(waiting && wait < millis()){
    done();
  }
}
