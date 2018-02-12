byte Slot[3];
byte next=0;


init { 
 d_step { 
Slot[0] =1; Slot[1] =0; Slot[2] =0; }
atomic { 
run P_0();
run P_1();
run P_2();
} }

proctype P_0() { 
byte my_place=0;

NCS: if
::  d_step {my_place = next;next = next+1;}  goto p1; 

fi;
p1: if
::  d_step {my_place==3-1;next = next-3;}  goto p2; 

::  d_step {my_place!=3-1;my_place = my_place%3;}  goto p2; 

fi;
p2: if
:: Slot[my_place]==1; goto p3; 

fi;
p3: if
:: Slot[(my_place+3-1)%3] = 0; goto CS; 

fi;
CS: if
:: Slot[(my_place+1)%3] = 1; goto NCS; 

fi;
}

proctype P_1() { 
byte my_place=0;

NCS: if
::  d_step {my_place = next;next = next+1;}  goto p1; 

fi;
p1: if
::  d_step {my_place==3-1;next = next-3;}  goto p2; 

::  d_step {my_place!=3-1;my_place = my_place%3;}  goto p2; 

fi;
p2: if
:: Slot[my_place]==1; goto p3; 

fi;
p3: if
:: Slot[(my_place+3-1)%3] = 0; goto CS; 

fi;
CS: if
:: Slot[(my_place+1)%3] = 1; goto NCS; 

fi;
}

proctype P_2() { 
byte my_place=0;

NCS: if
::  d_step {my_place = next;next = next+1;}  goto p1; 

fi;
p1: if
::  d_step {my_place==3-1;next = next-3;}  goto p2; 

::  d_step {my_place!=3-1;my_place = my_place%3;}  goto p2; 

fi;
p2: if
:: Slot[my_place]==1; goto p3; 

fi;
p3: if
:: Slot[(my_place+3-1)%3] = 0; goto CS; 

fi;
CS: if
:: Slot[(my_place+1)%3] = 1; goto NCS; 

fi;
}

