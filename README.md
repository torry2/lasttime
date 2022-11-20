# LastTime
#### :See the last time you used that command!
  
LastTime is a command line tool that searches your shells history file and outputs the last time(s) you used a specified command.  
A quick and simple alternative to the clunky shell command `cat ~/.historyfile | grep "lasttime" (| head -n x)`  
  
NOTE:  
LastTime currently only supports `BASH` and `ZSH` via `.bash_history` and `.zsh_history` dotfiles!  
  
#### Installation:
via Script:  
```
sudo curl "https://raw.githubusercontent.com/torry2/lasttime/main/install.sh" | bash
```
  
Manually:  
```
$ git clone https://github.com/torry2/lasttime.git #OR git@github.com:torry2/lasttime
$ cd lasttime
$ g++ lasttime.cpp -o lt
$ sudo cp lt /usr/local/bin
$ cd .. && rm -r lt # optional cleanup
```

#### Usage:

Help Output:  
```
INFO: lt <command> (<index>)
```
Call `lasttime` with `lt`, specifying a command will output the last time you used that command, if you wish to see the last `n` times you used it, simply specify the `n` times after the command, to see all instances in your history file, you can specify the integer 0.
   
Example Command: (ping)  
```
$ lt ping
ping torrytw.ooo
```
  
 Example Command: (with indexing)
 ```
 $ lt ping 5
 ping torrytw.ooo
 ping archlinux.org
 ping github.com
 ping 8.8.8.8
 ping minecraft.net
 ```
 
##### Features Coming Soon:  
- `Use` Function to automatically paste a history command into your TTY  
~~- Improved help message~~  
~~- Index command history (e.g show the last `n` times you used that command)~~  
- Improved installation method
  
###### Bug & Error Reporting:  
Open an issue or pull request!  

