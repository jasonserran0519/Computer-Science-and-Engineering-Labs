# Name: <Jason Serrano>
# Date: <1/11/24> (Friday)
# Title: Lab1 – Unix/Linux Commands and Basic Shell Programming
# Description: This program computes the area of a triangle and area of a circle <you should
# 
# With this program. It first checks if the user running the program is me (Jserrano). If it is not me, the program will not run.
# After verifying, my program will ask for measurements of width and height of there rectangle. Given the measurements the program will compute the area.
# After this, the program will do the same for a circle, given its radius by the user. Once given, the program will return the area of the circle.




#Sample shell programs for Lab assignment
#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$


user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "jserrano" ] 
then
    echo "Now you can proceed!"
else
    echo "Check who logged in!"
exit 1
fi
response="Yes"
while [ $response != "No" ]
do
    echo "Enter height of rectangle: "
    read height
    echo "Enter width of rectangle: "
    read width
    area=`expr $height \* $width`
    echo "The area of the rectangle is $area"
    echo "Would you area of a circle [Yes/No]?"
    read response
    echo "Enter radius of Circle: "
    read radius
    pi=3.14
    Circle_Area=`echo "scale=2; $pi * $radius * $radius" | bc`
    echo "the area of the circle is $Circle_Area"
    done
done