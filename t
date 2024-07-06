
   [33m┌[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m┐[0m
   [33m│[0m                                 [33m│[0m
   [33m│[0m   [33mfuncheck[0m -- [1m1.1.2[0m             [33m│[0m
   [33m│[0m                                 [33m│[0m
   [33m│[0m   - program: [1m./so_long[0m          [33m│[0m
   [33m│[0m                                 [33m│[0m
   [33m│[0m   - arguments:                  [33m│[0m
   [33m│[0m       * [1m./maps/map02.ber[0m        [33m│[0m
   [33m└[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m─[0m[33m┘[0m

[44m[1m INFO [0m If your program wait for stdin input, you can type here or pipe it.
[33m───────────── TTY ────────────[0m
[33m──────────────────────────────[0m
[46m[1m TASK [0m Testable functions fetching [42m[1m ✓ [0m
[44m[1m INFO [0m Functions detected count: [1m22[0m
┏[43m [1mmalloc [0m [33m233[0m bytes allocated in [33m9[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)


┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m3[0m contexts 
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:44:9 (0x405388)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
        ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m1[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:37:8 (0x405322)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
        ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m190[0m bytes allocated in [33m8[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m1[0m contexts 
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:44:9 (0x405388)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
        ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m146[0m bytes allocated in [33m6[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m2[0m contexts 
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:37:8 (0x405322)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
        ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m190[0m bytes allocated in [33m8[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m1[0m contexts 
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:44:9 (0x405388)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_rows at src/map.c:25:9 (0x40358b)
        ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m1[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:37:8 (0x405322)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_rows at src/map.c:25:9 (0x40358b)
        ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m3[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m85[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:44:9 (0x405388)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
        ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m26[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m4[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m45[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:44:9 (0x405388)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
        ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m43[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:68:11 (0x405104)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m52[0m bytes allocated in [33m2[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m1[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_rows at src/map.c:30:10 (0x4035b4)
    ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m26[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_rows at src/map.c:30:10 (0x4035b4)
      ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m1[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_rows at src/map.c:30:10 (0x4035b4)
    ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m26[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_rows at src/map.c:30:10 (0x4035b4)
      ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m3[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:68:11 (0x405104)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m25[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m208[0m bytes allocated in [33m8[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m2[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:68:11 (0x405104)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m25[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m182[0m bytes allocated in [33m7[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m1[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:68:11 (0x405104)
  ┗━┳━━ get_rows at src/map.c:30:10 (0x4035b4)
    ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m18[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_rows at src/map.c:25:9 (0x40358b)
    ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m1[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:68:11 (0x405104)
  ┗━┳━━ get_rows at src/map.c:30:10 (0x4035b4)
    ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m35[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_rows at src/map.c:30:10 (0x4035b4)
    ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m1[0m contexts 
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_rows at src/map.c:25:9 (0x40358b)
    ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m26[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_rows at src/map.c:25:9 (0x40358b)
      ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m2[0m contexts 
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m85[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:44:9 (0x405388)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
        ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mmalloc [0m when this function is failing, allocations are not freed in [33m4[0m contexts 
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m45[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ gnl_strjoin at lib/gnl/get_next_line_utils.c:44:9 (0x405388)
  ┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:28:12 (0x404f21)
    ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
      ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
        ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
          ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m43[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:68:11 (0x405104)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m26[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mread [0m when this function is failing, allocations are not freed in [33m3[0m contexts 
┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:20:11 (0x404eb3)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m25[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m208[0m bytes allocated in [33m8[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mread [0m when this function is failing, allocations are not freed in [33m2[0m contexts 
┗━┳━━ ft_createtmp at lib/gnl/get_next_line.c:20:11 (0x404eb3)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:71:8 (0x40513e)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m25[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_next_line at lib/gnl/get_next_line.c:78:12 (0x4051d0)
  ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
    ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
      ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m165[0m bytes allocated in [33m7[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mclose [0m when this function is failing, allocations are not freed in [33m2[0m contexts 
┗━┳━━ get_columns at src/map.c:84:2 (0x4036e8)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m233[0m bytes allocated in [33m9[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)

┏[42m [1mclose [0m when this function is failing, allocations are not freed in [33m2[0m contexts 
┗━┳━━ get_rows at src/map.c:37:2 (0x4035fc)
  ┗━┳━━ init_map at src/map.c:103:2 (0x403501)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m233[0m bytes allocated in [33m9[0m allocations is not freed
┗━┳━━ ft_assembleline at lib/gnl/get_next_line.c:46:9 (0x40501f)
  ┗━┳━━ get_next_line at lib/gnl/get_next_line.c:75:9 (0x405178)
    ┗━┳━━ get_columns at src/map.c:82:22 (0x4036b4)
      ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
        ┗━━━━ main at src/main.c:104:2 (0x40306c)
┏[43m [1mmalloc [0m [33m80[0m bytes allocated in [33m1[0m allocations is not freed
┗━┳━━ get_columns at src/map.c:77:18 (0x403662)
  ┗━┳━━ init_map at src/map.c:106:2 (0x40352f)
    ┗━━━━ main at src/main.c:104:2 (0x40306c)


[1mFunction tests: [32m22 passed[0m, 22 in total
[1mTime:[0m           177 ms
[1mSuccess rate:[0m   100 %
[0;37mAll tests ran[0m
