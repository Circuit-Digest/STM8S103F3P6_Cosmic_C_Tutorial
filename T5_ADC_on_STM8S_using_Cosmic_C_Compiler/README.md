# [ADC on STM8S using Cosmic C Compiler – Reading Multiple ADC Values and Displaying on LCD](https://circuitdigest.com/microcontroller-projects/adc-on-stm8s-using-c-compiler-reading-multiple-adc-values-and-displaying-on-lcd)

<img src="https://github.com/Circuit-Digest/STM8S103F3P6_Cosmic_C_Tutorial/blob/master/IMAGES/T5_ADC_on_STM8S_using_Cosmic_C_Compiler.jpg" alt="image3" title="image3">

<br>
<a href="https://circuitdigest.com/microcontroller-projects/adc-on-stm8s-using-c-compiler-reading-multiple-adc-values-and-displaying-on-lcd"><img src="https://img.shields.io/static/v1?label=&labelColor=505050&message=ADC ON STM8S USING COSMIC C COMPILER CIRCUIT DIGEST&color=%230076D6&style=social&logo=google-chrome&logoColor=%230076D6" alt="circuitdigest"/></a>
<br>

[Click here](https://circuitdigest.com/microcontroller-projects/adc-on-stm8s-using-c-compiler-reading-multiple-adc-values-and-displaying-on-lcd) for the complete tutorial.

<br>
In this tutorial, we will learn how to use the ADC feature on our STM8S103F3P6 Microcontroller. As we know “We live in an analog world with digital devices”, meaning everything around us like wind speed, light intensity, temperature, and everything we deal with like speed, velocity, pressure, etc. are analog in nature. But our microcontrollers and microprocessors are digital devices and they will not be able to measure these parameters without an important peripheral called [Analog to Digital Converters (ADC)](https://circuitdigest.com/tags/adc). So in this article, let's learn how to use ADC on STM8S Microcontroller with COMIC C compiler.

If you are new to STM8, do check out the [Getting Started with STM8S using STVD and Cosmic C Compiler](https://circuitdigest.com/microcontroller-projects/getting-started-with-stm8s-using-stvd-and-cosmic-c-compiler) article to understand the basics of the controller board and programming environment. We will not be covering the basics in this tutorial.


<br>

**ADC pins on STM8S103F3P6 Microcontroller**


<img src="https://circuitdigest.com/sites/default/files/inlineimages/u3/ADC-on-STM8S103F3P6.png" alt="image3" title="image3">

<br>

**ADC characteristics for STM8S103P36**


<img src="https://circuitdigest.com/sites/default/files/inlineimages/u2/ADC-Characteristics.png" alt="image3" title="image3">


**Circuit Diagram to Perform ADC with STM8 Microcontroller**

The complete circuit diagram used in this project is given below, it is very similar to the STM8S LCD tutorial that we discussed previously.

<img src="https://circuitdigest.com/sites/default/files/circuitdiagram_mic/ADC-on-STM8S-Microcontroller-Circuit.png" alt="image3" title="image3">

