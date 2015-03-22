Protocol
--------

This is a description of the protocol in between the PC and the embedded device.

Commands
---------
  - All commands to the device will be pushed through a bi-directional byte stream.
  - Commands are sent through `[length] [command] ([arg1] [arg2] ...)`
  
    Command   |            Description            |            Example              | Command Number 
--------------|-----------------------------------|---------------------------------|--------
G0            |Rapid Move (same as G1 in practice)| `G0 X1.3 Y4.5`                  | 1
G1            |Linear Move                        | `G1 X1.3 Y4.5`                  | 2      
G4            |Dwell                              | `G4 S1` or `G4 M1000`           | 3     
G20           |Set unit to inches                 | `G20`                           | N/A*
G21           |Set unit to millimeters            | `G21`                           | N/A*
G28           |Return to Home                     | `G28` or `G28 X` or `G28 Y`     | 4  
G90           |Set absolute positioning           | `G90`                           | N/A*
G91           |Set relative postioning            | `G91`                           | N/A*
M0            |Uncoditional Stop                  | `M0`                            | 5
M1            |Sleep                              | `M1`                            | 6
M3            |X-ray tube On                      | `M3 V50 A3`                     | 7
M5            |X-ray tube Off                     | `M5`                            | 8
M100          |Grab data from detector            | `M100`                          | 9
M102          |Version data                       | `M102`                          | 0

*Run on pc 

