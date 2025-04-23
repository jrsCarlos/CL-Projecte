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
   %20 = float %17
   %18 = %15 +. %20
   %21 = 2.0
   %22 = -. %21
   %25 = float a
   %23 = %22 /. %25
   %26 = %18 -. %23
   pi = %26
   %29 = a == b
   %31 = %29 or end
   writei %31
   writes "\n"
   %32 = a * b
   writei %32
   writes "\n"
   %33 = 2
   %35 = float %33
   %34 = %35 *. pi
   writef %34
   writes "\n"
   return
endfunction


