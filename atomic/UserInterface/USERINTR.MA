[top]
components : userface@UserInterface 
out : amnt_out
out : pin_out
in : get_pin get_amnt cardno
Link : get_amnt get_amnt@userface
Link : get_pin get_pin@userface
Link : cardno cardno@userface
Link : amnt_out@userface amnt_out
Link : pin_out@userface pin_out


[userface]
distribution : normal
mean : 4
deviation : 2 
