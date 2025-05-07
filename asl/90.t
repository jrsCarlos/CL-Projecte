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
     readi %2
     z[%1] = %2
     %3 = 5
     %4 = z[%3]
     %5 = 88
     %7 = float %5
     %6 = %7 *. f
     %10 = float %4
     %9 = %10 -. %6
     writef %9
     readi b
     readf f
     ifFalse b goto endif1
     writes "h\n\tl\\a"
     %12 = -. f
     %13 = -. %12
     %14 = -. %13
     writef %14
     writes "\n"
  label endif1 :
     %15 = 1
     _return_value = %15
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
     %9 = 0
     %10 = r == %9
     ifFalse %10 goto endif1
     pushparam 
     %12 = 55555
     pushparam %12
     %13 = 5
     %14 = - %13
     %15 = 4
     %16 = %14 / %15
     %16 = float %16
     pushparam %16
     call f
     popparam 
     popparam 
     popparam %17
  label endif1 :
     %18 = 3
     %19 = r + %18
     %21 = float %19
     %20 = %21 *. u
     _return_value = %20
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
   %3 = float %2
   q = %3
   pushparam 
   %4 = 3
   %5 = 4
   %6 = %4 + %5
   pushparam %6
   pushparam 
   %7 = 4444
   pushparam %7
   %8 = 3
   %11 = float %8
   %9 = q +. %11
   pushparam %9
   call fz
   popparam 
   popparam 
   popparam %12
   pushparam %12
   call fz
   popparam 
   popparam 
   popparam %13
   q = %13
   %15 = 3.7
   %16 = q +. %15
   %19 = 4
   %22 = float %19
   %20 = %16 +. %22
   writef %20
   writes "\n"
   return
endfunction


