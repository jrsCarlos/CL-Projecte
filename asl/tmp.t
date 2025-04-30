function fact
  params
    _return_value integer
    n integer
  endparams

  vars
    f integer
  endvars

     %1 = 1
     f = %1
  label beginWhile1 :
     %2 = 1
     %4 = n <= %2
     %3 = not %4
     ifFalse %3 goto endWhile1
     %5 = f * n
     f = %5
     %6 = 1
     %7 = n - %6
     n = %7
     goto beginWhile1
  label endWhile1 :
     _return_value = f
     return
     return
endfunction

function main
  vars
    max integer
    i integer
    f integer
    end boolean
  endvars

     %1 = 0
     i = %1
     %2 = 1
     end = %2
     readi max
     %3 = i <= max
     ifFalse %3 goto endif1
     %5 = 0
     end = %5
  label endif1 :
  label beginWhile1 :
     %6 = not end
     ifFalse %6 goto endWhile1
     writei i
     writes "!="
     pushparam 
     pushparam i
     call fact
     popparam 
     popparam %7
     writei %7
     writes "\n"
     %8 = i == max
     ifFalse %8 goto endif2
     %10 = 1
     end = %10
  label endif2 :
     goto beginWhile1
  label endWhile1 :
     return
endfunction


