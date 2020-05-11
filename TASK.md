
I this Lab work you should implement an **C**ommand **L**ine **I**nterface.

### Commands must be recognized

Command                 | Arguments  | Description
----------------------- | ---------- | -----------
```help```              |     no     | Print the help string with all **commands** descriptions.
```exit```              |     no     | Finish the program. Exit from CLI.
```save```              |     no     | Save current **history** to **logfile**.
```quit```              |     no     | ```save``` \+ ```exit```.
```load```              |     no     | Print **logfile**.
```logfile```           |     no     | Print **logfile** path.
```logfile```           |    path    | Set path as **logfile** path, print whether exists this file or not.
```list```              |     no     | Print current **history**.
```log on```            |     no     | Switch _on_ saving actions to **history**.
```log off```           |     no     | Switch _off_ saving actions to **history**.
```log append```        |     no     | When we ```save```, it should write current **history** to **logfile** appending.
```log new```           |     no     | When we ```save```, it should write current **history** to **logfile** deleting all content in this file.
```log clear history``` |     no     | Clear current **history**.



#### Record format in **logfile**

```date``` - ```command```

Example:

> ```2020.03.04 10:45:23``` - ```exit```

#### Starting

Your program should have some ```greeting```.

Start program:
* ```greeting```
* Logfile is %%**logfile** path%% 
* ```help``` string

Example:
> Hello user! (greeting)

> logfile is ```D:/log.txt```

> This program can ... . Available commands:
> * ```command1``` - ```description1```
> * ```command2``` - ```description2```

> ...

When CLI is ready to take a command, it should print ```prompt```.

```prompt``` examples:

> * ```>```
> * ```$```    (```git bash``` use this ```prompt```)
> * ```->```
> * ```>>>```  (```python IDLE``` use this ```prompt```)
> * ```:```
> * ```#```

##### Work example
```
Hello user!
logfile is D:/lab/log.txt
Available commands:


help              - *some description*
quit              - *some description*
exit              - *some description*
save              - *some description*
load              - *some description*
logfile           - *some description*
list              - *some description*
log on            - *some description*
log off           - *some description*
log append        - *some description*
log new           - *some description*
log clear history - *some description*

$load

logfile is empty.

$list

History:
2020.03.04 10:45:23 - load

$
$save

History saved to logfile.

$load
logfile:
2020.03.04 10:45:23 - load
2020.03.04 10:45:50 - list
2020.03.04 10:46:03 - save

$exit
```

