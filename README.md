# MVC-1
Model view controller with thread example

## About
This repository shows several ways to apply a design pattern to run different modules independent or not without it being necessary for anyone to know any other.

### Branches
There are different branches in this repo where this pattern is applied.
One is more C like, the second more Java like.

## How this works?
The main core of the program is the MainController, in both branches its a Singleton.
* In the main branch, each main is added to the MainController to be runned when the Controller runs all functions.

* On the other hand, in the Class-Like branch, we have a subscriber that needs to be inherited by the class to be runned.
Each class will auto-subscribe to MainController to be runned when necessary.


![alt text](https://github.com/Llanyro/MVC-1/blob/main/MVC.png?raw=true)