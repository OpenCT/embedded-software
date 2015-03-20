setup(){
  //prepare control stream
  //prepare data stream
}

loop(){
  // if availible pull data from control stream
    //interpretCommand(data)
  
}

pullData(){
  //generate clock if not already done
  //pull down reset
  //on Trigger rise
    //grab video as analog
    //push data into data stream
  //until EOS rise
  //push end of line to data stream
  //return
}
interpretCommand(){
  //pull off ^.*\  and run that function with the rest of the string
}
version(){
  //push version number to control
}
load(){
  //compile GCode into numbers (for better effeciency) 2 numbers [instruction] [arguments]
  //note argument pointers
  //load into array
}
start(){
  //replace argument pointers
  //start runGCode
}
stop(){
  //halt runGCode when it reaches a stopping point
}
pause(){
  //halt runGCode when it reaches a stopping point
  //set flag for resume
  //safely shut down
}
resume(){
  //unset flag for resume
  //safely start up
  //begin runGCode
}
test(){
  //run test suite
}
runGCode(){
  //getInstruction
  //runInstruction 
  //checkPause / Cancel
  //repeat

}
