# [ADC on STM8S using Cosmic C Compiler – Reading Multiple ADC Values and Displaying on LCD](https://circuitdigest.com/microcontroller-projects/adc-on-stm8s-using-c-compiler-reading-multiple-adc-values-and-displaying-on-lcd)

<img src="https://github.com/Circuit-Digest/STM8S103F3P6_Cosmic_C_Tutorial/blob/master/IMAGES/T5_ADC_on_STM8S_using_Cosmic_C_Compiler.jpg" alt="image3" title="image3">

<br>
<a href="https://circuitdigest.com/microcontroller-projects/adc-on-stm8s-using-c-compiler-reading-multiple-adc-values-and-displaying-on-lcd"><img src="https://img.shields.io/static/v1?label=&labelColor=505050&message=ADC ON STM8S USING COSMIC C COMPILER CIRCUIT DIGEST&color=%230076D6&style=social&logo=google-chrome&logoColor=%230076D6" alt="circuitdigest"/></a>
<br>
<br>

The [16x2 Alphanumeric LCD display](https://circuitdigest.com/tags/16x2-lcd) is the most commonly used display among hobbyists and enthusiasts. The display is very useful when you want to display basic information to the user and can also help in testing or debugging our code. This particular 16x2 LCD module is easily available and has been popular for a long time. You can learn more about the basics of the 16x2 LCD module in the linked article.

To continue with our seri es of STM8 Microcontroller tutorials, in this tutorial, we will learn how to use the ADC feature on our STM8S103F3P6 Microcontroller. An ADC is a very useful peripheral on a microcontroller that is often used by embedded programmers to measure units that are in constant change like the varying voltage, current, temperature, humidity, etc.

If you are new to STM8, do check out the [Getting Started with STM8S using STVD and Cosmic C Compiler](https://circuitdigest.com/microcontroller-projects/getting-started-with-stm8s-using-stvd-and-cosmic-c-compiler) article to understand the basics of the controller board and programming environment. We will not be covering the basics in this tutorial.


<br>

**ADC pins on STM8S103F3P6 Microcontroller**


<img src="https://circuitdigest.com/sites/default/files/inlineimages/u3/ADC-on-STM8S103F3P6.png" alt="image3" title="image3">

<br>

**ADC characteristics for STM8S103P36**


<img src="https://circuitdigest.com/sites/default/files/inlineimages/u2/ADC-Characteristics.png" alt="image3" title="image3">


# Circuit Diagram to Interface LCD with STM8 Microcontroller

The complete STM8 LCD Circuit can be found in the below image. As you can see the connection for STM8S103F3P6 Controller with LCD is very simple, we have the LCD display directly connected to our board and the ST-link is also connected to program the board.

<img src="https://circuitdigest.com/sites/default/files/circuitdiagram_mic/ADC-on-STM8S-Microcontroller-Circuit.png" alt="image3" title="image3">



For more details you can visit our tutorial on [Interfacing 16x2 Alphanumeric LCD display with STM8 Microcontroller](https://circuitdigest.com/microcontroller-projects/interfacing-16x2-lcd-display-with-stm8-microcontroller)
