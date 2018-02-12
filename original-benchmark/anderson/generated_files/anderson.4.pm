byte Slot[4];
byte next=0;


init { 
 d_step { 
Slot[0] =1; Slot[1] =0; Slot[2] =0; Slot[3] =0; }
atomic { 
run P_0();
run P_1();
run P_2();
run P_3();
} }

proctype P_0() { 
byte my_place=0;

NCS: if
::  d_step {my_place = next;next = next+1;}  goto p1; 

fi;
p1: if
::  d_step {my_place==4-1;next = next-4;}  goto p2; 

::  d_step {my_place!=4-1;my_place = my_place%4;}  goto p2; 

fi;
p2: if
:: Slot[my_place]==1; goto p3; 

fi;
p3: if
:: Slot[my_place] = 0; goto CS; 

fi;
CS: if
:: Slot[(my_place+1)%4] = 1; goto NCS; 

fi;
}

proctype P_1() { 
byte my_place=0;

NCS: if
::  d_step {my_place = next;next = next+1;}  goto p1; 

fi;
p1: if
::  d_step {my_place==4-1;next = next-4;}  goto p2; 

::  d_step {my_place!=4-1;my_place = my_place%4;}  goto p2; 

fi;
p2: if
:: Slot[my_place]==1; goto p3; 

fi;
p3: if
:: Slot[my_place] = 0; goto CS; 

fi;
CS: if
:: Slot[(my_place+1)%4] = 1; goto NCS; 

fi;
}

proctype P_2() { 
byte my_place=0;

NCS: if
::  d_step {my_place = next;next = next+1;}  goto p1; 

fi;
p1: if
::  d_step {my_place==4-1;next = next-4;}  goto p2; 

::  d_step {my_place!=4-1;my_place = my_place%4;}  goto p2; 

fi;
p2: if
:: Slot[my_place]==1; goto p3; 

fi;
p3: if
:: Slot[my_place] = 0; goto CS; 

fi;
CS: if
:: Slot[(my_place+1)%4] = 1; goto NCS; 

fi;
}

proctype P_3() { 
byte my_place=0;

NCS: if
::  d_step {my_place = next;next = next+1;}  goto p1; 

fi;
p1: if
::  d_step {my_place==4-1;next = next-4;}  goto p2; 

::  d_step {my_place!=4-1;my_place = my_place%4;}  goto p2; 

fi;
p2: if
:: Slot[my_place]==1; goto p3; 

fi;
p3: if
:: Slot[my_place] = 0; goto CS; 

fi;
CS: if
:: Slot[(my_place+1)%4] = 1; goto NCS; 

fi;
}

