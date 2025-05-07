function f
  params
    _return_value boolean
    a integer
    b float
  endparams

  vars
    x integer
    y boolean
    z array<10,integer> 10
  endvars

     %1 = 9
     %2 = 67
     %3 = a + %2
     z = %3
     %4 = 34
     x = %4
     %5 = 3
     %6 = 56
     %7 = 9
     %8 = %6 + z
     z = %8
     %9 = 3
     %12 = float z
     %11 = %12 <=. b
     %10 = not %11
     ifFalse %10 goto endif1
     %14 = 78
     x = %14
     writef b
     writes "\n"
     goto endelse1
  label endif1 :
     %15 = 99
     x = %15
  label endelse1 :
     %16 = 3
     writei z
     writes "\n"
     %17 = 1
     _return_value = %17
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


