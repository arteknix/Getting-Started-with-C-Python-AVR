# Communication over Serial Port

>[!NOTE]
> Serial Communication 📞 is very usefull and generic.\
> it can transmit over several protocols and interfaces:\
> mainly:
>  
>  - usb
>  - rs232/485
>  - bluetooth
>  - wifi / ethernet
> 
> We'll use standard serial and serial over bluetooth (SPP) in this context.
>

## Serial Software

For proprietary OSes I do not use, **PuTTy** is a good candidate because it handels **Serial** and **ssh**.\
On Android I've tested **Serial/Bluetooth/Wifi Monitor**.\
There are many candidates for Linux and we'll be using **screen** and **picocom**.

>[!TIP]
> We will use ***python-serial*** a lot, because it will help us to treat data as well.
