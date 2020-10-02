[top]
components : balancver@Balanceverifier pinver@PINverifier userface@UserInterface
out : amnt_out
out : eject
in : in
Link : in cardno@userface
Link : get_pin@pinver    get_pin@userface
Link : pin_out@userface  pin_in@pinver
Link : get_amnt@pinver   get_amnt@userface
Link : amnt_out@userface amnt_in@balancver
Link : get_amnt_out@balancver get_amnt@userface
Link : amnt_out@balancver amnt_out


[balancver]
distribution : normal
mean : 4
deviation : 2 

[pinver]
distribution : normal
mean : 4
deviation : 2 

[userface]
distribution : normal
mean : 4
deviation : 2 