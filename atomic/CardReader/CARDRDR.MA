[top]
components : cardreader@CardReader
out : card_out
out : cardno_out
in : card_in eject
Link : card_in card_in@cardreader
Link : eject eject@cardreader
Link : cardno_out@cardreader cardno_out
Link : card_out@cardreader card_out


[cardreader]
distribution : normal
mean : 2
deviation : 1 
