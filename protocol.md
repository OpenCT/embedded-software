Protocol
--------

This is a description of the protocol in between the PC and the embedded device.

Commands
---------
  - All commands to the device will be pushed through a bi-directional text stream.
  - Each communication will be iniated by the PC
  - The first command to be sent is `version`
  
    Command   |            Description            |              Usage              | Example 
--------------|-----------------------------------|---------------------------------|--------
config        |Configure Permanent settings       |`config setting:value;next:value`| `config duty-cycle:0.75;max-length:5`
debug         |                                   |                                 |       
load          |Loads G-Code into memory           |`load line 1;line2`              | `load G28;M03;M05;M02`      
manual        |Manually activate hardware         |`manual command arguments`       | `manual x 5`   
pause         |Pauses executing the current scan  |`pause`                          | `pause`
resume        |Resumes paused scan                |`resume`                         | `resume`   
start         |Begins the scan                    |`start arguments`                | `start `    
status        |                                   |                                 |       
stop          |Perminently stops a scan           |`stop`                           | `stop`` 
test          |Run automated tests of the hardware|`test`                           | `test``
version       |Prints the current version         |`version`                        | `version`
  
