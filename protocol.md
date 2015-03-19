Protocol
--------

This is a description of the protocol in between the PC and the embedded device.

Commands
---------
  - All commands to the device will be pushed through a bi-directional text stream.
  - Each communication will be iniated by the PC
  - The first command to be sent is `version`
  
Command       | Description            |Usage | Example 
--------------|------------------------|------|--------
config        |                        |      |       
debug         |                        |      |       
load          |Loads G-Code into memory|      |       
manual        |                        |      |       
pause         |Pauses executing the current scan|      |       
resume        |Resumes paused scan     |      |       
start         |Begins the scan         |      |       
status        |                        |      |       
stop          |Perminently stops a scan|      |       
test          |                        |      |       
verison       |                        |      |       
  
