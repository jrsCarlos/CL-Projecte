function f1
  params
    a integer
    b integer
  endparams

  vars
    c float
    d integer
    found boolean
  endvars

     %1 = 0
     found = %1
     %2 = 0.7
     %4 = float a
     %3 = %4 +. %2
     c = %3
     %6 = 0
     d = %6
     %7 = a + d
     %10 = float %7
     %9 = %10 <=. c
     %8 = not %9
     %12 = not found
     %13 = %8 or %12
     ifFalse %13 goto endif1
     writes "\n"
     goto endelse1
  label endif1 :
     writes "\n"
  label endelse1 :
     %14 = 11
     %15 = b <= %14
     ifFalse %15 goto endif2
     %17 = 2
     %19 = float %17
     %18 = %19 *. c
     %21 = 1
     %24 = float %21
     %22 = %18 +. %24
     c = %22
  label endif2 :
     writef c
     writes "\n"
     return
endfunction

function main
  vars
    a integer
    b integer
  endvars

   %1 = 4
   a = %1
   %2 = 2
   %3 = %2 * a
   %4 = 1
   %5 = %3 + %4
   b = %5
   pushparam 
   pushparam b
   %6 = 3
   %7 = %6 + b
   pushparam %7
   call f1
   popparam 
   popparam 
   popparam %8
   return
endfunction


