function main
  vars
    a integer
    b integer
    end boolean
    pi float
  endvars

   %1 = 12
   a = %1
   %2 = 5
   %3 = a * %2
   %4 = 1
   %5 = a + %4
   %6 = a * %5
   %7 = %3 + %6
   b = %7
   %9 = b < a
   %8 = not %9
   %10 = 0
   %11 = a == %10
   %13 = not %11
   %14 = %8 and %13
   end = %14
   %15 = 3.3
   %16 = 1
   %17 = %16 / a
   %18 = %15 +. %17
   %19 = 2.0
   %20 = -. %19
   %21 = %20 /. a
   %22 = %18 -. %21
   pi = %22
   %23 = a == b
   %25 = %23 or end
   writei %25
   writes "\n"
   %26 = a * b
   writei %26
   writes "\n"
   %27 = 2
   %28 = %27 *. pi
   writef %28
   writes "\n"
   return
endfunction


