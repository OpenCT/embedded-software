byte in[1024];
byte inIndex,key;

void setup() {
  // initialize serial:
  Serial.begin(9600);

}
void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    
    inIndex = (inIndex+1)%1024;
    in[inIndex] = Serial.read();
    
    if(in[inIndex] != ' ')
    {
      byte command = str2command(key,inIndex);
      key = inIndex + 1;
      switch(command){
        case 0:
          config();
          break;
        case 1:
          debug();
          break;
        case 2:
          load();
          break;
        case 3:
          manual();
          break;
        case 4:
          pause();
          break;
        case 5:
          resume();
          break;
        case 6:
          start();
          break;
        case 7:
          status();
          break;
        case 8:
          stop();
          break;
        case 9:
          test();
          break;
        case 10:
          version();
          break;
      }
    }

 }
}


byte str2command(byte start, byte end){
  //config, debug, load	, manual, pause, resume, start, status, stop, test, version
  
  return 0; //should return index of the command or -1 for non-existant
}
void config(void){
  
}
void debug(void){
  
}
void load(void){
  
}
void manual(void){
  
}
void pause(void){
  
}
void resume(void){
  
}
void start(void){
  
}
void status(void){
  
}
void stop(void){
  
}
void test(void){
  //run test suite
}
void version(void){
  Serial.println("0.0.1");
}

