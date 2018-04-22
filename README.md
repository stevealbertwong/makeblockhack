# Makeblock Hack

# Table of Contents
&nbsp;[How we build it](https://github.com/stevealbertwong/makeblockhack/blob/master/README.md#How-we-build-it)  <br/> 
&nbsp;[PID control](https://github.com/stevealbertwong/makeblockhack/blob/master/README.md#PID-control-to-steer)  <br/> 
&nbsp;[Reference](https://github.com/stevealbertwong/makeblockhack/blob/master/README.md#Reference)  <br/> 

--- 

We created a line follow robot that uses PID controller feed back line detection error to correct steering angle in makeblock robot hackathon! It could also grap your water bottle and bring it to you and send email to you when it has finished its work!

![alt text](https://raw.githubusercontent.com/stevealbertwong/makeblockhack/master/pic/pic.jpg)


# How we build it
The physical building of the robot is very similar to the assembly instructions.pdf in the repo.

Check out our [demo here](https://youtu.be/C-BMuusDLDE). (https://youtu.be/C-BMuusDLDE)

![alt text](https://raw.githubusercontent.com/stevealbertwong/makeblockhack/master/pic/pic1.png)
![alt text](https://raw.githubusercontent.com/stevealbertwong/makeblockhack/master/pic/pic2.png)
![alt text](https://raw.githubusercontent.com/stevealbertwong/makeblockhack/master/pic/pic3.png)
![alt text](https://raw.githubusercontent.com/stevealbertwong/makeblockhack/master/pic/pic4.png)


We also used [IFTTT](https://ifttt.com/maker_webhooks) webhooks and wifi makeblock module to send email to our gmail account with logic in microcontroller. 

![alt text](https://raw.githubusercontent.com/stevealbertwong/makeblockhack/master/pic/makebot_api_IFTTT.png)

# PID control to steer

We use line tracking sensor to calculate the amount of error accumulated. When the car goes out of the black line, right/left wheel error starts to count, the longer the bigger the error. We use such error to create a close feedback loop on the amount of force apply to steering angle. Intuitively, the further the car drifted away from black line, the more steering angle is applied.

![alt text](https://raw.githubusercontent.com/stevealbertwong/makeblockhack/master/pic/pid1.png)
![alt text](https://raw.githubusercontent.com/stevealbertwong/makeblockhack/master/pic/pid2.png)

# Reference 

http://www.instructables.com/id/Learning-Experience-and-Review-the-Makeblock-3-in-/ here is more on using mblock (makeblock IDE). You could also using arduino IDE to compile with makeblock library. But it is much more convenient to use mblock to compile the code.

Here is a good introduction of using PID control in making your robot!
http://www.instructables.com/id/Line-Follower-Robot-PID-Control-Android-Setup/



