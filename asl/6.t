function f
  params
    _return_value boolean
    a integer
    f float
  endparams

  vars
    x integer
    b boolean
    z integer 10
  endvars

     %1 = 5
     readi z
     %2 = 5
     %3 = 88
     %5 = float %3
     %4 = %5 *. f
     %8 = float z
     %7 = %8 -. %4
     writef %7
     readc b
     readf f
     ifFalse b goto endif1
     writes "h\n\tl\\a"
     %10 = -. f
     %11 = -. %10
     %12 = -. %11
     writef %12
     writes "\n"
  label endif1 :
     %13 = 1
     _return_value = %13
     return
     return
endfunction

function fz
  params
    _return_value float
    r integer
    u float
  endparams

  label beginWhile1 :
     %1 = 0.01
     %4 = float r
     %3 = %4 <=. %1
     %2 = not %3
     ifFalse %2 goto endWhile1
     %6 = 1
     %7 = r - %6
     r = %7
     goto beginWhile1
  label endWhile1 :
     %8 = 0
     %9 = r == %8
     ifFalse %9 goto endif1
     pushparam 
     %11 = 55555
     pushparam %11
     %12 = 5
     %13 = - %12
     %14 = 4
     %15 = %13 / %14
     %15 = float %15
     pushparam %15
     call f
     popparam 
     popparam 
     popparam %16
  label endif1 :
     %17 = 3
     %18 = r + %17
     %20 = float %18
     %19 = %20 *. u
     _return_value = %19
     return
     return
endfunction

function main
  vars
    a integer
    q float
  endvars

   %1 = 1
   %2 = - %1
   %2 = float %2
   q = %2
   pushparam 
   %3 = 3
   %4 = 4
   %5 = %3 + %4
   pushparam %5
   pushparam 
   %6 = 4444
   pushparam %6
   %7 = 3
   %10 = float %7
   %8 = q +. %10
   pushparam %8
   call fz
   popparam 
   popparam 
   popparam %11
   pushparam %11
   call fz
   popparam 
   popparam 
   popparam %12
   q = %12
   %13 = 3.7
   %14 = q +. %13
   %17 = 4
   %20 = float %17
   %18 = %14 +. %20
   writef %18
   writes "\n"
   return
endfunction


