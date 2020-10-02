[top]
components : pinver@PINverifier 
out : get_pin
out : get_amnt
out : eject
in : in 
Link : in pin_in@pinver
Link : get_pin@pinver get_pin
Link : get_amnt@pinver get_amnt
Link : eject@pinver eject


[pinver]
distribution : normal
mean : 4
deviation : 2 
