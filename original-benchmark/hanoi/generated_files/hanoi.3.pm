byte a[16];
byte a_act=16;
byte b[16];
byte b_act=1;
byte c[16];
byte c_act=1;


init { 
 d_step { 
a[0] =100; a[1] =15-0; a[2] =15-1; a[3] =15-2; a[4] =15-3; a[5] =15-4; a[6] =15-5; a[7] =15-6; a[8] =15-7; a[9] =15-8; a[10] =15-9; a[11] =15-10; a[12] =15-11; a[13] =15-12; a[14] =15-13; a[15] =15-14; b[0] =100; b[1] =0; b[2] =0; b[3] =0; b[4] =0; b[5] =0; b[6] =0; b[7] =0; b[8] =0; b[9] =0; b[10] =0; b[11] =0; b[12] =0; b[13] =0; b[14] =0; b[15] =0; c[0] =100; c[1] =0; c[2] =0; c[3] =0; c[4] =0; c[5] =0; c[6] =0; c[7] =0; c[8] =0; c[9] =0; c[10] =0; c[11] =0; c[12] =0; c[13] =0; c[14] =0; c[15] =0; }
atomic { 
run AtoB();
run AtoC();
run BtoA();
run BtoC();
run CtoA();
run CtoB();
} }

proctype AtoB() { 

q: if
::  d_step {a[a_act-1]<b[b_act-1];b[b_act] = a[a_act-1];b_act = b_act+1;a[a_act-1] = 0;a_act = a_act-1;}  goto q; 

fi;
}

proctype AtoC() { 

q: if
::  d_step {a[a_act-1]<c[c_act-1];c[c_act] = a[a_act-1];c_act = c_act+1;a[a_act-1] = 0;a_act = a_act-1;}  goto q; 

fi;
}

proctype BtoA() { 

q: if
::  d_step {b[b_act-1]<a[a_act-1];a[a_act] = b[b_act-1];a_act = a_act+1;b[b_act-1] = 0;b_act = b_act-1;}  goto q; 

fi;
}

proctype BtoC() { 

q: if
::  d_step {b[b_act-1]<c[c_act-1];c[c_act] = b[b_act-1];c_act = c_act+1;b[b_act-1] = 0;b_act = b_act-1;}  goto q; 

fi;
}

proctype CtoA() { 

q: if
::  d_step {c[c_act-1]<a[a_act-1];a[a_act] = c[c_act-1];a_act = a_act+1;c[c_act-1] = 0;c_act = c_act-1;}  goto q; 

fi;
}

proctype CtoB() { 

q: if
::  d_step {c[c_act-1]<b[b_act-1];b[b_act] = c[c_act-1];b_act = b_act+1;c[c_act-1] = 0;c_act = c_act-1;}  goto q; 

fi;
}

