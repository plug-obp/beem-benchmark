byte a[16];
byte peg_count=15;


init { 
 d_step { 
a[0] =1; a[1] =1; a[2] =1; a[3] =1; a[4] =1; a[5] =1; a[6] =1; a[7] =1; a[8] =1; a[9] =1; a[10] =1; a[11] =1; a[12] =1; a[13] =1; a[14] =1; a[15] =0; }
atomic { 
run P();
} }

proctype P() { 

q: if
::  d_step {a[((0)*4+0)]==1 && a[((0+1)*4+0+1)]==1 && a[((0+2)*4+0+2)]==0;a[((0)*4+0)] = 0;a[((0+1)*4+0+1)] = 0;a[((0+2)*4+0+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+1)]==1 && a[((0+1)*4+1+1)]==1 && a[((0+2)*4+1+2)]==0;a[((0)*4+1)] = 0;a[((0+1)*4+1+1)] = 0;a[((0+2)*4+1+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+0)]==1 && a[((1+1)*4+0+1)]==1 && a[((1+2)*4+0+2)]==0;a[((1)*4+0)] = 0;a[((1+1)*4+0+1)] = 0;a[((1+2)*4+0+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+1)]==1 && a[((1+1)*4+1+1)]==1 && a[((1+2)*4+1+2)]==0;a[((1)*4+1)] = 0;a[((1+1)*4+1+1)] = 0;a[((1+2)*4+1+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+0)]==1 && a[((2-1)*4+0+1)]==1 && a[((2-2)*4+0+2)]==0;a[((2)*4+0)] = 0;a[((2-1)*4+0+1)] = 0;a[((2-2)*4+0+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+1)]==1 && a[((2-1)*4+1+1)]==1 && a[((2-2)*4+1+2)]==0;a[((2)*4+1)] = 0;a[((2-1)*4+1+1)] = 0;a[((2-2)*4+1+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+0)]==1 && a[((3-1)*4+0+1)]==1 && a[((3-2)*4+0+2)]==0;a[((3)*4+0)] = 0;a[((3-1)*4+0+1)] = 0;a[((3-2)*4+0+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+1)]==1 && a[((3-1)*4+1+1)]==1 && a[((3-2)*4+1+2)]==0;a[((3)*4+1)] = 0;a[((3-1)*4+1+1)] = 0;a[((3-2)*4+1+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+2)]==1 && a[((0+1)*4+2-1)]==1 && a[((0+2)*4+2-2)]==0;a[((0)*4+2)] = 0;a[((0+1)*4+2-1)] = 0;a[((0+2)*4+2-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+3)]==1 && a[((0+1)*4+3-1)]==1 && a[((0+2)*4+3-2)]==0;a[((0)*4+3)] = 0;a[((0+1)*4+3-1)] = 0;a[((0+2)*4+3-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+2)]==1 && a[((1+1)*4+2-1)]==1 && a[((1+2)*4+2-2)]==0;a[((1)*4+2)] = 0;a[((1+1)*4+2-1)] = 0;a[((1+2)*4+2-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+3)]==1 && a[((1+1)*4+3-1)]==1 && a[((1+2)*4+3-2)]==0;a[((1)*4+3)] = 0;a[((1+1)*4+3-1)] = 0;a[((1+2)*4+3-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+2)]==1 && a[((2-1)*4+2-1)]==1 && a[((2-2)*4+2-2)]==0;a[((2)*4+2)] = 0;a[((2-1)*4+2-1)] = 0;a[((2-2)*4+2-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+3)]==1 && a[((2-1)*4+3-1)]==1 && a[((2-2)*4+3-2)]==0;a[((2)*4+3)] = 0;a[((2-1)*4+3-1)] = 0;a[((2-2)*4+3-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+2)]==1 && a[((3-1)*4+2-1)]==1 && a[((3-2)*4+2-2)]==0;a[((3)*4+2)] = 0;a[((3-1)*4+2-1)] = 0;a[((3-2)*4+2-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+3)]==1 && a[((3-1)*4+3-1)]==1 && a[((3-2)*4+3-2)]==0;a[((3)*4+3)] = 0;a[((3-1)*4+3-1)] = 0;a[((3-2)*4+3-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+0)]==1 && a[((0)*4+0+1)]==1 && a[((0)*4+0+2)]==0;a[((0)*4+0)] = 0;a[((0)*4+0+1)] = 0;a[((0)*4+0+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+1)]==1 && a[((0)*4+1+1)]==1 && a[((0)*4+1+2)]==0;a[((0)*4+1)] = 0;a[((0)*4+1+1)] = 0;a[((0)*4+1+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+0)]==1 && a[((1)*4+0+1)]==1 && a[((1)*4+0+2)]==0;a[((1)*4+0)] = 0;a[((1)*4+0+1)] = 0;a[((1)*4+0+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+1)]==1 && a[((1)*4+1+1)]==1 && a[((1)*4+1+2)]==0;a[((1)*4+1)] = 0;a[((1)*4+1+1)] = 0;a[((1)*4+1+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+0)]==1 && a[((2)*4+0+1)]==1 && a[((2)*4+0+2)]==0;a[((2)*4+0)] = 0;a[((2)*4+0+1)] = 0;a[((2)*4+0+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+1)]==1 && a[((2)*4+1+1)]==1 && a[((2)*4+1+2)]==0;a[((2)*4+1)] = 0;a[((2)*4+1+1)] = 0;a[((2)*4+1+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+0)]==1 && a[((3)*4+0+1)]==1 && a[((3)*4+0+2)]==0;a[((3)*4+0)] = 0;a[((3)*4+0+1)] = 0;a[((3)*4+0+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+1)]==1 && a[((3)*4+1+1)]==1 && a[((3)*4+1+2)]==0;a[((3)*4+1)] = 0;a[((3)*4+1+1)] = 0;a[((3)*4+1+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+2)]==1 && a[((0)*4+2-1)]==1 && a[((0)*4+2-2)]==0;a[((0)*4+2)] = 0;a[((0)*4+2-1)] = 0;a[((0)*4+2-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+3)]==1 && a[((0)*4+3-1)]==1 && a[((0)*4+3-2)]==0;a[((0)*4+3)] = 0;a[((0)*4+3-1)] = 0;a[((0)*4+3-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+2)]==1 && a[((1)*4+2-1)]==1 && a[((1)*4+2-2)]==0;a[((1)*4+2)] = 0;a[((1)*4+2-1)] = 0;a[((1)*4+2-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+3)]==1 && a[((1)*4+3-1)]==1 && a[((1)*4+3-2)]==0;a[((1)*4+3)] = 0;a[((1)*4+3-1)] = 0;a[((1)*4+3-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+2)]==1 && a[((2)*4+2-1)]==1 && a[((2)*4+2-2)]==0;a[((2)*4+2)] = 0;a[((2)*4+2-1)] = 0;a[((2)*4+2-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+3)]==1 && a[((2)*4+3-1)]==1 && a[((2)*4+3-2)]==0;a[((2)*4+3)] = 0;a[((2)*4+3-1)] = 0;a[((2)*4+3-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+2)]==1 && a[((3)*4+2-1)]==1 && a[((3)*4+2-2)]==0;a[((3)*4+2)] = 0;a[((3)*4+2-1)] = 0;a[((3)*4+2-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+3)]==1 && a[((3)*4+3-1)]==1 && a[((3)*4+3-2)]==0;a[((3)*4+3)] = 0;a[((3)*4+3-1)] = 0;a[((3)*4+3-2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+0)]==1 && a[((0+1)*4+0)]==1 && a[((0+2)*4+0)]==0;a[((0)*4+0)] = 0;a[((0+1)*4+0)] = 0;a[((0+2)*4+0)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+1)]==1 && a[((0+1)*4+1)]==1 && a[((0+2)*4+1)]==0;a[((0)*4+1)] = 0;a[((0+1)*4+1)] = 0;a[((0+2)*4+1)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+2)]==1 && a[((0+1)*4+2)]==1 && a[((0+2)*4+2)]==0;a[((0)*4+2)] = 0;a[((0+1)*4+2)] = 0;a[((0+2)*4+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((0)*4+3)]==1 && a[((0+1)*4+3)]==1 && a[((0+2)*4+3)]==0;a[((0)*4+3)] = 0;a[((0+1)*4+3)] = 0;a[((0+2)*4+3)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+0)]==1 && a[((1+1)*4+0)]==1 && a[((1+2)*4+0)]==0;a[((1)*4+0)] = 0;a[((1+1)*4+0)] = 0;a[((1+2)*4+0)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+1)]==1 && a[((1+1)*4+1)]==1 && a[((1+2)*4+1)]==0;a[((1)*4+1)] = 0;a[((1+1)*4+1)] = 0;a[((1+2)*4+1)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+2)]==1 && a[((1+1)*4+2)]==1 && a[((1+2)*4+2)]==0;a[((1)*4+2)] = 0;a[((1+1)*4+2)] = 0;a[((1+2)*4+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((1)*4+3)]==1 && a[((1+1)*4+3)]==1 && a[((1+2)*4+3)]==0;a[((1)*4+3)] = 0;a[((1+1)*4+3)] = 0;a[((1+2)*4+3)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+0)]==1 && a[((2-1)*4+0)]==1 && a[((2-2)*4+0)]==0;a[((2)*4+0)] = 0;a[((2-1)*4+0)] = 0;a[((2-2)*4+0)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+1)]==1 && a[((2-1)*4+1)]==1 && a[((2-2)*4+1)]==0;a[((2)*4+1)] = 0;a[((2-1)*4+1)] = 0;a[((2-2)*4+1)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+2)]==1 && a[((2-1)*4+2)]==1 && a[((2-2)*4+2)]==0;a[((2)*4+2)] = 0;a[((2-1)*4+2)] = 0;a[((2-2)*4+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((2)*4+3)]==1 && a[((2-1)*4+3)]==1 && a[((2-2)*4+3)]==0;a[((2)*4+3)] = 0;a[((2-1)*4+3)] = 0;a[((2-2)*4+3)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+0)]==1 && a[((3-1)*4+0)]==1 && a[((3-2)*4+0)]==0;a[((3)*4+0)] = 0;a[((3-1)*4+0)] = 0;a[((3-2)*4+0)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+1)]==1 && a[((3-1)*4+1)]==1 && a[((3-2)*4+1)]==0;a[((3)*4+1)] = 0;a[((3-1)*4+1)] = 0;a[((3-2)*4+1)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+2)]==1 && a[((3-1)*4+2)]==1 && a[((3-2)*4+2)]==0;a[((3)*4+2)] = 0;a[((3-1)*4+2)] = 0;a[((3-2)*4+2)] = 1;peg_count = peg_count-1;}  goto q; 

::  d_step {a[((3)*4+3)]==1 && a[((3-1)*4+3)]==1 && a[((3-2)*4+3)]==0;a[((3)*4+3)] = 0;a[((3-1)*4+3)] = 0;a[((3-2)*4+3)] = 1;peg_count = peg_count-1;}  goto q; 

fi;
}
