function f
  params
    v integer array
  endparams

  vars
    c integer 10
    i integer
  endvars

     %1 = v
     %3 = 0
     %5 = 10
     %6 = 1
  label beginAssign1 :
     %4 = %3 < %5
     ifFalse %4 goto endAssign1
     %7 = %1[%3]
     c[%3] = %7
     %3 = %3 + %6
     goto beginAssign1
  label endAssign1 :
     writes "en f. c: "
     %8 = 0
     i = %8
  label beginWhile2 :
     %10 = 10
     %11 = i < %10
     ifFalse %11 goto endWhile2
     %13 = c[i]
     writei %13
     %14 = ' '
     writec %14
     %15 = 1
     %16 = i + %15
     i = %16
     goto beginWhile2
  label endWhile2 :
     %18 = '\n'
     writec %18
     return
endfunction

function g
  params
    v integer array
  endparams

  vars
    d integer 10
    i integer
  endvars

     %1 = 0
     i = %1
  label beginWhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endWhile1
     %6 = 1
     %7 = - %6
     d[i] = %7
     %9 = 1
     %10 = i + %9
     i = %10
     goto beginWhile1
  label endWhile1 :
     %13 = 0
     %15 = 10
     %16 = 1
  label beginAssign2 :
     %14 = %13 < %15
     ifFalse %14 goto endAssign2
     %17 = d[%13]
     v[%13] = %17
     %13 = %13 + %16
     goto beginAssign2
  label endAssign2 :
     return
endfunction

function main
  vars
    a integer 10
    b integer 10
    i integer
    j integer
  endvars

     %1 = 0
     i = %1
  label beginWhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endWhile1
     a[i] = i
     %7 = 0
     b[i] = %7
     %9 = 1
     %10 = i + %9
     i = %10
     goto beginWhile1
  label endWhile1 :
     %13 = 0
     %15 = 10
     %16 = 1
  label beginAssign2 :
     %14 = %13 < %15
     ifFalse %14 goto endAssign2
     %17 = a[%13]
     b[%13] = %17
     %13 = %13 + %16
     goto beginAssign2
  label endAssign2 :
     writes "despres de b=a. b: "
     %18 = 0
     i = %18
  label beginWhile3 :
     %20 = 10
     %21 = i < %20
     ifFalse %21 goto endWhile3
     %23 = b[i]
     writei %23
     %24 = ' '
     writec %24
     %25 = 1
     %26 = i + %25
     i = %26
     goto beginWhile3
  label endWhile3 :
     %28 = '\n'
     writec %28
     writes "despres de b=a. a: "
     %29 = 0
     i = %29
  label beginWhile4 :
     %31 = 10
     %32 = i < %31
     ifFalse %32 goto endWhile4
     %34 = a[i]
     writei %34
     %35 = ' '
     writec %35
     %36 = 1
     %37 = i + %36
     i = %37
     goto beginWhile4
  label endWhile4 :
     %39 = '\n'
     writec %39
     pushparam 
     %40 = &a
     pushparam %40
     call f
     popparam 
     popparam %41
     writes "despres de f(a). a: "
     %42 = 0
     i = %42
  label beginWhile5 :
     %44 = 10
     %45 = i < %44
     ifFalse %45 goto endWhile5
     %47 = a[i]
     writei %47
     %48 = ' '
     writec %48
     %49 = 1
     %50 = i + %49
     i = %50
     goto beginWhile5
  label endWhile5 :
     %52 = '\n'
     writec %52
     pushparam 
     %53 = &a
     pushparam %53
     call g
     popparam 
     popparam %54
     writes "despres de g(a). a: "
     %55 = 0
     i = %55
  label beginWhile6 :
     %57 = 10
     %58 = i < %57
     ifFalse %58 goto endWhile6
     %60 = a[i]
     writei %60
     %61 = ' '
     writec %61
     %62 = 1
     %63 = i + %62
     i = %63
     goto beginWhile6
  label endWhile6 :
     %65 = '\n'
     writec %65
     return
endfunction


