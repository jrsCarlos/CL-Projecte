function one
  params
    _return_value float
  endparams

   %1 = 1
   _return_value = %1
   return
   return
endfunction

function sort
  params
    v float array
  endparams

  vars
    i integer
    j integer
    jmin integer
    aux float
  endvars

     %1 = 0
     i = %1
  label beginWhile2 :
     %3 = 20
     %4 = 1
     %5 = %3 - %4
     %6 = i < %5
     ifFalse %6 goto endWhile2
     jmin = i
     %9 = 1
     %10 = i + %9
     j = %10
  label beginWhile1 :
     %12 = 20
     %13 = j < %12
     ifFalse %13 goto endWhile1
     %15 = v
     %16 = %15[j]
     %17 = v
     %18 = %17[jmin]
     %19 = %16 <. %18
     ifFalse %19 goto endif1
     jmin = j
  label endif1 :
     %24 = 1
     %25 = j + %24
     j = %25
     goto beginWhile1
  label endWhile1 :
     %28 = jmin == i
     %27 = not %28
     ifFalse %27 goto endif2
     %29 = v
     %30 = %29[i]
     aux = %30
     %32 = v
     %33 = v
     %34 = %33[jmin]
     %32[i] = %34
     %36 = v
     %36[jmin] = aux
  label endif2 :
     %38 = 1
     %39 = i + %38
     i = %39
     goto beginWhile2
  label endWhile2 :
     return
endfunction

function evenPositivesAndSort
  params
    v float array
  endparams

  vars
    i integer
  endvars

     %1 = 0
     i = %1
  label beginWhile1 :
     %3 = 20
     %4 = i < %3
     ifFalse %4 goto endWhile1
     %6 = v
     %7 = %6[i]
     %8 = 0
     %12 = float %8
     %10 = %7 <=. %12
     %9 = not %10
     ifFalse %9 goto endif1
     %13 = v
     pushparam 
     call one
     popparam %14
     %13[i] = %14
  label endif1 :
     %16 = 1
     %17 = i + %16
     i = %17
     goto beginWhile1
  label endWhile1 :
     pushparam 
     %19 = v
     pushparam %19
     call sort
     popparam 
     popparam %21
     return
endfunction

function main
  vars
    af float 20
    i integer
  endvars

     %1 = 0
     i = %1
  label beginWhile1 :
     %3 = 20
     %4 = i < %3
     ifFalse %4 goto endWhile1
     readf %6
     af[i] = %6
     %7 = 1
     %8 = i + %7
     i = %8
     goto beginWhile1
  label endWhile1 :
     pushparam 
     %10 = &af
     pushparam %10
     call evenPositivesAndSort
     popparam 
     popparam %11
     %12 = 0
     i = %12
  label beginWhile2 :
     %14 = 20
     %15 = i < %14
     ifFalse %15 goto endWhile2
     %17 = af[i]
     pushparam 
     call one
     popparam %18
     %20 = %17 ==. %18
     %19 = not %20
     ifFalse %19 goto endif1
     %23 = af[i]
     writef %23
     %24 = ' '
     writec %24
     %25 = 1
     %26 = i + %25
     i = %26
     goto endelse1
  label endif1 :
     %28 = '\n'
     writec %28
     return
  label endelse1 :
     goto beginWhile2
  label endWhile2 :
     %29 = '\n'
     writec %29
     return
endfunction


