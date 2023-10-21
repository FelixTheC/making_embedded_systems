# Automatically greenhouse device

## Main loop

1. main device boot-up/start
2. set update timer
3. get some config via web-request??
   1. how often should the temp/soil/humidity get be checked
   2. what are the thresholds to open/close roof light and water pump
4. update timer (3 different or only one??)
5. send information to web server that changes where made
6. start timer
7. timeout occurred
   1. check if threshold was reached
   2. send open/close signal to roof light or water pump
8. send information to web server (what was checked, the value, and the possible action)

## Checking updates from web server

1. Start update timer (hard configured)
2. timeout occurred
   1. send current config to web server
   2. if changes are made download changes
      1. stop timer(s) 
      2. apply changes
      3. restart timer(s)