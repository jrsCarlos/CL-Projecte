function f
  params
    _return_value boolean
    a integer
    b float
  endparams

  vars
    x integer
    y boolean
    z integer 10
  endvars

     %1 = 9
     %2 = 67
     %3 = a + %2
     z[%1] = %3
     %4 = 34
     x = %4
     %5 = 3
     %6 = 56
     %7 = 9
     %8 = z[%7]
     %9 = %6 + %8
     z[%5] = %9
     %10 = 3
     %11 = z[%10]
     %14 = float %11
     %13 = %14 <=. b
     %12 = not %13
     ifFalse %12 goto endif1
     %16 = 78
     x = %16
     writef b
     writes "\n"
     goto endelse1
  label endif1 :
     %17 = 99
     x = %17
  label endelse1 :
     %18 = 3
     %19 = z[%18]
     writei %19
     writes "\n"
     %20 = 1
     _return_value = %20
     return
     return
endfunction

function fz
  params
    r integer
  endparams

  label beginWhile1 :
     %1 = 0
     %3 = r <= %1
     %2 = not %3
     ifFalse %2 goto endWhile1
     %4 = 1
     %5 = r - %4
     r = %5
     goto beginWhile1
  label endWhile1 :
     return
endfunction

function main
  vars
    a integer
  endvars

     pushparam 
     %1 = 3
     pushparam %1
     %2 = 2
     %2 = float %2
     pushparam %2
     call f
     popparam 
     popparam 
     popparam %3
     ifFalse %3 goto endif1
     %4 = 3.7
     %6 = float a
     %5 = %6 +. %4
     %8 = 4
     %11 = float %8
     %9 = %5 +. %11
     writef %9
     writes "\n"
  label endif1 :
     return
endfunction


