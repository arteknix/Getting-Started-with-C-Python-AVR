# How to use Arduino.mk

Install the package for your distro, in _debian_ it's called **arduino-mk**

You'll find info in the [UsingArduino/README.md](UsingArduino/README.md#arduino-mk)

Create a folder conataining **one** Arduino-sketck (.ino or .pde)

You can take the files in Example00.
 
Type ```make``` , that's it 😃 

For uploading you need **Avrdude**. which is such a cool tool. The documentation is amazing too. 

So just type ```make upload``` , when using usb on the UNO for example. 

>[!TIP]
> As you are using Arduino, avrdude is installed in the arduino folder along it's configuration file.
>
> When we use AVR without Arduino, we will need to check if it is installed
>
> ```which avrdude``` 
