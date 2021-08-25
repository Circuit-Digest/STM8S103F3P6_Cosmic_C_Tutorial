# [Pulse width Modulation (PWM) with STM8 using Cosmic C and STVD: Controlling Brightness of LED](https://circuitdigest.com/microcontroller-projects/pulse-width-modulation-pwm-with-stm8-using-cosmic-c-and-stvd)

<img src="https://github.com/Circuit-Digest/STM8S103F3P6_Cosmic_C_Tutorial/blob/master/IMAGES/T6_Pulse_width_Modulation_with_STM8_using_Cosmic_C_and_STVD.jpg" alt="image3" title="image3">

<br>
<a href="https://circuitdigest.com/microcontroller-projects/pulse-width-modulation-pwm-with-stm8-using-cosmic-c-and-stvd"><img src="https://img.shields.io/static/v1?label=&labelColor=505050&message=PWM WITH STM8S USING COSMIC C COMPILER CIRCUIT DIGEST&color=%230076D6&style=social&logo=google-chrome&logoColor=%230076D6" alt="circuitdigest"/></a>
<br>

[Click here](https://circuitdigest.com/microcontroller-projects/pulse-width-modulation-pwm-with-stm8-using-cosmic-c-and-stvd) for the complete tutorial.

<br>
Pulse Width Modulation (PWM) is a type of analog modulating technique in which the duration or width of the pulse changes in accordance with the time. It is a commonly used technique to produce a continuous pulse signal with a defined frequency and duty cycle. In short, PWM is about changing the width of a pulse while the frequency remains constant.

With a PWM signal, you can easily control the speed of the servo motor or the brightness of an LED. Since generic microcontrollers can only provide Logic 1 (High) or Logic 0 (Low) on their output pins, they cannot provide a varying analog voltage unless it has a [Digital to Analog converter (DAC)](https://circuitdigest.com/tags/dac) built-in or its connected externally. In such a case, the microcontroller can be programmed to output a [Pulse Width Modulation (PWM)](https://circuitdigest.com/tags/pwm) with a varied duty cycle which can then be converted to the varying analog voltage.

If you are new to STM8, do check out the [Getting Started with STM8S using STVD and Cosmic C Compiler](https://circuitdigest.com/microcontroller-projects/getting-started-with-stm8s-using-stvd-and-cosmic-c-compiler) article to understand the basics of the controller board and programming environment. We will not be covering the basics in this tutorial.


