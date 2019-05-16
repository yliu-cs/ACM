/*
  // windows
  :loop
  data.exe > in.txt
  main.exe < in.txt > out.txt
  std.exe < in.txt > std.txt
  fc out.txt std.txt
  if not errorlevel 1 goto loop
  pause
  :end

  // Linux
  declare -i n=1
  while (true)
    do
    ./dtmk
    ./my < 1.in > my.out
    ./force < 1.in > for.out
    if diff my.out for.out
    then
      echo right $n
      n=n+1
    else
      exit
    fi
  done
*/

