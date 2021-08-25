# SPI on STM8S Using Cosmic C Compiler – Interface the MAX7219 module with STM8S

<img src="https://github.com/Circuit-Digest/STM8S103F3P6_Cosmic_C_Tutorial/blob/master/IMAGES/T7_I2C_Communication_on_STM8S_using_Cosmic_C_Compiler.jpg" alt="image3" title="image3">

<br>
<a href="https://circuitdigest.com/microcontroller-projects/i2c-communication-on-stm8s-using-cosmic-c-compiler-reading-mlx90614-sensor-values"><img src="https://img.shields.io/static/v1?label=&labelColor=505050&message=I2C COMMUNICATION ON STM8S USING COSMIC C COMPILER CIRCUIT DIGEST&color=%230076D6&style=social&logo=google-chrome&logoColor=%230076D6" alt="circuitdigest"/></a>
<br>

[Click here](https://circuitdigest.com/microcontroller-projects/i2c-communication-on-stm8s-using-cosmic-c-compiler-reading-mlx90614-sensor-values) for the complete tutorial.

<br>
In this article, we are going to perform the I2C Communication on STM8S microcontroller by using the MLX90614 I2C sensor. We will measure the Ambient Temperature and the Object’s Temperature and then we will display the measured temperature on the LCD. If you are following the STM8S Microcontroller Tutorials, you would know that we have already covered the basics of the STM8s using the Cosmic C Compiler.

If you are new to STM8, do check out the [Getting Started with STM8S using STVD and Cosmic C Compiler](https://circuitdigest.com/microcontroller-projects/getting-started-with-stm8s-using-stvd-and-cosmic-c-compiler) article to understand the basics of the controller board and programming environment. We will not be covering the basics in this tutorial.

<br>

**Hardware Setup to Interface MLX90614 and LCD with STM8S for I2C**
<br>
<br>
<img src="https://circuitdigest.com/sites/default/files/inlineimages/u3/I2C-on-STM8S-Board.jpg" alt="image3" title="image3">

<br>

**Circuit Diagram to Interface MLX90614 and LCD with STM8S**
<br>
<br>
The following schematic illustrates the connections diagram of the MLX90614 sensor and the LCD with the STM8S. This schematic is very similar to the STM8S LCD tutorial that we have discussed previously. I have just wired the SDA and SCL pins of the sensor with the SDA (PB5) and SCL(PB4) pin of the STM8S103F3P6 board and I have provided a 5V power supply to both the sensor and the LCD. Please note carefully that we need to power the STM8S103F3P6 board with a USB connector so that the board gives a proper 5V power supply to both the sensor and the LCD.
<br>
<img src="https://circuitdigest.com/sites/default/files/circuitdiagram_mic/Interface-MLX90614-and-LCD-with-STM8S.jpg" alt="image3" title="image3">

<br>

**Connecting Logic Analyzer with STM8S to Monitor I2C Communication**
<br>
<br>
A logic analyzer is an electronic instrument that captures and displays multiple signals from a digital system or digital circuit. We are going to use the USB logic analyzer to analyze the I2C data. The connection of an USB logic analyzer is very simple. You can refer the following block diagram to connect an USB logic analyzer with any I2C devices to see the I2C data of that device.
<br>
<img src="https://circuitdigest.com/sites/default/files/inlineimages/u3/Connecting-Logic-Analyzer-with-STM8S.png" alt="image3" title="image3">

<br>

**Monitoring the I2C Communication On the Logic Analyzer**
<br> 
<br>
<img src="https://circuitdigest.com/sites/default/files/inlineimages/u3/I2C-on-STM8S.png" alt="image3" title="image3">

<br>


