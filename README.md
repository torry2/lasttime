# LastTime
#### :See the last time you used that command!
  
LastTime is a command line tool that searches your shells history file and outputs the last time you used a specified command.  
A quick and simple alternative to the clunky shell command `cat ~/.historyfile | grep "lasttime"`
  
NOTE:  
LastTime currently only supports `BASH` and `ZSH` via `.bash_history` and `.zsh_history` dotfiles!  
  
#### Installation:
via Script:  
```
NULL
```
  
Manually:  
```
$ git clone https://github.com/torry2/lasttime.git #OR git@github.com:torry2/lasttime
$ cd lasttime
$ g++ lasttime.cpp -o lasttime
$ sudo cp lasttime /usr/local/bin
$ cd .. && rm -r lasttime # optional cleanup
#### Usage:
  
Display Help Message:  
```
$ lasttime
helpoutput
```
Example Command: (ping)  
```
$ lasttime ping
ping github.com
ping archlinux.org
```
  
##### Features Coming Soon:  
- Index command history (e.g show the last `n` times you used that command)  
- `Use` Function to automatically paste a history command into your TTY  
  
###### Bug & Error Reporting:  
Open an issue or pull request!  

