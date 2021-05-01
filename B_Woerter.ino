
void W_ESIST() {
  leds[0].setRGB( R, G, B);  //E
  leds[1].setRGB( R, G, B);  //S
  leds[3].setRGB( R, G, B);  //I
  leds[4].setRGB( R, G, B);  //S
  leds[5].setRGB( R, G, B); //T
}

void M_FUENF() {
  for (int i=7; i <= 10; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void M_ZEHN() {
  for (int i=18; i <= 21; i++){
    leds[i].setRGB( R, G, B);  
  }
}


void M_ZWANZIG () {
  for (int i=11; i <= 17; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void M_VIERTEL () {
  for (int i=26; i <= 32; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void W_NACH () {
  for (int i=38; i <= 41; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void W_VOR () {
  for (int i=35; i <= 37; i++){
    leds[i].setRGB( R, G, B);  
  } 
}


void M_HALB() {
  for (int i=44; i <= 47; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_ZWOELF(){
  for (int i=49; i <= 53; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_ZWEI(){
  for (int i=62; i <= 65; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_EIN(){
  for (int i=61; i <= 63; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_EINS(){
  for (int i=60; i <= 63; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_SIEBEN(){
  for (int i=55; i <= 60; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_DREI(){
  for (int i=67; i <= 70; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_FUENF(){
  for (int i=73; i <= 76; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_ELF () {
  for (int i=85; i <= 87; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_NEUN (){
  for (int i=81; i <= 84; i++){
    leds[i].setRGB( R, G, B);  
  }

}

void H_VIER (){  
  for (int i=77; i <= 80; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_ACHT (){
  for (int i=89; i <= 92; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_ZEHN () {
  for (int i=93; i <= 96; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void H_SECHS(){
  for (int i=104; i <= 108; i++){
    leds[i].setRGB( R, G, B);  
  }

}

void W_UHR(){
  for (int i=99; i <= 101; i++){
    leds[i].setRGB( R, G, B);  
  }

}

void P_EINS() {
  leds[113].setRGB( R, G, B);  // OL
}
void P_ZWEI() {
  leds[113].setRGB( R, G, B);  //OL
  leds[112].setRGB( R, G, B);  //OR

}
void P_DREI() {
  leds[113].setRGB( R, G, B);  //OL
  leds[112].setRGB( R, G, B);  //OR
  leds[111].setRGB( R, G, B);  //UR
}
void P_VIER() {
  leds[112].setRGB( R, G, B);  //OL
  leds[111].setRGB( R, G, B);  //OR
  leds[110].setRGB( R, G, B);  //UR
  leds[113].setRGB( R, G, B);  //UL
}



// SECONDS COUNTER MODE
void L_ZERO(){
  for (int i=23; i <= 25; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[43].setRGB( R, G, B);  
  leds[39].setRGB( R, G, B);  
  leds[44].setRGB( R, G, B);  
  leds[47].setRGB( R, G, B);  
  leds[48].setRGB( R, G, B);  
  leds[65].setRGB( R, G, B);  
  leds[61].setRGB( R, G, B);  
  leds[63].setRGB( R, G, B);  
  leds[66].setRGB( R, G, B);  
  leds[67].setRGB( R, G, B);  
  leds[70].setRGB( R, G, B);  
  leds[87].setRGB( R, G, B);  
  leds[83].setRGB( R, G, B);  
  for (int i=89; i <= 91; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void L_ONE(){
  leds[24].setRGB( R, G, B);  
  leds[42].setRGB( R, G, B);  
  leds[41].setRGB( R, G, B);  
  leds[46].setRGB( R, G, B);  
  leds[63].setRGB( R, G, B);  
  leds[68].setRGB( R, G, B);  
  leds[85].setRGB( R, G, B);  
  for (int i=89; i <= 91; i++){
    leds[i].setRGB( R, G, B);  
  }  
}
void L_TWO(){
  for (int i=23; i <= 25; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[43].setRGB( R, G, B);  
  leds[39].setRGB( R, G, B);  
  leds[48].setRGB( R, G, B);  
  leds[62].setRGB( R, G, B);  
  leds[68].setRGB( R, G, B);  
  leds[86].setRGB( R, G, B);  
  for (int i=88; i <= 92; i++){
    leds[i].setRGB( R, G, B);  
  } 
}

void L_THREE(){
  for (int i=22; i <= 26; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[40].setRGB( R, G, B);  
  leds[46].setRGB( R, G, B);  
  leds[62].setRGB( R, G, B);  
  leds[70].setRGB( R, G, B);  
  leds[83].setRGB( R, G, B);  
  leds[87].setRGB( R, G, B);  
  for (int i=89; i <= 91; i++){
    leds[i].setRGB( R, G, B);  
  }  
}

void L_FOUR(){
  leds[25].setRGB( R, G, B);  
  leds[40].setRGB( R, G, B);  
  leds[41].setRGB( R, G, B);  
  leds[45].setRGB( R, G, B);  
  leds[47].setRGB( R, G, B);  
  leds[65].setRGB( R, G, B);  
  leds[62].setRGB( R, G, B);  
  for (int i=66; i <= 70; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[84].setRGB( R, G, B);  
  leds[91].setRGB( R, G, B); 
  
}

void L_FIVE(){
  for (int i=22; i <= 26; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[43].setRGB( R, G, B);  
  leds[44].setRGB( R, G, B);  
  for (int i=62; i <= 65; i++){
    leds[i].setRGB( R, G, B);  
  }  
  leds[70].setRGB( R, G, B);  
  leds[83].setRGB( R, G, B);  
  for (int i=89; i <= 91; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[87].setRGB( R, G, B);  
}

void R_ZERO(){
  for (int i=29; i <= 31; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[37].setRGB( R, G, B);  
  leds[33].setRGB( R, G, B);  
  leds[50].setRGB( R, G, B);  
  leds[53].setRGB( R, G, B);  
  leds[54].setRGB( R, G, B);  
  leds[59].setRGB( R, G, B);  
  leds[57].setRGB( R, G, B);  
  leds[55].setRGB( R, G, B);  
  leds[72].setRGB( R, G, B);  
  leds[73].setRGB( R, G, B);  
  leds[76].setRGB( R, G, B);  
  leds[81].setRGB( R, G, B);  
  leds[77].setRGB( R, G, B);  
  for (int i=95; i <= 97; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void R_ONE(){
  leds[30].setRGB( R, G, B);  
  leds[36].setRGB( R, G, B);  
  leds[35].setRGB( R, G, B);  
  leds[52].setRGB( R, G, B);  
  leds[57].setRGB( R, G, B);  
  leds[74].setRGB( R, G, B);  
  leds[79].setRGB( R, G, B);  
  for (int i=95; i <= 97; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void R_TWO(){
  for (int i=29; i <= 31; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[37].setRGB( R, G, B);  
  leds[33].setRGB( R, G, B);  
  leds[54].setRGB( R, G, B);  
  leds[56].setRGB( R, G, B);  
  leds[74].setRGB( R, G, B);  
  leds[80].setRGB( R, G, B);  
  for (int i=94; i <= 98; i++){
    leds[i].setRGB( R, G, B);  
  } 
}

void R_THREE(){
  for (int i=28; i <= 32; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[34].setRGB( R, G, B);  
  leds[52].setRGB( R, G, B);  
  leds[56].setRGB( R, G, B);  
  leds[76].setRGB( R, G, B);  
  leds[77].setRGB( R, G, B);  
  leds[81].setRGB( R, G, B);  
  for (int i=95; i <= 97; i++){
    leds[i].setRGB( R, G, B);  
  }  
}

void R_FOUR(){
  leds[31].setRGB( R, G, B);  
  leds[34].setRGB( R, G, B);  
  leds[35].setRGB( R, G, B);  
  leds[51].setRGB( R, G, B);  
  leds[53].setRGB( R, G, B);  
  leds[59].setRGB( R, G, B);  
  leds[56].setRGB( R, G, B);  
  for (int i=72; i <= 76; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[78].setRGB( R, G, B);  
  leds[97].setRGB( R, G, B); 
}

void R_FIVE(){
  for (int i=28; i <= 32; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[37].setRGB( R, G, B);  
  leds[50].setRGB( R, G, B);  
  for (int i=56; i <= 59; i++){
    leds[i].setRGB( R, G, B);  
  }  
  leds[76].setRGB( R, G, B);  
  leds[77].setRGB( R, G, B);  
  for (int i=95; i <= 97; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[81].setRGB( R, G, B);  
}

void R_SIX(){
  leds[30].setRGB( R, G, B);  
  leds[31].setRGB( R, G, B);  
  leds[36].setRGB( R, G, B);  
  leds[50].setRGB( R, G, B);  
  for (int i=56; i <= 59; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[72].setRGB( R, G, B);  
  leds[76].setRGB( R, G, B);
  leds[81].setRGB( R, G, B);  
  leds[77].setRGB( R, G, B);
  for (int i=95; i <= 97; i++){
    leds[i].setRGB( R, G, B);  
  }
}

void R_SEVEN(){
  for (int i=28; i <= 32; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[33].setRGB( R, G, B);  
  leds[53].setRGB( R, G, B);
  leds[57].setRGB( R, G, B);  
  leds[73].setRGB( R, G, B);
  leds[80].setRGB( R, G, B);  
  leds[95].setRGB( R, G, B);
}

void R_EIGHT(){
  for (int i=29; i <= 31; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[37].setRGB( R, G, B);  
  leds[33].setRGB( R, G, B);
  leds[50].setRGB( R, G, B);  
  leds[54].setRGB( R, G, B);
  for (int i=56; i <= 58; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[72].setRGB( R, G, B);  
  leds[76].setRGB( R, G, B);
  leds[81].setRGB( R, G, B);  
  leds[77].setRGB( R, G, B);
  for (int i=95; i <= 97; i++){
    leds[i].setRGB( R, G, B);  
  }
}


void R_NINE(){
  for (int i=29; i <= 31; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[37].setRGB( R, G, B);  
  leds[33].setRGB( R, G, B);
  leds[50].setRGB( R, G, B);  
  leds[54].setRGB( R, G, B);
  for (int i=55; i <= 58; i++){
    leds[i].setRGB( R, G, B);  
  }
  leds[76].setRGB( R, G, B);  
  leds[78].setRGB( R, G, B);
  leds[95].setRGB( R, G, B);  
  leds[96].setRGB( R, G, B);
}





























