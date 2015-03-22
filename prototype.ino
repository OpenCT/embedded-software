byte buffer[16];
byte bufI,length;
boolean bufferFull, running, cancel;
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
void setCommand(){
  //set flags and shit
}

//called repeatedly
void runCommands(){

}
