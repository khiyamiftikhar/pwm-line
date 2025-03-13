This project is a definitiona and implementation of pwm-line interface. It can be used to create multiple
pwm-line objects, that can be set to run at different phases, but same duty cycle and period.
It is intended for the keypad prober class that will output pwms on each ouput line, with different
phases. Also there will be a gap between each phase so that distinct pulse is read on the input pin of
the kepad. This way the output  pin will be easily identified on a press.