[top]
components : balancver@Balanceverifier 
out : amnt_out
out : get_amnt_out
in : in 
Link : in amnt_in@balancver
Link : amnt_out@balancver amnt_out
Link : get_amnt_out@balancver get_amnt_out


[balancver]
distribution : normal
mean : 4
deviation : 2 
